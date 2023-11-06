#pragma once
#include<iostream>
#include<string>
#include <memory>
#include <vector>

namespace citizen {
	const int min_wage = 16200;
	const float EPSILON = 0.00001f;
	class Citizen;
	using CitizenPtr = std::shared_ptr<Citizen>;

	class Citizen {
	protected:
		std::string last_name;
		std::string first_name;
		std::string middle_name;
		Citizen() = default;
		Citizen(const Citizen&) = default;
		Citizen& operator=(const Citizen&) = default;
	public:
		virtual double payment() = 0;
		virtual std::unique_ptr<Citizen> clone() const = 0;
		virtual void print(std::ostream& os = std::cout) const = 0;
		virtual ~Citizen() = default;
		std::string get_last_name() const;
		std::string get_first_name() const;
		std::string get_middle_name() const;
		void set_last_name(std::string last_name);
		void set_first_name(std::string first_name);
		void set_middle_name(std::string middle_name);
		Citizen(std::string _last_name, std::string _first_name, std::string _middle_name);
	};
	class Schoolboy : public Citizen
	{
	private:
		std::string school_name;
		int ID_number;
		bool large_fam;
	public:
		double payment() override;
		std::unique_ptr<Citizen> clone() const override;
		void print(std::ostream& os) const override;
		std::string get_school_name() const;
		int get_ID_number() const;
		bool get_large_fam() const;
		void set_school_name(std::string school_name);
		void set_ID_number(int ID_number);
		void set_large_fam(bool large_fam);
		Schoolboy(std::string LastName, std::string FirstName, std::string MiddleName, std::string school_name, int ID_number, bool large_fam);
	};
	class Student : public Citizen
	{
	private:
		std::string university_name;
		int ID_number;
		double average_grade;
	public:
		double payment() override;
		std::unique_ptr<Citizen> clone() const override;
		void print(std::ostream& os) const override;
		std::string get_university_name() const;
		int get_ID_number() const;
		double get_average_grade() const;
		void set_university_name(std::string university_name);
		void set_ID_number(int ID_number);
		void set_average_grade(double average_grade);
		Student(std::string _last_name, std::string _first_name, std::string _middl_name, std::string _university_name, int _ID_number, double _average_grade);
	};
	class Pensioner : public Citizen
	{
	private:
		std::string snils;
		int experience;
	public:
		double payment() override;
		std::unique_ptr<Citizen> clone() const override;
		void print(std::ostream& os) const override;
		std::string get_snils() const;
		int get_experience() const;
		void set_snils(std::string snils);
		void set_experience(int experience);
		Pensioner(std::string _last_name, std::string _first_name, std::string _middl_name, std::string snils, int experience);
	};

	class CitizenList {
	public:
		CitizenList() = default;
		CitizenList(const CitizenList& other);
		CitizenList& operator=(const CitizenList& other);
		int size() const;
		void swap(CitizenList& other);
		CitizenPtr operator[](int index) const;
		void add(CitizenPtr const f);
		void remove(int index);
		void insert(CitizenPtr people, int index);
	private:
		std::vector <CitizenPtr> _data;
	};
	int search_max_payment(const CitizenList& _citizen);
}