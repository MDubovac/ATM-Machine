#include <stdio.h>
#include <string.h>

/* User Struct */
struct User {
  char cardHolderFirstName[20];
  char cardHolderLastName[20];
  int cardNumber;
  int pin;
  float balance;
};

int main() {
  /* Dummy User */
  struct User user1;
  strcpy(user1.cardHolderFirstName, "Mladen");
  strcpy(user1.cardHolderLastName, "Dubovac");
  user1.cardNumber = 123456;
  user1.pin = 1234;
  user1.balance = 21350.50;

  /* A variable that shows weather the user is finished or not */
  int finished = 0;

  /* Log in */
  int cardNumber;
  int pin;

  printf("Enter your card number please: ");
  scanf("%d", &cardNumber);

  printf("Enter your PIN please: ");
  scanf("%d", &pin);

  if(cardNumber != user1.cardNumber || pin != user1.pin) {
    printf("Wrong credentials!");
  } else {
    printf("Welcome %s %s\n", user1.cardHolderFirstName, user1.cardHolderLastName);
    
    /* Check if the user is finished */
    while(finished != 1) {
      
      /* Display all the actions */
      printf(" Available actions:\n");
      printf("  1.Check balance\n");
      printf("  2.Withdrawal\n");
      printf("  3.Deposit\n");

      /* Get the action by index */
      int actionIndex;
      printf("Enter the wanted action: ");
      scanf("%d", &actionIndex);

      /* Prepare all the variables needed for any of the user actions */
      float toWithdraw;
      float toDeposit;
      
      switch(actionIndex) {
        case 1: /* Show balance */
          printf("%f EUR", user1.balance);
          break;
        case 2: /* Withdrawal */
          printf("Enter the amount of money to withdraw: ");
          scanf("%f", &toWithdraw);
          if(toWithdraw > user1.balance) {
            printf("Insufficient funds!");
            continue;
          } else {
            user1.balance -= toWithdraw;
            printf("You have withdrew: %f EUR\n", toWithdraw);
            printf("New balance: %f EUR", user1.balance);
          }
          break;
        case 3: /* Deposit */
          printf("Enter the amount of money to deposit: ");
          scanf("%f", &toDeposit);
          user1.balance += toDeposit; 
          printf("Deposit successfull!\n");
          printf("New balance: %f EUR\n", user1.balance);
        default:
          printf("Invalid action index");
          break;
      }

      /* Ask the user if he/she is finished */
      char areYouFinished;
      printf("\nAre you finished? y/Yes / n/No\n");
      scanf(" %c", &areYouFinished);

      if(areYouFinished == 'y') {
        printf("Goodbye %s.", user1.cardHolderFirstName);
        finished = 1;
      } else {
        continue;
      }
    }
  }
  return 0;
}
