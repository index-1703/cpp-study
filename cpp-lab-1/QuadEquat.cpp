#include "QuadEquat.h"
#define EPS 1e-15

using namespace std;

static inline double Discriminant(double a, double b, double c)
{
	return b * b - 4.0 * a * c;
}

static inline bool isZero(double num)
{
	return fabs(num) < EPS;
}

static std::vector<double> SolQuadEquet(double a, double b, double c)
{
	double d = Discriminant(a, b, c);
	vector<double> res;
	if (d > 0.0) {
		double x1 = (-b + sqrt(d)) / (2.0 * a);
		double x2 = (-b - sqrt(d)) / (2.0 * a);
		res.push_back(x1);
		res.push_back(x2);
	} 
	else if(!isZero(d)) {
		double x1 = (-b) / (2.0 * a);
		res.push_back(x1);
	}

	return res;
}

static std::vector<double> SolLineEquet( double b, double c )
{
	vector<double> res;
	double x1 = (-c) / b;
	res.push_back(x1);

	return res;
}

QuadEquat::QuadEquat(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;

	if (!isZero(a)) {
		this->roots = SolQuadEquet(this->a, this->b, this->c);
	}
	else if (!isZero(b)) {
		this->roots = SolLineEquet(this->b, this->c);
	}
}

QuadEquat::~QuadEquat( )
{
	this->roots.clear( );
}

std::vector<double> QuadEquat::Roots( )
{
	return this->roots;
}

void QuadEquat::PrintRoots( )
{
	size_t size = this->roots.size( );

	cout.precision(15);
	cout << "Equation with coefficients: " 
		<< this->a << ", " << this->b << ", " << this->c 
		<< " has " << this->roots.size() << " ";

	cout << ((size > 1) ? "roots" : "root");

	if (size > 0) {
		cout << ": " << roots[0];
		if (size > 1)
			cout << ", " << roots[1];
	}

	cout << endl;
}
