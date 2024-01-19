#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include "header.h" 

std::vector<int> occupiedSpaces;
std::vector<int> player1Spaces;
std::vector<int> player2Spaces;

std::string board1 = "\n\n                                                          ^   ^\n";
std::string board2 = "                                                        7 | 8 | 9 \n";
std::string board3 = "                                                     < - - - - - - >\n";
std::string board4 = "                                                        4 | 5 | 6\n";
std::string board5 = "                                                     < - - - - - - >\n";
std::string board6 = "                                                        1 | 2 | 3\n";
std::string board7 = "                                                          #   # \n\n";

bool gameActive = true;

void game() {

	if(gameActive){
		playerOneSelect();
		if(gameActive){
			updateBoard1();
			printBoard();
		}
	}
	
	
	if(gameActive){
		playerTwoSelect();
		if(gameActive){
			updateBoard2();
			printBoard();
		}
	}


	if (gameActive) {
		game();
			}

}

void playerOneSelect() {
	std::cout << std::setw(79) << std::setfill(' ') << "Player 1: Enter a space.  (1 - 9)\n\n" <<
		"                                                            ";
	int spaceSelection1;
	std::cin >> spaceSelection1;

	for (int i : occupiedSpaces) {
		if (i == spaceSelection1) {
			std::cout << std::setw(79) << std::setfill(' ') <<
				"That space is already taken. Try again.\n\n";
			playerOneSelect();
			return;
		}
	}
	if ((spaceSelection1 > 9 || spaceSelection1 < 1) && spaceSelection1 != 0) {
		std::cout << std::endl << std::setw(88) << std::setfill(' ') <<
			"Invalid entry.  Select an integer between 1 and 9.\n\n";
		playerOneSelect();
		return;
	}

	if (spaceSelection1 == 0) {
		quitGame();
	}

	player1Spaces.push_back(spaceSelection1);
	occupiedSpaces.push_back(spaceSelection1);

	if(player1Spaces.size() > 2) {
		bool check1 = winChecker(player1Spaces);

		if (check1) {
			updateBoard1();
			printBoard();
			std::cout << "\n\n\n" << std::setw(68) << std::setfill(' ') << "Player 1 Wins!!";
			gameActive = false;
			playAgain();
			return;
		}

		if (player1Spaces.size() == 5) {

			bool checkTie = winChecker(player1Spaces);

			if (!checkTie) {
				std::cout << "\n\n\n" << std::setw(63) << std::setfill(' ') << "Draw!";
				updateBoard1();
				printBoard();
				gameActive = false;
				playAgain();
				return;
			}
		}
	}


}

void playerTwoSelect() {

	if (player1Spaces.size() < 5) {
		std::cout << std::setw(79) << std::setfill(' ') << "Player 2: Enter a space.  (1 - 9)\n\n" << 
			"                                                            ";
		int spaceSelection2;
		std::cin >> spaceSelection2;

		for (int i : occupiedSpaces) {
			if (i == spaceSelection2) {
				std::cout << std::setw(79) << std::setfill(' ') << 
					"That space is already taken. Try again.\n\n";
				playerTwoSelect();
				return;
			}
		}

		if ((spaceSelection2 > 9 || spaceSelection2 < 1) && spaceSelection2 != 0) {
			std::cout << std::endl << std::setw(88) << std::setfill(' ') <<
				"Invalid entry.  Select an integer between 1 and 9.\n\n";
			playerOneSelect();
			return;
		}
		if (spaceSelection2 == 0) {
			quitGame();
		}

		player2Spaces.push_back(spaceSelection2);
		occupiedSpaces.push_back(spaceSelection2);


		std::cout << "\n\n";
	}

	if (player2Spaces.size() > 2) {
		bool check2 = winChecker(player2Spaces);

		if (check2) {
			updateBoard2();
			printBoard();
			std::cout << "\n\n\n" << std::setw(68) << std::setfill(' ') << "Player 2 Wins!!";
			playAgain();
			gameActive = false;
			return;
		}
	}

	return;

}

std::string stringify(std::vector<int> myVec) {

	std::sort(myVec.begin(), myVec.end());

	std::string score;
	

	for (int i : myVec) {
		score += std::to_string(i);
	}
	return score;

}

