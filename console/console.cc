#include <citizen/citizen.h>
#include<iostream>
#include <conio.h>

using namespace citizen;
using namespace std;

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
	{
		key = _getch();
	}
	return key;
}
void Arrow(int position_real, int position)
{
	if (position_real == position)
	{
		printf("-->");
	}
	else
	{
		printf("   ");
	}
}
int Menu()
{
	int position = 1;
	int KeyPres = 0;
	while (KeyPres != 13)
	{
		cout<<"\t����\t"<< endl;
		Arrow(1, position); cout<< "�������� ������� � ������ �� ���������� �������"<<endl;
		Arrow(2, position); cout << "������� ������� �� ������ �� ��������� �������" << endl;
		Arrow(3, position); cout << "������� ������ �� �����"<<endl;
		Arrow(4, position); cout << "����� �� ������������ �������" << endl;
		Arrow(5, position); cout << "�������� ������� � ����� ������" << endl;
		Arrow(6, position); cout << "�����" << endl << endl;
		KeyPres = GetKey();
		system("cls");
		if (KeyPres == 72 && position != 1)
			position--;
		else if (KeyPres == 80 && position != 6)
		{
			position++;
		}


	}
	return position;
}

int main() {
	setlocale(LC_ALL, "Russian");
	CitizenList List;
	CitizenPtr citizen1;
	while (true)
	{
		int choice1 = Menu();
		switch (choice1)
		{
		case 1:
		{
			cout << "�� ������ � ������� ������� �������� � ������ �� ��������� �������" << endl;
			int index = 0;
			cout << "������� ������ ��� ������� ��������" << endl;
			cin >> index;
			cout << "�������� ������ ������ �� ������ ��������: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
			int choice2 = 0;
			cin >> choice2;
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				cout << "�� ����� ����������� ������!";
				break;
			}
			std::string first_name;
			std::string last_name;
			std::string middle_name;

			switch (choice2)
			{

				case 1: //��������
				{
					std::string school_name;
					int shool_ID_number;
					bool large_fam;

					cout << "������� �������: " << endl;
					cin >> last_name;
					cout << "������� ���: " << endl;
					cin >> first_name;
					cout << "������� ��������: " << endl;
					cin >> middle_name;
					cout << "������� �������� �����: " << endl;
					cin >> school_name;
					cout << "������� ����� ������������ �����: ";
					cin >> shool_ID_number;
					cout << "������� ���� �������������� � ����������� ����� (1/0): ";
					cin >> large_fam;

					citizen1 = Citizen::create_schoolboy(last_name, first_name, middle_name, school_name, shool_ID_number, large_fam);
					break;
				}
				case 2:
				{
					std::string university_name;
					int student_ID_number;
					double average_grade;

					cout << "������� �������: " << endl;
					cin >> last_name;
					cout << "������� ���: " << endl;
					cin >> first_name;
					cout << "������� ��������: " << endl;
					cin >> middle_name;
					cout << "������� �������� ������������: " << endl;
					cin >> university_name;
					cout << "������� ����� �������� ������: " << endl;
					cin >> student_ID_number;
					cout << "������� ������� ���� " << endl;
					cin >> average_grade;

					citizen1 = Citizen::create_student(last_name, first_name, middle_name, university_name, student_ID_number, average_grade);
					break;

				}
				case 3:
				{

					std::string snils;
					int experience;

					cout << "������� �������: " << endl;
					cin >> last_name;
					cout << "������� ���: " << endl;
					cin >> first_name;
					cout << "������� ��������: " << endl;
					cin >> middle_name;
					cout << "������� �����: " << endl;
					cin >> snils;
					cout << "������� ����: " << endl;
					cin >> experience;
					citizen1 = Citizen::create_pensioner(last_name, first_name, middle_name, snils, experience);
					break;

				}
			}	
				List.insert(citizen1, index);
			break;
		}
		case 2: {

			cout << "�� ������ � ������� �������� �������" << endl;
			if (List.size() == 0)
			{
				cout << "� ����� ������ ��� ����������!" << endl << "�������� ���������� � ���������� �����!" << endl << endl;
				break;
			}
			cout << "������� ������ �������, ������� ������ �������" << endl;
			int index = -1;
			cin >> index;
			List.remove(index);
			break;
		}
		case 3: {
			int size = List.size();
			if (size == 0)
			{
				cout << "� ����� ������ ��� ����������!" << endl << "�������� ���������� � ���������� �����!" << endl << endl;
				break;
			}
			for (int i = 0; i < size; i++)
			{
				cout << List[i];
			}
			break;
		}
		case 4: {
			if (List.size() == 0)
			{
				cout << "� ����� ������ ��� ����������!" << endl << "�������� ���������� � ���������� �����!" << endl << endl;
				break;
			}
			int index = search_max_payment(List);
			cout << "�������� � ������������ ���������� ������: " << endl;
			cout << List[index];
			break;
		}
		case 5:
		{
				cout << "�������� ������ ��������� �� ������ ��������: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
				int choice2 = 0;
				cin >> choice2;
				if (choice2 != 1 && choice2 != 2 && choice2 != 3)
				{
					cout << "�� ����� ����������� ������!";
					break;
				}
				std::string first_name;
				std::string last_name;
				std::string middle_name;

				switch (choice2)
				{

				case 1:
				{
					std::string school_name;
					int shool_ID_number;
					bool large_fam;

					cout << "������� �������: " << endl;
					cin >> last_name;
					cout << "������� ���: " << endl;
					cin >> first_name;
					cout << "������� ��������: " << endl;
					cin >> middle_name;
					cout << "������� �������� �����: " << endl;
					cin >> school_name;
					cout << "������� ����� ������������ �����: " << endl;
					cin >> shool_ID_number;
					cout << "������� ���� �������������� � ����������� ����� (1/0): " << endl;
					cin >> large_fam;

					citizen1 = Citizen::create_schoolboy(last_name, first_name, middle_name, school_name, shool_ID_number, large_fam);
					break;
				}
				case 2:
				{
					std::string university_name;
					int student_ID_number;
					double average_grade;

					cout << "������� �������: " << endl;
					cin >> last_name;
					cout << "������� ���: " << endl;
					cin >> first_name;
					cout << "������� ��������: " << endl;
					cin >> middle_name;
					cout << "������� �������� ������������: " << endl;
					cin >> university_name;
					cout << "������� ����� �������� ������: " << endl;
					cin >> student_ID_number;
					cout << "������� ������� ���� " << endl;
					cin >> average_grade;

					citizen1 = Citizen::create_student(last_name, first_name, middle_name, university_name, student_ID_number, average_grade);
					break;

				}
				case 3:
				{

					std::string snils;
					int experience;

					cout << "������� �������: " << endl;
					cin >> last_name;
					cout << "������� ���: " << endl;
					cin >> first_name;
					cout << "������� ��������: " << endl;
					cin >> middle_name;
					cout << "������� �����: " << endl;
					cin >> snils;
					cout << "������� ����: " << endl;
					cin >> experience;
					citizen1 = Citizen::create_pensioner(last_name, first_name, middle_name, snils, experience);
					break;
				}
				}
				List.add(citizen1);
				break;
		}
			case 6: 
			{
				cout << "������ ��������� ���������!" << endl;
				return 0;
			}
				
		}
	}
	return 0;
}