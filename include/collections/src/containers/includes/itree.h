/*
 * itree.h
 *
 *  Created on: Dec 25, 2015
 *      Author: Sean
 *      Description:	Binary search tree with an iterated search algorithm
 */
#pragma once

#include"abstracts/basic_tree.cpp"
namespace std {
	template<class T, class K = unsigned long int>
	class itree : public basic_tree<T,K> {
	public:
		itree();
		itree(const T &value, const K &newKey);
		itree(const itree &otherTree);
		~itree();
		basic_tree<T,K> &operator=(const basic_tree<T,K> &otherTree);
		const T &search(const K &searchKey);
	private:
		branch<T,K> &climb(const K &_key);
	};
}