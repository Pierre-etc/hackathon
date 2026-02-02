
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
    int T;

public:
    Entity(int x, int y, int E, int, int T);
    void deplacement(int i);
    void reproduction();
    void viellissement();
};

struct Mouton : public Entity
{
    Mouton(int x, int y, int E, int age, int T);
    int type = 0;
    void alimentation();
};

struct Loup : public Entity
{
    int type = 1;
    void alimentation();
    Loup(int x, int y, int E, int age, int T);
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
    void manger_mouton(Mouton *m, Loup *l, Null_Entity *pa);
    void renouvellement(int grille_herbe[]);
    void deplacementf(Entity *Ent);
    Grille();
};

// Mouton constructeur_mouton(int x, int y, int E, int Age);
int position(Entity *e);