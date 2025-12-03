#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void withdraw(int *x);
void deposite(int *x);
void progressBar();  
int authentication();
void changePin();

int pin = 0, tempPin;

int main() {
    int choice, balance = 10000;
    char choose;
    
    if(!pin) {
        printf("First of all, create your pin: ");
        scanf("%d", &pin);
        progressBar();

        reenter:
        printf("Enter your pin again: ");
        scanf("%d", &tempPin);
        if(pin == tempPin) {
            printf("Your pin successfully merged to your account\n");
            tempPin = 0;
        } else {
            printf("Re-enter the pin.\n");
            goto reenter;
        }
    }

    start:
    printf("\n-------Menu-------\n");    
    printf("1. Withdraw\n2. Deposit\n3. Check Balance\n4. Change PIN\nYour Choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            withdraw(&balance);
            break;
        case 2:
            deposite(&balance);
            break;
        case 3:
            authentication();
            printf("Your balance is: %d\n", balance);
            break;
        case 4:
            changePin();
            break;
        default:
            printf("Enter a valid option!\n");
    }

    start_2:
    printf("\nDo you want to continue?\n");
    printf("y - continue\nn - end\nYour choice: ");
    scanf(" %c", &choose);

    if (choose == 'y' || choose == 'Y')
        goto start;
    else if (choose == 'n' || choose == 'N')
        return 0;
    else {
        printf("Enter a valid choice!\n");
        goto start_2;
    }
}

void progressBar() {
    int total = 20;
    for (int i = 0; i <= total; i++) {
        printf("\r[");
        for (int j = 0; j < i; j++) printf("#");
        for (int j = i; j < total; j++) printf(" ");
        printf("] %d%%", (i * 100) / total);
        fflush(stdout);
        usleep(200000);
    }
    printf("\r                           \r");
}

void withdraw(int *x) {
    int amount;
    authentication();
    printf("How much you want to withdraw: ");
    scanf("%d", &amount);

    if (*x < amount) {
        printf("You don't have enough money!\n");
    } else {
        printf("\nProcessing withdrawal...\n");
        progressBar();
        *x -= amount;
        printf("\nWithdraw successful!\nAmount withdrawn: %d\n", amount);
    }
}

//deposite function

void deposite(int *x) {
    int amount;
    authentication();
    printf("How much you want to deposit: ");
    scanf("%d", &amount);

    printf("Processing deposit...\n");
    progressBar();
    *x += amount;
    printf("\nAmount successfully added!\nNew Balance: %d\n", *x);
}

int authentication() {
    printf("Enter your pin to continue: ");
    re:
    	scanf("%d", &tempPin);	
    if(pin == tempPin) {
        tempPin = 0;
        return 1;
    } else {
        printf("Access denied!\nRe Enter The Pin : ");
        goto re;
        exit(0);
    }
}

//chane pin number !

void changePin() {
    printf("Please enter your current pin: ");
    scanf("%d", &tempPin);
    if(pin == tempPin) {
        printf("Access Granted!\nEnter your new pin: ");
        scanf("%d", &tempPin);
        pin = tempPin;
        printf("Your New Pin Successfully Merged To Your Bank Account\n")
    } else {
        printf("Contact your nearest bank branch\n");
    }
}


