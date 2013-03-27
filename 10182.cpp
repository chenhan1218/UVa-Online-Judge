#include <iostream>
#include <iomanip>
using namespace std ;

#include <algorithm>

int
main()
{
	int		number = 0 ;
	int		layer = 0 ;
	int		x = 0 ;
	int		y = 0 ;
	int		i = 0 ; // loop counter
	int		j = 0 ; // loop counter

	while( cin >> number )
	{
		if( number == 1 )
		{
			cout << "0 0" << endl ;
		}
		else
		{
			x = 1 ;
			y = 0 ;
			number -= 1 ;
			for( layer = 1 ; number > layer * 6 ; layer++ )
			{
				number -= layer * 6 ;
				x++ ;
			}

			// now we have find the layer of the point.
			// note that we don't add break operation here.
			switch( number / layer )
			{
				case 5:
					y += number - layer * 5 ;
					number = layer * 5 ;
				case 4:
					x += number - layer * 4 ;
					number = layer * 4 ;
				case 3:
					x += number - layer * 3 ;
					y -= number - layer * 3 ;
					number = layer * 3 ;
				case 2:
					y -= number - layer * 2 ;
					number = layer * 2 ;
				case 1:
					x -= number - layer * 1 ;
					number = layer * 1 ;
				case 0:
					x -= number - layer * 0 ;
					y += number - layer * 0 ;
					number = layer * 0 ;
			}

			cout << x << " " << y << endl ;
		}
	}

	return 0 ;
}
