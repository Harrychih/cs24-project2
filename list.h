#ifndef LIST_H
#define LIST_H
#include <cstdlib>
#include <iostream> 
#include "itemtype.h"
using namespace std;

class list
{
public:
    typedef int value_type;
    // constructor
    list();
    // modifiers
    void set_data_fname(string f_name){data_field.set_filename(f_name);}
    void set_data_count(const value_type& count){data_field.set_count(count);}
    void set_next(list* n) {next_field = n;};
    void set_prev(list* p) {prev_field = p;};

    // observers
    string data_filename() const {return data_field.filename();}
    int data_count() const {return data_field.count();}

    

    // forward nexts
    list* next() {return next_field;};
    const list* next() const {return next_field;};

    // backward nexts
    list* prev() {return prev_field;};
    const list* prev() const {return prev_field;};
    
private:
	// content 
    itemtype data_field;
    // forward pointer
    list* next_field;
    // backward pointer
    list* prev_field;
    
};

// Helper Function
void head_insert(list*& head, const string file_name);
void list_insert(list*& head, list*& previous, const string file_name);
void erase_one(list*& head, list*& dele);
size_t length (list* head);
void print (list* head);
void list_print (list* head);
// list* prevListSearch(list* head, string file_name);
void countPlus(list*& head, string file_name);

#endif
