#include<iostream>
#include <utility>

using namespace std;
class answer
{
    private:
    int ans{};
    

    public:
    answer()=default;
    explicit answer(int answer):ans{answer}{}

    ~answer()
    {
        if(ans!=0)
        cout<<" Valid object's value is: "<<ans;
    }

    answer(const answer&) = default;
    answer &operator=(const answer&) = default;

    answer(answer&& other)
    {
    *this = std::move(other);
    }
    answer&operator=(answer&& other)
    {
        if(this==&other)
        return *this;

        this->ans = exchange(other.ans,0);

        return *this;
    }
};

int main()
{
    {
        answer a;
        answer b{10};
        a = b;      
    }
    //Destructor prints twice here as 2 valid objects are destructed
        std::cout << '\n';
    {
        answer a{6};
        answer b{8};
        a = std::move(b);
    }
    //Destructor prints only once as the object moved from is now invalid
    return 0;
}       