

class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (parent[leftChild[i]] != -1) return false;
                parent[leftChild[i]] = i;
            }
            if (rightChild[i] != -1) {
                if (parent[rightChild[i]] != -1) return false;
                parent[rightChild[i]] = i;
            }
        }

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) {
                if (root != -1) return false; 
                root = i;
            }
        }
        if (root == -1) return false;

        vector<bool> visited(n, false);
        stack<int> st; 
        st.push(root);
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            if (visited[node]) continue;
            visited[node] = true;
            if (leftChild[node] != -1) st.push(leftChild[node]);
            if (rightChild[node] != -1) st.push(rightChild[node]);
        }

        for (bool v : visited) {
            if (!v) return false;
        }

        return true;
    }
};
