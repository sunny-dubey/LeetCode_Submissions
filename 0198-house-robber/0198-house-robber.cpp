class Solution {
public:
    
    int check(int n, vector<int> &nums, vector<int> &dp)
    {
        if(n==0)
            return nums[0];
        
        if(dp[n]!=-1)
            return dp[n];
        
        int left = 0;
        
        if(n-2>=0)
           left = check(n-2,nums,dp);;
        int right = check(n-1,nums,dp);
        
        return dp[n] = max(left + nums[n],right);
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> dp(n+1,-1);
        
        return check(n-1,nums,dp);
        
    }
};