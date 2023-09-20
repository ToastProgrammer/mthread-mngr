#include <pdev_message.hpp>

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