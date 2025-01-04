#include "Header.h"

void print(int* mas_data, Array<int>& arr)
{
	for (size_t i{ 0 }; i < arr.GetSize(); i++)
	{
		cout << mas_data[i] << " ";
	}
	cout << "\n";

	delete[] mas_data;
}