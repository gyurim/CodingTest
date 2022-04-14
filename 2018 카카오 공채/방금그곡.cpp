// 2022.04.14
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

int getTime(string st, string en)
{
    int hour = atoi(en.substr(0, 2).c_str()) - atoi(st.substr(0, 2).c_str());
    int minute = atoi(en.substr(3, 2).c_str()) - atoi(st.substr(3, 2).c_str());

    return hour * 60 + minute;
}

string setSharp(string str)
{
    while (true) // 모든 경우에 대해 바꾸어줘야함 
    {
        auto it = str.find("C#");
        if (it != string::npos)
        {
            str[it] = 'c';
            str = str.erase(++it, 1);
            continue;
        }
        it = str.find("D#");
        if (it != string::npos)
        {
            str[it] = 'd';
            str = str.erase(++it, 1);
            continue;
        }
        it = str.find("F#");
        if (it != string::npos)
        {
            str[it] = 'f';
            str = str.erase(++it, 1);
            continue;
        }
        it = str.find("G#");
        if (it != string::npos)
        {
            str[it] = 'g';
            str = str.erase(++it, 1);
            continue;
        }
        it = str.find("A#");
        if (it != string::npos)
        {
            str[it] = 'a';
            str = str.erase(++it, 1);
            continue;
        } 
        if (it == string::npos) break;
    }

    return str;
}

string solution(string m, vector<string> musicinfos)
{
    string answer = "(None)";
    int answerTime = 0;
    m = setSharp(m);
    // cout << "m: " << m << endl;
    for (auto musicinfo : musicinfos)
    {
        stringstream ss(musicinfo);
        string token;
        vector<string> info;
        while (getline(ss, token, ','))
        {
            info.push_back(token);
        }

        string music = "";
        int time = getTime(info[0], info[1]);
        int j = 0;
        info[3] = setSharp(info[3]);
        for (int i = 0; i < time; i++)
        {
            music += info[3][j];
            j++;
            if (j == info[3].size())
                j = 0;
        }
        // cout << "music: " << music << endl;

        // music과 m 비교 (연속 구간 비교)
        auto it = music.find(m);
        if (it != string::npos)
        {
            if (answerTime < time)
            {
                answerTime = time;
                answer = info[2];
            }
        }
    }
    return answer;
}

int main()
{
    vector<string> musicinfos{"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};
    cout << solution("CC#BCC#BCC#BCC#B", musicinfos);
    return 0;
}