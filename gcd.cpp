#include<iostream>
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
		std :: cout << q ;
	}
	else{
		gcd(q, r);	
	}
}

int main(){
	int a, b, g;
	std :: cin >> a;
	std :: cin >> b;
	g = gcd(a,b);
	
	return 0;
}
