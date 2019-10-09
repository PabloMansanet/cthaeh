#include <SFML/Graphics.hpp>
#include <vector>
#include <stdint.h>

#include "imgui.h"
#include "imgui-SFML.h"

std::vector<sf::RectangleShape> CreateRectangles()
{
   const size_t gridSide = 7u;
   const size_t vectorLength = gridSide * gridSide;
   const sf::Vector2f rectanglesOrigin = sf::Vector2f(50.0, 50.0);
   const sf::Vector2f rectangleDimensions = sf::Vector2f(100.0, 100.0);

   auto rectangles = std::vector<sf::RectangleShape>(vectorLength);

   for (size_t i = 0; i < rectangles.size(); i++) {
      const size_t xPos = (i % gridSide);
      const size_t yPos = (i / gridSide);

      auto color = ((xPos + yPos) % 2 == 0) ? sf::Color::Cyan : sf::Color::White;
      rectangles[i].setSize( rectangleDimensions );
      rectangles[i].setFillColor( color );

      const float xOffset = rectangleDimensions.x * xPos;
      const float yOffset = rectangleDimensions.y * yPos;
      const sf::Vector2f offset = sf::Vector2f(xOffset, yOffset);

      rectangles[i].setPosition( rectanglesOrigin + offset );
   }

   return rectangles;
}

int main()
{
   sf::RenderWindow window(sf::VideoMode(640, 480), "");
   window.setVerticalSyncEnabled(true);
   ImGui::SFML::Init(window);

   sf::Color bgColor;

   float color[3] = { 0.f, 0.f, 0.f };

   char windowTitle[255] = "TAK";
   window.setTitle(windowTitle);
   //window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.

   sf::Clock deltaClock;
   auto rectangles = CreateRectangles();

   while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
         ImGui::SFML::ProcessEvent(event);

         if (event.type == sf::Event::Closed) {
            window.close();
         }
      }

      ImGui::SFML::Update(window, deltaClock.restart());

      ImGui::Begin("Settings");

      if (ImGui::ColorEdit3("Background color", color)) {
         bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
         bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
         bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
      }

      ImGui::End();

      window.clear(bgColor);
      for (auto& rectangle: rectangles) {
         window.draw(rectangle);
      }

      ImGui::SFML::Render(window);
      window.display();
   }

   ImGui::SFML::Shutdown();
}

