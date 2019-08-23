// 프로그래머스 12913 - 땅따먹기
// 문제의 핵심은 단순히 한 행씩 내려오면서 작업을 수행하는 것이 아니다.
// 각 행에서 최적의 값을 찾아야 하는 것
// 첫 번째 풀었을 때는 이것을 고려하지 않아서 테스트 케이스가 모두 실패했었다.
// 블로그를 참고하여 해결했다.
// 모든 위치에서 나올 수 있는 모든 수를 더하는 방식으로 해결해야 하고
// 열은 4개라는 점을 기억하자
// 1. 현재 행에서 0번열을 선택 했다면? 이전 행의 1, 2, 3번열 중에서 최대 값을 구한다.
// 2. 현재 행에서 1번열을 선택 했다면? 이전 행의 0, 2, 3번열 중에서 최대 값을 구한다.
// 3. 현재 행에서 2번열을 선택 했다면? 이전 행의 0, 1, 3번열 중에서 최대 값을 구한다.
// 4. 현재 행에서 3번열을 선택 했다면? 이전 행의 0, 1, 2번열 중에서 최대 값을 구한다.
// 5. 마지막 행의 최대값을 리턴한다.
// 왜 이러한 방식으로 해야할까?
// 1    2 3 5
// 5    6 7 8
// 4    3 2 1
// 1000 0 9 8
// 다음과 같이 있을때 내가 직전에 풀었던 방식으로 답을 구한다면 5 + 7 + 4 + 9 = 25이다.
// 그런데 진짜 최대값을 찾는다면 5 + 7 + 3 + 1000 = 1015 이것이 정답이다.
// 그렇기 때문에 위와 같은 방법으로 해결해야 한다.
// 위의 예제를 아래와 같이 만든다.
// 1 2 3 5
// 10 11 12 11
// 16 15 13 13
// 1015 16 25 24
// 따라서 최대값은 1015
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getMax(int value1, int value2, int value3) {
    return max(value1, max(value2, value3));
}

int solution(vector<vector<int> > land) {
    for (int r = 1; r < land.size(); r++) {
        land[r][0] += getMax(land[r-1][1], land[r-1][2], land[r-1][3]);
        land[r][1] += getMax(land[r-1][0], land[r-1][2], land[r-1][3]);
        land[r][2] += getMax(land[r-1][0], land[r-1][1], land[r-1][3]);
        land[r][3] += getMax(land[r-1][0], land[r-1][1], land[r-1][2]);
    }
    size_t landSize = land.size();
    return *max_element(land[landSize-1].begin(), land[landSize-1].end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<vector<int> > land(3, vector<int>(4));
    
    land[0][0] = 1;
    land[0][1] = 2;
    land[0][2] = 3;
    land[0][3] = 5;
    
    land[1][0] = 5;
    land[1][1] = 6;
    land[1][2] = 7;
    land[1][3] = 8;
    
    land[2][0] = 4;
    land[2][1] = 3;
    land[2][2] = 2;
    land[2][3] = 1;
    
    cout << solution(land) << '\n';
    return 0;
}
