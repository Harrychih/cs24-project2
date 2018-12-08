#ifndef WORD_H	
#define WORD_H
#include <iostream>
#include <cstdlib>	
#include "itemtype.h"
#include "list.h"
using namespace std;

class word
{
public:
	//comstructor
	word();
	//modifiers
	void w_set_next(word* n) {next_field = n;};
	void w_set_prev(word* p) {prev_field = p;};
	void set_name(string wname) {name = wname;};
	void set_head(list* l) {head = l;};
	// void set_data(string fname);
	void update_count(string file_name);
	//observers
	void print_word() const;
	string get_name() {return name;};
	list* w_head() const {return head;};
	int w_length(word* word_head);

	// forward nexts
    word* w_next() {return next_field;};
    const word* w_next() const {return next_field;};
    // backward nexts
    word* w_prev() {return prev_field;};
    const word* w_prev() const {return prev_field;};


private:
	list* head;
	string name;
	word* prev_field;
	word* next_field;
};

// helper function
void add_new_word(word*& word_head, string n_name, string f_name);
#endif