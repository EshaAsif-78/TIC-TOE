#include <iostream>

using namespace std;

// Game board constants
const int ROWS = 3;
const int COLUMNS = 3;

// Game board
char board[ROWS][COLUMNS];

// Players
char player1 = 'X';
char player2 = 'O';

// Current player
char currentPlayer;

// Check for win
bool isWinner(char player) {
  // Check rows
  for (int i = 0; i < ROWS; i++) {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
      return true;
    }
  }

  // Check columns
  for (int i = 0; i < COLUMNS; i++) {
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
      return true;
    }
  }

  // Check diagonals
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }

  if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }

  return false;
}

// Check for draw
bool isDraw() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (board[i][j] == '-') {
        return false;
      }
    }
  }

  return true;
}

void displayBoard() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  // Initialize the game board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      board[i][j] = '-';
    }
  }

  // Start the game
  currentPlayer = player1;

  while (true) {
    // Display the board
    displayBoard();

    // Get the player's move
    int row, column;
    cout << currentPlayer << "'s turn, enter your move (row, column): ";
    cin >> row >> column;

    // Check if the move is valid
    if (row < 0 || row >= ROWS || column < 0 || column >= COLUMNS || board[row][column] != '-') {
      cout << "Invalid move!" << endl;
      continue;
    }

    // Update the board
    board[row][column] = currentPlayer;

    // Check for win
    if (isWinner(currentPlayer)) {
      cout << currentPlayer << " has won the game!" << endl;
      break;
    }

    // Check for draw
    if (isDraw()) {
      cout << "The game is a draw!" << endl;
      break;
    }

    // Switch players
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
  }

  // Ask if the players want to play again
  cout << "Do you want to play again? (y/n): ";
  char answer;
  cin >> answer;

  if (answer == 'y') {
    main();
  }

  return 0;
}


