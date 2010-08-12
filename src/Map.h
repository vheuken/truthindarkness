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

You should have received a copy of the GNU General Public License along
with "Truth in Darkness". If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAP_H
#define MAP_H

#include "SpriteSheet.h"
#include "ImageManager.h"
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>
#include <string>

class Map
{
private:
	// obtains data from the map file
	void mapFileParser();

	boost::filesystem::ifstream mapFile;

	// map properties
	std::string mapName;
	int mapWidth, mapHeight;
		

public:
	Map(boost::filesystem::path mapFilePath);
};

#endif // MAP_H
