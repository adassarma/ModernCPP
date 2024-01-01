#include "threadpool.hpp"

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
    }
    cv.notify_all();
    for(auto &worker: workers)
    worker.join();
}

ThreadPool::ThreadPool(size_t nr_threads): stop(false)
{
    for(size_t i =0;i<nr_threads;++i)
    {
        std::thread worker([this]()
        {
            while(true)
            {
                std::function<void()> task;
                {
                    std::unique_lock lock(mtx);
                    cv.wait(lock,[this](){return stop||!tasks.empty();});
                    if(stop&&tasks.empty())
                    return;

                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
        workers.emplace_back(std::move(worker));
    }
}

template <class F, class... Args>
std::future<std::result_of_t<F(Args...)>>ThreadPool::enqueue(F&&f,Args &&...args)
{
    using return_type = std::result_of_t<F(Args...)>;

    auto task = std::make_shared
}