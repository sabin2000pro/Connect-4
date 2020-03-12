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

#define PLAYER_NAME_SIZE 128

#define TRUE 1
#define FALSE 0
#define PLAYER_MOVES 42 // Number of player moves

char playerOneName[PLAYER_NAME_SIZE];
char playerTwoName[PLAYER_NAME_SIZE];

void showInstructions();
void startGame();
void showGameHelp();
void displayGameBoard(char gameBoard[][BOARD_HORIZONTAL]);
void playGame(char gameBoard[][BOARD_HORIZONTAL]);

int makeMove(char gameBoard[][BOARD_HORIZONTAL]);
int checkWinner(char gameBoard[][BOARD_HORIZONTAL], char token);

int verifyHorizontalFour(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token);
int verifyVerticalFour(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token);

int verifyDiagonalFour(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token);
int verifyDiagonalFourRight(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token);

int checkHorizontal(char gameBoard[][BOARD_HORIZONTAL], char token);
int verticalCheck(char gameBoard[][BOARD_HORIZONTAL], char token);

int diagonalCheck(char gameBoard[][BOARD_HORIZONTAL], char token);
int diagonalCheckRight(char gameBoard[][BOARD_HORIZONTAL], char token);

void updateBoard(char gameBoard[][BOARD_HORIZONTAL],char token, int theColumn);
void saveGame(char gameBoard[][BOARD_HORIZONTAL]);
void loadGame(char gameBoard[][BOARD_HORIZONTAL]); // Routine to load the game

struct stack {
    char gameBoard[BOARD_VERTICAL][BOARD_HORIZONTAL]; // Stores the char 2-d array in a struct
    int currentMove; // Store the current move in a stack struct.
};

void setupStack(struct stack *theStack) {
    theStack->currentMove = -1; // Set the current move to -1.
}

int *popMove(struct stack *theStack, char gameBoard[][BOARD_HORIZONTAL]) { // Routine that will pop a move a player has made
    int *thisMove; // The move to remove.

     if(theStack->currentMove == -1) { // If the stack is empty
         printf("The board is empty, no move to remove"); // No value to remove
         return NULL; // Return nothing
     }

     thisMove = &theStack->gameBoard[theStack->currentMove]; // Set the move to the address value of the stack by pointing to the board current move
     theStack->currentMove--; // Decrement a move.

     return thisMove; // Return the deleted move.
}

enum playerOptions {SHOW_INSTRUCTIONS = 0, SHOW_HELP = 1, PLAY_GAME = 2, PLAY_VS_COMPUTER = 3, LOAD_GAME = 4, QUIT = 5}; // A menu of options


void showInstructions() { // Routine that shows the game instructions
    printf("\n\n The aim of the game is for 2 players to make a straight line of 4 discs.");
    printf("\n\n The line can be vertical, horizontal or diagonal and match 4 to win");

    printf("\n\n Before starting the game, the players decidce randomly which of them will be the beginner, either Player 1 or Player 2.");
    printf("\n\n Moves are made alternatively, one by turn, Player 1 then Player 2");
    printf("\n\n Press S to save game.");
}

void showGameHelp() {
    printf("\n\n Match 4 Discs diagonally, horizontally or vertically to win.\n ");
}

void playGame(char gameBoard[][BOARD_HORIZONTAL]) { // Routine that starts the game
   
    int namesEntered = 0; // Flag to determine if the names are
    int column = 0;
    int theRow = 0;

    int thePlayer = 0;
    int secondPlayer = 0;
    int position = 0;

    printf("\n\n Player X: Enter your name please.");
    scanf("%s", playerOneName);
     namesEntered = 1;

    printf("\n Player O: Enter your name please."); // Asks player 2 to enter 
    scanf("%s", playerTwoName);

    namesEntered = 1;

        if(namesEntered == 1) { // If the name has been entered
    
            displayGameBoard(gameBoard); // Show the game board again.
            makeMove(gameBoard); // Enable the player to make a move.
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
             playerTwoName[line_length-1] = '\0'; // Remove the line
         }
}

