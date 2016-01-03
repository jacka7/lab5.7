#include <iostream>
#include <math.h>
#define PI 3.14159265358979323846

class Point
{
private:
	double _x, _y;
public:
	virtual void print();
	double getX();
	double getY();
	void setX(double x);
	void setY(double y);
	Point(double x, double y) :_x(x), _y(y){};
	Point() :_x(0), _y(0){};
	~Point();
};

class Line
{
private:
	double len;
	void newLine();
	Point first, second;
public:
	double getLen();
	void setLine(Point one, Point two);
	virtual void print();
	Point getPoint(int number);
	Line(Point _1, Point _2) :first(_1), second(_2), len(){ newLine(); };
	Line(double xFirst, double yFirst, double xSecond, double ySecond) :
		second(Point(xFirst, yFirst)), first(Point(xSecond, ySecond)), len() {newLine();};
	Line() :first(Point()), second(Point()), len(0){};
	~Line();
};

Point Line::getPoint(int number)
{
	if (number == 1) return first;
	return second;
}

class Parallelogram
{
private:
	double square;
	double perimetr;
	double angle;
	void newElements();
	Line lines[2];
public:
	Parallelogram(Point _1, Point _2, Point _3);
	double getSquare();
	double getAngle();
	double getPerimetr();
	void setParallelogram(Point _1, Point _2, Point _3);
	void print();
	Parallelogram() :perimetr(0), square(0){
		lines[0] = Line();
		lines[1] = Line();
	};
	~Parallelogram();
};

double Parallelogram::getAngle()
{
	return angle;
}

void Parallelogram::setParallelogram(Point _1, Point _2, Point _3)
{
	lines[0].setLine(_1, _2);
	lines[1].setLine(_2, _3);
	newElements();
}

void Parallelogram::print()
{
	std::cout << "first line:\n";
	lines[0].print();
	std::cout << "second line:\n";
	lines[1].print();
	std::printf("perimetr: %.2f\n", perimetr);
	std::printf("square: %.2f\n", square);
	std::printf("angle: %.0f\n", angle);
}

void Parallelogram::newElements()
{
	perimetr = 2*(lines[0].getLen() + lines[1].getLen());
	angle = 180/PI*acos(((lines[0].getPoint(2).getX()-lines[0].getPoint(1).getX())*(lines[1].getPoint(2).getX()-lines[1].getPoint(1).getX())+
		(lines[0].getPoint(2).getY() - lines[0].getPoint(1).getY())*(lines[1].getPoint(2).getY() - lines[1].getPoint(1).getY()))/
		(lines[0].getLen()*lines[1].getLen()));
	if (angle > 90) angle = 180 - angle;
	Line c(lines[0].getPoint(1),lines[1].getPoint(2));
	double p = c.getLen() + lines[0].getLen() + lines[1].getLen();
	square = 2*sqrt(p*(p - c.getLen())*(p - lines[0].getLen())*(p - lines[1].getLen()));
}

double Parallelogram::getPerimetr()
{
	return perimetr;
}

Parallelogram::Parallelogram(Point _1,Point _2,Point _3)
{
	lines[0] = Line(_1, _2);
	lines[1] = Line(_2, _3);
	perimetr = 2 * (lines[0].getLen() + lines[1].getLen());
	newElements();
}

double Parallelogram::getSquare()
{
	return square;
}

Parallelogram::~Parallelogram()
{}

Line::~Line()
{}

void Point::print()
{
	std::cout <<"("<< _x << "," << _y <<")"<< std::endl;
}

Point::~Point()
{}

double Point::getX()
{
	return _x;
}

double Point::getY()
{
	return _y;
}

void Point::setX(double x)
{
	_x = x;
}

void Point::setY(double y)
{
	_y = y;
}

void Line::newLine()
{
	len=sqrt((first.getX() - second.getX())*(first.getX() - second.getX()) +
		(first.getY() - second.getY())*(first.getY() - second.getY()));
}

double Line::getLen()
{
	return len;
}

void Line::setLine(Point one, Point two)
{
	first = one;
	second = two;
	newLine();
}

void Line::print()
{
	std::cout << "first: "; 
	first.print();
	std::cout << "second: ";
	second.print();
	std::printf("len: %.2f\n", len);
}

int main()
{
	Parallelogram myPar(Point(1, 2), Point(2, 3), Point(3, 5));
	myPar.print();
	system("pause");
	return 0;
}