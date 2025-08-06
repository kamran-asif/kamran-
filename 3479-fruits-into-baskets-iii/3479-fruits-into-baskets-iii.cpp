class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
      
    int n = fruits.size();
    if (n == 0) return 0;
    
    // Step 1: Build Segment Tree
    int size = 1;
    while (size < n) size <<= 1; // Finding the nearest power of 2
    vector<int> seg(2 * size, 0);
    
    // Step 2: Fill the leaf nodes with baskets capacity
    for (int i = 0; i < n; ++i) {
        seg[size + i] = baskets[i];
    }
    
    // Step 3: Build the Segment Tree using Max of children
    for (int i = size - 1; i > 0; --i) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
    
    // Step 4: Function to Update the Tree (mark the basket as 0 when fruit placed)
    auto update = [&](int pos) {
        pos += size;
        seg[pos] = 0;
        for (pos >>= 1; pos >= 1; pos >>= 1) {
            seg[pos] = max(seg[2 * pos], seg[2 * pos + 1]);
        }
    };
    
    // Step 5: Function to Query for Leftmost Available Basket with Capacity >= fruit
    auto query = [&](int x) {
        int pos = 1;
        int l = 0, r = size - 1;
        while (pos < size) {
            int mid = (l + r) / 2;
            if (seg[2 * pos] >= x) {
                pos = 2 * pos;
                r = mid;
            } else {
                pos = 2 * pos + 1;
                l = mid + 1;
            }
        }
        if (l < n && seg[pos] >= x) {
            return l; // Return the index of the basket
        }
        return -1; // No basket found
    };
    
    // Step 6: Place Fruits in the Baskets
    int unplaced = 0;
    for (int fruit : fruits) {
        int idx = query(fruit);
        if (idx == -1) {
            // No valid basket found for this fruit
            ++unplaced;
        } else {
            // Place the fruit and mark the basket as used
            update(idx);
        }
    }
    
    // Step 7: Return the unplaced fruit count
    return unplaced;

  
    }
};