int makeMove(char gameBoard[][BOARD_HORIZONTAL]) { // Routine that allows Player X to make a move
   struct stack *theStack;
   int valid_move = 0; // Determines if the slot is a valid move or not.
   int theColumn = 0;

   int counter = 0;
   int nextColumn = 0;

   int game_over = 0; // Game over flag to determine if the game is over. Takes O(1) constant time.

   char token;
   char popMoveFlag;
   char saveGameFlag;

   do {
       counter++;
       if(counter % 2 == 0) { // If the counter is divisible by 2, change player.
           printf("\n Player %s it's your turn now. Choose a column coordinate please", playerTwoName);
           scanf("%d", &theColumn);
           token = 'O';
       }

       else {
           printf("\n Player %s choose a column coordinate please.", playerOneName); // Prompts the player to make a move.
           scanf("%d", &theColumn);
           token = 'X';
       }


        if(theColumn > BOARD_VERTICAL) { // If the column that the user
            printf("\n Not possible");

            valid_move = 0;
            continue;
        }
       
       updateBoard(gameBoard, token, theColumn);
       displayGameBoard(gameBoard);
       checkWinner(gameBoard, token);

       printf("\n Would you like save the game?");
           scanf("  %c", &saveGameFlag);

              if(saveGameFlag == 'N') {
                  printf("\n Game Not Saved");
                  continue;
              }

              if(saveGameFlag == 'Y') {
                  saveGame(gameBoard);
                  printf("\n Game Successfully Saved");
                  continue;
              }

    } while(!game_over); // Loop until the game is not over.
       
  return 0;
}


void updateBoard(char gameBoard[][BOARD_HORIZONTAL], char token, int theColumn) { // Routine to update the game board
    int updated_position = 0;
    for(int i = BOARD_VERTICAL - 1; i >=0; i--) { // Loop over the board

        if(gameBoard[i][theColumn] == ' ') {

            updated_position = 1;
            gameBoard[i][theColumn] = token;
            
             displayGameBoard(gameBoard);  // Display the game board again     

             break;
        }
    }
 }

 int checkWinner(char gameBoard[][BOARD_HORIZONTAL], char token) {
      return (checkHorizontal(gameBoard, token) && (verticalCheck(gameBoard, token)) && (diagonalCheck(gameBoard, token)) || diagonalCheckRight(gameBoard, token));
 }

int verifyHorizontalFour(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token) {
    int counter = 0;

    if(gameBoard[row][column] == gameBoard[row][column +1]) {
        counter++;
    }

     if(gameBoard[row][column] == gameBoard[row][column + 2]) {
        counter++;
    }

     if(gameBoard[row][column] == gameBoard[row][column + 3]) {
        counter++;
    }

     if(gameBoard[row][column] == token) {
        counter++;
    }


    return counter == 4;
}

int verifyVerticalFour(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token) { // Routine that will verify a vertical win
    int counter = 0;

    if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row+1][column]) {
        counter++;
    }

    if(gameBoard[row][column] == gameBoard[row+2][column]) {
        counter++;
    }

   if(gameBoard[row][column] == gameBoard[row+3][column]) {
       counter++;
   }

   if(gameBoard[row][column] == token) { // If the game board's row and column is equal to the winning token
       counter++; // Increment the counter again
   }

   return counter == 4; // Return the counter

    return 0;
}

int verifyDiagonalFour(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token) { // Routin that will verify a diagonal for 4 in a row

int counter = 0; // Set the counter to 0. Takes up O(1) time.

 if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row+1][column+1]) { // If the game board row and column is not an empty string and the row and column matches the one above it
     counter++; // Increment the counter
 }

 if(gameBoard[row][column] == gameBoard[row+2][column+2]) {
     counter++;
 }

 if(gameBoard[row][column] == gameBoard[row+3][column+3]) {
     counter++;
 }

 if(gameBoard[row][column] == token) {
     counter++;
 }

 return counter == 4; // Return the counter


    return 0;
}

int verifyDiagonalFourRight(char gameBoard[][BOARD_HORIZONTAL], int row, int column, char token) {
    int counter = 0;

    if(gameBoard[row][column] != ' ' && gameBoard[row][column] == gameBoard[row+1][column-1]) {
        counter++;
    }

    if(gameBoard[row][column] == gameBoard[row+2][column-2]) {
        counter++;
    }

    if(gameBoard[row][column] == gameBoard[row+3][column-3]) {
        counter++;
    }

    if(gameBoard[row][column] == token) {
        counter++;
    }

    return counter == 4;

    return 0;
}

int verticalCheck(char gameBoard[][BOARD_HORIZONTAL], char token) { // Helper method that checks the vertical board for a win.
 char playAgainToken;
     for(int i = 0; i < BOARD_VERTICAL-3; i++) {
         for(int j = 0; j < BOARD_HORIZONTAL; j++) {
            
          if(verifyVerticalFour(gameBoard, i, j, token) == 1) { // If the verification of the vertical four is true
              printf("Player : %c  you are the winner. Would you like to play again? Y for Yes or N for No", token); // Display the winner of the game.
              scanf(" %c", &playAgainToken); // Get the user input if the player wants to play again.

             if(playAgainToken == 'N') {
                 printf("\n Have a good day");
                 exit(1);
             }

             if(playAgainToken == 'Y') { // If the user enters Y
                startGame();
             }

             if(playAgainToken != 'N' || playAgainToken != 'Y') {
                 printf("\n Not a valid option. The game ends here");
                 exit(1);
             }
            
              return 1;
            }
         }
    }

    return 1;
}

