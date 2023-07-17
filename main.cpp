#include "kernel.cuh"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Vec3f.h"
#include "Game.h"

int main() {
	Game game(500, 500);

	int arraySize = 5;
	int* a = new int[arraySize] {1, 2, 3, 4, 5};
	int* b = new int[arraySize] {10, 20, 30, 40, 50};
	int* c = new int[arraySize];

	go(a, b, c, arraySize);

	std::cout << "{1, 2, 3, 4, 5} + {10, 20, 30, 40, 50} = {" << c[0] << ", " << c[1] << ", " << c[2] << ", " << c[3] << ", " << c[4] << "}\n";

	delete[] a;
	delete[] b;
	delete[] c;

	while (game.open()) {
		game.eventHandler();
		game.window->clear(sf::Color(0, 0, 0));
		game.window->display();
	}

	return 0;
}