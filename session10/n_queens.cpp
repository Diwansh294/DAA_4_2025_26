#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
vector<vector<string>> result;
vector<string> board;
int n;

bool issafe(int row,int col){
    for(int i=0; i<row; i++){
        if(board[i][col]=='Q') return false;
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0;j--,i--){
        if(board[i][j]=='Q')return false;
    }
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        if(board[i][j]=='Q')return false;
    }
    return true;
}

void solve(int row){
    if(row==n){
        result.push_back(board);
        return;
    }
    for(int col=0;col<n;col++){
        if(issafe(row,col)){
            board[row][col]='Q';
            solve(row+1);
            board[row][col]='.'; 
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    this->n=n;
    board = vector<string>(n, string(n,'.'));
    solve(0);
    return result;
}
};
