#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

/*
(*) Write a simple version of the game Hangman. The computer outputs a character string on the screen in which the characters of a word are replaced by _. By guessing individual letters, letters of the word can be uncovered. These are then displayed in the word. You can choose up to seven letters and also have 3 chances to guess the entire word. If you guess the word, you win, after the third unsuccessful guess you lose. E.g.:
-------- // a is choen
-------- // e is chonsen
------E- // o is chosen
-O----E- // MONDBIER is guessed
-O----E-
...
Note: Under this specification there is a file called words.o and an associated header file words.h. words.o includes a compiled function get_word that returns a string containing a randomly chosen German word. This can be used as a secret starting word for a game round. (Since words.o is a pre-compiled file, it cannot be used on all systems. It should work on almighty, the terminals in the computer labs and in the provided virtual machine.)

In order to upload your program, it must not contain external references. So you would have to provide your own get_word function that for example always returns the same string or not use get_word at all.
*/

class Hangman {
private:
    vector<string> words;
    string word;
    string guessedLetters;

    void GetWords(const filesystem::path &path) {
        ifstream fin{path};
        words.reserve(2'000'000);  // das arbeitet in CLion, aber in VSCode nicht, keine Ahnung warum

        for (string buf; getline(fin, buf);)
            words.push_back(buf);
    }

    string GetRandomWord() {
        random_device rd;
        mt19937_64 gen{rd()};
        uniform_int_distribution<size_t> dist(0, words.size() - 1);
        auto w = words[dist(gen)];

        for (auto &c: w)
            c = static_cast<char>(toupper(c));

        return w;
    }

    void Initialize() {
        guessedLetters.clear();
        word = GetRandomWord();
        DrawWord();
    }

    void Greet() {
        for (char o = 'y'; o == 'y' || o == 'Y';) {
            cout << "Game started!\n";
            Initialize();
            cout << (StartGame() ? "You won!\n" : "You lost!\n");
            cout << "Game ended!\n";
            cout << "The word was " << word;
            cout << "\nDo you want to continue? y/n\n";
            cin >> o;
        }
    }

    bool StartGame() {
        for (uint16_t tries = 3; tries > 0;) {
            auto c = GetLetter();
            if (word.find(c) != string::npos) {
                guessedLetters += c;
                DrawWord();
                if (WordIsGuessed())
                    return true;
            }
            else
                cout << "Wrong letter! " << --tries << " tries are left!\n";
        }
        return false;
    }

    static char GetLetter() {
        char c{};
        while (!isalpha(c)) {
            cout << "Choose a letter: ";
            cin >> c;
            c = static_cast<char>(toupper(c));
        }
        return c;
    }

    void DrawWord() {
        for (const auto letter: word)
            cout << (guessedLetters.find(letter) != string::npos ? letter : '_');
        cout << endl;
    }

    bool WordIsGuessed() {
        return all_of(word.begin(), word.end(),
                      [&](const char letter) -> bool { return guessedLetters.find(letter) != string::npos; });
    }

public:
    explicit Hangman(string_view path) {
        GetWords(path);
        Greet();
    }
};

int main() {
    Hangman hangman{"wordlist-german.txt"};  // https://gist.github.com/MarvinJWendt/2f4f4154b8ae218600eb091a5706b5f4#file-wordlist-german-txt
    return 0;
}

/*
Input:
a
b
c
d
e
f
n

Output:
Game started!
_______________
Choose a letter: a
________A______
Choose a letter: b
_______BA______
Choose a letter: c
Wrong letter! 2 tries are left!
Choose a letter: d
Wrong letter! 1 tries are left!
Choose a letter: e
__E__E_BA___E__
Choose a letter: f
Wrong letter! 0 tries are left!
You lost!
Game ended!
The word was QUELLENBAUSTEIN
Do you want to continue? y/n
*/