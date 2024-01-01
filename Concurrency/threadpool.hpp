#ifndef THREAD_POOL_HPP
#define THREAD_POOL_HPP
#include<functional>
#include<future>
#include<iostream>
#include<queue>
#include<thread>
#include<vector>

class ThreadPool
{
    public:
    ThreadPool(const ThreadPool &)  = delete;
    ThreadPool(ThreadPool &&) = delete;
    ThreadPool &operator=(const ThreadPool &) = delete;
    ThreadPool &operator=(ThreadPool &&) = delete;

    ThreadPool(size_t nr_threads);
    virtual ~ThreadPool();

    template<class F, class ...Args>
    std::future<std::result_of_t<F(Args...)>> enqueue(F&&f, Args &&...args);

    private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex mtx;
    std::conditional_variable cv;
    bool stop;
};

#endif