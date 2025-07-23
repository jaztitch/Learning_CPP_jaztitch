#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iostream>

using namespace std;

struct stdObj{
    string name, color, material, status;
    struct stdObj *next;
};

struct stdSpace{
    bool created;
    string info;
    stdObj *objects;
};

struct stdGrid{
    bool created, visible;
    struct stdSpace east, west, north, south, center;
};

struct stdGrid world[3][3];

#endif