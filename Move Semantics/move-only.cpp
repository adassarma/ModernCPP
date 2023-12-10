#include <iostream>


class the_answer
{
    std::unique_ptr<int> p;
public:
explicit the_answer(int answer) : p{std::make_unique<int>(answer)}
{ }
~the_answer()
{
std::cout << "The answer is: " << *p << '\n';
}
public:
    the_answer(the_answer &&other) noexcept = default;
    the_answer &operator=(the_answer &&other) noexcept = default;
};
int main(void)
{
the_answer is_42{42};
the_answer is_what{42};
is_what = std::move(is_42);
return 0;
}