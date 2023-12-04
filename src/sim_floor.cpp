#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include <sim_floor.h>

const Coord GRID_ORIGIN(0, 0);

/*
The following functions that call the private functions of the 
same name may change with implementation of thread safety mechanisms.
*/ 

bool SimGrid::get(Coord c) {
    return (_get(c));
}

bool SimGrid::isFull(Coord c) {
    return (bool(_get(c) == NO_OCCUPANT));
}

void SimGrid::put(Coord c, int new_id) {
    _set(new_id, c);
}

void SimGrid::clear(Coord c) {
    _set(NO_OCCUPANT, c);
}

void SimGrid::moveRobot(int occupant_id, Coord c, Coord new_c){
    if (!_verify(occupant_id, c)){
        //TODO: Throw exception
        std::cout << "Error: Device " << occupant_id << " not at " << c.x << ", " << c.y << std::endl;
    }else if (new_c < GRID_ORIGIN || new_c < bound){
        //TODO: Throw exception
        std::cout << "Error: Device " << occupant_id << "cannot reach space out of bounds (" << c.x << ", " << c.y << ")" << std::endl;
    }else{
        _set(NO_OCCUPANT, c);
        _set(occupant_id, new_c);
    }
}

void SimGrid::addRobot(int occupant_id, Coord c){
    if (isFull(c)){
        //TODO: Throw exception
        std::cout << "Error: Device " << occupant_id << " cannot be added at " << c.x << ", " << c.y << "as it is not empty" << std::endl;
    } else {
        _set(occupant_id, c);
    }
}

void SimGrid::delRobot(int occupant_id, Coord c){
    if (!_verify(occupant_id, c)){
        //TODO: Throw exception
        std::cout << "Error: Device " << occupant_id << " cannot be removed at " << c.x << ", " << c.y << "as it is not located there" << std::endl;
    } else {
        _set(NO_OCCUPANT, c);
    }
}

void SimGrid::printFloor(){
    int id;
    std::string outp;

    outp.reserve((bound.x * 5 + 1) * bound.y);

    for (int i; i < bound.x; i++){
        outp += "____";
    }
    outp += "\n";
    for (int j = 0; j < bound.y; j++)
    {
        for (int i = 0; i < bound.x; i++)
        {
            id = _get(i, j);
            outp += "|_";
            if (id == NO_OCCUPANT)
                outp += "_";
            else
                outp += std::to_string(id);
            outp += "_|";
        }
        outp += "|\n";
    }
}

std::string getInputCmd(){
    std::string cmd;
    std::cout << "Enter command: ";
    std::getline(std::cin, cmd);
    return cmd;
}

void SimManager::run(){
    std::string cmd;
    while (status == 0){
        cmd = getInputCmd();
        if (cmd == "exit"){
            status = 1;
        } else if (cmd == "print"){
            printFloor();
        }
    }
}

void SimManager::printFloor(){
    floor->printFloor();
}

void SimManager::cmd(mngr_cmd_t cmd, int id, Coord c, Coord delta_c)
{
    switch (cmd)
    {
    case mngr_cmd_t::ADD:
        floor->addRobot(id, c);
        break;
    case mngr_cmd_t::DEL:
        floor->delRobot(id, c);
        break;
    case mngr_cmd_t::MOVE :
        floor->moveRobotBy(id, c, delta_c);
        break;
    case mngr_cmd_t::MOVE_BY :
        floor->moveRobotBy(id, c, delta_c);
        break;
    default:
        //TODO: Throw exception
        std::cout << "Error: Invalid command [" << std::to_string(cmd) << "] (cmd=" << cmd << ",id=" << std::to_string(id) << ",c=(" << c.x << c.y << "),delta_c=(" << c.x << c.y << "))" << std::endl;
        break;
    }
}

bool SimManager::addStep(){
    return false;
}