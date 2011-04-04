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

#include "SpriteSheet.h"

SpriteSheet::SpriteSheet(const sf::Image& spriteSheetImage)
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
#include <iostream>
void SpriteSheet::setSpriteSheetSubRect(int tileID)
{
	// coordinates for left and right of rect
	int leftCoord, topCoord;		

	leftCoord = (TILE_X * (tileID-1)) % (int)spriteSheet.GetImage()->GetWidth();
	std::cout << "leftCoord = " << leftCoord << std::endl;
	topCoord = (TILE_Y * ((int) ((TILE_Y * tileID-1) / 
			   spriteSheet.GetImage()->GetHeight())-1)) + TILE_Y;

	std::cout << "topCoord = " << topCoord << std::endl;
	spriteSheet.SetSubRect(sf::IntRect(leftCoord,
									topCoord,
									leftCoord + TILE_X,
									topCoord  + TILE_Y));
}

sf::Sprite SpriteSheet::getSpriteSheet()
{
	return spriteSheet;
}
