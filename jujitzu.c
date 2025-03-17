#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int userGuess, generator, attempts = 3, lose = 0;
    srand(time(NULL));
    generator = rand() % 100;

    while(!lose){
            printf("\nEnter you guess: ");
            scanf("%i", &userGuess);
            if(generator > userGuess){
                printf("Too large..");
                attempts--;
            } else if(generator < userGuess){
                printf("Too small..");
                attempts--;
            } else{
                printf("You guessed it..");
                printf("\nRandom number is:%i", generator);
            }

            if(attempts == 0){
                printf("\nTrials are gone..");
                printf("\nThe correct answer: %i", generator);
                lose = 1;
        }
    }
    return 0;
}
