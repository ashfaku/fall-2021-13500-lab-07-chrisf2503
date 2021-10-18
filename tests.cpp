#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("testing if it remove space"){
	CHECK(removeLeadingSpaces(" something") == "something");
	CHECK(removeLeadingSpaces("	something") == "something");
	CHECK(removeLeadingSpaces(" 		something") == "something");
}
TEST_CASE("checking if the line of code has a open cerly"){
	CHECK(foundOpenCerly("int num = 2 ") == false);
	CHECK(foundOpenCerly("if(number == 2)") == false);
	CHECK(foundOpenCerly("for(...){ ") == true);
	CHECK(foundOpenCerly("int main() \n {") == true);
}//*/
TEST_CASE("checking if the line of code has a close cerly"){
	CHECK(foundCloseCerly("}") == true);
	CHECK(foundCloseCerly("if(...) {...} ") == true);
	CHECK(foundCloseCerly("some code") == false);
	CHECK(foundCloseCerly("{") == false);
}
