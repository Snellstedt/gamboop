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

#include <iostream> //std IO
#include <cstring>
#include <string>
#include <getopt.h>

#include "cartridge.h"
#include "controls.h"
#include "cpu_core.h"
#include "display.h"
#include "game_boy.h"
#include "interrupts.h"
#include "sound.h"
#include "timings.h"

using u8 = unsigned char;
using u16 = unsigned short;
using s8 = signed char;

int main(int argc, char** args){

	std::string rom_name;
    int c;
    bool debug = false;
    //process command line//////////////////////////////////////////////////////////
    while (1) {
        static struct option long_options[] = {
                { "rom", required_argument, 0, 'r' },
                { "debug", no_argument, 0, 'd'},
                { 0,0,0,0 }
            };
            /*getopt_long stores the option index here*/
            int option_index = 0;
            c = getopt_long(argc, args, "r:d",long_options, &option_index);

            //detect the end of the options
            if (c == -1) break;
 
            switch (c) {
            case 0: //if this option set a flag, do nothing else now
                if (long_options[option_index].flag != 0) break;
                break;
            case 'r':{
            	
            	rom_name = std::string(optarg);
                break;
            }

            case 'd':{
                debug = true;
                break;
            }

            default:
                std::cout << "You dun goofed\n";
                return 1;
                break;
            }
    }// end while loop
    ///end getopt //////////////////////////////////////////////////////////////////

}