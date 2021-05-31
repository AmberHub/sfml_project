#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :
    public Entity
{
private :
    //Variables

    //Initializers
    void initVariables();
    void initComponents();

public :
    //Constructor/Destructor
    Player(float x, float y, sf::Texture* textures);
    virtual ~Player();


};

#endif PLAYER_H