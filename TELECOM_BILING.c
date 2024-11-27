#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_OF_RECORDS 100

char current_flow[10] = "continue";
int current_no_of_records = 0;

void Add_New_record();
// void view_records();
// void modify_records();
// void search_records();
// void delete_records();
void basic_manual();
void print_all_comands();
void strlwr(char string[])
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] >= 'A' && string[i] <= 'Z')
        {
            string[i] += 32;
        }
    }
}
void print_all_data();

struct Customer
{
    int age;
    char name[100];
    unsigned customer_number;
    char address[100];
    char gender;
};

struct Customer *Customers = NULL;

int main()
{
    char current_command[10];
    basic_manual();
    do
    {
        printf(">> ");
        scanf("%s", current_command);
        strlwr(current_command);
        if (strcmp(current_command, "help") == 0)
        {
            print_all_comands();
        }
        else if (strcmp(current_command, "new_data") == 0)
        {
            Add_New_record();
        }
        else if (strcmp(current_command, "print_data") == 0)
        {
            print_all_data();
        }
        else if (strcmp(current_command, "exit") == 0)
        {
            strcpy(current_flow, "exit");
        }
    } while (strcmp(current_flow, "continue") == 0);
    sleep(1);
    printf("\n.....Closing System!...\n\n");
    sleep(1);
    free(Customers);
    return 0;
}

void basic_manual()
{
    printf("\nWelcome To The Telecom billing system!\nList of all commands; \n");
    printf("1.'new_data': Adds new records \n2.'search': Search a particular record\n");
    printf("3. 'delete' : Delete a particular or a set of records\n4. 'modify' : Change a particualr record\n");
    printf("5. 'help' : To search for commands\n6. 'exit' : Exits the program\n");
    printf("7. 'print_data : Prints all available records\n\n");
}

void print_all_comands()
{
    printf("\n1.'new_data': Adds new records \n2.'search': Search a particular record\n");
    printf("3. 'delete' : Delete a particular or a set of records\n4. 'modify' : Change a particualr record\n");
    printf("5. 'help' : To search for commands\n6. 'exit' : Exits the program\n\n");
}

void Add_New_record()
{
    FILE *fptr = fopen("customer_data.txt", "a"), *fptr1 = fopen("current_no_records.txt", "w");
    if (fptr == NULL || fptr1 == NULL)
    {
        printf("\nError in Creating File!\n");
    }
    int no_of_records;
    printf("\nEnter the no of records you want to input: ");
    scanf("%d", &no_of_records);
    current_no_of_records += no_of_records;
    fprintf(fptr1, "%d ", no_of_records);
    if (current_no_of_records <= MAX_OF_RECORDS)
    {
        Customers = (struct Customer *)malloc(no_of_records * sizeof(struct Customer));
        if (Customers == NULL)
        {
            printf("Allocation was unsucessfull! \n");
        }
        for (int i = 0; i < no_of_records; i++)
        {
            printf("Enter customer name: ");
            scanf("%s", Customers[i].name);
            fprintf(fptr, "%s ", Customers[i].name);
        }
        free(Customers);
        fclose(fptr);
    }
    printf("\n\n");
}

void print_all_data()
{
    FILE *fileptr = fopen("customer_data.txt", "r"), *fptr1 = fopen("current_no_records.txt", "r");

    if (fileptr == NULL || fptr1 == NULL)
    {
        printf("Error in Reading File!\n");
    }
    char name[10];
    fscanf(fptr1, "%d", &current_no_of_records);
    printf("Current No of records = %d\n", current_no_of_records);
    for (int i = 0; i < current_no_of_records; i++)
    {
        fscanf(fileptr, "%s", name);
        printf("Name: %s\n", name);
    }
    fclose(fileptr);
    printf("\n\n");
}
