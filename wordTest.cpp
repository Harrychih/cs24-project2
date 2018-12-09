// wordTest.cpp
// Test for the functionality of word

#include <iostream>
#include <cstdlib>
#include "word.h"

int main () {

	word* head = NULL;
	add_new_word(head,"apple","test1.txt");
	cout << "1" << endl;
	add_new_word(head,"apple","test2.txt");
	cout << "2" << endl;
	add_new_word(head,"apple","test2.txt");
	cout << "3" << endl;
	add_new_word(head,"apple","test1.txt");
	cout << "4" << endl;
	add_new_word(head,"apple","test1.txt");
	cout << "5" << endl;
	add_new_word(head,"app","test1.txt");
	cout << "6" << endl;
	add_new_word(head,"app1","test1.txt");
	cout << "7" << endl;
	add_new_word(head,"app1","test2.txt");
	cout << "8" << endl;
	add_new_word(head,"banana","test1.txt");
	cout << "9" << endl;
	add_new_word(head,"apply","test2.txt");
	cout << "10" << endl;
	add_new_word(head,"orange","test1.txt");
	cout << "11" << endl;
	add_new_word(head,"apple","test1.txt");
	cout << "12" << endl;
	add_new_word(head,"apple","test2.txt");
	cout << "13" << endl;
	add_new_word(head,"apple","test2.txt");
	cout << "14" << endl;
	add_new_word(head,"apple","test1.txt");
	cout << "15" << endl;
	add_new_word(head,"apple","test1.txt");
	cout << "16" << endl;
	add_new_word(head,"app","test1.txt");

	add_new_word(head,"where","test1.txt");
	add_new_word(head,"where","test2.txt");
	add_new_word(head,"about","test1.txt");
	add_new_word(head,"orange","test2.txt");
	add_new_word(head,"orange","test1.txt");
	add_new_word(head,"File","test1.txt");
	add_new_word(head,"you","test2.txt");
	add_new_word(head,"you","test2.txt");
	add_new_word(head,"get","test1.txt");
	add_new_word(head,"test","test1.txt");

	word* temp;
	temp = head;
	while (temp)
	{
		cout << "word: " << temp->get_name()<<endl;
		temp->print_word();
		cout << "end of the word" << endl;
		temp = temp->w_next();
	}

	return 0;
	
}