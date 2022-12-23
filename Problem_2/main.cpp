#include <fstream>
#include <vector>
#include <tuple>

using namespace std;


int main(int argc, char **argv) {

	ifstream readFile;
	readFile.open("input.txt", ifstream::in);

	vector<tuple<char,int>> storage;

	char read1;
	char read2;
	int converted2;

	while(readFile >> read1) {
		readFile >> read2;
		switch(read2) {
		case 'X':
			converted2 = 1;
			break;
		case 'Y':
			converted2 = 2;
			break;
		case 'Z':
			converted2 = 3;
			break;
		default:
			return 1;
		}
		storage.emplace_back(tuple<char,int>(read1,converted2));
	}

	readFile.close();

	return 0;
}