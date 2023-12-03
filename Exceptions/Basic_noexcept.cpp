#include<iostream>
#include<stdexcept>

void foo() noexcept
{
     throw std::runtime_error("Custom message"); // Error
}

int main()
{
    try
    {
        foo();
    }
    catch (const std::exception& e)
    {
        std::cout<<e.what()<<"\n";
    }
    return 0;
}