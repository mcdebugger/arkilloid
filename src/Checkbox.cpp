//Checkbox.cpp
#include "Checkbox.h"
#include <report.hpp>

extern int stateID;
extern int nextState;

Checkbox::Checkbox(int x, int y, std::string filename)
{
    filename = path_construct("images", filename);
   	report("Creating checkbox \"" + filename + "\"", MSG_DEBUG);
    checked = true;
    buttonSheet = new Texture;
    buttonSheet->load_from_file(filename);

    buttonSheet->num_vclip = 4;

    clips[CLIP_MOUSEOVER].x = 0;
    clips[CLIP_MOUSEOVER].y = 0;
    clips[CLIP_MOUSEOVER].w = buttonSheet->w;
    clips[CLIP_MOUSEOVER].h = buttonSheet->h/4;

    clips[CLIP_MOUSEOUT].x = 0;
    clips[CLIP_MOUSEOUT].y = buttonSheet->h/4;
    clips[CLIP_MOUSEOUT].w = buttonSheet->w;
    clips[CLIP_MOUSEOUT].h = buttonSheet->h/2;

    clips[CLIP_MOUSEOVER_CHECKED].x = 0;
    clips[CLIP_MOUSEOVER_CHECKED].y = buttonSheet->h/2;
    clips[CLIP_MOUSEOVER_CHECKED].w = buttonSheet->w;
    clips[CLIP_MOUSEOVER_CHECKED].h = 3*buttonSheet->h/4;

    clips[CLIP_MOUSEOUT_CHECKED].x = 0;
    clips[CLIP_MOUSEOUT_CHECKED].y = 3 * buttonSheet->h/4;
    clips[CLIP_MOUSEOUT_CHECKED].w = buttonSheet->w;
    clips[CLIP_MOUSEOUT_CHECKED].h = buttonSheet->h;

    box.x = x;
    box.y = y;
    box.w = buttonSheet->w;
    box.h = buttonSheet->h/4;

    clip = clips[CLIP_MOUSEOUT_CHECKED];
}

void Checkbox::handle_events(SDL_Event &event,void(callback)(void))
{
    //mouse_offsets
    int mouse_x,mouse_y;

    if(event.type == SDL_MOUSEMOTION)
    {
        mouse_x = event.motion.x;
        mouse_y = event.motion.y;

        if((mouse_x > box.x)&&(mouse_y > box.y)&&
           (mouse_x < box.x+box.w)&&(mouse_y < box.y+box.h))
        {
            if(checked == true)
                clip = clips[CLIP_MOUSEOVER_CHECKED];
            else
                clip = clips[CLIP_MOUSEOVER];
        }
        else
        {
            if(checked == true)
                clip = clips[CLIP_MOUSEOUT_CHECKED];
            else
                clip = clips[CLIP_MOUSEOUT];
        }
    }
    if(event.type == SDL_MOUSEBUTTONDOWN)
    {
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            mouse_x = event.button.x;
            mouse_y = event.button.y;
            if((mouse_x > box.x)&&(mouse_y > box.y)&&
                (mouse_x < box.x+box.w)&&(mouse_y < box.y+box.h))
            {
                //clip = clips[MOUSE_DOWN];
                change();
                callback();
            }
        }
    }
}

void Checkbox::change()
{
	if(checked)	uncheck();
	else check();
}
void Checkbox::check()
{
	checked = true;
	clip = clips[CLIP_MOUSEOUT_CHECKED];
}
void Checkbox::uncheck()
{
	checked = false;
	clip = clips[CLIP_MOUSEOUT];
}
