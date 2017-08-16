#include <atomic>
#include <algorithm>
#include <iostream>
#include <memory>
#include <thread>
#include <mutex>
#include <vector>

std::mutex              g_lockprint;

template <typename T> class stack
{
private:
	struct node
	{
		node* next;
		std::shared_ptr<T> data;
		node(const T& d, node* n = 0)
			:next(n), data(std::make_shared<T>(d)) {}
	};
	std::atomic<node*> head;
public:
	void push(const T& data)
	{
		node* new_node = new node(data, head.load());
		while (!head.compare_exchange_weak(
			new_node->next,
			new_node));
	}

	std::shared_ptr<T> pop()
	{
		node* old_head=head.load();
		while (old_head
			&& !head.compare_exchange_weak(
			old_head,
			old_head->next));
		return old_head ?
			old_head->data :
		std::shared_ptr<T>();
	}
};

void pop_and_push(stack<int>* stack,int number)
{
	for(int i=0;i<10;i++)
	{
		stack->push(i);
	}

	for(int i=0;i<10;i++)
	{
		
		std::shared_ptr<int> res = stack->pop();
		{

			std::unique_lock<std::mutex> locker(g_lockprint);
			if (res.get() != nullptr)
				std::cout << "[" << number << "] " << *res.get() << std::endl;
			else
				std::cout << "Null" << std::endl;
		}
	}
}

int main(int argc,char* argv[])
{
	stack<int> my_stack;
	std::vector<std::thread> threads;

	for(int i=0;i<1000;i++) threads.push_back(std::thread(pop_and_push,&my_stack,i));
	
	for(auto &a : threads) a.join();


	return 0;
}
