#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long product = 1;

    for (long long i = 0; i < n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = ( tmp_previous + current ) % 10;
    }
    product = current * previous;
    return product % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    long long diff = n / 60;
    n = n - ( 60 * diff );
    std::cout << fibonacci_sum_squares_naive(n);
}
