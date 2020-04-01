#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int stock[n];
	    for(int i=0;i<n;i++) cin>>stock[i];
	    stack<int> s;
	    int next_greater[n]; //calculates next greater on left
	    for(int i=0;i<n;i++)
	    {
	        if(s.empty())
	        {
	            next_greater[i]=-1;
	            s.push(i);
	        }
	        else
	        {
	            while(!s.empty() && stock[s.top()]<=stock[i]) s.pop();
	            next_greater[i]= (s.empty())? -1: s.top();
	            s.push(i);
	        }
	    }
	    int span= INT_MIN;
	    for(int i=0;i<n;i++)
	    {
	        cout<<i-next_greater[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
