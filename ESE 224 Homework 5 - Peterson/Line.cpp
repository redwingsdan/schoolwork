#include "Line.h"
Line::Line():length(1){
	fixed.setX(0);
	fixed.setY(0);
	second.setX(1);
	second.setY(0);
}
Line::Line(Point p, double l){
	fixed = p;
	length = l;
	second.setX(l +fixed.getX());
	second.setY(0);
}
Line::Line(Point p, Point p2, double l){
	fixed = p;
	second = p2;
	length = l;
}
Point Line::getfixed() const{
	return fixed;
}
Point Line::getsecond() const{
	return second;
}
double Line::getlength() const{
	return length;
}
void Line::printLine() const{
	cout << "(" << fixed.getX() << "," <<
		fixed.getY() << ") (" << second.getX() <<
		"," << second.getY() << ") L= " << length;
}
void Line::setline(Point p){
	double dx, dy;
	dx = p.getX() - fixed.getX();
	dy = p.getY() - fixed.getY();
	fixed = p;
	second.setX(second.getX() +dx);
	second.setY(second.getY() +dy);
}
void Line::setline(double dx, double dy){
	fixed.setX(fixed.getX()+dx);
	second.setX(second.getX()+dx);
	fixed.setY(fixed.getY()+dy);
	second.setY(second.getY()+dy);
}
void Line::changeline(double newL){
	length = newL;
}