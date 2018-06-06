#include "BoggleSolver.h"

const int BOARD_MAX_SIZE = 4; 

/*
 * The SolveBoggle recursively goes through the board and checks if a sequence of letters is a prefix and/or a word. 
 * The function will check all possible directions which are: UP, DOWN, LEFT, RIGHT, UP-LEFT, UP-RIGHT, DOWN-RIGHT, DOWN-LEFT.
 * Every time that a letter is part of a prefix, we concatenate the letter with the rest of string.
 * To ensure that the function doesn't infinitely call on itself, we check these things:
 * 	1) If we are out of bounds, meaning we are off the board
 * 	2) If the letter we are checking has already been visited(this prevents the program from backtracking)
 * 	3) If the letter is not part of a prefix 
 * 	4) If the sequence of letters is a word 
 * 	5) If the sequence of letters is already found (If it's already found, we stop searching with that sequence of letters) 
 * Once we find the word, we add the word to another Dictionary data structure. We use this additional Dictionary object as part of our general cases so that we don't search for the same words multiple times
 */
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

	//If we go through all 8 directions and no word is found with that current letter position, we reset this flag back to 0 so we can go through that letter again
	stepBoard[startRow][startCol] = 0;		
		
}

/*
 * The SolveBoard function is a wrapper class that will call the SolveBoggle function. This function ensures that we iterate through each letter on the board to find all possible words
 */
void SolveBoard(Dictionary& loadedDictionary, Dictionary& wordsFound, bool printBoard, char board[][BOARD_MAX_SIZE], int stepBoard[][4], std::ofstream& output){
	std::string currPrefix = "";
	int step = 0;	

	for(int startRow = 0; startRow < BOARD_MAX_SIZE; startRow++){
		for(int startCol = 0; startCol < BOARD_MAX_SIZE; startCol++){
			SolveBoggle(startRow, startCol, loadedDictionary,wordsFound, printBoard, stepBoard, step, board, currPrefix, output);
		}
	}
}
