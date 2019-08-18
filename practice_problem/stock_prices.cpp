// 프로그래머스 42584 - 주식가격
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int, int> > st;
    
    int end = (int)prices.size();
    for (int sec = 1; sec <= end; sec++) {
        while (!st.empty() && st.top().second > prices[sec-1]) {
            answer[st.top().first-1] = (sec - st.top().first);
            st.pop();
        }
        st.push(make_pair(sec, prices[sec-1]));
    }
    
    while (!st.empty()) {
        answer[st.top().first-1] = (end - st.top().first);
        st.pop();
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> price1 = { 1, 2, 3, 2, 3 };
    vector<int> price2 = { 498, 501, 470, 489 };
    
    vector<int> answer1 = solution(price1);
    vector<int> answer2 = solution(price2);
    
    for (int ans : answer1) {
        cout << ans << " ";
    }
    cout << '\n';
    
    for (int ans : answer2) {
        cout << ans << " ";
    }
    cout << '\n';
    
    return 0;
}
