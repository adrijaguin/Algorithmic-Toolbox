#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
#include <map> 
using std::vector;
using std::map;
using std::pair;
//using std::iterator;
using std::cin;
using std::cout;


int get_majority_element(vector<long> &a, int left, int right, int major, int elem) {
	
  int count = 0, i;
  long x = a[left];
  vector<long> c;
  map<long, int> m;
  map<long, int>::iterator itr; 
  
  c.push_back(a[0]);
  //for finding unique elements
  for ( i = 1; i < right; i++ )
  {
  	if ( a[i] != a[i-1]  )
  	{
  		c.push_back(a[i]);
	}
  }
  //for inserting into tree and count
  i = 0;
  for ( int j = 0; j < right; j++ )
  {
  	if ( a[j] == x )
  	{
  		count++;
	}
	else if ( a[j] != x )
	{
		j--;
		m.insert(pair<long, int>(c[i], count));
		i++;
		left = left + count;
		x = a[left];
		count = 0;
	}
	if ( (a[j] == a[j-1]) && (i == c.size()-1) && (j == a.size()-1))
	{
		m.insert(pair<long, int>(c[i], count));
	}
  }
	for ( itr = m.begin(); itr != m.end(); itr++ ) 
    {
    	if ( itr->second > elem )
    	{
    		major++;
    		return major;
		}
	}
	
    return major;
} 
 
  /*
  for ( i = left; i < right; i++ )
  {
  	if ( a[i] == x )
  	{
  		count++;
  		//cout << "\tcount: " << count << "\t";
    }
   	if ( count > elem )
  	{
  		major++;
  		//cout << "\nelem: " << elem << "\t";
  		//cout << "\tmajor1: " << major << "\n";
  		return major;
  	}
	 if ( a[i] != x && left < right - 1)
  	{
  		left = left + count;
  		x = a[left];
  		count = 0;
  		//major = get_majority_element(a, left+count, right, major, elem);
  		//cout << "\nmajor1: " << major << "\n";
  		//return major;
		//if ( major == 1 )
  		//{
  			//cout << "\nmajor2: " << major << "\n";
  			//return major;
		//}
   
    /*else if ( a[i] != x && left < right - 1 )
  	{	
  		//left = left + count;
  		get_majority_element(a, left+count, right, elem);
  	}*/
  	
  
  //if ( a[i] != x && left < right - 1)
  //{
  	//left = left + count;
  	//major = get_majority_element(a, left+count, right, major, elem);
  	//cout << "\nmajor1: " << major << "\n";
  	//return major;
	//if ( major == 1 )
  	//{
  		//cout << "\nmajor2: " << major << "\n";
  		//return major;
	//}
  //}
  //cout << "\nmajor: " << major << "\n";
	
	

/*
int majority(vector<long> &a, int left, int right, int major, int elem)
{
	for ( int i = 0; i < right; i++ )
	{
		int currElement = a[i];
		int count = 0;
		for ( int j = 0; j < right; j++ )
		{
			if ( a[j] == currElement )
			{
				count++;
			}
			if ( count > elem )
			{
				return 1;
			}
		}
	}
	return 0;
}


int stress_test(vector<long>a, int left, int right, int major, int elem, int iter)
{
	int nm, fm;
	
	nm = majority(a, left, right, major, elem);
	fm = get_majority_element(a, left, right, major, elem);
	
	if ( nm != fm )
	{
		cout << "\nnm result: " << nm << "\n";
		cout << "\nfm result: " << fm << "\n";
		cout << "\niter: " << iter << "\n";
		for ( int d = 0; d < right; d++ )
			cout << a.at(d) << " ";
		return -1;
	}
	else
	{
		cout << "OK";
	}
	
	int i = 0;
	int temp = a[0];
	while ( i < right )
	{
		a[i] = a[i+1];
		i++;
	}
	a[i-1] = temp; 
	cout << "\na[]: ";
	for ( int f = 0; f < right; f++ )
	{
		cout << a[f] << "\t";
	}cout << "\n";
	iter++;
	stress_test(a, left, right, major, elem, iter);
}
*/

int main() 
{
  int n;
  cin >> n;
  vector<long> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  sort( a.begin(), a.end() );
  cout << get_majority_element(a, 0, a.size(), 0, n/2);
  //cout << "Failed case: " << stress_test(a, 0, a.size(), n/2, 0, 1) << "\n";
}
