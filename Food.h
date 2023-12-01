#ifndef FOOD_H
#define FOOD_H

#include <cstdlib>
#include <time.h>

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"


using namespace std;

class Food 
{
    private: 
    objPos FoodPos; 
    GameMechs *mainGameMechsRef; 
    objPosArrayList *playerPosList;

    public: 
    Food(GameMechs* thisGMRef);
    ~Food(); 

    objPosArrayList* generateFood(objPosArrayList* playerPosList); // change this
    
    void getFoodPos(objPos &returnPos); 

}; 

#endif