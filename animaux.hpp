#include <iostream>
#pragma once

struct Entity
{
    int x;
    int y;
    int E;
    int Age;

    void mort(){}
    
};

struct Mouton : public Entity
{
    void deplacement(){}
    void alimentation(){}
    void reproduction(){}
};

struct Loup : public Entity
{
    void deplacement(){}
    void alimentation(){}
    void reproduction(){}
};