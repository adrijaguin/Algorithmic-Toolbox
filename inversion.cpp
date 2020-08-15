#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::cin;


long long merge(vector<int> &a, vector<int> &b, int left, int mid, int right)
{
	int i, j, k, inv_C = 0;
	i = left;
	j = mid;
	k = left;
	
	while ( (i <= mid - 1) && (j <= right) )
	{
		if ( a[i] <= a[j] )
		{
			b[k] = a[i];
			i++;
		}
		else
		{
			b[k] = a[j];
			j++;
			inv_C += (mid - i);
		}
		k++;
	}
	while ( i <= mid - 1 )
	{
		b[k] = a[i];
		i++, k++;
	}
	while ( j <= right )
	{
		b[k] = a[j];
		j++, k++;
	}
	for ( i = left; i <= right; i++ )
	{
		a[i] = b[i];
	}
	return inv_C;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, int left, int right) {
  long long inv_count = 0;
  
  if ( right < left + 1 ) return inv_count;
  
  if ( right > left )
  {
	int mid = left + (right - left) / 2;
	inv_count = get_number_of_inversions(a, b, left, mid);
  	inv_count += get_number_of_inversions(a, b, mid+1, right);
  	
	inv_count += merge(a, b, left, mid+1, right);
  }
  return inv_count;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  vector<int> b(a.size());
  cout << get_number_of_inversions(a, b, 0, a.size()-1);
}
