#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > h;
vector<vector<int> > g;

bool check(int x, int y, int type) {
    if (type == 0) { // 기둥
        if (y == 0 || (x != 0 && g[y][x-1]) || g[y][x] || h[y-1][x]) {
            return true;
        }
    } else if (type == 1) { // 보
        if (y && ((x != 0 && g[y][x-1] && g[y][x+1]) || h[y-1][x] || h[y-1][x+1])) {
            return true;
        }
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    
    h = g = vector<vector<int> >(n+1, vector<int>(n+1));
    
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        
        if (a == 0) { // 기둥
            // 설치
            if (b == 1 && check(x, y, a)) h[y][x] = 1;
            else if (b == 0) { // 삭제
                bool chk = true;
                
                h[y][x] = 0;
                
                if (h[y+1][x] && !check(x, y+1, 0)) chk = false;
                
                if (x && g[y+1][x-1] && !check(x-1, y+1, 1)) chk = false;
                
                if (g[y+1][x] && !check(x, y+1, 1)) chk = false;
                
                if (!chk) h[y][x] = 1;
            }
        } else if (a == 1) { // 보
            // 설치
            if (b == 1 && check(x, y, a)) g[y][x] = 1;
            else if (b == 0) { // 삭제
                bool chk = true;
                
                g[y][x] = 0;
                
                if (h[y][x] && !check(x, y, 0)) chk = false;
                
                if (h[y][x+1] && !check(x+1, y, 0)) chk = false;
                
                if (x && g[y][x-1] && !check(x-1, y, 1)) chk = false;
                
                if (g[y][x+1] && !check(x+1, y, 1)) chk = false;
                
                if (!chk) g[y][x] = 1;
            }
        }
    }
    
    for (int y = 0; y <= n; y++) {
        for (int x = 0; x <= n; x++) {
            if (h[y][x]) {
                answer.push_back(vector<int>());
                answer.back().push_back(x);
                answer.back().push_back(y);
                answer.back().push_back(0);
            }
            
            if (g[y][x]) {
                answer.push_back(vector<int>());
                answer.back().push_back(x);
                answer.back().push_back(y);
                answer.back().push_back(1);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > build_frame1 = {
        {1,0,0,1},
        {1,1,1,1},
        {2,1,0,1},
        {2,2,1,1},
        {5,0,0,1},
        {5,1,0,1},
        {4,2,1,1},
        {3,2,1,1}
    };
    
    vector<vector<int> > answer1 = solution(5, build_frame1);
    
    for (int i = 0; i < answer1.size(); i++) {
        cout << answer1[i][0] << " " << answer1[i][1] << " " << answer1[i][2] << '\n';
    }
    
    return 0;
}
