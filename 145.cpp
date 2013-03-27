#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

class Time
{
	friend istream& operator>>(istream& is, Time& t) {
		is >> t.hour >> t.minute ;
		return is;
	}
	
	public:
		Time() ;
		Time( int hour, int minute ) ;
		Time( const Time& t ) ;
		Time& operator=( Time t ) {
			hour = t.hour ;
			minute = t.minute ;
		}
		int operator-( Time& t ) {
			return toMinute() - t.toMinute() ;
		}
		int	hour ;
		int	minute ;
		int	toMinute() ;
		int	cmp( Time &t ) ;
		static int intersectMinute( Time &s1, Time &e1, Time &s2, Time &e2 ) {
			int		ans = 0 ;
			if( s1.cmp( e2 ) < 0 && s2.cmp( e1 ) < 0 )
			{
				ans += e1 - s1 ;
				ans += e2 - s2 ;
				ans -= max( e2.toMinute(), e1.toMinute() ) - 
						min( s2.toMinute(), s1.toMinute() );
			}
			return ans ;
		}
};

Time::Time()
{
	hour = 0 ;
	minute = 0 ;
}

Time::Time( int inputHour, int inputMinute )
{
	hour = inputHour ;
	minute = inputMinute ;
}

Time::Time( const Time& t )
{
	hour = t.hour ;
	minute = t.minute ;
}

int Time::toMinute()
{
	return hour * 60 + minute ;
}

int Time::cmp( Time &t )
{
	return toMinute() - t.toMinute() ;
}

Time	Zero( 0, 0 ) ;
Time	_24Time( 24, 0 ) ;
Time	DayStart( 8, 0 ) ;
Time	DayEnd( 18, 0 ) ;
Time	EveningStart( 18, 0 ) ;
Time	EveningEnd( 22, 0 ) ;
Time	NightStart( 22, 0 ) ;
Time	NightEnd( 8, 0 ) ;

class Call
{
	friend istream& operator>>(istream& is, Call& b) {
		is >> b.chargingStep >> b.calledNumber >> b.startTime >> b.endTime ;
		return is;
	}
	
	public:
		Call() {
			day = 0 ;
			evening = 0 ;
			night = 0 ;
			cost = 0 ;
		}
		char	chargingStep ;
		string	calledNumber ;
		Time	startTime ;
		Time	endTime ;
		int		day ;
		int		evening ;
		int		night ;
		double	cost ;
		void	calculateSpent() ;
};

void Call::calculateSpent()
{
	day = 0 ;
	evening = 0 ;
	night = 0 ;
	cost = 0 ;
	
	if( startTime.cmp( endTime ) >= 0 )
	{
		night += Time::intersectMinute( startTime, _24Time, Zero, NightEnd ) ;
		night += Time::intersectMinute( Zero, endTime, Zero, NightEnd ) ;
		day += Time::intersectMinute( startTime, _24Time, DayStart, DayEnd ) ;
		day += Time::intersectMinute( Zero, endTime, DayStart, DayEnd ) ;
		evening += Time::intersectMinute( startTime, _24Time, EveningStart, EveningEnd ) ;
		evening += Time::intersectMinute( Zero, endTime, EveningStart, EveningEnd ) ;
		night += Time::intersectMinute( startTime, _24Time, NightStart, _24Time ) ;
		night += Time::intersectMinute( Zero, endTime, NightStart, _24Time ) ;
	}
	else
	{
		night += Time::intersectMinute( startTime, endTime, Zero, NightEnd ) ;
		day += Time::intersectMinute( startTime, endTime, DayStart, DayEnd ) ;
		evening += Time::intersectMinute( startTime, endTime, EveningStart, EveningEnd ) ;
		night += Time::intersectMinute( startTime, endTime, NightStart, _24Time ) ;
	}
		
	switch( chargingStep )
	{
		case 'A':
			cost = 0.10 * day + 0.06 * evening + 0.02 * night ;
			break ;
		case 'B':
			cost = 0.25 * day + 0.15 * evening + 0.05 * night ;
			break ;
		case 'C':
			cost = 0.53 * day + 0.33 * evening + 0.13 * night ;
			break ;
		case 'D':
			cost = 0.87 * day + 0.47 * evening + 0.17 * night ;
			break ;
		case 'E':
			cost = 1.44 * day + 0.80 * evening + 0.30 * night ;
			break ;
		default:
			cost = -1 ;
			break ;
	}
}

int main()
{
	Call	call ;
	char	chargingStep ;
	
	while( cin >> call )
	{
		call.calculateSpent() ;
		cout 	<< setw( 10 ) << call.calledNumber
				<< setw( 6 ) << call.day 
				<< setw( 6 ) << call.evening
				<< setw( 6 ) << call.night 
				<< setw( 3 ) << call.chargingStep
				<< setw( 8 ) << fixed << setprecision( 2 ) << call.cost << endl ;
	}

	return 0 ;
}
