#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  
  int i = 1;
  while ( i <= n )
  {
  	n -= i;
  	summands.push_back(i);
  	i++;
  }
  if ( n != 0 )
  {
  	summands[i-2] += n;
  }
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
