#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::string ToLower(string s) {
	for (auto& c : s) {
		c = tolower(c);
	}
	return s;
}

int main() {
	int n;
	cin >> n;
	vector<std::string> v(n);
	for (auto& el : v) {
		std::cin >> el;
	}
	
	sort(begin(v), end(v), [](std::string x, std::string y) {return ToLower(x) < ToLower(y); });
	
	for (const auto& el : v) {
		cout << el << ' ';
	}
	
	return 0;
}

/*

// Ќаиболее нетривиальна€ часть решени€ этой задачи Ч реализовать функцию, сравнивающую две строки без учЄта регистра.

// Ёто можно сделать, например, с помощью функции lexicographical_compare, сравнивающей два диапазона элементов 
// (в нашем случае Ч два набора символов) с помощью данного компаратора. ¬ компараторе дл€ функции lexicographical_compare 
// мы используем функцию tolower, возвращающую символ, приведЄнный к нижнему регистру.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	// считываем вектор строк
	int n;
	cin >> n;
	vector<string> v(n);
	for (string& s : v) {
		cin >> s;
	}

	// сортируем
	sort(begin(v), end(v),
		// компаратор дл€ сортировки Ч л€мбда-функци€, сравнивающа€ строки без учЄта регистра
		[](const string& l, const string& r) {
		// сравниваем лексикографически...
		return lexicographical_compare(
			// ... все символы строки l ...
			begin(l), end(l),
			// ... со всеми символами строки r ...
			begin(r), end(r),
			// ..., использу€ в качестве компаратора сравнение отдельных символов без учЄта регистра
			[](char cl, char cr) { return tolower(cl) < tolower(cr); }
		);
	}
	);

	// выводим отсортированный вектор
	for (const string& s : v) {
		cout << s << ' ';
	}

	return 0;
}

*/