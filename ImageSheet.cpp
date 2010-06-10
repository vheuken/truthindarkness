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

#include "ImageSheet.h"

ImageSheet::ImageSheet(std::string imagePath)
{
	this->imagePath = imagePath;
}

std::string ImageSheet::getImagePath() const
{
	return imagePath;
}

sf::Image ImageSheet::getImageSheetImage() const
{
	return ImageSheetImage;
}

sf::Image ImageSheet::getImage(int tileNum) const
{
	//TODO: return a tile from sf::Image ImageSheetImage

	//ARBITRARY RETURN TO PLEASE COMPILER
	return sf::Image();
}