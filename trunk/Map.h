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

#ifndef MAP_H
#define MAP_H

#include <fstream>
#include <string>

class Map
{
private:
	std::string mapName;
	std::string mapFilePath;
	std::ifstream mapFile;

	//map dimensions
	int width;
	int height;

	//gets all info from map file
	void parseMapFile();

public:
	Map(std::string mapFileDirectory);
	int getWidth() const;
	int getHeight() const;
	std::string getMapFilePath() const;
};

#endif // MAP_H