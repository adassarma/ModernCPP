#include<thread>
#include<string>
#include<mutex>
#include<iostream>

std::mutex m{};

void foo()
{
    static std::string message{"Hello, I am a thread!"};
    while(true)
    {
        std::lock_guard lock(m);
        for(const auto& c: message)
        std::cout<<c;
    }
}

int main()
{   
    std::thread t1{foo};
    std::thread t2{foo};
    t1.join();
    t2.join();
}