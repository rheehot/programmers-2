#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair<int, int> POS;

bool isDivide(POS& ap1, POS& ap2, POS& bp1, POS& bp2) {
    double ax = ap2.first  - ap1.first;      // x
    double ay = ap2.second - ap1.second;     // y
    
    double cy1 = bp1.second - ap1.second;
    double cx1 = bp1.first  - ap1.first;
    
    double cy2 = bp2.second - ap2.second;
    double cx2 = bp2.first  - ap2.first;
    
    double f1 = ax * cy1 - ay * cx1;
    double f2 = ax * cy2 - ay * cx2;
    
    return (f1 * f2 <= 0) ? true : false;
}

bool isCross(POS& ap1, POS& ap2, POS& bp1, POS& bp2) {
    double ok1 = isDivide(ap1, ap2, bp1, bp2);
    double ok2 = isDivide(bp1, bp2, ap1, ap2);
    return (ok1 && ok2) ? true : false;
}

vector<int> solution(vector<int> pattern) {
    vector<pair<POS, POS> > pos;
    for (int i = 0; i < pattern.size()-1; i++) {
        int x1 = (pattern[i]-1) % 3 + 1,    y1 = (pattern[i]-1) / 3 + 1;
        int x2 = (pattern[i+1]-1) % 3 + 1,  y2 = (pattern[i+1]-1) / 3 + 1;
        pos.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
    }
    
    // 선분 만들어서 교차점 구하기
    vector<int> answer;
    for (int i = 0; i < pos.size(); i++) {
        int count = 0;
        for (int j = 0; j < pos.size(); j++) {
            if (i == j) continue;
            if (isCross(pos[i].first, pos[i].second, pos[j].first, pos[j].second)) {
                count++;
            }
        }
        answer.push_back(count);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed;
    cout.precision(6);
    
    vector<int> answer1 = solution({1, 2, 5, 8, 9});
    vector<int> answer2 = solution({1, 6, 8, 3, 4});
    vector<int> answer3 = solution({2, 5, 1, 3});
    vector<int> answer4 = solution({6, 5, 7, 3, 9});
    vector<int> answer5 = solution({5, 3});
    for (int ans : answer1) {
        cout << ans << " ";
    }
    cout << '\n';
    
    for (int ans : answer2) {
        cout << ans << " ";
    }
    cout << '\n';
    
    for (int ans : answer3) {
        cout << ans << " ";
    }
    cout << '\n';
    
    for (int ans : answer4) {
        cout << ans << " ";
    }
    cout << '\n';
    
    for (int ans : answer5) {
        cout << ans << " ";
    }
    cout << '\n';
    return 0;
}
