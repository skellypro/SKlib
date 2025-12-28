/*
 * @author: Sean Kelly
 * TODO: overload function resize() to take additional arguments
 */
#pragma once

#include"includes/rlist.h"
namespace std {
	template<class T>
	rlist<T>::rlist() {
		basic_list<T>::basic_list();
	}
	template<class T>
	rlist<T>::rlist(unsigned long int new_size) {
		basic_list<T>::basic_list();
		grow(new_size);
	}
	template<class T>
	rlist<T>::rlist(unsigned long int new_size, ...) {
		basic_list<T>::basic_list();
		va_list newList;
		va_start(newList, new_size);
		varAdd(newList, new_size);
		va_end(newList);
	}
	template<class T>
	rlist<T>::rlist(const basic_list<T> &otherList) {
		basic_list<T>::basic_list();
		copy(otherList);
	}
	template<class T>
	rlist<T>::~rlist() {
		clear();
	}
	template<class T>
	void rlist<T>::copy(const basic_list<T> &otherList) {
		if(!empty)
			clear();
		grow(otherList._size, otherList);
	}
	template<class T>
	void rlist<T>::clear() {
		if(empty())
			_max = 0;
		else {
			basic_list<T>::pop_front();
			clear();
		}
	}
	template<class T>
	void rlist<T>::resize(unsigned long int newSize) {
		if(_max < newSize)
			_max = newSize;
			grow(newSize - _size);
	}
	// TODO: fix these functions.
	template<class T>
	void rlist<T>::resize(unsigned long int args, ...) {
		va_list newVals;
		va_start(newVals, args);
		varAdd(newVals, args + _size, _size - 1);
		va_end();
	}
	template<class T>
	void rlist<T>::push_front(unsigned long int args, ...) {
		va_list newVals;
		va_start(newVals, args);
		varAddFront(newVals, args);
		va_end();
	}
	template<class T>
	void rlist<T>::push_back(unsigned long int args, ...) {
		va_list newVals;
		va_start(newVals, args);
		varAddBack(newVals, args);
		va_end();
	}
	template<class T>
	basic_list<T> &rlist<T>::operator=(const basic_list<T> &otherList) {
		if(this != *otherList)
			copy(otherList);
		return *this;
	}
	template<class T>
	T &rlist<T>::operator[](unsigned long int n) {
		if(n > _size)
			throw n;
		if(n > _size / 2)
			return left(lastP, _size - 1, n);
		return right(firstP, 0, n);
	}
	template<class T>
	bool rlist<T>::grow(unsigned long int size,
			const basic_list<T> &otherList = NULL) {
		if(full())
			return false;
		if(_size != size) {
			if(&otherList == NULL)
				push_back(T());
			else
				push_back(otherList[_size + 1]);
			return grow(size, otherList);
		}
		return true;
	}
	template<class T>
	T &rlist<T>::left(node<T> *nextNode,
			unsigned long int i,
			unsigned long int index) {
		if(i == index)
			return *(nextNode->val);
		return left(nextNode->leftP, i - 1, index);
	}
	template<class T>
	T &rlist<T>::right(node<T> *nextNode,
			unsigned long int i,
			unsigned long int index) {
		if(i == index)
			return *(nextNode->val);
		return right(nextNode->rightP, i + 1, index);
	}
	template<class T>
	bool rlist<T>::varAdd(va_list &newList,
			unsigned long int new_size,
			unsigned long int index = 0) {
		if(index == new_size)
			return true;
		push_back(va_arg(newList,T));
		return varAdd(newList, new_size, index + 1);
	}
	//TODO: fix this
	template<class T>
	bool rlist<T>::varAddFront(va_list &newList,
			unsigned long int args,
			unsigned long int index = 0) {
		if(args == index)
			return true;
		push_front(va_arg(newList, T));
		return varAdd(newList, args, index + 1);
	}
	template<class T>
	bool rlist<T>::varAddBack(va_list &newList,
			unsigned long int args,
			unsigned long int index = 0) {
		if(args == index)
			return true;
		push_back(va_arg(newList, T));
		return varAdd(newList, args, index + 1);
	}
}