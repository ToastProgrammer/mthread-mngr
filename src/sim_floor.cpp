#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include <sim_floor.h>

const Coord BASE(0, 0);



SimGrid::SimGrid(int x, int y){
    bound = Coord(x, y);
    grid = std::make_unique<std::vector<int>>(x * y, NO_OCCUPANT);
}

SimGrid::~SimGrid(){
}

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
    }else if (new_c < BASE || new_c < bound){
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
        std::cout << "Error: Device " << occupant_id << " not at " << c.x << ", " << c.y << std::endl;
    } else {
        _set(occupant_id, c);
    }
}

void SimGrid::delRobot(int occupant_id, Coord c){

}

void SimGrid::printFloor(){
    for (int y = 0; y < bound.y; y++)
    {
        for (int x = 0; x < bound.x; x++)
        {
            std::cout << _get(x, y) << " ";
        }
        std::cout << std::endl;
    }
}

SimManager::SimManager(int n){
    
}

SimManager::~SimManager(){

}

void SimManager::run(){

}

void SimManager::printFloor(){
    floor->printFloor();
}

bool SimManager::addStep(){
    return false;
}

std::string getInputCmd(){
    std::string cmd;
    std::cout << ">> ";
    std::getline(std::cin, cmd);
    return cmd;
}
