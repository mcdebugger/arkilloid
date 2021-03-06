//Help.h
#ifndef HELP_H
#define HELP_H

#include "Intro.h"
#include "Button.h"
#include "Checkbox.h"
class Help : public GameState
{
public:
	Help();
	~Help();
	void handle_events(SDL_Event &event);
	void render();
	void logic();
private:
    Button *buttonStart;
    Button *HelpButtonExit;
    Checkbox *musicOn;
    Checkbox *soundOn;
};

#endif
