#include <iostream>
#include "Rectangle.h"
#include "User.h"

int main()
{
	Rectangle r1(0,2,0,0,8,0);
	r1.Print();
	Rectangle r2;
	r2.Print();
	Rectangle r3 = r1 + r2;
	r3.Print();
	User u;
	u.Interact(r2);
	return 0;
}

 