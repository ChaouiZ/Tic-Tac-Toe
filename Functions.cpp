#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "header.h" 

std::vector<int> occupiedSpaces;
std::vector<int> player1Spaces;
std::vector<int> player2Spaces;

 std::string board1 = "         ^   ^\n";
 std::string board2 = "         |   |   \n";
 std::string board3 = "    < - - - - - - >\n";
 std::string board4 = "         |   |  \n";
 std::string board5 = "    < - - - - - - >\n";
 std::string board6 = "         |   |  \n";
 std::string board7 = "         #   # \n\n";

void game() {

	playerOneSelect();
	playerTwoSelect();
	updateBoard1();
	updateBoard2();
	printBoard();
	displayScore();

	
}

void playerOneSelect() {
	std::cout << " Player 1: Enter a space. (1 - 9)\n";
	int spaceSelection1;
	std::cin >> spaceSelection1;

	for (int i : occupiedSpaces) {
		if (i == spaceSelection1) {
			std::cout << "That space is already taken. Try again.\n\n";
			playerOneSelect();
			return;
		}
	}
	player1Spaces.push_back(spaceSelection1);
	occupiedSpaces.push_back(spaceSelection1);

	
}

void playerTwoSelect() {

	if(player1Spaces.size() < 5) {
		std::cout << " Player 2: Enter a space. (1 - 9)\n";
		int spaceSelection2;
		std::cin >> spaceSelection2;

		for (int i : occupiedSpaces) {
			if (i == spaceSelection2) {
				std::cout << "That space is already taken. Try again.\n\n";
				playerTwoSelect();
				return;
			}
		}
		player2Spaces.push_back(spaceSelection2);
		occupiedSpaces.push_back(spaceSelection2);


		std::cout << "\n\n";
	}
	return;
	
}

void displayScore() {



	if (player1Spaces.size() == 1) {
		std::cout << "Player 1 opens with space ";
		
		for (int i : player1Spaces) {
			std::cout << i;
			std::cout << "\n\n";
			
		}
	}

	if (player2Spaces.size() == 1) {
		std::cout << "Player 2 opens with space ";

		for (int i : player2Spaces) {
			std::cout << i;
			std::cout << "\n\n";
			game();
			return;
		}
	}

	if (player1Spaces.size() == 2) {
		std::cout << "Player 1 has spaces ";

		for (int i : player1Spaces) {
			std::cout << i;

			if (i != player1Spaces.back()) {
				std::cout << " and ";
			}
		}
		std::cout << "\n\n";

	}

	if (player2Spaces.size() == 2) {
		std::cout << "Player 2 has spaces ";

		for (int i : player2Spaces) {
			std::cout << i;
			
			if (i != player2Spaces.back()) {
				std::cout << " and ";
			}
		}
			std::cout << "\n\n";
			game();
			return;
	}

	if(player1Spaces.size() > 2 && player1Spaces.size() < 5) {
		std::cout << "Player 1 has spaces ";
		for (int i : player1Spaces) {
			std::cout << i << ", ";
		}
		std::cout << "\n\n";
		game();
		return;
	}

	if(player2Spaces.size() > 2 && player1Spaces.size() < 5) {
		std::cout << "Player 2 has spaces ";
		for (int i : player2Spaces) {
			std::cout << i << ", ";
		}
		std::cout << "\n\n";
		game();
		return;
	}
	
	if (player1Spaces.size() == 5) {

		std::cout << "Player 1 has spaces ";
		for (int i : player1Spaces) {
			std::cout << i << ", ";
		}
		std::cout << "\n\n";

		std::cout << "Player 2 has spaces ";
		for (int i : player2Spaces) {
			std::cout << i << ", ";
		}
		std::cout << "\n\n";

		bool player1Result = winChecker(stringify(player1Spaces));
		bool player2Result = winChecker(stringify(player2Spaces));

		if (player1Result) {
			std::cout << "Player 1 Wins!\n\n";
			return;
		}
		else if (player2Result) {
			std::cout << "Player 2 Wins!\n\n";
			return;
		}
		else {
			std::cout << "Draw!\n\n";
		    
		}
	}
}

std::string stringify(std::vector<int> myVec) {

	std::sort(myVec.begin(), myVec.end());

	std::string score;

	for (int i : myVec) {
		score += std::to_string(i);
	}
	return score;

}

bool winChecker(std::string str) {

	if (str == "123" || str == "159" || str == "147" || str == "456" ||
		str == "789" || str == "258" || str == "369" || str == "357") {
		return true;
	}
	return false;
}

