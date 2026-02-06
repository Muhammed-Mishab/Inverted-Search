#include "validate.h"

int update_database(Slist **head, main_node *hash_table[], char *file)
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        return FAILURE;
    }

    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '#')
        {
            int index, file_count, word_count;
            char word[100], fname[100];

            fscanf(fp, "%d;%[^;];%d;", &index, word, &file_count);

            main_node *new_main = malloc(sizeof(main_node));
            if (!new_main)
                return FAILURE;

            strcpy(new_main->word, word);
            new_main->file_count = file_count;
            new_main->link = NULL;
            new_main->mainlink = NULL;

            sub_node *sub_head = NULL;
            sub_node *sub_tail = NULL;

            while (fscanf(fp, "%[^;];%d;", fname, &word_count) == 2)
            {
                sub_node *new_sub = malloc(sizeof(sub_node));
                if (!new_sub)
                    return FAILURE;

                strcpy(new_sub->file_name, fname);
                strcpy(new_sub->words, word);
                new_sub->word_count = word_count;
                new_sub->link = NULL;

                if (!sub_head)
                    sub_head = sub_tail = new_sub;
                else
                {
                    sub_tail->link = new_sub;
                    sub_tail = new_sub;
                }
            }

            new_main->link = sub_head;

            if (hash_table[index] == NULL)
            {
                hash_table[index] = new_main;
            }
            else
            {
                main_node *temp = hash_table[index];
                while (temp->mainlink)
                    temp = temp->mainlink;
                temp->mainlink = new_main;
            }
        }
    }

    fclose(fp);
    return SUCCESS;
}
