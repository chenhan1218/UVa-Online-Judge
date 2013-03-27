#include <iostream>
using namespace std ;

class Node
{
	public :
		Node() ;
		int n ;
		Node *left ;
		Node *right ;
};

Node::Node()
{
	left= NULL ;
	right = NULL ;
}

class Node_queue
{
	public :
		Node_queue() ;
		Node *value ;
		Node_queue *next ;
};

Node_queue::Node_queue()
{
	value = NULL ;
	next = NULL ;
}

int main()
{
	char s ;
	int n ;

	Node *head ;
	Node *dealing ;

	Node_queue *queueprint , *queue_last , *temp_Node_queue ;

	int output[ 256 ] ;
	int numbers_node ;

	while( cin >> s )
	{
		head = new Node() ;
		head->n = 0 ;

		do
		{
			dealing = head ;

			cin >> n ; /* something wrong happen here */
			if( cin.fail() )
			{
				cin.clear() ;
			}

			cin >> s ;  /* use to absort ','   */

			if( s == ')')
			{
				break ;
			}
			else
			{
				while( cin >> s )
				{
					if( s == ')' )
					{
						if( dealing->n == 0 )
						{
							dealing->n = n ;
						}
						else
						{
							dealing->n = -1 ;
						}

						break ;
					}
					else if( s == 'L' )
					{
						if( dealing->left == NULL )
						{
							dealing->left = new Node ;
							(dealing->left)->n = 0 ;
						}

						dealing = dealing->left ;
					}
					else if( s == 'R' )
					{
						if( dealing->right == NULL )
						{
							dealing->right = new Node ;
							(dealing->right)->n = 0 ;
						}

						dealing = dealing->right ;
					}
				}
			}
		}while( cin >> s );

		numbers_node = 0 ;
		queueprint = new Node_queue ;
		queueprint->value = head ;
		queue_last = queueprint ;

		while( queueprint != NULL )
		{
			if( (queueprint->value)->n > 0 )
			{
				
				output[ numbers_node ] = (queueprint->value)->n ;
				numbers_node++ ;

				if( (queueprint->value)->left != NULL )
				{
					queue_last->next = new Node_queue ;
					queue_last = queue_last->next ;

					queue_last->value =  (queueprint->value)->left ;
				}
				if( (queueprint->value)->right != NULL )
				{
					queue_last->next = new Node_queue ;
					queue_last = queue_last->next ;

					queue_last->value =  (queueprint->value)->right ;
				}

				temp_Node_queue = queueprint ;
				queueprint = queueprint->next ;
				delete temp_Node_queue ;
			}
			else
			{
				break ;
			}
		}

		if( queueprint != NULL )
		{
			cout << "not complete" << endl ;
		}
		else
		{
			for( int i = 0 ; i < numbers_node - 1 ; i++ )
			{
				cout << output[ i ] << " " ;
			}
			cout << output[ numbers_node - 1 ] << endl ;
		}
	}

	return 0 ;
}
