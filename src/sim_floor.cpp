#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include <sim_floor.h>



RobotFloorSimulator::RobotFloorSimulator(int n){
    std::unique_ptr<std::vector<int>> mgr_floor = std::make_unique<std::vector<int>>(n);
    }

RobotFloorSimulator::~RobotFloorSimulator()
{
}

void RobotFloorSimulator::run()
{
}

void RobotFloorSimulator::printFloor()
{
}

bool RobotFloorSimulator::addStep()
{
    return false;
}

std::string getInputCmd(){
    std::string cmd;
    std::cout << ">> ";
    std::getline(std::cin, cmd);
    return cmd;
}

RobotFloorGrid::RobotFloorGrid()
{
}

RobotFloorGrid::~RobotFloorGrid()
{
}


bool RobotFloorGrid::isOccupied(int x, int y)
{
    return false;
}

int RobotFloorGrid::moveRobot(int occupant_id, int x, int y, int new_x, int new_y)
{
    return 0;
}

int RobotFloorGrid::moveRobotBy(int occupant_id, int dx, int dy)
{
    return 0;
}

int RobotFloorGrid::addRobot(int x, int y)
{
    return 0;
}
