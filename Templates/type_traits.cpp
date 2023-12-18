#include<iostream>
#include<type_traits>

template<auto answer,
std::enable_if_t<std::is_integral_v <decltype(answer)>,int>* = nullptr >

void foo()
{
    std::cout<<"Integer passed!\n";
}

int main()
{
    foo<6>(); //Works for int only
}