# Overview #

ImageManager is used to load image files into the game. It makes sure that only one copy of any image is loaded into memory at any given time.

It incorporates the singleton pattern. There should only be one instance of ImageManager.

# Members #

| **Signature** | **Parameters** | **Output** |
|:--------------|:---------------|:-----------|
| const sf::Image& getImage(boost::filesystem::path imagePath) | **_imagePath_** - path to image file | returns the image |
| static ImageManager& getManager() |  | returns the instance of ImageManager used by the whole program |