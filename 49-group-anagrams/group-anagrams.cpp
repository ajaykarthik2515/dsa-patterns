class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s: strs){
            string key="";
            int freq[26]={0};
            for(char c:s){
                freq[c-'a']++;
            }
            for(int i=0;i<26;i++){
                key+="#";
                key+=to_string(freq[i]);
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &[key,anagrams]: mp){
            res.push_back(anagrams);
        }
        return res;
    }
/*
complexities for this solution 
| Complexity | Value              |
| ---------- | ------------------ |
| **Time**   | **O(n × k log k)** |
| **Space**  | **O(n × k)**       |
    */
};