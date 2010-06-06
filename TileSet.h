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

#ifndef TILE_SET_H
#define TILE_SET_H

#include <SFML/Graphics.hpp>
#include <string>

class TileSet
{
private:
	sf::Image tileSetImage;
	std::string imageDirectory;	

public:
	TileSet(std::string imageDirectory);
	std::string getDirectory();
	sf::Image getTileSetImage();
	
	//returns a tile
	sf::Image getTile(int tileNum);
};

#endif // TILE_SET_H