class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        const int MOD = 1e9 + 7;//modulo value taki answer bda na ho
        vector<long long> left(n), right(n);//hr element k right or left contribution store krne k liy
        stack<int> st;//monotonic stck bnane k liy rkh rhe h
//left contribution niklne k loop
        for (int i = 0; i < n; i++) {
            //jb tk stck khaali na ho jata aur top element crrnt s bda h,pop kro
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            //agr stack khali hai to left contribution i+1 hoga,warna distance from top of stack
            left[i] = st.empty() ? (i + 1) : (i - st.top());
            //current index ko stack m daldo
            st.push(i);
        }
//stck ko clear kr rhe hain taaki right k liy use kr ske
        while (!st.empty()) st.pop();
//right contribution nikalne k loop(right to left)
        for (int i = n - 1; i >= 0; i--) {
            //jb tk stck khali nhi hojata aur top element crrnt s bda ya brabr h pop kro
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            //agr stck khaali h to right contribution n-i hoga,wrna top s dstnce
            right[i] = st.empty() ? (n - i) : (st.top() - i);
            //crrnt index ko stck m daal do
            st.push(i);
        }
//final answer store krne k liy variable
        long long ans = 0;
        //hr element k contribution clculate krke final answr  m jod rh h
        for (int i = 0; i < n; i++) {
            //elment*uska leftcntribution*uska right cntributn)%MOD
            ans = (ans + (long long)arr[i] * left[i] % MOD * right[i]) % MOD;
        }
        return (int)ans;//final answr ko int m cnvrt kr rhe hain
    }
};
