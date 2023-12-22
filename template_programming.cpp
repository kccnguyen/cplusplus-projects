#include <iostream>
#include <string>
#include <vector>
#include <complex>

namespace HL {
	//	void Swap(int& a, int& b) {
	//		int c = a;
	//		a = b;
	//		b = c;
	//	}
	//
	//	void swap(std::string& s1, std::string& s2) {
	//		std::string temp = s1;
	//		s1 = s2;
	//		s2 = temp;
	//	}
	//}

	// template <typename T>
	template <typename T>
	void swap(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	}

	template <class T>
	T summation(std::vector<T>& v) {
		T result{}; // use initializer {} to set default value for result

		for (T i : v)
			result += i;

		return result;

	}
}

	template <typename T>
	class MyClass {
		T number;
	public:
		MyClass(T number);

		void print() const;
	};

	template <class T>
	MyClass<T>::MyClass(T number) : number{ number } {}

	template <class T>
	void MyClass<T>::print() const {
		std::cout << number << std::endl;
	}


	int main()
	{
		int a = 10, b = 20;

		//HL::swap<int>(a, b);
		//std::cout << a << " " << b << std::endl;

		std::string s1 = "hello", s2 = "world";
		//HL::swap<std::string>(s1, s2);
		//std::cout << s1 << " " << s2 << std::endl;


		std::vector<int> vi{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		std::vector<std::string> vs{ "a", "b", "c", "d", "e", "f", "g" };

		using HL::swap;

		swap(s1, s2);

		std::cout << HL::summation(vi) << std::endl;
		std::cout << HL::summation(vs) << std::endl;

		MyClass<int> mc(10);

		MyClass<std::string> mc1("hello");

		mc.print();
		mc1.print();
}

