#pragma once
#include <vector>
#include <string>
#include <algorithm>

extern std::vector<int> occupiedSpaces;
extern std::vector<int> player1Spaces;
extern std::vector<int> player2Spaces;
extern std::string board1;
extern std::string board2;
extern std::string board3;
extern std::string board4;
extern std::string board5;
extern std::string board6;
extern std::string board7;
//         ^   ^
//       1 | 2 | 3
//    < - - - - - - >
//       4 | 5 | 6
//    < - - - - - - >
//       7 | 8 | 9
//         #   #  

void game();
void playerOneSelect();
void playerTwoSelect();
std::string stringify(std::vector<int>);
bool winChecker(std::vector<int>);
void printBoard();
void updateBoard1();
void updateBoard2();
bool check159(std::vector<int>);
bool check147(std::vector<int>);
bool check258(std::vector<int>);
bool check369(std::vector<int>);
bool check357(std::vector<int>);
bool checkLinearConditions(std::vector<int>);
void clearBoard();
void playAgain();
void quitGame();