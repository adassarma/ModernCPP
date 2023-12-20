#include<mutex>
#include<thread>
#include<string>
#include<iostream>

std::recursive_mutex m{};

void foo()
{
    m.lock();
    m.lock();
    std::cout<<"No deadlock!\n";

    m.unlock();
    m.unlock();
}

int main()
{
    std::thread t1{foo};
    std::thread t2{foo};
    t1.join();
    t2.join();
}