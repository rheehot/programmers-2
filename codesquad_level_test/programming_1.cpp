#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
[50점]
배열 arr가 주어집니다. 배열 arr의 각 원소는 숫자 0부터 9까지로 이루어져 있습니다.
이 배열 arr에서 연속으로 나타나는 숫자는 하나씩만 남기고 전부 제거하려고 합니다. 배열 arr에서 연속으로 중복되는 수를 제거 되고 남은 수들을 return 하는 solution 함수를 완성해 주세요.
단, 제거된 후 남은 수들을 반환할 때는 배열 arr의 원소들의 순서를 유지해야 합니다.
중복된 모든 숫자를 제거하는게 아닙니다.
예를들면
arr = [1, 1, 3, 3, 0, 1, 1] 이면 [1, 3, 1] 을 return 합니다.
arr = [4, 4, 4, 3, 3] 이면 [4, 3] 을 return 합니다.
arr = [1,2,3,4] 이면 [] 빈 배열을 return 합니다.
배열 arr에서 연속적으로 나타나는 숫자는 제거하고 남은 수들을 return 하는 solution 함수를 완성해 주세요.
solution 함수 내부에서 배열의 값을 반복해서 비교하는 로직을 직접 구현하세요.
<본 테스트는 결과를 확인하려는게 아니라 직접 로직 구현에 얼마나 충실한가 코드를 확인합니다>
제한사항
배열 arr의 크기 : 100 이하의 자연수
배열 arr의 원소의 크기 : 0보다 크거나 같고 9보다 작거나 같은 정수
*/

vector<int> solution(vector<int> param0) {
    vector<int> answer;
    
    int i = 0;
    int size = (int)param0.size();
    while (i < size-1) {
        int j = i+1;
        bool overlap_check = false;
        while (j < size) {
            if (param0[i] == param0[j]) {
                if (!overlap_check) overlap_check = true;
            } else {
                break;
            }
            ++j;
        }
        if (overlap_check) {
            answer.push_back(param0[i]);
        }
        i = j;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr;
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(7);
    arr.push_back(1);
    arr.push_back(1);
    arr.push_back(1);
    
    
    vector<int> answer = solution(arr);
    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        if (i == answer.size()-1) {
            cout << answer[i];
        } else {
            cout << answer[i] << ", ";
        }
    }
    cout << "]\n";
    
    return 0;
}
