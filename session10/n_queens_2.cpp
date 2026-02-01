class Solution {
private:
    vector<bool>diag1,diag2,hor;
public:
    bool chck(int x, int y, int n){
        if(hor[x] || diag1[x+y] || diag2[x+n -(y+1)]){
            return true;
        }
        return false;
    }
    void rec(int y, int n, vector<bool>&diag1, vector<bool>&diag2, vector<bool>&hor, int&ans){
        if(y==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(chck(i,y,n)){
                continue;
            }
            else{
                hor[i]=true;
                diag1[i+y]=true;
                diag2[i+n -(y+1)]=true;
                rec(y+1,n,diag1,diag2,hor,ans);
                hor[i]=false;
                diag1[i+y]=false;
                diag2[i+n -(y+1)]=false;
            }
        }
    }
    int totalNQueens(int n) {
        diag1.resize(2*n),diag2.resize(2*n);
        hor.resize(n);
        int ans=0;
        rec(0,n,diag1,diag2,hor,ans);
        return ans;
    }
};
