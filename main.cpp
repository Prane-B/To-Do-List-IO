#include <iostream>
#include <vector>

using namespace std;

string add;
vector<string> todo = {};
int i = 0;

void checklist () {
    for (i; i < todo.size(); i++) {
        cout << todo[i] << endl;
    }
    if (0 == todo.size()) {
        cout << "No tasks" << endl;
    }
}

int main() {
    cin >> add;
    todo.push_back(add);
    cin >> add;
    todo.push_back(add);
    cin >> add;
    todo.push_back(add);
    cin >> add;
    todo.push_back(add);
    checklist();
    return 0;
}