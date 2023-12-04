#ifndef SIM_FLOOR_H
#define SIM_FLOOR_H

#include <iostream>
#include <memory>
#include <vector>


#define NO_OCCUPANT 0

enum mngr_cmd_t{
    CMD_BASE = 0x0f,
    ADD = CMD_BASE + 1,
    DEL,
    MOVE,
    MOVE_BY,
};


struct Coord{
    Coord() : x(0), y(0) {}
    Coord(int n_x, int n_y) : x(n_x), y(n_y) {}

    Coord operator+(const Coord& rhs) const { return Coord(x + rhs.x, y + rhs.y); }
    bool operator==(const Coord& rhs) const { return (x == rhs.x && y == rhs.y); }
    bool operator<(const Coord& rhs) const { return (x < rhs.x && y < rhs.y); }
    bool operator>(const Coord& rhs) const { return (x > rhs.x && y > rhs.y); }
    bool operator<=(const Coord& rhs) const { return (x <= rhs.x && y <= rhs.y); }
    bool operator>=(const Coord& rhs) const { return (x >= rhs.x && y >= rhs.y); }

    int x;
    int y;
};


class SimGrid{
public:
    SimGrid() : bound(0, 0), grid(std::make_unique<std::vector<int>>(0)) {}
    SimGrid(Coord grid_size) : bound(grid_size), grid(std::make_unique<std::vector<int>>(grid_size.x * grid_size.y, NO_OCCUPANT)) {}

    bool get(Coord c);
    bool isFull(Coord c);
    void put(Coord c, int new_id);
    void clear(Coord c);
    
    void moveRobot(int occupant_id, Coord c, Coord new_c);
    void moveRobotBy(int occupant_id, Coord c, Coord delta_c) { moveRobot(occupant_id, c, c + delta_c); }
    void addRobot(int occupant_id, Coord c);
    void delRobot(int occupant_id, Coord c);

    void printFloor();

    
private:
    std::unique_ptr<std::vector<int>> grid;
    Coord bound;    // Coordinate of furthest boundary edge from 0, 0

    int _index(Coord c) { return (c.x + c.y * bound.x);}
    int _index(int x, int y) { return (x + y * bound.x);}
    
    int _get(Coord c) { return grid->at(_index(c));}
    int _get(int x, int y) { return grid->at(_index(x, y));}
    void _set(int new_id, Coord c) { grid->at(_index(c)) = new_id; }
    bool _verify(int occupant_id, Coord c) { return (occupant_id == _get(c)); }
};


class SimManager{

public:
    SimManager() : floor(std::make_unique<SimGrid>(Coord(0, 0))), status(0) {};
    SimManager(Coord grid_size) : floor(std::make_unique<SimGrid>(grid_size)), status(0) {};

    void run();
    void printFloor();
    void cmd(mngr_cmd_t cmd, int id, Coord c, Coord delta_c = Coord(0, 0));
    bool addStep();

private:
    
    std::unique_ptr<SimGrid> floor;
    int status;
};

#endif // SIM_FLOOR_H