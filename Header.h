#pragma once
#include <vector>
#include <string>
#include <algorithm>

extern std::vector<int> occupiedSpaces;
extern std::vector<int> player1Spaces;
extern std::vector<int> player2Spaces;

void game();
void playerOneSelect();
void playerTwoSelect();
void displayScore();
std::string stringify(std::vector<int>);
bool winChecker(std::string);
