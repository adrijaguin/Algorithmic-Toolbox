#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<double> values) {
  double value = 0.0000;
  int n = values.size(), full_weights = 0;
  
  vector<int> unit(n);
  
  for (int i = 0; i < n; i++) {
  	full_weights += weights[i];
  }
  
  for (int i = 0; i < n; i++) {
    unit[i] = ( values[i] / weights[i] );
  }
  //sort(unit.begin(), unit.end());
  
  	vector<int> :: iterator it;
  	
  	if( capacity > full_weights )
  	{
  		for (int i = 0; i < n; i++) {
  			value += values[i];
  		}
	}
	else{
		
		while( capacity != 0){
			it = max_element(unit.begin(), unit.end());
			
			for(int i = 0; i < n; i++)
			{
				if(unit[i] == *it)
				{
					if( capacity >= weights[i] )
					{
						capacity = capacity - weights[i];
						value += values[i];
						//values[i] = 0;
						//weights[i] = 0;
						unit[i] = 0;
					}
		
  					else if(capacity < weights[i])
  					{
  						double v = values[i], w = weights[i];
  						value += ( (v * capacity) / w );
  						capacity = 0;
					}
				}	
			}
	
		}
	}
  return value;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<double> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
