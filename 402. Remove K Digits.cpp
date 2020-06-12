class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> p;
        string s=num;
        for(int i=0;i<s.length() && k>=0;i++)
        {
            while(!p.empty() && p.top()>s[i]-'0' && k>0)
            {
                p.pop();
                k--;
            }
            p.push(s[i]-'0');
        }
        while(!p.empty() && k--) p.pop();
        string j="";
        if(p.empty()) return "0";
        while(!p.empty()) 
        {
            j=to_string(p.top())+j;
            p.pop();
        }
        j.erase(0, min(j.find_first_not_of('0'), j.size()-1));
        return j;
    }
};
