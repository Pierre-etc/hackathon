
#include <iostream>
#include "const.hpp"

#pragma once

typedef struct 
{
    int x;
    int y;
    int E;
    int age;
    int type;

    Entity(int x, int y, int E, int age);
    void deplacement(int i);
    void reproduction();
    void viellissement();
    void alimentation();
}Entity;

struct Mouton : public Entity
{
    int type = 0;
};

struct Loup : public Entity
{
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
    void manger_herbe(Entity *m);
    void manger_mouton(Mouton *m, Loup *l);
    void renouvellement(int grille_herbe[]);
    void deplacementf(Entity *Ent);
};
inline void Grille::manger_herbe(Entity*m);
Mouton constructeur_mouton(int x, int y, int E, int Age);
int position(Entity *e);