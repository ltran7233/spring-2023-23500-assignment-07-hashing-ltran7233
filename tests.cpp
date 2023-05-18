#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "OList.h"
#include "Node.h"
#include "Person.h"
#include "Dictionary.h"

Dictionary *d1 = new Dictionary();

TEST_CASE("insert"){
	Person p1("John", "Doe", 1);
	Person p2("Bob", "Smith", 2);
	Person p3("Sam", "Lee", 3);
	d1->insert(p1);
	d1->insert(p2);
	d1->insert(p3);
	CHECK(d1->get_p("Doe, John").get_name() == "Doe, John");
	CHECK(d1->get_p("Smith, Bob").get_name() == "Smith, Bob");
	CHECK(d1->get_p("Lee, Sam").get_name() == "Lee, Sam");
}
