#include <fstream>
#include <vector>
#include <tuple>
#include <iostream>
#include <map>

using namespace std;


int main(int argc, char **argv) {

	ifstream readFile;
	readFile.open("input.txt", ifstream::in);

	vector<tuple<char,char>> storage;

	char read1;
	char read2;

	while(readFile >> read1) {
		readFile >> read2;
		storage.emplace_back(tuple<char,char>(read1, read2));
	}

	readFile.close();

	map<tuple<char,char>, int> scores;

	// Losses
	scores.emplace(tuple<char,char>('A','Z'), 1);
	scores.emplace(tuple<char,char>('B','X'), 2);
	scores.emplace(tuple<char,char>('C','Y'), 3);
	// Ties
	scores.emplace(tuple<char,char>('A','X'), 4);
	scores.emplace(tuple<char,char>('B','Y'), 5);
	scores.emplace(tuple<char,char>('C','Z'), 6);
	// Wins
	scores.emplace(tuple<char,char>('A','Y'), 7);
	scores.emplace(tuple<char,char>('B','Z'), 8);
	scores.emplace(tuple<char,char>('C','X'), 9);

	return 0;
}