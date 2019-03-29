// 부분합과 이분 탐색으로 문제를 해결해야한다.
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> cookie) {
    int n = (int)cookie.size();
    
    vector<int> pSum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        pSum[i] = pSum[i-1] + cookie[i-1];
    }
    
    int answer = 0;
    // 처음 시도했던 방법
    // 3중 for문에 예외처리를 통하여 테스트를 통과함
    // 최대 시간 89.34ms 걸림 (100ms 이내 들어옴)
    /*for (int m = 1; m < n; m++) {
        for (int l = m - 1; l >= 0; l--) {
            int left  = pSum[m] - pSum[l];
            if (answer >= left) continue;
            for (int r = m + 1; r <= n; r++) {
                int right = pSum[r] - pSum[m];
                if (left == right) {
                    answer = max(answer, left);
                    break;
                }
            }
        }
    }*/
    
    // 다른 사람이 구현한 이분 탐색 방법
    // 최대 시간 40.06 ms (2배 빠름)
    // 이분 탐색 구현하는 연습을 하자..
    for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            int left = i, right = j;
            while (left <= right) {
                int mid = (left + right) / 2;
                int leftSum = pSum[mid] - pSum[i-1];
                int rightSum = pSum[j] - pSum[mid];
                if (leftSum == rightSum) {
                    answer = max(answer, leftSum);
                    break;
                } else if (leftSum > rightSum) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
    
    return answer;
}

int main() {
    vector<int> cookie = {1, 1, 2, 3};
    cout << solution(cookie) << '\n';
    return 0;
}
