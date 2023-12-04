#include <pdev_message.h>
#include <sim_floor.h>


int main(int argc, char **argv)
{
    std::cout  << "Initializing Manager" << std::endl;
    SimManager sim(Coord(10, 10));
    sim.printFloor();
    sim.cmd(mngr_cmd_t::ADD, 0xAB, Coord(0, 0));
    sim.printFloor();

    return 0;
}
