#include <iostream>
using namespace std ;

class Node
{                        //Declare structure of vertex
	public:
		Node( long long ) ;
		long long integer ;
		int times ;
		Node *next ;
};

Node::Node( long long input_integer )
{
	integer = input_integer ;
	times = 0 ;
	next = NULL ;
}

int main()
{
	Node *ptr_first_element , *ptr_last_element , *ptr_temp ;

	long long input ;
	cin >> input ;

	ptr_temp = new Node( input ) ;
	ptr_temp->times ++ ;
	ptr_first_element = ptr_temp ;
	ptr_last_element = ptr_temp ;

	while( cin >> input )
	{
		ptr_temp = ptr_first_element ;
		while( ptr_temp != NULL )
		{
			if( ptr_temp->integer == input )
			{
				ptr_temp->times ++ ;
				break ;
			}
			else
			{
				// The element is not in Node ptr_temp, so we try to find next element in the queue.
				ptr_temp = ptr_temp->next ;
			}
		}
		
		if( ptr_temp == NULL )
		{
			// If ptr_temp == NULL, it means the input integer is not in the queue.
			// So now we have to allocate a space for the new comer.
			ptr_temp = new Node( input ) ;
			ptr_temp->times ++ ;
			ptr_last_element->next = ptr_temp ;
			ptr_last_element = ptr_last_element->next ;

		}
	}

	ptr_temp = ptr_first_element ;
	while( ptr_temp != NULL )
	{
		cout << ptr_temp->integer << " " << ptr_temp->times << endl ;

		ptr_temp = ptr_temp->next ;
	}

	return 0 ;
}
