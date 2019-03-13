#include <iostream>

//--------------------------------------------------------------------
// Write a C/C++ program (without using STL or other Library), to Read 
// a Double Precision value from stdin and print the smallest number 
// that is greater than 95% of the numbers encountered so far. 
// Ex: Run with Input size : 128,000,000 
//--------------------------------------------------------------------

struct Node
{
	double value;
	Node * next;
	Node(double val) : value(val), next(nullptr) {}
};

//Sorted Linked List 
class LinkedList
{
	Node * first; 
	int count;
public:
	LinkedList() : first(nullptr), count( 0 ) {}
	void insert(double val);
	double getvalue();
	void printList();
};


//Function to get the next number after 95th percent of List 
double LinkedList::getvalue()
{

	if (first == nullptr)
	{
		return 0;
	}

	//Calucate the Index of the 95th Element in list 
	int value = count * 0.95;
	std::cout << value << std::endl;
	
	//Move the Node to that position
	Node * temp = first;
	while (value-1 > 0)
	{
		temp = temp->next;
		--value;
	}

	//Retrieve the Value
	if (temp->next == nullptr)
	{
		return temp->value;
	}
	else
	{
		temp = temp->next;
		return temp->value;
	}
}

//Sorted Insert
void LinkedList::insert(double val)
{
	Node * node = new Node(val);
	count++;

	if (first == nullptr)
	{
		first = node;
		return;
	}

	Node * prev = nullptr;
	Node * curr = first;

	if (val < first->value)
	{
		node->next = first;
		first = node;
		return;
	}

	while (curr != NULL)
	{
		if (val < curr->value)
		{
			break;
		}
		prev = curr;
		curr = curr->next;
	}

	if (curr == nullptr)
	{
		prev->next = node;
		return;
	}

	prev->next = node;
	node->next = curr;
}

void LinkedList::printList()
{
	Node * temp = first;
	if (first == nullptr)
	{
		std::cout << "Empty List" << std::endl;
		return;
	}

	std::cout << "Number of Elements : " << count << std::endl;
	for (Node * temp = first; temp != nullptr; temp = temp->next)
	{
		std::cout << temp->value << " ";
	}
	std::cout << std::endl;
}

int main()
{
	LinkedList * ll = new LinkedList();
	ll->insert( 45 );
	ll->insert( 56);
	ll->insert( 12);
	ll->insert(  6 );
	ll->insert( 100 );
	ll->insert( 12345 );
	ll->insert( 37);
	ll->insert( 67 );
	ll->insert( 19 );
	ll->insert( 81 );
	ll->insert( 111 ) ;
	ll->insert( 423 );
	ll->insert( 9 );
	ll->insert(1000 );
	ll->insert(43 );
	ll->insert(59 );
	ll->insert(2222 );
	ll->insert(32 );
	ll->insert(99 );
	ll->insert(1001 );

	ll->insert(44);
	ll->insert(467);
	ll->insert(181);
	ll->insert(180);
	ll->insert(281);
	ll->insert(54);
	ll->insert(418);
	ll->insert(404);
	ll->insert(952);
	ll->insert(18953);

	ll->insert(1999 );
	ll->insert(5 );
	ll->insert(555 );
	ll->insert(381 );
	ll->insert(8323);
	ll->insert(700);
	ll->insert(1011);

	ll->printList();
	std::cout << ll->getvalue() << std::endl;
}