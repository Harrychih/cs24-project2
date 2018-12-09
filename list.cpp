#include "list.h"			

list::list()
{
	next_field = NULL;
	prev_field = NULL;
}

void head_insert(list*& head, const string file_name)
{
	list* temp_ptr;
	temp_ptr = new list;
	temp_ptr->set_data_fname(file_name);
	temp_ptr->set_data_count(temp_ptr->data_count() + 1);
	if (head == NULL)
	{
		temp_ptr->set_prev(NULL);
		temp_ptr->set_next(NULL);
	}
	else
	{
		temp_ptr->set_prev(NULL);
		temp_ptr->set_next(head);
		head->set_prev(temp_ptr);
	}
	head = temp_ptr;
}

void list_insert(list*& head, list*& previous, const string file_name) 
{
	list* temp_ptr1;
	temp_ptr1 = new list;
	temp_ptr1 = head;
	int temp = 0;
	while (temp_ptr1 != NULL)
	{
		if (temp_ptr1->data_filename() == "")
		{
			temp_ptr1->set_data_fname(file_name);
			temp_ptr1->set_data_count((temp_ptr1->data_count()) + 1);
		}
		else if (temp_ptr1->data_filename() == file_name)
		{
			temp_ptr1->set_data_count((temp_ptr1->data_count()) + 1);
			return;
		}

		else
			temp_ptr1 = temp_ptr1->next();
			
	}
	//empty case
	if (head == NULL)
		head = new list;
	if(previous == NULL)
	{
		head_insert(head, file_name);
		return;
	}
	list* temp_ptr;
	temp_ptr = new list;
	temp_ptr->set_data_fname(file_name);
	temp_ptr->set_data_count(temp_ptr->data_count() + 1);
	temp_ptr->set_prev(previous);
	temp_ptr->set_next(previous->next());

	previous->set_next(temp_ptr);
	(temp_ptr->next())->set_prev(temp_ptr);
    	
}

void erase_one(list*& head, list*& dele)
{
	//if the list deleted is the first one
	if (dele->prev() == NULL){
		head = dele->next();
		delete dele;
		return;
	}
	(dele->prev())->set_next(dele->next());
	(dele->next())->set_prev(dele->prev());
	delete dele;

}

size_t length (list* head) 
{
	int counter = 0; 
	list* temp_ptr;
	temp_ptr = new list;
	temp_ptr = head;
	while (temp_ptr != NULL)
	{
		counter++;
		temp_ptr = temp_ptr->next();
	}
	return counter;
}	

void print (list* src) 
{
	cout << "File: " << src->data_filename() << "; Count: " << src->data_count() << endl;
	return;
}

void list_print (list* head)
{
	if (head == NULL)
		return;
	else
	{
		list* head_ptr;
		head_ptr = new list;
		head_ptr = head->next();
		while (head_ptr != NULL)
		{
			print(head_ptr);
			head_ptr = head_ptr->next();
		}
	}
	return;
}

/*
list* prevListSearch(list* head, string file_name)
{
	list* temp_ptr;
	temp_ptr = new list;
	temp_ptr = head;
	if (temp_ptr == NULL)
		return NULL;
	while(temp_ptr != NULL)
	{
		if (temp_ptr->data_filename() == file_name)
			return temp_ptr->prev();
		else
			temp_ptr = temp_ptr->next();
	}
	return temp_ptr->prev();

}
*/

void countPlus(list*& head, string file_name)
{

	list* temp_list;
	temp_list = head;
	while (temp_list != NULL)
	{
		if (temp_list->data_filename()==file_name)
		{
			temp_list->set_data_count(temp_list->data_count() + 1);
			return;
		}
		else
			temp_list = temp_list->next();
	}

	list* new_file;
	new_file = new list;
	new_file->set_data_fname(file_name);
	new_file->set_data_count(1);

	if (head == NULL)
	{
		new_file->set_next(NULL);
		head = new_file;
		return;
	}
	else if (head->next()==NULL)
	{
		head->set_next(new_file);
		new_file->set_prev(head);
		new_file->set_next(NULL);
		return;
	}
	else
	{
		new_file->set_next(head->next());
		(head->next())->set_prev(new_file);
		head->set_next(new_file);
		new_file->set_prev(head);
		return;
	}



}


