class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i] = nums[i]+prefix[i-1];
        
        int ans = 0;
        
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
           ans+=mp[(prefix[i]%k + k)%k];
           mp[(prefix[i]%k + k)%k]++;
        }
          
        
        return ans;
    }
};