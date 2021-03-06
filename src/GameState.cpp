//GameState.cpp
#include "GameState.h"

extern int stateID;
extern int nextState;

GameState::GameState()
{
    bg = new Texture;
}

GameState::~GameState()
{
    //delete bg;
}

void GameState::set_next_state( int newState )
{
    //If the user doesn't want to exit
    if( nextState != STATE_EXIT )
    {
        //Set the next state
        nextState = newState;
    }
}
