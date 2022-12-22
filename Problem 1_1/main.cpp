#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	int best = 0;
	int bestCalories = 0;
	int current = 1;
	int currentCalories = 0;

	string readIn;
	vector<int> storage;

	ifstream readFile;
	readFile.open("input.txt", std::ifstream::in);

	for (int i = 0; i < 2264; i++){
		getline(readFile, readIn);
		if (!readIn.empty()) {
			currentCalories += stoi(readIn);
		}
		else {
			storage.emplace_back(currentCalories);
			currentCalories = 0;
			current++;
			if (argc!= 1 && current == stoi(argv[1])) {break;}
		}
	}
	readFile.close();
	cout << current << endl;

	sort(storage.begin(), storage.end(), greater<int>());

	int sum = storage.at(0) + storage.at(1) + storage.at(2);

	ofstream outFile;
	outFile.open("results.txt");
	outFile << "Sum of 3 Best Calories: " << sum << endl;
	outFile.close();

	return 0;
}