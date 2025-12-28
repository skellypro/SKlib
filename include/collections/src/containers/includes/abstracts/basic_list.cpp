/*
 *	@author: Sean Kelly
 */
#pragma once

#include"interfaces/basic_list.h"
namespace std {
	template<class T>
	basic_list<T>::basic_list()
	:_size(0), _max(0), firstP(NULL), lastP(NULL) {}
	template<class T>
	void basic_list<T>::push_back(const T &newVal) const {
		if(!full())
			add(lastP, newVal, false);
	}
	template<class T>
	void basic_list<T>::push_front(const T &newVal) const {
		if(!full())
			add(firstP, newVal, true);
	}
	template<class T>
	const T &basic_list<T>::front() const {
		return firstP->val;
	}
	template<class T>
	const T &basic_list<T>::back() const {
		return lastP->val;
	}
	template<class T>
	void basic_list<T>::pop_front() {
		remove(firstP, true);
	}
	template<class T>
	void basic_list<T>::pop_back() {
		remove(lastP, false);
	}
	template<class T>
	const unsigned long int basic_list<T>::size() const {
		return _size;
	}
	template<class T>
	const unsigned long int basic_list<T>::max() const {
		return _max;
	}
	template<class T>
	bool basic_list<T>::full() const {
		return _max > 0 && _size == _max;
	}
	template<class T>
	bool basic_list<T>::empty() const {
		return _size == 0;
	}
	template<class T>
	void basic_list<T>::add(node<T> *addPoint, const T &newVal, bool first) {
		if(full())
			return;
		node<T> *newNode = new node<T>(newVal);
		if(empty())
			firstP = lastP = newNode;
		else {
			if(first)
				firstP = firstP->leftP = newNode;
			else
				lastP = lastP->rightP = newNode;
		}
	}
	template<class T>
	void basic_list<T>::remove(node<T> *deletePoint, bool first) {
		if(empty())
			return;
		if(first) {
			firstP = firstP->rightP;
			delete firstP->leftP;
			firstP->leftP = NULL;
		}
		else {
			lastP = lastP->leftP;
			delete lastP->rightP;
			lastP->rightP = NULL;
		}
	}
}
