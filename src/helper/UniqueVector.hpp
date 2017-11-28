#ifndef UNIQUEVECTOR_H_
#define UNIQUEVECTOR_H_

#include <vector>
#include <algorithm>

// private inheritance, nobody else knows about the inheritance, so nobody is upcasting my
// container to a std::vector
template<class T> class UniqueVector: private std::vector<T> {
private:
	// in case I changed to boost or something later, I don't have to update everything below
	typedef std::vector<T> base_vector;

public:
	typedef typename base_vector::size_type size_type;
	typedef typename base_vector::iterator iterator;
	typedef typename base_vector::const_iterator const_iterator;

	using base_vector::operator[];

	using base_vector::begin;
	using base_vector::clear;
	using base_vector::end;
	using base_vector::erase;
	using base_vector::push_back;
	using base_vector::reserve;
	using base_vector::resize;
	using base_vector::size;

	// custom extension
	bool push_back_unique(T t) {
		if (find(begin(), end(), t) != end())
			return (false);
		push_back(t);
		return (true);
	}
};

#endif
