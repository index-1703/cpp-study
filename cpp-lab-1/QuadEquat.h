#ifndef QUADEQUAT_H_INCLUDE__
#define QUADEQUAT_H_INCLUDE__

#include <iostream>
#include <vector>
#include <cmath>

class QuadEquat
{
public:
	QuadEquat(double a, double b, double c);
	~QuadEquat( );
	std::vector <double> Roots( );
	void PrintRoots( );

private:
	double a = 0.0;
	double b = 0.0;
	double c = 0.0;
	std::vector <double> roots;
};


#endif // !QUADEQUAT_H_INCLUDE__
