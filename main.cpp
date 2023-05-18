#include <iostream>
#include "Dictionary.h"

int main() {
	Dictionary *d1 = new Dictionary();
	Person p1("John", "Doe", 1);
	Person p2("Bob", "Smith", 2);
	Person p3("Sam", "Lee", 3);
	
	d1->insert(p1);
	d1->insert(p2);
	d1->insert(p3);
	
	std::cout << d1->get_p("Doe, John").get_name() << std::endl;
	std::cout << d1->get_p("Smith, Bob").get_name() << std::endl;
	std::cout << d1->get_p("Lee, Sam").get_name() << std::endl;
	return 0;
}
