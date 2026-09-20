/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> ansList = new ArrayList<>();
        dfs(root, targetSum, 0, ansList, new ArrayList<>());
        return ansList;
    }

    private void dfs(TreeNode root, int targetSum, int currSum, List<List<Integer>> ansList, List<Integer> currList) {
        if (root == null) return;

        currList.add(root.val);

        if (root.left == null && root.right == null) {
            if (currSum+root.val == targetSum) {
                ansList.add(new ArrayList<>(currList));
                currList.remove(currList.size()-1); //backtrack
                return;
            } else {
                currList.remove(currList.size()-1);
                return;
            }
        }

        dfs(root.left, targetSum, currSum+root.val, ansList, currList);
        dfs(root.right, targetSum, currSum+root.val, ansList, currList);

        currList.remove(currList.size()-1); //backtrack
    }
}