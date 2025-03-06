#include <stdio.h>
#include <conio.h>

int pin = 1234; //The pin that needs to be entered
float balance = 1000.0; //The initial balance
 
void checkBalance() {
    printf("\nYour balance is: $%.2f\n", balance);
}

void depositMoney() {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    balance += amount;
    printf("\nDeposit successful. New balance: $%.2f\n", balance);
}

void withdrawMoney() {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= balance) {
        balance -= amount;
        printf("\nWithdrawal successful.\n\nNew balance: $%.2f\n", balance);
    } else {
        printf("\nInsufficient balance.\n");
    }
}

// Function to read PIN and mask it with '****'
int readPIN() {
    int pinEntered = 0;
    printf("\n");
    printf("Enter your PIN: ");
    
    for (int i = 0; i < 4; i++) {
        char ch = getch();
        printf("*");
        
        int digit = ch - '0';

        //Builds the pin from 0 as first digit
        pinEntered = pinEntered * 10 + digit;
    }
    
    printf("\n");
    
    return pinEntered;
}

int main() {
    int user_pin, choice;
    
    // PIN Authentication
    user_pin = readPIN();
    if (user_pin != pin) {
        printf("Invalid PIN.\n");
        printf("\n");
        return 1;
    }

    do {
        //User Menu
        printf("\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit");
        printf("\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                printf("Exiting...\n\n");
                break;
            default:
                printf("\nInvalid choice.Try again\n");
        }
    } while (choice != 4); //Executes when user chooses something other than what's on the list

    return 0;
}


