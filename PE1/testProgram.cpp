// Main Program Menu to use Singly and Doubly linked list functions
// Author: Joshua Zimmerman 
// Date: 03/03/17

#include<cstdlib>
#include<cassert>
#include <iostream> // for file I/O

#include "dnode.h" // doubly linked list function(s) header file
#include "node1.h"// singly linked list function(s) header file

using namespace std;
using namespace main_savitch_5;
int main()

{
	
	node *ptr = NULL;		// pointer to determine if link is empty for Singly Linked List
	node *headPtr = NULL;	// pointer to determine if link is empty for Singly Linked List
	node *tailPtr = NULL;	// pointer to determine if link is empty for Singly Linked List

	dnode *d_ptr = NULL;		// pointer to determine if link is empty for doubly Linked List
	dnode *d_headPtr = NULL;	// pointer to determine if link is empty for doubly Linked List
	dnode *d_tailPtr = NULL;	// pointer to determine if link is empty for doubly Linked List
	
	int userInput; // User input for Singly linked list or Doubly linked list
	int subUserInput; // User input for Singly and Doubly linked list sub menues

	int firstNodevalue;
	// node singlyLinkedListObject; 

	do
	{
	cout << "Menu" << endl;
	cout << "1. Singly linked list" << endl;
	cout << "2. Doubly linked list" << endl;
	cout << "3. Exit" << endl;
	
	cin >> userInput;

		switch (userInput) // Swtich statement that handles user input to choose which node function to call
		{
		case 1:
			do
			{

				cout << endl;
				cout << "*****************************************" << endl;
				cout << " Sub Menu for Singly linked list" << endl;
				cout << "1. Create a node" << endl;
				cout << "2. Insert a node to the head" << endl;
				cout << "3. Insert a node to the tail" << endl;
				cout << "4. Remove a node from the head" << endl;
				cout << "5. Remove a node from the tail" << endl;
				cout << "6. Print the list" << endl;
				cout << "7. Show statistics" << endl;
				cout << "8. Exit to main menu" << endl;

				cin >> subUserInput; // Gets user input for sub menu 

				switch (subUserInput) // swtich statement to test user user input for the singly linked list sub menu 

				{

				case 1: // case to create a node
					if (ptr == NULL)
					{
						cout << "Create a node" << endl;
						ptr = new node; // node object 
						headPtr = ptr;
						tailPtr = ptr;
						cout << "Please enter a value to put in the first node:" << endl;
						cin >> firstNodevalue; // Gets user input for node's data field 
						ptr->set_data(firstNodevalue);
						ptr->set_link(NULL);
						
						break;
					}
					else
					{
						cout << "Error a node has already been created " << endl;
					break;
				}
					

				case 2: // case to insert a node to the head

					

					if (ptr != NULL)
					{
						cout << "Please enter a value to insert to the head" << endl;
						cin >> firstNodevalue;
						list_head_insert(headPtr, firstNodevalue);
						break;
					}
					else
					{
						cout << "Error: There is no node in the list. Press any key to continue " << endl;
						cout << endl;
						break;
					}

				case 3: // case to insert a node to the tail

					

				
					if (ptr != NULL) // checks of list is empty 
					{
						cout << "Please enter a value to insert to the tail" << endl;
						cin >> firstNodevalue;
						list_tail_insert(tailPtr,firstNodevalue); // to insert into tail
						
						break;
					}
					else
					{
						cout << "Error: There is no node in the list. Press any key to continue  " << endl;
						cout << endl; 
						break;
					}

				case 4: // case to remove a node from the head

		

					if (headPtr != NULL) // checks of list is empty 
					{
						
						list_head_remove(headPtr); // to remove from head

						break;
					}
					else
					{
						cout << "Error: You cannot remove the head on an empty list " << endl;
						cout << endl;
						break;
					}
				case 5: // case to remove a node from the tail

					cout << "Remove a node from the tail" << endl;

					if (tailPtr!= NULL) // Checks of list is empty 
					{
						list_tail_remove(tailPtr, headPtr); // to remove from tail
						break;
					}
					else
					{
						cout << "Error cannot remove from tail on an empty list " << endl;
						break;
					}

				case 6: // case to print the current nodes in the list

					cout << "Print the list" << endl;

					list_print(headPtr);
						break;
					

				case 7: // case to show statistics of nodes

					cout << "Show statistics" << endl;
					if (headPtr != NULL)
					{
						list_showStatistics(headPtr);
						break;
					}
					else
					{
						cout << "There is no  node in the list to print" << endl;
						break;
					}

					

				case 8: // case to exit the singly linked list sub menu 

					break;

				}
			} while (subUserInput != 8); // tests if user input is the value to go back to main menu
			break;

		case 2:
			do
			{
			cout << endl;

			cout << "*****************************************" << endl;
			cout << "Sub Menu for Doubly linked list" << endl;
			cout << "1. Create a node" << endl;
			cout << "2. Insert a node to the head" << endl;
			cout << "3. Insert a node to the tail" << endl;
			cout << "4. Remove a node from the head" << endl;
			cout << "5. Remove a node from the tail" << endl;
			cout << "6. Print the list" << endl;
			cout << "7. Print the list in reverse order" << endl;
			cout << "8. Show statistics" << endl;
			cout << "9. Exit to main menu" << endl;

			cin >> subUserInput;

			switch (subUserInput)

			{

			case 1: // case to create a new node 

				if (d_headPtr == NULL)
				{
					cout << "Create a node" << endl;
					d_ptr = new dnode; // node object 
					d_headPtr = d_ptr;
					d_tailPtr = d_ptr;
					cout << "Please enter a value to put in the first node:" << endl;
					cin >> firstNodevalue; // Gets user input for node's data field 
					d_ptr->set_data(firstNodevalue);
					d_ptr->set_fore(NULL);
					d_ptr->set_back(NULL);
				
					break;
				}
				else
				{
					cout << "Error a node has already been created " << endl;
					break;
				}

			case 2: // case to insert a node to the head

				cout << "Insert a node to the head" << endl;

				if (d_headPtr != NULL)
				{
					cout << "Please enter a value to insert to the head" << endl;
					cin >> firstNodevalue;
					d_list_head_insert(d_headPtr, firstNodevalue);
					break;
				}
				else
				{
					cout << "Error cannot insert on an empty list " << endl;
					break;
				}

			case 3: // case to insert a node to the tail

				cout << "Insert a node to the tail" << endl;

				if (d_tailPtr != NULL) // checks of list is empty 
				{
					cout << "Please enter a value to insert to the tail" << endl;
					cin >> firstNodevalue;
					d_list_tail_insert(d_tailPtr, firstNodevalue); // to insert into tail

					break;
				}
				else
				{
					cout << "Error cannot insert on an empty list " << endl;
					break;
				}

			case 4: // case to remove a node from the head

				cout << "Remove a node from the head" << endl;
				if (d_headPtr != NULL) // checks of list is empty 
				{

					d_list_head_remove(d_headPtr, d_tailPtr); // to remove from head

					break;
				}
				else
				{
					cout << "Error cannot remove head on an empty list " << endl;
					break;
				}

			case 5: // case to remove a node from the tail

				cout << "Remove a node from the tail" << endl;
				
				if (d_tailPtr != NULL) // Checks of list is empty 
				{
					d_list_tail_remove(d_tailPtr, d_headPtr); // to remove from tail
					break;
				}
				else
				{
					cout << "Error cannot remove from tail on an empty list " << endl;
					break;
				}

			case 6: // case to print the list of nodes

				cout << "Print the list" << endl;


				d_list_print(d_headPtr);
				break;

			case 7: // case to print the list in reverse order 

				cout << "Print the list in reverse order" << endl;
				list_printReverse(d_tailPtr);
				break;

			case 8: // case to show statistics 

				cout << "Show stastics" << endl;
				if (d_headPtr != NULL)
				{
					d_list_showStatistics(d_headPtr);
					break;
				}
				else
				{
					cout << "Error: There is no node in the list to print" << endl;
					break;
				}

			case 9: // case to exit the main menu
				break;
			}

			} while (subUserInput != 9); // tests if user input is the value to exit the submenu 
			break;

		}

	}while (userInput != 3); // Tests if the user inputs the Exit value
	

	return 0; // Exits the program



}

