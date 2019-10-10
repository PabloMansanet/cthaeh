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

   sf::Color greyish(43, 47, 59);
   sf::Color blueish(139, 164, 243);

   static const char* windowTitle = "TAK";
   window.setTitle(windowTitle);

   sf::Clock deltaClock;
   Board board = Board(5u, greyish, blueish);

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

      ImGui::End();
      window.clear();

      window.draw(board);

      ImGui::SFML::Render(window);
      window.display();
   }

   ImGui::SFML::Shutdown();
}
