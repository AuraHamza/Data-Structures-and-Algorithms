// windows_trie_autocomplete_full.cpp
// Compile on Windows (Visual Studio or g++/MinGW on Windows)

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cctype>
using namespace std;

// ------------------ Trie ------------------
class trie_node {
public:
    trie_node* children[26];
    bool isend;
    trie_node() {
        isend = false;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};

class Trie {
public:
    trie_node* root;
    Trie() { root = new trie_node(); }

    static string normalize(const string &s) {
        string out;
        for (char c : s) 
            if (isalpha((unsigned char)c))
                out.push_back((char)tolower((unsigned char)c));
            
        return out;
        
    }

    void insert(const string &rawWord) {
        string word = normalize(rawWord);
        if (word.empty()) return;

        trie_node* cur = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!cur->children[idx]) cur->children[idx] = new trie_node();
            cur = cur->children[idx];
        }
        cur->isend = true;
    }

    void collect(trie_node* node, const string &prefix, vector<string> &out, int limit = 50) {
        if (!node) return;
        if (node->isend) {
            out.push_back(prefix);
            if ((int)out.size() >= limit) return;
        }
        for (int i = 0; i < 26 && (int)out.size() < limit; ++i) {
            if (node->children[i]) {
                collect(node->children[i], prefix + char('a' + i), out, limit);
            }
        }
    }

    vector<string> suggestions(const string &rawPrefix, int limit = 50) {
        string prefix = normalize(rawPrefix);
        vector<string> out;

        trie_node* cur = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!cur->children[idx]) return out;
            cur = cur->children[idx];
        }

        collect(cur, prefix, out, limit);
        return out;
    }

    void preloadSamples() {
        vector<string> sample = {
            "cat","cap","car","care","carbon","cart","cartoon","cater",
            "dog","door","dot","dove","data","date",
            "apple","apply","application","apt","aptitude",
            "search","sea","season","second","secure"
        };
        for (auto &w : sample) insert(w);
    }
};

// ------------------ Console helpers ------------------
void setColor(int color) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}

void renderInputWithGhost(const string &typed, const string &ghost) {
    setColor(7);
    cout << "Search: " << typed;

    if (!ghost.empty()) {
        if (ghost.size() >= typed.size() && ghost.substr(0, typed.size()) == typed) {
            string rem = ghost.substr(typed.size());
            setColor(8);
            cout << rem;
            setColor(7);
        }
    }
    cout << "\n\n";
}

// ------------------ Live Autocomplete ------------------
void liveAutocompleteMode(Trie &trie) {
    string typed = "";
    string ghost = "";

    cout << "Live inline autocomplete mode.\n";
    cout << "TAB to accept suggestion, ENTER to submit, ESC to return\n\n";

    fflush(stdin);

    while (true) {
        vector<string> sug = trie.suggestions(typed, 20);
        ghost = (!sug.empty() ? "Search !!!!" : typed);

        system("cls");
        renderInputWithGhost(typed, ghost);

        cout << "Suggestions:\n";
        vector<string> show = trie.suggestions(typed, 8);
        if (show.empty()) cout << "  (none)\n";
        else {
            for (size_t i = 0; i < show.size(); i++) {
                if (i == 0) {
                    setColor(144);
                    cout << "  " << show[i] << "  <- top\n";
                    setColor(7);
                } else {
                    cout << "  " << show[i] << "\n";
                }
            }
        }

        cout << "\n(ESC to return)\n";

        int ch = _getch();

        if (ch == 27) return;
        if (ch == 13) {
            system("cls");
            cout << "Search submitted: " << typed << "\n";
            vector<string> results = trie.suggestions(typed, 20);

            if (results.empty()) cout << "No results.\n";
            else {
                for (size_t i = 0; i < results.size(); i++)
                    cout << i + 1 << ". " << results[i] << "\n";
            }
            cout << "\nPress any key...";
            _getch();
            return;
        }
        if (ch == 9) { // TAB
            if (!ghost.empty()) typed = ghost;
            continue;
        }
        if (ch == 8) { // BACKSPACE
            if (!typed.empty()) typed.pop_back();
            continue;
        }
        if (isalpha(ch)) typed.push_back((char)tolower(ch));
    }
}

// ------------------ Menu ------------------

int main() {
    Trie trie;
    trie.preloadSamples();

    while (true) {
        cout << "==== TRIE AUTOCOMPLETE ====\n";
        cout << "1. Insert Word\n";
        cout << "2. Live Inline Autocomplete\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";

        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            string dummy; getline(cin, dummy);
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 1) {
            cout << "Enter word: ";
            string w; cin >> w;
            trie.insert(w);
            cout << "Inserted.\n\n";
        }
        else if (choice == 2) {
            system("cls");
            cin.clear();
            string dummy; getline(cin, dummy);
            liveAutocompleteMode(trie);
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
