#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool ifExist;
    vector<vector<bool>> visited;
    int rnum,cnum;
    bool exist(vector<vector<char>>& board, string word) {
        ifExist=false;
        rnum=board.size();
        cnum=board[0].size();
        visited=vector<vector<bool>>(rnum,vector<bool>(cnum,false));
        for (int i=0;i<rnum;++i) {
            for (int j=0;j<cnum;++j) {
                if (ifExist) return true;
                dfs(board,word,0,i,j);
            }
        }
        return ifExist;
    }

    void dfs(vector<vector<char>>& board, string& word, int index, int row, int col) {
        if (!ifExist && row>=0 && row<rnum && col>=0 && col<cnum && !visited[row][col] && word.size()>0 && word[index]==board[row][col]) {
            visited[row][col]=true;
            if (index==word.size()-1) {
                ifExist=true;
                return;
            }
            dfs(board,word,index+1,row+1,col);
            dfs(board,word,index+1,row-1,col);
            dfs(board,word,index+1,row,col+1);
            dfs(board,word,index+1,row,col-1);
            visited[row][col]=false;
        }
    }
};


int main() {
    return 0;
}