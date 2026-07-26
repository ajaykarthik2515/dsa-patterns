class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(auto s: strs){
            string temp=s;
            sort(s.begin(), s.end());
            mp[s].push_back(temp);
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
/*
Feedback -
Optimization: Use Character Frequency as the Key

Instead of sorting:

eat -> aet
tea -> aet
ate -> aet

Count the frequency of each letter.

eat

a -> 1
b -> 0
c -> 0
d -> 0
e -> 1
...
t -> 1
...
z -> 0

Every anagram produces the same frequency array.

Step 1: Build a frequency array

For every string

int freq[26] = {0};

for (char c : s)
    freq[c - 'a']++;

For "eat"

[1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0]

For "tea"

[1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0]

Exactly the same.

Step 2: Convert it into a string key

One common way is:

string key;

for (int i = 0; i < 26; i++) {
    key += "#";
    key += to_string(freq[i]);
}

For "eat" the key becomes something like:

#1#0#0#0#1#0#0#...#1...

Using # avoids ambiguity. For example:

"11" could mean 1,1 or 11.
"#1#1" is always unambiguous.

Now use this key:

mp[key].push_back(s);
Complexity

For each string:

Count characters
for(char c : s)

Runs k times.

O(k)
Build key

Always 26 iterations.

O(26)

Since 26 is constant,

O(1)

Total per string

O(k)

For n strings

O(n × k)
Comparison
Your solution
eat
 ↓
sort
 ↓
aet

Time:

O(k log k)
Optimized solution
eat
 ↓
count letters
 ↓
frequency key

Time:

O(k)
Overall Comparison
Approach	        Time	            Space
Sort each string	O(n × k log k)	    O(n × k)
Frequency count	    O(n × k)	        O(n × k)

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

Which should you use in interviews?
Sorting approach: Easier to explain and implement. It's accepted and often sufficient.
Frequency-count approach: Mention it as an optimization when the problem guarantees a fixed alphabet (e.g., lowercase English letters). It reduces the per-string work from O(k log k) to O(k), which is the optimal asymptotic solution for this problem.
*/