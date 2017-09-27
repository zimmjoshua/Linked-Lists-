// Implementation file for doubly linked list functions
// Author: Joshua Zimmerman 
// Date: 03/03/17


// INVARIANT for the dnode class:
//   The data of a node is stored in data_field, and the link in link_field.

#include "dnode.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream> // For file I/O
using namespace std;

namespace main_savitch_5
{

	void d_list_head_insert(dnode*& d_head_ptr, const dnode::value_type& entry) // Function to insert a node to the head of the list
	{
		dnode * tptr;
		tptr = d_head_ptr;
		d_head_ptr = new dnode(entry, d_head_ptr);
		tptr->set_back(d_head_ptr);

	}

	
	void d_list_tail_insert(dnode* &d_tail_ptr, const dnode::value_type& entry) // Function to insert a node to the tail of the list

	{
		dnode *d_insert_ptr;

		d_insert_ptr = new dnode(entry,NULL, d_tail_ptr);
		d_tail_ptr->set_fore(d_insert_ptr);
		d_tail_ptr = d_insert_ptr;
		

	}

	void d_list_head_remove(dnode*& d_head_ptr, dnode*& d_tail_ptr) // Function to remove a node from the head of the list
	{
		if (d_head_ptr->fore() != NULL)
		{
			dnode *d_remove_ptr;

			d_remove_ptr = d_head_ptr;
			d_head_ptr = d_head_ptr->fore();
			d_head_ptr->set_back(NULL);
			delete d_remove_ptr;
		}
		else
		{
			d_head_ptr = NULL;
			d_tail_ptr = NULL;
		}
	}

	void d_list_tail_remove(dnode* &d_tail_ptr, dnode* &d_head_ptr) // Function to remove a node from the tail of the list
	{
		
		if (d_tail_ptr != d_head_ptr)
		{
			dnode *d_remove_ptr;

			d_remove_ptr = d_tail_ptr;
			d_tail_ptr = d_tail_ptr->back();
			d_tail_ptr->set_fore(NULL);
			delete d_remove_ptr;
		}
		else
		{
			d_head_ptr = NULL;
			d_tail_ptr = NULL;
		}
	}

	void d_list_print(dnode * d_headPtr) // Function to print the current nodes in the linked list
	{

		if (d_headPtr == NULL)
		{
			cout << "The linked list is empty." << endl;
		}
		else
		{
			dnode * cursor;
			cout << "the printed order of a current linked list is: " << endl;
			for (cursor = d_headPtr; cursor != NULL; cursor = cursor->fore())
				cout << cursor->data() << " " << endl;
		}
	}

	void list_printReverse(dnode * d_tailPtr) // Function to print the current nodes in the linked list in reverse

	{

		if (d_tailPtr == NULL)
		{
			cout << "The linked list is empty." << endl;
		}
		else
		{
			dnode * cursor;
			cout << "the reversed printed order of a current linked list is: " << endl;
			for (cursor = d_tailPtr; cursor != NULL; cursor = cursor->back())
				cout << cursor->data() << " " << endl;
		}

	}

	void d_list_showStatistics(dnode *d_headPtr) // Function to print the smallest, largest, averagem and sum of all values in the linked list

	{

		int count = 0; // variable to count number of elements in list
		double sum = 0.0, average;
		dnode *cursor;
		int smallest = d_headPtr->data();
		int largest = d_headPtr->data();

		for (cursor = d_headPtr; cursor != NULL; cursor = cursor->fore())
		{
			count++;
			if (smallest > cursor->data())
				smallest = cursor->data();

			if (largest < cursor->data())
				largest = cursor->data();

			sum = sum + cursor->data();
		}

		average = sum / count;

		cout << "Statistics:" << endl << endl;
		cout << "total sum " << sum << endl;
		cout << "smallest value " << smallest << endl;
		cout << "largest value " << largest << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average " << average << endl;

	}
}