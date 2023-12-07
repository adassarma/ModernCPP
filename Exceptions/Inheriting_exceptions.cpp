#include<iostream>
#include<stdexcept>
#include<string.h>

using namespace std;

class my_exception: public std::runtime_error
{
    public:
    explicit my_exception(const char* str):std::runtime_error{str}{}
};

int main()
{
    try
    {
        throw my_exception("Throw occurs in main!\n");
    }
    catch(const my_exception&e){
    std::cout<<"Caught by my_exception!"; // This one executes
    } 
    catch(const std::exception&e){
    std::cout<<"Caught by std::exception!";
    }
}