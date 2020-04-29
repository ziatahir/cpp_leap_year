#define BOOST_TEST_MODULE sampleUnitTest
#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

BOOST_AUTO_TEST_CASE(test_case_1) {
    BOOST_TEST(1 + 1 == 2);
}

//functions to check logic
int addTwoNumbers(int i, int j ) {
 return i+j;
}

int checksize(std::string str ) {
 return str.size();
}

// test cases
BOOST_AUTO_TEST_CASE(test_case_2) {
 BOOST_CHECK(addTwoNumbers(2, 3) == 5);
}

BOOST_AUTO_TEST_CASE(test_case_3) {
 BOOST_CHECK(checksize("hello") == 5);
}
