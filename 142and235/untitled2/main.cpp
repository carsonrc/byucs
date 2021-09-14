#include <iostream>
#include <string>
using namespace std;

int GetUserDecision();// gets the user's decision at each decision point
void DeathByFreezing(); // the most common ending for the game, in a function
int GameReview(); // contains outputs for rating the game
void GameOpinion(string refer, int rating); // asks user for a referral and rating
void Dashes(); // separates the games from one another using a line of a randomly selected character

int main() {

    int userDecision;
    char playAgain = 0;
    do {
        cout << "Welcome to the Multi-Path Camping Game!" << endl;
        cout << "Your objective is to survive, and if you're lucky, get the girl!" << endl;
        cout << "START:" << endl;
        cout << "You decide to go camping over the weekend in Provo Canyon. Do you:\n"
                "a). bring your whole bed and all your jackets... just in case\n"
                "b). pack minimally. Get your Bear Grylls on!" << endl;
        userDecision = GetUserDecision();
        switch (userDecision) {
            case 1:
                cout << "You realize a bit late that you don't have space for your mattress and jackets. Do you:\n"
                        "a). strap it on top?\n"
                        "b). leave it behind?" << endl;
                userDecision = GetUserDecision();
                switch (userDecision) {
                    case 1:
                        cout << "You strap on the mattress and the jackets on top of the '94 Civic, and "
                                "set off. Halfway up the canyon, all your stuff \n flies off the top of the"
                                " car, hitting the car behind you and causing an accident. You get "
                                "arrested for manslaughter.\n"
                                "\n"
                                "END" << endl;//end result aa
                        playAgain = GameReview();
                        if (playAgain != 1) {
                            exit(0);
                        }

                    case 2:
                        DeathByFreezing();
                        playAgain = GameReview();
                        if (playAgain != 1) {
                            exit(0);
                        } //end result ab
                }
                break;
            case 2:
                cout << "You look cool going camping with your minimal gear, but you are freezing to death. Do you:\n"
                        "a). cuddle with your buddy, even though it'll make things weird?\n"
                        "b). die an honorable death, preserving your masculinity?" << endl;
                userDecision = GetUserDecision();
                switch (userDecision) {
                    case 1:
                        cout << "You ask your buddy if you can sleep with him. He looks at you weird and you explain"
                                " that it's the only way to stay warm. Turns out, there are two other guys and a girl"
                                " who didn't bring enough stuff either, and you all end up sharing the\n same two person"
                                " tent. It's the middle of the night and you are regretting your decision. You see that"
                                " there is another\n friend Jack who brought a tent, who has less people with him. Do you:\n"
                                "a). Go and ask if you can sleep with him? \n"
                                "b). Tough it out?" << endl;
                        userDecision = GetUserDecision();
                        switch (userDecision) {
                            case 1:
                                cout << "You approach the tent, and realize that Jack is sharing the tent with his"
                                        " girlfriend. You hear questionable noises.\n Do you:\n"
                                        "a). interrupt to not freeze to death? You gotta do what you gotta do "
                                        "to survive.\n"
                                        "b). Take your chances outside with the cold?" << endl;
                                userDecision = GetUserDecision();
                                switch (userDecision) {
                                    case 1:
                                        cout << "You rather timidly ask if you can sleep with them. Jack glares at you"
                                                " but his girlfriend pities you and lets you in.\n They share their air"
                                                " mattress with you and you sleep warm, even if it's a bit awkward."
                                                " You spend time talking to\n Jack's girlfriend, and eventually she"
                                                " leaves him for you and you get married in the temple.\n"
                                                "\n"
                                                "END" << endl; //end result baaa
                                        playAgain = GameReview();
                                        if (playAgain != 1) {
                                            exit(0);
                                        }

                                    case 2:
                                        DeathByFreezing();//end result baab
                                        playAgain = GameReview();
                                        if (playAgain != 1) {
                                            exit(0);
                                        }

                                }
                                break;
                            case 2:
                                cout << "You spend the whole night getting spooned by your buddy, because there isn't"
                                        " room enough to lay on your back. However, a cute girl is on your other side,"
                                        " and you hit it off well with her. Turns out, she ate a lot of beans for lunch"
                                        " and\n farts such a copious amount that all of you asphyxiate in your sleep.\n"
                                        "END" << endl; //end result bab
                                playAgain = GameReview();
                                if (playAgain != 1) {
                                    exit(0);
                                }
                        }
                        break;
                    case 2:
                        DeathByFreezing(); //end result bb
                        playAgain = GameReview();
                        if (playAgain != 1) {
                            exit(0);
                        }
                        break;
                }


                break;

        }

    }while(playAgain == 1);
}

int GetUserDecision() {
    char userInput;
    int decisionOutput;
    {
        cout << "Choose 'a' or 'b' by inputting the respective character." << endl;
        cin >> userInput;
        switch (userInput) {
            case 'a':
                decisionOutput = 1;
                break;
            case 'b' :
                decisionOutput = 2;
                break;
            default:
                cout << "Invalid input. Input the single character 'a' or 'b'. Start program again." << endl;
        }
    }
    return decisionOutput;
}

void DeathByFreezing(){
    cout << "You freeze to death. Don't you remember the Boy Scout Motto?\n"
            "END" << endl;
}
int GameReview () {
    string refer;
    int rating;
    int playAgain;

    cout << "Did you like this game? Enter 'yes' or 'no' if you would refer it to a friend." << endl;
    cin >> refer;
    cout << "How many stars would you give it? Enter a integer between 0 and 6." << endl;
    cin >> rating;

    GameOpinion(refer, rating);
    cout << "Enter '1' to play again." << endl;
    cin >> playAgain;

    Dashes();

    return playAgain;
}
void GameOpinion(string refer, int rating) {
    if ((refer == "yes") && (rating > 3)) {
        cout << "Thanks! I hope you give me a good grade :)" << endl;
    }
    else if ((refer == "yes") && (rating > 1)) {
        cout << "Why would you refer this to a friend if you don't like it? :(" << endl;
    }
    else {
        cout << "I'm sorry you didn't like it. I hope you find it in\n"
                " your heart to give me a good grade anyway." << endl;
    }
}
void Dashes() { // separates the games from one another using a line of a randomly selected character
    int randCharacterIndex;
    randCharacterIndex = rand() % 3;
    for (int i = 0; i <= 40; i++) {
        if (randCharacterIndex == 0) {
            cout << "-";
        }
        else if (randCharacterIndex == 1){
            cout << "=";
        }
        else if (randCharacterIndex == 2){
            cout << "~";
        }
    }
    cout << endl;
}