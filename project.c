// vechile service record system
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define Node
struct Node
{
    char vehiclenumber[20];
    char name[20];
    char contactnumber[15];
    char vehiclename[20];
    char date[20];
    float cost;
    struct Node *next;
};
// Declare head pointer
struct Node *head = NULL;

// Function To Add New Record
void newRecord(char date[], char vehiclename[], char vehiclenumber[], char name[], char contactnumber[], float cost)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->date, date);
    strcpy(newNode->name, name);
    strcpy(newNode->vehiclename, vehiclename);
    strcpy(newNode->contactnumber, contactnumber);
    strcpy(newNode->vehiclenumber, vehiclenumber);
    newNode->cost = cost;
    newNode->next = head;
    head = newNode;
    printf("Record Enter sucessfully !!\n");
}
// Function to delete a record from Record book

// Functions to check the record by vechile Number
void searchRecords(char vehiclenumber[])
{
    struct Node* temp = head ;
    int found  = 0;
    if (head == NULL)
    {
        printf("Records list is empty !!\n");
    }
        while (temp != NULL)
        {
            if (strcmp(temp->vehiclenumber,vehiclenumber)==0)
            {
                printf("Date : %s\n", temp->date);
                printf("Name : %s\n", temp->name);
                printf("Vehicle Name : %s\n", temp->vehiclename);
                printf("Vehicle Number : %s\n", temp->vehiclenumber);
                printf("Service Cost : %.2f\n", temp->cost);
                printf("Contact Number : %s\n", temp->contactnumber);
                printf("----------------------------\n");
                found =1 ;
            }
            temp = temp->next;
        }
        if(!found)
        {
            printf("Record Not found!!\n");
        }
    }

// Function to View the records of the service of the vechiles
void viewRecords()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("No records found.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("Date : %s\n", temp->date);
        printf("Name : %s\n", temp->name);
        printf("Vehicle Name : %s\n", temp->vehiclename);
        printf("Vehicle Number : %s\n", temp->vehiclenumber);
        printf("Service Cost : %.2f\n", temp->cost);
        printf("Contact Number : %s\n", temp->contactnumber);
        printf("----------------------------\n");
        temp = temp->next;
    }
}


// Function to calculate the parts of the service parts 
void Bill()
{
    int total = 0 , choice ;
    while(1)
    {
        printf("<----- Service Parts ----->\n");
        printf("1.Sets of side mirrors - Rs 1000\n");
        printf("2.Sets of Wipers - Rs 500\n");
        printf("3.Doors - Rs 10000\n");
        printf("4.Seat cover - Rs 1000 (per piece)\n");
        printf("5.Exit\n");
        printf("Section choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 : 
            total = total + 1000 ;
            break;
            case 2 : 
            total = total + 500;
            break;
            case 3 :
            total = total + 10000;
            break;
            case 4 :
            total = total + 4000;
            case 5 :
            exit(0);
            break;
            default :
            printf("No valid option !!\n");
            break;
        }
        printf("Bill : %d",total);
    }
}
// Function to print the receipt of the service 
void Receipt(char name[],char date[], char contactnumber[], char vehiclename[] ,char vehiclenumber[],float cost,float totalAmount)
{
            printf("<----- Receipt ----->\n");
            printf("Name : %s\n",name);
            printf("Date : %s\n",date);
            printf("Contact Number : %s\n",contactnumber);
            printf("Vehicle Name : %s\n",vehiclename);
            printf("Vehicle Number : %s\n",vehiclenumber);
            printf("Service Cost : %0.2f\n",cost);
            printf("Total Amount : %0.2f\n",totalAmount);
            printf("Thank You \n");
            printf("-----------------------\n");
}
// Function to delete the Service record by vechile number 
void deleteRecord(char vehiclenumber[])
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    int found = 0;
    if (head == NULL)
    {
        printf("Record book Empty\n");
        return;
    }
    while (temp != NULL)
    {
        if (strcmp(temp->vehiclenumber, vehiclenumber) == 0)
        {
            found = 1;
            if (prev == NULL)
            {
                head = temp->next; // delete the first node
            }
            else
            {
                prev->next = temp->next;  
            }
            free(temp);
            printf("Record Deleted Successfully\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    if (!found)
    {
        printf("Record Not found\n");
    }
}
// Menu
int main()
{
    while (1)
    {
        printf("<-----vehicle Service Record System ----->\n");
        printf("1.Add new record\n");
        printf("2.Search Service by vehicle number\n");
        printf("3.Delete Service record\n");
        printf("4.View records\n");
        printf("5.Parts\n");
        printf("6.Receipt\n");
        printf("7.Exit\n");
        int choice;
        float cost;
        char date[20],vehiclenumber[20],name[20],contactnumber[15],vehiclename[20];
        printf("Select Option : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("<-----Enter New Record----->\n");
        printf("Enter name : ");
        scanf(" %[^\n]", name);
        getchar();
        printf("Enter Vechile number : ");
        scanf(" %[^\n]", vehiclenumber);
        getchar();
        printf("Enter Vechile name : ");
        scanf(" %[^\n]", vehiclename);
        getchar();
        printf("Enter Contact number : ");
        scanf(" %[^\n]", contactnumber);
        getchar();
        printf("Enter Date : ");
        scanf(" %[^\n]", date);
        getchar();
        printf("Enter cost : ");
        scanf("%f", &cost);
        newRecord(date, vehiclename, vehiclenumber, name, contactnumber, cost);
        break;

        case 2:
        printf("Enter Vehicle Number : ");
        scanf(" %[^\n]",vehiclenumber);
        getchar();
        searchRecords(vehiclenumber);
        break;
        
        case 3:
        printf("Enter Vechile Number : ");
        scanf(" %[^\n]",vehiclenumber);
        getchar();
        deleteRecord(vehiclenumber);
        break;
        
        case 4:
        viewRecords();
        break;

        case 5:
        Bill();
        break;
            
        case 6 :
        printf(" <----- Details ----->\n");
        printf("Name : ");
        scanf(" %[^\n]", name);
        getchar();
        printf("Date : ");
        scanf(" %[^\n]", date);
        getchar();
        printf("Contact Number : ");
        scanf(" %[^\n]", contactnumber);
        getchar();
        printf("Vechile Name : ");
        scanf(" %[^\n]", vehiclename);
        getchar();
        printf("Vehicle Number : ");
        scanf(" %[^\n]", vehiclenumber);
        getchar();
        printf("Service Amount : ");
        scanf("%f",&cost);
        float totalAmount =(cost + (0.18*cost));
        Receipt(name,date,contactnumber,vehiclename,vehiclenumber,cost,totalAmount);
        break;
        
        case 7:
        exit(0);
        break;

        default:
        printf("Choose Valid Option !!\n");
        }
        printf("\n");
    }
    return 0;
}