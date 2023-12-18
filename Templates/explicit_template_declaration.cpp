#include<iostream>
#include "explicit_template_declaration.h"

template<typename T>
answer<T>::answer(T t) : m_answer{t}
{}

template<typename T>
void answer<T>::print()
{
    std::cout<<m_answer;
}

template class answer<int>;

int main()
{
    answer a{6};
    a.print();
}