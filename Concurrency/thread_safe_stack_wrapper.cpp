#include<mutex>
#include<stack>
#include<iostream>

//Wrappers inside class

template<typename T>
class my_stack
{
    private:
    std::stack<T> m_stack;
    mutable std::mutex m{};

    public:

    template<typename ARG>
    void push(ARG &&arg)
    {
        std::lock_guard lock(m);
        m_stack.push(std::forward<ARG>(arg));
    }

    void pop()
    {
        std::lock_guard lock(m);
        m_stack.pop();
    }

    auto empty() const
    {
        std::lock_guard lock(m);
        return m_stack.empty();
    }

};

// Using concepts

std::mutex m{};

template<typename S, typename T>
void push(S &s, T &&t)
{
    std::lock_guard lock(m);
    s.push(std::forward<T>(t));
}

template<typename S>
void pop(S &s)
{
    std::lock_guard lock(m);
    s.pop();
}
template<typename S>
auto empty(S &s)
{
    std::lock_guard lock(m);
    return s.empty();
}