int diagonalCheck(char gameBoard[][BOARD_HORIZONTAL], char token) {
char playAgainToken;
  for(int i = 0; i < BOARD_VERTICAL -3; i++) {
      for(int j = 0; j < BOARD_HORIZONTAL - 3; j++) {

          if(verifyDiagonalFour(gameBoard, i, j , token) == 1) {

              printf("Player : %c  you are the winner. Would you like to play again? Y for Yes or N for No", token);
              scanf(" %c", &playAgainToken); // Get the user input if the player wants to play again.

             if(playAgainToken == 'N') {
                 printf("\n Have a good day");
                 exit(1);
             }

             if(playAgainToken == 'Y') {
                 startGame();
             }
              return 1;

          }
      }
  }

    return 0;
}

int diagonalCheckRight(char gameBoard[][BOARD_HORIZONTAL], char token) {
    char playAgainToken;
    for(int i = 0; i < BOARD_VERTICAL-3; i++) {
        for(int j = 3; j < BOARD_HORIZONTAL; j++) {

            if(verifyDiagonalFourRight(gameBoard, i, j, token) == 1) {
                printf("Player : %c  you are the winner. Would you like to play again? Y for Yes or N for NO", token);
                scanf(" %c", &playAgainToken); // Get the user input if the player wants to play again.

             if(playAgainToken == 'N') {
                 printf("\n Have a good day");
                 exit(1);
             }

             if(playAgainToken == 'Y') {
                 startGame();
             }

              return 1;

            }
        }
    }

    return 0;
}

int checkHorizontal(char gameBoard[][BOARD_HORIZONTAL], char token) { // Routine that checks the horizontal for a match of 4 to determine the winner
    char playAgainToken;
    
     for(int i = 0; i < BOARD_VERTICAL; i++) {
         for(int j = 0; j < BOARD_HORIZONTAL-3; j++) {
            
          if(verifyHorizontalFour(gameBoard, i, j, token) == 1) {
              
             printf("Player : %c you are the winner. Would you like to play again? Y for Yes or N for NO", token); // Display who the winner is.
             scanf(" %c", &playAgainToken); // Get the user input if the player wants to play again.

             if(playAgainToken == 'N') {
                 printf("\n Have a good day");
                 exit(1);
             }

             if(playAgainToken == 'Y') {
                 startGame();
             }

             return 1;
            }
         }
     }

     return 1;
}

void setupBoard(char gameBoard[][BOARD_HORIZONTAL]) {

    for(int i = 0; i <= BOARD_VERTICAL; i++) {

        for(int j = 0; j <= BOARD_VERTICAL; j++) {

           gameBoard[i][j] = ' ';
        }
    }
    
 gameBoard[BOARD_VERTICAL-1][0] = ' ';
    
}

void displayGameBoard(char gameBoard[][BOARD_HORIZONTAL]) { // Routine to display the game board to play in. It will display a Connect 4 Game Board using a 2-D array data structure
  system("clear");
     for(int index = 0; index < BOARD_VERTICAL; index++) {

         for(int secondIndex = 0; secondIndex < BOARD_HORIZONTAL; secondIndex++) {

             printf("| %c ",  gameBoard[index][secondIndex]);
         }

         puts("|");

      puts("-----------------------------");

     }
}

void playVsComputer() {
   
}

void saveGame(char gameBoard[][BOARD_HORIZONTAL]) {
 FILE *savedGame = NULL;
  if(!savedGame) {
   
   savedGame = fopen("Desktop/Connect-4/connectfourgame.txt", "w");
   fprintf(savedGame, "%s", gameBoard);
    printf("File written");
  }

  else {
      printf("No file found");
  }

  fclose(savedGame);
}

void loadGame(char gameBoard[][BOARD_HORIZONTAL]) {
 
}

void startGame() {
 char gameBoard[BOARD_HORIZONTAL][BOARD_VERTICAL];
 memset(gameBoard, ' ', BOARD_HORIZONTAL * BOARD_VERTICAL);
   
 int thePlayerChoice = 0; // Player choice flag

 do {
     printf("\n\n Welcome to Connect 4");
     printf("\n\n Please choose an option below\n\n");

     printf("\n 0. Show Instructions");
     printf("\n 1. Show Help");
     printf("\n 2. Play Game");

     printf("\n 3. Play vs Computer");
     printf("\n 4. Load Game");
     printf("\n 5. Quit");

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
          playGame(gameBoard);
          break;

          case PLAY_VS_COMPUTER:
          playVsComputer();
          break;

          case LOAD_GAME:
          loadGame(gameBoard);
          break;

          case QUIT:
          printf("Have a good day");

          exit(1);
          break;
      }

      } while(thePlayerChoice != QUIT);
}

int main(int argc, char **argv) {
    startGame();

   return 0;
}