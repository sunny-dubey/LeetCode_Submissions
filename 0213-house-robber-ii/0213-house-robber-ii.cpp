class Solution {
public:
    
    int check(vector<int> &a)
    {
        int n = a.size();
        int prev1 = a[0];
        int prev2 = 0;
        
        for(int i=1;i<n;i++)
        {
            int take = a[i];
            if(i-2>=0)
                take+=prev2;
            int not_take = prev1;
            
            int curr =  max(take,not_take);
            
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> temp1,temp2;
        
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                temp1.push_back(nums[i]);
            if(i!=n-1)
                temp2.push_back(nums[i]);
        }
        return max(check(temp1),check(temp2));
    }
};