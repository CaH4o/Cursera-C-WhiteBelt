#include <iostream>

struct Day {
	int _value;
	explicit Day(int new_value) {
		_value = new_value;
	}
};

struct Month {
	int _value;
	explicit Month(int new_value) {
		_value = new_value;
	}
};

struct Year {
	int _value;
	explicit Year(int new_value) {
		_value = new_value;
	}
};

struct Date {
	int _day;
	int _month;
	int _year;
	Date(Day new_day, Month new_month, Year new_year) {
		_day = new_day._value;
		_month = new_month._value;
		_year = new_year._value;
	}
};

void Print(const Date& d) {
	std::cout << d._day << "/" << d._month << "/" << d._year << "\n";
}

void main() {
	Date holyday = { Day{8}, Month{3}, Year{5} };
	Print(holyday);

	system("pause");
}