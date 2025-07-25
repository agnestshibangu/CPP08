#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span {
	public:
		Span(unsigned int size);
		Span(const Span &src);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		void	addRange(std::vector<int>::iterator beg, std::vector<int>::iterator end);
		int		shortestSpan() const;
		int		longestSpan() const;
		void	showNumbers() const;

	private:
		std::vector<int>	_vec;
		Span();

	class FullException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "Span is full";
			}
	};
	class NoSpanException : public std::exception {
		public:
			virtual const char *what() const throw() {
				return "No span to find";
			}
	};
};

#endif