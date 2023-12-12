#include<iostream>
#include<type_traits>

template<typename T>
constexpr auto is_int()
{
    return false;
}

template<>
constexpr auto is_int<int>()
{
    return true;
}


template<typename T,std::enable_if_t<is_int<T>(),int> =0>
void func(T is)
{
    std::cout<<" The answer is:"<<is<<"\n";
}


int main()
{
    func(6); //works
    //func(6.1); //compile-error
    return 0;
}