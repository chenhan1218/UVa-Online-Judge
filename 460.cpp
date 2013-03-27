#include <iostream>
using namespace std ;

int main()
{
	int N ;
	long long int XLL_1 , YLL_1 , XUR_1 , YUR_1 ;
	long long int XLL_2 , YLL_2 , XUR_2 , YUR_2 ;

	cin >> N ;

	for( int i = 1 ; i <= N ; i++ )
	{
		if( i != 1 )
		{
			cout << endl ;
		}

		cin >> XLL_1 >> YLL_1 >> XUR_1 >> YUR_1 ;
		cin >> XLL_2 >> YLL_2 >> XUR_2 >> YUR_2 ;

		if( XUR_1 <= XLL_2 || XUR_2 <= XLL_1 || YLL_1 >= YUR_2 || YLL_2 >= YUR_1 )
		{
			cout << "No Overlap" ;
		}
		else
		{
			if( XLL_1 <= XLL_2 )
			{
				cout << XLL_2 << " " ;

				if( YLL_1 <= YLL_2 )
				{
					cout << YLL_2 << " " ;

					if( XUR_1 >= XUR_2 )
					{
						cout << XUR_2 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
					else
					{
						cout << XUR_1 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
				}
				else
				{
					cout << YLL_1 << " " ;

					if( XUR_1 >= XUR_2 )
					{
						cout << XUR_2 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
					else
					{
						cout << XUR_1 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
				}
			}
			else
			{
				cout << XLL_1 << " " ;

				if( YLL_1 <= YLL_2 )
				{
					cout << YLL_2 << " " ;

					if( XUR_1 >= XUR_2 )
					{
						cout << XUR_2 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
					else
					{
						cout << XUR_1 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
				}
				else
				{
					cout << YLL_1 << " " ;

					if( XUR_1 >= XUR_2 )
					{
						cout << XUR_2 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
					else
					{
						cout << XUR_1 << " " ;

						if( YUR_1 >= YUR_2 )
						{
							cout << YUR_2 ;
						}
						else
						{
							cout << YUR_1 ;
						}
					}
				}
			}
		}

		cout << endl ;
	}

	return 0 ;
}
