#ifndef SIM_FLOOR_H
#define SIM_FLOOR_H

#include <iostream>
#include <memory>
#include <vector>

#define NO_OCCUPANT 0


struct Coord{
    Coord(int n_x, int n_y) : x(n_x), y(n_y) {}
    int x;
    int y;
};


struct RobotFloorSpace{
    Coord loc;
    int id;

    RobotFloorSpace(int n_x, int n_y, int n_id) : loc(n_x, n_y), id(n_id) {}
    bool get() { return (bool(id)); }
    void put(int new_id) { id = id; }
    void clear() { id = NO_OCCUPANT; }
    
};

class RobotFloorGrid{
public:
    RobotFloorGrid();
    ~RobotFloorGrid();

    bool isOccupied(int x, int y);
    int moveRobot(int occupant_id, int x, int y, int new_x, int new_y);
    int moveRobotBy(int occupant_id, int dx, int dy);
    int addRobot(int x, int y);
    
private:
    std::unique_ptr<std::vector<RobotFloorSpace>> space;
    int x_size;
    int y_size;

    int _get(int x, int y);

};


class RobotFloorSimulator{

public:
    RobotFloorSimulator(int n);
    ~RobotFloorSimulator();

    void run();
    void printFloor();

private:
    bool addStep();
    RobotFloorGrid floor;
};

#endif // SIM_FLOOR_H