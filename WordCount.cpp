// WordCount.cpp

#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(const std::string & word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int totalWords = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			if(table[i].at(j).first != ""){
				totalWords += table[i].at(j).second;
			}
		}
	}
	return totalWords;
}

int WordCount::getNumUniqueWords() const {
	// STUB
	int totalUniqueWords = 0;
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			if(table[i].at(j).first != "" && table[i].at(j).second >= 1){
				totalUniqueWords++;
			}
		}
	}
	return totalUniqueWords;
}

int WordCount::getWordCount(const std::string & word) const {
	// STUB
	int wordCount = 0;
	std::string validWord = makeValidWord(word);
	for(size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			if(table[i].at(j).first == validWord){
				wordCount = table[i].at(j).second;
			}
		}
	}
	return wordCount;
}
	
int WordCount::incrWordCount(const std::string & word) {
	// STUB
	int count = 0;
	std::string validWord = makeValidWord(word);
	if(validWord == ""){
		return 0;
	}
	size_t index = hash(validWord);
	for(size_t i = 0; i < table[index].size(); i++){
		if(table[index].at(i).first == validWord){
			table[index].at(i).second++;
			count = table[index].at(i).second;
			return count;
		}
	}
	pair<std::string, int> PAIR(validWord, 1);
	table[index].push_back(PAIR);
	count = 1;
	return count;
}

int WordCount::decrWordCount(const std::string & word) {
	// STUB
	int count = 0;
	std::string validWord = makeValidWord(word);
	size_t index = hash(validWord);
	for(size_t i = 0; i < table[index].size(); i++){
		if(table[index].at(i).first == validWord && table[index].at(i).second > 1){
			table[index].at(i).second--;
			count = table[index].at(i).second;
			return count;
		} 
		if(table[index].at(i).first == validWord && table[index].at(i).second == 1){
			table[index].erase(table[index].begin() + i);
			return count;
		}
	}
	count = -1;
	return count;
}

bool WordCount::isWordChar(char c) {
	// ' and - only true if in middle of a word
	if(isalpha(c)){
		return true;
	}
	else
		return false;
}

std::string WordCount::makeValidWord(const std::string & word) {
	std::string cleanedWord = "";
	std::string validWord = "";
	int firstIndex = 0;
	int lastIndex = 0;
	bool flag = false;

	for(size_t h = 0; h < word.length(); h++){
		if(isWordChar(word[h]) == true){
			flag = true;
		}
	}

	if(flag == false){
		return validWord;
	}

	for(size_t i = 0; i < word.length(); i++){
		if(isWordChar(word[i]) == true){
			firstIndex = i;
			break;
		}
	}
	for(int j = word.length() - 1; j > -1; j--){
		if(isWordChar(word[j]) == true){
			lastIndex = j;
			break;
		}
	}
	cleanedWord = word.substr(firstIndex,lastIndex-firstIndex+1);
	//return cleanedWord;
	for(size_t k = 0; k < cleanedWord.length(); k++){
		if(isWordChar(cleanedWord[k]) == true || cleanedWord[k] == '\'' || cleanedWord[k] == '-'){
			validWord += tolower(cleanedWord[k]);
		}
	}
	return validWord;
}
