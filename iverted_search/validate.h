#ifndef VALIDATE_H
#define VALIDATE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct sub
{
    char words[100];
    int word_count;
    char file_name[25];
    struct sub *link;
} sub_node;

typedef struct single
{
    char file[30];
    struct single *link;
} Slist;

typedef struct hash
{
    int index;
    struct main *link;
} Hash;

typedef struct main
{
    int file_count;
    char word[27];
    char file[20][30];
    struct sub *link;
    struct main *mainlink;
} main_node;

int extntion(char *filename);
int empty(char *filename);
int insert_at_last(Slist **head, char *file);
void print_list(Slist *head);
int duplicate(Slist *head, char *filename);
int create_database(Slist *head, main_node *hash_table[]);
int display_database(main_node *hash_table[]);
int save_database(main_node *hash_table[], char *file);
int search_database(main_node *hash_table[]);
int update_database(Slist **head, main_node *hash_table[], char *file);
void delete_file_from_list(Slist **head, char *filename);
int hash_function(char *word);

#endif
