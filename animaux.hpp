#ifndef ANIMAUX_HPP
#define ANIMAUX_HPP
#include "const.hpp"


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

struct Grille{
    Entity *grille_animaux[n*n];
    int grille_herbe[n*n];
    void manger_herbe(Mouton *m);
    void manger_mouton(Mouton*m;Loup*l);
};















#endif