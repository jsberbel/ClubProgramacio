#include <iostream>
#include <ctime>
#include <atomic>
#include <thread>
#include <conio.h>

#define FILES 20
#define COLUMNES 20

#define TIME_DELAY 120

static std::atomic<int> key{ -1 };

struct Player {
	int x;
	int y;
};

void ProcessInput(Player &player) {
	switch (key) {
	case 87: case 119: //w
		if (player.y > 0) --player.y; break;
	case 65: case 97: //a
		if (player.x > 0) --player.x; break;
	case 83: case 115: //s
		if (player.y < FILES-1) ++player.y; break;
	case 68: case 100: //d
		if (player.x < COLUMNES-1) ++player.x; break;
	}
	key = -1;
}

void UpdateMap(char map[FILES][COLUMNES], Player &player) {
	for (int i = 0; i < FILES; ++i) {
		for (int j = 0; j < COLUMNES; ++j) {
			map[i][j] = '.';
		}
	}
	map[player.y][player.x] = '@';
}

void DrawMap(char map[FILES][COLUMNES]) {
	for (int i = 0; i < FILES; ++i) {
		for (int j = 0; j < COLUMNES; ++j) {
			std::cout << map[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main() {
	Player player = { FILES/2, COLUMNES/2 };
	char map[FILES][COLUMNES];

	int lasTime = clock();
	bool running = true;

	std::thread inputManager([]() { while (true) key = _getch(); });
	inputManager.detach();

	while (running) {
		if (clock() > lasTime + TIME_DELAY) {
			system("cls");

			ProcessInput(player);
			UpdateMap(map, player);
			DrawMap(map);			

			lasTime = clock();
		}
	}
}