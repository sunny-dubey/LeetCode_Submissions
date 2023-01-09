class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0)
            return 0;
        vector<int> c;
        bool negative = false;
        if(num<0)
        {
            negative = true;
            num*=-1;
        }
        while(num>0)
        {
            int x = num%10;
            c.push_back(x);
            num/=10;
        }
        sort(c.begin(),c.end());
        if(c[0]==0)
        {
            if(negative)
            {
                sort(c.begin(),c.end(),greater<int>());
            }
            else
            {
                int idx = 0;
               for(int i=0;i<c.size();i++)
               {
                   if(c[i]!=0)
                   {
                       idx = i;
                       break;
                   }
               }
                int x = c[idx];
                c[idx]=0;
                c[0]=x;
            }
        }
        else
        {
            if(negative)
            {
                sort(c.begin(),c.end(),greater<int>());
            }
        }
        long long ans = 0;
        long long x = 1;
        for(int i=c.size()-1;i>=0;i--)
        {
            ans+=x*c[i];
            x*=10;
        }
        if(negative)
            ans*=-1;
        return ans;
    }
};