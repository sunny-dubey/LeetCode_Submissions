class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = 0;
        int costSum = 0;
        for(auto x:gas)
            gasSum+=x;
        for(auto x:cost)
            costSum+=x;
        if(gasSum < costSum)
            return -1;
        
        int current = 0;
        int start = 0;
        int n = gas.size();
        
        for(int i=0;i<n;i++)
        {
            if(current < 0)
            {
                start = i;
                current = 0;
            }
            current += (gas[i] - cost[i]);
            
        }
        return start;
        
    }
};