#include <stdio.h>
#include <string.h>

const char *answers[7] =
 {"18", "Manila", "Tup", "Sinigang na baboy", "Adventure", "Casas", "IT"};

const char *question[7] = {"My age:", "where i lived:", "My school:", "Food i like:", "i love the most:", "my last name:", "My Course:"};

void hangman( const char *answer, int i){
static int wrongAns = 0, plus = 0;

 if ( strcmp(answer, answers[i]) == 0){
      plus++;
      printf("\ncorrect!, score: %i", plus);
      printf("\n");
      return;
    } else {
        wrongAns++;
  switch(wrongAns){
        case 1:
            printf("\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 7:
            printf("\n");
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        default:
            break;
        }
    }
}

void questions(){

  char answer[100];
    for(int i = 0; i < 7; i++){
       printf("%s", question[i]);
       scanf(" %[^\n]", answer);
       hangman(answer, i);
       printf("\n");
   }
}

int main(){

  questions();

  return 0;
  }
