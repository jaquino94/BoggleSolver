#include "Dictionary.h" 
#include <iostream>
#include <fstream>

Node::Node(){
	for(int i = 0; i < MAX_CHAR_SIZE; i++){
		arr[i] = NULL;
	}
	isWord = false;
}

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
