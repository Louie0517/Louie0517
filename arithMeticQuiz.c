#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define MAXCHAR 60
#define MAXLEN 100
#define USERSCORE 0

char username[MAXLEN][MAXCHAR];
char password[MAXLEN][MAXCHAR];
int playerScores[MAXLEN];
int playerRank[MAXLEN];
int numberOfuser = 0;

void authenticationScreen();
void menuScreen(int userPosition);
void leaderBoard();
int addition(int userPosition);
int subtraction(int userPosition);
int multiplication(int userPosition);
int division(int userPosition);


int main(){
    setvbuf(stdout, NULL, _IONBF, 0);
    srand(time(0));
    authenticationScreen();
    return 0;
}

void authenticationScreen(){
    char temporaryUsername[MAXLEN];
    char temporaryPassword[MAXCHAR];
    char userInput[5];
    int valid = 0;

    if(numberOfuser < MAXLEN){
        printf("Create an account");
        printf("\n\nUsername: ");
        fflush(stdout);
        scanf(" %[^\n]", temporaryUsername);
        for(int i = 0; i < numberOfuser; i++){
            if(strcmp(username[i], temporaryUsername) == 0){
                printf("Username already exist. Try new one");
                return;
            }
        }
        printf("\nPassword: ");
        fflush(stdout);
        scanf(" %[^\n]", temporaryPassword);
        strcpy(username[numberOfuser], temporaryUsername);
        strcpy(password[numberOfuser], temporaryPassword);
        playerScores[numberOfuser] = 0;
        numberOfuser++;
        printf("\nDo you already have account?\n");
        printf("Enter Yes if you have account already: ");
        fflush(stdout);
        scanf(" %[^\n]", userInput);
        printf("\n");
        if(strcasecmp(userInput, "YES") == 0){
            while(!valid){
                printf("Login\n\n");
                printf("\n\nUsername: ");
                fflush(stdout);
                scanf(" %[^\n]", temporaryUsername);
                printf("\nPassword: ");
                fflush(stdout);
                scanf(" %[^\n]", temporaryPassword);
                    for(int i = 0; i < numberOfuser; i++){
                        if(strcmp(username[i], temporaryUsername) != 0 && strcmp(password[i], temporaryPassword) == 0){
                            printf("Incorrect username.");
                        }
                        else if(strcmp(username[i], temporaryUsername) == 0 && strcmp(password[i], temporaryPassword) != 0){
                            printf("Incorrect password.");
                        }
                        else if (strcmp(username[i], temporaryUsername) != 0 && strcmp(password[i], temporaryPassword) != 0){
                            printf("Incorrect username and password.");
                        }
                        else if(strcmp(username[i], temporaryUsername) == 0 && strcmp(password[i], temporaryPassword) == 0){
                            system("cls");
                            int userPosition = i;
                            menuScreen(userPosition);
                            valid = 1;
                            break;
                        }
                    }
                }
            }
        }
        else {
                printf("Sorry, maximum number of user reached.");
                exit(1);
            }
}

void menuScreen(int userPosition){
    int alreadyPick = 0;
    char letter;

    leaderBoard();

    printf("\n===== WELCOME TO ARITHMETIC QUIZ =====\n");
    printf("PICK CHOICES\n");
    printf("A - Addition\nB - Subtraction\nM - Multiplication\nD - Division\nL - Logout");
    printf("Enter your choice: ");
    scanf(" %c", &letter);
    while(!alreadyPick){
        switch(letter){
            case 'A': case 'a':
                system("cls");
                addition(userPosition);
                break;
            case 'S' : case 's':
                system("cls");
                subtraction(userPosition);
                break;
            case 'M' : case 'm':
                system("cls");
                multiplication;
                break;
            case 'D' : case 'd':
                system("cls");
                division(userPosition);
                break;
            case 'L' : case 'l':
                exit(1);
            default:
                printf("You entered wrong input");
                break;
        }
        alreadyPick = 1;
    }
}

