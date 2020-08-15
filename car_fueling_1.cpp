#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    
    int refill = 0, n = stops.size(), ans = 0;
    int diff[n-1];
    for(int i = 0; i < n-1; i++)
    {
    	diff[i] = stops[i+1] - stops[i];
		if( tank < diff[i])
    	{
    		ans = -1;
			return ans;
		}
	}
    int i;
    if( ans == 0 )
	{
		i = 0;
		int sum;
		while(i < n-1)
		{
			sum = 0;
			while((sum < tank) && (i < n-1))
			{
				sum += diff[i];
				i++;
			}
			refill++;
		}
	}
	
	//cout << "\ni: " << i;
	//cout << "\nn: " << n << "\n";
 	
	if( (i == n-1) && (stops[i+1] - stops[i] < tank) )
	{
		refill -= 1;
	}
	    
return refill;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;
	n += 2;
    vector<int> stops(n);
    for (int i = 0; i < n; ++i)
    {
    	if( i == 0)
    	{
    		stops.at(i) = 0;
    	}
    	else if ( i <= n-2 && i > 0)
    	{
    		cin >> stops.at(i);
		}
		else{
        	stops.at(i) = d;
    	}
	}
	
    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
