class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int n = cost.size();
        int ans = 0;
        for(int i=0;i<n;i+=3)
            ans+=cost[i];
        for(int i=1;i<n;i+=3)
            ans+=cost[i];
        return ans;
        
    }
};