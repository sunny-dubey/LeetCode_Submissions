class Solution {
public:
    string capitalizeTitle(string title) {
         vector<string> v;
        int n = title.size();
        int j = 0;
        for(int i=0;i<=n;i++)
        {
            if(title[i]==32 or i==title.size())
            {
                string s="";
                for(;j<i;j++)
                {
                    s+=title[j];
                    
                }
                v.push_back(s);
                j = i+1;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i].size()>2)
            {
                if(v[i][0]>=97 and v[i][0]<=122)
                    v[i][0]-=32;
                for(int j=1;j<v[i].size();j++)
                {
                    if(v[i][j]>=65 and v[i][j]<=90)
                        v[i][j]+=32;
                }
            }
            else
            {
               for(int j=0;j<v[i].size();j++)
                {
                    if(v[i][j]>=65 and v[i][j]<=90)
                        v[i][j]+=32;
                }
            }
        }
        string ans;
        for(auto x:v)
        {
           ans+=x;
         ans+=32;
        }
        ans.pop_back();
        return ans;
        
        
    }
};