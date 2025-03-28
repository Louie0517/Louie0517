#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define YELLOW  "\x1b[33m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define MAGENTA "\x1b[35m"
#define RED "\x1b[31m"
#define MAXCHAR 60
#define MAXLEN 100
#define USERSCORE 0


char username[MAXLEN][MAXCHAR];
char password[MAXLEN][MAXCHAR];
int playerScores[MAXLEN];
int playerRank[MAXLEN];
int numberOfuser = 0;

void menuScreen(int userPosition);
void leaderBoard();
int addition(int userPosition);
int subtraction(int userPosition);
int multiplication(int userPosition);
int division(int userPosition);
void creatingAccScreen();
void userHaveAcc();
void authenticationScreen();


int main(){
    srand(time(NULL));
    authenticationScreen();
    return 0;
}
void creatingAccScreen() {
    FILE *usernames = fopen("Usernames record.txt", "a+");
    system("cls");
    if (usernames == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char temporaryUsername[MAXCHAR];
    char temporaryPassword[MAXCHAR];
    char userInput[5];

    printf(MAGENTA"\n\t\t\t\t||============"RESET);
    printf(" \033[38;5;218mCREATE ACCOUNT\033[0m");
    printf(MAGENTA" ============||\n"RESET);
    printf("\n\t\t\t\tUsername: ");
    scanf(" %[^\n]", temporaryUsername);

    for (int i = 0; i < numberOfuser; i++) {
        if (strcmp(username[i], temporaryUsername) == 0) {
            printf("\t\t\t\tUsername already exists. Try a new one.\n");
            printf("\t\t\t\tDo you want to login? (yes/no): ");
            scanf(" %[^\n]", userInput);

            fclose(usernames);
            if (strcasecmp(userInput, "yes") == 0) {
                userHaveAcc();
            } else {
                authenticationScreen();
            }
            return;
        }
    }

    printf("\n\t\t\t\tPassword: ");
    scanf(" %[^\n]", temporaryPassword);

    strcpy(username[numberOfuser], temporaryUsername);
    strcpy(password[numberOfuser], temporaryPassword);
    playerScores[numberOfuser] = 0;
    int newUserPosition = numberOfuser;
    numberOfuser++;

    fprintf(usernames, "Username: %s, Password: %s\n", temporaryUsername, temporaryPassword);
    fclose(usernames);

    printf(GREEN "\n\t\t\t\tAccount created successfully!\n" RESET);
    printf("\t\t\t\tDo you want to take the quiz now? (yes/no): ");
    scanf(" %[^\n]", userInput);

    if (strcasecmp(userInput, "yes") == 0) {
        menuScreen(newUserPosition);
    } else {
        authenticationScreen();
    }
}

void userHaveAcc() {
    int userPosition = -1, valid = 0;
    char temporaryUsername[MAXCHAR];
    char temporaryPassword[MAXCHAR];
    int attempts = 3;

    system("cls");
    printf(MAGENTA"\n\t\t\t\t||============ ");
    printf(" \033[1;35mLOGIN\033[0m");
    printf(MAGENTA" ============||\n"RESET);

    while (attempts > 0 && !valid) {
        printf("\n\t\t\t\t\tAttempts remaining: %d\n", attempts);
        printf("\t\t\t\t\tUsername: ");
        scanf(" %[^\n]", temporaryUsername);
        printf("\t\t\t\t\tPassword: ");
        scanf(" %[^\n]", temporaryPassword);

        valid = 0;
        for (int i = 0; i < numberOfuser; i++) {
            if (strcmp(username[i], temporaryUsername) == 0) {
                if (strcmp(password[i], temporaryPassword) == 0) {
                    valid = 1;
                    userPosition = i;
                    break;
                } else {
                    printf("\t\t\t\t\tIncorrect password.\n");
                    break;
                }
            }
        }

        if (!valid && attempts > 1) {
            attempts--;
            printf("\t\t\t\t\tLogin failed. Please try again.\n");
        } else {
            attempts--;
        }
    }

    if (valid) {
        system("cls");
        menuScreen(userPosition);
    } else {
        printf("\t\t\t\t\tToo many failed attempts. Returning to main menu...\n");
        system("pause");
    }
}

void authenticationScreen() {
    char userInput[5];

    while(1) {
        system("cls");
        printf(MAGENTA"\n\t\t\t\t||============ "RESET);
        printf(" \033[38;5;218mARITHMETIC QUIZ\033[0m ");
        printf(MAGENTA" ============||\n"RESET);
        printf(YELLOW"\n\t\t\t\t\t1. Create account\n\t\t\t\t\t2. Login\n\t\t\t\t\t3. Exit"RESET);
        printf(YELLOW"\n\t\t\t\t\tChoose option (1/2/3): ");
        scanf(" %[^\n]", userInput);


        if (strcmp(userInput, "1") == 0) {
            if (numberOfuser >= MAXLEN) {
                printf("\t\t\t\t\tSorry, maximum number of users reached.\n");
                system("pause");
            } else {
                creatingAccScreen();
            }
        }
        else if (strcmp(userInput, "2") == 0) {
            if (numberOfuser == 0) {
                printf(RED"\n\t\t\t\t\tNo accounts exist. Please create one first.\n"RESET);
                system("pause");
            } else {
                userHaveAcc();
            }
        }
        else if (strcmp(userInput, "3") == 0) {
            exit(0);
        }
        else {
            printf("\t\t\t\t\tInvalid choice. Please try again.\n");
            system("pause");
        }
    }
}

void menuScreen(int userPosition){
    char letter;
 while(1){

        system("cls");
        leaderBoard();

    printf(MAGENTA"\n\n\n\n\n\n\t\t\t||==============================================================||\n\n\n"RESET);
    printf("\t\t\tPICK CHOICES\n");
    printf("\t\t\tA - Addition\n\t\t\tS - Subtraction\n\t\t\tM - Multiplication\n\t\t\tD - Division\n\t\t\tL - Logout\n\t\t\tE - Exit\n");
    printf("\t\t\tEnter your choice: ");
    scanf(" %c", &letter);
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
                multiplication(userPosition);
                break;
            case 'D' : case 'd':
                system("cls");
                division(userPosition);
                break;
            case 'L' : case 'l':
                return;
            case 'E' : case 'e':
                exit(1);
                break;
            default:
                printf("You entered wrong input\n");
                system("pause");
                break;
        }
    }
}

