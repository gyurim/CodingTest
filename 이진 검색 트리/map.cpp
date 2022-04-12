#include <iostream>
#include <map>
using namespace std;

void map_example() {
    map<string, int> m;
    m["hi"] = 123;
    m["bkd"] = 1000;
    m["gogo"] = 165; 
    // ("bkd", 1000), ("gogo", 165), ("hi", 123)
    cout << m.size() << '\n'; // 3
    m["hi"] = -7; // ("bkd", 1000), ("gogo", 165), ("hi", 1-7)
    if (m.find("hi") != m.end())
        cout << "hi in m\n";
    else cout << "hi not in m\n";
    m.erase("bkd"); // ("gogo", 165), ("hi", -7);
    for (auto e : m)
        cout << e.first << ' ' << e.second << '\n';
    
    auto it1 = m.find("gogo");
    cout << it1->first << ' ' << it1->second << '\n'; // gogo 165
}