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

#include "ImageManager.h"

const sf::Image& ImageManager::getImage(boost::filesystem::path imagePath)
{
	// if image is in RAM
	if (isImageUsed(imagePath))
	{
		return imageMap[imagePath];
	}
	// if image is NOT in RAM
	
	addImage(imagePath);
	
	return imageMap[imagePath];
}

bool ImageManager::isImageUsed(boost::filesystem::path imagePath)
{
	std::map<boost::filesystem::path, sf::Image>::iterator found;

	found = imageMap.find(imagePath);

	// if image is NOT in RAM
	if ( found == imageMap.end() )
	{
		return false;
	}

	return true;
}

void ImageManager::addImage(boost::filesystem::path imagePath)
{
	sf::Image temp;
	
	// copies EMPTY IMAGE into imageMap 
	// copying an empty image doesn't take up very many resources
	imageMap.insert(std::pair<boost::filesystem::path, sf::Image>
							 (imagePath, temp));

	// load image
	imageMap[imagePath].LoadFromFile(imagePath.string());
}

ImageManager& ImageManager::getManager()
{
	static ImageManager instance;
	return instance;
}
