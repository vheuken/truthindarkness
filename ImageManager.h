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

#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

#include <map>
#include <utility>
#include <boost/filesystem.hpp>
#include <SFML/Graphics.hpp>

class ImageManager
{
private:
	std::map<boost::filesystem::path, sf::Image> imageMap;
	bool isImageUsed(boost::filesystem::path imagePath);
	void addImage(boost::filesystem::path imagePath);

public:
	const sf::Image* getImage(boost::filesystem::path imagePath);	
};

#endif // IMAGE_MANAGER_H
