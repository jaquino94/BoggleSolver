#include "BoggleSolver.h"
#include <iostream>

const int BOARD_MAX_SIZE = 4; 

void SolveBoggle(int startRow, int startCol, Dictionary loadedDictionary, bool printBoard, char board[][4], std::string currPrefix);

void SolveBoard(Dictionary& loadedDictionary, Dictionary& wordsFound, bool printBoard, char board[][4], int stepBoard[][4], std::ofstream& output);

int main(){
	std::ofstream output;
	std::string letters;
	char userInput;
	bool printBoard = false;
	Dictionary wordsFound;
	Dictionary loadedDictionary("words_alpha.txt");
	std::cout << "DICTIONARY INITIALIZED WITH " << loadedDictionary.getWordCount() << " WORDS" << std::endl;

	int stepBoard[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
	char board[BOARD_MAX_SIZE][BOARD_MAX_SIZE];

	
	std::cout << "Enter 4 letters for each row on the board: \n";
	for(int i = 0 ; i < 4; i++){
		std::cout << "Row " << i + 1 << ": "; 
		std::cin >> letters;  
		while((int)(letters.size()) != 4 ){
			std::cin.ignore();
			std::cin.clear();
			std::cout << "PLEASE ENTER A ROW WITH 4 LETTERS TOTAL: ";
			std::cin >> letters;
		}
		for(int j = 0; j  < (int)(letters.size()); j++){
			board[i][j] = letters[j];	
		}
	}

	for(int i = 0; i < BOARD_MAX_SIZE; i++){
		for(int j = 0; j < BOARD_MAX_SIZE; j++){
			std::cout<< board[i][j] << "    " ;
		}
		std::cout << "\n";
	}

	std::cout<< "Print board?(Y/N): ";
       	std::cin >> userInput;
	if(tolower(userInput) == 'y'){
		printBoard = true;
	}	
	
	output.open("foundWords.txt");	
	SolveBoard(loadedDictionary,wordsFound,printBoard,board,stepBoard,output);
	std::cout << "TOTAL WORDS FOUND: " << wordsFound.getWordCount() << std::endl;
	output.close();
}
