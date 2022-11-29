class Solution {
public:
    
    int check(int n, vector<int> &nums,vector<int> &dp)
    {
        if(n==0)
            return nums[0];
        
        if(dp[n]!=-1)
            return dp[n];
        
        
        
        int not_pick = check(n-1,nums,dp);
        int pick = nums[n];
        if(n-2>=0)
            pick += check(n-2,nums,dp);
        
        int ans = max(pick,not_pick);
        return dp[n]  = ans;
        
        
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        
        return check(nums.size()-1,nums,dp);
        
    }
};