void printBoard() {


	
		std::cout << board1;
		std::cout << board2;
		std::cout << board3;
		std::cout << board4;
		std::cout << board5;
		std::cout << board6;
		std::cout << board7;
	
	


}
void updateBoard1()	{
	if (player1Spaces.size() == 1)	{
		int player1choice = player1Spaces.at(0);
	
		switch (player1choice) {
		
		case 1:
			board2.replace(7, 1, "X");
			break;
		case 2:
			board2.replace(11, 1, "X");
			break;
		case 3:
			board2.replace(15, 1, "X");
			break;
		case 4:
			board4.replace(7, 1, "X");
			break;
		case 5:
			board4.replace(11, 1, "X");
			break;
		case 6:
			board4.replace(15, 1, "X");
			break;
		case 7:
			board6.replace(7, 1, "X");
			break;
		case 8:
			board6.replace(11, 1, "X");
			break;
		case 9:
			board6.replace(15, 1, "X");
			break;
		}
	
	}

	if (player1Spaces.size() == 2) {
		int player1choice = player1Spaces.at(1);

		switch (player1choice) {

		case 1:
			board2.replace(7, 1, "X");
			break;
		case 2:
			board2.replace(11, 1, "X");
			break;
		case 3:
			board2.replace(15, 1, "X");
			break;
		case 4:
			board4.replace(7, 1, "X");
			break;
		case 5:
			board4.replace(11, 1, "X");
			break;
		case 6:
			board4.replace(15, 1, "X");
			break;
		case 7:
			board6.replace(7, 1, "X");
			break;
		case 8:
			board6.replace(11, 1, "X");
			break;
		case 9:
			board6.replace(15, 1, "X");
			break;
		}

	}

	if (player1Spaces.size() == 3) {
		int player1choice = player1Spaces.at(2);

		switch (player1choice) {

		case 1:
			board2.replace(7, 1, "X");
			break;
		case 2:
			board2.replace(11, 1, "X");
			break;
		case 3:
			board2.replace(15, 1, "X");
			break;
		case 4:
			board4.replace(7, 1, "X");
			break;
		case 5:
			board4.replace(11, 1, "X");
			break;
		case 6:
			board4.replace(15, 1, "X");
			break;
		case 7:
			board6.replace(7, 1, "X");
			break;
		case 8:
			board6.replace(11, 1, "X");
			break;
		case 9:
			board6.replace(15, 1, "X");
			break;
		}

	}
}

void updateBoard2() {
	if (player2Spaces.size() == 1) {
		int player2choice = player2Spaces.at(0);

		switch (player2choice) {

		case 1:
			board2.replace(7, 1, "O");
			break;
		case 2:
			board2.replace(11, 1, "O");
			break;
		case 3:
			board2.replace(15, 1, "O");
			break;
		case 4:
			board4.replace(7, 1, "O");
			break;
		case 5:
			board4.replace(11, 1, "O");
			break;
		case 6:
			board4.replace(15, 1, "O");
			break;
		case 7:
			board6.replace(7, 1, "O");
			break;
		case 8:
			board6.replace(11, 1, "O");
			break;
		case 9:
			board6.replace(15, 1, "O");
			break;
		}

	}

	if (player2Spaces.size() == 2) {
		int player2choice = player2Spaces.at(1);

		switch (player2choice) {

		case 1:
			board2.replace(7, 1, "O");
			break;
		case 2:
			board2.replace(11, 1, "O");
			break;
		case 3:
			board2.replace(15, 1, "O");
			break;
		case 4:
			board4.replace(7, 1, "O");
			break;
		case 5:
			board4.replace(11, 1, "O");
			break;
		case 6:
			board4.replace(15, 1, "O");
			break;
		case 7:
			board6.replace(7, 1, "O");
			break;
		case 8:
			board6.replace(11, 1, "O");
			break;
		case 9:
			board6.replace(15, 1, "O");
			break;
		}

	}

	if (player2Spaces.size() == 3) {
		int player2choice = player2Spaces.at(2);

		switch (player2choice) {

		case 1:
			board2.replace(7, 1, "O");
			break;
		case 2:
			board2.replace(11, 1, "O");
			break;
		case 3:
			board2.replace(15, 1, "O");
			break;
		case 4:
			board4.replace(7, 1, "O");
			break;
		case 5:
			board4.replace(11, 1, "O");
			break;
		case 6:
			board4.replace(15, 1, "O");
			break;
		case 7:
			board6.replace(7, 1, "O");
			break;
		case 8:
			board6.replace(11, 1, "O");
			break;
		case 9:
			board6.replace(15, 1, "O");
			break;
		}

	}
}


