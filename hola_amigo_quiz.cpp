#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random> // for std::shuffle

using namespace std;

struct Question {
    string lyric;
    string missingWord;
};

int main() {
    vector<Question> questions = {
        {"Hola amigo, kaise ho ____?", "theekho"},
        {"Aunty ko bolna \"I'm sending my ____\"", "love"},
        {"It's the return of the ____", "mack"},
        {"Sune tere word hi hai ____", "cap"},
        {"Mere shabd ka wazan hai jaise ____", "cement"},
        {"Dilli ke launde ki buddhi ____", "garam"},
        {"Tu choot ka ____, teri fuddi dharm", "ghulam"},
        {"Dilli ke launde ki ____, garam", "buddhi"},
        {"Dilli ke launde hai ____, kutti", "rakam"},
        {"Pull up with Neena main jaise ____", "Masaba"},
        {"Get set go, ye hai green light ____", "gang"},
        {"Mere G, ni rehta jahan pe pool hai ____", "gehra"},
        {"Haan khainch ke maare tere ____, pe hum", "guddi"},
        {"Hu taira jahan pe koi bhi taira ____", "nahi"},
        {"Hola lekin Amigo tu weak hai ____", "bohat"},
        {"Main ghuse pe gira phir khada hua ____", "right"},
        {"Baap ke ____, nahi khaata", "paise"},
        {"Tere idols ka idol main ____", "Jackson"},
        {"Higher than ____", "Eiffel"},
        {"Bhai mera really ____", "chill"},
        {"Mic pe hai proper ____, bol jahan vahaan mil", "ill"},
        {"Jeben kaafi badi lekin jebon se hai bada ____", "dil"},
        {"Namaste ____", "aunty"}
    };

    // Shuffle the questions
    random_device rd;
    mt19937 g(rd());
    shuffle(questions.begin(), questions.end(), g);

    system("clear");
    cout << "\n=== 🎤 Hola Amigo Lyric Quiz ===\n";
    cout << "Guess the missing word from Seedhe Maut's track!\n";
    cout << "----------------------------------------------\n";

    int score = 0;
    string ans;

    for (auto &q : questions) {
        cout << "\n" << q.lyric << "\n> ";
        cin >> ans;

        if (ans == q.missingWord) {
            cout << "✅ Correct!\n";
            score++;
        } else {
            cout << "❌ Wrong! Answer: " << q.missingWord << "\n";
        }
    }

    cout << "\n🎯 Final Score: " << score << "/" << questions.size() << "\n";
    if (score == questions.size()) {
        cout << "🔥 Perfect! You're a Hola Amigo OG!\n";
    } else if (score > (questions.size() / 2)) {
        cout << "💪 Not bad! Listen more to level up.\n";
    } else {
        cout << "📚 Seedhe Maut nahi sunte? Ngmi.\n";
    }

    return 0;
}

