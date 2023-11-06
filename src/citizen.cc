#include <citizen/citizen.h>
#include <string>
#include <stdexcept>
#include <memory>

using namespace citizen;
using namespace std;

Citizen::Citizen(const string _last_name, const string _first_name, const string _middle_name) : last_name(_last_name), first_name(_first_name), middle_name(_middle_name) {}
Schoolboy::Schoolboy(const string _last_name, const string _first_name, const string _middle_name, const string _school_name, const int _ID_number, const bool _large_fam) : Citizen(_last_name, _first_name, _middle_name), school_name(_school_name), ID_number(_ID_number), large_fam(_large_fam) {}
Student::Student(const string _last_name, const string _first_name, const string _middle_name, const string _university_name, int _ID_number, double _average_grade) : Citizen(_last_name, _first_name, _middle_name), university_name(_university_name), ID_number(_ID_number), average_grade(_average_grade) {}
Pensioner::Pensioner(const string _last_name, const string _first_name, const string _middle_name, const string _snils, const int _experience) : Citizen(_last_name, _first_name, _middle_name), snils(_snils), experience(_experience) {}

string Citizen::get_last_name() const {
	return last_name;
}
string Citizen::get_first_name() const {
	return first_name;
}
string Citizen::get_middle_name() const {
	return middle_name;
}

string Schoolboy::get_school_name() const {
	return school_name;
}
int Schoolboy::get_ID_number() const {
	return ID_number;
}
bool Schoolboy::get_large_fam() const {
	return large_fam;
}

string Student::get_university_name() const {
	return university_name;
}
int Student::get_ID_number() const {
	return ID_number;
}
double Student::get_average_grade() const {
	return average_grade;
}

string Pensioner::get_snils() const {
	return snils;
}
int Pensioner::get_experience() const {
	return experience;
}

void Citizen::set_last_name(string _last_name) {
	last_name = _last_name;
}
void Citizen::set_first_name(std::string _first_name) {
	first_name = _first_name;
}
void Citizen::set_middle_name(std::string _middle_name) {
	middle_name = _middle_name;
}

void Schoolboy::set_large_fam(bool _large_fam) {
	large_fam = _large_fam;
}
void Schoolboy::set_school_name(std::string _school_name) {
	school_name = _school_name;
}
void Schoolboy::set_ID_number(int _ID_number) {
	ID_number = _ID_number;
}

void Student::set_average_grade(double _average_grade) {
	average_grade = _average_grade;
	if (average_grade < 0.0 || average_grade > 5.0)
		throw invalid_argument("[set_average_grade()] Invalid set type.");
}
void Student::set_university_name(std::string _university_name) {
	university_name = _university_name;
}
void Student::set_ID_number(int _ID_number) {
	ID_number = _ID_number;
}

void Pensioner::set_experience(int _experience) {
	experience = _experience;
	if (experience < 0)
		throw invalid_argument("[set_experience()] Invalid set type.");
}
void Pensioner::set_snils(std::string _snils) {
	snils = _snils;
}

unique_ptr<Citizen> Schoolboy::clone() const {
	return make_unique<Schoolboy>(last_name, first_name, middle_name, school_name, ID_number, large_fam);
}
unique_ptr<Citizen> Student::clone() const {
	return make_unique<Student>(last_name, first_name, middle_name, university_name, ID_number, average_grade);
}
unique_ptr<Citizen> Pensioner::clone() const {
	return make_unique<Pensioner>(last_name, first_name, middle_name, snils, experience);
}

double Schoolboy::payment() {
	double payment = 0;
	if (large_fam == true)
		payment = 0.5 * min_wage;
	return payment;

}
double Student::payment() {
	double payment = 0;
	if (average_grade >= 3.5 && average_grade <= 5.0)
		payment = (-0.2 + 0.2 * average_grade) * min_wage;
	return payment;
}
double Pensioner::payment() {
	double payment = 0;
	if (experience >= 5 && experience <= 30)
		payment = (0.4 + 0.12 * experience) * min_wage;
	if (experience > 30)
		payment = 5 * min_wage;
	return payment;

}

void Schoolboy::print(std::ostream& oc) const {
	oc << "\tШкольник: \t" << endl << get_last_name() << " " << get_first_name() << " " 
		<< get_middle_name() << endl << "Название школы: " << get_school_name() << endl
		<< "номер ученического билета: " << get_ID_number() << endl << "Принадлежность к многодетной семье: "
		<< get_large_fam() << endl;
}
void Student::print(std::ostream& oc) const {
	oc << "\tСтудент: \t" << endl << get_last_name() << " " << get_first_name() << " " 
		<< get_middle_name() << endl << "Название университета: " << get_university_name() << endl
		<< "номер зачётной книжки: " << get_ID_number() << endl << "средний балл: " 
		<< get_average_grade() << endl;
}
void Pensioner::print(std::ostream& oc) const {
	oc << "\tПенсионер: \t" << endl << get_last_name() << " " 
		<< get_first_name() << " " << get_middle_name() 
		<< endl << "СНИЛС: " << get_snils() << endl << "стаж: " 
		<< get_experience() << endl;
}