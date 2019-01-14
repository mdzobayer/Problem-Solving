#include <bits/stdc++.h>

using namespace std;

struct node {

    node() {
        no = 0;
        weight = 0;
    }
    int no, newRoad;
    int weight;
    bool operator < (const node &n) {
        if (weight < n.weight) return true;
        else if (weight > n.weight) return false;
        else {
            if (no < n.no) return true;
            else return false;
        }
    }
    node operator = (const node n) {
        this->no = n.no;
        this->weight = n.weight;
    }
};
bool operator < (const node & x, const node & n) {
    if (x.weight < n.weight) return true;
        else if (x.weight > n.weight) return false;
        else {
            if (x.no < n.no) return true;
            else return false;
        }
}

int main() {

    priority_queue < node > pq;

    node temp;

    for (int i = 1; i < 10; ++i) {
        temp.no = i;
        temp.weight = 10 + i;
         pq.push(temp);
    }
    while(!pq.empty()) {
        temp = pq.top();
        cout << temp.no << " " << temp.weight << endl;
        pq.pop();
    }

    return (0);
}
