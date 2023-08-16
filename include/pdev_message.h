#ifndef PDEV_MESSAGE_H
#define PDEV_MESSAGE_H

#include <sstream>

class Parser
{

public:
    Parser();
    ~Parser();

    void parse(const std::stringstream &file);

};

#endif // PDEV_MESSAGE_H
