#include<mutex>
#include<thread>
#include<iostream>

std::timed_mutex m{};

void foo()
{
    using namespace std::chrono;

    if(m.try_lock_for(seconds(1)))
    std::cout<<"Lock Acquired!\n";
    else
    std::cout<<"Lock Acquisition Failed!\n";
}

int main()
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();
}