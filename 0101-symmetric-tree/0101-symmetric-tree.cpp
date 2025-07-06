class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //root ko do bar bhjke dono sides compare krnge
        return isMirror(root, root);
    }
//dono structure ko mirror wise compare krnge
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        //agr dono nodes null hain symmetric h
        if (!t1 && !t2) return true;
        //agr ek null h or dusra nhi,assymetric
        if (!t1 || !t2) return false;
        //value match nhi kre to assymetric
        if (t1->val != t2->val) return false;
        //recursively left of t1 vs right of t2 and right of t1 vs left of t2
        return isMirror(t1->left,  t2->right)
            && isMirror(t1->right, t2->left);
    }
//iterative approach using queue(bfs style)
    bool isSymmetricIter(TreeNode* root) {
        //empty tree symmetric hota h
        if (!root) return true;
        queue<TreeNode*> q;
        //root k immediate children ko pair m push kro
        q.push(root->left);
        q.push(root->right);
        while (!q.empty()) {
            TreeNode* t1 = q.front(); q.pop();
            TreeNode* t2 = q.front(); q.pop();
            //dono null ho to nxt pr chle jao
            if (!t1 && !t2) continue;
            //agr ek null ho value mismatch to false
            if (!t1 || !t2) return false;
            if (t1->val != t2->val) return false;
            //nxt lvl m outer-inner pairs push kro
            //outer:t1->leftvs t2->right
            q.push(t1->left);
            q.push(t2->right);
            //inner:t1->right vs t2->left
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};
