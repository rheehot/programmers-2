#include <iostream>
#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int j = 0;
    int numberLength = (int)number.length();
    for (int i = k; i < numberLength; i++) {
        int maxValue = 0;
        int maxIndex = j;
        while (j < i + 1) {
            if (maxValue < number[j]) {
                maxValue = number[j];
                maxIndex = j;
            }
            j++;
        }
        j = maxIndex + 1;
        answer += number[maxIndex];
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution("1924", 2) << '\n';
    cout << solution("1231234", 3) << '\n';
    cout << solution("4177252841", 4) << '\n';
    cout << solution("10000", 2) << '\n';
    cout << solution("10000", 4) << '\n';
    
    return 0;
}
