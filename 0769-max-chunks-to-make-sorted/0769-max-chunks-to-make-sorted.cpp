class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSoFar = 0;   // stores the maximum value encountered so far
        int chunks = 0;     // counts the number of valid chunks

        for (int i = 0; i < arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);  // update maximum seen so far

            // if max value equals current index,
            // we can safely end a chunk here
            if (maxSoFar == i) {
                chunks++;
            }
        }

        return chunks;  
    }
};
