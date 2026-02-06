//Name         : Muhammed Mishab
//Date         : 29-12-2025
//Description  : Inverted Search Engine



#include "validate.h"

main_node *hash_table[27];

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("\nERROR: Missing command line arguments!\n");
        printf("Usage: <./a.out> <file1.txt> <file2.txt> ...\n\n");
        return FAILURE;
    }

    Slist *head = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (extntion(argv[i]) == FAILURE)
        {
            continue;
        }

        if (empty(argv[i]) == FAILURE)
        {
            continue;
        }

        if (duplicate(head, argv[i]) == FAILURE)
        {
            printf("WARNING: File %s is a duplicate file\n", argv[i]);
            continue;
        }

        if (insert_at_last(&head, argv[i]) == FAILURE)
        {
            continue;
        }

        printf("SUCCESS: File %s added to the linked list\n", argv[i]);
        print_list(head);
    }

    int option, flag = 0, count = 0;

    while (1)
    {
        printf("\n-----------------------------------------------\n");
        printf("        INVERTED SEARCH ENGINE - MAIN MENU\n");
        printf("-----------------------------------------------\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Update Database\n");
        printf("4. Search Database\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("Enter your option : ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                if (flag == 0)
                {
                    flag = 1;
                    if (create_database(head, hash_table) == SUCCESS)
                    {
                        printf("\nSUCCESS: Files added to database successfully!\n");
                    }
                    else
                    {
                        printf("\nFAILURE: Files not added to database successfully!\n");
                    }
                }
                else
                {
                    printf("\nWARNING: Database creation already completed!\n");
                }
                break;

            case 2:
                if (display_database(hash_table) == SUCCESS)
                {
                    printf("\nSUCCESS: Data displayed successfully\n");
                }
                else
                {
                    printf("\nFAILURE: Data not displayed\n");
                }
                break;

            case 3:
            {
                char str1[10];
                printf("Enter file name : ");
                scanf("%s", str1);

                if (extntion(str1) == FAILURE)
                {
                    continue;
                }

                if (flag == 1)
                {
                    printf("\nWARNING: Database creation completed. Update not possible!\n");
                }
                else if (count == 1)
                {
                    printf("\nWARNING: Database update already completed!\n");
                }
                else
                {
                    count = 1;
                    if (update_database(&head, hash_table, str1) == SUCCESS)
                    {
                        printf("\nSUCCESS: Data updated successfully\n");
                    }
                    else
                    {
                        printf("\nFAILURE: Data not updated\n");
                    }
                }
                break;
            }

            case 4:
                if (search_database(hash_table) == SUCCESS)
                {
                    printf("\nSUCCESS: Search completed successfully\n");
                }
                else
                {
                    printf("\nFAILURE: Word not found in database\n");
                }
                break;

            case 5:
            {
                char str[10];
                printf("Enter file name : ");
                scanf("%s", str);

                if (extntion(str) == FAILURE)
                {
                    continue;
                }

                if (save_database(hash_table, str) == SUCCESS)
                {
                    printf("\nSUCCESS: Database saved to %s successfully!\n", str);
                }
                else
                {
                    printf("\nFAILURE: Database not saved!\n");
                }
                break;
            }

            case 6:
                printf("\nThank you for using Inverted Search Engine!\n");
                printf("Exiting...\n\n");
                return SUCCESS;

            default:
                printf("\nERROR: Invalid option! Please try again.\n");
        }
    }
}
