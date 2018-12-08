// wordTest.cpp
// Test for the functionality of word

#include <iostream>
#include <cstdlib>
#include "word.h"

int main () {
	string temp1 = "vocalbulary";
	string temp2 = "ball";
	word* test1;
	test1 = new word;
	test1->set_name(temp1);
	word* test2;
	test2 = new word;
	test2->set_name(temp2); 
	cout << "string 1 is " << test1->get_name() << endl;
	cout << "string 2 is " << test2->get_name() << endl;
	cout << "-------------------------------" << endl;
	add_new_word(test1,"vocalbulary","file1");
	test1->print_word();
	test2->print_word();
	cout << "-------------------------------" << endl;
	add_new_word(test1,"vocalbulary","file1");
	test1->print_word();
	test2->print_word();
	cout << "-------------------------------" << endl;
	add_new_word(test1,"vocalbulary","file2");
	test1->print_word();
	test2->print_word();
	cout << "-------------------------------" << endl;
	add_new_word(test2,"vocalbulary","file1");
	test1->print_word();
	test2->print_word();
	cout << "-------------------------------" << endl;
	add_new_word(test2,"vocalbulary","file1");
	test1->print_word();
	test2->print_word();
	cout << "-------------------------------" << endl;

	return 0;
	
}