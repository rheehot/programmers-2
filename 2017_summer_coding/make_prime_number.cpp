#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    const int limit = 50 * 1000;
    vector<bool> isPrimeNum(limit+1, true);
    for (int i = 2; i < sqrt(limit); i++) {
        if (!isPrimeNum[i]) continue;
        for (int j = i*i; j <= limit; j+=i) {
            if (!isPrimeNum[j]) continue;
            isPrimeNum[j] = false;
        }
    }
    
    int answer = 0;
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
        int sum = nums[i];
        for (int j = i+1; j < n; j++) {
            sum += nums[j];
            for (int k = j+1; k < n; k++) {
                sum += nums[k];
                if (isPrimeNum[sum]) answer++;
                sum -= nums[k];
            }
            sum -= nums[j];
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> nums = {1, 2, 7, 6, 4};
    cout << solution(nums) << '\n';
    return 0;
}

