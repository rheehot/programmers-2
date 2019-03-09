#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<pair<double, double> > process_times;
    for (int i = 0; i < lines.size(); i++) {
        string tokens1  = lines[i].substr(11, 12);
        double cp_hour   = stod(tokens1.substr(0, 2));
        double cp_minute = stod(tokens1.substr(3, 2));
        double cp_sec    = stod(tokens1.substr(6, 6));
        double cp_time   = stod(to_string(cp_hour*3600 + cp_minute*60 + cp_sec));
        
        size_t index = lines[i].find("s");
        double pcss_time = stod(lines[i].substr(24, index-24));
        double st_time   = cp_time - pcss_time + 0.001f;
        process_times.push_back(make_pair(st_time, cp_time));
    }
    
    for (int i = 0; i < process_times.size(); i++) {
        int count = 0;
        double cp_time = process_times[i].second;
        for (int j = i; j < process_times.size(); j++) {
            double st_time = process_times[j].first;
            if (st_time - 1.f < cp_time) {
                ++count;
            }
        }
        answer = max(answer, count);
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cout << fixed;
    cout.precision(4);
    
    vector<string> lines;
    lines.push_back("2016-09-15 20:59:57.421 0.351s");
    lines.push_back("2016-09-15 20:59:58.233 1.181s");
    lines.push_back("2016-09-15 20:59:58.299 0.8s");
    lines.push_back("2016-09-15 20:59:58.688 1.041s");
    lines.push_back("2016-09-15 20:59:59.591 1.412s");
    lines.push_back("2016-09-15 21:00:00.464 1.466s");
    lines.push_back("2016-09-15 21:00:00.741 1.581s");
    lines.push_back("2016-09-15 21:00:00.748 2.31s");
    lines.push_back("2016-09-15 21:00:00.966 0.381s");
    lines.push_back("2016-09-15 21:00:02.066 2.62s");
    cout << solution(lines) << '\n';
   
    lines.clear();
    lines.push_back("2016-09-15 01:00:04.001 2.0s");
    lines.push_back("2016-09-15 01:00:07.000 2s");
    cout << solution(lines) << '\n';
    
    lines.clear();
    lines.push_back("2016-09-15 01:00:04.002 2.0s");
    lines.push_back("2016-09-15 01:00:07.000 2s");
    cout << solution(lines) << '\n';
    
    lines.clear();
    lines.push_back("2016-09-15 00:00:00.000 3s");
    cout << solution(lines) << '\n';
    
    lines.clear();
    lines.push_back("2016-09-15 23:59:59.999 0.001s");
    cout << solution(lines) << '\n';
    return 0;
}
