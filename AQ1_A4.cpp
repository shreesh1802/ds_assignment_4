#include <iostream>
#include <queue>
#include <string>
using namespace std;

void generateBinary(int n) {
    if (n <= 0) return;

    queue<string> q;
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string current = q.front();
        q.pop();

        cout << current;
        if (i < n) cout << ", ";  // formatting

      
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n = 5;
    generateBinary(n);
    return 0;
}
