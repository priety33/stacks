class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0;
        int tank=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            tank= tank+ gas[i] -cost[i]; //at any point fuel in tank shouls be >0 to move forward
            if(tank<0)
            {
                total=total+tank; //adding all negative values of tank in total => total will give total negative values of trip
                tank=0;
                start=i+1;
            }
        }
        return (total+tank<0) ? -1:start; // at end, check if value in tank is able to suffice the total negative value of trip
    }
};
