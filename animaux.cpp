#include "animaux.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void def_animaux()
{
}
int position(Entity *e)
{
    return e->x + n * (e->y);
}

inline void Grille::manger_herbe(Mouton *m)
{

    grille_herbe[position(m)] = 0;      
    m->alimentation();
    
}

inline void Grille::manger_mouton(Mouton *m, Loup *l)
{
    l->alimentation();
    grille_animaux[position(m)] = 0;
    delete m;
}


inline void Mouton::alimentation()
{
    E += 15;
}

inline void Grille::renouvellement(int grille_herbe[])
{
    for (int i = 0; i < n * n; i++)
    {
        if (grille_herbe[i] == 0)
        {
            srand(time(NULL));
            int b = rand() % 10;
            if (b == 2)
            { grille_herbe[i]=1;

            } // b nombre aléatoire généré entre 0 et 9, on veut une proba de
        }
    }
}
inline void Loup::alimentation()
{
    E += 35;
}


inline void Entity::deplacement(int i)
{
    if (i == 0)
    {
        x += 1;
    }
    if (i == 1)
    {
        x -= 1;
    }
    if (i == 2)
    {
        y += 1;
    }
    if (i == 3)
    {
        y -= 1;
    }
}

inline void Entity::reproduction()
{
    E -= 20;
}

inline void Entity::viellissement()
{
    age+=1;
}