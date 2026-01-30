
#include <iostream>
#include "const.hpp"

#pragma once

struct Entity
{
    int x;
    int y;
    int E;
    int age;
    int type;

    void deplacement(int i);
    void reproduction();
    void viellissement();
};

struct Mouton : public Entity
{
    void alimentation();
    int type = 0;
};

struct Loup : public Entity
{
    void alimentation();
    int type = 1;
};

struct Null_Entity : public Entity
{
    int type = 2;
};

struct Grille
{
    Entity *grille_animaux[GRID_SIZE * GRID_SIZE];
    int grille_herbe[GRID_SIZE * GRID_SIZE];
    void manger_herbe(Mouton *m);
    void manger_mouton(Mouton *m, Loup *l);
    void renouvellement(int grille_herbe[]);
    void deplacementf(Entity *Ent);
};
