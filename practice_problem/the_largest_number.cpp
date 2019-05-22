#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    vector<string> sNumbers;
    int zeroCount = 0;
    for (int num : numbers) {
        if (num == 0) zeroCount++;
        sNumbers.push_back(to_string(num));
    }
    
    if (sNumbers.size() == zeroCount) return "0";
    
    sort(sNumbers.begin(), sNumbers.end(),
         [](const string& a, const string& b) {
             return a + b > b + a;
         });
    
    string answer = "";
    for (string s : sNumbers) answer.append(s);
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution({6, 10, 2}) << '\n';
    cout << solution({3, 30, 34, 5, 9}) << '\n';
    
    return 0;
}
