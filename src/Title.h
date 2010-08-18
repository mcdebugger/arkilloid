//Title.h
#ifndef TITLE_H
#define TITLE_H
#include "GameState.h"
#include "Button.h"
#include "Ball.h"
#include <GLFT_Font.hpp>
class Title : public GameState
{
public:
    Title();
    ~Title();
    void handle_events(SDL_Event &event);
    void logic();
    void render();
//    void buttonExit_click();
//    void buttonStart_click();
private:
	Button *buttonExit, *buttonOptions, *buttonStart;
    Ball *ball;
    SDL_Surface *version;
    SDL_Surface *hi_score_show;
};


#endif
