/*
 효율성을 따지지 않으면 쉽게 풀 수 있지만, 효율성이 필요한 문제이다.
 문자열 검색을 빠르게 해주는 'Trie' 자료구조를 이용해서 해결해야 한다.
 (후... 쉽지 않다...)
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Trie {
    int count;
    bool finish;
    Trie* next[26];
    
    Trie(): finish(false), count(1) {
        memset(next, 0, sizeof(next));
    }
    
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (next[i]) delete next[i];
        }
    }
    
    void insert(const char* key) {
        if (*key == '\0') {
            finish = true;
            return;
        }
        
        int current = *key - 'a';
        
        if (next[current] == NULL) next[current] = new Trie();
        else next[current]->count++;
        
        next[current]->insert(key + 1);
    }
    
    int find(const char* key) {
        if (*key == '?') {
            int tempCount = 0;
            for (int i = 0; i < 26; i++) {
                if (next[i] != NULL) tempCount += next[i]->count;
            }
            return tempCount;
        }
        
        int current = *key - 'a';
        
        if (next[current] == NULL) return 0;
        
        if (*(key + 1) == '?') return next[current]->count;
        
        return next[current]->find(key + 1);
    }
};

Trie *forwardRoot[10001];
Trie *reverseRoot[10001];

vector<int> solution(vector<string> words, vector<string> queries) {
    

    for (string word : words) {
        size_t wordLength = word.length();
        
        const char* ch = word.c_str();
        
        if (forwardRoot[wordLength] == NULL) {
            forwardRoot[wordLength] = new Trie();
        }
            
        forwardRoot[wordLength]->insert(ch);
        
        string reverseWord = word;
        reverse(reverseWord.begin(), reverseWord.end());
        
        const char* reverseCh = reverseWord.c_str();
        
        if (reverseRoot[wordLength] == NULL) {
            reverseRoot[wordLength] = new Trie();
        }
        
        reverseRoot[wordLength]->insert(reverseCh);
    }
    
    
    vector<int> answer(queries.size());
    
    int index = 0;
    for (string query : queries) {
        size_t queryLength = query.length();

        if (query[queryLength - 1] == '?') {
            const char* ch = query.c_str();

            if (forwardRoot[queryLength] == NULL) {
                index++;
                continue;
            }

            answer[index++] = forwardRoot[queryLength]->find(ch);
        } else {
            string reverseQuery = query;
            reverse(reverseQuery.begin(), reverseQuery.end());
            
            const char* reverseCh = reverseQuery.c_str();
            
            if (reverseRoot[queryLength] == NULL) {
                index++;
                continue;
            }
            
            answer[index++] = reverseRoot[queryLength]->find(reverseCh);
        }
    }
    
    delete forwardRoot[10001];
    delete reverseRoot[10001];

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    
    vector<string> words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
    vector<string> queries = {"fro??", "????o", "fr???", "fro???", "pro?"};
    
    vector<int> answer = solution(words, queries);
    
    for (int cnt : answer) {
        cout << cnt << '\n';
    }
    
    return 0;
}
