#ifndef BOGGLESOLVER_H
#define BOGGLESOLVER_H
#include <string> 

/*
 * The Dictionary interface  
 *
 * There's a private function that is being used by the wrapper function, PrintWords, 
 * along with a function that returns the total amount of words that has been added into the Dictionary. 
 * These are optional functionalities to use with the program. 
 */

const int MAX_CHAR_SIZE = 26;
struct Node{
	Node* arr[MAX_CHAR_SIZE];
	bool isWord;
	
	Node();
};
class Dictionary{
	private: 
		Node* root; 
		int wordCount;
		void printHelper(Node* start, std::string prefix);
	public: 
		Dictionary();
		Dictionary(std::string file);
	       	void addWord(std::string word);
		bool isWord(std::string word);
		bool isPrefix(std::string word);
		void printWords(std::string prefix);
		int getWordCount();	
};

#endif
