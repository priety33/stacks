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
                left[i]=-1; //if no smaller element on left, take smallest index on left =-1
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
                right[i]=n; //if no smaller element on right, take smallest index on right= n (end of array)
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


// can also be done using single stack- more efficient (coding blocks video)
           int area;
            stack<int> s;
            for(int j=0;j<m;j++)
            {
                if(s.empty() || height[j]>=height[s.top()]) s.push(j);
                else
                {
                    while(!s.empty() && height[s.top()]>height[j])
                    {
                        int curht=height[s.top()];
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
                        int curht=height[s.top()];
                        s.pop();
                        if(s.empty())
                        {
                            area=curht*m; //m is the index, as all the elements left now int the stack, do not have any smaller element to their right, otherwise they would have been popped earlier
                        }
                        else
                        {
                            area=curht*(m-s.top()-1);
                        }
                        ans=max(ans,area);
                }
             return ans;
