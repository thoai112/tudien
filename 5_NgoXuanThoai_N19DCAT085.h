#include <iostream>
#include <Windows.h>
using namespace std;

//giao dien tra tu
void KhungTraTu();
void Cuoi();

void gotoxy(int x, int y)
{
     HANDLE hConsoleOutput;
     COORD Cursor_an_Pos = {x-1, y-1};
     hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void KhungTraTu()
{
	//Tren
	gotoxy(3, 8);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Duoi	
	gotoxy(3, 35);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Trai
	gotoxy(2, 9);
	for(int i=0; i<27; i++){
		cout << char(186);
		gotoxy(2, 9+i);
	}
	//Phai
	gotoxy(101, 9);
	for(int i=0; i<27; i++)
	{
		cout << char(186);
		gotoxy(101, 9+i);
	}
	//Ngang giua
	gotoxy(3, 11);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Doc giua
	gotoxy(42, 9);
	for(int i=0; i<27; i++)
	{
		cout << char(186);
		gotoxy(42, 9+i);
	}
	//Ngang duoi giua 
	gotoxy(3, 13);
	for(int i=0; i<98; i++)
		cout << char(205);
	gotoxy(42, 13);
	cout << char(206);
	gotoxy(101, 13);
	cout <<char(185);
	gotoxy(2, 13);
	cout <<char(204);
	//Goc duoi
	gotoxy(2, 35);
	cout << char(200);
	gotoxy(42, 35);
	cout <<char(202);
	gotoxy(101, 35);
	cout <<char(188);
	//Goc giua
	gotoxy(2, 11);
	cout <<char(204);
	gotoxy(42, 11);
	cout <<char(206);
	gotoxy(101, 11);
	cout <<char(185);
	//Goc tren
	gotoxy(2, 8);
	cout <<char(201);
	gotoxy(42, 8);
	cout <<char(203);
	gotoxy(101, 8);
	cout <<char(187);
}

//Text
void Cuoi()
{
	gotoxy(17, 9);
	cout << "TIENG ANH";
	gotoxy(12, 10);
	cout << "------ENGLISH------";
	
	gotoxy(65, 9);
	cout << "TIENG VIET";
	gotoxy(61, 10);
	cout << "----VIETNAMESE----";
	
	gotoxy(44, 12);
	cout << "Tu Loai:	";
	gotoxy(44, 14);
	cout << "Nghia: ";
	
	gotoxy(3, 37);
	cout << "Nhap tu tieng Anh ma ban muon dich nghia";
	gotoxy(51, 37);
	cout << "Nhan phim TAB de tiep tuc tra tu";
	
	gotoxy(91, 37);
    cout<<"ESC - Exit";
}

void GiaoDienTraTu()
{
	KhungTraTu();
	Cuoi();
}

//Giao dien them
void TieuDe();
void KhungChucNang();
void Them();

void TieuDe()
{
	gotoxy(44,3);
	cout <<"  ______  _   _  ____   _   _";
	gotoxy(44,4);
	cout<< " |_    _|| | | || ___| |  |  |";
	gotoxy(44,5);
	cout <<"   |  |  | |_| || |__  |  |  |";
	gotoxy(44,6);
	cout <<"   |  |  |  _  || |__| |  .  |";
	gotoxy(44,7);
	cout <<"   |  |  | | | || |__  | | | |";
	gotoxy(44,8);
	cout <<"   |__|  |_| |_||____| |_| |_|";
}

void KhungChucNang()
{
    //Tren
	gotoxy(40, 12);
	for(int i=0; i<40; i++)
		cout << char(205);
	//Duoi	
	gotoxy(40, 24);
	for(int i=0; i<40; i++)
		cout << char(205);
	//Trai
	gotoxy(39, 13);
	for(int i=0; i<12; i++){
		cout << char(186);
		gotoxy(39, 13+i);
	}
	//Phai
	gotoxy(80,13);
	for(int i=0; i<12; i++)
	{
		cout << char(186);
		gotoxy(80, 13+i);
	}
    //Ngang giua
    gotoxy(40, 16);
	for(int i=0; i<40; i++)
		cout << char(205);
    gotoxy(40, 20);
	for(int i=0; i<40; i++)
		cout << char(205);
    //Goc tren
    gotoxy(39, 12);
	cout <<char(201);
	gotoxy(80, 12);
	cout <<char(187);
    //Goc duoi
    gotoxy(39, 24);
	cout <<char(200);
	gotoxy(80, 24);
	cout <<char(188);
    
}
void KhungThem()
{   
    //Tren
	gotoxy(3, 8);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Duoi	
	gotoxy(3, 35);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Trai
	gotoxy(2, 9);
	for(int i=0; i<27; i++){
		cout << char(186);
		gotoxy(2, 9+i);
	}
	//Phai
	gotoxy(101, 9);
	for(int i=0; i<27; i++)
	{
		cout << char(186);
		gotoxy(101, 9+i);
	}
	//Ngang giua
	gotoxy(3, 11);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Doc giua
	gotoxy(25, 9);
	for(int i=0; i<27; i++)
	{
		cout << char(186);
		gotoxy(25, 9+i);
	}
    gotoxy(42, 9);
	for(int i=0; i<27; i++)
	{
		cout << char(186);
		gotoxy(42, 9+i);
	}
    gotoxy(70, 9);
	for(int i=0; i<27; i++)
	{
		cout << char(186);
		gotoxy(70, 9+i);
	}
	//Goc duoi
	gotoxy(2, 35);
	cout << char(200);
	gotoxy(25, 35);
	cout <<char(202);
    gotoxy(42, 35);
	cout <<char(202);
    gotoxy(70, 35);
	cout <<char(202);
	gotoxy(101, 35);
	cout <<char(188);
	//Goc giua
	gotoxy(2, 11);
	cout <<char(204);
	gotoxy(25, 11);
	cout <<char(206);
    gotoxy(42, 11);
	cout <<char(206);
    gotoxy(70, 11);
	cout <<char(206);
	gotoxy(101, 11);
	cout <<char(185);
	//Goc tren
	gotoxy(2, 8);
	cout <<char(201);
	gotoxy(25, 8);
	cout <<char(203);
    gotoxy(42, 8);
	cout <<char(203);
    gotoxy(70, 8);
	cout <<char(203);
	gotoxy(101, 8);
	cout <<char(187);
    //text
    gotoxy(10,9);
    cout <<"TU VUNG.";
    gotoxy(30,9);
    cout <<"TU LOAI";
    gotoxy(53,9);
    cout <<"NGHIA.";
    gotoxy(77,9);
    cout<<"VI DU.";
}
void ThemTu()
{   
    TieuDe();
    KhungThem();
}

void ThemNghia()
{
    TieuDe();
    gotoxy(3, 9);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Duoi	
	gotoxy(3, 25);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Trai
	gotoxy(2, 10);
	for(int i=0; i<16; i++){
		cout << char(186);
		gotoxy(2, 10+i);
	}
	//Phai
	gotoxy(101, 10);
	for(int i=0; i<16; i++)
	{
		cout << char(186);
		gotoxy(101, 10+i);
	}
    //Doc giua
    gotoxy(49, 10);
	for(int i=0; i<7; i++)
	{
		cout << char(186);
		gotoxy(49, 10+i);
	}
    gotoxy(3, 15);
	for(int i=0; i<98; i++)
		cout << char(205);
    //Goc duoi
	gotoxy(2, 25);
	cout << char(200);
	gotoxy(101, 25);
	cout <<char(188);
	//Goc tren
	gotoxy(2, 9);
	cout <<char(201);
	gotoxy(101, 9);
	cout <<char(187);
    //Giua
    gotoxy(49, 9);
	cout <<char(203);
	gotoxy(49, 15);
	cout <<char(202);
    //nhap nghia
    gotoxy(10,12);
    cout <<"Nhap tu can them:";
    gotoxy(68,11);
    cout <<"Nhap 0 THOAT.";
    gotoxy(55,13);
    cout <<"Thong Bao: ";
    gotoxy(15,16);
    cout <<"Nhap moi:";
}
void Them()
{
    TieuDe();
    KhungChucNang();
    //text
    gotoxy(52,14);
    cout <<"1. THEM TU VUNG.";
    gotoxy(52,18);
    cout <<"2. THEM NGHIA.";
    gotoxy(52,22);
    cout <<"3. THEM VI DU.";
    gotoxy(45,26);
    cout <<"LUA CHON:";
    gotoxy(68,26);
    cout <<"4. THOAT.";
}
//SUA 
void TextSua()
{
	gotoxy(48,3);
	cout <<"   ___   _    _    ___ ";
	gotoxy(48,4);
	cout << "  /___"<<char(92)<<" | |  | |  /   "<<char(92);
	gotoxy(48,5);
	cout << " |___ "<<char(92)<<"|| |  | | /     "<<char(92);
	gotoxy(48,6);
    cout << "    "<<char(92)<<char(92)<<" || |  | |   ___  |";
	gotoxy(48,7);	
	cout << " |"<<char(92)<<"__| || |__| || |   | |";
	gotoxy(48,8);
	cout << "  "<<char(92)<<"___/  "<<char(92)<<" __ / |_|   |_|";
}
void KhungSua()
{   
    //Tren
    gotoxy(3, 9);
	for(int i=0; i<98; i++)
		cout << char(205);
	//Trai
	gotoxy(2, 10);
	for(int i=0; i<7; i++){
		cout << char(186);
		gotoxy(2, 10+i);
	}
	//Phai
	gotoxy(101, 10);
	for(int i=0; i<7; i++)
	{
		cout << char(186);
		gotoxy(101, 10+i);
	}
    //Doc Duoi
    gotoxy(49, 10);
	for(int i=0; i<7; i++)
	{
		cout << char(186);
		gotoxy(49, 10+i);
	}
    gotoxy(3, 15);
	for(int i=0; i<98; i++)
		cout << char(205);
    //Goc duoi
	gotoxy(2, 15);
	cout << char(200);
	gotoxy(101, 15);
	cout <<char(188);
	//Goc tren
	gotoxy(2, 9);
	cout <<char(201);
	gotoxy(101, 9);
	cout <<char(187);
    //Giua
    gotoxy(49, 9);
	cout <<char(203);
	gotoxy(49, 15);
	cout <<char(202);
}
void Sua()
{   
    KhungSua();
    TextSua();
    gotoxy(10,12);
    cout <<"Nhap tu can sua:";
    gotoxy(68,11);
    cout <<"Nhap 0 THOAT.";
    gotoxy(55,13);
    cout <<"Thong Bao: ";

}
void KhungChucNang1()
{
    KhungChucNang();
    //Duoi
    gotoxy(40, 28);
	for(int i=0; i<40; i++)
		cout << char(205);
	//Trai
	gotoxy(39, 24);
	for(int i=0; i<5; i++){
		cout << char(186);
		gotoxy(39, 24+i);
	}
	//Phai
	gotoxy(80,24);
	for(int i=0; i<5; i++)
	{
		cout << char(186);
		gotoxy(80, 24+i);
	}
    //Goc duoi
    gotoxy(39, 28);
	cout <<char(200);
	gotoxy(80, 28);
	cout <<char(188);
}
void Sua1()
{
    TextSua();
    KhungChucNang1();
    gotoxy(52,14);
    cout <<"1. TU VUNG.";
    gotoxy(52,18);
    cout <<"2. LOAI TU.";
    gotoxy(52,22);
    cout <<"3. NGHIA.";
    gotoxy(52,26);
    cout <<"4. VI DU.";
    gotoxy(46,30);
    cout <<"LUA CHON:";
    gotoxy(68,30);
    cout <<"5. THOAT.";
}
void DanhSach()
{   
    gotoxy(30, 8);
	for(int i=0; i<50; i++)
		cout << char(205);
	//Duoi	
	gotoxy(30,15);
	for(int i=0; i<50; i++)
		cout << char(205);
	//Trai
	gotoxy(29, 9);
	for(int i=0; i<7; i++){
		cout << char(186);
		gotoxy(29, 9+i);
	}
	//Phai
	gotoxy(80, 9);
	for(int i=0; i<7; i++)
	{
		cout << char(186);
		gotoxy(80, 9+i);
	}
     //Goc tren
    gotoxy(29, 8);
	cout <<char(201);
	gotoxy(80, 8);
	cout <<char(187);
    //Goc duoi
    gotoxy(29, 15);
	cout <<char(200);
	gotoxy(80, 15);
	cout <<char(188);
}
void DanhSachNghia()
{
    gotoxy(45,6);
    cout<<"DANH SACH NGHIA";
    DanhSach();
}
void DanhSachViDu()
{
    gotoxy(45,6);
    cout<<"DANH SACH VI DU";
    DanhSach();
}
//XOA
void TextXoa()
{
	gotoxy(48,3);
	printf(" __  __   ____     ____ ");
	gotoxy(48,4);
	printf("|  %c/  | /    %c   /    %c  ",92,92,92);
	gotoxy(48,5);
	printf(" %c    / |  __  | /      %c ",92,92);
	gotoxy(48,6);
	printf("  %c  /  | |  | ||        | ",92);
	gotoxy(48,7);
	printf("  /  %c  | |__| ||   __   |",92);
	gotoxy(48,8);
	printf(" /    %c |      ||  /  %c  | ",92,92);
	gotoxy(48,9);
	printf("|__/%c__| %c____/ |_|    |_| ",92,92);
}
void Xoa()
{
    KhungSua();
    TextSua();
    gotoxy(10,12);
    cout <<"Nhap tu can xoa:";
    gotoxy(68,11);
    cout <<"Nhap 0 THOAT.";
    gotoxy(55,13);
    cout <<"Thong Bao: ";
}
void Xoa1()
{
    TextXoa();
    KhungChucNang1();
    gotoxy(52,14);
    cout <<"1. TU VUNG.";
    gotoxy(52,18);
    cout <<"2. LOAI TU.";
    gotoxy(52,22);
    cout <<"3. NGHIA.";
    gotoxy(52,26);
    cout <<"4. VI DU.";
    gotoxy(46,30);
    cout <<"LUA CHON:";
    gotoxy(68,30);
    cout <<"5. THOAT.";
}
void ChonXoa()
{	
	TextXoa();
	//Tren
	gotoxy(40, 12);
	for(int i=0; i<40; i++)
		cout << char(205);
	//Duoi	
	gotoxy(40, 20);
	for(int i=0; i<40; i++)
		cout << char(205);
	//Trai
	gotoxy(39, 13);
	for(int i=0; i<8; i++){
		cout << char(186);
		gotoxy(39, 13+i);
	}
	//Phai
	gotoxy(80,13);
	for(int i=0; i<8; i++)
	{
		cout << char(186);
		gotoxy(80, 13+i);
	}
    //Ngang giua
    gotoxy(40, 16);
	for(int i=0; i<40; i++)
		cout << char(205);
    //Goc tren
    gotoxy(39, 12);
	cout <<char(201);
	gotoxy(80, 12);
	cout <<char(187);
    //Goc duoi
    gotoxy(39, 20);
	cout <<char(200);
	gotoxy(80, 20);
	cout <<char(188);
	gotoxy(52,14);
    cout <<"1. XOA MOT TU.";
    gotoxy(52,18);
    cout <<"2. XOA TOAN BO.";
	gotoxy(46,22);
    cout <<"LUA CHON:";
    gotoxy(68,22);
    cout <<"0. THOAT.";
}
//Xuat toan bo
void XuatCay()
{   
    gotoxy(45,6);
    cout<<"DANH SACH TOAN BO TU DIEN ANH-VIET.";
    KhungThem();
}
//Giao Dien Chinh
void textT()
{

	gotoxy(34,1);
	printf("  ______");
	gotoxy(34,2);
	printf(" |_    _|");
	gotoxy(34,3);
	printf("   |  |");
	gotoxy(34,4);
	printf("   |  |");
	gotoxy(34,5);
	printf("   |  |");
	gotoxy(34,6);
	printf("   |__|");
}

void textU()
{
	gotoxy(43,1);
    printf(" _   _");
    gotoxy(43,2);
    printf("| | | |");
    gotoxy(43,3);
    printf("| | | |");
    gotoxy(43,4);
    printf("| | | |");
    gotoxy(43,5);
    printf("| |_| |");
    gotoxy(44,6);
    printf("%c___/ ",92);
   
}
void textD()
{
	 gotoxy(54,1);
	printf(" _____");
	 gotoxy(54,2);
	printf("|  __ %c",92);
	 gotoxy(54,3);
	printf("| |  %c |",92);
	gotoxy(54,4);
	printf("| |  | |",92);
	 gotoxy(54,5);
	printf("| |__/ |");
	 gotoxy(54,6);
	printf("|_____/");
}
void textI()
{
	gotoxy(62,1);
	cout<<" __";
	gotoxy(62,2);
	cout<<"|  |";
	gotoxy(62,3);
	cout<<"|  |";
	gotoxy(62,4);
	cout<<"|  |";
	gotoxy(62,5);
	cout<<"|  |";
	gotoxy(62,6);
	cout<<"|__|";
}
void textE()
{
	
	gotoxy(66,1);
	cout<<" ____";
	gotoxy(66,2);
	cout<<"| ___|";
	gotoxy(66,3);
	cout<<"| |__";
	gotoxy(66,4);
	cout<<"| |__|";
	gotoxy(66,5);
	cout<<"| |__";
	gotoxy(66,6);
	cout<<"|____|";
	
	
}
void textN()
{
	
	gotoxy(72,1);
	cout<<" _   _";
	gotoxy(72,2);
	printf("| %c | |",92);
	gotoxy(72,3);
	printf("|  %c| |",92);
	gotoxy(72,4);
	printf("| |%c  |",92);
	gotoxy(72,5);
	printf("| | %c |",92);
	gotoxy(72,6);
	cout<<"|_| |_|",92;
}
void TextTuDien()
{
	textT();
	textU();
	textD();
	textI();
	textE();
	textN();
}
//Khung Chinh
void khungChinh()
{
	//TREN TRAI
	//Canh tren
	gotoxy(12, 7);
	for(int i=0; i<40; i++)
		cout<<char(205);
	//Canh duoi
	gotoxy(12, 15);
	for(int i=0; i<32; i++)
		cout<<char(205);	
	//Canh trai
	gotoxy(14, 8);
	for(int i=0; i< 8; i++)
	{
		cout<<char(206);
		gotoxy(14, 8+i);
	}
	//Canh phai
	gotoxy(49, 8);
	for(int i=0; i< 7; i++)
	{
		cout<<char(206);
		gotoxy(49, 8+i);
	}	
	
	//TREN PHAI
	//Canh tren
	gotoxy(54, 7);
	for(int i=0; i<40; i++)
		cout<<char(205);	
	//Canh duoi
	gotoxy(63, 15);
	for(int i=0; i<31; i++)
		cout<<char(205);	
	//Canh trai
	gotoxy(56, 8);
	for(int i=0; i< 7; i++)
	{
		cout<<char(206);
		gotoxy(56, 8+i);
	}
	//Canh phai
	gotoxy(91, 8);
	for(int i=0; i< 8; i++)
	{
		cout<<char(206);
		gotoxy(91, 8+i);
	}
	
	//DUOI TRAI
	//Canh tren
	gotoxy(12, 16);
	for(int i=0; i<32; i++)
		cout<<char(205);	
	//Canh duoi
	gotoxy(12, 24);
	for(int i=0; i<40; i++)
		cout<<char(205);	
	//Canh trai
	gotoxy(14, 17);
	for(int i=0; i< 8; i++)
	{
		cout<<char(206);
		gotoxy(14, 17+i);
	}
	//Canh phai
	gotoxy(49, 18);
	for(int i=0; i< 7; i++)
	{
		cout<<char(206);
		gotoxy(49, 18+i);
	}		
	
	//DUOI PHAI
	//Canh tren
	gotoxy(63, 16);
	for(int i=0; i<31; i++)
		cout<<char(205);	
	//Canh duoi
	gotoxy(54, 24);
	for(int i=0; i<40; i++)
		cout<<char(205);	
	//Canh trai
	gotoxy(56, 18);
	for(int i=0; i< 7; i++)
	{
		cout<<char(206);
		gotoxy(56, 18+i);
	}
	//Canh phai
	gotoxy(91, 17);
	for(int i=0; i< 8; i++)
	{
		cout<<char(206);
		gotoxy(91, 17+i);
	}		
	
	//GIUA
	//Canh tren
	gotoxy(44, 13);
	for(int i=0; i<18; i++)
		cout<<char(205);
	//Canh duoi
	gotoxy(44, 18);
	for(int i=0; i<18; i++)
		cout<<char(205);
	
	//Canh trai
	gotoxy(43, 14);
	for(int i=0; i<=4; i++)
	{
		cout<<char(186);
		gotoxy(43, 14+i);
	}
	//Canh phai
	gotoxy(62, 14);
	for(int i=0; i<=4; i++)
	{
		cout<<char(186);
		gotoxy(62, 14+i);
	}
	
	gotoxy(43, 13);
	cout<<char(201);
	
	gotoxy(43, 18);
	cout<<char(200);
	
	gotoxy(62, 13);
	cout<<char(187);
	
	gotoxy(62, 18);
	cout<<char(188);
	

}

void Text()
{	
	gotoxy(47, 15);
	cout<<"XUAT TU DIEN";
	
	gotoxy(26, 11);
	cout<<"TRA TU DIEN";
	
	gotoxy(68, 11);
	cout<<"THEM TU";
	
	gotoxy(28, 19);
	cout<<"SUA TU";
	
	gotoxy(71, 19);
	cout<<"XOA TU";

	gotoxy(26, 12);
	cout<<"==>PHIM 1<==";
	
	gotoxy(68, 12);
	cout<<"==>PHIM 2<==";
	
	gotoxy(26, 20);
	cout<<"==>PHIM 3<==";
	
	gotoxy(68, 20);
	cout<<"==>PHIM 4<==";
	
	gotoxy(47, 16);
	cout<<"==>PHIM 5<==";
}
void GiaoDienChinh()
{	
	TextTuDien();
	khungChinh();
	Text();
	gotoxy(33, 25);
	printf("LUA CHON YEU CAU(0: KET THUC): ");
}

