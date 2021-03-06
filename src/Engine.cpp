/*
 *		Engine.cpp - Arkilloid core engine sources
 *
 *		Copyright 2012 Maxim Kachur <mcdebugger@duganet.ru>
 *		
 *		This file is part of Arkilloid.
 *
 *		Arkilloid is free software: you can redistribute it and/or modify
 *		it under the terms of the GNU General Public License as published by
 *		the Free Software Foundation, either version 3 of the License, or
 *		(at your option) any later version.
 *
 *		Arkilloid is distributed in the hope that it will be useful,
 *		but WITHOUT ANY WARRANTY; without even the implied warranty of
 *		MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *		GNU General Public License for more details.
 *
 *		You should have received a copy of the GNU General Public License
 *		along with Arkilloid.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Engine.h"
#include "Game.h"

Engine::Engine() {
	surf_engine = NULL;
	
	engine_running = true;
}

int Engine::Exec() {
	
	if(Init() == false) {
		return -1;
	}
	
	Game game;
	if(game.Exec() == false)
	{
		return 1;
	}
	
	game.Close();
	Cleanup_Process();
	
	return 0;
}
