#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};
    int n = (int)maps.size();
    int m = (int)maps[0].size();
    
    int dist[100][100];
    memset(dist, 0, sizeof(dist));
    dist[0][0] = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == n-1 && x == m-1) {
            return dist[n-1][m-1];
        }
        
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                continue;
            }
            if (maps[ny][nx] == 1 && dist[ny][nx] == 0) {
                dist[ny][nx] = dist[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    return -1;
}
