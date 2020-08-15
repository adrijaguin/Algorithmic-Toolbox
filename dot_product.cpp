#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long max_dot_product(vector<int> a, vector<int> b) {
  
	long long result = 0;
  	int n = a.size();
 	sort(a.begin(), a.end());
 	sort(b.begin(), b.end());
 
  for(size_t i = 0; i < n; i++)
  {	
  	result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }
  std::cout << "\n" << max_dot_product(a, b) << std::endl;
}

