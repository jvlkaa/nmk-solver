
##   NMK solver (Tic-Tac-Toe)

A student project created on 05.2022 implements a **Tic-Tac-Toe game solver** using **minimax algorithm** in C++. It's an extended version of Tic-Tac-Toe, where the game can be played on `N x M` board, and the win condition is to have `K` of your own symbols in a row/column/diagonal.
 ## How it works
### Commands
### 1) `GEN_ALL_POS_MOV N M K PLayer Board`
shows the number of player's possible moves and prints them at a given game state

**parameters:**
 - N, M - size of the board  
 - K - number of symbols in a row/column/diagonal needed to win
 - Player - number of the player whose turn it is
 - Board - current state of the board
 
### 2) `GEN_ALL_POS_MOV_CUT_IF_GAME_OVER N M K PLayer`
shows the number of player's possible moves and prints them at a given game state and in case of a win, it only shows the winning move

**parameters:**
- N, M - size of the board  
- K - number of symbols in a row/column/diagonal needed to win
- Player - number of the player whose turn it is

### 3) `SOLVE_GAME_STATE N M K Player`
solves the game in the current state and returns the player(s) who win(s)

**parameters:**
- N, M - size of the board  
- K - number of symbols in a row/column/diagonal needed to win
- Player - number of the player whose turn it is

**possible results:**
```
FIRST_PLAYER_WINS
SECOND_PLAYER_WINS
BOTH_PLAYERS_TIE
```
 ### Examples
 ```
 SOLVE_GAME_STATE 3 3 3 2 
 2 1 0 
 1 0 0 
 0 0 0

 result:
 BOTH_PLAYERS_TIE
 ```
 ```
 GEN_ALL_POS_MOV 3 3 3 1
2 1 0
0 0 2
2 0 1

result:
4
2 1 1
0 0 2
2 0 1

2 1 0
1 0 2
2 0 1

2 1 0
0 1 2
2 0 1

2 1 0
0 0 2
2 1 1
 ```
 ```
GEN_ALL_POS_MOV_CUT_IF_GAME_OVER 3 3 3 2
1 0 2
0 1 2
0 0 0

result:
1 
1 0 2
0 1 2
0 0 2
```
 
## Setup
#### How to run project
1. Clone this repository.
2. Open the project solution file (`.sln`) with Visual Studio.
3. Build and run the project.
