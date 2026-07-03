class Solution {
public:

bool is_safe(int row,int col,vector<vector<char>>& board ,char s){

    // row
    for(int i=0;i<9;i++){
        if(board[row][i]==s) return false;
    }

    // column
    for(int i=0;i<9;i++){
        if(board[i][col]==s) return false;
    }

    int rbod = row - row%3;
    int cbod = col - col%3;

    for(int i=rbod;i<rbod+3;i++){
        for(int j=cbod;j<cbod+3;j++){
            if(board[i][j]==s) return false;
        }
    }

    return true;
}

bool solve(int row,vector<vector<char>>& board){

    if(row==9) return true;

    for(int col=0;col<9;col++){

        if(board[row][col]=='.'){

            for(char c='1';c<='9';c++){

                if(is_safe(row,col,board,c)){

                    board[row][col]=c;

                    if(solve(row,board))
                        return true;

                    board[row][col]='.';
                }
            }

            return false;
        }
    }

    return solve(row+1,board);
}

void solveSudoku(vector<vector<char>>& board) {
    solve(0,board);
}

};