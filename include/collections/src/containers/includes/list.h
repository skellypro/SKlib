/*
 * list.h
 *
 *  Created on: Feb 9, 2015
 *      Author: Sean
 *      TODO: overload function resize() to take additional arguments
 */
#pragma once

#include"abstracts/basic_list.cpp"
namespace std {
	/*
	 * Type: list<T>
	 * Members:
	 *	firstP:Pointer to node<T>:points to address of first node
	 *	lastP:Pointer to node<T>:points to address of last node
	 *	_size:Unsigned Integer:current size of the list
	 * 	max:Unsigned Integer:optional maximum size
	 * Domain:
	 * 	push_front(val:Constant T Ref):Constant T Ref:pushes new value to front of list
	 * 	push_back(val:Constant T Ref):Constant T Ref:pushes new value to back of list
	 * 	pop_front():T:removes node in front of list, sends old value to user
	 * 	pop_back():T:removes node in back of list, sends old value to user
	 */
	template<class T>
	class list : public basic_list<T> {
	public:
		chain();
		chain(unsigned long int newSize);
		chain(unsigned long int newSize, unsigned long int newMax);
		chain(unsigned long int newSize, ...);
		chain(const basic_list<T> &otherChain);
		virtual ~chain();
		void clear();
		void copy(const basic_list<T> &otherChain);
		void sort();
		void resize(unsigned long int newSize);
		void resize(unsigned long int args, ...);
		void push_front(unsigned long int args, ...);
		void push_back(unsigned long int args, ...);
		basic_list<T> &operator=(const basic_list<T> &otherChain);
		T &operator[](unsigned long int n);
	private:
		// TODO: implement this function
		void handle_args(unsigned long int argc,
			va_list &argv,
			bool end = 0x00);
		T &traverse(unsigned long int n, bool lower);
	};
}
