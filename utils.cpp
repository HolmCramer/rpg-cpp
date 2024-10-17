#include <iostream>
using namespace std;

int clr_scr() {
	cout << "\x1B[2J"; //cls
	return 0;
}
