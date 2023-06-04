#include <citizen/citizen.h>
#include <gtest/gtest.h>
#include <string.h>

using namespace citizen;
using namespace std;

TEST(CitizenListTest, size_add) {
	CitizenList test_list;
	EXPECT_EQ(test_list.size(), 0);

	auto aa1 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 0);
	test_list.add(aa1);

	EXPECT_EQ(test_list.size(), 1);
}

TEST(CitizenListTest, insert) {
	CitizenList test_list;
	auto aa1 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 0);
	auto aa2 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 0);
	auto aa3 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 0);
	test_list.add(aa1);
	test_list.add(aa2);

	test_list.insert(aa3, 1);

	EXPECT_EQ(test_list[1], aa3);

}

TEST(CitizenListTest, remove) {
	CitizenList test_list;
	auto aa1 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 0);
	auto aa2 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 0);
	test_list.add(aa1);
	test_list.add(aa2);

	test_list.remove(0);

	EXPECT_EQ(test_list[0], aa2);

}

TEST(CitizenListTests, size)
{
	CitizenList test_list;
	test_list.add(make_shared<Pensioner>("asd", "asd", "asd", "asd", 0));
	test_list.add(make_shared<Pensioner>("asd", "asd", "asd", "asd", 0));
	test_list.add(make_shared<Pensioner>("asd", "asd", "asd", "asd", 0));
	test_list.add(make_shared<Pensioner>("asd", "asd", "asd", "asd", 0));
	test_list.add(make_shared<Pensioner>("asd", "asd", "asd", "asd", 0));
	test_list.add(make_shared<Pensioner>("asd", "asd", "asd", "asd", 0));
	ASSERT_EQ(test_list.size(), 6);
}

TEST(CitizenListTests, exceptions) {
	CitizenList test_list;
	test_list.add(make_shared<Pensioner>("asd", "asd", "asd", "asd", 0));
	EXPECT_THROW(test_list[-1], out_of_range);
}