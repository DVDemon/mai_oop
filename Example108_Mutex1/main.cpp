#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

void threadFunction(std::mutex *lock)
{
	lock->lock();
	std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(rand()%5));
	std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;

	lock->unlock();
}


int main(int argc,char * argv[])
{
	std::mutex lock,lock1;
	srand((unsigned int)time(0));
	std::thread t1(threadFunction,&lock);
	std::thread t2(threadFunction,&lock);
	std::thread t3(threadFunction,&lock);
	t1.join();
	t2.join();
	t3.join();

	return 0;
}