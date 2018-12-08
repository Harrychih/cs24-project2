#include <string>
#include "word.h"



using namespace std;

word::word() 
{
	string name = "";
	head = new list;
	prev_field = NULL;
	next_field = NULL;
}

/*
void word::set_data(string fname) 
{
	list* temp;
	temp = new list;
	if (head == NULL) 
	{
		temp->set_data_fname(fname);
		temp->set_data_count(1);
		temp->set_next(NULL);
		temp->set_prev(NULL);
		head = temp;
		return;
	}
	list* temp_prev;
	temp_prev = new list;
	temp_prev = prevListSearch(head, fname);
	list_insert(head, temp_prev, fname);
	return;
}
*/

void word::update_count(string file_name)
{
	countPlus(head, file_name);
	return;
}

void word::print_word() const
{
	list* word_print;
	word_print = head;
	while (word_print != NULL)
	{
		list_print(word_print);
		word_print = word_print->next();
	}
	return;
}

int w_length(word* word_head)
{
	int counter = 0;
	word* temp_word;
	temp_word = word_head;
	while (temp_word != NULL)
	{
		counter++;
		temp_word = temp_word->w_next();
	}
	return counter;
}

void add_new_word(word*& word_head, string n_name, string f_name)
{
	word* temp_word;
	temp_word = word_head;
	while (temp_word != NULL)
	{
		string temp_string = temp_word->get_name();
		if (temp_string == n_name)
		{
			temp_word->update_count(f_name);
			return;
		}
		else if (temp_string.compare(n_name) > 0)
		{

			word* new_word;
			new_word = new word;
			new_word->set_name(n_name);
			temp_word->w_set_prev(new_word);
			new_word->w_set_next(temp_word);
			new_word->w_set_prev(temp_word->w_prev());
			if(temp_word->w_prev() != NULL)
				(temp_word->w_next())->w_set_prev(new_word);
			else
				word_head = new word;
			


			new_word->update_count(f_name);
			return;
		}
		else
			temp_word = temp_word->w_next();

	}
	int len = w_length(word_head);
	word* temp_ptr;
	temp_ptr = word_head;
	for (int i = 0; i < (len-1); i++)
	{
		temp_ptr = temp_ptr->w_next();
	}
	word* tail_new_word;
	tail_new_word = new word;
	tail_new_word->set_name(n_name);
	temp_ptr->w_set_next(tail_new_word);
	tail_new_word->w_set_prev(temp_ptr);
	tail_new_word->w_set_next(NULL);
	
	tail_new_word->update_count(f_name);
	return;
}