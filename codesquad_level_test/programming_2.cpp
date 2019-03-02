#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 [150점]
 arr1과 arr2가 주어집니다. 각 배열의 원소는 숫자 1부터 9까지로 이루어져 있습니다.
 이 배열에서 2번 이상 페어로 나오는 숫자들을 비교해서 둘 중에 어느 쪽이 더 큰 값인지 확인해야 합니다.
 arr1 배열이 더 큰 값을 포함하면 1을, arr2 배열이 더 큰 값을 포함하고 있으면 2를 return 하는 solution 함수를 완성해 주세요.
 양쪽 배열에 모두 페어가 없으면 0을 return 하세요.
 같은 숫자 2개가 페어로 나오는 경우보다는 3개가 페어로 나오는 경우가 더 큰 값이다.
 같은 숫자 3개가 페어로 나오는 경우보다는 4개가 페어로 나오는 경우가 더 큰 값이다.
 양쪽 모두 같은 개수의 페어라면 더 큰 숫자가 큰 값이다.
 숫자 페어가 2벌이 나오는 경우에는 더 큰 숫자로 되어있는 페어만 고려한다.
 양쪽 배열에서 페어 숫자가 같으면 비교를 할 수 없으니 0을 return 하세요.
 예를들면
 arr1 = [1, 5, 7, 2, 9]이고, arr2 = [2, 3, 9, 4, 8] 이면 페어가 없으니 0를 return 합니다.
 arr1 = [1, 4, 1, 3, 5]이고, arr2 = [9, 2, 3, 1, 3] 이면 숫자 3이 페어로 나온 2를 return 합니다.
 arr1 = [1, 1, 9, 4, 1]이고, arr2 = [2, 3, 3, 9, 9] 이면 숫자 1이 3번 페어로 나온 1를 return 합니다.
 arr1 = [1, 4, 9, 4, 1]이고, arr2 = [9, 3, 1, 9, 1] 이면 페어중에 큰 숫자 9가 나온 2를 return 합니다.
 solution 함수 외에도 필요한 함수를 추가해서 코드를 분리해보세요.
 <본 테스트는 결과를 확인하려는게 아니라 직접 로직 구현에 얼마나 충실한가 코드를 확인합니다>
 제한사항
 각 배열 arr의 크기 : 5
 각 배열 arr의 원소의 크기 : 1보다 크거나 같고 9보다 작거나 같은 정수
 */

unordered_map<int, int> get_hash_map(vector<int>& arr) {
    unordered_map<int, int> hash_map;
    
    for (int i = 0; i < arr.size(); i++) {
        if (hash_map.find(arr[i]) == hash_map.end()) {
            hash_map[arr[i]] = 1;
        } else {
            hash_map[arr[i]] += 1;
        }
    }
    
    return hash_map;
}

pair<int, int> get_maxKey_maxValue(unordered_map<int, int>& hash_map) {
    int max_key = 0;    // 원소의 수는 1 ~ 9
    int max_value = 0;
    
    for (auto it : hash_map) {
        if (it.second > 1) {
            if (it.second > max_value) {
                max_key = it.first;
                max_value = it.second;
            } else if (it.second == max_value) {
                if (it.first > max_key) {
                    max_key = it.first;
                    max_value = it.second;
                }
            }
        }
    }
    
    return make_pair(max_key, max_value);
}

int get_answer(int key1, int value1, int key2, int value2) {
    if (key1 == 0 && key2 == 0) {
        return 0;
    } else {
        if (value1 > value2) {
            return 1;
        } else if (value1 < value2) {
            return 2;
        } else {    // value1 = value2
            if (key1 > key2) {
                return 1;
            } else if (key1 < key2) {
                return 2;
            } else {    // key1 == key2
                return 0;
            }
        }
    }
}

int solution(vector<int> arr1, vector<int> arr2) {
    unordered_map<int, int> hash_map1 = get_hash_map(arr1);
    unordered_map<int, int> hash_map2 = get_hash_map(arr2);
    pair<int, int> p1 = get_maxKey_maxValue(hash_map1);
    pair<int, int> p2 = get_maxKey_maxValue(hash_map2);
    // key1, value1, key2, value2
    return get_answer(p1.first, p1.second, p2.first, p2.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    vector<int> arr1, arr2;
    arr1.push_back(1);
    arr1.push_back(5);
    arr1.push_back(7);
    arr1.push_back(2);
    arr1.push_back(9);
    
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(9);
    arr2.push_back(4);
    arr2.push_back(8);
    
    cout << solution(arr1, arr2) << '\n';
    return 0;
}

