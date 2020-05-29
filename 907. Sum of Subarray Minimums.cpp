//Dp gives stack overflow for larger inputs

/*
res = sum(A[i] * f(i))
where f(i) is the number of subarrays, in which A[i] is the minimum.
f(i)= number of subarrays ending on A[i] (left) * number of subarrays starting from A[i] (right)

window[i][0]= next greater element on left
window[i][1]= next greater element on right

i- window[i][0] equals to the number of subarray ending with A[i]

window[i][1]-i equals to the number of subarray starting with A[i],
*/

class Solution {
public:
    #define mod 1000000007
    
    int sumSubarrayMins(vector<int>& A) {
        long long sum=0;
        long long n=A.size();
        vector<vector<int>> window(n, vector<int>(2));
        for(int i=0; i<n; i++) {
            window[i][0]=-1;
            window[i][1]=n;
        }
        stack<int> left;
        for(int i=0; i<n; i++) {
            if(left.empty()) left.push(i);
            else if(A[left.top()]>=A[i]) {
                while(!left.empty() && A[left.top()]> A[i]) {
                    window[left.top()][1]=i;
                    left.pop();
                }
                if(!left.empty()) window[i][0]=left.top();
                left.push(i);
            }
            else {
                window[i][0]=left.top();
                left.push(i);
            }
        }
        for(int i=0; i<n; i++) {
            int left= i-window[i][0];
            int right= window[i][1]-i;
            sum+=((left*right)*A[i])%mod;
        }
        return sum%mod;
    }
};
