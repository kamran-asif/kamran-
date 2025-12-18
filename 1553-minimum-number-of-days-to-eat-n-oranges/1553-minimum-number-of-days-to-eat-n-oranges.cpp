// f(n): minimum days to eat n oranges
// f(0)=0, f(1)=1
// for n>1:
//  - make n divisible by 2 using (n%2) single eats, then 1 day for n/2 → f(n/2)
//  - make n divisible by 3 using (n%3) single eats, then 1 day for 2*(n/3) → f(n/3)
// f(n) = 1 + min((n%2) + f(n/2), (n%3) + f(n/3))
// memoization avoids recomputation for large n (≤ 2e9)

class Solution {
private:
    unordered_map<long long,int> memo;
    int dfs(long long n) {
        if (n <= 1) return (int)n;       
        if (memo.count(n)) return memo[n];
        long long eatToDiv2 = n % 2;
        int daysVia2 = (int)eatToDiv2 + 1 + dfs(n / 2);
        long long eatToDiv3 = n % 3;
        int daysVia3 = (int)eatToDiv3 + 1 + dfs(n / 3);

        int ans = min(daysVia2, daysVia3); 
        memo[n] = ans;                    
        return ans;
    }

public:
    int minDays(int n) {
        memo.clear();
        return dfs(n);
    }
};
