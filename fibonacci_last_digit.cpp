#include <iostream>
#include <cmath>

int get_fibonacci_last_digit_naive(int n) {
    int current;
	if (n <= 1)
    {
    	current = n;
	}
        
    else
	{
 	   int previous = 0;
    	current  = 1;

    	for (int j = 0; j < n - 1; ++j) {
    		int tmp_previous = previous;
       		previous = current;
        	current = (tmp_previous + current) % 10;
   		 }
	}
	
	return current;
}

int main() {
    int n;
    std::cin >> n;
    //test_sol(n);
    int c = get_fibonacci_last_digit_naive(n);
    std::cout << c << "\n";
    }
