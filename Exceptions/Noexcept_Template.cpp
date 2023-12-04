#include<limits>
#include<iostream>
#include<stdexcept>

template<typename T>
uint64_t foo(T val) noexcept(sizeof(T)<=4)
{
    if constexpr(sizeof(T)<=4)
    {
        return static_cast<uint64_t>(val)<<32; 
    }

    throw std::runtime_error("Too large to be casted!");
}

int main()
{
    try
    {
        uint32_t val1 = std::numeric_limits<uint32_t>::max();
        std::cout<<"foo:"<<foo(val1)<<"\n";
        uint64_t val2 = std::numeric_limits<uint64_t>::max();
        std::cout<<"foo:"<<foo(val2)<<"\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}