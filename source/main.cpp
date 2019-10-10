#include <SFML/Graphics.hpp>
#include <vector>
#include <stdint.h>

#include "imgui.h"
#include "Board.h"
#include "imgui-SFML.h"

int main()
{
	int resX = 640;
    int resY = 480;
	sf::RenderWindow window(sf::VideoMode(640, 480), "");

	sf::View view;
    view.setSize( resX, resY );
    view.setCenter( view.getSize().x / 2, view.getSize().y / 2 );
    view = getLetterboxView( view, resX, resY ); 

    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    sf::Color greyish(43, 47, 59);
    sf::Color blueish(139, 164, 243);	

    char windowTitle[255] = "TAK";
    window.setTitle(windowTitle);
    //window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.

    sf::Clock deltaClock;
    Board board = Board(5u, greyish, blueish);

    while (window.isOpen()) {
    	sf::Event event;
        while (window.pollEvent(event)) {
        	ImGui::SFML::ProcessEvent(event);

        	if (event.type == sf::Event::Closed) {
        		window.close();
            }

            if (event.type == sf::Event::Resized) {
                view = getLetterboxView( view, event.size.width, event.size.height );
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Settings");

		//

        ImGui::End();

        window.clear();

        window.setView(view);

        window.draw(board);

        ImGui::SFML::Render(window);
        window.display();
    }

   ImGui::SFML::Shutdown();
}
