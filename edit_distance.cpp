#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using std::vector;
using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::min;

int edit_distance( string &str1, string & str2 )
{
	int l1 = str1.length(), col, row;
	int l2 = str2.length();
	int dp[l1 + 1][l2 + 1];

	for ( row = 0; row <= l1; row++ )
	{
		for ( col = 0; col <= l2; col++)
		{
			dp[row][col] = 0;
		}
	}
	
	for ( col = 0; col <= l2; col++  )
	{
		dp[0][col] = col;
	}
	
	for ( row = 0; row <= l1; row++  )
	{
		dp[row][0] = row;
	}
	
	for ( row = 1; row <= l1; row++ )
	{
		for ( col = 1; col <= l2; col++)
		{
			int mis = dp[row - 1][col - 1] + 1;
			int mat = dp[row - 1][col - 1];
			int ins = dp[row][col - 1] + 1;
			int del = dp[row - 1][col] + 1;
			if ( str1[row-1] == str2[col-1] ) {
				dp[row][col] = mat;
            }
            else
            {
            	dp[row][col] = min(mis, min(ins, del));
			}	
		}
	}
	return dp[l1][l2];
}

int main() {
  string str1, str2;
  cin >> str1;
  cin >> str2;
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
