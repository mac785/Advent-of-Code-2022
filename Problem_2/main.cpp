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

	scores.emplace(tuple<char,char>(A,X), 4);

	return 0;
}