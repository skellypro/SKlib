/*
 * Name:	Sean
 * TODO: overload function resize() to take additional arguments
 */
#pragma once

#include"abstracts/basic_list.cpp"
namespace std{
	template<class T>
	class rlist: private basic_list<T> {
	public:
		rlist();
		rlist(unsigned long int new_size);
		rlist(unsigned long int new_size, ...);
		rlist(const basic_list<T> &otherList);
		virtual ~rchain();
		void copy(const basic_list<T> &otherList);
		void sort();
		void clear();
		void resize(unsigned long int newSize);
		void resize(unsigned long int args, ...);
		void push_front(unsigned long int args, ...);
		void push_back(unsigned long int args, ...);
		basic_list<T> &operator=(const basic_list<T> &otherList);
		T &operator[](unsigned long int n);
		~rlist();
	private:
		bool grow(unsigned long int size,
				const basic_list<T> &otherList = NULL);
		T &left(node<T> *nextNode, unsigned long int i,
				unsigned long int index);
		T &right(node<T> *nextNode, unsigned long int i,
				unsigned long int index);
		bool varAdd(va_list &newList, unsigned long int new_size,
				unsigned long int index = 0);
		bool varAddFront(va_list &newList, unsigned long int args,
						unsigned long int index = 0);
		bool varAddBack(va_list &newList, unsigned long int args,
					unsigned long int index = 0);
	};
}
