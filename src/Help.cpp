//Help.cpp
#include "Help.h"

extern int stateID;
extern int nextState;
extern std::ofstream loger;
extern std::vector<SDL_Surface*> imageList;
extern Mix_Music *music;
extern bool sound_on;

Help::Help()
{
    bg = imageList[BG_HELP];
    buttonStart = new Button(413,436, "images/buttonStart.bmp");
    buttonExit = new Button(518,436, "images/buttonExit.bmp");
    musicOn = new Checkbox(413, 200, "images/on_off_button.png");
    if(Mix_PlayingMusic() == 0)
    {
        musicOn->check();
    }
    soundOn = new Checkbox(413, 230, "images/on_off_button.png");
    if(sound_on == false)
    {
        soundOn->check();
    }
    SDL_WM_GrabInput(SDL_GRAB_OFF);
}

void soundOn_checked()
{
    sound_on = false;
}

void soundOn_notchecked()
{
    sound_on = true;
}
void musicOn_checked()
{
    Mix_HaltMusic();
}

void musicOn_notchecked()
{
    Mix_PlayMusic(music, -1);
}

Help::~Help()
{
    //SDL_FreeSurface(bg);
    bg = NULL;
    delete buttonExit;
    delete buttonStart;
    delete soundOn;
    delete musicOn;
}

void Help::handle_events(SDL_Event &event)
{
    buttonStart->handle_events(event, buttonStart_click);
    buttonExit->handle_events(event, buttonExit_click);
    if(soundOn->is_checked())
    {
        soundOn->handle_events(event,soundOn_checked);
    }
    else
    {
        soundOn->handle_events(event,soundOn_notchecked);
    }

    if(musicOn->is_checked())
    {
        musicOn->handle_events(event,musicOn_checked);
    }
    else
    {
        musicOn->handle_events(event,musicOn_notchecked);
    }
}

void Help::logic()
{
}



void Help::render(SDL_Surface* screen)
{
    apply_surface(0,0,bg,screen);
    buttonStart->show(screen);
    buttonExit->show(screen);
    soundOn->show(screen);
    musicOn->show(screen);
}