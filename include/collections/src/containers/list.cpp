/*
 * chain.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Sean
 *      TODO: Implement function sort()
 */
#pragma once

#include"includes/list.h"
namespace std {
	template<class T>
	list<T>::list() {
		basic_list<T>::basic_list();
	}
	template<class T>
	list<T>::list(unsigned long int newSize) {
		basic_list<T>::basic_list();
		while(_size < newSize)
			push_back(T());
	}
	template<class T>
	list<T>::list(unsigned long int newSize, unsigned long int newMax)
	: firstP(NULL), lastP(NULL), _size(0), _max(newMax) {
		if(newSize > newMax)
			throw this;
		while(_size < newSize)
			pushback(T());
	}
	template<class T>
	list<T>::list(unsigned long int new_size, ...) {
		basic_list<T>::basic_list();
		va_list newChain;
		handle_args(new_size, newChain, true);
	}
	template<class T>
	list<T>::list(const basic_list<T> &otherList) {
		basic_list<T>::basic_list();
		copy(otherList);
	}
	template<class T>
	list<T>::~list() {
		clear();
	}
	template<class T>
	void list<T>::copy(const basic_list<T> &otherList) {
		if(!empty())
			clear();
		for(unsigned long int i = 0; i < otherList.size(); i++)
			push_back(otherList[i]);
	}
	template<class T>
	void list<T>::sort() {

	}
	template<class T>
	void list<T>::resize(unsigned long int newSize) {
		if(_max < newSize)
			_max = newSize;
		while(_size < newSize)
			push_back(T());
	}
	template<class T>
	void list<T>::resize(unsigned long int args, ...) {
		if(_max < _size + args)
			_max = _size + args;
		va_list newChain;
		handle_args(args, newChain, true);
	}
	template<class T>
	void list<T>::push_front(unsigned long int args, ...) {
		va_list newList;
		handle_args(args, newList);
	}
	template<class T>
	void chain<T>::push_back(unsigned long int args, ...) {
		va_list newList;
		handle_args(args, newList, true);
	}
	template<class T>
	void list<T>::clear() {
		while(!empty())
			basic_list<T>::pop_back();
		_max = 0;
	}
	template<class T>
	basic_list<T> &list<T>::operator=(const basic_list<T> &otherList) {
		if(this != *otherList)
			copy(otherList);
		return *this;
	}
	template<class T>
	T &list<T>::operator[](unsigned long int n) {
		if(n >= basic_list<T>::_size)
			throw n;//new out_of_range("");
		if(n < _size / 2)
			return traverse(n, true);
		else
			return traverse(n, false);
	}
	template<class T>
	void list<T>::handle_args(unsigned long int argc,
			va_list &argv,
			bool end = 0x00) {
		va_start(argv, argc);
		unsigned long int i = 0;
		if(end)
			while(i < argc) {
				push_front(va_arg(argv, T));
				i++;
			}
		else
			while(i < argc) {
				push_back(va_arg(argv, T));
				i++;
			}
		va_end(argv);
	}
	template<class T>
	T &list<T>::traverse(unsigned long int n, bool lower) {
		unsigned long int index = lower ? 0 : _size - 1;
		node<T> *traversalP = lower ? firstP : lastP;
		do {
			if(index == n)
				return traversalP->val;
			index += lower ? 1 : -1;
			traversalP = lower ? traversalP->rightP : traversalP->leftP;
		} while(traversalP != NULL);
	}
}