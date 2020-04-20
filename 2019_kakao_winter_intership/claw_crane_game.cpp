#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int> > board, vector<int> moves)
{
    int answer = 0;

    stack<int> st;
    for (int move : moves) {
        int col = move - 1;
        int catchNumber = 0;
        
        for (int row = 0; row < board.size(); row++) {
            if (board[row][col]) {
                catchNumber = board[row][col];
                board[row][col] = 0;
                break;
            }
        }
        
        if (catchNumber == 0) continue;
        
        if (!st.empty()) {
            if (catchNumber == st.top()) {
                answer += 2;
                st.pop();
                continue;
            }
        }

        st.push(catchNumber);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > board = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    
    cout << solution(board, moves) << '\n';
    
    return 0;
}
