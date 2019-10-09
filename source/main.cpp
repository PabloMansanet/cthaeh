#include <SFML/Graphics.hpp>
#include <vector>
#include <stdint.h>

#include "imgui.h"
#include "Board.h"
#include "imgui-SFML.h"

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
   Board board = Board(5u, sf::Color::Red, sf::Color::Green);

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
      window.draw(board);

      ImGui::SFML::Render(window);
      window.display();
   }

   ImGui::SFML::Shutdown();
}

