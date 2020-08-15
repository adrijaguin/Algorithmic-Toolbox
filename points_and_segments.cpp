#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <map>
using std::vector;
using std::sort;
using std::string;
using std::cin;
using std::cout;
using std::map;
using std::pair;
using std::iterator;

struct seg
{
	int first;
	string second;
};

struct point
{
	int f;
	int s;
};

/*vector<seg> merge_(vector<seg> arr, int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    /* create temp arrays */
    //vector<seg> L(n1), R(n2); 
    /* Copy data to temp arrays L[] and R[] */
    //for (i = 0; i < m; i++) 
    //
    /*	seg myseg = {arr[i].first, arr[i].second};
    	L.push_back(myseg);
	}
    	
    for (j = m; j < r; j++) 
    {
    	seg myseg = {arr[j].first, arr[j].second};
    	R.push_back(myseg);
	}
	cout << "\n arr: \n";
    for ( int a = l; a < r; a++ )
    {
    	cout << "arr[a].first: " << arr[a].first << " arr[a].second: " << arr[a].second << "\n";
	}*/
    /* Merge the temp arrays back into arr[l..r]*/
    //i = 0; // Initial index of first subarray 
    //j = 0; // Initial index of second subarray 
    //k = l; // Initial index of merged subarray 
    /*while (i < n1 && j < n2) { 
        if ( L[i].first < R[j].first ) { 
            arr[k].first = L[i].first; 
            arr[k].second = L[i].second; 
            i++; 
        } 
        else if ( L[i].first == R[j].first )
        {
        	if ( L[i].second == "left" )
        	{
        		arr[k] = L[i]; 
			}
			else if ( L[i].second == "point" && R[j].second == "right" )
        	{
        		arr[k] = L[i]; 
			}
			i++;
		}
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    }*/ 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    /*while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  */
    /* Copy the remaining elements of R[], if there 
       are any */
    /*while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    }
         cout << "\n arr: \n";
    for ( int a = l; a < r; a++ )
    {
    	cout << "arr[a].first: " << arr[a].first << " arr[a].second: " << arr[a].second << "\n";
	}
    return arr;
} 

vector<seg> mergeSort(vector<seg> arr, int l, int r) 
{ 
  
    if (l < r)
	{ 
		int m = l + (r - l) / 2;*/ 
        //cout << "\nr: " << r;
        //cout << "\nl: " << l << "\tm: " << m;
        //mergeSort(arr, l, m); 
        //cout << "\nm+1: " << m+1 << "\tr: " << r;
        //mergeSort(arr, m+1, r);
        //merge_(arr, l, m, r); 
    //}
    //return arr;
//}

bool comparePoint( point i1, point i2) 
{ 
    return (i1.f < i2.f); 
}

bool compareSeg( seg i1, seg i2) 
{ 
    if ( i1.first < i2.first )
    	return true;
    else if ( i1.first == i2.first && i1.second == "left" )
    {
    	return true;
	}
	else if ( i1.first == i2.first && i2.second == "right" )
    {
    	return true;
	}
	else 
    	return false;
} 

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  int n = starts.size(), m = points.size(), cnt = 0, z = 0, q = 2*n + m;
  vector<int> count(m);
  vector <seg> parray;
  vector <point> dup;
  map<int, int> final;
  map<int, int>::iterator it1;
  vector <point>::iterator it2;

  for( int i = 0; i < m; i++ )
  {
  	point mypoint = {points[i], i};
  	dup.push_back(mypoint); 
  }
  sort(dup.begin(), dup.end(), comparePoint);
  
  for ( int i = 0; i < n; i++ )
  {	
    seg myseg = {starts[i], "left"};
    parray.push_back(myseg);
  }
  
    for ( int i = 0; i < m; i++ )
  {
  	seg myseg = {points[i], "point"};
  	parray.push_back(myseg); 
  }
  
  for ( int i = 0; i < n; i++ )
  {	
    seg myseg = {ends[i], "right"};
    parray.push_back(myseg);
  }
  //mergeSort(parray, 0, q);
  sort(parray.begin(), parray.end(), compareSeg);
  for ( int h = 0; h < q; h++ )
  {
  	if ( parray[h].second == "left" )
  	{
  		cnt++;
	}
	else if ( parray[h].second == "right" )
	{
		cnt--; 
	}
	else if ( parray[h].second == "point" )
	{
		count[z] = cnt;
		z++;
	}
  }
  z = 0;
  it1 = final.begin();
  for ( it2 = dup.begin(); it2 != dup.end(); it2++ )
  {
  	final.insert(pair<int, int>(it2->s, count[z])); 
  	it1++, z++;
  }
  z = 0;
  for ( it1 = final.begin(); it1 != final.end(); it1++ )
  {
  	count[z] = it1->second;
  	z++;
  }
  
  return count;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  int i = 0;
  for ( int i = 0; i < points.size(); i++) {
    for ( int j = 0; j < starts.size(); j++) {
    	if ( starts[j] <= points[i] && points[i] <= ends[j] )
      		cnt[i] = cnt[i] + 1;
      	else
      		cnt[i] = cnt[i] + 0;
      }
    }
  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    cin >> points[i];
  }  
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  for ( int i = 0; i < m; i++ ) {
    cout << cnt[i] << " ";
  }
}
