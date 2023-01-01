class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        // getting all string
        int j = 0;
        for(int i=0;i<=s.size();i++)
        {
            if(s[i]==32 or i==s.size())
            {
                string x ="";
                for(;j<i;j++)
                {
                    x+=s[j];
                    
                }
                j=i+1;
                v.push_back(x);
            }
        }
        if(v.size()!=pattern.size())
            return false;
        unordered_map<char,string> mp1;
        unordered_map<string,char> mp2;
        
        for(int i=0;i<v.size();i++)
        {
            if(mp1.find(pattern[i])!=mp1.end() and mp1[pattern[i]]!=v[i]) 
                return false;
            else if(mp2.find(v[i])!=mp2.end() and mp2[v[i]]!=pattern[i])
                return false;
            mp1[pattern[i]] = v[i];
            mp2[v[i]] = pattern[i];
        }
           return true;
        
    }
};