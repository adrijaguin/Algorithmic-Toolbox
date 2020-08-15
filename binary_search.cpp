#include <iostream>
#include <cassert>
#include <vector>
using std::cout;
using std::cin;
using std::vector;



int binary_search(const vector<int> &a, int x) 
{	
  int left = 0, right = (int)a.size() - 1, middle = 0;
  
  	while( left <= right )
  	{
  		middle = left + (right - left) / 2;
		  	
  		if ( a[middle] == x )
  		{
  			return middle;
  		}
  		else if ( a[middle] > x )
  		{
			right = middle - 1;
	  	}
	  	else if ( a[middle] < x )
	  	{
	  		left = middle + 1;
		}
  	}
  	return -1;
  
}

void binary_search_wrapper(const vector<int> &a, vector<int> &b)
{
	int bSize = b.size();
	vector<int> c(bSize);
	
	for ( int i = 0; i < bSize; i++)
	{
		c[i] = binary_search(a, b[i]);
	}
	
	for ( int i = 0; i < bSize; i++)
	{
		cout << c[i] << " ";
	}
}


int main() {
  int n, m;
  cin >> n;
  vector<int> a(n);

  //Starting with the input array size along with the input
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  
  cin >> m;
  vector<int> b(m);
  //Keys to be searched starting with the number of keys to be searched
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  binary_search_wrapper(a, b);
  return 0;
}
