#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int i = 0, answer = 0;
    int left = 1;
    while (left <= n) {
        // 왼쪽으로 탐색하면서 기존에 설치된 기지국의 전파가 닿았을때
        if (i < stations.size() && left >= stations[i] - w) {
            left = stations[i++] + w + 1;
        }
        // 기존에 설치된 기지국의 전파가 닿지 않은 경우..
        else {
            int tmpLeft = left + w;
            // 특별한 경우가 있다.
            // left가 기존에 설치된 마지막 기지국의 전파 영역에 도달하면
            // 마지막 기지국 전파 영역을 제외한 가장 오른쪽에 기지국을 설치 한다.
            // 그리디 알고리즘 .. 오른쪽이 최적의 해 이다.
            if (i + 1 <= stations.size() - 1 && tmpLeft >= stations[i + 1] - w) {
                left = stations[i + 1] - w - 1;
            }
            left = tmpLeft + w + 1;
            ++answer;
        }
    }
    
    return answer;
}

