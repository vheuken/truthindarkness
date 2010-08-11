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

#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(sf::Image spriteSheetImage)
{
	spriteSheet.SetImage(spriteSheetImage);
}

sf::Sprite SpriteSheet::getTile(int tileID)
{
	// if sprite is already in spriteMap
	if ( isSpriteUsed(tileID) )
	{
		return spriteSheetMap[tileID];
	}
	
	addSprite(tileID);

	return spriteSheetMap[tileID];
}

bool SpriteSheet::isSpriteUsed(int tileID)
{
	std::map<int, sf::Sprite>::iterator found;

	found = spriteSheetMap.find(tileID);

	// if sprite is NOT in the map
	if ( found == spriteSheetMap.end() )
	{
		return false;
	}

	return true;
}

void SpriteSheet::addSprite(int tileID)
{
	setSpriteSheetSubRect(tileID);
	
	spriteSheetMap.insert(std::pair<int, sf::Sprite>(tileID, spriteSheet));
}

void SpriteSheet::setSpriteSheetSubRect(int tileID)
{
	// coordinates for left and right of rect
	int leftCoord, topCoord;		

	leftCoord = (TILE_X * tileID) % (int)spriteSheet.GetSize().x;

	topCoord = TILE_Y * ((int) ((TILE_Y * tileID) / 
			   spriteSheet.GetSize().y)-1);

	spriteSheet.SetSubRect(sf::IntRect(leftCoord,
									   topCoord,
									   leftCoord + TILE_X,
									   topCoord  + TILE_Y));
}
