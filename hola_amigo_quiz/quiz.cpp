#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Question {
    string lyric;
    string missingWord;
};

int main() {
    vector<Question> questions = {
        {"Hola amigo, kese ho ____?", "thik"},
        {"Seedhe maut ka flow hai ____", "danger"},
        {"Baarish ke baad, scene hai ____", "clean"},
        {"Mere shabd ka wazan hai jaise ____", "cement"}
    };

    cout << "\n=== 🎤 Hola Amigo CLI Quiz ===\n";
    cout << "Type the missing word to complete the lyric!\n";
    cout << "--------------------------------------------\n";

    srand(time(0));
    int score = 0;

    for (int i = 0; i < questions.size(); i++) {
        int index = rand() % questions.size();
        Question q = questions[index];

        cout << "\n" << q.lyric << "\n> ";
        string ans;
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
        cout << "🔥 Full marks! Seedhe Maut certified!\n";
    } else if (score > 2) {
        cout << "💪 Good job, you know your bars!\n";
    } else {
        cout << "📚 Time to listen again, rookie.\n";
    }

    return 0;
}
