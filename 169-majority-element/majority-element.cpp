class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ans;
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]]>(n/2)){
                ans = nums[i];
                break;
            } 
        }
        return ans;
/*
Complexity for this solution
Time: O(n)
Space: O(n)
*/
    }
};
//-------------------
/*
Feedback -
Better Solution: Boyer-Moore Voting Algorithm ⭐⭐⭐⭐⭐

This is the solution interviewers expect.

Idea

The majority element appears more than n/2 times.

Whenever we see a different element, we "cancel" one occurrence of the current candidate.

Since the majority element appears more than all other elements combined, it survives all cancellations.

int majorityElement(vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0)
            candidate = num;

        count += (num == candidate) ? 1 : -1;
    }

    return candidate;
}
Comparison
Approach	          Time	       Space	      Interview Rating
Hash Map (yours)	   O(n)	        O(n)	     ⭐⭐⭐⭐
Boyer-Moore Voting	   O(n)	        O(1)	     ⭐⭐⭐⭐⭐
Interview Tip

If you're asked to solve Majority Element (LeetCode 169):

First mention the hash map approach (O(n), O(n)).
Then say: "Since the problem guarantees a majority element exists, we can optimize the space to O(1) using the Boyer-Moore Voting Algorithm."
Implement Boyer-Moore.

That's the solution most interviewers are looking for.
*/