#include "header.h"

bool is_list_empty (List L){
	return (L.first == NULL);
}

bool is_only_have_one_data(List L){
	return (L.first->next == NULL);
}

void create_empty_list(List *L){
	L->first = NULL;
}

address memory_allocation (str judul, str penulis){
	address temp;
	
	temp = malloc(sizeof(tNode));
	
	strcpy(temp->judul, judul);
	strcpy(temp->penulis, penulis);
	temp->next = NULL;
	
	return temp;
}

void insert_first(List *L, str judul, str penulis){
	address temp = memory_allocation(judul, penulis);
	
	temp->next = L->first;
	
	L->first = temp;
	
	printf("\n[+] Data berhasil dimasukkan");
}
void insert_last(List *L, str judul, str penulis){
	address temp, last;
	
	if(is_list_empty(*L)){
		insert_first(L, judul, penulis);
	}else{
		temp = memory_allocation(judul, penulis);
		 
		last= L->first;
		while(last->next!= NULL){
			last = last->next;
		}
		last->next = temp;
		
		printf("\n[+] Data berhasil dimasukkan");
	}
}

void delete_first(List *L){
	address temp;
	
	if(is_list_empty(*L)){
	
	}else{
		temp = L->first;
		
		L->first = temp->next;
		
		free(temp);
		
	
	}
}


void delete_last(List *L){
	address temp, hapus;
	
	if(is_list_empty(*L)) {
		printf("\nList Kosong, tidak ada data yang dihapus");
	}else{
		if(is_only_have_one_data(*L)){
			delete_first(L);
		}else{
			temp = L->first;
			
			while(temp->next->next!=NULL){
				temp = temp->next;
			}
			
			hapus = temp->next;
			temp->next = NULL;
			free(hapus);
		}
	}
}

void print_list(List L){
	
	address temp;
	
	if(is_list_empty(L)){
		printf("\nList kosong, tidak ada data yang ditampilkan\n");
	}else{
		temp = L.first;
		printf("\n--- [ Tampil Buku ] ---");
		while(temp!=NULL){
			printf("\n-------------------------");
			printf("\nJudul Buku : %s", temp->judul);
			printf("\nPenulis : %s", temp->penulis);
			printf("\n-------------------------\n");
		
			temp = temp->next;
		}
	}
}


