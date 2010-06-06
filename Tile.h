/*
This file is part of "Truth in Darkness".

"Truth in Darknes" is free software: you can redistribute it 
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the 
License, or (at your option) any later version.

"Truth in Darknes" is distributed in the hope that 
it will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See 
the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with "Truth in Darknes". If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <string>

class Tile
{
private:
	unsigned int Type;
	std::string textureDirectory;
	sf::Sprite texture;

public:
	Tile();
	
	//this enum is in no way complete
	//and is subject to change
	typedef enum { null, GRASS, WATER } TileType;
};

#endif // TILE_H