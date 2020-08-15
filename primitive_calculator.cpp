#include <iostream>
#include <climits>
#include <vector>
#include <list>
#include <stdint.h>
using std::vector;
using std::list;
using std::cout;
using std::cin;

void primitive_calculator(int32_t number)
{
        vector<int32_t> min_steps( number + 1);
        vector<int32_t> predecessor( number + 1);
        
        for( int32_t i = 2; i <= number; i++ )
        {
        	min_steps[i] = min_steps[i - 1] + 1;
        	predecessor[i] = i - 1;
            if ( i % 3 == 0 )
            {
                if( min_steps[i/3] < min_steps[i] )
                {
                        min_steps[i] = min_steps[i/3] + 1;
                        predecessor[i] = i/3;
                }
            }
            if ( i % 2 == 0 )
            {
                if( min_steps[i/2] < min_steps[i] )
                {
                        min_steps[i] = min_steps[i/2] + 1;
                        predecessor[i] = i/2;
                }
            }
    }
    cout << min_steps[number] << "\n";
    list<int32_t> sequence;
    for ( int32_t i = number; i != 0; i = predecessor[i] )
    {
    	sequence.push_front(i);
	}
	list<int32_t>::iterator it;
	for ( it = sequence.begin(); it != sequence.end(); ++it )
	{
		cout << *it << " ";
	}
}
int main()
{
    int32_t number;
    cin >> number;
    primitive_calculator(number);
    return 0;
}

