

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>> nodes;
        dfs(root, 0, 0, nodes);

        sort(nodes.begin(), nodes.end(), [](const auto &a, const auto &b){
            if (get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b); // col
            if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b); // row
            return get<2>(a) < get<2>(b);                             // value
        });

        vector<vector<int>> res;
        bool first = true;
        int curCol = 0;
        for (const auto &t : nodes) {
            int col = get<0>(t);
            int val = get<2>(t);
            if (first || col != curCol) {
                res.emplace_back();
                curCol = col;
                first = false;
            }
            res.back().push_back(val);
        }
        return res;
    }

private:
    void dfs(TreeNode* node, int row, int col, vector<tuple<int,int,int>> &nodes) {
        if (!node) return;
        nodes.emplace_back(col, row, node->val);
        dfs(node->left,  row + 1, col - 1, nodes);
        dfs(node->right, row + 1, col + 1, nodes);
    }
};
