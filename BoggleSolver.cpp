#include "BoggleSolver.h"

const int BOARD_MAX_SIZE = 4; 

void SolveBoggle(int startRow, int startCol, Dictionary& loadedDictionary,Dictionary& wordsFound, bool printBoard, int stepBoard[][BOARD_MAX_SIZE], int step, char board[][BOARD_MAX_SIZE], std::string currPrefix, std::ofstream& output){

	if(startRow < 0 || startCol < 0){
		return;
	}
	
	if(startRow >= BOARD_MAX_SIZE || startCol >= BOARD_MAX_SIZE){
		return;
	}

	if(loadedDictionary.isWord(currPrefix)){
		//
		//Check if the word has been added already
		if(!wordsFound.isWord(currPrefix)){
			if(printBoard){
				wordsFound.addWord(currPrefix);
				output << currPrefix << "\n";

				std::cout << "FOUND WORD: " << currPrefix << std::endl;
				std::cout << "--------------------------------------" << std::endl;
				for(int i = 0; i < BOARD_MAX_SIZE; i++){
					for(int j = 0; j < BOARD_MAX_SIZE; j++){
						std::cout<< board[i][j] << "  ";
						
					}
					std::cout << "                ";
					for(int j = 0; j < BOARD_MAX_SIZE; j++){
						std::cout<< stepBoard[i][j] << "  ";
						
					}
					std::cout << "\n";
				}		
			std::cout << "\n";
			}
			else{
				std::cout << "FOUND WORD: " << currPrefix << std::endl;
				wordsFound.addWord(currPrefix);
				output << currPrefix << "\n";
			}
		}
		
	}

	if(stepBoard[startRow][startCol] != 0){
		return;
	}


	if(!loadedDictionary.isPrefix(currPrefix)){
		return;
	}
	
	stepBoard[startRow][startCol] = ++step;	

	//Left
	SolveBoggle(startRow, startCol - 1, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);
	//Right
	SolveBoggle(startRow, startCol + 1, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);
	//Up
	SolveBoggle(startRow - 1, startCol, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);
	//Down
	SolveBoggle(startRow + 1, startCol, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);
	//Up-Left
	SolveBoggle(startRow - 1, startCol - 1, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);
	//Up-Right
	SolveBoggle(startRow - 1, startCol + 1, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);
	//Down-Left
	SolveBoggle(startRow + 1, startCol - 1, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);
	//Down-Right
	SolveBoggle(startRow + 1, startCol + 1, loadedDictionary, wordsFound, printBoard, stepBoard, step, board, (currPrefix + board[startRow][startCol]), output);

	stepBoard[startRow][startCol] = 0;		
		
}

void SolveBoard(Dictionary& loadedDictionary, Dictionary& wordsFound, bool printBoard, char board[][BOARD_MAX_SIZE], int stepBoard[][4], std::ofstream& output){
	std::string currPrefix = "";
	int step = 0;	

	for(int startRow = 0; startRow < BOARD_MAX_SIZE; startRow++){
		for(int startCol = 0; startCol < BOARD_MAX_SIZE; startCol++){
			SolveBoggle(startRow, startCol, loadedDictionary,wordsFound, printBoard, stepBoard, step, board, currPrefix, output);
		}
	}
}
