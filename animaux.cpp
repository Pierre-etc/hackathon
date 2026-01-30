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
    if (grille_herbe[position(m)] == 1)
    {
        grille_herbe[position(m)] = 0;
        m->E = m->E + 15;
    }
}

inline void Entity::vieillir()
{
    age++;
}