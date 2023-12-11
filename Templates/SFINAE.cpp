#include<iostream>

struct first
{
    using type = unsigned;
};

template<typename T>
void foo(typename T::type t)
{
    std::cout<<"Struct says: "<<t<<"\n";
}

template<typename T>
void foo(T t)
{
    std::cout<<"Int says: "<<t<<"\n";
}

int main()
{
    foo<first>(10);
    foo<int>(20);

    return 0;
}