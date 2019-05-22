// 처음에 재귀호출 방식으로 풀었으나 시간 초과가 났다.
// 문제 해결방법을 찾아보고 구현 했다.
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(int n) {
    vector<char> patterns = {'4', '1', '2'};
    
    string answer = "";
    int remainder = 0;
    while (n > 0) {
        remainder = n % 3;
        if (remainder == 0) n = (n / 3) - 1;
        else n /= 3;
        answer = patterns[remainder] + answer;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    cout << solution(n) << '\n';
    
    return 0;
}
