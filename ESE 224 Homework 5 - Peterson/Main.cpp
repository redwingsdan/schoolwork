#include <iostream>
#include "Line.h"

using namespace std;

int main()
{
	Line l1;
	Point p1;
	p1.setX(1);
	p1.setY(4);
	Line l2(p1,2);
	Point p2;
	p2.setX(2);
	p2.setY(4);
	Line l3(p1, p2, 1);
	l1.printLine();
	cout << endl;
	l2.printLine():
	cout << endl;
	l3.printLine();
	cout << endl;
	l1.setline(p1);
	cout << "New c1: ";
	l1.printLine();
	cout << endl:
	l3.changeline(10);
	cout << "New c3: ";
	l3.printLine();
	cout << endl;

	Point p3 = l2.getfixed();
	Point p4 = l2.getsecond();

	cout << "l2 fixed point : (" << p3.getX() <<
		"," << p3.getY() << ")" << endl;

	cout << "l2 second point : (" << p4.getX() <<
		"," << p4.getY() << ")" << endl;

	cout << "l2 length = " << c2.getlength() << endl;


	return 0;
}