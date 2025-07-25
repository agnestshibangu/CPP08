
#include <iostream>
#include "Span.hpp"

void	test_subject() {
	std::cout << "Test subject" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	test_invalid_addNumber() {
	std::cout << "Test invalid addNumber" << std::endl;
	try {
		Span sp = Span(1);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_invalid_shortestSpan() {
	std::cout << "Test invalid shortestspan with 0 and 1 element" << std::endl;
	try {
		Span sp = Span(1);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp = Span(1);
		sp.addNumber(1);
		std::cout << sp.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_invalid_longestSpan() {
	std::cout << "Test invalid longestSpan with 0 and 1 element" << std::endl;
	try {
		Span sp = Span(1);
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span sp = Span(1);
		sp.addNumber(1);
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_big_number() {
	std::cout << "Test big number" << std::endl;
	try {
		Span sp = Span(5000);
		for (int i = 0; i < 5000; i++) {
			sp.addNumber(i);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_invalid_range() {
	std::cout << "Test invalid range capacity too small & valid case of 5" << std::endl;
	try {
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		Span sp = Span(1);
		sp.addRange(vec.begin(), vec.end());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::vector<int> vec;
		vec.push_back(1);
		Span sp = Span(1);
		sp.addRange(vec.begin(), vec.end());
		sp.showNumbers();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_valid_range() {
	std::cout << "Test valid range" << std::endl;
	try {
		std::vector<int> vec;
		vec.reserve(100);
		for (int i = 0; i < 100; i++) {
			vec.push_back(i);
		}
		Span sp = Span(100);
		sp.addRange(vec.begin(), vec.end());
		sp.showNumbers();
		std::cout <<  "shortest span" << sp.shortestSpan() << std::endl;
		std::cout << "longest span" << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_copy_assignation() {
	std::cout << "Test copy assignation, reserve bigger than assignation" << std::endl;
	Span sp = Span(5);
	sp.addNumber(42);
	sp.addNumber(24);
	sp.addNumber(99);
	sp.showNumbers();
	Span sp2 = sp;
	sp2.showNumbers();
	std::cout << std::endl;
}

void	test_copy_constructor() {
	std::cout << "Test copy constructor" << std::endl;
	std::cout << "---original---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(42);
	sp.addNumber(24);
	sp.addNumber(99);
	sp.showNumbers();
	std::cout << "---copy---" << std::endl;
	Span sp2(sp);
	sp2.showNumbers();
	std::cout << std::endl;
}

int main() {
	std::cout << "----------" << std::endl;
	test_subject();
	std::cout << "----------" << std::endl;
	test_invalid_addNumber();
	std::cout << "----------" << std::endl;
	test_invalid_shortestSpan();
	std::cout << "----------" << std::endl;
	test_invalid_longestSpan();
	std::cout << "----------" << std::endl;
	test_big_number();
	std::cout << "----------" << std::endl;
	test_invalid_range();
	std::cout << "----------" << std::endl;
	test_valid_range();
	std::cout << "----------" << std::endl;
	test_copy_assignation();
	std::cout << "----------" << std::endl;
	test_copy_constructor();

	return 0;
}
