//============================================================================
// Name        : SFML_Basic.cpp
// Author      : Saulo Campos
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "lib.hpp"
using namespace std;

int main() {

	const int width = 400;
	const int height = 400;
	stringstream titulo;

	sf::RenderWindow window(sf::VideoMode(width, height), "Titulo");

	window.setVerticalSyncEnabled(true);





	while (window.isOpen()) {


		sf::Event event;
		while (window.pollEvent(event)) {
			/*
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			*/

			switch(event.type){
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				cout <<  "pessionou uma tecla!" << endl ;

				/*
				if(event.key.scancode == sf::Keyboard::Scan::Space){
					cout <<" pulo" << endl;
				}
				 	*/

				std::cout << "scancode: " << event.key.scancode << std::endl;
				std::cout << "code: " << event.key.code << std::endl;
				std::cout << "control: " << event.key.control << std::endl;
				std::cout << "alt: " << event.key.alt << std::endl;
				std::cout << "shift: " << event.key.shift << std::endl;
				std::cout << "system: " << event.key.system << std::endl;
				std::cout << "description: " << sf::Keyboard::getDescription(event.key.scancode).toAnsiString() << std::endl;
				std::cout << "localize: " << sf::Keyboard::localize(event.key.scancode) << std::endl;
				std::cout << "delocalize: " << sf::Keyboard::delocalize(event.key.code) << std::endl;


				break;

			case sf::Event::LostFocus:
				cout <<  "pessionou uma mouse!" << endl ;
				break;



			case sf::Event::Resized:

				    std::cout << "new width: " << event.size.width << std::endl;
				    std::cout << "new height: " << event.size.height << std::endl;

				    titulo << "Titulo" << "[" << event.size.width << ":" <<  event.size.height << "]\n";
				    window.setTitle(titulo.str());

				    std::cout << "the escape key was pressed" << std::endl;

				    break;
			default:
			break;
			}


		}

		window.clear(sf::Color::Green);
		window.display();


	}

	return 0;
}
