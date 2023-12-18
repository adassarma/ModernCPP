#include<memory>
#include<iostream>
#include<stdexcept>
template<typename T>
class mock_vector
{
    public:
    using size_type = std::size_t;

    mock_vector(size_type s):m_size{s},m_buffer{std::make_unique<T[]>(m_size)}
    {}
    void resize(size_type size) noexcept (std::is_nothrow_move_constructible_v<T>)
    {
        auto tmp = std::make_unique<T[]>(size);
        for(size_type i =0;i<m_size;++i)
        tmp[i] = std::move_if_noexcept(m_buffer[i]);

        m_size = size;
        m_buffer = std::move(tmp);
    }


    private:
    size_type m_size{};
    std::unique_ptr<T[]> m_buffer{};
};

struct suboptimal
{
    suboptimal() = default;
    suboptimal(suboptimal &&other)
    {
        *this = std::move(other);
    }
    suboptimal &operator=(suboptimal &&)
    {
        std::cout<<"Move!\n";
        return *this;
    }

    suboptimal(const suboptimal& other)
    {
        *this = other;
    } 

    suboptimal &operator=(const suboptimal&)
    {
        std::cout<<"Copy!\n";
        return *this;
    }
};

struct optimal
{
    optimal()=default;

    optimal(optimal&& other) noexcept
    {
        *this = std::move(other);
    }

    optimal &operator=(optimal&&) noexcept
    {
        std::cout<<"Move!\n";
        return *this;
    }

    optimal(const optimal& other)
    {
        *this = other;
    }

    optimal &operator=(const optimal&)
    {
        std::cout<<"Copy!\n";
        return *this;
    }
};



int main()
{
    mock_vector<optimal> d1(6);
    mock_vector<suboptimal> d2(6);
    d1.resize(10);
    std::cout<<"---------\n";
    d2.resize(10);
}



