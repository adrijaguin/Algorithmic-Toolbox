#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;
using std::max;

int lcs2(vector<int> &a, vector<int> &b, int n, int m) {
 int dp[n+1][m+1];
 
  for ( int row = 0; row <= n; row++ )
  {
  	for ( int col = 0; col <= m; col++ )
  	{
  		dp[row][col] = 0;
	}
  }
 
  for ( int row = 0; row <= n; row++ )
  {
  	for ( int col = 0; col <= m; col++ )
  	{
  		if ( row == 0 || col == 0 )
  		{
  			dp[row][col] = 0;
		}
  		else if ( a[row-1] == b[col-1] )
		{
			dp[row][col] = dp[row-1][col-1] + 1;
		}
		else
		{
			dp[row][col] = max(dp[row-1][col], dp[row][col-1]);
		}
	}
  }
  return dp[n][m];
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for ( int i = 0; i < n; i++ ) {
    cin >> a[i];
  }

  int m;
  cin >> m;
  vector<int> b(m);
  for ( int i = 0; i < m; i++ ) {
    cin >> b[i];
  }

  cout << lcs2(a, b, n, m) << "\n";
}
