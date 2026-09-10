class Solution {
public:
    string convertBinary(int n) {
        if (n == 0)
            return "0";
        string res;
        while (n > 0) {
            if (n % 2 == 1)
                res += '1';
            else
                res += '0';
            n = n / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    string convertDateToBinary(string date) {
        string ans = "";
        string temp = "";
        for (int i = 0; i <= date.size(); i++) {
            if (i == date.size() || date[i] == '-') {
                ans += convertBinary(stoi(temp));
                if(i!=date.size())ans += '-';
                temp = "";
            } else {
                temp += date[i];
            }
        }
        
        return ans;
    }
};