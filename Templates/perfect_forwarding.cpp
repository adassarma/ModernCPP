#include<iostream>

struct answer{};

void foo2(const answer& one)
{
    std::cout<<"L-value detected!\n";
}

void foo2(answer&& two)
{
    std::cout<<"R-value detected!\n";
}

template<typename T>
void foo1(T&&t)
{
    foo2(std::forward<T>(t));
}

int main()
{
    answer a;
    foo1(a);
    foo1(answer{});
}