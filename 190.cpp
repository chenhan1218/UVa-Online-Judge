#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std ;

void solve( double **matrix, int n )
{
	int		i = 0 ;
	int		j = 0 ;
	int		k = 0 ;
	
	for( i = 0 ; i < n ; i++ )
	{
		// ensure that pivot is exist
		j = i ;
		while( j < n && matrix[ j ][ i ] == 0 )
		{
			j++ ;
		}

		if( j == n )
			return ;
		swap( matrix[ i ], matrix[ j ] ) ;
		
		for( j = n ; j >= i ; j-- )
		{
			matrix[ i ][ j ] /= matrix[ i ][ i ] ;
		}
		
		for( j = i + 1 ; j < n ; j++ )
		{
			for( k = n ; k >= i ; k-- )
			{
				matrix[ j ][ k ] -= matrix[ i ][ k ] * matrix[ j ][ i ] ;
			}
		}
	}

	for( i = n - 1 ; i >= 0 ; i-- )
	{
		for( j = i - 1 ; j >= 0 ; j-- )
		{
			matrix[ j ][ n ] -= matrix[ j ][ i ] * matrix[ i ][ n ] ;
			matrix[ j ][ i ] = 0 ;
		}
	}
}

int main()
{
	double	*matrix[ 3 ] = { 0 } ;
	double	x[ 3 ] = { 0 } ;
	double	y[ 3 ] = { 0 } ;
	double	c = 0 ;
	double	d = 0 ;
	double	e = 0 ;
	double	h = 0 ;
	double	k = 0 ;
	double	r = 0 ;
	int		i = 0 ;
	int		j = 0 ;
	
	cout << fixed << setprecision( 3 ) ;
	
	for( i = 0 ; i < 3 ; i++ )
		matrix[ i ] = new double[ 4 ] ;
	
	while( cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] )
	{
		for( i = 0 ; i < 3 ; i++ )
		{
			matrix[ i ][ 0 ] = x[ i ] ;
			matrix[ i ][ 1 ] = y[ i ] ;
			matrix[ i ][ 2 ] = 1 ;
			matrix[ i ][ 3 ] = 0 - x[ i ] * x[ i ] - y[ i ] * y[ i ] ;
		}
		
		solve( matrix, 3 ) ;
		c = matrix[ 0 ][ 3 ] ;
		d = matrix[ 1 ][ 3 ] ;
		e = matrix[ 2 ][ 3 ] ;
		h = c / 2 ;
		k = d / 2 ;
		r = sqrt( pow( c/2, 2 ) + pow( d/2, 2 ) - e ) ;
		
		cout << "(x " ;
		if( h >= 0 )
		{
			cout << "+ " << fabs( h ) ;
		}
		else
		{
			cout << "- " << fabs( h ) ;
		}
		cout << ")^2 + (y " ;
		if( k >= 0 )
		{
			cout << "+ " << fabs( k ) ;
		}
		else
		{
			cout << "- " << fabs( k ) ;
		}
		cout << ")^2 = " << r << "^2" << endl ;
		
		cout << "x^2 + y^2 " ;
		if( c >= 0 )
		{
			cout << "+ " << fabs( c ) ;
		}
		else
		{
			cout << "- " << fabs( c ) ;
		}
		cout << "x " ;
		if( d >= 0 )
		{
			cout << "+ " << fabs( d ) ;
		}
		else
		{
			cout << "- " << fabs( d ) ;
		}
		cout << "y " ;
		if( e >= 0 )
		{
			cout << "+ " << fabs( e ) ;
		}
		else
		{
			cout << "- " << fabs( e ) ;
		}
		cout << " = 0" << endl ;
		cout << endl ;
	}
	
	return 0 ;
}
