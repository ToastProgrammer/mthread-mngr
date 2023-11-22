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

SimManager::SimManager(int n){
    
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
