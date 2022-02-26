#include <iostream>
using namespace std;

#define MAX_LINES 100
#define MAX_CLUES 50


int main() {
	cout << "NONOGRAM CHEATER" << endl;

	int rows;
	int rowClues;
	int cols;
	int colClues;

	cin >> rows;
	cin >> rowClues;
	cin >> cols;
	cin >> colClues;

	if (
		rows > MAX_LINES || 
		cols > MAX_LINES || 
		rowClues > MAX_CLUES || 
		colClues > MAX_CLUES) {

	}


	return 0;
}