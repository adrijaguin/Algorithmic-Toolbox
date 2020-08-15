#include <iostream>
#include <vector>
using std::vector;

int get_fibonacci_partial_sum_naive(int from, int to) {
    int sum = 0;

    int current = 0;
    int next  = 1;

    for (int i = 0; i <= to; ++i) {
        if (i >= from) {
            sum = ( sum + current ) % 10;
        }
        int new_current = next;
        next = ( next + current ) % 10;
        current = new_current;
        
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    
    int diff = from / 60;
	from = from - ( 60 * diff );
	to = to - ( 60 * diff );
		
    if( to - from <= 60 ){
    	std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
	}
	else if( to - from > 60 ){
		int to1 = ( to / 60 );
		int to2 = to - to1 * 60;
		int sum1 = get_fibonacci_partial_sum_naive(from, 60);	
		int sum2 = get_fibonacci_partial_sum_naive(0, to2);	
		sum1 = sum1 + sum2;
		sum1 = sum1 % 10;
		std::cout << sum1;
	}
	
	return 0;
}
