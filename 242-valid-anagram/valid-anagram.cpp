class Solution {
public:
    bool isAnagram(string s, string t) {
       int n= s.size();
       int m=t.size();
       if(n!=m) return false;
       unordered_map<char,int> freq1;
        unordered_map<char,int> freq2;
       for(int i=0;i<n;i++)
       {
        freq1[s[i]]++;
        freq2[t[i]]++;
       }
       return freq1 == freq2 ? true: false;
        
    }
};