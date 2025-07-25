#include "Span.hpp"

// reserve Prévois de la place pour size éléments, mais ne considère pas encore que le vecteur contient ces éléments
Span::Span(unsigned int size) {
	this->_vec.reserve(size);
}

Span::Span(const Span &src) {
	*this = src;
}

Span::~Span() {}

Span &Span::operator=(const Span &src) {
	this->_vec.reserve(src._vec.capacity());
	this->_vec = src._vec;
	return *this;
}

void Span::addNumber(int number) {
	if (this->_vec.size() == this->_vec.capacity())
		throw FullException();
	this->_vec.push_back(number);
}

void Span::addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end) {

	if (static_cast<unsigned long>(std::distance(beg, end)) > _vec.capacity() - _vec.size())
		throw FullException();
	this->_vec.insert(this->_vec.end(), beg, end);
}

int Span::shortestSpan() const {
	if (this->_vec.size() <= 1)
		throw NoSpanException();

	std::vector<int> sorted(this->_vec);
	std::sort(sorted.begin(), sorted.end());

	int min = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int diff = sorted[i] - sorted[i - 1];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() const {
	if (this->_vec.size() <= 1)
		throw NoSpanException();
	std::vector<int> temp(this->_vec);
	std::sort(temp.begin(), temp.end());
	return temp[temp.size() - 1] - temp[0];
}

void Span::showNumbers() const {
	size_t vector_size = this->_vec.size();
	for (size_t i = 0; i < vector_size; i++) {
		std::cout << "vec[" << i << "] = " << this->_vec[i] << std::endl;
	}
	std::cout << "capacity = " << this->_vec.capacity() << std::endl;
	std::cout << "size = " << this->_vec.size() << std::endl;
}

Span::Span() {}