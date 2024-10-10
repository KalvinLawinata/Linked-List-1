#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	List L;
	List RevList;
	address active;
	bool cek = false;
	int countData=0;
	str tempJudul;
	str tempPenulis;
	address cari;
	address bantu;
	address cariLast;
	address cariBack;
	bool cekPrevious = false;
	create_empty_list(&L);
	create_empty_list(&RevList);

	do{
		system("cls");
		system("color 0E");
		printf("Atma Library\n");
		if(!is_list_empty(L)){
			printf("\nBuku yang sedang ditampilkan: ");
			printf("\nJudul Buku     : %s", active->judul);
			printf("\nNama penulis : %s", active->penulis);
		}else{
			printf("\n[!] Tidak ada Buku yang ditampilkan [!]\n");
		}
		
		printf("\nDibuat oleh NAMA - KELAS - NPM\n\n");
		printf("[1] Masukkan Data Buku\n");
		printf("[2] Tampilkan Data\n");
		printf("[3] Hapus Data Buku\n");
		printf("[4] Previous Buku\n");
		printf("[5] Next Buku\n");
		printf("[TUGAS]\n");
		printf("[6] Update Buku yang ditampilkan\n");
		printf("Pilih menu: ");scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Masukkan Judul Buku : ");fflush(stdin);gets(tempJudul);
				while(strcmp(tempJudul,"")==0){
					printf("\n[!] Judul Buku tidak boleh kosong [!]\n");
					printf("\nMasukkan Judul Buku : ");fflush(stdin);gets(tempJudul);
				}
				
				printf("\nMasukkan nama penulis : ");fflush(stdin);gets(tempPenulis);
				while(strcmp(tempPenulis,"")==0){
					printf("\n[!] Nama penulis tidak boleh kosong [!]\n");
					printf("\nMasukkan nama penulis : ");fflush(stdin);gets(tempPenulis);
				}
				insert_last(&L, tempJudul, tempPenulis);
				
				cari = L.first;			
				while(cari->next!=NULL){
					cari = cari->next;
				}
				active = cari;
				countData++;
				
			break;
			
			case 2 :				
				print_list(L);
			break;
			
			case 3 :
				if( is_list_empty (L)){
					printf("\n[!] Tidak ada Buku yang terdaftar saat ini [!]");
				}else{
					while(countData>0){	
						delete_first(&L);
						countData--;	
					}
					printf("\n[-] Semua data berhasil dihapus");
				}
			break;
			
			case 4:
				if(countData==0 || active==L.first){
//					if(!is_only_have_one_data(L)){
//						address bantu = L.first;
//						while(bantu->next->next!=NULL){
//							bantu = bantu->next;
//						}
//						cariBack = bantu->next;
//						active = cariBack;
//						printf("\n[!] Skip ke Buku terakhir");
//						
//					}else{
//					
//					}
					printf("\n[!] Tidak ada Buku sebelumnya");
				}else{
					cariBack = L.first;
					while(cariBack->next != active){
						cariBack = cariBack->next;
					}
					active = cariBack;
					printf("\n\t[!] Berhasil kembali ke Buku sebelumnya");
					
				}			
			break;
			
			case 5:
				if(countData == 0 ){
					printf("\nTidak ada Buku selanjutnya");
				}else{
					if(active->next == NULL){
//						active = L.first;
						printf("\n[!] Tidak ada Buku selanjutnya");
//						printf("\n[!] Kembali ke Buku pertama");
					}else{
						active = active->next;
						printf("\nBerhasil pindah ke Buku selanjutnya");
					}
				}
			break;
			
			case 6 :
				if(countData == 0 ){
					printf("\nTidak ada buku untuk ditampilkan");
				}else{
					printf("Masukkan Judul Buku : ");fflush(stdin);gets(tempJudul);
					while(strcmp(tempJudul,"")==0){
						printf("\n[!] Judul Buku tidak boleh kosong [!]\n");
						printf("\nMasukkan Judul Buku : ");fflush(stdin);gets(tempJudul);
					}
					
					printf("Masukkan nama penulis : ");fflush(stdin);gets(tempPenulis);
					while(strcmp(tempPenulis,"")==0){
						printf("\n[!] Nama penulis tidak boleh kosong! [!]\n");
						printf("\nMasukkan nama penulis : ");fflush(stdin);gets(tempPenulis);
					}
					strcpy(active->judul, tempJudul);
					strcpy(active->penulis, tempPenulis);
					printf("\n[~] Berhasil mengupdate data ");
				}
			break;
			
			case 0:
				printf("\nMengeluarkan program...");
			break;
			
			default :
				printf("\nMenu tidak tersedia!");
			break;	
			
		}getch();
	}while(menu!=0);
	return 0;
}
