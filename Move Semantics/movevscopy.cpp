#include<iostream>

class copy_or_move
{
    public:
    
    copy_or_move() = default;
    copy_or_move(const copy_or_move& other)
    {
        *this = other;
    }
    copy_or_move &operator=(const copy_or_move& other)
    {
        std::cout<<"Copy is performed!\n";
        return *this;
    }

    copy_or_move(copy_or_move&& other) noexcept
    {
        *this = std::move(other);
    }

    copy_or_move&operator=(copy_or_move&& other) noexcept
    {
        std::cout<<"Move is performed!\n";
        return *this;
    }
};

int main()
{
    const copy_or_move test1;
    copy_or_move test2;
    test2 = std::move(test1); // Copy is performed even though std::move is used! This is because test1 is const.
    return 0;
}