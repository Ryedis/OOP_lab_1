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
		cout<<"\tМеню\t"<< endl;
		Arrow(1, position); cout<< "Добавить элемент в конец списка"<<endl;
		Arrow(2, position); cout << "Вставить элемент в список по указанному индексу" << endl;
		Arrow(3, position); cout << "Вывести список на экран"<<endl;
		Arrow(4, position); cout << "Поиск по максимальной выплате" << endl;
		Arrow(5, position); cout << "Удалить элемент из списка по указаному индексу" << endl;
		Arrow(6, position); cout << "Выход" << endl << endl;
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
			cout << "Выберите какого гражданина вы хотите добавить: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
			int choice2 = 0;
			cin >> choice2;
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				cout << "Вы ввели некоректные данные!" << endl;
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

				cout << "Введите фамилию: " << endl;
				cin >> last_name;
				cout << "Введите имя: " << endl;
				cin >> first_name;
				cout << "Введите отчество: " << endl;
				cin >> middle_name;
				cout << "Введите название школы: " << endl;
				cin >> school_name;
				cout << "Введите номер ученического билет: " << endl;
				cin >> ID_number;
				cout << "Введите флаг принадлежности к многодетной семье (1/0): " << endl;
				cin >> large_fam;

				List.add(make_shared<Schoolboy>(last_name, first_name, middle_name, school_name, ID_number, large_fam));
				break;
			}
			case 2:
			{
				std::string university_name;
				int ID_number;
				double average_grade;

				cout << "Введите фамилию: " << endl;
				cin >> last_name;
				cout << "Введите имя: " << endl;
				cin >> first_name;
				cout << "Введите отчество: " << endl;
				cin >> middle_name;
				cout << "Введите название университета: " << endl;
				cin >> university_name;
				cout << "Введите номер зачётной книжки: " << endl;
				cin >> ID_number;
				cout << "Введите средний балл " << endl;
				cin >> average_grade;

				List.add(make_shared<Student>(last_name, first_name, middle_name, university_name, ID_number, average_grade));
				break;

			}
			case 3:
			{

				std::string snils;
				int experience;

				cout << "Введите фамилию: " << endl;
				cin >> last_name;
				cout << "Введите имя: " << endl;
				cin >> first_name;
				cout << "Введите отчество: " << endl;
				cin >> middle_name;
				cout << "Введите снилс: " << endl;
				cin >> snils;
				cout << "Введите стаж: " << endl;
				cin >> experience;
				List.add(make_shared<Pensioner>(last_name, first_name, middle_name, snils, experience));
				break;
			}
			}
			break;
		}
		case 2: {

			cout << "Вы попали в подменю вставки элемента в список по указаному индексу" << endl;
			int index = 0;
			cout << "Введите индекс для вставки элемента" << endl;
			cin >> index;
			cout << "Выберите какого гражданина вы хотите добавить: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
			int choice2 = 0;
			cin >> choice2;
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				cout << "Вы ввели некоректные данные!" << endl;
				break;
			}
			std::string first_name;
			std::string last_name;
			std::string middle_name;

			switch (choice2)
			{

			case 1: //школьник
			{
				std::string school_name;
				int ID_number;
				bool large_fam;

				cout << "Введите фамилию: " << endl;
				cin >> last_name;
				cout << "Введите имя: " << endl;
				cin >> first_name;
				cout << "Введите отчество: " << endl;
				cin >> middle_name;
				cout << "Введите название школы: " << endl;
				cin >> school_name;
				cout << "Введите номер ученического билет: " << endl;
				cin >> ID_number;
				cout << "Введите флаг принадлежности к многодетной семье (1/0): " << endl;
				cin >> large_fam;

				List.insert(make_shared<Schoolboy>(last_name, first_name, middle_name, school_name, ID_number, large_fam), index);
				break;
			}
			case 2:
			{
				std::string university_name;
				int ID_number;
				double average_grade;

				cout << "Введите фамилию: " << endl;
				cin >> last_name;
				cout << "Введите имя: " << endl;
				cin >> first_name;
				cout << "Введите отчество: " << endl;
				cin >> middle_name;
				cout << "Введите название университета: " << endl;
				cin >> university_name;
				cout << "Введите номер зачётной книжки: " << endl;
				cin >> ID_number;
				cout << "Введите средний балл " << endl;
				cin >> average_grade;

				List.insert(make_shared<Student>(last_name, first_name, middle_name, university_name, ID_number, average_grade), index);
				break;

			}
			case 3:
			{

				std::string snils;
				int experience;

				cout << "Введите фамилию: " << endl;
				cin >> last_name;
				cout << "Введите имя: " << endl;
				cin >> first_name;
				cout << "Введите отчество: " << endl;
				cin >> middle_name;
				cout << "Введите снилс: " << endl;
				cin >> snils;
				cout << "Введите стаж: " << endl;
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
				cout << "В вашем списке нет людей!" << endl << "Добавьте граждан и попробуйте снова!" << endl << endl;
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
				cout << "В вашем списке нет людей!" << endl << "Добавьте граждан и попробуйте снова!" << endl << endl;
				break;
			}
			int index = search_max_payment(List);
			cout << "Гражданин с максимальной выплатой: " << endl;
			List[index]->print();
			cout << "Размер выплаты: " << List[index]->payment() << endl;
			break;
		}
		case 5:
		{
			cout << "Вы попали в подменю удаление объекта" << endl;
			if (List.size() == 0)
			{
				cout << "В вашем списке нет людей!" << endl << "Добавьте граждан и попробуйте снова!" << endl << endl;
				break;
			}
			cout << "Введите индекс объекта, который хотите удалить" << endl;
			int index = -1;
			cin >> index;
			List.remove(index);
			break;
		}
			case 6: 
			{
				cout << "Работа программы завершена!" << endl;
				return 0;
			}
				
		}
	}
	return 0;
}