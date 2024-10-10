#include "header.h"

int main(int argc, char *argv[]) {
	int menu;
	List L;
	List RevList;
	address active;
	bool cek = false;
	int countData=0;
	str tempJudul;
	str tempUrl;
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
		printf("Atma Web\n");
		if(!is_list_empty(L)){
			printf("\nWeb yang sekarang aktif: ");
			printf("\nJudul : %s", active->judul);
			printf("\nURL : %s", active->url);
		}else{
			printf("\n[!] Tidak ada web yang aktif [!]\n");
		}
		
		printf("\nDibuat oleh NAMA - KELAS - NPM\n\n");
		printf("[1] Masukkan Data Web\n");
		printf("[2] Tampilkan Data\n");
		printf("[3] Hapus Data Pengguna\n");
		printf("[4] Previous Page\n");
		printf("[5] Next Page\n");
		printf("[TUGAS]\n");
		printf("[6] Update Page Aktif\n");
		printf("Pilih menu: ");scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Masukkan Judul Website : ");fflush(stdin);gets(tempJudul);
				while(strcmp(tempJudul,"")==0){
					printf("\n[!] Judul tidak boleh kosong [!]\n");
					printf("\nMasukkan Judul Website : ");fflush(stdin);gets(tempJudul);
				}
				
				printf("\nMasukkan URL : ");fflush(stdin);gets(tempUrl);
				while(strcmp(tempUrl,"")==0){
					printf("\n[!] URL tidak boleh kosong [!]\n");
					printf("\nMasukkan URL : ");fflush(stdin);gets(tempUrl);
				}
				insert_last(&L, tempJudul, tempUrl);
				if(cekPrevious == false){
					cari = L.first;			
					while(cari->next!=NULL){
						cari = cari->next;
					}
					active = cari;
					countData++;
				}
			break;
			
			case 2 :				
				print_list(L);
			break;
			
			case 3 :
				if( is_list_empty (L)){
					printf("\n[!] Tidak ada web yang terdaftar saat ini [!]");
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
						printf("\n[!] Maju ke web terakhir");
						
					}else{
					
					}
//					printf("\n[!] Tidak ada halaman sebelumnya");
				}else{
					cariBack = L.first;
					while(cariBack->next != active){
						cariBack = cariBack->next;
					}
					active = cariBack;
					cekPrevious = true;
					printf("\n\t[!] Berhasil kembali ke halaman sebelumnya");
					
				}			
			break;
			
			case 5:
				if(countData == 0 ){
					printf("\nTidak ada halaman selanjutnya");
				}else{
					if(active->next == NULL){
						active = L.first;
//						printf("\n[!] Tidak ada halaman selanjutnya");
						printf("\n[!] Kembali ke halaman pertama");
					}else{
						active = active->next;
						printf("\nBerhasil pindah ke halaman selanjutnya");
					}
				}
			break;
			
			case 6 :
				if(countData == 0 ){
					printf("\nTidak ada halaman aktif");
				}else{
					printf("Masukkan Judul Website : ");fflush(stdin);gets(tempJudul);
					while(strcmp(tempJudul,"")==0){
						printf("Judul tidak boleh kosong!");
						printf("\nMasukkan Judul Website : ");fflush(stdin);gets(tempJudul);
					}
					
					printf("Masukkan URL : ");fflush(stdin);gets(tempUrl);
					while(strcmp(tempUrl,"")==0){
						printf("URL tidak boleh kosong!");
						printf("\nMasukkan Judul Website : ");fflush(stdin);gets(tempUrl);
					}
					strcpy(active->judul, tempJudul);
					strcpy(active->url, tempUrl);
					printf("\n[~] Berhasil mengupdate web");
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
