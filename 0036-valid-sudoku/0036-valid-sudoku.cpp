class Solution {
public://hash set quesn where we store 3 variable wrna baki m 2 variable hi store krta h
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);
     for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char num = board[i][j];
                if(num == '.') {
                    continue;
                }
                int boxindex = (i / 3) * 3 + (j / 3);
                if(rows[i].count(num) || cols[j].count(num) || boxes[boxindex].count(num)) { //.count(num) does if the no is existed or not //if exist mean duplicate has found so return flse
                    return false;
                }
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxindex].insert(num);
            }
        }
        return true;
    }
};
