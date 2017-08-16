#include <atomic>
#include <thread>
#include <iostream>
#include <condition_variable>
#include <mutex>

std::atomic_bool x,y; 
std::atomic_int z;


std::mutex mtx;
std::condition_variable v;

void write_x(){

 x.store(true,std::memory_order_seq_cst); //2
// x.store(true,std::memory_order_release); //2
}

void write_y() {
 y.store(true,std::memory_order_seq_cst); //3
// y.store(true,std::memory_order_release); //3
}

void read_x_then_y(){
    std::unique_lock<std::mutex> lock(mtx);
    v.wait(lock);
 //*
 while(!x.load(std::memory_order_seq_cst));
 if(y.load(std::memory_order_seq_cst)) //4
               ++z; 
 /*/
 while(!x.load(std::memory_order_acquire));
 if(y.load(std::memory_order_acquire)) //4
               ++z;
 //*/
}

void read_y_then_x(){
        std::unique_lock<std::mutex> lock(mtx);
    v.wait(lock);
   //*
 while(!y.load(std::memory_order_seq_cst));
 if(x.load(std::memory_order_seq_cst)) //5
               ++z;
  /*/   
 while(!y.load(std::memory_order_acquire));
 if(x.load(std::memory_order_acquire)) //5
               ++z;
 //*/
}

int main()
{
    for(int i=0;i<100;i++){
    x=false;
    y=false;
    z=0;
    


 
    //std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);

    std::cout << "press enter" << std::endl;
    std::cin.get();
    v.notify_all();
    std::cout << "start" << std::endl; 
    
    std::thread a([]{ write_x();write_y();});
    a.join();
    //b.join();
    c.join();
    d.join();

    if(z.load()!=0) std::cout << "Z:" << z.load() << std::endl; //1
    }
    std::cout << "Done";
}
