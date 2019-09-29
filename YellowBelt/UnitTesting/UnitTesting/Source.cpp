#include <iostream>
#include <string>
#include <sstream> 
#include <exception> 

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const std::string& testName) {
		try {
			func();
			std::cerr << testName << " OK\n";
		} catch (const std::exception& e) {
			++failCount;
			std::cerr << testName << " fail: " << e.what() << std::endl;
		}
	
	}

	~TestRunner()
	{
		if (failCount > 0) {
			std::cerr << failCount << " tests failed. Terminate.";
			system("pause");
			exit(1);
		}
	}
private:
	int failCount = 0;
};

template <class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint) {
	if (t != u) {
		std::ostringstream os;
		os << "Assertion failed : " << t << " != " << u << " Hint : " << hint;
		throw std::runtime_error(os.str());
	}
}

int Foo(int x, int y) {
	if (!y) return x;
	return x / y;
}

void TestFoo() {
	AssertEqual(Foo(1, 2), 0, "Line 47");
	AssertEqual(Foo(2, 1), 2, "Line 48");
	AssertEqual(Foo(10, 2), 5, "Line 49");
	AssertEqual(Foo(10, 0), 10, "Line 50");
}

void TestAll() {
	TestRunner tr;
	tr.RunTest(TestFoo, "TestFoo");
}

void main() {
	TestAll();

	int x = 1;
	int y = 2;

	std::cout << "x:" << x << " and y:" << y  << " = " << Foo(x, y) << std::endl;

	system("pause");
}