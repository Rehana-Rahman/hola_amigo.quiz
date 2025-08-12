#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct Question {
    string lyric;
    string missingWord;
};

int main() {
    vector<Question> questions = {
        {"Hola amigo, kaise ho ____?", "theek ho"},
        {"Aunty ko bolna \"I'm sending my ____\"", "love"},
        {"It's the return of the ____", "mack"},
        {"Sune tere word hi hai ____", "cap"},
        {"Mere shabd ka wazan hai jaise ____", "cement"},
        {"Dilli ke launde ki buddhi ____", "garam"},
        {"Tu choot ka ____, teri fuddi dharm", "ghulam"},
        {"Dilli ke launde ki ____, garam", "buddhi"},
        {"Dilli ke launde hai ____, ", rakam "kutti"},
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

    srand(time(0));
    random_shuffle(questions.begin(), questions.end());

    system("clear");
    cout << "\n=== 🎤 Hola Amigo Lyric Quiz ===\n";
    cout << "Guess the missing word from Seedhe Maut's track!\n";
    cout << "----------------------------------------------\n";

    int score = 0;

    for (int i = 0; i < questions.size(); i++) {
        cout << "\n" << questions[i].lyric << "\n> ";
        string ans;
        cin >> ans;

        if (ans == questions[i].missingWord) {
            cout << "✅ Correct!\n";
            score++;
        } else {
            cout << "❌ Wrong! Answer: " << questions[i].missingWord << "\n";
        }
    }

    cout << "\n🎯 Final Score: " << score << "/" << questions.size() << "\n";
    if (score == questions.size()) {
        cout << "🔥 Perfect! You’re a Hola Amigo OG!\n";
    } else if (score > (questions.size() / 2)) {
        cout << "💪 Get better mf!\n";
    } else {
        cout << "📚 Seedhe maut nahi sunte? Ngmi.\n";
    }

    return 0;
}
g++ seedhemaut_quiz.cpp -o seedhemaut_quiz
./seedhemaut_quiz
./seedhemautquiz
