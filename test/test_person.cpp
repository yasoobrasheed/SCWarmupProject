#include "gtest/gtest.h"
#include "person.h"

// this class is used for testing public methods in class Person
class test_person: public ::testing::Test {
protected:
	Person person;
	Person recipient;
};

// test get_username and set_username
TEST_F(test_person, test_username) {
	// Char Limit
	EXPECT_FALSE(person.set_username("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"));
	EXPECT_TRUE(person.set_username("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
 	EXPECT_STREQ(person.get_username().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");

	// Alphanumeric Rules
	EXPECT_TRUE(person.set_username("abcdefg0"));
	EXPECT_STREQ(person.get_username().c_str(), "abcdefg0");
	EXPECT_FALSE(person.set_username("0abcdefg"));
	EXPECT_FALSE(person.set_username("abcdefg"));
	EXPECT_FALSE(person.set_username("0123456"));
	EXPECT_FALSE(person.set_username(""));
}

// test get_firstname and set_firstname
TEST_F(test_person, test_firstname) {
	// Char Limit
	EXPECT_FALSE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"));
	EXPECT_TRUE(person.set_firstname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
 	EXPECT_STREQ(person.get_firstname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");

	// Alphanumeric Rules
	EXPECT_FALSE(person.set_firstname("abcdefg0"));
	EXPECT_FALSE(person.set_firstname("abcdefg;"));
	EXPECT_FALSE(person.set_firstname(""));
}

// test get_lastname and set_lastname
TEST_F(test_person, test_lastname) {
	// Char Limit
	EXPECT_FALSE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklm"));
	EXPECT_TRUE(person.set_lastname("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl"));
 	EXPECT_STREQ(person.get_lastname().c_str(), "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijkl");

	// Alphanumeric Rules
	EXPECT_FALSE(person.set_lastname("abcdefg0"));
	EXPECT_FALSE(person.set_lastname("abcdefg;"));
	EXPECT_FALSE(person.set_lastname(""));
}

// test get_age and set_age
//   test_person is the name of class your inherit from the base Test class
//   test_age is the name of this test case, which will show up in the test
//     results
//   make sure you cover every subroutine and branches
//   here we test edge cases of invalid ages
//   also, we test the get_age() method
//   avoid using ASSERT_FALSE here; if there is something wrong in ASSERT,
//   it will abort the whole testing which will hinder the grading process
TEST_F(test_person, test_age) {
	// Edge Cases
	EXPECT_FALSE(person.set_age(-1));
	EXPECT_FALSE(person.set_age(17));
	EXPECT_FALSE(person.set_age(101));
	EXPECT_FALSE(person.set_age(25.1));
	EXPECT_FALSE(person.set_age(NULL));

	// Truth
	EXPECT_TRUE(person.set_age(18));
	EXPECT_EQ(person.get_age(), 18);
}

//test get_gender and set_gender
TEST_F(test_person,test_gender){
	// Edge Cases
	EXPECT_TRUE(person.set_gender(""))
}

// test get_tagline and set_tagline
TEST_F(test_person, test_tagline) {
}

// test get_info and set_info
TEST_F(test_person, test_info) {
}



// test get_msgstat, send_msg and read_msg
//   to make your code shorter, we suggest combining these tests together; you
//   can also separate them into several test cases
TEST_F(test_person, test_msg) {
}
