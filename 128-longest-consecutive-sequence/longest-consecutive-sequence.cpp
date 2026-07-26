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
That's exactly the right interview strategy. For LeetCode 128 - Longest Consecutive Sequence, here's how I'd approach it in an interview.

Step 1: State the sorting solution first

Say something like:

"A straightforward approach is to sort the array first. After sorting, consecutive numbers become adjacent, so we can scan once to find the longest streak while skipping duplicates."

Then write something similar to your solution.

Complexity
Time: O(n log n)
Space: O(1) extra (ignoring the sort implementation's stack usage)

Then immediately add:

"However, the problem asks for an O(n) solution, so we can improve it using a hash set."

This shows the interviewer you recognized the optimization opportunity.

Step 2: Think about why sorting is unnecessary

Ask yourself:

Do I really need the numbers to be ordered?

Not really.

You only need to answer questions like:

Is 5 present?
Is 6 present?
Is 7 present?

A hash set can answer these in O(1) average time.

Step 3: Use an unordered_set

Put every number into a set.

unordered_set<int> st(nums.begin(), nums.end());

Now you can check if any number exists in constant average time.

Step 4: The key observation ⭐⭐⭐⭐⭐

This is the insight interviewers want.

Consider:

100 4 200 1 3 2

The sequence is

1 2 3 4

Should you start counting from 2?

No.

Because 1 is before it.

Should you start from 3?

No.

Because 2 is before it.

Should you start from 4?

No.

Because 3 is before it.

Only 1 should start a sequence.

General rule

A number starts a sequence only if

num - 1

is not present.

if (!st.count(num - 1))

Now you've found the beginning of a sequence.

Step 5: Expand forward

Once you know it's the start,

1

↓

2?

↓

3?

↓

4?

↓

5?

Keep checking

num + 1
num + 2
...

until the sequence ends.

Count its length.

Update the answer.

Example
nums = [100,4,200,1,3,2]

Set:

{100,4,200,1,3,2}

Iterate:

100
99 doesn't exist
Start

Length = 1
4

3 exists

Don't start
200

199 doesn't exist

Start

Length = 1
1

0 doesn't exist

Start

2 exists

3 exists

4 exists

5 doesn't exist

Length = 4

Answer = 4

Complexity

Each number is expanded at most once.

Although there's a nested loop,

for(...)
{
    while(...)
}

the total work is still O(n).

Why?

Because once a number has been visited while expanding a sequence, it won't be expanded again from another starting point.

Final code
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int longest = 0;

    for (int num : st) {

        // Only start from the beginning of a sequence
        if (!st.count(num - 1)) {

            int current = num;
            int length = 1;

            while (st.count(current + 1)) {
                current++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    return longest;
}
What the interviewer is evaluating

They aren't just looking for the code. They want to see if you discover the key optimization:

Don't start counting from every number—only start from numbers that have no predecessor.

Without this observation, you'd end up repeatedly traversing the same sequences.

The interview flow I'd recommend
Brute Force (if asked):
For each number, keep searching for num + 1, num + 2, ...
Time: O(n²)
Better Solution (your current one):
Sort + single scan
Time: O(n log n)
Optimal Solution:
unordered_set
Only start from sequence beginnings (num - 1 not present)
Time: O(n) average

This progression demonstrates both problem-solving ability and optimization skills, which is exactly what interviewers like to see.

*/