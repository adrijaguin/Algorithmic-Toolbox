#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using std::max;
using std::min;


vector<int> IsGreaterThanEqual(vector<int>a, int i, int j)
{
	int max1 = max(a[i], a[j]);
	int min1 = min(a[i], a[j]);
	int max2 = max1;
	int min2 = min1;
	
	stringstream ss1, ss2, ss3, ss4, ss5, ss6;
	string s1, s2, s3, s4;
	
		ss1 << max1;
		ss1 >> s1;
		ss2 << min1;
		ss2 >> s2;
		
		s3 = s1 + s2;
		s4 = s2 + s1;
	
		ss3 << s3;
		ss3 >> max1;
		
		ss4 << s4;
		ss4 >> min1;

	if( min1 >= max1 )
	{
		a[i] = min2;
		a[j] = max2;
	}
	else
	{
		a[j] = min2;
		a[i] = max2;
	}
	
	return a;
}


void largest_number(vector<int> a) {

int i = 0, k, n = a.size();
vector<int> b(&a[0], &a[n]);

while ( b[i] >= 0 && i < n )
{
	if( b[i] >= 10 )
	{
			b[i] = b[i] / 10;
	}
	else if ( b[i] < 10 )
	{
		i++;
	}
}

//Bubble sort, sort a according to b
for ( i = 0; i < n-1; i++ )
{
	for ( k = 0; k < n-i-1; k++ )
	{
		if ( b[k+1] > b[k] )
		{
			swap( b[k+1], b[k] );
			swap( a[k+1], a[k] );
		}
		else if ( b[k] == b[k+1] )
		{
			a = IsGreaterThanEqual(a, k, k+1);
		}
	}
}
 

	for (int q = 0; q < n; q++) {
   		cout << a[q];
	}
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  largest_number(a);
  return 0;
}
