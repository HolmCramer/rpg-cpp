#include <iostream>

int clr_scr() {
	std::cout << "\x1B[2J"; //cls
	return 0;
}