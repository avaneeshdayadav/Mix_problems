// Problem Link : https://leetcode.com/problems/valid-sudoku/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        unordered_map<int,vector<int>> rows, cols;
        unordered_map<string,vector<int>> cell;
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                // Check in row
                if(board[i][j] == '.')
                    continue;
                
                if(rows.find(i) == rows.end())
                {
                    vector<int> temp;
                    temp.push_back(board[i][j]);
                    rows[i] = temp;
                }
                else
                {
                    if(find(rows[i].begin(), rows[i].end(), board[i][j]) != rows[i].end())
                        return false;
                    
                    rows[i].push_back(board[i][j]);
                }
                
                
                // Check in column
                if(cols.find(j) == cols.end())
                {
                    vector<int> temp;
                    temp.push_back(board[i][j]);
                    cols[j] = temp;
                }
                else
                {
                    if(find(cols[j].begin(), cols[j].end(), board[i][j]) != cols[j].end())
                        return false;
                    
                    cols[j].push_back(board[i][j]);
                }
                
                
                // Check in cell
                string key = to_string(i/3) + " " + to_string(j/3);
                
                if(cell.find(key) == cell.end())
                {
                    vector<int> temp;
                    temp.push_back(board[i][j]);
                    cell[key] = temp;
                }
                else
                {
                    if(find(cell[key].begin(),cell[key].end(),board[i][j]) != cell[key].end())
                        return false;
                    
                    cell[key].push_back(board[i][j]);
                }
            }
        }
        
        return true;
    }
};