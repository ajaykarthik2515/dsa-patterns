class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int ans = 0;
        int vowelCount = 0;
        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) {
                vowelCount++;
            }
            if (i >= k) {
                if (isVowel(s[i-k])) {
                    vowelCount--;
                }
            }
            if (i >= k - 1) {
                ans = max(ans, vowelCount);
            }
        }
        return ans;
    }
};