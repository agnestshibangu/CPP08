
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

void	test_deque() {
	std::cout << "Deque container" << std::endl;
	std::deque<int> dequ;
	for(int i = 1; i <= 10; i++) {
		dequ.push_back(i);
	}
	
	int values[] = {2, 5, 42, 6};
	for (int i = 0; i < 4; ++i) {
		try {
			std::deque<int>::iterator it = easyfind(dequ, values[i]);
			std::cout << "Found: " << *it << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << ": " << values[i] << std::endl;
		}
	}
	std::cout << std::endl;
}

void	test_list() {
	std::cout << "List container" << std::endl;
	std::list<int> list;
	for(int i = 1; i <= 20; i++) {
		list.push_back(i);
	}
	
	int values[] = {2, 10, 12, 60};
	for (int i = 0; i < 4; ++i) {
		try {
			std::list<int>::iterator it = easyfind(list, values[i]);
			std::cout << "Found: " << *it << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << ": " << values[i] << std::endl;
		}
	}
	std::cout << std::endl;
}

void	test_vector() {
	std::cout << "Vector container" << std::endl;
	std::vector<int> vect;
	for(int i = 1; i <= 20; i++) {
		vect.push_back(i);
	}
	
	int values[] = {22, 15, 53, 50};
	for (int i = 0; i < 4; ++i) {
		try {
			std::vector<int>::iterator it = easyfind(vect, values[i]);
			std::cout << "Found: " << *it << std::endl;
		} catch (std::exception &e) {
			std::cout << e.what() << ": " << values[i] << std::endl;
		}
	}
	std::cout << std::endl;
}

int main() {
	test_deque();
	test_list();
	test_vector();

	return 0;
}

