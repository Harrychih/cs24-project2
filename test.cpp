// Test.cpp
// Test specific problem
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
	string string_a = "apple";
	string string_b = "apply";
	string string_c = "app";

	cout << "apple to apply: " << string_a.compare(string_b) << endl;
	cout << "apple and app: " << string_a.compare(string_c) << endl;
	cout << "apply and app: " << string_b.compare(string_c) << endl;

	return 0;
}