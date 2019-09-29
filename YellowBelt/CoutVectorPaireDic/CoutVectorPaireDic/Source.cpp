#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>

template <typename Collection>
std::string Join(const Collection& c, char d) {
	std::stringstream ss;
	bool isFirst = true;

	for (const auto& i : c) {
		if (!isFirst) ss << d;
		isFirst = false;
		ss << i;
	}

	return ss.str();
}

template <typename First, typename Second>
std::ostream& operator<< (std::ostream& out, const std::pair<First, Second>& p) {
	return out << '(' <<p.first << ',' << p.second << ')';
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& vi) {
	return out << '[' << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
std::ostream& operator<< (std::ostream& out, const std::map<Key, Value>& m) {
	return out << '{' << Join(m, ',') << '}';
}

void main() {
	std::vector<std::vector<int>> v = { {1,2}, {3,4} };
	std::cout << v << std::endl;

	std::map<int, double> m = { { 1, 2.5 }, { 3, 4.6 }};
	std::cout << m << std::endl;

	system("pause");
}