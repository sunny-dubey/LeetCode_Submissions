class Solution {
public:
    
    bool check(long long mid,long long n, vector<int> &nums)
    {
        long long temp = 0;
        long long res = 0;
        for(int i=0;i<nums.size();i++)
        {
            temp+=nums[i];
            if(temp>=mid)
            {
                temp = temp -mid;
                res++;
            }
                    
        }
        if(res>=n)
            return true;
        else
            return false;
        
        
    }
    
    
    long long maxRunTime(int n, vector<int>& batteries) {
        int size = batteries.size();
        sort(batteries.begin(),batteries.end());
        if(n>size)
            return 0;
        
        long long start = 0;
        long long end = 1e16;
        long long ans = 0;
        long long sum = 0;
        for(auto x:batteries)
            sum+=x;
        while(start<=end)
        {
            long long mid = (end - start)/2 + start;
            if(check(mid,n, batteries))
            {
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return ans;
        
    }
};