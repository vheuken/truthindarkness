/*
This file is part of "Truth in Darknesss".

"Truth in Darkness" is free software: you can redistribute it 
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation, either version 3 of the 
License, or (at your option) any later version.

"Truth in Darkness" is distributed in the hope that 
it will be useful, but WITHOUT ANY WARRANTY; without even the implied
warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See 
the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with "Truth in Darkness". If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TILE_SET_H
#define TILE_SET_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Tile.h"

class TileSet
{
private:
	sf::Image tileSetImage;
	std::string imageDirectory;	

public:
	TileSet(std::string imageDirectory);
	std::string getDirectory() const;
	sf::Image getTileSetImage() const;
	
	//returns a tile
	Tile getTile(int tileNum) const;
};

#endif // TILE_SET_H