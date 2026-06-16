#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        long long result = 0;   // current accumulated value
        long long num = 0;      // current number being formed
        int sign = 1;           // +1 or -1

        stack<long long> st;    // stores previous result and sign

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }
            else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }
            else if (c == '(') {
                // Save current context
                st.push(result);
                st.push(sign);

                // Reset for inner expression
                result = 0;
                sign = 1;
                num = 0;
            }
            else if (c == ')') {
                // Finish current number inside parentheses
                result += sign * num;
                num = 0;

                // Restore sign and previous result
                int prevSign = st.top(); st.pop();
                long long prevResult = st.top(); st.pop();

                result = prevResult + prevSign * result;
            }
            // ignore spaces
        }

        // Add the last pending number
        result += sign * num;

        return (int)result;
    }
};