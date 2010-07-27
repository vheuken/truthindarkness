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

#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include "ImageManager.h"
#include <SFML/Graphics.hpp>
#include <map>

class SpriteSheet
{
private:
	// map holds multiple "copies" of the same sprite 
	// with a set subrect
	// key valuerefers to tile ID
	std::map<int, sf::Sprite> spriteSheetMap;

public:
	SpriteSheet(sf::Image spriteSheetImage);

};

#endif // SPRITE_SHEET_H
