#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdint>

class Board: public sf::Drawable
{
public:
   Board(size_t size, sf::Color squareColorA, sf::Color squareColorB);

   void SetColors(sf::Color squareColorA, sf::Color squareColorB);

   sf::View getLetterboxView(sf::View view, float windowWidth, float windowHeight);

private:
   void draw(sf::RenderTarget& target, sf::RenderStates states) const;
   std::vector<sf::RectangleShape> CreateRectangles(size_t size,
         sf::Color squareColorA,
         sf::Color squareColorB);
   const size_t mSize;
   std::vector<sf::RectangleShape> mGrid;
};


#endif
