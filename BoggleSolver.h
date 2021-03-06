#ifndef BOGGLESOLVER_H
#include "Dictionary.h"
#include <iostream>
#include <fstream>
#define BOGGLESOLVER_H

/*
 * The Boggle Solver Interface
 * Note: the ofstream object is option and can be omitted. Just change the function parameter list here and the cpp file.
 */
void SolveBoggle(int startRow, int startCol, Dictionary& loadedDictionary, Dictionary& wordsFound, int stepBoard[][4], int step, char board[][4], bool& foundWord, std::string currPrefix, std::ofstream& output);

void resetBoard(int[][4]);

void SolveBoard(Dictionary& loadedDictionary, Dictionary& wordsFound, char board[][4], int stepBoard[][4], std::ofstream& output);
#endif
