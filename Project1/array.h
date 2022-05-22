#pragma once
#include <iostream>
#include <algorithm>

class ArrayError {};

template<class T>
class Array {
	T* arr;
	int size;
public:
	Array() : size(0) {}
	Array(int s);
	Array(const Array<T>& obj) { copy(obj); }
	~Array() { clear(); }

	void resize(int s);
	void clear();
	void copy(const Array<T> &obj);
	void sort();

	T &at(int index);
	T &operator[] (int ind) { return at(ind); }
	Array<T> &operator= (const Array<T> &obj) { copy(obj); return *this; }
	int get_size() { return size; }

	template<class Z>
	friend std::ostream &operator<< (std::ostream &on, Array <Z> &obj);
};

template<class T>
Array<T>::Array(int s) : size(s)
{
	arr = new T[s];
}

template<class T>
void Array<T>::resize(int s)
{
	if (size == 0) {
		arr = new T[s];
		size = s;
		return;
	}
	T* temp = new T[s];
	int m_size = (s < size ? s : size);
	for (int i = 0; i < m_size; i++)
		temp[i] = arr[i];
	clear();
	arr = temp;
	size = s;
}
template<class T>
void Array<T>::clear()
{
	delete[] arr;
	size = 0;
}

template<class T>
void Array<T>::copy(const Array<T> &obj)
{
	if (size != 0)
		clear();
	size = obj.size;
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = obj.arr[i];
}
template<class T>
T &Array<T>::at(int index)
{
	if (index < 0 || index >= size)
		throw ArrayError();
	return arr[index];
}
template<class T>
void Array<T>::sort()
{
	std::sort(arr, arr + size);
}
template<class Z>
std::ostream &operator<< (std::iostream & os, Array<Z> &obj)
{
	for (int i = 0; i < obj.size; i++)
		os << obj.array[i] << " ";
	return os;
}