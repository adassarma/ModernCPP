#include<atomic>
#include<thread>
#include<iostream>

int count{};
std::atomic<int> atomic_count{};

void foo()
{
    do{
        count++;
        atomic_count++;
    }
    while(atomic_count<99999);
}

int main()
{
    std::thread t1{foo};
    std::thread t2{foo};

    t1.join();
    t2.join();

    std::cout<<"count: "<<count<<"\n";
    std::cout<<"atomic count: "<<atomic_count<<"\n";
}