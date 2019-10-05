// 첫 번째 풀이
/* #include <string>
#include <tuple>
#include <set>
using namespace std;
set<tuple<int, int, int, int> > chk;

int convert(char dir) {
    if (dir == 'U')      return 0;
    else if (dir == 'D') return 1;
    else if (dir == 'L') return 2;
    else                 return 3;
}

bool checkRange(int nx, int ny) {
    return (-5 <= nx && nx <= 5 && -5 <= ny && ny <= 5);
}

int solution(string dirs)
{
    const int dx[] = {0, 0, -1, 1};
    const int dy[] = {-1, 1, 0, 0};
    
    int x = 0, y = 0;
    for (char dir : dirs) {
        int d = convert(dir);
        int nx = x + dx[d];
        int ny = y + dy[d];
        
        if (!checkRange(nx, ny))
            continue;
        
        if (chk.count(make_tuple(x, y, nx, ny)) == 0) {
            chk.insert(make_tuple(x, y, nx, ny));
            chk.insert(make_tuple(nx, ny, x, y));
        }
        
        x = nx;
        y = ny;
    }
    
    return (int)(chk.size() / 2);
}*/

// 두 번째 풀이
#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <set>

using namespace std;

pair<int, int> getPos(char dir) {
    if (dir == 'U') return make_pair(1, 0);
    if (dir == 'L') return make_pair(0, -1);
    if (dir == 'R') return make_pair(0, 1);
    return make_pair(-1, 0);
}

int solution(string dirs) {
    set<tuple<int, int, int, int> > visited;
    
    int answer = 0;
    int x = 0, y = 0;
    for (char dir : dirs) {
        pair<int, int> pos = getPos(dir);
        
        int nextX = x + pos.first;
        int nextY = y + pos.second;
        
        if (nextX < -5 || nextX > 5 || nextY < -5 || nextY > 5) continue;
        
        if (visited.count(make_tuple(x, y, nextX, nextY)) == 0) {
            visited.insert(make_tuple(x, y, nextX, nextY));
            visited.insert(make_tuple(nextX, nextY, x, y));
            answer++;
        }
        
        x = nextX;
        y = nextY;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("ULURRDLLU") << '\n';
    cout << solution("LULLLLLLU") << '\n';
    
    return 0;
}
