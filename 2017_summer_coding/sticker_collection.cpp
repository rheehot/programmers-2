// 문제 해결 방법
// 14 6 5 11 3 9 2 10
// 1. 현재 index 위치에서 스티커를 뗀 경우에는 index-2에 메모이제이션 했던 값을 불러와서
//    현재 떼어낸 스티커의 값을 더해 주면 된다. (dp[?][i-2] * sticker[i])
// 2. 현재 index 위치에서 스티커를 떼지 않은 경우에는 직전의 위치(index-1)가 스티커를 뗀 경우이므로
//    직전 위치(index-1)에 메모이제이션 했던 값을 불러온다. (dp[?][i-1])
// 3. 1번에서 구한 값과 2번에서 구한 값을 비교하여 최대값을 현재 값에 넣는다.
//    ( dp[?][i] = max(dp[?][i-1], dp[?][i-2] * sticker[i]) )
#include <iostream>
#include <vector>
using namespace std;
int dp[2][100000];

int solution(vector<int> sticker)
{
    int n = (int)sticker.size();
    // 예외 처리
    if (n == 1) return sticker[0];
    if (n == 2) return max(sticker[0], sticker[1]);
    
    // d[0][i] : 첫 번째 스티커를 뗀 경우
    dp[0][0] = sticker[0];
    dp[0][1] = sticker[0];
    
    // d[1][i] : 첫 번째 스티커를 떼지 않은 경우
    dp[1][0] = 0;
    dp[1][1] = sticker[1];
    
    for (int i = 2; i < n; i++) {
        dp[0][i] = max(dp[0][i-1], dp[0][i-2] + sticker[i]);
        dp[1][i] = max(dp[1][i-1], dp[1][i-2] + sticker[i]);
    }
    
    return max(dp[0][n-2], dp[1][n-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> sticker = {14, 6, 5, 11, 3, 9, 2, 10};
    cout << solution(sticker) << '\n';
    return 0;
}

