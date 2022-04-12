#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
} 

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int denominator = lcm(b, d);
    int numerator = (denominator / b) * a + (denominator / d) * c;

    // 약분 
    int g = gcd(denominator, numerator);
 
    cout << numerator / g << " " << denominator / g << endl; 
    return 0;

}