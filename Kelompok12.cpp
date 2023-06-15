#include <iostream>
#include <string>

using namespace std;

struct bio{
    int id;
    const char* nama;
    char* tlp;
};

class Member{
	public:
	    bio biodata[4];
	    Member(){
	        biodata[0].id=123234;
	        biodata[0].nama="sifa";
	        biodata[0].tlp="081234567786";
	        biodata[1].id=233211;
	        biodata[1].nama="krisna";
	        biodata[1].tlp="082332211221";
	        biodata[2].id=543654;
	        biodata[2].nama="upin";
	        biodata[2].tlp="081233312266";
	        biodata[3].id=981234;
	        biodata[3].nama="bernat";
	        biodata[3].tlp="082333899696";
	    }
	    void listMember(){
	    	cout<<"\n--------------------------------------------"<<endl;
    		cout<<"Id\t\t"<<"Nama\t\t"<<"Telepon\t\t"<<endl;
    		cout<<"--------------------------------------------"<<endl;
	        for(int i=0;i<4;i++){
	            cout<<biodata[i].id<<"\t\t"<<biodata[i].nama<<"\t\t"<<biodata[i].tlp<<endl;
	        }
	    }
};

class Menu {
	public:
		Menu(){
			
		}
	    void showMenu() {
	        cout << "\n================DAFTAR MENU================\n";
	        cout << "No  Makanan                  Harga\n";
	        cout << "1.  Nasi Goreng              Rp.13.000\n";
	        cout << "2.  Mie Goreng               Rp.12.000\n";
	        cout << "3.  Bakso                    Rp.15.000\n";
	        cout << "4.  Mie Ayam                 Rp.10.000\n";
	        cout << endl;
	        cout << "No Minuman                   Harga\n";
	        cout << "5   Es Teh                   Rp.5.000\n";
	        cout << "6   Es Jeruk                 Rp.6.000\n";
	        cout << "===========================================\n";
	    }
};

class Order : public Member {
	protected:
	    char* sub[50];
	    int pilih[50], jumlah[50], total_sub_menu[50], harga[50];
	    static int a;
	    static long int total_pembayaran;
	    bool finish = false;
	
	public:
	    Order() {
	        cout << "\nRestoran Pak Wasil, Murah, Enak dan Bersahabat \n";
	    }
	
	    void ord() {
	    	Menu menu;
		    menu.showMenu();
		    cout << "Pilihlah menu dengan menekan angka yang tersedia\n";
		    cout << "Tekan 0 jika telah selesai melakukan pemesanan\n";
	        while (finish == false) {
	            cout << "Pilih menu : ";
	            cin >> pilih[a];
	
	            if (pilih[a] <= 6) {
	                if (pilih[a] == 0) {
	                    finish = true;
	                    cout << "Masuk ke Nota untuk menampilkan menu yang sudah dipesan\n\n";
	                    break;
	                } else {
	                    switch (pilih[a]) {
	                        case 1:
	                            sub[a] = "Nasi Goreng";
	                            harga[a] = 13000;
	                            break;
	                        case 2:
	                            sub[a] = "Mie Goreng";
	                            harga[a] = 12000;
	                            break;
	                        case 3:
	                            sub[a] = "Bakso\t";
	                            harga[a] = 15000;
	                            break;
	                        case 4:
	                            sub[a] = "Mie Ayam";
	                            harga[a] = 10000;
	                            break;
	                        case 5:
	                            sub[a] = "Es Teh\t";
	                            harga[a] = 5000;
	                            break;
	                        case 6:
	                            sub[a] = "Es Jeruk";
	                            harga[a] = 6000;
	                            break;
	                        default:
	                            break;
	                    }
	
	                    cout << "Total porsi " << sub[a] << " : ";
	                    cin >> jumlah[a];
	                    cout << endl;
	
	                    total_sub_menu[a] = jumlah[a] * harga[a];
	                    total_pembayaran = total_pembayaran + total_sub_menu[a];
	                    a++;
	                }
	            } else {
	                cout << "Maaf nomor yang Anda masukkan salah\n\n";
	            }
	        }
	    }
};

int Order::a = 0;
long int Order::total_pembayaran = 0;

class Nota : public Order {
	public:
	    void tampilkanNota() {
	    	int id;
	        cout << "Masukkan ID member apabila Anda memilikinya\n serta masukkan 0 jika tidak memilikinya\n";
	        cout << "Id Member : ";
	        cin >> id;
	        cout << "===========================NOTA PEMBELIAN==================================\n";
	        cout << "---------------------------------------------------------------------------\n";
	        cout << "No\tNama Menu\t\tHarga\t\tJumlah\t\tSub Total\n";
	        cout << "---------------------------------------------------------------------------\n";
	        for (int i = 0; i < a; i++) {
	            cout << i + 1 << "\t" << sub[i] << "\t\t" << harga[i] << "\t\t" << jumlah[i] << "\t\t" << total_sub_menu[i] << endl;
	        }
	        cout << endl;
	        for (int i = 0; i < 4; i++) {
	                if (id == biodata[i].id) {
	                total_pembayaran = total_pembayaran*90/100;
	            }
	        }
	        cout << "---------------------------------------------------------------------------\n";
	        cout << "Total Pembayaran = Rp." << total_pembayaran << endl;
	    }
};

class Restaurant {
public:
    Restaurant() {
        cout << "\n==========SELAMAT DATANG DI RESTAURANT PAK WASIL===========";
    }

    static void show() {
        cout << "\nMenu:" << endl;
        cout << "1. Tampilkan Menu" << endl;
        cout << "2. Order" << endl;
        cout << "3. Nota" << endl;
        cout << "4. List Member" << endl;
        cout << "5. Exit" << endl;
        cout << "\nPilih Opsi: ";
    }

    static int getPilihan() {
        int pilihan;
        cin >> pilihan;
        return pilihan;
    }
};

int main() {
    Restaurant r;
    cout << endl;

    while (true) {
        Restaurant::show();
        int pilihan = Restaurant::getPilihan();

        if (pilihan == 1) {
            Menu menu;
            menu.showMenu();

        } else if (pilihan == 2) {
            Order o;
            o.ord();

        } else if (pilihan == 3) {
            Nota n;
            n.tampilkanNota();

        } else if (pilihan == 4) {
            Member member;
            member.listMember();

        } else if (pilihan == 5) {
            break;
        } else {
            cout << "Maaf anda salah memasukkan angka" << endl;
        }
    }

    return 0;
}
