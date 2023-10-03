#include <sim_floor.h>


// SimGrid

void SimGrid::moveRobot(int occupant_id, Coord c, Coord new_c)
{
    if(_get(c) != occupant_id){
        std::cout << "Error: Robot " << occupant_id << " not at " << c.x << ", " << c.y << std::endl;
        //TODO: Add "robot move wrong robot at address" error message to queue
    }
    else if(_get(new_c) != NO_OCCUPANT){
        std::cout << "Error: Robot " << occupant_id << " cannot move to " << new_c.x << ", " << new_c.y << std::endl;
        //TODO: Either send "robot move destination occupied" error message to queue or have robot wait for opening(?)
    }
    else{
        _set(c, NO_OCCUPANT);
        _set(new_c, occupant_id);
    }
    
}

void SimGrid::moveRobotBy(int occupant_id, Coord c, Coord d_c)
{
    if(_get(c) != occupant_id){
        std::cout << "Error: Robot " << occupant_id << " not at " << c.x << ", " << c.y << std::endl;
        //TODO: Add "robot move wrong robot at address" error message to queue
    }
    else if(_get(c + d_c) != NO_OCCUPANT){
        std::cout << "Error: Robot " << occupant_id << " cannot move to " << c.x + d_c.x << ", " << c.y + d_c.y << std::endl;
        //TODO: Either send "robot move destination occupied" error message to queue or have robot wait for opening(?)
    }
    else{
        _set(c, NO_OCCUPANT);
        _set(c+d_c, occupant_id);
    }
}

void SimGrid::addRobot(int occupant_id, Coord c)
{
    if(_get(c) != NO_OCCUPANT){
        std::cout << "Error: Robot " << occupant_id << " cannot be added to " << c.x << ", " << c.y << std::endl;
        //TODO: Add "robot add destination occupied" error message to queue
    }
    else{
        _set(c, occupant_id);
    }
}

void SimGrid::delRobot(int occupant_id, Coord c)
{
    if(_get(c) != occupant_id){
        std::cout << "Error: Robot " << occupant_id << " not at " << c.x << ", " << c.y << std::endl;
        //TODO: Add "robot delete wrong robot at address" error message to queue
    }
    else{
        _set(c, NO_OCCUPANT);
    }
}


// SimManager

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
