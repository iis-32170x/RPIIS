#include "youngtbl.hpp"
#include <string>
#include <sstream>
using namespace std;

int main()
{
	// Переключение кодовой страницы
	setlocale(LC_ALL, "Russian");
	
	// Таблица Юнга, методы над которой определены в header-файле
	YoungTableau t;
	
	cout << "Здравствуйте!\n";
	while (1)
	{
		cout << "\n1) Прочесть таблицу из файла";
		cout << "\n2) Просмотреть таблицу";
		cout << "\n3) Добавить элемент в таблицу";
		cout << "\n4) Удалить элемент из таблицы";
		cout << "\n5) Записать таблицу в файл";
		cout << "\n6) Выйти из программы";
		cout << "\nВаш выбор: ";
		int choice;
		cin >> choice;
		switch(choice)
		{
			// Чтение таблицы из файла
			case 1:
			{
				string ifname;
				cout << "\nВведите название текстового файла, из которого будет производиться ввод, без расширения: ";
				cin >> ifname;
				ifstream fin(ifname + ".txt");
				
				if (!fin)
				{
					cout << "Файл не существует.\n";
					break;
				}
				
				// Создание вектора из n пустых векторов как основы таблицы Юнга
				int n;
				fin >> n;
				t.initialize(n);

				// Ввод таблицы построчно
				for (int i = 0; i <= n; i++)
				{
					string u;
					getline(fin, u);
					istringstream iss(u);
					int num;
					while (iss >> num)
						t.add(i, num);
				}
				
				cout << "Таблица из " << ifname << ".txt была успешно прочитана.\n";
				break;
			}

			// Вывод таблицы на экран
			case 2:
			{
				t.print();
				break;
			}

			// Добавление элемента в таблицу
			case 3:
			{
				int k, e;
				cout << "\nВыберите строку, в которую вы хотите добавить элемент: ";
				cin >> k;
				if (k<1 || k>t.width())
				{
					cout << "Неверно введён номер строки.\n";
					break;
				}
				cout << "Введите элемент, который вы хотите добавить: ";
				cin >> e;
				t.add(k, e);
				cout << "В строку №" << k << " был добавлен элемент " << e << ".\n";
				break;
			}

			// Удаление элемента из таблицы
			case 4:
			{
				int r_ch, e;
				cout << "\nВведите e: ";
				cin >> e;
				cout << "Что вы хотите удалить?";
				cout << "\n1) Первый e, встретившийся в таблице";
				cout << "\n2) Все e в таблице";
				cout << "\nВаш выбор : ";
				cin >> r_ch;
				switch (r_ch)
				{
					case 1:
						t.remove(e);
						break;
					case 2:
						t.removeAll(e);
						break;
					default:
						cout << "Ошибка!\n\n";
				}
				break;
			}

			// Вывод таблицы в файл
			case 5:
			{
				string ofname;
				cout << "\nВведите название текстового файла, в который хотите произвести вывод, без расширения: ";
				cin >> ofname;
				t.printToFile(ofname + ".txt");
				break;
			}

			// Завершение работы
			case 6:
			{
				cout << "\nДо свидания!\n";
				return 0;
			}
			
			// Выбор действия не соответствует заранее определённому
			default:
			{
				cout << "Ошибка!\n\n";
			}
		}
	}
}