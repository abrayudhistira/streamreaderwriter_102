#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	string baris;
	string NamaFile;

	cout << "Masukkan Nama File : ";
	cin >> NamaFile;

	//membuka file dalam mode menuis.
	ofstream outfile;
	// menunjuk ke sebuah nama file
	outfile.open(NamaFile,ios::out);

	cout << ">= Menulis File, \'q\' untuk keluar" << endl;

	//unlimited loop untuk menulis
	while (true) {
		cout << "- ";
		//mendapatkan setiap karakter dalam satu baris
		getline(cin, baris);
		//loop akan berhentu jika anda memasukkan karakter q
		if (baris == "q") break;
		//menulis dan memasukkan nilai dari nilai 'baris' ke dalam file
		outfile << baris << endl;
	}
	//selesai dalam menulis sekarang tutup filenya
	outfile.close();

	//membuka file dalam mode membaca
	ifstream infile;
	//menunjuk ke sebuah file
	infile.open(NamaFile,ios::in);

	cout << endl << ">= Membuka dan membaca file " << endl;
	//jika file ada maka 
	if (infile.is_open())
	{
		//melakukan perukangan setiap baris
		while (getline(infile, baris))
		{
			//dan tampilkan disini
			cout << baris << '\n';
		}
		//tutup file tersebut setelah selesai
		infile.close();
	}
	//jika tidak ditemukan file maka akan menampilakan ini
	else cout << "Unable to open File.";
	return 0;
}