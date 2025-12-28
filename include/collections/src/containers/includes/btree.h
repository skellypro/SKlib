/*
 * btree.h
 *
 *  Created on: Dec 24, 2015
 *      Author: Sean
 */
#pragma once

#include"abstracts/basic_tree.cpp"
namespace std {
	template<class T, class K = unsigned long int>
	class btree : public basic_tree<T,K> {
	public:
		btree();
		btree(const T &value, const K &newKey);
		btree(const btree &otherTree);
		~btree();
		basic_tree<T,K> &operator=(const basic_tree<T,K> &otherTree);
		const T &search(const K &searchKey);
	private:
		branch<T,K> &climb(const branch *&nextBranch, const K &_key);
	};
}
