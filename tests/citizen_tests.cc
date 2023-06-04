#include <citizen/citizen.h>
#include <gtest/gtest.h>
#include <string.h>

using namespace citizen;
using namespace std;


TEST(citizen_test, payment_schoolboy1)
{
	auto aa1 = make_shared<Schoolboy>("asd", "asd", "asd", "asd", 123, true);
	double a1 = aa1->payment();
	EXPECT_NEAR(a1, 8100.0, EPSILON);
}
TEST(citizen_test, payment_schoolboy2)
{
	auto aa2 = make_shared<Schoolboy>("asd", "asd", "asd", "asd", 123, false);
	double a2 = aa2->payment();
	EXPECT_NEAR(a2, 0.0, EPSILON);
}

TEST(citizen_test, payment_student1)
{
	auto aa1 = make_shared<Student>("asd", "asd", "asd", "asd", 123, 1.5);
	double a1 = aa1->payment();
	EXPECT_NEAR(a1, 0.0, EPSILON);
}
TEST(citizen_test, payment_student2)
{
	auto aa2 = make_shared<Student>("asd", "asd", "asd", "asd", 123, 3.5);
	double a2 = aa2->payment();
	EXPECT_NEAR(a2, 8100.0, EPSILON);
}
TEST(citizen_test, payment_student3)
{
	auto aa3 = make_shared<Student>("asd", "asd", "asd", "asd", 123, 4.3);
	double a3 = aa3->payment();
	EXPECT_NEAR(a3, 10692.0, EPSILON);
}
TEST(citizen_test, payment_student4)
{
	auto aa4 = make_shared<Student>("asd", "asd", "asd", "asd", 123, 5.0);
	double a4 = aa4->payment();
	EXPECT_NEAR(a4, 12960.0, EPSILON);
}

TEST(citizen_test, payment_pensioner1)
{
	auto aa1 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 0);
	EXPECT_NEAR(aa1->payment(), 0, EPSILON);
}
TEST(citizen_test, payment_pensioner2)
{
	auto aa2 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 3);
	EXPECT_NEAR(aa2->payment(), 0, EPSILON);
}
TEST(citizen_test, payment_pensioner3)
{
	auto aa3 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 5);
	EXPECT_NEAR(aa3->payment(), 16200, EPSILON);
}
TEST(citizen_test, payment_pensioner4)
{
	auto aa4 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 23);
	EXPECT_NEAR(aa4->payment(), 51192, EPSILON);
}
TEST(citizen_test, payment_pensioner5)
{
	auto aa5 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 30);
	EXPECT_NEAR(aa5->payment(), 64800, EPSILON);
}
TEST(citizen_test, payment_pensioner6)
{
	auto aa6 = make_shared<Pensioner>("asd", "asd", "asd", "asd", 31);
	EXPECT_NEAR(aa6->payment(), 81000, EPSILON);

}

TEST(citizen_test, schoolboy_get_test) {
	auto aa1 = make_shared<Schoolboy>("Samantha", "Sims", "Pace", "Massachusetts", 165237, true);
	EXPECT_EQ(aa1->get_last_name(), "Samantha");
	EXPECT_EQ(aa1->get_first_name(), "Sims");
	EXPECT_EQ(aa1->get_middle_name(), "Pace");
	EXPECT_EQ(aa1->get_school_name(), "Massachusetts");
	EXPECT_EQ(aa1->get_ID_number(), 165237);
	EXPECT_EQ(aa1->get_large_fam(), true);
}

TEST(citizen_test, student_get_test){
	auto aa1 = make_shared<Student>("Samantha", "Sims", "Pace", "Massachusetts", 615234, 3.0);
	EXPECT_EQ(aa1->get_last_name(), "Samantha");
	EXPECT_EQ(aa1->get_first_name(), "Sims");
	EXPECT_EQ(aa1->get_middle_name(), "Pace");
	EXPECT_EQ(aa1->get_university_name(), "Massachusetts");
	EXPECT_EQ(aa1->get_ID_number(), 615234);
	EXPECT_NEAR(aa1->get_average_grade(), 3.0, EPSILON);

}

TEST(citizen_test, pensioner_get_test) {
	auto aa1 = make_shared<Pensioner>("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	EXPECT_EQ(aa1->get_last_name(), "Samantha");
	EXPECT_EQ(aa1->get_first_name(), "Sims");
	EXPECT_EQ(aa1->get_middle_name(), "Pace");
	EXPECT_EQ(aa1->get_snils(), "677-351-892-48");
	EXPECT_EQ(aa1->get_experience(), 24);

}