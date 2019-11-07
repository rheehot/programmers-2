#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > rotateKey(vector<vector<int> >& key) {
    int rSize = (int)key.size();
    int cSize = (int)key[0].size();
    
    vector<vector<int> > rotatedKey(rSize, vector<int>(cSize));
    
    for (int r = 0; r < rSize; r++) {
        for (int c = 0; c < cSize; c++) {
            rotatedKey[c][rSize-r-1] = key[r][c];
        }
    }
    
    return rotatedKey;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    
    int m = (int)key.size();
    int n = (int)lock.size();
    
    int zeroCount = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            if (lock[r][c] == 0) zeroCount++;
        }
    }
        
    // 1. key 4방향으로 회전
    for (int rotate = 0; rotate < 4; rotate++) {
        for (int lR = -20; lR <= 20; lR++) {
            for (int lC = -20; lC <= 20; lC++) {
                bool ok = true;
                int cnt = 0;
                for (int kR = 0; kR < m; kR++) {
                    for (int kC = 0; kC < m; kC++) {
                        int nR = lR + kR;
                        int nC = lC + kC;
                        if (nR < 0 || nR >= n || nC < 0 || nC >= n) {
                            continue;
                        }
                        if (lock[nR][nC] == 1 && key[kR][kC] == 1) {
                            ok = false;
                            break;
                        }
                        if (lock[nR][nC] == 0 && key[kR][kC] == 1) {
                            cnt++;
                        }
                    }
                    if (!ok) break;
                }
                if (ok && zeroCount == cnt) {
                    answer = ok;
                    break;
                }
            }
            if (answer) break;
        }
        if (answer) break;
        key = rotateKey(key);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > key = {
        {0, 0, 0},
        {1, 0, 0},
        {0, 1, 1}
    };
    
    vector<vector<int> > lock = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    
    cout << solution(key, lock) << '\n';
    
    return 0;
}
