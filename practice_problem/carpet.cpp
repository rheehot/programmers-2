// 프로그래머스 42842 - 카펫
// 가로와 세로 길이는 무조건 3 이상이다. (red 격자가 1개일 때를 생각해보면 된다.)
// 세로 길이로 탐색할 범위를 지정한다.
// 탐색하면서 red격자의 갯수를 구한다.
// red 격자의 갯수 == (brown의 가로 길이 - 왼쪽 - 오른쪽) * (brown의 세로 길이 - 위 - 아래)
// 즉, (brown.col - 2) * (brown.row - 2) == red 이다.
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int red) {
    int sum = brown + red;
    int rowLimit = (int)sqrt(sum);
    
    vector<int> answer;
    for (int row = 3; row <= rowLimit; row++) {
        if (sum % row == 0) {
            int col = sum / row;
            // 빨간색의 격자의 개수가 일치하는지
            if ((col - 2) * (row - 2) == red) {
                answer.push_back(col);
                answer.push_back(row);
                break;
            }
        }
    }
    
    return answer;
}

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> answer1 = solution(10, 2);
    for (int ans : answer1) cout << ans << " ";
    cout << '\n';
    
    vector<int> answer2 = solution(8, 1);
    for (int ans : answer2) cout << ans << " ";
    cout << '\n';
    
    vector<int> answer3 = solution(24, 24);
    for (int ans : answer3) cout << ans << " ";
    cout << '\n';
    
    return 0;
}
