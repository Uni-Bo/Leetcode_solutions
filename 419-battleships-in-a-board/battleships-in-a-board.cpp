class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        int n=board.size();
        int m=board[0].size();

        if( i<0 || i>=n || j<0 || j>=m || board[i][j]=='.') return;

        board[i][j]='.';
        dfs(i+1,j,board);
        dfs(i,j+1,board);
        dfs(i,j-1,board);
        dfs(i-1,j,board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int res=0;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X'){
                    dfs(i,j,board);
                    res++;
                }
            }
        }
        return res;
    }
};
// [
// ["X","X",".","X"],
// [".",".",".","X"],
// [".",".",".","X"]
// ]