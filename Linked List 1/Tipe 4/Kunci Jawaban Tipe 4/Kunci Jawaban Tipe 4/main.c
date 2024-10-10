#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	List L;
	List RevList;
	address active;
	bool cek = false;
	int countData=0;
	str tempJudul;
	str tempSutradara;
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
		printf("Atma Bioskop\n");
		if(!is_list_empty(L)){
			printf("\nFilm yang sekarang diputar: ");
			printf("\nJudul film     : %s", active->judul);
			printf("\nNama sutradara : %s", active->sutradara);
		}else{
			printf("\n[!] Tidak ada film yang diputar [!]\n");
		}
		
		printf("\nDibuat oleh NAMA - KELAS - NPM\n\n");
		printf("[1] Masukkan Data Film\n");
		printf("[2] Tampilkan Data\n");
		printf("[3] Hapus Data Film\n");
		printf("[4] Previous Film\n");
		printf("[5] Next Film\n");
		printf("[TUGAS]\n");
		printf("[6] Update film yang diputar\n");
		printf("Pilih menu: ");scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Masukkan Judul film : ");fflush(stdin);gets(tempJudul);
				while(strcmp(tempJudul,"")==0){
					printf("\n[!] Judul film tidak boleh kosong [!]\n");
					printf("\nMasukkan Judul film : ");fflush(stdin);gets(tempJudul);
				}
				
				printf("\nMasukkan nama sutradara : ");fflush(stdin);gets(tempSutradara);
				while(strcmp(tempSutradara,"")==0){
					printf("\n[!] Nama sutradara tidak boleh kosong [!]\n");
					printf("\nMasukkan nama sutradara : ");fflush(stdin);gets(tempSutradara);
				}
				insert_last(&L, tempJudul, tempSutradara);
				
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
					printf("\n[!] Tidak ada film yang terdaftar saat ini [!]");
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
//						printf("\n[!] Skip ke film terakhir");
//						
//					}else{
//					
//					}
					printf("\n[!] Tidak ada film sebelumnya");
				}else{
					cariBack = L.first;
					while(cariBack->next != active){
						cariBack = cariBack->next;
					}
					active = cariBack;
					printf("\n\t[!] Berhasil kembali ke film sebelumnya");
					
				}			
			break;
			
			case 5:
				if(countData == 0 ){
					printf("\nTidak ada film selanjutnya");
				}else{
					if(active->next == NULL){
//						active = L.first;
						printf("\n[!] Tidak ada film selanjutnya");
//						printf("\n[!] Kembali ke film pertama");
					}else{
						active = active->next;
						printf("\nBerhasil pindah ke film selanjutnya");
					}
				}
			break;
			
			case 6 :
				if(countData == 0 ){
					printf("\nTidak ada vido untuk diputar");
				}else{
					printf("Masukkan Judul film : ");fflush(stdin);gets(tempJudul);
					while(strcmp(tempJudul,"")==0){
						printf("\n[!] Judul film tidak boleh kosong [!]\n");
						printf("\nMasukkan Judul film : ");fflush(stdin);gets(tempJudul);
					}
					
					printf("Masukkan nama sutradara : ");fflush(stdin);gets(tempSutradara);
					while(strcmp(tempSutradara,"")==0){
						printf("\n[!] Nama sutradara tidak boleh kosong! [!]\n");
						printf("\nMasukkan nama sutradara : ");fflush(stdin);gets(tempSutradara);
					}
					strcpy(active->judul, tempJudul);
					strcpy(active->sutradara, tempSutradara);
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
