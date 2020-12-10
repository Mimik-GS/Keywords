//Gabrianna Falcon
// Keywords
// A Code Breaker Training Simulation Program

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //This section is my list of 10 words and their coressponding hints.
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"objective","What's the point of this program?"},
        {"innocent","The person/object has done nothing wrong."},
        {"time","Something everyone wants more of."},
        {"wallet","Where money is stored."},
        {"payments","A pesky thing that likes taking money."},
        {"bottle","Something you drink out of."},
        {"confinement","It's like getting stuck."},
        {"isolation","It's getting lonely here."},
        {"breakdown","Something that is unstable would like to do this."},
        {"release","Let go."}
    };

        //This is to welcome the user, tell them what to do, how to get a hint and to quit.
        cout << "\t\t\tWelcome to Keywords!\n\n";
        cout << "With the enemy going to back to simpler code, we have created this program to train new recruits to \n";
        cout << "deal with this situation. Unscramble the letters below to make a word and practice.\n\n";
        cout << "Enter 'hint' for a hint.\n";
        cout << "Enter 'quit' to quit the game.\n\n";

        //The 'while' will loop through if you ask to play again and 'for' will loop and generate 3 words.
    char again = 'y';
    while (again == 'y')
    {
        for (int i = 0; i < 3; i++)
        {
            srand(static_cast<unsigned int>(time(0)));
            int choice = (rand() % NUM_WORDS);
            string theWord = WORDS[choice][WORD];   //This is the word to guess.
            string theHint = WORDS[choice][HINT];   //The hint for the word.

            string jumble = theWord;  //This is the jumbled version of the word.
            int length = jumble.size();
            for (int i = 0; i < length; ++i)
            {
                int index1 = (rand() % length);
                int index2 = (rand() % length);
                char temp = jumble[index1];
                jumble[index1] = jumble[index2];
                jumble[index2] = temp;
            }

            //Tells the jumbled word and asks for the guess.
            cout << "The jumble is: " << jumble;
            string guess;
            cout << "\n\nYour guess: ";
            cin >> guess;

            //This is looped to ask the user for a guess until they get it right or until the user asks to quit.
            while ((guess != theWord) && (guess != "quit"))
            {
                if (guess == "hint")
                {
                    cout << theHint;
                }
                else
                {
                    cout << "Sorry, that's not it.";
                }

                cout << "\n\nYour guess: ";
                cin >> guess;
            }

            if (guess == theWord)
            {
                cout << "\nThat's it, you guessed it!\n";
            }
        }
   
        cout << "\nYou have guessed all three correct.";
        cout << "\nDo you want to play again? (y/n): ";
        cin >> again;
    }

    cout << "\nGood job and continue practicing later.";

    return 0;
}