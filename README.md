A program that will find all possible words on a boggle board.

**NOTE: THIS PROGRAM ONLY USES WORDS THAT DOESN'T CONTAIN ANY SPECIAL CHARACTERS (I.E COMMAS, APOSTROPHES ETC).**

The program has two major parts: the Dictionary class and the BoggleSolver class.

The Dictionary class creates a tree data structure where each level is an array of Node pointers. 
Instead storing each word from the text file that we are reading from, we are reading each letter and have the 
index that correspond to that letter to the next node
Each node also has two flags: isWord and isPrefix.
	- The isPrefix flag will tell us whether a sequence of letters are an actual prefix to a word 
	- The isWord flag is what we'll be using to tell us whether the entire sequence of letters is a word

Having an array of Node pointers is much faster in terms of the total number of comparisons that we are doing tofind a word, as compared to storing each individual words, since the largest possible number of comparison that we are going to do is the longest word that's going to be in the Dictionary; so our look up time will always be O(n). 
	EX: If our longest word in the Dictionary is 23 letters long, that's biggest possible number of comparisons that we will do.

The Boggle Solver class utilizes the Dictionary class to find all the possible words on the given board. We use recusion to traverse the board and check all possible directions around each letters. This class relies on the flags that the Dictionary class has in order to check if a direction leads to a word or not. This saves the program in checking by not letting it go in blindly in all possible directions if the end the word doesn't exist.

**Program Output:**

*User Input for the board*

![alt text](/imgs/UserInput.png "The program will ask the user to input the letters on the board")


*Board Confirmation*

![alt text](https://github.com/jaquino94/BoggleSolver/blob/master/imgs/InputBoard.png "The program will confirm the user input by showing it on a board. It will also ask if the user wants to see the board, showing where the word is found")


*Board shown with found words*

![alt text](https://github.com/jaquino94/BoggleSolver/blob/master/imgs/FoundWords.png "The program showing the words found, and the where on the found they are found, along with the steps for each letter of the found word")


*Program with just the words being shown*

![alt text](https://github.com/jaquino94/BoggleSolver/blob/master/imgs/NoBoardShown.png "If the user doesn't choose to show the board, the program will just list out all the words found")

*Total words found at the end of the program*

![alt text](https://github.com/jaquino94/BoggleSolver/blob/master/imgs/TotalWordsFound.png "At the end, the program will show how many words are found with the given word")






