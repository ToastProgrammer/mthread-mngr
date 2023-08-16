cmake_minimum_required(VERSION 3.15)

add_executable(pdevice-mngr main.cpp)

target_sources(pdevice-mngr
    PUBLIC
        sim_floor.cpp
        pdev_message.cpp
        main.cpp
)