/* Purpose: Author: Pranav Vashisth*/
#include <stdio.h>
#include <stdlib.h>
typedef struct ads
{
    char ad[100];
    struct ads *next;
    struct ads *prev;
} node;
node *create(node *start, int n)
{
    node *temp, *newnode;
    int i;
    for (i = 0; i < n; i++)
    {
        newnode = (node *)malloc(sizeof(node));
        printf("Enter the ad: ");
        fgets(newnode->ad, 100, stdin);
        newnode->next = NULL;
        if (start == NULL)
        {
            start = newnode;
            temp = newnode;
            newnode->prev = NULL;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    return start;
}
void traverse(node *start)
{
    node *temp;
    temp = start;
    while (temp != NULL)
    {
        printf("%s ", temp->ad);
        temp = temp->next;
    }
}
node *display(node *add);
node *add(node *start);
node *del(node *start);
int main()
{
    int n;
    printf("Enter the number of ads you want in the list: ");
    scanf("%d", &n);
    getchar();
    node *start = NULL;
    node *buff = NULL; // for buffer when display is called
    start = create(start, n);
    traverse(start);
    int choice, displayChoice;

    do
    {
        printf("\n1. Add advertisement");
        printf("\n2. Remove advertisement");
        printf("\n3. Display advertisement");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            // Add advertisement
            printf("Enter advertisement: ");
            start = add(start);
            traverse(start);
            break;

        case 2:
            // Remove advertisement
            printf("Enter advertisement to remove: ");
            start = del(start);
            traverse(start);
            break;

        case 3:
            // Display advertisement
            if (start == NULL)
            {
                printf("No advertisements available.\n");
                break;
            }

            printf("Displaying first advertisement...\n");
            buff = start;
            buff = display(buff);

            do
            {
                if (buff->next != NULL)
                    printf("\n1. Show next advertisement");
                if (buff->prev != NULL)
                    printf("\n2. Show previous advertisement");
                printf("\n3. Exit");
                printf("\nEnter your choice: ");
                scanf("%d", &displayChoice);

                switch (displayChoice)
                {
                case 1:
                    if (buff->next != NULL)
                    {
                        buff = buff->next;
                        buff = display(buff);
                        printf("Showing next advertisement...\n");
                    }
                    else
                    {
                        printf("No more advertisements.\n");
                    }
                    break;

                case 2:
                    if (buff->prev != NULL)
                    {
                        buff = buff->prev;
                        buff = display(buff);
                        printf("Showing previous advertisement...\n");
                    }
                    else
                    {
                        printf("No previous advertisement.\n");
                    }
                    break;

                case 3:
                    printf("Exiting advertisement display...\n");
                    break;

                default:
                    printf("Invalid choice, please try again.\n");
                }
            } while (displayChoice != 3);
            break;

        case 4:
            // Exit program
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    return 0;
}
node *display(node *add)
{
    printf("\n%s", add->ad);
    return add;
}
node *add(node *start)
{
    node *temp = start, *p = (node *)malloc(sizeof(node));
    getchar();
    printf("Enter the ad: ");
    fgets(p->ad, 100, stdin);
    p->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = p;
    p->prev = temp;
    return start;
}
node *del(node *start)
{
    node *temp = start;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *abc = temp->next;
    temp->next = NULL;
    free(abc);
    return start;
}