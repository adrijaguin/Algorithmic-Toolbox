#include <iostream>
using std::cin;
using std::cout;

int get_change(int money) {
  int d[] = { 1, 3, 4 };
  int MinNumCoins[money], m;
  MinNumCoins[0] = 0;
  for ( m = 1; m <= money; m++ )
  {
  	MinNumCoins[m] = 1000;
  	for ( int i = 0; i < 3; i++ )
  	{
  		if ( m >= d[i] )
  		{
  			int numCoins = MinNumCoins[m - d[i]] + 1;
  			if ( numCoins < MinNumCoins[m] )
  			{
  				MinNumCoins[m] = numCoins;
			}
		}
	}
  }
  return MinNumCoins[money];
}

int main() {
  int money;
  cin >> money;
  cout << get_change(money);
}
