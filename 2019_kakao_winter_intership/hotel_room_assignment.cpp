#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<long long, long long> check;

long long go(long long number) {
    if (!check[number]) return number;
    return check[number] = go(check[number]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for (long long number : room_number) {
        if (!check[number]) {
            check[number] = go(number + 1);
            answer.push_back(number);
            continue;
        }
        
        long long tempNumber = go(number);
        check[tempNumber] = go(tempNumber + 1);
        answer.push_back(tempNumber);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<long long> answer = solution(10, { 1, 3, 4, 1, 3, 1 });
    for (long long ans : answer) cout << ans << " ";
    cout << '\n';
    
    return 0;
}

