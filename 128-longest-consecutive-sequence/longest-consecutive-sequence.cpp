class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int c=0;
        int ans=0;
        int element;
        for(int i=0;i<nums.size();i++){
            if(c==0){
                element = nums[i];
                c++;
                ans= max(ans, c);
            }else{
                if(nums[i]==element){ // duplicates case
                    continue;
                }else if(nums[i]== element + 1){
                    c++;
                    element = nums[i];
                    ans= max(ans, c);
                }else {
                    c=1;
                    element = nums[i];
                }
            }
        }
        return ans;
    }
};

/*
Your solution is correct for the sorting approach, but it can be simplified and made more readable.

Improvement 1: Handle the empty array

Right now, if nums is empty:

sort(nums.begin(), nums.end());

works fine, but your loop never executes and ans remains 0, which is correct. However, it's good practice to make this explicit:

if (nums.empty()) return 0;
Improvement 2: Remove element

You don't need an extra variable. Since the array is sorted, compare with the previous element.

Instead of:

element = nums[i];

just use:

nums[i - 1]
Improvement 3: Start from index 1

The first element already forms a sequence of length 1.

Initialize:

int current = 1;
int longest = 1;

Then iterate from i = 1.

Cleaner solution
int longestConsecutive(vector<int>& nums) {
    if (nums.empty())
        return 0;

    sort(nums.begin(), nums.end());

    int current = 1;
    int longest = 1;

    for (int i = 1; i < nums.size(); i++) {

        if (nums[i] == nums[i - 1])
            continue;

        if (nums[i] == nums[i - 1] + 1)
            current++;
        else
            current = 1;

        longest = max(longest, current);
    }

    return longest;
}
Why is this better?

Your code:

Need:
element
c == 0 check
assign element
update element

New code:

Just compare

nums[i]
↓

nums[i-1]

No extra state to maintain.

Complexity
Operation	Complexity
Sorting	O(n log n)
Traversal	O(n)
Total	O(n log n)
Extra Space	O(1) (ignoring the sort implementation's stack usage)
Interview perspective

If this were an interview, I'd rate it like this:

✅ Correctness: 10/10
✅ Complexity (sorting approach): 10/10
⚠️ Readability: 7/10 (your version) → 9.5/10 (cleaned version)
⭐ Optimality: Not optimal because the expected solution is O(n) using an unordered_set.

A good interview flow is:

Present this sorting solution (O(n log n)).
Mention: "We can do better because sorting is the bottleneck."
Then derive the unordered_set solution with O(n) average time. That's typically what interviewers are hoping to see for LeetCode 128.


*/