class Solution {
public:
    string convertToTitle(int columnNumber) {
       string ans = "";
       while (columnNumber > 0) {
           // excl clmn1 s strt hote hain, isly phle 1 subtract krke 0-based index bna rhe hain
           columnNumber--;
           // remainder btata h ki crrnt posn pe kaunsa lttr ayega (0->A, 25->Z)
           int rem = columnNumber % 26;
           ans.push_back(char('A' + rem));  // crrspndng lttr strng k end m add kro
           // ab no ko 26 s divide krke aage k digits prcss krnge
           columnNumber /= 26;
       }
       // hm lettrs rvrse order m add kye h, isliy final string ko ulta krna pdega
       reverse(ans.begin(), ans.end());
       return ans;
    }
};
