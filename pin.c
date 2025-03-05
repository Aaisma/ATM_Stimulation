#Code for ATM Stimulation

#include <stdio.h>

int pin = 1234;
float balance = 1000.0;

int main() {
    int user_pin, choice;
    
    // PIN authentication
    printf("Enter your PIN: ");
    scanf("%d", &user_pin);
    if (user_pin != pin) {
        printf("Invalid PIN.\n");
        return 1;
    }

    do {
        printf("\n1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Thank You for the Transaction....\n");
                break;
            default:
                printf("Invalid choice. Please Choose between 1 to 4...\n");
        }
    } while (choice != 4);

    return 0;
}
