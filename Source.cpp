#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Array<int> arr, arr2, arr_buf;
	int choise, size, grow, index, value;
	int* mas_data;

	enum MENU {
		EXIT = 0,
		GETSIZE, //Размер массива
		SETSIZE, //Установить размер
		LAST_INDEX, //Посмотреть последний индекс
		ISEMPTY, //Пуст?
		DELETE_FREE, //Удалить лишнюю память
		CLEAR, //Удалить всё
		GET_INDEX, //Получить по индексу
		SET_INDEX, //Установить по индексу
		ADD, //Добавить
		SUM, //"Сложить"
		ASSIGN, //Прировнять
		PRINT, //Вывести
		INSERT_INDEX, //Вставить по индексу
		DELETE_INDEX //Удалить по индексу
	};

	cout << "1 - Размер массива\n2 - Установка размера\n3 - Последний допустимый индекс\n4 - Пуст?\n5 - Удалить лишнюю память\n6 - Очистить\n7 - Получить элемент по индексу\n8 - Установить по индексу\n9 - Добавить значение\n10 - Сложение двух массивов\n11 - Прировнять массивы\n12 - Получить массив с данными(ВЫВОД)\n13 - Вставка элемента на заданную позицию\n14 - Удаление элемента с заданной позиции\n";

	do
	{
		try
		{
			cin >> choise;

			switch (choise)
			{
			case GETSIZE:
				cout << "Размер массива: " << arr.GetSize() << "\n";
				break;
			case SETSIZE:
				cout << "Введите размер: ";
				cin >> size;
				cout << "Введите для скольки элементов выделить память: ";
				cin >> grow;
				arr.SetSize(size, grow);
				break;
			case LAST_INDEX:
				cout << "Последний индекс: " << arr.GetUpperBound() << "\n";
				break;
			case ISEMPTY:
				if (arr.IsEmpty() == true)
				{
					cout << "Массив пуст\n";
				}
				else
				{
					cout << "Массив не пуст\n";
				}
				break;
			case DELETE_FREE:
				arr.FreeExtra();
				break;
			case CLEAR:
				arr.RemoveAll();
				break;
			case GET_INDEX:
				cout << "Введите индекс: ";
				cin >> index;
				cout << arr.GetAt(index);
				break;
			case SET_INDEX:
				cout << "Введите индекс: ";
				cin >> index;
				cout << "Введите то что хотите вставить: ";
				cin >> value;
				arr.SetAt(index, value);
				break;
			case SUM:
				arr.Append(arr2);
				break;
			case ADD:
				cout << "Введите то что хотите вставить: ";
				cin >> value;
				arr.Add(value);
				cout << "Введите то что хотите вставить(2): ";
				cin >> value;
				arr2.Add(value);
				break;
			case ASSIGN:
				arr2 = arr;
				break;
			case PRINT:
				mas_data = arr.GetData();
				cout << "Массив 1\n";
				print(mas_data, arr);

				mas_data = arr2.GetData();
				cout << "Массив 2\n";
				print(mas_data, arr);
				break;
			case INSERT_INDEX:
				cout << "Введите индекс: ";
				cin >> index;
				cout << "Введите то что хотите вставить: ";
				cin >> value;
				arr.InsertAt(index, value);
				break;
			case DELETE_INDEX:
				cout << "Введите индекс: ";
				cin >> index;
				arr.RemoveAt(index);
				break;
			case EXIT:
				break;
			}
		}
		catch (const out_of_range& range_er)
		{
			cout << range_er.what();
		}
	} while (choise != 0);


	return 0;
}