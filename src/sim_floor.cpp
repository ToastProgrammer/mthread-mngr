#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include <sim_floor.h>

SimGrid::SimGrid()
{
}

SimGrid::~SimGrid()
{
}

void SimGrid::moveRobot(int occupant_id, Coord c, Coord new_c)
{
}

void SimGrid::moveRobotBy(int occupant_id, Coord new_c)
{
}

void SimGrid::addRobot(int occupant_id, Coord c)
{
}

void SimGrid::delRobot(int occupant_id, Coord c)
{
}

SimManager::SimManager(int n)
{
    
}

SimManager::~SimManager()
{
}

void SimManager::run()
{
}

void SimManager::printFloor()
{
}

bool SimManager::addStep()
{
    return false;
}

std::string getInputCmd(){
    std::string cmd;
    std::cout << ">> ";
    std::getline(std::cin, cmd);
    return cmd;
}

int _get(int x, int y)
{
    
}