void leaderBoard(){
    FILE *file;

    if(file == NULL){
        printf("File can't find");
        exit(1);
    }

    file = fopen("ranking records.txt", "w+");
    printf("\n===== LEADERBOARD =====\n");

    int bScores[MAXLEN];
    int space[MAXLEN];

    for(int i = 0; i < numberOfuser; i++){
        bScores[i] = playerScores[i];
        space[i] = i;
    }

    for(int i = 0; i < numberOfuser - 1; i++){
        for(int j = 0; j < numberOfuser - 1; i++){
            if(bScores[j] < bScores[j+1]){
                int tUse = bScores[j];
                bScores[j] = bScores[j+1];
                bScores[j+1] = tUse;

                int idx = space[j];
                space[j] = space[j+1];
                space[j+1] = idx;
            }
        }
    }

    for(int i= 0; i < numberOfuser; i++){
        playerRank[space[i]] = i + 1;
    }

    printf("RANK\tPLAYER NAME\tSCORE\n");
    fprintf(file, "RANK\tPLAYER NAME\tSCORE");
    printf("========================");
    for(int i = 0; i < numberOfuser; i++){
        int rnk = space[i];
        printf("%i\t\t%s\t\t%i\n", i+1, username[rnk], playerScores[rnk]);
        fprintf(file, "%i\t\t%s\t\t%i\n", i+1, username[rnk], playerScores[rnk]);
    }
     printf("========================");

     fclose(file);
}

int addition(int userPosition){
    int a, b, score, first, second, answer, sum, limit = 4, isDone = 0;
    a = rand() % 1000;
    b = rand() % 1000;

    printf("\n===== ADDITION QUIZ =====\n");

    while(!isDone){
        printf("%i + %i\n", a, b);
        sum = a + b;
        printf("Enter your answer: ");
        scanf("%i", &answer);

        if(sum == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(sum != answer){
            printf("wrong answer.\nRight answer: %i", sum);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.");
            isDone = 1;
            playerScores[userPosition] += score;
            return score;
        }
    }
    return score;
}
int subtraction(int userPosition){
    int a, b, score, first, second, answer, dif, limit = 4, isDone = 0;
    a = rand() % 1000;
    b = rand() % 1000;

    printf("\n===== SUBTRACTION QUIZ =====\n");

    while(!isDone){
        printf("%i - %i\n", a, b);
        dif = a - b;
        printf("Enter your answer: ");
        scanf("%i", &answer);

        if(dif == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(dif != answer){
            printf("wrong answer.\nRight answer: %i", dif);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.");
            isDone = 1;
            playerScores[userPosition] += score;
            return score;
        }
    }
    return score;
}
int multiplication(int userPosition){
    int a, b, score, first, second, answer, prod, limit = 4, isDone = 0;
    a = rand() % 1000;
    b = rand() % 1000;

    printf("\n===== MULTIPLICATION QUIZ =====\n");

    while(!isDone){
        printf("%i * %i\n", a, b);
        prod = a * b;
        printf("Enter your answer: ");
        scanf("%i", &answer);

        if(prod == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(prod != answer){
            printf("wrong answer.\nRight answer: %i", prod);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.");
            isDone = 1;
            playerScores[userPosition] += score;
            return score;
        }
    }
    return score;
}
int division(int userPosition){
    int a, b, score, first, second, answer, div, limit = 4, isDone = 0;
    a = rand() % 1000;
    b = rand() % 1000;

    printf("\n===== MULTIPLICATION QUIZ =====\n");

    while(!isDone){
        printf("%i * %i\n", a, b);
        div = a * b;
        printf("Enter your answer: ");
        scanf("%i", &answer);

        if(div == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(div != answer){
            printf("wrong answer.\nRight answer: %i", div);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.");
            isDone = 1;
            playerScores[userPosition] += score;
            return score;
        }
    }
    return score;
}

