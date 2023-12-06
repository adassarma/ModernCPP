#include<iostream>
#include<stdexcept>

class nested
{
    public:
    ~nested()
    {
    std::cout << "# exceptions: " << std::uncaught_exceptions() <<'\n';
    }
};
class first
{
    public:
    ~first()
    {
    try {
    nested n;
    throw std::runtime_error("First is Throwing!");
    }
    catch (const std::exception &e) 
    {
        std::cout << "Who is throwing? " << e.what() << '\n';
    }
    }
};

int main(void)
{
    try 
    {
    first a;
    throw std::runtime_error("Main is throwing!");
    }
    catch (const std::exception &e) 
    {
    std::cout << "Who is throwing? " << e.what() << '\n';
    }
}