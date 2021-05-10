#include <iostream>
#include "QuadEquat.h"

int main(void) {
	QuadEquat example1(0,0,0);
	example1.PrintRoots( );

	QuadEquat example2(1,17,-18);
	example2.PrintRoots( );

	QuadEquat example3(2, -9, 7);
	example3.PrintRoots( );

	return 0;
}