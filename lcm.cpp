#include<iostream>/*
using namespace std;

int gcd(int a, int b){
	
	int r, p, q;
	if(a > b){
		p = a;
		q = b;
	}
	else
	{
		p = b;
		q = a;
	}
	
	r = p % q;
	if(r == 0){
		return q;
	}
	else{
		gcd(q, r);	
	}
}


long long lcm(int a, int b){
	int hcf;
	long long mul, p, q, l;
	
	p = a, q = b;
	mul= p * q;
	
	hcf = gcd(a,b);
	l = mul / hcf;
	std :: cout <<l;
	return l;
}


int main(){
	int a, b;
	std :: cin >> a;
	std :: cin >> b;
	lcm(a,b);
	return 0;
}*/
#include <iostream>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_naive(a, b) << std::endl;
  return 0;
}
