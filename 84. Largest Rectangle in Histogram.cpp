class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        int left[n], right[n];
        int area=INT_MIN;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty()) 
            {
                left[i]=-1;
                s.push(i);
            }
            else 
            {
                while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
                left[i]= (s.empty())? -1: s.top();
                s.push(i);
            }
        }
        stack<int> p;
        for(int i=n-1;i>=0;i--)
        {
            if(p.empty()) 
            {
                right[i]=n;
                p.push(i);
            }
            else 
            {
                while(!p.empty() && heights[p.top()]>=heights[i]) p.pop();
                right[i]= (p.empty())? n: p.top();
                p.push(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            area=max(area,heights[i]*(right[i]-left[i]-1));
        }
        return area;
    }
};
