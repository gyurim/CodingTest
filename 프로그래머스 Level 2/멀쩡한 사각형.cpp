using namespace std;

long long gcd(int w, int h){
    long c;
    while (h != 0) {
        c = w % h;
        w = h;
        h = c;
    }
    return w;
}

long long solution(int w,int h) {
    long long answer = 1;
    long long W = w;
    long long H = h;
    answer = w + h - gcd(w, h);
    
    return (W * H) - answer;
}