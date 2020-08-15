#include <iostream>

int get_change(int m) {
  int n1 = 0, n2;
  
  n1 = (m / 10);
  m = m - ( 10 * n1 );
  
  n2 = (m / 5);
  m = m - ( 5 * n2 );
  
  n1 += m + n2;
    
  return n1;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
