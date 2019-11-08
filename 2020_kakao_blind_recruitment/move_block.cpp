#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int> > tempBoard;

const int dirY[] = {0, 1, 0, -1};
const int dirX[] = {1, 0, -1, 0};
const int errY[] = {-1, 1, 1, -1};
const int errX[] = {1, 1, -1, -1};

const int MAX = 101;
const int DIR = 4;

int dist[MAX][MAX][DIR];
int n;

bool check(int y, int x, int d) {
    if (y < 0 || y >= n || x < 0 || x >= n) return false;
    
    int ny = y + dirY[d], nx = x + dirX[d];
    if (ny < 0 || ny >= n || nx < 0 || nx >= n) return false;
    
    if (tempBoard[y][x] || tempBoard[ny][nx]) return false;
    
    return true;
}

bool check2(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= n) return false;
    
    if (tempBoard[y][x]) return false;
    
    return true;
}

int solution(vector<vector<int>> board) {
    memset(dist, -1, sizeof(dist));
    
    n = (int)board.size();
    
    tempBoard = board;
    
    queue<tuple<int, int, int> > q;
    q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 0;
    
    while (!q.empty()) {
        int y, x, d;
        tie(y, x, d) = q.front();
        q.pop();
        
        if ((y == n-1 && x == n-1) || (y+dirY[d] == n-1 && x+dirX[d] == n-1)) {
            return dist[y][x][d];
        }
        
        int ny = 0, nx = 0, nd = 0, ey = 0, ex = 0;
        
        // 이동
        for (int i = 0; i < 4; i++) {
            ny = y + dirY[i];
            nx = x + dirX[i];
            nd = d;
            
            if (check(ny, nx, nd) && dist[ny][nx][nd] == -1) {
                dist[ny][nx][nd] = dist[y][x][d] + 1;
                q.push(make_tuple(ny, nx, nd));
            }
        }
        
        // 시계 방향 회전
        ny = y;
        nx = x;
        nd = (d + 1) % 4;
        ey = y + errY[nd];
        ex = x + errX[nd];
        if (check(ny, nx, nd) && check2(ey, ex) && dist[ny][nx][nd] == -1) {
            dist[ny][nx][nd] = dist[y][x][d] + 1;
            q.push(make_tuple(ny, nx, nd));
        }
        
        // 반 시계 방향 회전
        ny = y;
        nx = x;
        nd = (d + 3) % 4;
        ey = y + errY[d];
        ex = x + errX[d];
        if (check(ny, nx, nd) && check2(ey, ex) && dist[ny][nx][nd] == -1) {
            dist[ny][nx][nd] = dist[y][x][d] + 1;
            q.push(make_tuple(ny, nx, nd));
        }
        
        // 축 변경
        int ry = y + dirY[d], rx = x + dirX[d], rd = (d + 2) % 4;
        
        // 시계 방향 회전
        ny = ry;
        nx = rx;
        nd = (rd + 1) % 4;
        ey = ry + errY[nd];
        ex = rx + errX[nd];
        if (check(ny, nx, nd) && check2(ey, ex) && dist[ny][nx][nd] == -1) {
            dist[ny][nx][nd] = dist[y][x][d] + 1;
            q.push(make_tuple(ny, nx, nd));
        }
        
        // 반 시계 방향 회전
        ny = ry;
        nx = rx;
        nd = (rd + 3) % 4;
        ey = ry + errY[rd];
        ex = rx + errX[rd];
        if (check(ny, nx, nd) && check2(ey, ex) && dist[ny][nx][nd] == -1) {
            dist[ny][nx][nd] = dist[y][x][d] + 1;
            q.push(make_tuple(ny, nx, nd));
        }
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };
    
    cout << solution(board) << '\n';
    
    return 0;
}

