#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

#define MaxN 30000

bool	visited[ MaxN + 1 ] = { 0 } ;
vector<int>	neighbor[ MaxN + 1 ] ;

void dfs( int index, int &counter )
{
	int		i = 0 ;
	if( visited[ index ] == false )
	{
		visited[ index ] = true ;
		counter++ ;
		for( i = 0 ; i < neighbor[ index ].size() ; i++ )
			dfs( neighbor[ index ][ i ], counter ) ;
	}
}

int main()
{
	int		n = 0 ;
	int		m = 0 ;
	int		a = 0 ;
	int		b = 0 ;
	int		counter = 0 ;
	int		largest = 0 ;
	int		t = 0 ;
	int		i = 0 ;

	cin >> t ;
	while( t > 0 )
	{
		t-- ;
		cin >> n >> m ;

		fill( visited, visited + n, false ) ;
		for( i = 0 ; i < n ; i++ )
			neighbor[ i ].clear() ;
		
		for( i = 0 ; i < m ; i++ )
		{
			cin >> a >> b ;
			neighbor[ a ].push_back( b ) ;
			neighbor[ b ].push_back( a ) ;
		}
		
		largest = 0 ;
		for( i = 1 ; i <= n ; i++ )
		{
			if( visited[ i ] == false )
			{
				counter = 0 ;
				dfs( i, counter ) ;
			
				largest = max( largest, counter ) ;
			}
		}
		
		cout << largest << endl ;
	}
	
	return 0 ;
}
/* old version 
#include <iostream>
using namespace std ;

#define Max 30000
#define true 1
#define false 0

class Node // Declare structure of vertex
{
	public:
		Node() ;
		int vertex ;
		Node *next ;
};

Node::Node()
{
	next = NULL ;
}

Node **node ; 	// node[] is the node vertex and z is the tail vertex 
Node **nodeT ; 	// node[] is the node vertex and z is the tail vertex 

void allocate() ;			//allocate the adjacency-list
void deallocate( int N ) ;			//deallocate the adjacency-list
void adjlist( int N , int M ) ;		//Build the adjacency-list of input graph
void dumplist( int N ) ; 		//Show the adjacency-list
int strongly_connect_component(int N);

int main()
{
	int a , N , M, cases ;

	allocate() ;

	cin >> a ; // read in number of cases

	for( cases = 1 ; cases <= a ; cases++ )
	{
		cin >> N >> M ;

		adjlist( N , M ) ;

		cout << strongly_connect_component( N ) << endl ;

		deallocate( N ) ;
	}

	return 0 ;
}

//
// allocate the adjacency-list
//
void allocate()
{
    node = new Node *[ Max ] ;
    nodeT = new Node *[ Max ] ;

	for( int i = 1 ; i <= Max ; i++ )
	{
		node[ i ] = new Node ;
		node[ i ]->next = NULL ;
		nodeT[ i ] = new Node ;
		nodeT[ i ]->next = NULL ;
	}
}

//
// deallocate the adjacency-list
// (Read in date from stdin )
//
void deallocate( int N )
{
	Node *tempPtr = NULL ;
	for( int i = 1 ; i <= N ; i++ )
	{
		while( node[ i ]->next != NULL )
		{
			tempPtr = node[ i ]->next ;
			node[ i ]->next = tempPtr->next ;
			delete tempPtr ;
		}

		while( nodeT[ i ]->next != NULL )
		{
			tempPtr = nodeT[ i ]->next ;
			nodeT[ i ]->next = tempPtr->next ;
			delete tempPtr ;
		}
	}
}

//
// Build the adjacency-list of input graph
//
void adjlist( int N , int M )
{
	int v1,v2;
	Node *ptr ;

	for( int i = 1 ; i <= M ; i++ )
	{
		cin >> v1 >> v2 ;

		// add v2 to the adjacency-list of v1
		ptr = new Node ;
		ptr->vertex = v2 ;
		ptr->next = node[ v1 ]->next ;
		node[ v1 ]->next = ptr ;

		// add v1 to the adjacency-list of v2
		ptr = new Node ;
		ptr->vertex = v1 ;
		ptr->next = node[ v2 ]->next ;
		node[ v2 ]->next = ptr ;

		// add v2 to the inverse adjacency-list of v1
		ptr = new Node ;
		ptr->vertex = v2;
		ptr->next = nodeT[ v1 ]->next ;
		nodeT[ v1 ]->next = ptr ;

		// add v1 to the inverse adjacency-list of v2
		ptr = new Node ;
		ptr->vertex = v1;
		ptr->next = nodeT[ v2 ]->next ;
		nodeT[ v2 ]->next = ptr ;
	}
}

//
// Show the adjacency-list
// (Print it to stdout. )
//
void dumplist( int N )
{
	Node *ptr;

	for( int i = 1 ; i <= N ; i++ )
	{
		cout << "    " << i << "  " ;

		ptr = node[ i ]->next;
		while( ptr != NULL )
		{
			cout << "  -->" << ptr->vertex ;
			ptr = ptr->next ;
		}

		cout << endl ;
	}

	cout << endl ;
}

//
// 1 call DFS(G) to compute finishing time f[u] for each vertex u
// 2 compute G^T
// 3 call DFS(G^T), but in the main loop of DFS, consider the vertices
//   in order of decreasing f[u] (as computed in line 1)
// (All the information come from INTRODUCTION TO ALGORITHMS in P.554.)
//
int strongly_connect_component( int N )
{
	void DFS_VISIT( int u , int *visitedVertexs , int *color , int *f_order ) ;
	void DFS_VISIT_T( int u , int *color , int *counter ) ;
	int *color = new int [ N + 1 ] ;	// 0 is white, 1 is gray, 2 is black
	int *f_order = new int [ N + 1 ] ;	// record the visited order of every vertex
	int counter = 0;
	int largestGroup = 0 ;
	int visitOrder = 0 ;
	int i = 0 ; // loop counter 

	// Initialize the array color to 0 for the usage below.
	for( i = 1 ; i <= N ; i++ )
	{
		color[ i ] = 0 ;
	}

	for( i = 1 ; i <= N ; i++ )
	{
		if( color[ i ] == 0 )
		{
			DFS_VISIT( i , &visitOrder , color , f_order) ;
		}
	}

	// Initialize the array color to 0 for the usage below.
	for( i = 1 ; i <= N ; i++ )
	{
		color[ i ] = 0 ;
	}

	for( i = N ; i >= 1 ; i-- )
	{
		if( color[ f_order[ i ] ] == 0 )
		{
			counter = 0 ;
			DFS_VISIT_T( f_order[ i ] , color , &counter ) ;

			if( counter > largestGroup )
			{
				largestGroup = counter ;
			}
		}
	}

	return largestGroup ;
}

void DFS_VISIT( int u , int *visitOrder , int *color , int * f_order )
{
	color[ u ] = 1 ;

	Node *v = node[ u ]->next ;

	while( v != NULL )
	{
		if( color[ v->vertex ] == 0 )
		{
			DFS_VISIT( v->vertex , visitOrder , color , f_order ) ;
		}

		v = v->next ;
	}

	color[ u ] = 2 ;

	*visitOrder = *visitOrder + 1 ;
	f_order[ *visitOrder ] = u ;
}

void DFS_VISIT_T( int u , int *color , int *counter )
{
	*counter = *counter + 1 ;
	color[ u ] = 1 ;

	Node *v = nodeT[ u ]->next ;

	while( v != NULL )
	{
		if( color[ v->vertex ] == 0 )
		{
			DFS_VISIT_T( v->vertex , color , counter ) ;
		}

		v = v->next ;
	}

	color[ u ] = 2 ;
}

*/
