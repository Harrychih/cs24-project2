// listTest.cpp
// Test the fucntionality of the list
#include <iostream>
#include "list.h"

using namespace std;


int main(){

	list* temp_ptr1;
	temp_ptr1 = new list;
	head_insert(temp_ptr1, "file1");
	list_insert(temp_ptr1, temp_ptr1, "file2");
	cout << "size = " << length(temp_ptr1) << endl;
	cout << "----------------" << endl;
	list_print(temp_ptr1);
	cout << "---------------" << endl;
	countPlus(temp_ptr1, "file1");
	cout << "-----------------" << endl;
	list_print(temp_ptr1);
	cout << "-----------------" << endl;
	list* temp_ptr2;
	temp_ptr2 = new list;
	temp_ptr2 = prevListSearch(temp_ptr1, "file2");
	list_print(temp_ptr2);
	cout << "-----------------" << endl;
	countPlus(temp_ptr1, "file2");
	list_print(temp_ptr1);
	cout << "-----------------" << endl;
	list_print(temp_ptr2);


	return 0;

}