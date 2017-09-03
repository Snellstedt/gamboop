#ifndef GAME_BOY_H
#define GAME_BOY_H
/*
gamboop - an open source Game Boy Emulator
Copyright (C) 2017  Isaac Snellgrove

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, write snellgrove.isaac@gmail.com .

*/
#include <iostream>
#include "interrupts.h"

class GameBoy{
public:
    //Constuctor
    GameBoy(std::string rom_in, bool debug_in): controls(), cpu(), display(), interrupts(){

        //detect what type ROM we have, and create the appropriate cartidge object
        
    }
private:
    //freind fucntions to give other components acces to working memory
    // read byte and read word, write byte and write word






    /////////////////////////////////////////////////


    //contains:

    //detect and make the correct cartridge object
    
    //create a Controls
    Controls controls;
    //create a CPU
    Cpu cpu;
    //create a display
    Display display;
    //create an interrupt contoller
    Interrupts interrupts;
    //create the sound module
    // Sound sound;
    
};

#endif