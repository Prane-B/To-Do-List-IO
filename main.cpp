#include <iostream>
#include <vector>
#include <string>

using namespace std;

string add;
vector<string> todo = {};
int i = 0;
int j;
string cmd;

void checklist() {
    i = 0;
    for (i; i < todo.size(); i++) {
        cout << i << ". " << todo[i] << endl;
    }
    if (todo.empty()) {
        cout << "No tasks" << endl;
    }
}

int main() {
    while (true) {
        cin >> cmd;
        cin.ignore(); // Ignore the newline character left in the buffer

        if (cmd == "add") {
            getline(cin, add);
            todo.push_back(add);
        }
        else if (cmd == "check") {
            checklist();
        }
        else if (cmd == "remove") {
            cin >> j;
            todo.erase(todo.begin() + j);
        }
        else if (cmd == "exit") {
            break;
        }
    }
    checklist();
    return 0;
}