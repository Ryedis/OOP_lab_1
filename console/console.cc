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
		Arrow(1, position); cout<< "�������� ������� � ����� ������"<<endl;
		Arrow(2, position); cout << "�������� ������� � ������ �� ���������� �������" << endl;
		Arrow(3, position); cout << "������� ������ �� �����"<<endl;
		Arrow(4, position); cout << "����� �� ������������ �������" << endl;
		Arrow(5, position); cout << "������� ������� �� ������ �� ��������� �������" << endl;
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
	while (true)
	{
		int choice1 = Menu();
		switch (choice1)
		{
		case 1:
		{
			cout << "�������� ������ ���������� �� ������ ��������: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
			int choice2 = 0;
			cin >> choice2;
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				cout << "�� ����� ����������� ������!" << endl;
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
				int ID_number;
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
				cin >> ID_number;
				cout << "������� ���� �������������� � ����������� ����� (1/0): " << endl;
				cin >> large_fam;

				List.add(make_shared<Schoolboy>(last_name, first_name, middle_name, school_name, ID_number, large_fam));
				break;
			}
			case 2:
			{
				std::string university_name;
				int ID_number;
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
				cin >> ID_number;
				cout << "������� ������� ���� " << endl;
				cin >> average_grade;

				List.add(make_shared<Student>(last_name, first_name, middle_name, university_name, ID_number, average_grade));
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
				List.add(make_shared<Pensioner>(last_name, first_name, middle_name, snils, experience));
				break;
			}
			}
			break;
		}
		case 2: {

			cout << "�� ������ � ������� ������� �������� � ������ �� ��������� �������" << endl;
			int index = 0;
			cout << "������� ������ ��� ������� ��������" << endl;
			cin >> index;
			cout << "�������� ������ ���������� �� ������ ��������: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
			int choice2 = 0;
			cin >> choice2;
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				cout << "�� ����� ����������� ������!" << endl;
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
				int ID_number;
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
				cin >> ID_number;
				cout << "������� ���� �������������� � ����������� ����� (1/0): " << endl;
				cin >> large_fam;

				List.insert(make_shared<Schoolboy>(last_name, first_name, middle_name, school_name, ID_number, large_fam), index);
				break;
			}
			case 2:
			{
				std::string university_name;
				int ID_number;
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
				cin >> ID_number;
				cout << "������� ������� ���� " << endl;
				cin >> average_grade;

				List.insert(make_shared<Student>(last_name, first_name, middle_name, university_name, ID_number, average_grade), index);
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
				List.insert(make_shared<Pensioner>(last_name, first_name, middle_name, snils, experience), index);
				break;

			}
			}
			break;
		}
		case 3: {
			int size = List.size();
			if (size == 0)
			{
				cout << "� ����� ������ ��� �����!" << endl << "�������� ������� � ���������� �����!" << endl << endl;
				break;
			}
			for (int i = 0; i < size; i++)
			{
				List[i]->print();
			}
			break;
		}
		case 4: {
			if (List.size() == 0)
			{
				cout << "� ����� ������ ��� �����!" << endl << "�������� ������� � ���������� �����!" << endl << endl;
				break;
			}
			int index = search_max_payment(List);
			cout << "��������� � ������������ ��������: " << endl;
			List[index]->print();
			cout << "������ �������: " << List[index]->payment() << endl;
			break;
		}
		case 5:
		{
			cout << "�� ������ � ������� �������� �������" << endl;
			if (List.size() == 0)
			{
				cout << "� ����� ������ ��� �����!" << endl << "�������� ������� � ���������� �����!" << endl << endl;
				break;
			}
			cout << "������� ������ �������, ������� ������ �������" << endl;
			int index = -1;
			cin >> index;
			List.remove(index);
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