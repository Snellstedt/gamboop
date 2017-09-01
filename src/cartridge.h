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

// cartridge class
// each MBC class will inherit the parent cartidge class
// upon startup, the emulator will detect what kind of MBC
// the cartidge will use, and instantiate an object 
// appropriatley using polymorphism

//base class. this class loads up the run upon construction, but does not 
//provide any bank switching. The only two commercial cames this will run 
//should be Tetris and Dr. Mario

class Cartridge{
public:
    //Constructor
    Cartridge();
    
private:
};