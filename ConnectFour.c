#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>


// Author of Application: Sabin Constantin Lungu
// Purpose of Application: To implement a Connect 4 Game using Data Structures and Algorithms.
// Date of Last Modification: 27/02/2020
// Any Bugs? None currently. Just warnings to be fixed.

#define BOARD_HORIZONTAL 7
#define BOARD_VERTICAL 6 // Vertical slots for the game board

#define PLAYER_ONE_SIZE 128
#define PLAYER_TWO_SIZE 128

#define TRUE 1
#define FALSE 0
#define PLAYER_MOVES 42

void showInstructions();
void showGameHelp();
void displayGameBoard(char *gameBoard);

void playGame(char *gameBoard, const char *GAMEPIECES);
int makeMove(char *gameBoard, int column, const char *GAMEPIECES);
int makeSecondPlayerMove(char *gameBoard, int column, const char *GAMEPIECES);

struct BoardState {
    int playerMoves[PLAYER_MOVES];
    int topValue;
};

enum playerOptions {SHOW_INSTRUCTIONS = 0, SHOW_HELP = 1, PLAY_GAME = 2, PLAY_VS_COMPUTER = 3, QUIT = 4}; // A menu of options


void showInstructions() { // Routine that shows the game instructions
    printf("\n\n The aim of the game is for 2 players to make a straight line of 4 discs.");
    printf("\n\n The line can be vertical, horizontal or diagonal and match 4 to win");

    printf("\n\n Before starting the game, the players decidce randomly which of them will be the beginner, either Player 1 or Player 2.");
    printf("\n\n Moves are made alternatively, one by turn, Player 1 then Player 2");
}

void showGameHelp() {
    printf("\n\n Match 4 Discs diagonally, horizontally or vertically to win.\n ");
}

void playGame(char *gameBoard, const char *GAMEPIECES) { // Routine that starts the game
    char playerOneName[PLAYER_ONE_SIZE]; // Name of player 1
    char playerTwoName[PLAYER_TWO_SIZE]; // Name of player 2

    int namesEntered = 0; // Flag to determine if the names are

    int column = 0;
    int position = 0;

        printf("\n\n Player X: Enter your name please.");
        scanf("%s", playerOneName);
        namesEntered = 1;

        printf("\n Player O: Enter your name please."); // Asks player 2 to enter 
        scanf("%s", playerTwoName);

        namesEntered = 1;

        if(namesEntered == 1) { // If the name has been entered
        
            displayGameBoard(gameBoard); // Show the game board again.
            makeMove(gameBoard, column, GAMEPIECES); // Enable the player to make a move.
        }

        if(strcmp(playerOneName, "0") == 0) { // If the player enters 0 for the name
            exit(1); // Exit
    
        }

        if(strcmp(playerTwoName, "0") == 0) { // If player name entered is 0
            exit(1); // Exit the game
        }

         // Remove trailing lines
         int line_length = strlen(playerOneName);

         if(line_length > 0 && playerOneName[line_length-1] == '\n' && playerTwoName[line_length-1] == '\n') {

             playerOneName[line_length-1] = '\0';
             playerTwoName[line_length-1] = '\0';
         }
}

int makeMove(char *gameBoard, int column, const char *GAME_PIECES) { // Routine that allows Player X to make a move
   int valid_move = 0; // Determines if the slot is a valid move or not.

   printf("\n Player X make a move please. Choose a column");
   scanf("%d", &column);

        if(column > BOARD_VERTICAL) {
            printf("\n Not possible");

            valid_move = 0;
            exit(1);
        }
    
  return 0;
}

void setupBoard(char *gameBoard) {

    for(int i = 0; i <= 6; i++) {

        for(int j = 0; j <= 6; j++) {

            *((gameBoard + i * BOARD_HORIZONTAL + j)) = 'P';
        }
    }
}

int makeSecondPlayerMove(char *gameBoard, int column, const char *GAME_PIECES) { // Routine that allows the second player to make a move.
    return 1;
}

void displayGameBoard(char *gameBoard) { // Routine to display the game board to play in. It will display a Connect 4 Game Board using a 2-D array data structure

     for(int index = 0; index < BOARD_VERTICAL; index++) {

         for(int secondIndex = 0; secondIndex < BOARD_HORIZONTAL; secondIndex++) {

             printf("| %c ",  gameBoard[BOARD_VERTICAL * index + secondIndex]);
         }
         puts("|");
         printf("\n"); // Print a new line
     }
}

void playVsComputer() {
    printf("In Play vs Computer");
}

int main(int argc, char **argv) {
  char gameBoard[BOARD_HORIZONTAL][BOARD_VERTICAL];
  setupBoard(gameBoard);
   
    const char *GAME_PIECES = "XO";
    int thePlayerChoice = 0; // Player choice flag

 do {
     printf("\n\n Welcome to Connect 4");
     printf("\n\n Please choose an option below\n\n");

     printf("\n 0. Show Instructions");
     printf("\n 1. Show Help");
     printf("\n 2. Play Game");

     printf("\n 3. Play vs Computer");
     printf("\n 4. Quit");

     scanf("%d", &thePlayerChoice); // Allows the player to input a choice

      switch(thePlayerChoice) {

          case SHOW_INSTRUCTIONS:
          showInstructions();
          break;

          case SHOW_HELP:
          showGameHelp();
          break;

          case PLAY_GAME:
          setupBoard(gameBoard);
          playGame(gameBoard, GAME_PIECES);
          break;

          case PLAY_VS_COMPUTER:
          playVsComputer();
          break;

          case QUIT:
          printf("Have a good day");

          exit(1);
          break;
      }

      } while(thePlayerChoice != QUIT);

   return 0;
}
