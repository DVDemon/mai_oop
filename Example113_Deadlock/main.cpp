#include <iostream>
#include <thread>
#include <mutex>


std::mutex resource_A;
std::mutex resource_B;
std::timed_mutex resource_BT;

void FooA()
{
	std::unique_lock<std::mutex> lockA(resource_A, std::defer_lock);
	std::unique_lock<std::mutex> lockB(resource_B, std::defer_lock);

	lockA.lock();
	std::cout << "FooA: ResourceA locked" << std::endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
/*
	if (resource_BT.try_lock_for(std::chrono::milliseconds(5000)))
	{
		std::cout << "FooA: ResourceB locked" << std::endl;
		resource_BT.unlock();
	}
	else std::cout << "FooA: Deadlock detected!!!!" << std::endl;
//*/
  	//*
	lockB.lock();
	std::cout << "FooA: ResourceB locked" << std::endl;
	//*/
	lockA.unlock();
	lockB.unlock();

}

void FooB()
{
	std::unique_lock<std::mutex> lockA(resource_A, std::defer_lock);
	std::unique_lock<std::mutex> lockB(resource_B, std::defer_lock);

	//resource_BT.lock();
	lockB.lock();
	std::cout << "FooB: ResourceB locked" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));


	lockA.lock();
	std::cout << "FooB: ResourceA locked" << std::endl;

	//resource_BT.unlock();
	lockB.unlock();
	lockA.unlock();
}

int main(int argc, const char* argv[])
{
	std::cout << "Let's start:" << std::endl;

	std::thread t1(FooA);
	std::thread t2(FooB);
	t1.join();
	t2.join();

	std::cout << "I don't belive in DeadLock" << std::endl;


	std::cin.get();
}