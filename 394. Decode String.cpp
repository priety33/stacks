class Solution {
public:
    string decodeString(string s) {
        stack<string> p;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='[') //indicates a number will be encountered before this now
            {
                int num=0;
                i--;
                int k=0;
                while(i>=0 && s[i]-'0'>=0 && s[i]-'0'<=9)
                {
                    num=pow(10,k)*(s[i]-'0')+num;
                    i--;
                    k++;
                }
                if(i>0) i++;
                string b="";
                while(!p.empty() && p.top()!="]")
                {
                    b=b+p.top();
                    p.pop();
                }
                p.pop();
                string w="";
                for(int j=0;j<num;j++) w=w+b;
                p.push(w);
            }
            else
            {
                string k(1,s[i]);
                p.push(k);
            }
        }
        string sol;
        while(!p.empty())
        {
            sol=sol+p.top();
            p.pop();
        }
        return sol;
    }
};
