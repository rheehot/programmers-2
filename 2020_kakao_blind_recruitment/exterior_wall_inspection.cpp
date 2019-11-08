#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int weakSize = (int)weak.size();
    
    for (int i = 0; i < weakSize; i++) {
        weak.push_back(weak[i] + n);
    }
    
    sort(dist.begin(), dist.end());
    
    const int INF = 123456789;
    int answer = INF;
    
    vector<int> tempDist = dist;
    
    do {
        for (int i = 0; i < weakSize; i++) {
            int last = -INF, cnt = -1;
            bool success = true;
            for (int j = i; j < i + weakSize; j++) {
                if (last == -INF || weak[j] - last > tempDist[cnt]) {
                    last = weak[j];
                    cnt++;
                    // weak의 길이가 dist의 길이보다 큰 경우가 있기 때문에
                    // dist의 길이를 벗어나면, 그 케이스는 정답이 없음을 처리하기 위한 예외 처리
                    if (cnt == tempDist.size()) {
                        success = false;
                        break;
                    }
                }
            }
            if (success) answer = min(answer, cnt + 1);
        }
    } while (next_permutation(tempDist.begin(), tempDist.end()));
    
    return (answer == INF) ? -1 : answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(12, { 1, 5, 6, 10 }, { 1, 2, 3, 4 }) << '\n';
    cout << solution(12, { 1, 3, 4, 9, 10 }, { 3, 5, 7 }) << '\n';
    
    return 0;
}
