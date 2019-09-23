#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    const int MOD = 1e9 + 7;
    vector<int> dp(n+1);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(4) << '\n';
    
    return 0;
}
