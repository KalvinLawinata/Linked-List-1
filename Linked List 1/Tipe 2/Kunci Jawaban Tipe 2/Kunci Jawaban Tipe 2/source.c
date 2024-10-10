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

address memory_allocation (str judul, str penyanyi){
	address temp;
	
	temp = malloc(sizeof(tNode));
	
	strcpy(temp->judul, judul);
	strcpy(temp->penyanyi, penyanyi);
	temp->next = NULL;
	
	return temp;
}

void insert_first(List *L, str judul, str penyanyi){
	address temp = memory_allocation(judul, penyanyi);
	
	temp->next = L->first;
	
	L->first = temp;
	
	printf("\n[+] Data berhasil dimasukkan");
}
void insert_last(List *L, str judul, str penyanyi){
	address temp, last;
	
	if(is_list_empty(*L)){
		insert_first(L, judul, penyanyi);
	}else{
		temp = memory_allocation(judul, penyanyi);
		 
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
		printf("\n--- [ Tampil Lagu ] ---");
		while(temp!=NULL){
			printf("\n-------------------------");
			printf("\nJudul Lagu : %s", temp->judul);
			printf("\nPenyanyi : %s", temp->penyanyi);
			printf("\n-------------------------\n");
		
			temp = temp->next;
		}
	}
}

void reverse_list(List *L, int countData){
	address prev = NULL;
    address current = (*L).first;
    address next = NULL;
	
	 
    while (current != NULL) {
        // Simpan pointer ke node berikutnya
        next = current->next;
     
        // Balikkan arah pointer 'next' dari node sekarang
        current->next = prev;
        
        // Pindahkan 'prev' dan 'current' maju satu langkah
        prev = current;
        current = next;
    }
    
    // Perbarui pointer ke node pertama di list
    (*L).first = prev;
	print_list(*L);
}
