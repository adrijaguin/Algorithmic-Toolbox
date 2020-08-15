#include <iostream>
#include <limits>

long long pisano_period(long long m)
{
	long long a = 0, b = 1, c;
	
	for(int j = 0; j < m * m; j++){
		c = ( a + b ) % m;
		a = b;
		b = c;
		if( a == 0 && b == 1 ) {
			return j + 1;
		}
	}
}

long long get_fibonacci_huge_naive(long long n, long long m) {
        
	long long previous = 0, current = 1;
	long long r = n % pisano_period(m);
	long long rem = r;
	
	if (r <= 1)
        return r;
    
    else{
		for (int i = 1; i < r; i++) {	
			rem = ( previous + current ) % m;	
			previous = current;
			current = rem;
    	}
	}
	return rem % m;
}

int main() {
    long long n, m, f;
    int pisano, r;
    std::cin >> n >> m;
    std :: cout << get_fibonacci_huge_naive(n, m);
    return 0;
}
