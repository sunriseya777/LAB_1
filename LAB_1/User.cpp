#include "User.h"
#include <iostream>

void User::Interact(const Rectangle& r) {
	std::cout << "User works with rectangle\n";
	r.Print();
	std::cout << "Area: " << r.Area() << "\n";
	std::cout << "Perimeter " << r.Perimeter()<<"\n";
}