void leaderBoard(){
    system("cls");


    FILE *file;

    if(file == NULL){
        printf("File can't find");
        return;
    }

    file = fopen("ranking records.txt", "a+");
    printf(MAGENTA"\n\t\t\t||========================="RESET);
    printf(" \033[38;5;218mLEADERBOARD\033[0m");
    printf(MAGENTA" ========================||\n"RESET);

    int bScores[MAXLEN];
    int space[MAXLEN];

    for(int i = 0; i < numberOfuser; i++){
        bScores[i] = playerScores[i];
        space[i] = i;
    }

    for(int i = 0; i < numberOfuser - 1; i++){
        for(int j = 0; j < numberOfuser - 1; j++){
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

    printf(YELLOW"\t\t\t\tRANK\t\tPLAYER NAME\t\t\tSCORE\n"RESET);
    fprintf(file, "RANK\t\tPLAYER NAME\t\tSCORE");
    printf(MAGENTA"\t\t\t||==============================================================||\n"RESET);
    for(int i = 0; i < numberOfuser; i++){
        int rnk = space[i];
        printf(" \t\t\t\t%i\t\t%s\t\t\t%i\n", i+1, username[rnk], playerScores[rnk]);
        fprintf(file, "\n%i\t\t%s\t\t\t%i\n", i+1, username[rnk], playerScores[rnk]);

    }

     fclose(file);
     fflush(stdout);
}

int addition(int userPosition){
    int a, b, score = 0, first, second, answer, sum, limit = 4;

    printf(MAGENTA"\n\t\t\t\t\t0===== "RESET);
    printf("\033[38;5;218mADDITION QUIZ\033[0m");
    printf(MAGENTA" =====0\n"RESET);
    while(limit > 0){
        a = (rand() % 12) + 1;
        b =(rand() % 12) + 1;
        sum = a + b;
        printf("\n%i + %i\n", a, b);
        printf("Enter your answer: ");
        scanf("%i", &answer);

        if(sum == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(sum != answer){
            printf("wrong answer.\n");
            printf(RED"Right answer: %i"RESET, sum);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.\n");
            playerScores[userPosition] += score;
            printf("Game exiting..");
            return score;
        }
    }
    return score;
}
int subtraction(int userPosition){
    int a, b, score = 0, first, second, answer, dif, limit = 4;

    printf(MAGENTA"\n\t\t\t\t\t0===== "RESET);
    printf(" \033[38;5;218mSUBTRACTION QUIZ\033[0m ");
    printf(MAGENTA" =====0\n"RESET);

    while(limit > 0){
        a = (rand() % 12) + 1;
        b = (rand() % 12) + 1;

        dif = a - b;
        printf("\n%i - %i\n", a, b);
        printf("Enter your answer: ");
        scanf("%i", &answer);

        if(dif == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(dif != answer){
            printf("wrong answer.");
            printf(RED"\nRight answer: %i"RESET, dif);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.\n");
            playerScores[userPosition] += score;
            printf("Game exiting..");
            return score;
        }
    }
    return score;
}
int multiplication(int userPosition){
    int a, b, score = 0, first, second, answer, prod, limit = 4;

    printf(MAGENTA"\n\t\t\t\t\t0===== "RESET);
    printf(" \033[38;5;218mMULTIPLICATION QUIZ\033[0m");
    printf(MAGENTA" =====0\n"RESET);

    while(limit > 0){
        a = (rand() % 11) + 1;
        b = (rand() % 11) + 1;
        printf("\n%i * %i\n", a, b);
        prod = a * b;
        printf("Enter your answer: ");
        scanf("%i", &answer);

        if(answer == -1) {
            playerScores[userPosition] += score;
            return score;
        }
        if(prod == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(prod != answer){
            printf("wrong answer.\n");
            printf(RED"\nRight answer: %i"RESET, prod);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.\n");
            playerScores[userPosition] += score;
            printf("Game exiting..");
            return score;
        }
    }
    return score;
}

int division(int userPosition){
    int a, b,  score = 0, first, second, div, limit = 4, answer;
    double decimal;

    printf(MAGENTA"\n\t\t\t\t\t0===== "RESET);
    printf(" \033[38;5;218mDIVISION QUIZ\033[0m");
    printf(MAGENTA" =====0\n"RESET);

    while(limit > 0){
        b = (rand() % 11) + 1;
        a = b * (rand() % 12) + 1;
        printf("\n%i / %i\n", a, b);
        div = a / b;
        printf("Enter your answer: ");
        scanf("%lf", &decimal);
        answer = (int) decimal;

        if(div == answer){
            printf("Correct answer.\n");
            score++;
        }
        else if(div != answer){
            printf("wrong answer.");
            printf(RED"\nRight answer: %i"RESET, div);
            limit--;
        }

        if(limit == 0){
            printf("You reached your limit.\n");
            playerScores[userPosition] += score;
            printf("Game exiting..");
            return score;
        }
    }
    return score;
}

