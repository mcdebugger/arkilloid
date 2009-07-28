/*
 *      Frame.h
 *
 *      Copyright 2009 PlugHead Games <plughead@mail.ru>
 *      Copyright 2009 DUGA Project <dev@duganet.ru>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#ifndef FRAME_H
#define FRAME_H

#include "SDLUtils.h"
#include "Constants.h"
#include "Brick.h"
#include "Button.h"
#include "Timer.h"
#include "Texture.h"
#include <vector>
#include "../extern/GLFT_Font/GLFT_Font.h"

class Frame
{
public:
    Frame();
    ~Frame();
    bool init();
    bool initGL();
    bool load_files();
    bool main_loop();
    void exit();
private:
    SDL_Surface *screen;

    SDL_Event event;
    GLFT_Font font;
    bool quit;
};

#endif
