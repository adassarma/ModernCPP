#include<mutex>
#include<shared_mutex>
#include<thread>
#include<iostream>

int count_rw{};
const auto &count_ro = count_rw;

std::shared_mutex m{};

void reader()
{
    while(true)
    {
        std::shared_lock lock(m);
        if(count_ro>6)
        return;
    }
}

void writer()
{
    while(true)
    {
        std::unique_lock lock(m);
        if(++count_rw==1000)
        return;
    }
}

int main()
{
    std::thread t1{reader};
    std::thread t2{reader};
    std::thread t3{reader};
    std::thread t4{reader};
    std::thread t5{writer};

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
}