#include<iostream>
#include<type_traits>
#include<iomanip>


template<typename T,std::enable_if_t<std::is_integral_v<T>>* = nullptr>
void answer(T is)
{
    std::cout <<"Integer passed!\n";
}

template<typename T, std::enable_if_t<std::is_floating_point_v<T>>* = nullptr>
void answer(T is)
{
    std::cout<<"Floating value passed!\n";
}

int main()
{
    answer(6);
    answer(6.1);
}