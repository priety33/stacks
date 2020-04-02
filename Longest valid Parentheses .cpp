//O(n)space- stack, O(n)time

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    string s; cin>>s;
	    stack<pair<char,int>> st;
	    st.push({'e',-1});
	    int len=0;
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='(') st.push({s[i],i});
	        else
	        {
	            if(st.top().first=='(')
	            {
	                st.pop();
	                len=max(len,i-st.top().second);
	            }
	            else st.push({s[i],i});
	        }
	    }
	    cout<<len<<endl;
	}
	return 0;
}

//o(1)space, o(n)time
/*In this approach, we make use of two counters left and right. 
First, we start traversing the string from the left towards the right and for every ‘(’ encountered, 
we increment the left counter and for every ‘)’ encountered, we increment the right counter.
Whenever left becomes equal to right, we calculate the length of the current valid string and keep track
of maximum length substring found so far. If right>left we reset left and right to 0.

Next, we start traversing the string from right to left and similar procedure is applied. here we reset when left>right. */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    string s; cin>>s;
	    int left=0, right=0;
	    int len=0;
      //left to right
	    for(int i=0;i<s.length();i++)
	    {
	        if(s[i]=='(') left++;
	        else right++;
	        
	        if(left==right) len=max(len,2*left);
	        if(left<right)
	        {
	            left=0;
	            right=0;
	        }
	    }
	    left=0, right=0;
      //right to left
	    for(int i=s.length()-1;i>=0;i--)
	    {
	        if(s[i]=='(') left++;
	        else right++;
	        
	        if(left==right) len=max(len, 2*left);
	        if(left>right)
	        {
	            left=0;
	            right=0;
	        }
	    }
	    cout<<len<<endl;
	}
	return 0;
}
