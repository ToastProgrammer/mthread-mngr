#ifndef SIM_THREADS_HPP
#define SIM_THREADS_HPP

#include <thread>
#include <pdev_message.hpp>

template <typename T>
class MessageThread
{
public:
    void operator()(MessageQueue<std::shared_ptr<MessageQueue<T>>> &msgQueue)
    {
        while (true)
        {
            if (msgQueue.isEmpty())
            {
                std::this_thread::yield();
            }
            else
            {
                T msg = msgQueue.pop();
                msg->process();
            }
        }
    }
}


#endif // SIM_THREADS_HPP