#include <iostream>

long long fibonacci_sum_naive(int n2) {
    if (n2 <= 1)
        return n2;

	int fib[2];
    fib[0] = 0;
    fib[1] = 1;
    long long sum = 1;

    for (long long i = 1; i < n2; i++) {
        int temp = fib[1];
        fib[1] = ( fib[0] + fib[1] ) % 10;
        fib[0] = temp;
        sum = ( sum + fib[1] ) % 10;
    }
    
    return sum;
}

int main() {
    long long n1 = 0;
    int sum;
	long long n2;
    std::cin >> n1;
    if(n1 <= 60)
    {
    	std :: cout << fibonacci_sum_naive(n1);
	}
	else{
    	n2 = n1 % 60;
    	std :: cout << fibonacci_sum_naive(n2);
    }
    return 0;
}
