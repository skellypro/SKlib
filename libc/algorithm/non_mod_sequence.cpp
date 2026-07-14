/*
 * non_mod_sequence.cpp
 *
 *  Created on: Jul 12, 2026
 *      Author: sean
 *
 * Description:	Standard Template library: Algorithms pertainint to
 *				Non-modifying sequence operations.
 */

#include <algorthm>

#include <iterator>

#include <utility>

namespace std {
    template<class InputIterator, class UnaryPredicate>
    bool all_of(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last) {
            if (!pred(*first))
                return false;
            first++;
        }
        return true;
    }

    template<class InputIterator, class UnaryPredicate>
    bool any_of(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last) {
            if (pred(*first))
                return true;
            first++;
        }
        return false;
    }

    template<class InputIterator, class UnaryPredicate>
    bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred)
    {
        while (first != last) {
            if (pred(*first))
                return false;
            first++;
        }
        return true;
    }

    template<class InputIterator, class Function>
    Function for_each(InputIterator first, InputIterator last, Function fn)
    {
        while (first != last) {
            fn(*first);
            first++;
        }
        return move(fn);
    }
}