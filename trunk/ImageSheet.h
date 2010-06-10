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

#ifndef IMAGE_SHEET_H
#define IMAGE_SHEET_H

#include <SFML/Graphics.hpp>
#include <string>

#include "Tile.h"

class ImageSheet
{
private:
	sf::Image imageSheetImage;
	std::string imagePath;

	//count the number of rows/cols in imagesheet
	int countRows() const;
	int countCols() const;

public:
	ImageSheet(std::string imagePath);
	std::string getImagePath() const;
	sf::Image getImageSheetImage() const;
	
	//returns an image to be turned into a tile
	sf::Image getImage(int imageNum) const;
};

#endif // IMAGE_SHEET_H