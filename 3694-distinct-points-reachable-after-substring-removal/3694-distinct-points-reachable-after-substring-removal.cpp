class Solution {
public:
    int distinctPoints(string s, int k) {
      int n = s.size();
        vector<int> prefX(n + 1, 0), prefY(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefX[i + 1] = prefX[i];
            prefY[i + 1] = prefY[i];
            if (s[i] == 'L') prefX[i + 1]--;
            if (s[i] == 'R') prefX[i + 1]++;
            if (s[i] == 'U') prefY[i + 1]++;
            if (s[i] == 'D') prefY[i + 1]--;
        }

       int totalX = prefX[n];
        int totalY = prefY[n];

      
        set<pair<int, int>> distinct;

        for (int i = 0; i <= n - k; ++i) {
            int removeX = prefX[i + k] - prefX[i];
            int removeY = prefY[i + k] - prefY[i];
            int finalX = totalX - removeX;
            int finalY = totalY - removeY;
            distinct.insert({finalX, finalY});
        }

        return distinct.size();
    }
    
    }
    }
