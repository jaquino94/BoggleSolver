#include "Dictionary.h" 
#include <iostream>
#include <fstream>

Node::Node(){
	for(int i = 0; i < MAX_CHAR_SIZE; i++){
		arr[i] = NULL;
	}
	isWord = false;
}

/*
 * We have to two constructors: 
 * 	1) Doesn't take in a text file, but just establishes the root of the tree
 * 	2) Takes in a text file and creates the tree
 */
Dictionary::Dictionary(){
	root = new Node;
	wordCount = 0;
}

Dictionary::Dictionary(std::string file){
	root = new Node; 
	wordCount = 0; 

	std::string word;
	std::ifstream input;
	input.open(file);
	while(input >> word){ 
		addWord(word);
	}
	input.close();
}

/*
 * The function creates new Nodes for each letter of the word that we are adding. 
 * At the end, we set the isWord flag to be true. This will be useful with our Boggle Solver class.
 */
void Dictionary::addWord(std::string word){
	Node* currNode = root; 

	for(int i = 0; i < (int)word.size(); i++){
		int index = (int)word[i] - (int)'a';	
		if(currNode->arr[index] == NULL){
			currNode->arr[index] = new Node;
		}				
		currNode = currNode->arr[index];
	}
	currNode->isWord = true;
	wordCount++;
}

/*
 * The isPrefix returns false if any of the letter's, from the parameter we passed in, is a null pointer.
 * This is how the program knows whether to keep going with a sequence of letters or not. 
 */
bool Dictionary::isPrefix(std::string word){
	Node* temp = root;

	for(int i = 0; i < (int)word.size(); i++){
		int index = (int)word[i] - (int)'a';

		if(temp->arr[index] == NULL){
			return false; 
		}
		temp = temp->arr[index];
	}	
	return true;
}	

/*
 * The function traverses through the tree based on the letters of the word passed in. 
 * If we reach the end of the word, we check if the flag is true or not. 
 * The fuction also checks if we hit a null pointer before reaching the end of the word.
 */
bool Dictionary::isWord(std::string word){
	Node* temp = root;

	for(int i = 0; i < (int)word.size(); i++){
		int index = (int)word[i] - (int)'a';

		if(temp->arr[index] == NULL){
			return false; 
		}
		temp = temp->arr[index];
	}	
	return temp->isWord;
}	

/*
 * THE FOLLOWING FUNCTIONS ARE OPTIONAL.
 * THE PROGRAM WILL STILL FUNCTION CORRECTLY EVEN WITHOUT THEM.
 */
void Dictionary::printWords(std::string prefix){
	Node* currentNode = root;
	for(int i = 0; i < (int)prefix.size(); i++){
		int index = (int)prefix[i] - (int)'a';
		currentNode = currentNode->arr[index];	
	}

	for(int i = 0; i < MAX_CHAR_SIZE; i++){
		char letter = (int)'a' + i;
		std::string newPrefix = prefix + letter;
		printHelper(currentNode->arr[i], newPrefix);
	}

}

void Dictionary::printHelper(Node* currentNode, std::string prefix){
		if(currentNode == NULL){
			return; 
		}
		if(currentNode->isWord){
			std::cout << "WORD: " << prefix << std::endl;
		}
		for(int i = 0; i < MAX_CHAR_SIZE; i++){
			char letter = (int)'a' + i;	
			std::string newPrefix  = prefix + letter;
			printHelper(currentNode->arr[i],newPrefix);
		}
}

int Dictionary::getWordCount(){
	return wordCount;
}