bool winChecker(std::vector<int> playerVec) {

	if (check159(playerVec) || check147(playerVec) || check258(playerVec) || check369(playerVec) ||
		check357(playerVec) || checkLinearConditions(playerVec)) {
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
void updateBoard1() {
	if (player1Spaces.size() == 1) {
		int player1choice = player1Spaces.at(0);

		switch (player1choice) {

		case 1:
			board6.replace(56, 1, "X");
			break;
		case 2:
			board6.replace(60, 1, "X");
			break;
		case 3:
			board6.replace(64, 1, "X");
			break;
		case 4:
			board4.replace(56, 1, "X");
			break;
		case 5:
			board4.replace(60, 1, "X");
			break;
		case 6:
			board4.replace(64, 1, "X");
			break;
		case 7:
			board2.replace(56, 1, "X");
			break;
		case 8:
			board2.replace(60, 1, "X");
			break;
		case 9:
			board2.replace(64, 1, "X");
			break;
		}

	}

	if (player1Spaces.size() == 2) {
		int player1choice = player1Spaces.at(1);

		switch (player1choice) {

		case 1:
			board6.replace(56, 1, "X");
			break;
		case 2:
			board6.replace(60, 1, "X");
			break;
		case 3:
			board6.replace(64, 1, "X");
			break;
		case 4:
			board4.replace(56, 1, "X");
			break;
		case 5:
			board4.replace(60, 1, "X");
			break;
		case 6:
			board4.replace(64, 1, "X");
			break;
		case 7:
			board2.replace(56, 1, "X");
			break;
		case 8:
			board2.replace(60, 1, "X");
			break;
		case 9:
			board2.replace(64, 1, "X");
			break;
		}

	}

	if (player1Spaces.size() == 3) {
		int player1choice = player1Spaces.at(2);

		switch (player1choice) {

		case 1:
			board6.replace(56, 1, "X");
			break;
		case 2:
			board6.replace(60, 1, "X");
			break;
		case 3:
			board6.replace(64, 1, "X");
			break;
		case 4:
			board4.replace(56, 1, "X");
			break;
		case 5:
			board4.replace(60, 1, "X");
			break;
		case 6:
			board4.replace(64, 1, "X");
			break;
		case 7:
			board2.replace(56, 1, "X");
			break;
		case 8:
			board2.replace(60, 1, "X");
			break;
		case 9:
			board2.replace(64, 1, "X");
			break;
		}

	}

	if (player1Spaces.size() == 4) {
		int player1choice = player1Spaces.at(3);

		switch (player1choice) {

		case 1:
			board6.replace(56, 1, "X");
			break;
		case 2:
			board6.replace(60, 1, "X");
			break;
		case 3:
			board6.replace(64, 1, "X");
			break;
		case 4:
			board4.replace(56, 1, "X");
			break;
		case 5:
			board4.replace(60, 1, "X");
			break;
		case 6:
			board4.replace(64, 1, "X");
			break;
		case 7:
			board2.replace(56, 1, "X");
			break;
		case 8:
			board2.replace(60, 1, "X");
			break;
		case 9:
			board2.replace(64, 1, "X");
			break;
		}

	}

	if (player1Spaces.size() == 5) {
		int player1choice = player1Spaces.at(4);

		switch (player1choice) {

		case 1:
			board6.replace(56, 1, "X");
			break;
		case 2:
			board6.replace(60, 1, "X");
			break;
		case 3:
			board6.replace(64, 1, "X");
			break;
		case 4:
			board4.replace(56, 1, "X");
			break;
		case 5:
			board4.replace(60, 1, "X");
			break;
		case 6:
			board4.replace(64, 1, "X");
			break;
		case 7:
			board2.replace(56, 1, "X");
			break;
		case 8:
			board2.replace(60, 1, "X");
			break;
		case 9:
			board2.replace(64, 1, "X");
			break;
		}

	}
}

void updateBoard2() {
	if (player2Spaces.size() == 1) {
		int player2choice = player2Spaces.at(0);

		switch (player2choice) {

		case 1:
			board6.replace(56, 1, "O");
			break;
		case 2:
			board6.replace(60, 1, "O");
			break;
		case 3:
			board6.replace(64, 1, "O");
			break;
		case 4:
			board4.replace(56, 1, "O");
			break;
		case 5:
			board4.replace(60, 1, "O");
			break;
		case 6:
			board4.replace(64, 1, "O");
			break;
		case 7:
			board2.replace(56, 1, "O");
			break;
		case 8:
			board2.replace(60, 1, "O");
			break;
		case 9:
			board2.replace(64, 1, "O");
			break;
		}

	}

	if (player2Spaces.size() == 2) {
		int player2choice = player2Spaces.at(1);

		switch (player2choice) {

		case 1:
			board6.replace(56, 1, "O");
			break;
		case 2:
			board6.replace(60, 1, "O");
			break;
		case 3:
			board6.replace(64, 1, "O");
			break;
		case 4:
			board4.replace(56, 1, "O");
			break;
		case 5:
			board4.replace(60, 1, "O");
			break;
		case 6:
			board4.replace(64, 1, "O");
			break;
		case 7:
			board2.replace(56, 1, "O");
			break;
		case 8:
			board2.replace(60, 1, "O");
			break;
		case 9:
			board2.replace(64, 1, "O");
			break;
		}

	}

	if (player2Spaces.size() == 3) {
		int player2choice = player2Spaces.at(2);

		switch (player2choice) {

		case 1:
			board6.replace(56, 1, "O");
			break;
		case 2:
			board6.replace(60, 1, "O");
			break;
		case 3:
			board6.replace(64, 1, "O");
			break;
		case 4:
			board4.replace(56, 1, "O");
			break;
		case 5:
			board4.replace(60, 1, "O");
			break;
		case 6:
			board4.replace(64, 1, "O");
			break;
		case 7:
			board2.replace(56, 1, "O");
			break;
		case 8:
			board2.replace(60, 1, "O");
			break;
		case 9:
			board2.replace(64, 1, "O");
			break;
		}

	}

	if (player2Spaces.size() == 4) {
		int player2choice = player2Spaces.at(3);

		switch (player2choice) {

		case 1:
			board6.replace(56, 1, "O");
			break;
		case 2:
			board6.replace(60, 1, "O");
			break;
		case 3:
			board6.replace(64, 1, "O");
			break;
		case 4:
			board4.replace(56, 1, "O");
			break;
		case 5:
			board4.replace(60, 1, "O");
			break;
		case 6:
			board4.replace(64, 1, "O");
			break;
		case 7:
			board2.replace(56, 1, "O");
			break;
		case 8:
			board2.replace(60, 1, "O");
			break;
		case 9:
			board2.replace(64, 1, "O");
			break;
		}

	}
}


bool check159(std::vector<int> myVec) {

	std::vector<int> newVec;

	for (int i : myVec) {

		if (i == 1) {
			newVec.push_back(i);
		}
		if (i == 5) {
			newVec.push_back(i);
		}
		if (i == 9) {
			newVec.push_back(i);
		}

	}

	std::string vecString = stringify(newVec);

	if (vecString == "159") {
		return true;
	}
	return false;
}
bool check147(std::vector<int> myVec) {

	std::vector<int> newVec;

	for (int i : myVec) {

		if (i == 1) {
			newVec.push_back(i);
		}
		if (i == 4) {
			newVec.push_back(i);
		}
		if (i == 7) {
			newVec.push_back(i);
		}

	}

	std::string vecString = stringify(newVec);

	if (vecString == "147") {
		return true;
	}
	return false;
}
bool check258(std::vector<int> myVec) {

	std::vector<int> newVec;

	for (int i : myVec) {

		if (i == 2) {
			newVec.push_back(i);
		}
		if (i == 5) {
			newVec.push_back(i);
		}
		if (i == 8) {
			newVec.push_back(i);
		}

	}

	std::string vecString = stringify(newVec);

	if (vecString == "258") {
		return true;
	}
	return false;
}
bool check369(std::vector<int> myVec) {

	std::vector<int> newVec;

	for (int i : myVec) {

		if (i == 3) {
			newVec.push_back(i);
		}
		if (i == 6) {
			newVec.push_back(i);
		}
		if (i == 9) {
			newVec.push_back(i);
		}

	}

	std::string vecString = stringify(newVec);

	if (vecString == "369") {
		return true;
	}
	return false;
}
bool check357(std::vector<int> myVec) {

	std::vector<int> newVec;

	for (int i : myVec) {

		if (i == 3) {
			newVec.push_back(i);
		}
		if (i == 5) {
			newVec.push_back(i);
		}
		if (i == 7) {
			newVec.push_back(i);
		}

	}

	std::string vecString = stringify(newVec);

	if (vecString == "357") {
		return true;
	}
	return false;
}
bool checkLinearConditions(std::vector<int> myVec) {

	std::string vecString = stringify(myVec);
	
	if (vecString.find("123") != std::string::npos || vecString.find("456") != std::string::npos ||
		vecString.find("789") != std::string::npos) {
			return true;
		}
		return false;

}

void clearBoard() {
	board6.replace(56, 1, " ");
	board6.replace(60, 1, " ");
	board6.replace(64, 1, " ");
	board4.replace(56, 1, " ");
	board4.replace(60, 1, " ");
	board4.replace(64, 1, " ");
	board2.replace(56, 1, " ");
	board2.replace(60, 1, " ");
	board2.replace(64, 1, " ");
}


void playAgain() {
	std::cout << "\n\n" << std::setw(69) << std::setfill(' ') << "Play again? (y/n)";
	std::cout << "\n\n                                                            ";
	char anotherGame;
	std::cin >> anotherGame;

	if (anotherGame == 'y') {
		gameActive = true;
		clearBoard();
		printBoard();
		player1Spaces.clear();
		player2Spaces.clear();
		occupiedSpaces.clear();
		game();
		return;
	}

	std::cout << "\n\n";

}

void quitGame() {

	gameActive = false;
	game();
	return;
}