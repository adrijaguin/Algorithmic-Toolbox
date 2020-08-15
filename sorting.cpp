#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
using std::cin;
using std::cout;


vector<int> partition3(vector<int> &a, int l, int r, vector<int> m) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]); 
  m[1] = j; 
  for (int i = 0; i < j; i++ )
  {
  	if ( a[i] == x )
  	{
  		swap( a[i], a[--j] );
	}
  }
  m[0] = j;
  return m;
} 

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  vector<int> m(2); 
  m = partition3(a, l, r, m);
  

  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); i++) {
    cout << a[i] << ' ';
  }
}
