class Solution {
public:
    
    int check(int n, vector<int> &nums,vector<int> &dp)
    {
        if(n==0)
            return nums[n];
        if(dp[n]!=-1)
            return dp[n];
        
        int not_pick = check(n-1,nums,dp);
        int pick = nums[n];
        if(n-2>=0)
            pick+=check(n-2,nums,dp);
        
        int ans = max(pick,not_pick);
        return dp[n] = ans;
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n-1;i++)
            a.push_back(nums[i]);
        for(int i=1;i<n;i++)
            b.push_back(nums[i]);
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        int ans = max(check(n-2,a,dp1),check(n-2,b,dp2));
        return ans;
        
    }
};