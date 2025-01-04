#include "Array.h"

template<class T>
void Array<T>::SetSize(int size, int grow)
{
	if (size < 0)
	{
		throw out_of_range ("Размер не может быть меньше 0\n");
	}
	if (mas.size() < size)
	{
		mas.resize(size + grow);
	}
	else if (mas.size() > size)
	{
		mas.resize(size - grow);
	}
}

template<class T>
void Array<T>::RemoveAll()
{
	if (GetSize() == 0)
	{
		throw out_of_range("Удалять нечего. Список пуст\n");
	}
	mas.clear();
}

template<class T>
void Array<T>::SetAt(int index, T value) noexcept
{
	if (index < mas.size())
	{
		//Создание итератора указывающего на начало листа
		auto pos = mas.begin();
		//advance - функция которая заменеяет += к итератору, 
		// т.к. лист не поддерживает +=
		advance(pos, index);
		*pos = value;
	}
}

template<class T>
void Array<T>::Append(const Array<T>& mas2) noexcept
{
	//Метод insert() вставляет начиная с позиции, на которую указывает итератор pos,
	//элементы из другого контейнера из диапазона между итераторами begin и end.
	mas.insert(mas.end(), mas2.mas.begin(), mas2.mas.end());
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& mas2) noexcept
{
	RemoveAll();
	mas.insert(mas.begin(), mas2.mas.begin(), mas2.mas.end());

	return *this;
}

template<class T>
T* Array<T>::GetData() noexcept
{
	T* mas_data = new T[mas.size()];
	size_t i = 0;
	for (auto& elem : mas)
	{
		mas_data[i] = elem;
		i++;
	}

	return mas_data;
}

template<class T>
void Array<T>::InsertAt(int index, T value) noexcept
{
	auto pos = mas.begin();
	advance(pos, index);
	mas.insert(pos, value);
}

template<class T>
void Array<T>::RemoveAt(int index) noexcept
{
	auto pos = mas.begin();
	advance(pos, index);
	//Метод erase() удаляет элементы из диапазона,
	//на начало и конец которого указывают итераторы begin и end
	mas.erase(pos);
}

template<class T>
void Array<T>::FreeExtra() noexcept
{
	while (mas.size() > GetUpperBound() + 1)
	{
		mas.pop_back();
	}
}

template<class T>
Array<T> Array<T>::operator[] (int index) const noexcept
{
	if (index < 0 || index > mas.size())
	{
		//Выброс исключения при выходе за рамки индексов
		throw out_of_range("\nОшибка.Такого индекса не существует!\n");
	}
	auto pos = mas.begin();
	pos += index;
	return *pos;
}

template<class T>
Array<T> Array<T>::operator[] (int index) noexcept
{
	if (index < 0 || index > mas.size())
	{
		//Выброс исключения при выходе за рамки индексов
		throw "\nОшибка.Такого индекса не существует!\n";
	}
	auto pos = mas.begin();
	advance(pos, index);
	return *pos;
}