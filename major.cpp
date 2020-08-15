#include <algorithm>
#include <iostream>
#include <vector>
using std::vector;
using std::cin;
using std::cout;

int get_majority_element(vector<long> &a, int left, int right, int major, int elem) {
	
  int count = 0, i;
  long x = a[left];  
  
  for ( i = left; i < right; i++ )
  {
  	if ( a[i] == x )
  	{
  		count++;
  	}
   	if ( count > elem )
  	{
  		major++;
  		return major;
  	}
	 if ( a[i] != x && left < right - 1)
  	{
  		left = left + count;
  		x = a[left];
  		count = 0;
    	}
  }
	return major;
}

int main() 
{
  int n;
  //n = rand() % 11;
  cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
    //a[i] = rand() % 10;
  }
  sort( a.begin(), a.end() );
  cout << get_majority_element(a, 0, a.size(), 0, n/2);
}