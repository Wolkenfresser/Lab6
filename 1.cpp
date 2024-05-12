#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Функция для добавления кандидата
void addCandidate(vector<string>& candidates) {
    string name;
    cout << "Enter the name of the candidate: ";
    getline(cin, name);
    candidates.push_back(name);
    cout << "Candidate added successfully." << endl;
}

// Функция для удаления кандидата
void removeCandidate(vector<string>& candidates) {
    if (candidates.empty()) {
        cout << "No candidates to remove." << endl;
        return;
    }

    cout << "Current candidates:" << endl;
    for (size_t i = 0; i < candidates.size(); ++i) {
        cout << i + 1 << ". " << candidates[i] << endl;
    }

    cout << "Enter the index of the candidate to remove: ";
    string indexStr;
    getline(cin, indexStr);
    int index;
    try {
        index = stoi(indexStr);
    }
    catch (const std::exception& e) {
        cout << "Invalid input." << endl;
        return;
    }

    if (index < 1 || index > static_cast<int>(candidates.size())) {
        cout << "Invalid index." << endl;
        return;
    }

    candidates.erase(candidates.begin() + index - 1);
    cout << "Candidate removed successfully." << endl;
}

// Функция для генерации и отображения списка кандидатов
void generateAndDisplayVotingList(const vector<string>& candidates) {
    if (candidates.empty()) {
        cout << "No candidates to display." << endl;
        return;
    }

    cout << "Voting list:" << endl;
    for (const auto& candidate : candidates) {
        cout << "- " << candidate << endl;
    }
}

int main() {
    vector<string> candidates;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add candidate" << endl;
        cout << "2. Remove candidate" << endl;
        cout << "3. Generate and display voting list" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        string choiceStr;
        getline(cin, choiceStr);

        int choice;
        try {
            choice = stoi(choiceStr);
        }
        catch (const std::exception& e) {
            cout << "Invalid choice" << endl;
            continue;
        }

        switch (choice) {
        case 1:
            addCandidate(candidates);
            break;
        case 2:
            removeCandidate(candidates);
            break;
        case 3:
            generateAndDisplayVotingList(candidates);
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
