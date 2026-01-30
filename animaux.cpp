#include "animaux.hpp"

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


inline void Mouton::alimentation()
{
    E += 15;
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
    Age+=1;
}