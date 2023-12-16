#include<iostream>

struct answer{};

void foo2(const answer& one,int i)
{
    std::cout<<"L-value: "<<i<<"\n";
}

void foo2(answer&& two, int i)
{
    std::cout<<"R-value: "<<i<<"\n";
}

template<typename... Args>
void foo1(Args &&...args)
{
    foo2(std::forward<Args>(args)...);
}

int main()
{
    answer a;
    foo1(a,6); // Prints L-value:6
    foo2(answer{},10); // Prints R-value:10
}
