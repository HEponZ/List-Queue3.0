#pragma once
#include <iostream>
#include <list>
#include <exception>

using namespace std;

template <class T>
class Array
{
private:
	list<T> mas;
	int last_index;
public:
	Array()noexcept : Array{ list<T>(), -1 } {};
	Array(list<T> mas_S, int grow_size_S) noexcept : mas{ mas_S }, last_index{ grow_size_S } {};

	Array(Array&& arr) noexcept : mas{ arr.mas } { arr.mas.clear(); }
	Array(const Array& arr) noexcept : mas{ arr.mas } {};

	int GetSize() const noexcept { return mas.size(); }
	int GetUpperBound() const noexcept { return last_index; }
	void SetSize(int size, int grow = 1);
	bool IsEmpty() const noexcept { return mas.empty(); }
	void RemoveAll();
	T GetAt(int index) { return (*this)[index]; }
	void SetAt(int index, T value);
	void Add(T value)noexcept 
	{ 
		last_index++;
		mas.push_back(value);
	}
	void Append(const Array<T>& mas2)noexcept;
	Array<T>& operator=(const Array<T>& mas2)noexcept;
	T* const GetData()noexcept;
	void InsertAt(int index, T value);
	void RemoveAt(int index);
	void FreeExtra()noexcept;

	T operator[] (int index) const noexcept;
	T operator[] (int index)noexcept;
};