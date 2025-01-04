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
public:
	Array()noexcept : Array{ list<T>(), 0} {};
	Array(list<T> mas_S, size_t size_S) noexcept : mas{ mas_S } {};

	Array(Array&& arr) noexcept : mas{ arr.mas } { arr.mas.clear(); }
	Array(const Array& arr) noexcept : mas{ arr.mas } {};

	int GetSize() const noexcept { return mas.size(); }
	int GetUpperBound() const noexcept { return mas.size() - 1; }
	void SetSize(int size, int grow = 1);
	bool IsEmpty() const noexcept { return mas.empty(); }
	void RemoveAll();
	Array<T> GetAt(int index) { return this[index]; }
	void SetAt(int index, T value)noexcept;
	void Add(T value)noexcept { mas.push_back(value); }
	void Append(const Array<T>& mas2)noexcept;
	Array<T>& operator=(const Array<T>& mas2)noexcept;
	T* GetData()noexcept;
	void InsertAt(int index, T value)noexcept;
	void RemoveAt(int index)noexcept;
	void FreeExtra()noexcept;

	Array<T> operator[] (int index) const noexcept;
	Array<T> operator[] (int index)noexcept;
};