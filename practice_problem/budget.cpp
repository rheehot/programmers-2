#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    sort(budgets.begin(), budgets.end());
    
    int low = 0;
    int high = *max_element(budgets.begin(), budgets.end());
    int answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int sum = 0;
        for (int i = 0; i < budgets.size(); i++) {
            if (budgets[i] > mid) {
                sum += mid;
                continue;
            }
            sum += budgets[i];
        }
        if (sum <= M) {
            answer = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution({120, 110, 140, 150}, 485) << '\n';
    
    return 0;
}
