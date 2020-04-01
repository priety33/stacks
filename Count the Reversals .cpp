#include <stack>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    string str; cin>>str;
	    if(str.size()%2) //odd length parenthesis can never be balanced
	    {
	        cout<<"-1"<<endl;
	        continue;
	    }
	    stack<char> s;
	    int i;
	    for(i=0;i<str.size();i++)
	    {
	        if(str[i]=='{') s.push(str[i]);
	        else
	        {
	            if(!s.empty() && s.top()=='{') s.pop();
	            else s.push(str[i]);
	        }
	    }
	    int a=s.size();
	    i=0;
	   while(!s.empty() && s.top()=='{')
	   {
	       s.pop(); //all opening braces will be at top, if any.
	       i++;     //i will give us the count of opening braces -> at end a-i will give us count of closing braces, because they will be present at bottom of stack, after opening ones
	   }
	    if(i%2==0)
	    {
	        cout<<(i/2)+((a-i)/2)<<endl;
	    }
	    else
	    {
	        cout<<((i-1)/2)+((a-i-1)/2)+2<<endl; //removing 1 from both types, and counting their length as evens, then adding 2 for the two braces removed
	    }
	}
}
