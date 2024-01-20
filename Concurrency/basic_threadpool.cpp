#include <queue>
#include <condition_variable>
#include <thread>
#include <mutex>
#include <functional>
#include <chrono>
#include <iostream>

using namespace std;

class ThreadPool
{
    public:
    ThreadPool(size_t num_threads=thread::hardware_concurrency())
    {
        for(size_t i =0;i<num_threads;++i)
        {
            threads_.emplace_back([this]{
                while(true)
                {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(queue_lock_);
                        cv.wait(lock,[this]{
                            return !tasks_.empty()||_stop;
                        });

                        if(tasks_.empty()&&stop_)
                        return;
                        
                        task = move(tasks_.front());
                        tasks_.pop();    

                    }

                    task();
                }
            });
        }
    }

    ~ThreadPool()
    {
        {
            unique_lock<mutex> lock(queue_lock_);
            stop_ = true;
        }

        cv.notify_all();    
        for(auto &thread: threads_)
        {
            thread.join();
        }

    }

    void enqueue(function<void()> task)
    {
        {
            unique_lock<mutex> lock(queue_lock_);
            tasks_.emplace(move(task));
        }

        cv.notify_one();
    }

    private:
    queue<function<void()>> tasks_;
    vector<thread> threads_;
    mutex queue_lock_;
    condition_variable cv_;

    bool _stop = false;
};

int main()
{
    ThreadPool pool(4);
    for(int i =0;i<5;++i)
    {
        pool.enqueue([i]{
            cout<<"Task "<<i<<"is running on thread "<<this_thread::get_id()<<endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        });
    }
}