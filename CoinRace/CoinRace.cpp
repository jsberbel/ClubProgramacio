#include <iostream>
#include <ctime>
#include <atomic>
#include <thread>
#include <conio.h>

///////////////////////////////////////////
//				 DEFINES				 //
///////////////////////////////////////////
// Map dimensions
#define ROWS 20
#define COLS 20
// Time delay for each frame (milliseconds)
#define TIME_DELAY 125
// Max number of coins in map
#define MAX_COINS ROWS/2

///////////////////////////////////////////
//			 GLOBAL VARIABLES			 //
///////////////////////////////////////////
static std::atomic<int> g_keyDown{ -1 }; // key pressed in ascii decimal codification
static bool g_running{ true }; // whether if game is playing or not
static int score{ 0 }; // user score

// Coin class that stores its position and whether if the coin has bet catched or not
struct Coin {
	int x;
	int y;
	bool exists;
};

// Player class that store its position
struct Player {
	int x;
	int y;
};

// Process the game input for players actions and leavin the game
void ProcessInput(Player &player) {
	switch (g_keyDown) {
	case 87: case 119: // w-W
		if (player.y > 0) --player.y; break; // move player up and check limits
	case 65: case 97: // a-A
		if (player.x > 0) --player.x; break; // move player left and check limits
	case 83: case 115: // s-S
		if (player.y < ROWS-1) ++player.y; break; // move player down and check limits
	case 68: case 100: // d-D
		if (player.x < COLS-1) ++player.x; break; // move player right and check limits
	case 27: // ESC
		g_running = false; // leave the current game
	}
	g_keyDown = -1;
}

// Check if player gets a coin
void CheckCollision(Player &player, Coin *coins) {
	for (int i = 0; i < MAX_COINS; ++i) {
		if (coins[i].y == player.y && coins[i].x == player.x && coins[i].exists) { // if coin exists and its position is the same as the player position
			++score; // increment user score
			coins[i].exists = false; // kill de coin
		}
	}
}

// Update the whole game logic by filling the map matrix 2D
void UpdateGame(char map[ROWS][COLS], Player &player, Coin *coins) {
	ProcessInput(player);
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			map[i][j] = '.'; // fill the map with points by default
		}
	}
	for (int i = 0; i < MAX_COINS; ++i) 
		if (coins[i].exists) map[coins[i].y][coins[i].x] = '$'; // if coin exists, print it as a dollar symbol
	map[player.y][player.x] = '@'; // print the player as an arroba
	CheckCollision(player, coins);
}

// Draw the whole game by printing the content of the map matrix 2D
void DrawGame(char map[ROWS][COLS]) {
	system("cls");
	for (int i = 0; i < COLS*2; ++i) std::cout << '/';
	std::cout << std::endl;
	for (int i = 0; i < COLS-5; ++i) std::cout << ' ';
	std::cout << "COIN RACE" << std::endl;
	for (int i = 0; i < COLS*2; ++i) std::cout << '/';
	std::cout << std::endl;
	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			std::cout << map[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Score: " << score;
}

int main() {
	srand(unsigned(time(nullptr))); // set a random seed for rand()

	Player player = { rand() % ROWS, rand() % COLS }; // create player object with random position
	Coin coins[MAX_COINS]; // create array of coins
	char map[ROWS][COLS]; // create map matrix 2D

	for (int i = 0; i < MAX_COINS; ++i) coins[i] = { rand() % ROWS, rand() % COLS, true }; // initialize coins positions randomly

	int lastTime = clock(); // set up a time counter for timestep limiter

	std::thread inputManager([]() { while (true) g_keyDown = _getch(); }); // throw a thread with lambda function able to check always the user keyboard input
	inputManager.detach(); // detach the thread to execute parallely until game ends

	while (g_running) { // while game is still playing
		if (clock() > lastTime + TIME_DELAY) { // run for every timestep (if current time is greater than last time + delay between each frame)
			UpdateGame(map, player, coins);
			DrawGame(map);
			lastTime = clock(); // last time equals now to current time
		}
	}
}