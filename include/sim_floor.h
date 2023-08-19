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


class SimGrid{
public:
    SimGrid();
    ~SimGrid();

    bool get(Coord c) { return (_get(c)); }
    bool isFull(Coord c) { return (bool(_get(c))); }
    void put(Coord c, int new_id) { _set(c, new_id); }
    void clear(Coord c) {  _set(c, NO_OCCUPANT); }
    
    void moveRobot(int occupant_id, Coord c, Coord new_c);
    void moveRobotBy(int occupant_id, Coord new_c);
    void addRobot(int occupant_id, Coord c);
    void delRobot(int occupant_id, Coord c);

    
private:
    std::unique_ptr<std::vector<int>> grid;
    Coord bound;    // Coordingate of furthest boundary edge from 0, 0

    int _index(int x, int y) { return (x + (y * bound.x));}
    int _index(Coord c) { return (c.x + c.y * bound.x);}

    int _get(int x, int y) { return grid->at(_index(x, y));}
    int _get(Coord c) { return grid->at(_index(c.x, c.y));}

    void _set(int x, int y, int new_id) { grid->at(_index(x, y)) = new_id; }
    void _set(Coord c, int new_id) { grid->at(_index(c.x, c.y)) = new_id; }
};


class SimManager{

public:
    SimManager(int n);
    ~SimManager();

    void run();
    void printFloor();
    bool addStep();

private:
    
    std::unique_ptr<SimGrid> floor;
    int status;
};

#endif // SIM_FLOOR_H