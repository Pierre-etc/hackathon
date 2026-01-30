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
    int age;

    void deplacement(int i);
    void reproduction();
    void viellissement();
};

struct Mouton : public Entity
{
    void alimentation();
};

struct Loup : public Entity
{
    void alimentation();
};

struct Grille{
    Entity *grille_animaux[n*n];
    int grille_herbe[n*n];
    void manger_herbe(Mouton *m);
    void manger_mouton(Mouton*m,Loup*l);
    void renouvellement(int grille_herbe[]);
};















#endif