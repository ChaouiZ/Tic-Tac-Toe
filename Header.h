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
void displayScore();
std::string stringify(std::vector<int>);
bool winChecker(std::string);
void printBoard();
void updateBoard1();
void updateBoard2();