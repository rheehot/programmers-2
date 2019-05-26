#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    int heightsSize = (int)heights.size();
    vector<int> answer(heightsSize);
    for (int i = heightsSize-1; i >= 0; i--) {
        bool find = false;
        for (int j = i-1; j >= 0; j--) {
            if (heights[i] < heights[j]) {
                answer[i] = j+1;
                find = true;
                break;
            }
        }
        if (!find) answer[i] = 0;
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> answer1 = solution({6, 9, 5, 7, 4});
    for (int i : answer1) cout << i << " ";
    cout << '\n';
    
    vector<int> answer2 = solution({3, 9, 9, 3, 5, 7, 2});
    for (int i : answer2) cout << i << " ";
    cout << '\n';
    
    vector<int> answer3 = solution({1, 5, 3, 6, 7, 6, 5});
    for (int i : answer3) cout << i << " ";
    cout << '\n';
    
    return 0;
}
