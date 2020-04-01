class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n= matrix.size();
        if(n==0) return 0;
        int m= matrix[0].size();
        
        //stores continuous heights of 1 above it-> will act as height of histogram
        int rect[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || matrix[i][j]=='0') rect[i][j]=matrix[i][j]-'0';
                else
                {
                    rect[i][j]=rect[i-1][j]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            //for each row, considering current row as base of histogram, calculate maximum area of histogram above it.
            int area;
            stack<int> s;
            for(int j=0;j<m;j++)
            {
                if(s.empty() || rect[i][j]>=rect[i][s.top()]) s.push(j);
                else
                {
                    while(!s.empty() && rect[i][s.top()]>rect[i][j])
                    {
                        int curht=rect[i][s.top()];
                        s.pop();
                        if(s.empty())
                        {
                            area=curht*j;
                        }
                        else
                        {
                            area=curht*(j-s.top()-1);
                        }
                        ans=max(ans,area);
                    }
                    s.push(j);
                }
            }
            while(!s.empty())
                {
                        int area;
                        int curht=rect[i][s.top()];
                        s.pop();
                        if(s.empty())
                        {
                            area=curht*m;
                        }
                        else
                        {
                            area=curht*(m-s.top()-1);
                        }
                        ans=max(ans,area);
                }
        }
        return ans;
    }
};
