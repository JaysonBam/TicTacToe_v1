# TicTacToe_v1
Repository Description: Tic-Tac-Toe Game

This repository contains the source code for a Tic-Tac-Toe game implemented in C++. The game is played between two players on a 3x3 board. The code utilizes various functions and structures to handle player input, board manipulation, and game logic.

The main components of the code include:

1. Board Initialization: The program initializes the game board represented by a 2D character array `BV` with numbers from 1 to 9 representing empty positions on the board.

2. Player Structure: The `Player` structure holds information about each player, including their name, chosen character (X or O), and the number of wins.

3. Game Functions: Several functions are implemented to handle different aspects of the game. These include:
   - `checkWin()`: Checks for a winning condition by examining the board state.
   - `intIdToPointer()`: Converts a selected field ID to a pointer on the board.
   - `ifAvailable()`: Checks if a selected position on the board is available for selection.
   - `printAvailable()`: Displays the available field IDs for the current turn.
   - `printBoard()`: Prints the current state of the game board.
   - `resetBoard()`: Resets the game board to its initial state.
   - `playerTurn()`: Manages a player's turn, including input validation, updating the board, and checking for a win condition.
   - `uppercase()`: Converts a string to uppercase.
   - `GetPlayerInfo()`: Retrieves player information, such as names and characters, from user input.
   - `PrintWinner()`: Prints the final result of the game, including the number of wins for each player or a draw.
   - `SwapPlayers()`: Swaps the positions of the two players for the next game.

4. Game Flow: The `main()` function orchestrates the game flow by initializing the board, getting player information, and managing the turns until the game is over. It includes a loop that allows for multiple games to be played consecutively. After each game, the players have the option to play again or quit.

The repository provides a complete implementation of the Tic-Tac-Toe game, allowing players to compete against each other. It demonstrates the use of functions, data structures, loops, and conditional statements to create an interactive game experience.
