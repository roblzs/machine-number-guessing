#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

int generate_random_number(){
    int MIN_INT = 0;
    int MAX_INT = 100;

    srand(time(0));

    int random_number = (rand() % MAX_INT) + MIN_INT;

    return random_number;
}

bool check_if_equal(int& correct_number, int& guess){
    bool correct = false;

    if(guess == correct_number){
        correct = true;
    }else if(guess > correct_number){
        cout << "Correct number is smaller than " << guess << endl;
    }else if(guess < correct_number){
        cout << "Correct number is bigger than " << guess << endl;
    }

    return correct;
}

int guess_the_number(int& correct_number){
    int guess = 0;

    cout << endl << "Enter Your guess: ";
    cin >> guess;
    
    return guess;
}

int main(){
    int random_number = generate_random_number();

    cout << "You have 10 attempts to guess the number" << endl;

    int attempts = 10;
    bool correct = false;

    while(attempts > 0 && !correct){
        int guess = guess_the_number(random_number);
        correct = check_if_equal(random_number, guess);

        attempts --;
    }

    if(!correct){
        cout << endl << "You lose!";
    }else{
        cout << endl << "You win!";
    }
}