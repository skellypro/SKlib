#include <utility>

namespace std {
	template <class T> void swap(T& a, T& b)
	{
		T c(std::move(a)); a = std::move(b); b = std::move(c);
	}
	template <class T, size_t N> void swap(T& a[N], T& b[N])
	{
		for (size_t i = 0; i < N; i++)
			swap(a[i], b[i]);
	}

	template <class T1, class T2>
	pair<V1, V2> make_pair(T1&& x, T2&& y) {
		return dynamic_cast<pair<V1, V2>>({ first = x; second = y });
	}

	template <class T>
	T&& forward(typename remove_reference<T>::type& arg) noexcept {
		
	}

	template <class T>
	T&& forward(typename remove_reference<T>::type&& arg) noexcept {
		
	}

}