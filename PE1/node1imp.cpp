// Implementation file for Singly linked list functions
// Author: Joshua Zimmerman 
// Date: 03/03/17

#include "node1.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
#include <iostream> // For file I/O
using namespace std;

namespace main_savitch_5
{


	size_t list_length(const node* head_ptr)
		// Library facilities used: cstdlib
	{
		const node *cursor;
		size_t answer;

		answer = 0;
		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())   //this is the way to traverse a linked list
			++answer;

		return answer;
	}

	void list_head_insert(node*& head_ptr, const node::value_type& entry) // function to insert a node to the head of the list
	{
		head_ptr = new node(entry, head_ptr);
	}

	void list_tail_insert(node* &tail_ptr, const node::value_type& entry) // function to insert a node to the tail of the list

	{
		node *insert_ptr;

		insert_ptr = new node(entry, tail_ptr->link());
		tail_ptr->set_link(insert_ptr);
		tail_ptr = insert_ptr;

	}

	void list_insert(node* previous_ptr, const node::value_type& entry)
	{
		node *insert_ptr;

		insert_ptr = new node(entry, previous_ptr->link());
		previous_ptr->set_link(insert_ptr);
	}

	node* list_search(node* head_ptr, const node::value_type& target)
		// Library facilities used: cstdlib
	{
		node *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	const node* list_search(const node* head_ptr, const node::value_type& target)
		// Library facilities used: cstdlib
	{
		const node *cursor;

		for (cursor = head_ptr; cursor != NULL; cursor = cursor->link())
			if (target == cursor->data())
				return cursor;
		return NULL;
	}

	node* list_locate(node* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		node *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	const node* list_locate(const node* head_ptr, size_t position)
		// Library facilities used: cassert, cstdlib
	{
		const node *cursor;
		size_t i;

		assert(0 < position);
		cursor = head_ptr;
		for (i = 1; (i < position) && (cursor != NULL); i++)
			cursor = cursor->link();
		return cursor;
	}

	void list_head_remove(node*& head_ptr) // function to remove a node from the head of the list
	{
		node *remove_ptr;

		remove_ptr = head_ptr;
		head_ptr = head_ptr->link();
		delete remove_ptr;
	}

	void list_remove(node* previous_ptr)
	{
		node *remove_ptr;

		remove_ptr = previous_ptr->link();
		previous_ptr->set_link(remove_ptr->link());
		delete remove_ptr;
	}

	void list_tail_remove(node* &tail_ptr, node* &head_ptr) // function to remove a node from the tail of the list
	{
		if (head_ptr != tail_ptr)
		{
			node * cursor;
			node * previou = NULL;

			for (cursor = head_ptr; cursor != tail_ptr; cursor = cursor->link())
			{
				previou = cursor;

			}
			tail_ptr = previou;
			previou->set_link(NULL);
		}
		else
		{
			head_ptr = NULL;
			tail_ptr = NULL;
		}
		
	}

	void list_clear(node*& head_ptr)
		// Library facilities used: cstdlib
	{
		while (head_ptr != NULL)
			list_head_remove(head_ptr);
	}

	void list_copy(const node* source_ptr, node*& head_ptr, node*& tail_ptr)
		// Library facilities used: cstdlib
	{
		head_ptr = NULL;
		tail_ptr = NULL;

		// Handle the case of the empty list.
		if (source_ptr == NULL)
			return;

		// Make the head node for the newly created list, and put data in it.
		list_head_insert(head_ptr, source_ptr->data());
		tail_ptr = head_ptr;

		// Copy the rest of the nodes one at a time, adding at the tail of new list.
		source_ptr = source_ptr->link();
		while (source_ptr != NULL)
		{
			list_insert(tail_ptr, source_ptr->data());
			tail_ptr = tail_ptr->link();
			source_ptr = source_ptr->link();
		}
	}

	
	void list_print(node * headPtr) // function to print the current nodes in the list

	{

		if (headPtr == NULL)
		{
			cout << "The linked list is empty." << endl;
		}
			else
			{
				node * cursor;
				cout << "the printed order of a current linked list is: " << endl;
				for (cursor = headPtr; cursor != NULL; cursor = cursor->link())
				cout << cursor->data() << " " << endl;
			}

	}

	void list_showStatistics(node *headPtr)  // function to print the largest, smallest, average and total sum of all nodes in the list

	{

		int count = 0; // variable to count number of elements in list
		double sum = 0.0, average; // variables to store the average and sum of the node list
		node *cursor;
		int smallest = headPtr->data();
		int largest = headPtr->data();

		for(cursor = headPtr; cursor != NULL; cursor = cursor->link())
		{
			count++;
			if(smallest > cursor->data())
				smallest = cursor->data();

			if(largest < cursor->data())
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