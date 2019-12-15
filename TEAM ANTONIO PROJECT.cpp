#include <iostream>
#include <conio.h>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <stdexcept>
#include "sstream"
#include "string"


using namespace std;

//*Fungsi penambahan tiik "." di setiap angka ribuan dan jutaan pada outputan nominal harga

 string formatangka(int angka, string perantara = ".")
 {
 stringstream ss; ss << angka;
 string output = ss.str();
 int inspost = output.length() -3;
 while (inspost > 0) {
    output.insert(inspost, perantara);
    inspost -= 3;
 }
 return output;
 }

 void garis() // fungsi untuk memberi garis pembatas
 {cout<<"-------------------------------------------------------------"<<endl;}

 //=============================================================================
 // Output dan operasi untuk program Laba-Rugi dengan modal Per-Barang
 toko (int beli[100], int jual[100], int jml[100],int n)
 {
 int i, jum_beli, jum_jual, selisih;
 jum_beli=0;
 jum_jual=0;
 for (i=0; i<n; i++)
 {
 jum_beli=jum_beli+(beli[i]*jml[i]);
 jum_jual=jum_jual+(jual[i]*jml[i]);
 }
 cout<<endl;
 cout<<"Total Harga Beli"<<": Rp. "<<formatangka(jum_beli)<<"  [MODAL yang diperlukan]"<<endl;
 cout<<"Total Harga Jual"<<": Rp. "<<formatangka(jum_jual)<<endl;
 garis();
 if ( jum_jual > jum_beli )
 {
 selisih=jum_jual-jum_beli;cout<<endl;
 cout<<"UNTUNG sebesar  "<<"\t: Rp. "<<formatangka(selisih)<<endl;
 }
 else if (jum_beli > jum_jual )
 {
 selisih=jum_beli-jum_jual;cout<<endl;
 cout<<"RUGI sebesar  "<<"\t: Rp. "<<formatangka(selisih)<<endl;
 }
 else if (jum_beli == jum_jual )
 {
 cout<<"Tidak ada UNTUNG / RUGI "<<endl;
 }
 else
 {
 cout<<"error !";
 }
 return jual[i];
 }

 //=======================================================================
 // Output dan operasi untuk program Laba-Rugi dengan modal Per-Barang

 toko2 (int beli[100], int jual[100], int jml[100], int pcs[100],int n)
 {
 int i, jum_beli, jum_jual, selisih;
 jum_beli=0;
 jum_jual=0;
 for (i=0; i<n; i++)
 {
 jum_beli=jum_beli+((beli[i]*jml[i])/pcs[i]);
 jum_jual=jum_jual+(jual[i]*jml[i]);
 }
 cout<<endl;
 cout<<"Total Harga Beli"<<": Rp. "<<formatangka(jum_beli)<<"  [MODAL yang diperlukan]"<<endl;
 cout<<"Total Harga Jual"<<": Rp. "<<formatangka(jum_jual)<<endl;
 garis();
 if ( jum_jual > jum_beli )
 {
 selisih=jum_jual-jum_beli;cout<<endl;
 cout<<"UNTUNG sebesar  "<<"\t: Rp. "<<formatangka(selisih)<<endl;
 }
 else if (jum_beli > jum_jual )
 {
 selisih=jum_beli-jum_jual;cout<<endl;
 cout<<"RUGI sebesar  "<<"\t: Rp. "<<formatangka(selisih)<<endl;
 }
 else if (jum_beli == jum_jual )
 {
 cout<<"Tidak ada UNTUNG / RUGI "<<endl;
 }
 else
 {
 cout<<"error !";
 }
 return jual[i];
 }
 //* Fungsi mengubah Inputan password menjadi tanda bintang "*"
