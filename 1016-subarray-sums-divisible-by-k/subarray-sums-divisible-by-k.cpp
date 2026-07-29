class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int prefixSum=0;
        int ans=0;

        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            int rem=prefixSum%k;
            if (rem < 0)
                rem += k; // very very imp we have to store all the remainder in non-neagrive only detailed explaination in the comment below
            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
        
    }
};

/*
The important question is not really "why make negative remainder positive?" It's why negative remainders can break our hash-map grouping.

First, what are we trying to do?

In this problem, we use this property:

If two prefix sums have the same remainder when divided by k, their difference is divisible by k.

For example, k = 5:

12 % 5 = 2
7  % 5 = 2

12 - 7 = 5
5 % 5 = 0

So we put both prefix sums into the same map bucket:

remainder 2 → frequency

That's the whole idea.

Now look at negative numbers

Suppose:

prefixSum1 = -2
prefixSum2 = 3
k = 5

Their difference is:

3 - (-2) = 5

which is divisible by 5. So these two prefix sums must belong to the same remainder group.

Mathematically:

-2 = (-1 × 5) + 3
 3 = ( 0 × 5) + 3

So both can be viewed as having remainder 3.

But C++ does this:

-2 % 5   // -2
 3 % 5   //  3

Now your map sees:

-2 → one group
 3 → another group

❌ It thinks they're different, even though their difference is divisible by 5.

That's the problem we're fixing.

How does this formula fix it?
((prefixSum % k) + k) % k

Take:

prefixSum = -2
k = 5

Step 1:

-2 % 5 = -2

Step 2: Add k:

-2 + 5 = 3

Step 3: % k again:

3 % 5 = 3

So:

-2 → remainder 3

Now compare with positive 3:

3 % 5 = 3

Both correctly become:

-2 → 3
 3 → 3

and therefore go into the same hash-map bucket. ✅

Why do % k again after adding k?

Because what if the original remainder was already positive?

Suppose:

prefixSum = 3
k = 5

First:

3 % 5 = 3

Add k:

3 + 5 = 8

But 8 isn't a valid normalized remainder for division by 5. We want 0...4.

So:

8 % 5 = 3

That's why we do:

((prefixSum % k) + k) % k

It guarantees:

0 <= remainder < k
Easy way to remember

Don't memorize the formula first. Remember the goal:

I want equivalent prefix sums to always have the same non-negative remainder key.

Then:

int rem = prefixSum % k;

if (rem < 0)
    rem += k;

I actually find this version easier to understand:

prefixSum += nums[i];

int rem = prefixSum % k;

if (rem < 0)
    rem += k;

ans += mp[rem];
mp[rem]++;

It's equivalent to:

int rem = ((prefixSum % k) + k) % k;

For interviews, I'd use the if (rem < 0) rem += k; version if it feels more natural to you.
*/
