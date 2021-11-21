#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

void send_instructions(){
    cout << "Controls:" << endl << "+ bigger" << endl << "- smaller" << endl << "= correct";
}

string ask_if_correct(){
    string input = "";

    cout << "Was I correct? ";
    cin >> input;

    if(input != "+" && input != "-" && input != "="){
        ask_if_correct();
    }   

    return input;
}

bool guess(int& attempt){
    int MIN_INT = 0;
    int MAX_INT = 0;
    int random_number = 50;
    bool has_won = false;
    string was_correct = "";


    srand(time(0));

    cout << endl << "My guess is " << random_number << endl;
    was_correct = ask_if_correct();

    if(was_correct == "-"){
        MAX_INT -= (rand() % 10);
        MIN_INT -= (rand() % 10);
    }else if(was_correct == "+"){
        MAX_INT = 100;
        MIN_INT += (rand() % 10);
    }else if(was_correct == "="){
        has_won = true;
    }

    random_number = (rand() % MAX_INT) + MIN_INT;

    return has_won;
}

int main(){
    int attempts = 10;
    bool correct = false;
    string ready = "";
    string start = "";

    cout << "Think of a number between 0 and 100" << endl << endl; 

    while(attempts >= 0 && !correct){
        correct = guess(attempts);

        attempts --;
    }

    if(!correct){
        cout << endl << "I lost!";
    }else{
        cout << endl << "I won!";
    }
}