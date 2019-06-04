#include <iostream>
#include <vector>
using namespace std;

int solution(int n) {
    int cnt = 0;
    int temp = n;
    while (temp > 0) {
        if (temp % 2 == 1) cnt++;
        temp /= 2;
    }
    
    int answer = 0;
    for (int num = n + 1; num <= 1000000; num++) {
        temp = num;
        int cnt2 = 0;
        while (temp > 0) {
            if (temp % 2 == 1) cnt2++;
            temp /= 2;
        }
        if (cnt == cnt2) {
            answer = num;
            break;
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution(78) << '\n';
    cout << solution(15) << '\n';
    
    return 0;
}
