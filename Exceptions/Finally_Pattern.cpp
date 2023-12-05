#include<iostream>
#include<stdexcept>

using namespace std;

template<typename FUNC>
class finally
{
    FUNC m_func;

    public:
    finally(FUNC func): m_func{func}{}

    ~finally()
    {
        m_func();
        cout<< "Destructor called!\n";
    }

};

int main()
{
    try
    {
        auto var1 = finally{[](){cout<<"Lambda is being executed now!\n";}};
        throw runtime_error("Throwing error on purpose\n");
        cout<<" This line is never executed.";
    }

    catch(const exception&e)
    {
        cout<<" Exception Caught after Destructor is invoked!\n";
    }
}