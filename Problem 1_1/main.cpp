#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int best = 0;
	int bestCalories = 0;
	int current = 1;
	int currentCalories = 0;

	string readIn;

	//ifstream readFile("input.txt", ios_base::in | ios_base::binary);
	ifstream readFile;
	readFile.open("input.txt", std::ifstream::in);
	//readFile.open("input.txt");

	//while(getline(readFile, readIn)) {
	//while (!readFile.eof()) {
	while (readFile.good()) {
		getline(readFile, readIn);
		if (!readIn.empty()) {
			currentCalories += stoi(readIn);
		}
		else {
			if (currentCalories > bestCalories) {
				bestCalories = currentCalories;
				currentCalories = 0;
				best = current;
				current++;
				if (argc!= 1 && current == stoi(argv[1])) {break;}
			}
		}
	} 
	while (readFile.good()) {
		getline(readFile, readIn);
		if (!readIn.empty()) {
			currentCalories += stoi(readIn);
		}
		else {
			if (currentCalories > bestCalories) {
				bestCalories = currentCalories;
				currentCalories = 0;
				best = current;
				current++;
				if (argc!= 1 && current == stoi(argv[1])) {break;}
			}
		}
	} 
	readFile.close();
	cout << current << endl;
	ofstream outFile;
	outFile.open("results.txt");
	outFile << "Best: " << best << endl;
	outFile << "Best Calories: " << bestCalories << endl;
	outFile.close();

	return 0;
}