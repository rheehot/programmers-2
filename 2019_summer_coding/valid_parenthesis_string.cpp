// 올바른 괄호의 쌍 만들기
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void go(vector<string>& answer, string cur, int open, int close, int n) {
    if (cur.length() == 2*n) {
        answer.push_back(cur);
        return;
    }
    if (open < n)       go(answer, cur+"(", open+1, close, n);
    if (close < open)   go(answer, cur+")", open, close+1, n);
}

vector<string> solution(int N)
{
    vector<string> answer;
    string cur = "";
    go(answer, cur, 0, 0, N);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> answer = solution(n);
    for (string str : answer) cout << str << '\n';
    cout << "count : " << answer.size() << '\n';
    
    return 0;
}