/*


Menu
1. Singly linked list
2. Doubly linked list
3. Exit
1

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
2
Error: There is no node in the list. Press any key to continue


*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
4
Error: You cannot remove the head on an empty list


*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
The linked list is empty.

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
7
Show statistics
There is no  node in the list to print

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
1
Create a node
Please enter a value to put in the first node:
5

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
the printed order of a current linked list is:
5

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
7
Show statistics
Statistics:

total sum 5
smallest value 5
largest value 5
Sum: 5
Average 5

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
1
Error a node has already been created

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
2
Please enter a value to insert to the head
1

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
the printed order of a current linked list is:
1
5

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
7
Show statistics
Statistics:

total sum 6
smallest value 1
largest value 5
Sum: 6
Average 3

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
3
Please enter a value to insert to the tail
9

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
the printed order of a current linked list is:
1
5
9

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
7
Show statistics
Statistics:

total sum 15
smallest value 1
largest value 9
Sum: 15
Average 5

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
3
Please enter a value to insert to the tail
4

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
the printed order of a current linked list is:
1
5
9
4

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
7
Show statistics
Statistics:

total sum 19
smallest value 1
largest value 9
Sum: 19
Average 4.75

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
4

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
the printed order of a current linked list is:
5
9
4

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
4

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
the printed order of a current linked list is:
9
4

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
7
Show statistics
Statistics:

total sum 13
smallest value 4
largest value 9
Sum: 13
Average 6.5

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
5
Remove a node from the tail

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
the printed order of a current linked list is:
9

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
5
Remove a node from the tail

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
6
Print the list
The linked list is empty.

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
7
Show statistics
There is no  node in the list to print

*****************************************
Sub Menu for Singly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Show statistics
8. Exit to main menu
8
Menu
1. Singly linked list
2. Doubly linked list
3. Exit
2

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
3
Insert a node to the tail
Error cannot insert on an empty list

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
4
Remove a node from the head
Error cannot remove head on an empty list

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
The linked list is empty.

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
7
Print the list in reverse order
The linked list is empty.

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
1
Create a node
Please enter a value to put in the first node:
10

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
2
Insert a node to the head
Please enter a value to insert to the head
8

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
the printed order of a current linked list is:
8
10

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
7
Print the list in reverse order
the reversed printed order of a current linked list is:
10
8

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
8
Show stastics
Statistics:

total sum 18
smallest value 8
largest value 10
Sum: 18
Average 9

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
3
Insert a node to the tail
Please enter a value to insert to the tail
12

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
the printed order of a current linked list is:
8
10
12

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
7
Print the list in reverse order
the reversed printed order of a current linked list is:
12
10
8

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
8
Show stastics
Statistics:

total sum 30
smallest value 8
largest value 12
Sum: 30
Average 10

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
2
Insert a node to the head
Please enter a value to insert to the head
9

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
the printed order of a current linked list is:
9
8
10
12

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
7
Print the list in reverse order
the reversed printed order of a current linked list is:
12
10
8
9

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
8
Show stastics
Statistics:

total sum 39
smallest value 8
largest value 12
Sum: 39
Average 9.75

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
4
Remove a node from the head

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
the printed order of a current linked list is:
8
10
12

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
7
Print the list in reverse order
the reversed printed order of a current linked list is:
12
10
8

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
8
Show stastics
Statistics:

total sum 30
smallest value 8
largest value 12
Sum: 30
Average 10

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
5
Remove a node from the tail

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
the printed order of a current linked list is:
8
10

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
7
Print the list in reverse order
the reversed printed order of a current linked list is:
10
8

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
8
Show stastics
Statistics:

total sum 18
smallest value 8
largest value 10
Sum: 18
Average 9

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
5
Remove a node from the tail

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
the printed order of a current linked list is:
8

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
5
Remove a node from the tail

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
6
Print the list
The linked list is empty.

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
5
Remove a node from the tail
Error cannot remove from tail on an empty list

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
2
Insert a node to the head
Error cannot insert on an empty list

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
8
Show stastics
Error: There is no node in the list to print

*****************************************
Sub Menu for Doubly linked list
1. Create a node
2. Insert a node to the head
3. Insert a node to the tail
4. Remove a node from the head
5. Remove a node from the tail
6. Print the list
7. Print the list in reverse order
8. Show statistics
9. Exit to main menu
9
Menu
1. Singly linked list
2. Doubly linked list
3. Exit
3
Press any key to continue . . .

*/