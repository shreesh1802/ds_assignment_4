#include <iostream>
#include <queue>
#include <climits>
using namespace std;


int minIndex(queue<int>& q, int n) {
    int min_index = -1;
    int min_val = INT_MAX;
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        if (curr <= min_val && i < n) {
            min_index = i;
            min_val = curr;
        }

        q.push(curr); // put it back
    }
    return min_index;
}


void moveMinToRear(queue<int>& q, int min_index) {
    int size = q.size();
    int min_val = 0;

    for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        if (i == min_index)
            min_val = curr;  // found the minimum
        else
            q.push(curr);    // keep others in queue
    }

    q.push(min_val); // move min to the end
}

void sortQueue(queue<int>& q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i + 1);
        moveMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
