#include <iostream>
#include <thread>
#include <exception>
#include <vector>
#include <mutex>

class MyException : public std::exception{
    
    public:
        const char *what() const noexcept override{
            return "something wrong happened";
        }
    
};
void throw_function() {
    throw new MyException();
}

void threadFunction(std::mutex * mutex, std::vector<std::exception_ptr>* exceptions) {
    try {
        throw_function();
    } catch (...) {
        std::lock_guard<std::mutex> lock(*mutex);
        exceptions->push_back(std::current_exception());
    }
}

int main() {
    std::mutex mutex;
    std::vector<std::exception_ptr> exceptions;

    std::thread thr(threadFunction, &mutex, &exceptions);
    thr.join();

    for (auto &e : exceptions) {
        try {
            if (e != nullptr)
                std::rethrow_exception(e);
        } catch (const std::exception *e) {
            std::cout << "Exception:" << e->what() << std::endl;
        } 
    }


    return 0;
}