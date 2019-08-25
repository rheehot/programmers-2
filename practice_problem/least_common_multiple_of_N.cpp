// 프로그래머스 12953 - N개의 최소공배수
// 제일 먼저 배열 첫 번째 두 번째 원소의 최소 공배수를 구한다.
// 그 최소 공배수와 다음 원소와 최소 공배수를 구한다.
// 배열 마지막까지 반복하면서 최소 공배수를 구한다.
// 유클리드 호제법을 사용한다.
#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = lcm(arr[0], arr[1]);
    for (int i = 2; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr1 = {2, 6, 8, 14};
    cout << solution(arr1) << '\n';
    
    vector<int> arr2 = {1, 2, 3};
    cout << solution(arr2) << '\n';
    
    return 0;
}
