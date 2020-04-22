// 이분 탐색까지는 생각했고, 이분 탐색 로직을 구현했다.
// 다만 check 로직을 제대로 구현하지 못해서 다른 사람들의 풀이를 참고했다.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int>& stones, int k, int mid) {
    int now = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - mid <= 0) now++;
        else now = 0;
        
        if (now >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    auto value = minmax_element(stones.begin(), stones.end());
    
    int low = *value.first;
    int high = *value.second;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        
        if (check(stones, k, mid)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return low;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3) << '\n';
    
    return 0;
}
