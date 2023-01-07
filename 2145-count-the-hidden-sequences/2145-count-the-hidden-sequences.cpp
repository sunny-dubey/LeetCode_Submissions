class Solution {
public:
    int numberOfArrays(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> prefix(n+1);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = nums[i] + prefix[i-1];
        
        long long low = 1e5;
        long long high = -1e5;
        for(auto x:prefix)
        {
            low = min(low,x);
            high = max(high,x);
        }
        int x = lower - low;
        int y = upper - high;
        int ans = 0;
        if(x<=y)
            ans = y-x+1;
        return ans;
    }
};