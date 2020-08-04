#include<iostream>
#include "Point.h"

using namespace std;

class Line
{
	double length;
	Point fixed;
	Point second;
public:
	Line();
	Line{Point, double);
	Line(Point, Point, double);

	Point getfixed() const;
	Point getsecond() const;
	double getlength() const;
	void printline() const;

	void Line::setline(Point p);
	void setline(double dx=0, double dy=0);
	void changeline(double dl);
	};