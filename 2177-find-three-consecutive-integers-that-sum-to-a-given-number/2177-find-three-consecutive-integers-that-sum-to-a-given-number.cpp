class Solution {
public:
    vector<long long> sumOfThree(long long n) {
        
        vector<long long> ans(3);
        ans[0]= n/3 -1;
        ans[1] = n/3;
        ans[2] =n/3 + 1;
        vector<long long> d;
        if(ans[0] + ans[1] + ans[2] == n)
            return ans;
        else
            return d;
    }
};