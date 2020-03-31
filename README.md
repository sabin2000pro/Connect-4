# Connect-4 - Purpose of Application
A Connect 4 Game in C that makes use of appropriate Data Structures and Algorithms. The game can be played 1vs1 and also against a Computer with an AI Algorithm. The following features will be implemented in the game.

>  1. Save & Load Game.

>  2. Undo (Remove) a move made by a player.

>  3. Push a move back into the game board. (Redo)

>  4. Option to play vs a Computer using an AI algorithm (1 Player).

# How do I run the application?

***MACOS - GCC Compiler***
If your Operating System is MacOS then follow the steps below to run the application:

> 1. Open the Terminal.

> 2. Go to your current directory where you have the makfile & .c file saved in.

> 3. Type the command: cd "<your directory". Don't enter it with quotes. Replace your directory with your actual folder where the files are saved in.
  
> 4. To compile the ConnectFour.c and create an executable, type the following command: "gcc -o ConnectFour ConnectFour.c". This will create an executable that you will be able to run within the same folder.

> 5. Run the executable.

***Windows***
If your Operating System is Windows then follow the steps below to run the application:

> 1. Start up the Command Prompt or the Microsoft Visual Studio 2017 Command Propmpt.

> 2. Type in the current directory that you are working in (cd "Folder name"). 

> 3. Type in the MS-DOS Shell the command: ***"nmake build"*** to make the application with regards to the makefile. 

> 4. Type in the MS-DOS Shell: cl "filename" to compile the application that will then create an executable file.
  
> 5. Run the executable file.

> 6. Finally don't forget to type in "nmake clean" to clean any junk files necessary, ie any junk .exe/.obj files.

# Data Structures & Algorithms Used

> A 2-D char array has been used to build the game board which allows players to make a move.

> The ***Linear Search Algorithm*** is used to check for win diagonally, horizontally or diagonally.

> ***Stack Data Structure*** used to push & pop a move that has been made by a player.

# Game Menu
The Game Menu presents the users with options to choose from.

<img width="237" alt="Menu" src="https://user-images.githubusercontent.com/29733613/78074529-cd047280-739a-11ea-84b0-7bfd6362eabf.png">

# See Instructions

Players can view the instructions of the game if they are new to to the game and have never played it before.

<img width="878" alt="Instructions" src="https://user-images.githubusercontent.com/29733613/78074540-d1309000-739a-11ea-88d7-70c1e41491c0.png">


# See Help

This allows players to get help.

<img width="461" alt="Show Help" src="https://user-images.githubusercontent.com/29733613/78074549-d4c41700-739a-11ea-925f-f853fa6afec6.png">

# Gameplay - 1

<img width="542" alt="GamePlay" src="https://user-images.githubusercontent.com/29733613/78074594-ea394100-739a-11ea-94c1-a500f95b680a.png">

# Gameplay - 2
The player chooses a position on the game board to insert a disc in, just like the real life connect 4 game until 4 discs are in a row diagonally, vertically or horizontally.

<img width="490" alt="GamePlay2" src="https://user-images.githubusercontent.com/29733613/78074613-eefdf500-739a-11ea-948a-fb9de24bb168.png">

# Vertical Win

<img width="637" alt="VerticalWin" src="https://user-images.githubusercontent.com/29733613/78074570-ddb4e880-739a-11ea-98a4-12549069489b.png">

# Horizontal Win

<img width="633" alt="HorizontalWin" src="https://user-images.githubusercontent.com/29733613/78074574-e1e10600-739a-11ea-8f0e-e6140af2092a.png">

# Diagonal Win

<img width="639" alt="DiagonalWin" src="https://user-images.githubusercontent.com/29733613/78076278-02f72600-739e-11ea-974c-7e0da741bffa.png">
