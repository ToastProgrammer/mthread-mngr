#ifndef PDEV_MESSAGE_H
#define PDEV_MESSAGE_H

#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <semaphore>

template <typename T>
class MessageQueue
{
public:
    MessageQueue(int n) : buffer(n), head(0), tail(0) {}
    ~MessageQueue() {}

    void push(T msg);

    T pop();
    {
        T msg = buffer[head];
        head = (head + 1) % buffer.size();
        return msg;
    }

    bool isEmpty() { return (head == tail); }
    bool isFull() { return ((tail + 1) % buffer.size() == head); }

private:
    std::vector<T> buffer;
    int head;
    int tail;
};
    
class Parser
{

public:
    Parser();
    ~Parser();

    void parse(const std::stringstream &file);

};

#endif // PDEV_MESSAGE_H
