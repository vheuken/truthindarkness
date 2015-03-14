# Overview #

SpriteSheet class is used to access individual tiles of a spritesheet.


# Details #


| **Signature** | **Parameters** | **Output** |
|:--------------|:---------------|:-----------|
| SpriteSheet(const sf::Image& spriteSheetImage)) | **_spriteSheetImage_** - image for SpriteSheet |  |
| sf::Sprite getTile(int tileID) | **_tileID_** - used to get individual tiles from SpriteSheet | returns an sf::Sprite with its subrect set according to the tileID |
| sf::Sprite getSpriteSheet() |  | returns an sf::Sprite that is the entire spritesheet |