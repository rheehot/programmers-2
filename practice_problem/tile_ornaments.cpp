#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    vector<long long> dp(N+1);
    dp[1] = 4;
    dp[2] = 6;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(5) << '\n';
    cout << solution(6) << '\n';
    
    return 0;
}
