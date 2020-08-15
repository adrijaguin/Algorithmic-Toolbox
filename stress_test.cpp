#include<iostream>
#include<vector>
#include<cstdlib>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers)
{

	int n = numbers.size();
	int i, j;
	long long result = 0;

	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			if( ((long long)numbers[i]) * numbers[j] > result ) 
				result = ((long long)(numbers[i])) * numbers[j];
		}
	}
				
	return result;
	
}

long long MaxPairwiseProductFast(const vector<int>& numbers)
{

	int n = numbers.size();
	int i, j;

	int max_index1 = -1;
	for(i = 0; i < n; i++)
		if((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
			max_index1 = i;
	
	int max_index2 = -1;
	for(j = 0; j < n; j++)
		if((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))) 
				max_index2 = j;
			
	return ((long long)(numbers[max_index1])) * numbers[max_index2];
	
}

int main()
{
	cout<<"\n";
	int n;
	cin>>n;
	vector<int> numbers(n);
	for(int i = 0; i < n; i++)
	{
		cin>>numbers[i];
	}
	long long result = MaxPairwiseProductFast(numbers);
	cout<<result<<"\n";
	
	return 0;	
}
