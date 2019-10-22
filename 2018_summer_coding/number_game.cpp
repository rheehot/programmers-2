// 최적의 결과를 찾아야하는 그리디문제이다.
// 주어진 문제에서 A배열은 순서대로 되어있으니깐 변화시킬 필요없다는 고정관념이 있었다.
// 이런 생각을 가지고 문제를 해결할 수 없었다.
// 해결 방법은 다음과 같다.
// A, B 배열을 오름차순으로 정렬한다.
// 해당 위치에서 두 원소를 비교하고, B의 원소가 크다면 값을 증가시킴과 동시에 B의 값을 -1로 초기화한다.
// B의 값을 -1로 초기화 하는 이유는 이미 한번 체크했다는 표시를 의미한다. (이미 뽑은 숫자는 다시 비교할 수 없기 때문에)
// 그리고 마지막으로 중요한 것은 2중 for문을 돌 때 바깥의 for문의 index값으로 안쪽 for문을 시작해야한다.
// 예시)
// for (int i = 0; i < size; i++) {
//      for (int j = i; j < size; j++) {
//
// 이렇게 하는 이유는 첫 번째 숫자를 비교해서 결과를 알았다면, 그 다음에는 이전의 숫자에 대해서 신경 쓸 필요가 없다.
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int answer = 0;
    int size = (int)A.size();
    
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (A[i] < B[j]) {
                answer++;
                B[j] = -1;
                break;
            }
        }
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << solution({ 5, 1, 3, 7 }, { 2, 2, 6, 8 }) << '\n';
    cout << solution({ 2, 2, 2, 2 }, { 1, 1, 1, 1 }) << '\n';
    
    return 0;
}