string getpassword( const string& prompt = "Enter password> " )
  {
  string result;

  // Set the console mode to no-echo, not-line-buffered input
  DWORD mode, count;
  HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
  HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
  if (!GetConsoleMode( ih, &mode ))
    throw runtime_error(
      "getpassword: You must be connected to a console to use this program.\n"
      );
  SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );

  // Get the password string
  WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
  char k;
  while (ReadConsoleA( ih, &k, 1, &count, NULL) && (k != '\r') && (k != '\n'))
    {
    if (k == '\b')
      {
      if (result.length())
        {
        WriteConsoleA( oh, "\b \b", 3, &count, NULL );
        result.erase( result.end() -1 );
        }
      }
    else
      {
      WriteConsoleA( oh, "*", 1, &count, NULL );
      result.push_back( k );
      }
    }

  // Restore the console mode
  SetConsoleMode( ih, mode );

  return result;
  }

    //===================================================
    //*PROGRAM UTAMA
    int main ()
 {
     struct data{string Nama;
                 string pass;
                 string pass2;
                 string no_tlp;
                 string umur;
                 string username;}regis[128];

    string user;
    int pil,r=1,c=0;
    char cpil;

 //===================================================================================

    cout << "\t\t===============================================================\n";
	cout << "\t\t                        SELAMAT DATANG                         \n";
	cout << "\t\t===============================================================\n";
	cout << "\t\t===============================================================\n";
	cout << "\t\t|               Aplikasi Rekapitulasi laba rugi               |\n";
	cout << "\t\t|                  by : ANTONIO PROECT                        |\n";
	cout << "\t\t===============================================================\n";
	cout << "\t\t|       TUNGGU                |     HITUNG KEUNTUNGANMU       |" << endl;
	cout << "\t\t|      APA LAGI               |          SEKARANG!            |" << endl;
	cout << "\t\t===============================================================\n";

	system("pause");
	system("cls");

//=====================================================================================================================
// FORM REGISTRASI
    regis:
        for(r<100; r++;){
            cout << "|=========================================================|" << endl;
            cout << "|                  ANTONIO TEAM PROJECT                   |" << endl;
            cout << "|                                                         |" << endl;
            cout << "|=========================================================|" << endl;
            cout << "|                        REGISTRASI                       |" << endl;
            cout << "|=========================================================|" << endl;
            cout << "   Nama Lengkap     : "; getline(cin,regis[r].Nama);
            cout << "   Username         : "; getline(cin,regis[r].username);
            cout << "   No Telepon       : "; getline(cin,regis[r].no_tlp);
            cout << "   Umur             : "; getline(cin,regis[r].umur);
            cout << "   Password         : "; getline(cin,regis[r].pass);
            cout << "   Confirm Password : "; getline(cin,regis[r].pass2);

            if (regis[r].pass == regis[r].pass2){
                cout << "\n\nRegistrasi Berhasil!\n" << endl;
                system("pause");
                system("cls");
                goto select;
            }else{
                cout << "\nPassword tidak sama";
                system("pause");
                system("cls");
                goto regis;
            }

            //================================================================
            //*Menu untuk Melakukan Login / Register lagi
             select:
            cout << "  =========================================\n";
            cout << "             ANTONIO TEAM PROJECT           \n";
            cout << "  ----          WAROENG LOEPLAY        ----\n";
            cout << "  =========================================\n\n";
            cout << "[1] Login " << endl;
            cout << "[2] Register" << endl;
            cout << "\n[0] Close/Exit\n" << endl;
            cout << "Masukan Pilihan : ";cin >> pil;
            cin.ignore(1024,'\n');

            if (pil == 1){
                system("cls");
                goto login;
            }else if (pil == 2){
                system("cls");
                goto regis;
            }else if (pil == 0){
                exit(0);
            }



        //====================================================
        //*Form Login
            login:
        cout<<"  =========================================\n";
		cout<<"             ANTONIO TEAM PROJECT           \n";
		cout<<"  ----          WAROENG LOEPLAY        ----\n";
		cout<<"  =========================================\n\n";
		cout<<"     ===================================\n";
		cout<<"      |          Silakan Login          |\n";
		cout<<"     ===================================\n";
		cout<<"  Username   : "; cin>>user;
		string pwd = getpassword("  Password    : "); //*Input Password menggunakan fungsi getpassword
        cout << endl;


        for(int j=0;j<100;j++){
           if((user == regis[j].username)&& (pwd == regis[j].pass)){
                c=1;
                break;
            }
        }
        if (c==0){
            cout << "\n\nUsername Atau Password Salah!\n\n" << endl;
            cout << "Goto Menu ? \n";
            cout << "[y]/[Y] Back To Menu\n[n]/[N] Go To Login\nAny Key Oherwise... : Close The Program" << endl;
            cout << "Select : "; cin>>cpil;
            if(cpil=='y'||cpil=='Y'){
                system("cls");
                goto select;
            } else if (cpil=='n'||cpil=='N'){
                system("cls");
                goto login;
            } else {
                exit(0);
            }
        }else {
            cout << "\n\nLogin Berhasil" << endl;
            system ("pause");
            system ("cls");
            goto main_menu;
            }


        }

        //=====================================================================
        // MENU UTAMA
        main_menu:
            cout << setw(30) << "\t\t=======================================\n";
			cout << setw(22) << "\t\t|             Menu Utama              |\n";
			cout << setw(30) << "\t\t=======================================\n";
			cout << setw(30) << "\t\t| 1. REKAP LABA RUGI PER-BARANG       |\n";
			cout << setw(30) << "\t\t| 2. REKAP LABA RUGI PER-PACKS/RENCENG|\n";
			cout << setw(30) << "\t\t|                                     |\n";
			cout << setw(30) << "\t\t|                                     |\n";
			cout << setw(30) << "\t\t| 9. Logout                           |\n";
			cout << setw(30) << "\t\t| 0. Tutup Aplikasi                   |\n";
			cout << setw(30) << "\t\t|-------------------------------------|\n\n\n";
			cout << "Pilih Menu : "; cin >> pil;
			cout << "\n";

			if(pil == 1){
			system("cls");
            goto labarugi;
		}else if (pil == 2){
			system("cls");
            goto labarugi2;
		}else if(pil == 9){
			cout << "Anda sudah logout";
			system ("pause");
			system("cls");
			goto select;
		}else if (pil == 0){
			exit(0);
		}else {
			cout <<"Key yang anda inputkan salah!\n";
			system("pause");
			system("cls");
			goto main_menu;
		}
//================================================================
//*Program Rekap Laba-Rugi Per-Barang
 labarugi:
 int n, ulangi, jml[100], jual[100], beli[100];
 char nama [100][100];
 int i;
 garis();
 cout<<"\t\tPROGRAM REKAP LABA RUGI V.2  ";cout<<endl;
 cout<<"\t\t      WAROENG LOEPLAY      ";cout<<endl;
 cout<<"username : " <<user<<endl;
 garis();
 cout<<"Banyak Barang : "; cin >>n;cout<<endl;
 cout<<"Entry Data \n";
 garis();
 for (i=0; i<n; i++)
 {
 cout <<"Nama Barang (Tanpa Spasi)     : ";
 cin >>nama[i];
 cout <<"Harga Beli"<<"\t: Rp. ";
 cin >>beli[i];
 cout <<"Harga Jual"<<"\t: Rp. ";
 cin >>jual[i];
 cout <<"Jumlah    "<<"\t: ";
 cin >>jml[i];
 cout <<endl;
 }
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"Nama Barang | @ Harga Beli | @ Harga Jual | Jumlah barang |\n";
 garis();

 for (i=0; i<n; i++)
 {
 cout<<setiosflags(ios::left)<<setw(16)<<nama[i];
 cout<<setiosflags(ios::left)<<"Rp. "<<setw(12)<<formatangka(beli[i]);
 cout<<setiosflags(ios::left)<<"Rp. "<<setw(15)<<formatangka(jual[i]);
 cout<<setiosflags(ios::left)<<setw(15)<<jml[i];
 cout<<endl;
 }
 toko(beli, jual, jml, n);
//=================================================================
     ujung:

 cout<<"\n\n==============================================="<<endl;
 cout<<"  [1] Mulai Ulang Program Rekap Laba-Rugi "<<endl;
 cout<<"  [2] Keluar(Logout)\n "<<endl;
 cout<<"  [0] Tutup Aplikasi ini/Close This Application\n"<<endl;
 cout<<"  Maukkan pilihan: "; cin>>ulangi;
 if (ulangi==1){
    system("cls");
    goto labarugi;
 }else if (ulangi==2){
    system("cls");
    goto select;
 }else if (ulangi==0){
    exit(0);
 }else{
    goto ujung;
 }
//================================================================
//*Program Rekap Laba-Rugi Per-Packs/ Per-Renceng / Per-Dus
  labarugi2:
 int pcs[100];
 garis();
 cout<<"\t\tPROGRAM REKAP LABA RUGI V.2  ";cout<<endl;
 cout<<"\t\t      WAROENG LOEPLAY      ";cout<<endl;
 cout<<"username : " <<user<<endl;
 garis();
 cout<<"Banyak Barang : "; cin >>n;cout<<endl;
 cout<<"Entry Data \n";
 garis();
 for (i=0; i<n; i++)
 {
 cout <<"Nama Barang (Tanpa Spasi)    : ";
 cin >>nama[i];
 cout <<"Harga Beli (Per pcs/dus/renceng)          "<<"\t: Rp. ";
 cin >>beli[i];
 cout <<"Jumlah Barang per-packs                   "<<"\t: ";
 cin >>pcs[i];
 cout <<"Harga Jual (Per sachet/barang/gelas/botol)"<<"\t: Rp. ";
 cin >>jual[i];
 cout <<"Jumlah barang yang laku                   "<<"\t: ";
 cin >>jml[i];
 cout <<endl;
 }
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
 cout<<"Nama Barang | @ Harga Beli | @ Harga Jual | Jumlah barang |\n";
 garis();

 for (i=0; i<n; i++)
 {
 cout<<setiosflags(ios::left)<<setw(16)<<nama[i];
 cout<<setiosflags(ios::left)<<"Rp. "<<setw(12)<<formatangka(beli[i]);
 cout<<setiosflags(ios::left)<<"Rp. "<<setw(15)<<formatangka(jual[i]);
 cout<<setiosflags(ios::left)<<setw(15)<<jml[i];
 cout<<endl;
 }
 toko2(beli, jual, jml, pcs, n);

//==========================================================
    ujung2:

 cout<<"\n\n==============================================="<<endl;
 cout<<"  [1] Mulai Ulang Program Rekap Laba-Rugi "<<endl;
 cout<<"  [2] Keluar(Logout)\n "<<endl;
 cout<<"  [0] Tutup Aplikasi ini/Close This Application\n"<<endl;
 cout<<"  Maukkan pilihan: "; cin>>ulangi;
 if (ulangi==1){
    system("cls");
    goto labarugi2;
 }else if (ulangi==2){
    system("cls");
    goto select;
 }else if (ulangi==0){
    return 0;
 }else{
    cout<<"Key yang anda inputkan salah!";
    goto ujung2;
 }
 getch();
 }

