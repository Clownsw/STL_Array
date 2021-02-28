#pragma once

#include <iostream>
#include <string>
#include <Windows.h>

#ifndef MYARRAY_H_
#define MYARRAY_H

template <class T>
class Myarray
{
private:
	T *addr; //地址
	int capacity; //容量
	int size; //大小
public:
	Myarray(int capacity);
	Myarray(const Myarray& ob);
	~Myarray();

	//尾插法
	void Push_back(const T& val);
	//遍历数组
	void PrintArray();
	//获取指定数组项
	T& GetArray(int Array_num);

};

#endif // !MYARRAY_H_

template <class T>
Myarray<T>::Myarray(int capacity)
{
	this->addr = new T[capacity];
	this->capacity = capacity;
	this->size = 0;
}

template <class T>
Myarray<T>::Myarray(const Myarray& ob)
{
	this->capacity = ob.capacity;
	this->addr = new T[this->capacity];

	int i = 0;
	for (; i < ob.size; i++)
	{
		this->addr[i] = ob.addr[i];
	}

	this->size = ob.size;
}

template <class T>
Myarray<T>::~Myarray()
{
	if (this->addr != NULL)
	{
		delete[] this->addr;
		this->addr = NULL;
	}
}

template<class T>
void Myarray<T>::Push_back(const T & val)
{
	//判断数组的实际个数
	if (this->size == this->capacity)
	{
		std::cout << "容器已满" << std::endl;
		return;
	}
	
	this->addr[this->size] = val;
	this->size++;
}

template<class T>
void Myarray<T>::PrintArray()
{
	int i = 0;
	for (; i < this->size; i++)
	{
		std::cout << this->addr[i] << ' ';
	}

	std::cout << "析构\n";
}

template<class T>
T& Myarray<T>::GetArray(int Array_num)
{
	return this->addr[Array_num];
}
