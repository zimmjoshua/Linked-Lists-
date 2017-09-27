// Function prototypes for Singly linked list functions
// Author: Joshua Zimmerman 
// Date: 03/03/17


//   void set_back(node* new_back)
//     Postcondition: The node now contains the specified new link.
//
//   value_type data( ) const
//     Postcondition: The return value is the data from this dnode.
//
//   const node* fore( ) const <----- const version
//   node* fore( ) <----------------- non-const version
//   const node* back( ) const <----- const version
//   node* back( ) <----------------- non-const version
//   See the note (above) about the const version and non-const versions:
//     Postcondition: The return value is a link from this dnode.

#ifndef MAIN_SAVITCH_DNODE_H  
#define MAIN_SAVITCH_DNODE_H
#include <cstdlib> // Provides size_t and NULL

namespace main_savitch_5
{
	class dnode
	{
	public:
		// TYPEDEF
		typedef double value_type;

		// CONSTRUCTOR
		dnode(
			const value_type& init_data = value_type(),
			dnode* init_fore = NULL,
			dnode* init_back = NULL
		)
		{
			data_field = init_data;
			link_fore = init_fore;
			link_back = init_back;
		}

		// Member functions to set the data and link fields:
		void set_data(const value_type& new_data) { data_field = new_data; }
		void set_fore(dnode* new_fore) { link_fore = new_fore; }
		void set_back(dnode* new_back) { link_back = new_back; }

		// Const member function to retrieve the current data:
		value_type data() const { return data_field; }

		// Two slightly different member functions to retrieve each current link:
		const dnode* fore() const { return link_fore; }
		dnode* fore() { return link_fore; }
		const dnode* back() const { return link_back; }
		dnode* back() { return link_back; }
	private:
		value_type data_field;
		dnode *link_fore;
		dnode *link_back;
	};
	

	void d_list_head_insert(dnode*& d_head_ptr,    const dnode::value_type& entry); // Function to insert a node to the head of the list
	void d_list_tail_insert(dnode* &d_tail_ptr, const dnode::value_type& entry); // Function to insert a node to the tail of the list
	void d_list_head_remove(dnode*& d_head_ptr, dnode*& d_tail_ptr); // Function to remove a node from the head of the list
	void d_list_tail_remove(dnode* &d_tail_ptr,  dnode* &d_head_ptr); // Function to remove a node from the tail of the list

	void d_list_print(dnode * d_headPtr);			// Printind doubly linked list
	void list_printReverse(dnode * d_tailPtr);		// Prints the list in reverse order
	void d_list_showStatistics(dnode *d_headPtr);   // Shows statistics on doubly linked list
}

#endif

