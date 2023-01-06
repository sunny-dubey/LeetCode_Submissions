class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // sliing window 
        int k = 0;
        for(auto x:nums)
            if(x==1)
                k++;
        int ans =0;
        for(int i=0;i<k;i++)
        {
            
            if(nums[i]==0)
            {
                ans++;
            }
        }
        vector<int> res;
        res.push_back(ans);
        int n = nums.size();
        for(int i=0;i<n;i++)
            nums.push_back(nums[i]);
        cout<<nums.size();
        for(int i=k;i<nums.size();i++)
        {

            if(nums[i-k]==0)
                ans--;
            if(nums[i]==0)
                ans++;
           res.push_back(ans);
        }
        int x = res[0];
        for(int i=1;i<res.size();i++)
            x = min(x, res[i]);
        return x;
    }
    
};