#include "Board.h"

Board::Board(size_t size,
      sf::Color squareColorA,
      sf::Color squareColorB):
   mSize(size)
{
   mGrid = CreateRectangles(size, squareColorA, squareColorB);
}

std::vector<sf::RectangleShape> Board::CreateRectangles(size_t size,
      sf::Color squareColorA,
      sf::Color squareColorB)
{
   const size_t vectorLength = size * size;
   const sf::Vector2f rectanglesOrigin = sf::Vector2f(50.0, 50.0);
   const sf::Vector2f rectangleDimensions = sf::Vector2f(100.0, 100.0);

   auto rectangles = std::vector<sf::RectangleShape>(vectorLength);

   for (size_t i = 0; i < rectangles.size(); i++) {
      const size_t xPos = (i % size);
      const size_t yPos = (i / size);

      auto color = ((xPos + yPos) % 2 == 0) ? squareColorA : squareColorB;
      rectangles[i].setSize( rectangleDimensions );
      rectangles[i].setFillColor( color );

      const float xOffset = rectangleDimensions.x * xPos;
      const float yOffset = rectangleDimensions.y * yPos;
      const sf::Vector2f offset = sf::Vector2f(xOffset, yOffset);

      rectangles[i].setPosition( rectanglesOrigin + offset );
   }

   return rectangles;
}

void Board::SetColors(sf::Color squareColorA, sf::Color squareColorB)
{
   for (size_t i = 0; i < mGrid.size(); i++) {
      const size_t xPos = (i % mSize);
      const size_t yPos = (i / mSize);
      auto color = ((xPos + yPos) % 2 == 0) ? squareColorA : squareColorB;
      mGrid[i].setFillColor( color );
   }
}


void Board::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
   for (auto& rectangle: mGrid) {
      target.draw(rectangle, states);
   }
}

