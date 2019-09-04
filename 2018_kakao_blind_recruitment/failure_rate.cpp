// 프로그래머스 42889 - 실패율
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myCompare(pair<double, int>& a, pair<double ,int>& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> stageCount(N+1);
    for (int i = 1; i <= N; i++) {
        for (int stage : stages) {
            if (i <= stage) stageCount[i]++;
        }
    }
    
    vector<pair<double, int> > temp;
    for (int i = 1; i <= N; i++) {
        int count = 0;
        for (int stage : stages) {
            if (i == stage) count++;
        }
        
        if (stageCount[i]) {
            temp.push_back(make_pair((double)count / stageCount[i], i));
        } else {
            // stageCount에 사람이 없는 경우에는 0 / 0 을 하게 되는데 이거는 nan 값이 나옴
            // 따라서 해당 stageCount가 0일때 실패율 예외처리를 해야한다.
            // test-case : 6, 7, 9, 13, 24 통과
            temp.push_back(make_pair(0, i));
        }
    }
    
    sort(temp.begin(), temp.end(), myCompare);
    
    vector<int> answer;
    for (auto p : temp) {
        answer.push_back(p.second);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> answer1 = solution(5, {2, 1, 2, 6, 2, 4, 3, 3});
    for (int ans : answer1) {
        cout << ans << " ";
    }
    cout << '\n';
    
    vector<int> answer2 = solution(4, {4, 4, 4, 4, 4});
    for (int ans : answer2) {
        cout << ans << " ";
    }
    cout << '\n';
    
    vector<int> answer3 = solution(3, {1, 1, 1, 1, 1});
    for (int ans : answer3) {
        cout << ans << " ";
    }
    cout << '\n';
    
    return 0;
}
