#include<tuple>
#include<iostream>

template<std::size_t I = 0, typename ...Args, typename FUNCTION>
constexpr void for_each(const std::tuple<Args...> &t, FUNCTION &&func)

{
    if constexpr (I < sizeof...(Args))
    {
        func(std::get<I>(t));
        for_each<I+1>(t,std::forward<FUNCTION>(func));
    }
}

template<typename... Args>
void foo(Args &&...args)
{
    std::tuple t(std::forward<Args>(args)...);
    for_each(t,[](const auto &arg){std::cout<<arg<<"\n";});
}

int main()
{
    foo("This","is an","example of","compile-time recursion! Here's an int:",6);
}