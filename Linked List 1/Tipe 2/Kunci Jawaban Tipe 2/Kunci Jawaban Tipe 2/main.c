#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	List L;
	List RevList;
	address active;
	bool cek = false;
	int countData=0;
	str tempJudul;
	str tempPenyanyi;
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
		printf("Atma Song\n");
		if(!is_list_empty(L)){
			printf("\nLagu yang sekarang diputar: ");
			printf("\nJudul : %s", active->judul);
			printf("\nPenyanyi : %s", active->penyanyi);
		}else{
			printf("\n[!] Tidak ada Lagu yang diputar [!]\n");
		}
		
		printf("\nDibuat oleh NAMA - KELAS - NPM\n\n");
		printf("[1] Masukkan Data Lagu\n");
		printf("[2] Tampilkan Data\n");
		printf("[3] Hapus Data Song\n");
		printf("[4] Previous Song\n");
		printf("[5] Next Song\n");
		printf("[TUGAS]\n");
		printf("[6] Update Lagu yang diputar\n");
		printf("Pilih menu: ");scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Masukkan Judul Lagu : ");fflush(stdin);gets(tempJudul);
				while(strcmp(tempJudul,"")==0){
					printf("\n[!] Judul tidak boleh kosong [!]\n");
					printf("\nMasukkan Judul Lagu : ");fflush(stdin);gets(tempJudul);
				}
				
				printf("\nMasukkan penyanyi : ");fflush(stdin);gets(tempPenyanyi);
				while(strcmp(tempPenyanyi,"")==0){
					printf("\n[!] Penyanyi tidak boleh kosong [!]\n");
					printf("\nMasukkan penyanyi : ");fflush(stdin);gets(tempPenyanyi);
				}
				insert_last(&L, tempJudul, tempPenyanyi);
			
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
					printf("\n[!] Tidak ada Lagu yang terdaftar saat ini [!]");
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
					if(!is_only_have_one_data(L)){
						address bantu = L.first;
						while(bantu->next->next!=NULL){
							bantu = bantu->next;
						}
						cariBack = bantu->next;
						active = cariBack;
						printf("\n[!] Skip ke Lagu terakhir");
						
					}else{
					
					}
//					printf("\n[!] Tidak ada lagu sebelumnya");
				}else{
					cariBack = L.first;
					while(cariBack->next != active){
						cariBack = cariBack->next;
					}
					active = cariBack;
					printf("\n\t[!] Berhasil kembali ke lagu sebelumnya");
				}			
			break;
			
			case 5:
				if(countData == 0 ){
					printf("\nTidak ada lagu selanjutnya");
				}else{
					if(active->next == NULL){
						active = L.first;
//						printf("\n[!] Tidak ada Lagu selanjutnya");
						printf("\n[!] Kembali ke lagu pertama");
					}else{
						active = active->next;
						printf("\nBerhasil pindah ke lagu selanjutnya");
					}
				}
			break;
			
			case 6 :
				if(countData == 0 ){
					printf("\nTidak ada halaman aktif");
				}else{
					printf("Masukkan Judul Lagu : ");fflush(stdin);gets(tempJudul);
					while(strcmp(tempJudul,"")==0){
						printf("\n[!] Judul tidak boleh kosong [!]\n");
						printf("\nMasukkan Judul Lagu : ");fflush(stdin);gets(tempJudul);
					}
					
					printf("Masukkan penyanyi : ");fflush(stdin);gets(tempPenyanyi);
					while(strcmp(tempPenyanyi,"")==0){
						printf("\n[!] Penyanyi tidak boleh kosong! [!]\n");
						printf("\nMasukkan penyanyi : ");fflush(stdin);gets(tempPenyanyi);
					}
					strcpy(active->judul, tempJudul);
					strcpy(active->penyanyi, tempPenyanyi);
					printf("\n[~] Berhasil mengupdate lagu ");
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
