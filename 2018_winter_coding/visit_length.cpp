#include <string>
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
}
