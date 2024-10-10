#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	List L;
	List RevList;
	address active;
	bool cek = false;
	int countData=0;
	str tempJudul;
	str tempChannel;
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
		printf("Atma Hub\n");
		if(!is_list_empty(L)){
			printf("\nVideo yang sekarang diputar: ");
			printf("\nJudul Video  : %s", active->judul);
			printf("\nNama Channel : %s", active->channel);
		}else{
			printf("\n[!] Tidak ada video yang diputar [!]\n");
		}
		
		printf("\nDibuat oleh NAMA - KELAS - NPM\n\n");
		printf("[1] Masukkan Data Video\n");
		printf("[2] Tampilkan Data\n");
		printf("[3] Hapus Data Video\n");
		printf("[4] Previous Video\n");
		printf("[5] Next Video\n");
		printf("[TUGAS]\n");
		printf("[6] Update video yang diputar\n");
		printf("Pilih menu: ");scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Masukkan Judul Video : ");fflush(stdin);gets(tempJudul);
				while(strcmp(tempJudul,"")==0){
					printf("\n[!] Judul tidak boleh kosong [!]\n");
					printf("\nMasukkan Judul Video : ");fflush(stdin);gets(tempJudul);
				}
				
				printf("\nMasukkan nama channel : ");fflush(stdin);gets(tempChannel);
				while(strcmp(tempChannel,"")==0){
					printf("\n[!] Nama channel tidak boleh kosong [!]\n");
					printf("\nMasukkan nama channel : ");fflush(stdin);gets(tempChannel);
				}
				insert_last(&L, tempJudul, tempChannel);
				
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
					printf("\n[!] Tidak ada video yang terdaftar saat ini [!]");
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
//						printf("\n[!] Skip ke video terakhir");
//						
//					}else{
//					
//					}
					printf("\n[!] Tidak ada video sebelumnya");
				}else{
					cariBack = L.first;
					while(cariBack->next != active){
						cariBack = cariBack->next;
					}
					active = cariBack;
					printf("\n\t[!] Berhasil kembali ke video sebelumnya");
					
				}			
			break;
			
			case 5:
				if(countData == 0 ){
					printf("\nTidak ada video selanjutnya");
				}else{
					if(active->next == NULL){
//						active = L.first;
						printf("\n[!] Tidak ada video selanjutnya");
//						printf("\n[!] Kembali ke video pertama");
					}else{
						active = active->next;
						printf("\nBerhasil pindah ke video selanjutnya");
					}
				}
			break;
			
			case 6 :
				if(countData == 0 ){
					printf("\nTidak ada vido untuk diputar");
				}else{
					printf("Masukkan Judul Video : ");fflush(stdin);gets(tempJudul);
					while(strcmp(tempJudul,"")==0){
						printf("\n[!] Judul tidak boleh kosong [!]\n");
						printf("\nMasukkan Judul video : ");fflush(stdin);gets(tempJudul);
					}
					
					printf("Masukkan nama channel : ");fflush(stdin);gets(tempChannel);
					while(strcmp(tempChannel,"")==0){
						printf("\n[!] Nama channel tidak boleh kosong! [!]\n");
						printf("\nMasukkan nama channel : ");fflush(stdin);gets(tempChannel);
					}
					strcpy(active->judul, tempJudul);
					strcpy(active->channel, tempChannel);
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
