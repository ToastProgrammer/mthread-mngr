#include <pdev_message.h>

template <typename T>
void MessageQueue<T>::push(T msg)
{
    buffer[tail] = msg;
    tail = (tail + 1) % buffer.size();
}

template <typename T>
T MessageQueue<T>::pop()
{
    T msg = buffer[head];
    head = (head + 1) % buffer.size();
    return msg;
}

Parser::Parser(){
    
}

Parser::~Parser(){

}

void Parser::parse(const std::stringstream &file)
{
}

std::string getInputCmd(){
    std::string cmd;
    std::cout << ">> ";
    std::getline(std::cin, cmd);
    return cmd;
}