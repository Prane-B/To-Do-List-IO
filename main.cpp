#include <iostream>
#include <vector>
#include <string>
#include <fstream>

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
    ifstream todolist("task.txt");
    while (getline(todolist, add)) {
        todo.push_back(add);
    }
    ofstream todolist2("task.txt");
    while (true) {
        cin >> cmd;
        cin.ignore(); // Ignore the newline character left in the buffer
        if (cmd == "add") {
            getline(cin, add);
            todo.push_back(add);
            todolist2 << add << endl;
        }
        else if (cmd == "edit") {
            cin >> j;
            cin.ignore();
            getline(cin, add);
            todo[j] = add;
            ofstream file("task.txt", ios::out | ios::trunc);
            for (const auto& task : todo) {
                file << task << endl;
            }
        }
        else if (cmd == "list") {
            checklist();
        }
        else if (cmd == "remove") {
            cin >> j;
            todo.erase(todo.begin() + j);
            ofstream file("task.txt", ios::out | ios::trunc);
            for (const auto& task : todo) {
                file << task << endl;
            }
        }
        else if (cmd == "exit") {
            return 0;
        }
        else if (cmd == "help") {
            cout << "add - Add a task" << endl;
            cout << "edit - Edit a task" << endl;
            cout << "list - List all tasks" << endl;
            cout << "remove - Remove a task" << endl;
            cout << "exit - Exit the program" << endl;
        }
        else
        {
            cout << "Invalid command type help for help" << endl;
        }

    }
}