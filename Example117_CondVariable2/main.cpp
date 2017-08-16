#include <iostream>
#include <thread>
#include <future>
#include <condition_variable>
#include <mutex>
#include <vector>
#include <memory>

class Wave {
public:
    std::mutex mtx;
    std::condition_variable cv;
    std::future<void> res;
    int index;

    Wave(int i) : index(i) {
        res = std::async(std::ref(*this)); // в конструкторе асинхронно запускаем operator()
    }

    virtual void wave() {

    }

    virtual void do_something(){
        std::cout << "Wave: " << index << std::endl;        
    }
    
    void operator()() {
        std::unique_lock<std::mutex> lock(mtx); // входим в защищенную секцию
        cv.wait(lock); // ожидаем сигнала
        
        
        do_something();
        
        
        wave(); // вызываем переопределенную функкцию
    }
};

class NextWave : public Wave { // простой односвязанный список
public:
    std::shared_ptr<Wave> next;

    NextWave(std::shared_ptr<Wave> wave,int i) : Wave(i), next(wave) {

    }

    void wave() override { // передаем сигнал в следующую волну
        std::unique_lock<std::mutex> lock2(next->mtx);
        next->cv.notify_all();
    }
};

int main(int argc, char** argv) {

    std::vector<std::shared_ptr < Wave>> ocean;

    ocean.push_back(std::shared_ptr<Wave>(new Wave(0))); // последняя волна
    for (int i = 1; i < 100; i++)
        ocean.push_back(std::shared_ptr<Wave>(new NextWave(ocean.back(),i))); // следующая волна ссылается на предыдущую

    {
        std::shared_ptr<Wave> last = ocean.back(); // получаем последнюю волну
        std::unique_lock<std::mutex> lock(last->mtx);

        std::cout << "Press any key!" << std::endl;
        std::cin.get();

        last->cv.notify_all(); // и запускаем!
    }
        
    for (auto i : ocean) i->res.get(); // ждем пока все выполнется

    return 0;
}

