/*
Copyright (c) 2011, Vincent Heuken
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "ImageManager.h"

const sf::Image& ImageManager::getImage(const boost::filesystem::path& 
										imagePath)
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

bool ImageManager::isImageUsed(const boost::filesystem::path& imagePath)
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

void ImageManager::addImage(const boost::filesystem::path& imagePath)
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
