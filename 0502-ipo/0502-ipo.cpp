class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        // Step 1: har project ko {required_capital, profit} ke form mein store kar rahe hain
        vector<pair<long long,long long>> projects;
        for (int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Step 2: projects ko required capital ke increasing order mein sort kar diya        // Taaki hum easily dekh sakein kaunse projects current capital se affordable hain
        sort(projects.begin(), projects.end());

        // Step 3: max heap banaya profits ke liye
        // Isme hamesha sabse bada profit top par rahega
        priority_queue<int> pq;

        // i pointer batata hai sorted list mein next kaunsa project abhi check karna hai
        int i = 0;

        // Step 4: maximum k projects tak choose kar sakte hain
        for (int round = 0; round < k; round++) {

            // जितने projects current capital w se affordable hain, unke profits heap mein daal do
            while (i < n && projects[i].first <= w) {
                pq.push(projects[i].second); // profit add kiya
                i++;                        // next project par move
            }

            // Agar koi bhi affordable project nahi hai, toh aur aage nahi ja sakte
            if (pq.empty()) break;

            // Heap ke top par sabse zyada profit wala project hai
            // Us project ko choose karke capital mein add kar diya
            w += pq.top();
            pq.pop(); // project use ho gaya, toh remove kar diya
        }

        // Final maximized capital return kar do
        return w;
    }
};
