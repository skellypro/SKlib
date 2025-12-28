/*
 * basic_chain.h
 *
 *  Created on: May 20, 2015
 *      Author: Sean
 *      description: abstract class for chain and rchain
 */

#pragma once

#include"node.cpp"
#include<cstdarg>
namespace std {
	template<class T>
	class basic_list {
	public:
		virtual basic_list();
		virtual ~basic_list() = 0;
		virtual basic_list operator=(const basic_list &otherList) = 0;
		virtual T &operator[](unsigned long int n) = 0;
		virtual void clear() = 0;
		virtual void copy(const basic_list &otherList) = 0;
		virtual void sort() = 0;
		virtual void push_back(const T &newVal)const;
		virtual void push_front(const T &newVal)const;
		virtual const T &front()const;
		virtual const T &back()const;
		virtual void pop_front();
		virtual void pop_back();
		virtual const unsigned long int size()const;
		virtual const unsigned long int max()const;
		virtual bool full()const;
		virtual bool empty()const;
	protected:
		virtual void add(node<T> *addPoint, const T &newVal, bool first);
		virtual void remove(node<T> *deletePoint, bool first);
		virtual unsigned long int _size, _max;
		virtual node<T> *firstP;
		virtual node<T> *lastP;
	private:
	};
}
