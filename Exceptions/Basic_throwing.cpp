#include<iostream>
#include<stdexcept>

void foo()
{
    throw std::runtime_error("Custom message");
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