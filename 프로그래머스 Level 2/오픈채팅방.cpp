#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
using namespace std;

// vector<string> solution(vector<string> record) {
//     vector<string> answer;
//     vector<pair<int, pair<char, string>>> outputs;

//     cout << record.size();
//     for (int i = 0; i < record.size(); i++) {
       
//         string s = record[i];

//         // 문자열 Tokenize 방법 1 
//         /*
//         string buf;
//         stringstream ss(s);
//         vector <string> tokens;

//         while (ss >> buf) tokens.push_back(buf); // 공백 문자 단위로 split 
//         */

//         // 문자열 Tokenize 방법 2 
//         string divid = " ";
//         vector<string> tokens;
//         char* c = strtok((char*)s.c_str(), divid.c_str()); // strtok은 char 배열만 되기 때문에 변환 필요 
//         // 현재 c에는 첫번째 단어의 주소가 저장되어 있음 

//         while (c != NULL) { // 자를 문자가 보이지 않으면 null 반환 
//             tokens.push_back(c);
//             cout << "c: " << c << endl;
//             c = strtok(NULL, divid.c_str()); 
//             // null을 주게 되면 내부 버퍼에 저장되어 있는 포인터에서 다음 " "을 찾고 그 뒤에 문자열의 주소를 반환 
//         }

//         // 단어 속에서 uid 문자 지우기 
//         tokens[1].replace(tokens[1].find("uid"), 3, ""); // replace(a,b,"c"): a 지점에서 b길이만큼의 문자열이 c 문자열로 교체됨 
    
//         int uid = stoi(tokens[1]);
        
//         if (tokens[0] == "Enter") {
//             cout << "Enter" << endl; 
//             if (outputs.size() > 0 ) {
//                 // change(outputs, uid, tokens[2]);
//                 outputs.push_back(make_pair(uid, make_pair('E', tokens[2])));
//             } else {
//                 outputs.push_back(make_pair(uid, make_pair('E', tokens[2])));
//             }
//         } else if (tokens[0] == "Change") {
//             if (outputs.size() > 0 ) {
//                 // change(outputs, uid, tokens[2]);
//             }     
//         } else if (tokens[0] == "Leave") {
//             // vector<pair<int, pair<char, string>>>::iterator it = find(outputs.begin(), outputs.end(), uid);
//             if (outputs.size() > 0) {
//                 for (int j = 0; j < outputs.size(); j++) {
//                     if (uid == outputs[j].first) {
//                         cout << "uid: " << uid << " outputs.first: " << outputs[j].first << endl;
//                         cout << "find ! " << endl;
//                         outputs.push_back(make_pair(uid, make_pair('L', outputs[j].second.second)));
//                         break;
//                     }
//                 }
//             }
//         }
//         cout << endl;
//     }
    
//     for (int i = 0; i < outputs.size(); i++) {
//         if (outputs[i].second.first == 'E') {
//             string s = outputs[i].second.second + "님이 들어왔습니다.";
//             answer.push_back(s);
//             cout << "answer: " << s << endl;
//         } else if (outputs[i].second.first == 'L') {
//             string s = outputs[i].second.second + "님이 나갔습니다.";
//             answer.push_back(s);
//             cout << "answer: " << s << endl;
//         }
//     }
//     // answer 
//     return answer;
// }

vector<string> solution(vector<string> record) {
	vector <string> answer;
	vector <string> uid; //record에서 아이디만 따로 저장
	map <string, string> nick_Info; //key:아이디 / value:닉네임
	stringstream ss; string action; string id; string nickname;
	for (int i = 0; i < record.size(); i++) {
		ss.str(record[i]);
		ss >> action; //Enter, Leave, Change
		if (action == "Enter") {
			ss >> id;
			ss >> nickname;
			answer.push_back("님이 들어왔습니다.");
			uid.push_back(id);
			nick_Info[id] = nickname;
		}
		else if (action == "Leave") {
			ss >> id;
			answer.push_back("님이 나갔습니다.");
			uid.push_back(id);
		}
		else {
			ss >> id;
			ss >> nickname;
			nick_Info[id] = nickname;
		}
		ss.clear();
	}
	for (int i = 0; i < answer.size(); i++) {
		answer[i] = nick_Info[uid[i]] + answer[i]; //아이디에 해당하는 닉네임을 붙여줌
	}
	return answer;
}
