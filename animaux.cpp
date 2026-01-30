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

inline void Grille::manger_mouton(Mouton *m, Loup *l)
{
    l->alimentation();
    grille_animaux[position(m)] = 0;
    m->mort();
}

inline void Grille::renouvellement(int grille_herbe[])
{for(int i=0;i<n*n;i++){
    if (grille_herbe[i]==0){
        
    }
     
}
}