#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<bool> > visited;

int bfs(int y, int x, vector<vector<int> >& picture) {
    const int dy[] = {-1, 1, 0, 0};
    const int dx[] = {0, 0, -1, 1};
    int size_of_one_area = 0;
    int value = picture[y][x];
    int m = (int)picture.size();
    int n = (int)picture[0].size();
    
    queue<pair<int, int> > q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        size_of_one_area++;
        
        for (int d = 0; d < 4; d++) {
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            
            if (ny < 0 || ny >= m || nx < 0 || nx >= n) {
                continue;
            }
            
            if (picture[ny][nx] == value && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
            }
        }
    }
    
    return size_of_one_area;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    visited = vector<vector<bool> >(m, vector<bool>(n));
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (!visited[y][x] && picture[y][x] != 0) {
                int size_of_one_area = bfs(y, x, picture);
                max_size_of_one_area = max(max_size_of_one_area, size_of_one_area);
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > a(6, vector<int>(4, 0));
    a[0][0] = 1;
    a[0][1] = 1;
    a[0][2] = 1;
    
    a[1][0] = 1;
    a[1][1] = 2;
    a[1][2] = 2;
    
    a[2][0] = 1;
    a[2][3] = 1;
    
    a[3][3] = 1;
    
    a[4][3] = 3;
    a[5][3] = 3;
    
    vector<int> answer = solution(6, 4, a);
    cout << answer[0] << ", " << answer[1] << '\n';
    
    return 0;
}
