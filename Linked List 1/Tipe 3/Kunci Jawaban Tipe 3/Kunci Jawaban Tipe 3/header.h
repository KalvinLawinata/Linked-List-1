#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>

typedef char str[64];

typedef struct Node *address;

typedef struct Node{
	str judul;
	str channel;
	address next;
}tNode;

typedef struct{
	address first;
}List;

bool is_list_empty (List L);
bool is_only_have_one_data(List L);

void create_empty_list(List *L);
address memory_allocation (str judul, str channel);

void insert_first(List *L, str judul, str channel);
void insert_last(List *L, str judul, str channel);

void delete_first(List *L);
void delete_last(List *L);

void print_list(List L);
void reverse_list(List *L, int countData);
