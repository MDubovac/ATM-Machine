#include <stdio.h>
#include <math.h>
#include <string.h>

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

  /* Log In */
  int cardNumber;
  int pin;

  printf("Enter your card number please: ");
  scanf("%d", &cardNumber);

  printf("Enter your PIN please: ");
  scanf("%d", &pin);

  if(cardNumber == user1.cardNumber && pin == user1.pin) {
    printf("Welcome %s %s", user1.cardHolderFirstName, user1.cardHolderLastName);
  } else {
    printf("Wrong credentials!");
  }

  return 0;
}

