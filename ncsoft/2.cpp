#include <string>
#include <vector>
#include <regex>
#include <iostream>

using namespace std;

int solution(vector<string> birth) {
    int answer = 0;
    
    regex re("\\d{4}-\\d{2}-\\d{2}");

    for (auto bth : birth) {
        if (regex_match(bth, re)) {
            regex y_re("(\\d{4})-(\\d{2})-(\\d{2})");
            smatch match;

            if (regex_match(bth, match, y_re)) {
                string y = match[1].str();
                string m = match[2].str();
                string d = match[3].str();

                int yy = atoi(y.c_str());
                int mm = atoi(m.c_str());
                int dd = atoi(d.c_str());

                if (yy < 1900 || yy > 2021) continue;
                if (mm >= 1 && mm <= 9) {
                    string rightMM = "0" + to_string(mm);
                    if (rightMM != m) continue;
                }
                if (dd >= 1 && dd <= 9) {
                    string rightDD = "0" + to_string(dd);
                    if (rightDD != d) continue;
                }

                if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12) {
                    if (dd < 0 || dd > 31) continue;
                }

                if (mm == 4 || mm == 6 || mm == 9 || mm == 11) {
                    if (dd < 0 || dd > 30) continue;
                }

                if (mm == 2) {
                    // 윤년 체크 
                    if (yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) {
                        if (dd < 0 || dd > 29) continue;
                    } else {
                        if (dd < 0 || dd > 28) continue;
                    }
                }
                answer++;
                // cout << yy << " " << mm << " " << dd << endl;
            }
        }
    }
    return answer;
}

int main() {
    vector<string> birth {"-2019-12-29-", "1945--10-31", "----------", "20000-123-567"};
    cout << solution(birth);
    return 0;
}