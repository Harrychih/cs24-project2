// wordTest.cpp
// Test for the functionality of word

#include <iostream>
#include <cstdlib>
#include "word.h"

int main () {

	word* head = NULL;
	add_new_word(head,"apple","test1.txt");
	add_new_word(head,"apple","test2.txt");
	add_new_word(head,"apple","test2.txt");
	add_new_word(head,"apple","test1.txt");
	add_new_word(head,"apple","test1.txt");

	add_new_word(head,"app","test1.txt");

	add_new_word(head,"app1","test1.txt");
	add_new_word(head,"app1","test2.txt");
	add_new_word(head,"banana","test1.txt");
	add_new_word(head,"apply","test2.txt");
	add_new_word(head,"orange","test1.txt");
	add_new_word(head,"apple","test1.txt");
	add_new_word(head,"apple","test2.txt");
	add_new_word(head,"apple","test2.txt");
	add_new_word(head,"apple","test1.txt");
	add_new_word(head,"apple","test1.txt");

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
	list* temp_l;
	list* l;
	while (temp)
	{
		l=temp->w_head();
		temp_l=l;
		cout << "word" << temp->get_name()<<endl;
		while(temp_l)
		{
			cout << "file: " <<temp_l->data_filename() << "; count:" << temp_l->data_count() <<endl;
			temp_l = temp_l->next();
		}
		cout << "end of the word" << endl;
		temp = temp->w_next();
	}

	return 0;
	
}