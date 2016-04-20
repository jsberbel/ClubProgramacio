#include <iostream>
using namespace std;

#define PLAYER1_TURN 0
#define PLAYER2_TURN 1

#define PLAYER1_MARK 'X'
#define PLAYER2_MARK 'O'

#define MAX_CELLS 9

enum GameState { PLAY, WINNER, EXIT };


// --------------------------------------------------------------- //
// GLOBAL VARIABLES
// --------------------------------------------------------------- //
char gameBoard[MAX_CELLS] = { '1','2','3','4','5','6','7','8','9' };
int player = PLAYER1_TURN;
char mark = PLAYER1_TURN;
GameState gameState = PLAY;


// --------------------------------------------------------------- //
// MAIN FUNCTIONS
// --------------------------------------------------------------- //

/* CheckWin returns de game status
- PLAY if game is in progress
- WINNER if game over and there's a winner
- EXIT if game is over and nobody wins */
GameState CheckWin() {
	// TODO
	return PLAY;
}

// DrawBoard prints the game board on the screen
void DrawBoard() {
	system("cls");

	cout << "//////////////////////////\n";
	cout << "//\tTic Tac Toe\t//\n";
	cout << "//////////////////////////\n\n";

	cout << "Player 1 (X) - Player 2 (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << gameBoard[0] << "  |  " << gameBoard[1] << "  |  " << gameBoard[2] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameBoard[3] << "  |  " << gameBoard[4] << "  |  " << gameBoard[5] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << gameBoard[6] << "  |  " << gameBoard[7] << "  |  " << gameBoard[8] << endl;

	cout << "     |     |     " << endl << endl;
}

// DoLogic gets the player input and checks the character entered in order to put a mark
void DoLogic() {
	// TODO
}

int main() {
	while (gameState == PLAY) {
		gameState = CheckWin();
		DrawBoard();
		DoLogic();
	}

	DrawBoard();
	if (gameState == WINNER) cout << "==>\aPlayer " << player << " win " << endl;
	else cout << "==>\aGame draw" << endl;

	system("pause");

	return 0;
}