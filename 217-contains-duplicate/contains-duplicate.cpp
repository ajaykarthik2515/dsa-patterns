class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i : nums) {
            if (freq[i] > 0)
                return true;
            freq[i]++;
        }
        return false;
    }
};

/*
Feedback -unordered_set (Best)
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.count(num))
            return true;
        seen.insert(num);
    }

    return false;
}
Why?

A set is exactly what you need:

Have I seen this number before? ✅
No need to store frequencies.

Complexity

Time: O(n) average
Space: O(n)
*/