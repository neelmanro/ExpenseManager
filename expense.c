#include <stdio.h>
#include <string.h>
typedef struct {
char category[100];
double price;
} Expense;

int addExpense(Expense number[], int *count,char name[], double price, double budget);
int printSummary(Expense number[], int count);
double moneyLeft(double budget,int count,Expense number[]);
int oldData(int *count,Expense number[]);
void SaveandExit(int count, Expense number[]);

int main(void){
double budget;
int data;
Expense number[1000];
int count = 0;
printf("\n");
printf("--------------------------------\n");
printf("Welcome to the Expense Manager\n\n");
printf("Select 1,2 or 3\n");
printf("1. Add old expenses\n");
printf("2. Do not add old expenses\n");
printf("3. Do not add old expenses and delete the saved ones\n");
printf("Selection-: ");
scanf("%d",&data);
while(1){
if(data == 1){
    oldData(&count, number);
    break;
} else if(data == 2){
    break;
    printf("No previous data added but is still saved\n");
} else if(data == 3){
    printf("No previous data added and deleted the saved expenses\n");
} else {
    printf("Wrong input\n");
    break;
        }
}
printf("\n");
printf("--------------------------------\n");
printf("Welcome to the Expense Manager\n\n");
printf("What is your total Budget: $");
scanf("%lf",&budget);


    
while(1){
int input;
printf("\n");
printf("Select from menu:\n\n");
printf("1.Show summary and Total Money Spent\n\n");
printf("2. Add daily expense\n\n");
printf("3. Money left from Budget\n\n");
printf("4. Exit\n\n");
printf("5. Save and Exit\n\n");
printf("Select option(1,2, 3, 4 or 5) :");
scanf("%d",&input);
if(input == 1){
printSummary(number,count);
} else if(input == 2){
char new_name[100];
double new_price;
printf("Add Catergory: ");
getchar();
scanf("%[^\n]",new_name);
printf("Add price:$ ");
scanf("%lf",&new_price);
addExpense(number,&count,new_name,new_price,budget);
} else if(input == 3){
    moneyLeft(budget,count,number);
} else if(input == 4){
    break;
    printf("Bye Bye!\n");
} else if(input == 5){
    SaveandExit(count,number);
    break;
    printf("Bye Bye\n");
    }else {
    printf("Wrong input\n");
}
}
return 0;
}

int printSummary(Expense number[], int count){
double total_spent = 0;
if(count == 0){
printf("Empty\n");
printf("Total Spent = $0\n");
} else {
printf("--------------------\n");
for(int i = 0;i < count;i++){
printf("Name: %s\n",number[i].category);
printf("Price: %.2f\n",number[i].price);
printf("--------------------\n");
total_spent += number[i].price;
}
    printf("Total money spent: %.1f\n",total_spent);
}
    return total_spent;
}

int addExpense(Expense number[], int *count,char name[], double price,double budget){
double total_spent = 0;
for (int i = 0; i < *count; i++) {
    total_spent += number[i].price;
}
double expense = budget - total_spent;
if(expense < price){
    printf("You are over budget, your remaining budget is: %.1f\n", expense);
    return *count;
} else if(*count == 0){
strcpy(number[0].category, name);
number[0].price = price;
printf("Expense added successfully!\n");
} else {
strcpy(number[*count].category, name);
number[*(count)].price = price; 
printf("Expense added successfully!\n");
}

    (*count)++;

    return *count;
}

double moneyLeft(double budget,int count,Expense number[]){
double moneyLeft = 0;
double total_spent = 0;
for (int i = 0; i < count; i++) {
    total_spent += number[i].price;
}
moneyLeft = budget - total_spent;
printf("Money left = %.1f\n", moneyLeft);
    return moneyLeft;
}   

int oldData(int *count, Expense number[]) {
    FILE *file = fopen("savedBudget.txt", "r");
    if (file == NULL) {
        printf("No previous data found.\n");
        return 1;
    }

    while (fscanf(file, "Category: %[^\n]\nPrice $%lf\n", number[*count].category, &number[*count].price) == 2) {
        (*count)++;
    }

    fclose(file);
    printf("%d previous expenses loaded.\n", *count);
    return (*count);
}


void SaveandExit(int count, Expense number[]){
FILE *file = fopen("savedBudget.txt","w");
if(file == NULL){
    printf("error loading file/cannot create file\n");
} else if(count == 0){
fprintf(file,"error as the list is empty\n");
    } else {
for(int i = 0;i < count;i++){
fprintf(file, "Category: %s\n", number[i].category);
fprintf(file, "Price $%.2f\n", number[i].price);
}
}
    fclose(file);

}
 
    
    