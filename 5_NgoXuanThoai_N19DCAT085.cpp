#include "5_NgoXuanThoai_N19DCAT085.h"
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
using namespace std;

#define LH -1
#define EH 0
#define RH 1

struct NODEDS
{
	char data[1000];
	NODEDS *link;
};
typedef struct NODEDS NodeDS; 

struct LIST
{
	NodeDS *pHead;
	NodeDS *pTail;
};
typedef struct LIST List;

struct Word
{
	char TuVung[100];
	char LoaiTu[20];
	List Nghia;
	List ViDu;
};

struct Node
{
	Word data;
	char cb;
	int height;
	Node *left;
	Node *right;
	Node *link;
};
typedef Node *Tree;

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
int Max(int a, int b)
{
    return (a > b)? a : b;
}
 
Node* newNode(Word key)
{
    Node* node = new Node();
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; 
    return(node);
}
 
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    y->height = Max(height(y->left),height(y->right)) + 1;
    x->height = Max(height(x->left),height(x->right)) + 1;
 
    return x;
}
 
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = Max(height(x->left),height(x->right)) + 1;
    y->height = Max(height(y->left),height(y->right)) + 1;
 
    return y;
}
 

int getBalance(Tree N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
Node *insert(Tree & t, Word data)
{
    /* 1. Perform the normal BST insertion */
    if (t == NULL)
        return(newNode(data));
 
    if (stricmp(t->data.TuVung, data.TuVung) > 0)
        t->left  = insert(t->left, data);
    else if (stricmp(t->data.TuVung,  data.TuVung) < 0)
        t->right = insert(t->right, data);
    else 
        return t;

    t->height = 1 + Max(height(t->left),height(t->right));

    int balance = getBalance(t);

    if (balance > 1 && stricmp(data.TuVung, t->left->data.TuVung) < 0)
        return rightRotate(t);

    if (balance < -1 && stricmp(data.TuVung, t->right->data.TuVung) > 0)
        return leftRotate(t);

    if (balance > 1 && stricmp(data.TuVung, t->left->data.TuVung) > 0)
    {
        t->left =  leftRotate(t->left);
        return rightRotate(t);
    }

    if (balance < -1 && stricmp(data.TuVung, t->right->data.TuVung) < 0)
    {
        t->right = rightRotate(t->right);
        return leftRotate(t);
    }

    return t;
}


// CHUC NANG //
void ThemKiTu(char *chuoi, char dau, char cuoi)
{
	int n = strlen(chuoi);
	n++;
    for(int i=n;i>0;i--)
    {
        chuoi[i] = chuoi[i-1];
    }
    chuoi[0] = dau;
    chuoi[n] = cuoi;
    chuoi[n+1] = '\0'; 
}

void XoaKiTu(char *chuoi, char kiTu)
{
    int n = strlen(chuoi);
    for(int i=0;i<n;i++)
    {
        if(chuoi[i]==kiTu)
        {
            for(int j=i; j<n;j++)
                chuoi[j]=chuoi[j+1];
            break;
        }	
    }
}

void XoaGoiY()
{
	int k=0;
	int x= 10, y= 12;
	int a = x -6;
	int b = y +2;
	for(int i= 0; i< 21; i++)
	{
		gotoxy(a, b+k);
		for(int j = 0; j< 38; j++)
			cout << " ";
		k++;
	}
}

void XoaKetQuaTimKiem()
{
	int x= 10, y= 12;
	int a = x+34;
	int b = y+3;
	for(int i=0; i< 20; i++)
	{
		gotoxy(a, b+i);
		for(int j = 0; j < 57;j++)
			cout << " ";
	}
	for(int i=0; i< 49; i++)
	{
		gotoxy(52+ i, 12);
		cout <<" ";
	}
	for(int i=0; i< 50; i++)
	{
		gotoxy(51+ i, 14);
		cout <<" ";
	}
}

//CAY NHI PHAN
Node *CreateNode(Word x)
{
	Node *p = new Node;
	if(p==NULL)
		return NULL;
	p->data = x;
	p->cb = EH;
	p->left = NULL;
	p->right = NULL;	
	return p;
}
//Quay don L-L
void QuayLL(Tree &root)
{
	Node *T1 = root->left;
 	root->left = T1->right;
 	T1->right = root;
 	switch(T1->cb)
 	{
 		case LH:
 			root->cb = EH;
 			T1->cb = EH; 
 			break;
 		case EH:
 			root->cb = LH;
 			T1->cb = RH;
 			break;
 	}
	root = T1;
}
//Quay don R-R
void QuayRR(Tree &root)
{
 	Node *T1=root->right;
 	root->right = T1->left;
 	T1->left = root;
 	switch(T1->cb)
 	{
 		case RH:
 			root->cb = EH;
 			T1->cb = EH;
 			break;
 		case EH:
 			root->cb = RH;
 			T1->cb = LH;
 			break;
 	}
 	root = T1;
}
//Quay kep L-R
void QuayLR(Tree &root)
{
 	Node *T1 = root->left;
 	Node *T2 = T1->right;
 	root->left = T2->right;
 	T2->right = root;
 	T1->right = T2->left;
 	T2->left = T1;
 	switch(T2->cb)
 	{
 		case LH:
 			root->cb = RH;
 			T1->cb = EH;
 			break;
 		case EH:
 			root->cb = EH;
 			T1->cb = EH;
 			break;
 		case RH:
 			root->cb = EH;
 			T1->cb = LH;
 			break;
 	}
 	T2->cb = EH;
 	root = T2;
}
//Quay kep R-L
void QuayRL(Tree &root)
{
 	Node *T1 = root->right;
 	Node *T2 = T1->left;
 	root->right = T2->left;
 	T2->left = root;
 	T1->left = T2->right;
 	T2->right = T1;
 	switch(T2->cb)
 	{
 		case RH:
 			root->cb = LH;
 			T1->cb = EH;
 			break;
 		case EH:
 			root->cb = EH;
 			T1->cb = EH;
 			break;
 		case LH:
 			root->cb = EH;
 			T1->cb = RH;
 			break;
 	}
 	T2->cb = EH;
 	root = T2;
}
//Can bang cay khi bi lech TRAI
int CBL(Tree &root)
{
 	Node *T1=root->left;
 	switch(T1->cb)
 	{
 		case LH:
 			QuayLL(root);
 			return 2;
 		case  EH:
 			QuayLL(root);
 			return 1;
 		case RH:
 			QuayLR(root);
 			return 2;
 	}
 	return 0;
}
//Can bang cay khi bi lech PHAI
int CBR(Tree &root)
{
 	Node *T1=root->right;
 	switch(T1->cb)
 	{
 		case LH:
 			QuayRL(root);
 			return 2;
 		case EH:
 			QuayRR(root);
 			return 1;
 		case RH:
 			QuayRR(root);
 			return 2;
 	}
 	return 0;
}

// DANH SACH LIEN KET
void Init(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}

NodeDS* GetNode(char *data)
{
	NodeDS *p = new NodeDS;
	if(p==NULL)return NULL;
	strcpy(p->data, data);
	p->link = NULL;
	return p;
}

void AddTail(List &l, char *data)
{
	NodeDS *p = GetNode(data);
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
		
	}
	else 
	{
		l.pTail->link = p;
		l.pTail = p;
	}
}

int InsertNode(Tree &root, Word x)
{
	int res;
	if(root==NULL)
	{ 
		root = CreateNode(x);
		if(root==NULL)
			return -1;
		return 2;
	}
	else 
	{
		if(stricmp(root->data.TuVung, x.TuVung) == 0)
			return 0; 
		else if(stricmp(root->data.TuVung, x.TuVung) > 0)
		{
			res = InsertNode(root->left,x);
			if(res < 2) 
				return res;
			switch(root->cb)
			{ 

				case RH:
 					root->cb = EH;
 					return 1;
 				case EH:
 					root->cb = LH;
 					return 2;
 				case LH:
 					CBL(root);
 					return 1;
			}
		}
		else if(stricmp(root->data.TuVung, x.TuVung)<0)
		{
			res = InsertNode(root->right,x);
			if(res<2)
				return res;
			switch(root->cb)
			{
				case LH:
 					root->cb = EH;
 					return 1;
 				case EH:
 					root->cb = RH;
 					return 2;
 				case RH:
 					CBR(root);
 					return 1;
			}
		}
	}
}

void DocFile(Tree &root, ifstream &filein)
{
    
    char temp1[100];
    Word word;
    //Init(word.Nghia);
    //Init(word.ViDu);
    while(!filein.eof())
    {   
		filein.getline(temp1,100);
        if(strstr(temp1, "@"))
        {
            if(strlen(word.TuVung) > 0)
                InsertNode(root, word);
				Init(word.Nghia);
				Init(word.ViDu);
                strcpy(word.TuVung, temp1);
            
        }
        else if(strstr(temp1, "*"))
        {
            strcpy(word.LoaiTu,temp1);
        }
        else if(strstr(temp1, "#"))
        {
            AddTail(word.ViDu, temp1);
        }
        else if(strstr(temp1, "-"))
        {
            AddTail(word.Nghia, temp1);
        }
    }
    InsertNode(root,word);

}

void GhiFile(Tree root, FILE *file)
{	
	if(root==NULL)
	  return;
	
	fprintf(file, root->data.TuVung);
	fprintf(file, root->data.LoaiTu);
	
	// doc danh sach NGHIA vao file
	NodeDS *nghia = root->data.Nghia.pHead;
	while(nghia!=NULL)
	{
		fprintf(file, nghia->data);
		nghia = nghia->link;
	}
	
	// doc danh sach VI DU vao file
	NodeDS *vidu = root->data.ViDu.pHead;
	while(vidu!=NULL)
	{
		fprintf(file, vidu->data);
		vidu = vidu->link;
	}
	
	GhiFile(root->left, file);
	GhiFile(root->right, file);
	
}

int i=1;
void Xuat(Tree &root)
{	
	if(root != NULL)
	{
		Xuat(root->left);
		cout<<endl;
		cout<<"So Thu Tu:"<<i <<endl; 
		cout<<root->data.TuVung <<endl;
        cout <<root->data.LoaiTu <<endl;
		NodeDS* nghia = root->data.Nghia.pHead;
        while (nghia != NULL)
        {	
            cout << nghia->data;
            nghia = nghia->link;
        }
		cout<<endl;
		NodeDS* vd = root->data.ViDu.pHead;
        while (vd != NULL)
        {	
            cout<<vd->data;
            vd = vd->link;
			
        }
		i++;
		Xuat(root->right);
	}
	else
	return ;
}

Node* TimKiemTu(Tree root, char *key)
{
	if(root==NULL)
	   return NULL;
	
	// T->data.TuVung co dang "@abc\n"
	// can bien s de xu li chuoi thanh "abc" de so sanh voi key
	char s[100];
	strcpy(s,root->data.TuVung);
	XoaKiTu(s,'@');
	XoaKiTu(s, '\n');
	
    if(stricmp(s,key)==0)
       return root;
            
    if(stricmp(s,key)>0)
       return TimKiemTu(root->left,key);
            
     return TimKiemTu(root->right,key);
}

int GetDuLieu(Tree root,Word &word)
{
	Init(word.Nghia);
	Init(word.ViDu);

	fflush(stdin);
	gotoxy(10,12);
	gets(word.TuVung);

	Node *p = TimKiemTu(root,word.TuVung);
	// da tim thay nen bi trung, khong duoc them vao nua
	if(p != NULL)return -1;
	
	// nhap tu vung
	ThemKiTu(word.TuVung, '@', '\n');
	
	// nhap loai tu
	fflush(stdin);
	gotoxy(27,12);
	gets(word.LoaiTu);
	ThemKiTu(word.LoaiTu, '*', '\n');
	
	// nhap nghia
	int flag;
	char Nghia[100];
	int x=12, i=0;

	do{
		fflush(stdin);
		gotoxy(47,x+i);
		gets(Nghia);
		ThemKiTu(Nghia, '-', '\n');
		AddTail(word.Nghia, Nghia);
		i++;
		gotoxy(44,x+i);
		cout<<"1. Them Nghia(bat ki thoat):";
		cin >>flag;
		i++;
		
	}while(flag==1); 
	
	// nhap vi du
	char ViDu[100];
	i=0;
	do{
		fflush(stdin);
		gotoxy(75,x+i);
		gets(ViDu);
		ThemKiTu(ViDu, '#', '\n');
		AddTail(word.ViDu, ViDu);
		
		i++;
		gotoxy(72,x+i);
		cout<<"1. Them Vi Du (bat ki thoat):";
		cin>>flag;
		i++;
	}while(flag==1); 
	
	return 1;
	
}

void Them(Tree root)
{	
	Them();
    int choice;
	do{
		system("cls");
		Them();
		gotoxy(56,26);
		cin >> choice;
		
		switch(choice)
		{
			case 1:
			{
				system("cls");
				ThemTu();
				Word word;
				int kt = GetDuLieu(root,word);
				if(kt == -1)
				{
				   gotoxy(5,15);
				   cout<<"===> TU DA TON TAI";
				   getch();
				}
				else InsertNode(root,word);
				
				break;
			}
			
			case 2:
			{		
			    
			    system("cls");
			    char key[100];
	            Node *p;
	            
	            // Kiem tra tu nhap vao phai dung
	            do{	
					ThemNghia();
					fflush(stdin);
					gotoxy(27,12);
					gets(key);
					if(stricmp(key, "0")==0)return;

					p = TimKiemTu(root, key);
				
					if(p==NULL)
					{	
						gotoxy(67,13);
						cout << "TU KHONG TON TAI.";
					}
					else
					{	
						gotoxy(67,13);
						cout <<"TU TON TAI.";
					}
	    
	           }while(p==NULL);
				
				char NghiaThem[100];
			    int dem=0, flag2;
			    do{
				    fflush(stdin);
					gotoxy(31,16+dem);
				    gets(NghiaThem);
				    ThemKiTu(NghiaThem, '-', '\n');
				    AddTail(p->data.Nghia, NghiaThem);
					gotoxy(31,17+dem);
				    cout <<"===> THEM NGHIA NHAN PHIM 1: ";
				    cin >>flag2;
				    dem = dem+2;
				}while(flag2==1);
				break;		  			  
			}
			
			case 3:
			{
				system("cls");
				char key[100];
	            Node *p;
	            
	            // Kiem tra tu nhap vao phai dung
	            do{ 
		            ThemNghia();
	                 fflush(stdin);
					 gotoxy(27,12);
	                 gets(key);
	                 if(stricmp(key, "0") == 0)
                        return;
	
	                 p = TimKiemTu(root, key);
	        
	                 if(p==NULL)
					 {	
						 gotoxy(67,13);
						cout<<"TU KHONG TON TAI";
					 }
	                 else
	                {	
						gotoxy(67,13);
	    	            cout<<"TU TON TAI";
		            }
	    
	            }while(p==NULL);
				
				
				char ViDuThem[100];
			    int dem=0, flag3;
			    do{
				    fflush(stdin);
					gotoxy(31,16+dem);
				    gets(ViDuThem);
				    ThemKiTu(ViDuThem, '#', '\n');
				    AddTail(p->data.ViDu, ViDuThem);
					gotoxy(31,17+dem);
				    cout<<"THEM VI DU NHAN 1: ";
				    cin >> flag3;
				    dem = dem+2;
				}while(flag3==1);
				break;		  	
			}
			
			default: break;	
		}
		
	}while(choice!=4);
}
// Goi y tu
void GoiYTu(Tree root, char *word, int &soTu)
{
	if(root!=NULL)
	{
		// chi cho phep goi y ra 20 tu
		if(soTu<=20)
		{
			// bien de xu li chuoi
			char tempt[100];
			strcpy(tempt,root->data.TuVung);
			XoaKiTu(tempt, '@');
			XoaKiTu(tempt, '\n');
			
			char *s;
			gotoxy(4, 14+ soTu);
			s=strstr(tempt,word);
			
			if(s!=NULL && stricmp(tempt,s)==0)
			{
				soTu++;
				cout <<tempt <<endl;
			}
		}
		else
			return;
		GoiYTu(root->left, word, soTu);
		GoiYTu(root->right, word, soTu);
	}
}
// Tra tu dien
char TraTu(Tree root)
{
	// canh toa do
	int x= 10, y= 12;
    int m = x-6, n = y; 

	// tu vung de tim kiem
	char word[1000];
	// so luong tu trong word
	int dem=0;
	// bat su kien nhap vao
	int key;
	
	
	do{
		
		gotoxy(m, n);
		key = getch();
		
		if(key == 13) //Khi nhan nut Enter
		{
			// neu so tu == 0
			if(dem==0)
			{
			  	gotoxy(53,19);
			    cout << "===> BAN CHUA NHAP TU NAO <===";
			    
			    gotoxy(53,20);
			    cout << ".... VUI LONG NHAP TU VAO ....";
			    
			}
			else 
			{
				// tim kiem tu vung
				Node *p = TimKiemTu(root, word);
				
				if(p==NULL)
				{
					gotoxy(53,19);
			        cout<<"===> KHONG TIM THAY TU BAN CAN TIM <===";
			        gotoxy(53,20);
			        cout<<".... VUI LONG KIEM TRA LAI ....";
				}
				else // da tim duoc
				{
					// xuat loai tu
					gotoxy(53,12);
					char TemptLoaiTu[100];
					strcpy(TemptLoaiTu, p->data.LoaiTu);
					XoaKiTu(TemptLoaiTu, '*'); 	
   	                cout<<TemptLoaiTu;
   	                // xuat danh sach nghia
   	                int y=15,count=0;
   	                NodeDS *nghia = p->data.Nghia.pHead;
  	                while(nghia!=NULL)
   	                {  	               
					    gotoxy(51,y+count);  	
   	  	                cout << nghia->data;
   	  	                nghia = nghia->link;
   	  	                count++;
	                }
	                // xuat danh sach vi du
	                gotoxy(44, y+count+3); 
	                cout << "Vi du: \n";
	                NodeDS *vidu = p->data.ViDu.pHead;
   	                while(vidu!=NULL)
   	                {
   	                	gotoxy(51, y+count+4);
   	                	char TemptViDu[100];
					    strcpy(TemptViDu, vidu->data);
					    XoaKiTu(TemptViDu, '#'); 	
   	  	                cout << TemptViDu;
   	  	                vidu = vidu->link;
   	  	                count++;
	                }
				}
			}
		}	
			
        
		if( (key >= 97 && key <=122) || (key >=65 && key <= 90) || (key == 32) || (key == 39) || (key == 45) )
		{
				word[dem] = char(key);
				dem++;
				word[dem] = '\0';
				printf("%c", key);
				gotoxy(m++, n);
				XoaGoiY();
				XoaKetQuaTimKiem();
				int soTu=0;
				GoiYTu(root,word, soTu);
				
		}
		
		if(key == 8) //Khi nhan nut xoa, BackSpace
		{
				if(dem>0)
				{
					dem--;
					word[dem] = '\0';			
					gotoxy(--m, n);
					printf(" ");
					gotoxy(m, n);
					XoaGoiY();
					XoaKetQuaTimKiem();
					int soTu = 0;
					GoiYTu(root, word, soTu);
				}
				
					
				if(dem == 0)
				{	
						gotoxy(x-6, y+2);
						XoaGoiY();	
						XoaKetQuaTimKiem();
				}		
		}
				
   }while(key != 27 && key != 9); // 27: ESC, 9: Tab
   
	return key;

}

void CapNhatDSLKTheoSo(List &l, int stt, char *key)
{
	NodeDS *p = l.pHead;
	int dem=1;
	
	while(dem!=stt)
	{
		dem++;
		p = p->link;
	}
	strcpy(p->data, key);
}
// Sua chua cap nhat lai tu dien
void CapNhat(Tree &root)
{
	char TuCanTim[100];
    Node *p;
	// Kiem tra tu nhap vao phai dung 
	do{	
		system("cls");
		Sua();
	    fflush(stdin);
		gotoxy(27,12);
	    gets(TuCanTim);
	    if(stricmp(TuCanTim, "0") ==0 )
            return;
	    p = TimKiemTu(root, TuCanTim);
	    if(p==NULL)
        {	
			gotoxy(67,13);
            cout<<"TU KHONG TON TAI.\n";
			sleep(3);
        }
	    else
	    {	
			gotoxy(67,13);
	    	cout<< "TU TON TAI.";
			sleep(1);
		}
	    
	}while(p==NULL);
	
	
	int choice;
	do{
		
		system("cls");
        Sua1();
		gotoxy(56,30);
        cin>>choice;
		
		switch(choice)
		{
			
			case 1:
			{
				cout<<"\n =====> NHAP TU VU THAY DOI: ";
				char KeyTuVung[100];
				fflush(stdin);
				gets(KeyTuVung);
				ThemKiTu(KeyTuVung, '@', '\n');
				strcpy(p->data.TuVung, KeyTuVung);
				break;
			}
			
			case 2:
			{
				cout<<"\n=====> NHAP LOAI TU THAY DOI: ";
				char KeyLoaiTu[100];
				fflush(stdin);
				gets(KeyLoaiTu);
				ThemKiTu(KeyLoaiTu, '*', '\n');
				strcpy(p->data.LoaiTu, KeyLoaiTu);
				break;
			}
			
			case 3:
			{
				int choice3;
				do{
				    system("cls");
					DanhSachNghia();
				    int dem=0;
				    NodeDS *nghia = p->data.Nghia.pHead;
				    if(nghia == NULL)
				    {	
						gotoxy(35,9);
				    	cout<<"===> KHONG CO NGHIA NAO";
				    	getch();
				    	break;
					}
				    // xuat danh sach nghia
				    int k=0;
					while(nghia!=NULL)
				    {
				    	dem++;
				    	char tempt[100];
				    	strcpy(tempt, nghia->data);
				    	XoaKiTu(tempt, '-');
						gotoxy(35,9+k);
				    	cout << dem  << ")" <<tempt;
					    nghia = nghia->link;
						k++;
				    }
				    
				    
				    int SoCanSua;
				    do{	
						gotoxy(32,17);			    					    			    	
                        cout << "===> MOI NHAP LUA CHON CAN SUA: ";
						gotoxy(65,17);
                        cin >> SoCanSua;
					}while(SoCanSua < 1 || SoCanSua>dem);

					gotoxy(32,19);
				    cout << "===> NHAP NGHIA MOI: ";
				    char KeyNghia[100];
				    fflush(stdin);
					gotoxy(55,19); 
				    gets(KeyNghia);
				    ThemKiTu(KeyNghia,'-','\n');
				    CapNhatDSLKTheoSo(p->data.Nghia, SoCanSua, KeyNghia);
					gotoxy(32,20);
				    cout << "BAN CO MUON CAP NHAP TIEP HAY KHONG: 1) CO: ";
					gotoxy(76,20);
				    cin >> choice3;
				}while(choice3==1);
				
				break;
			}
			
			case 4:
			{
				int choice4;
				do{
					system("cls");
					DanhSachViDu();
				    int dem=0;
				    NodeDS *vidu = p->data.ViDu.pHead;
				    
				    if(vidu == NULL)
				    {	
						gotoxy(35,9);
				    	cout<<"===> KHONG CO VI DU NAO";
				    	getch();
				    	break;
					}
				    
				    // xuat danh sach nghia
					int k=0;
				    while(vidu!=NULL)
				    {
				    	dem++;
				    	char tempt[100];
				    	strcpy(tempt, vidu->data);
				    	XoaKiTu(tempt, '#');
						gotoxy(35,9+k);
				    	cout<<dem <<")" <<tempt;
					    vidu = vidu->link;
						k++;
				    }
				    
				    int SoCanSua;
				    do{
						gotoxy(32,17);
				    	cout<<"===> MOI NHAP LUA CHON CAN SUA: ";
						gotoxy(65,17);
                        cin>>SoCanSua;
					}while(SoCanSua < 1|| SoCanSua>dem);
				  	gotoxy(32,19);
				    cout << "===> NHAP VI DU MOI: ";
				    char KeyViDu[100];
				    fflush(stdin);
					gotoxy(55,19);
				    gets(KeyViDu);
				    ThemKiTu(KeyViDu,'#','\n');
				    
				    CapNhatDSLKTheoSo(p->data.ViDu, SoCanSua, KeyViDu);
				    gotoxy(32,20);
				    cout << "BAN CO MUON CAP NHAT TIEP HAY KHONG: 1) CO: ";
				    gotoxy(76,20);
					cin >> choice4;
				}while(choice4==1);
				
				break;
			}
			
			default: break;
		}
	}while(choice!=5);
}
//Xoa node tren cay
void NodeTheMang(Tree &X, Tree &Y) 
{
	if (Y->left != NULL)
	{
		NodeTheMang(X, Y->left);
	}
	else 
	{
		X->data = Y->data; 
		X = Y; 
		Y = Y->right;
	}
}

void XoaNodeTrenCay(Tree &root, char *key)
{
	if (root == NULL)
	{
		return; 
	}
	else
	{
		if (stricmp(root->data.TuVung, key) >0 )
		{
			XoaNodeTrenCay(root->left, key); 
		}
		else if(stricmp(root->data.TuVung, key) <0 )
		{
			XoaNodeTrenCay(root->right, key); 
		}
		else 
		{
			Node *X = root;
		
			if (root->left == NULL)
			{
				root = root->right; 
			}
			else if (root->right == NULL)
			{
				
				root = root->left;
			}
			else 
			{	
				NodeTheMang(X, root->right);
			}
			delete X;
		}
	}
}

void XoaMotNode(List &l, NodeDS *nodecanxoa)
{
	if(l.pHead == nodecanxoa)
	{
		NodeDS *p = l.pHead;
	    l.pHead = l.pHead->link;
	    delete p;
	    return;
	}
	
	if(l.pTail == nodecanxoa)
	{
		NodeDS *p;
	    for(NodeDS *k = l.pHead; k!=NULL;k = k->link)
	    {
		   if(k == l.pTail)
          {
 	        l.pTail = p;
 	        l.pTail->link =NULL;
 	        delete k;
 	        return;
		   }
		   p = k;
	    }
	    return;
	}
	
	NodeDS *tam;
	for(NodeDS *p=l.pHead;p!=NULL;p=p->link)
	{
		if(p == nodecanxoa)
		{
			tam->link = p->link;
			delete p;
			return;
		}
		
		tam = p;
	}
}
//Xoa
void XoaDSLKDTheoSo(List &l, int stt)
{
	NodeDS *p = l.pHead;
	int dem=1;
	
	while(dem!=stt)
	{
		dem++;
		p = p->link;
	}
	XoaMotNode(l, p);
	
}

void Xoa(Tree &root)
{
	char key[100];
	Node *p;

	do{	
		system("cls");
		Xoa();
	    fflush(stdin);
		gotoxy(28,12);
	    gets(key);
	    if(stricmp(key, "0")==0)
			return;
	    p = TimKiemTu(root, key);
	    
	    if(p==NULL)
		{	
			gotoxy(67,13);
			cout << "TU KHONG TON TAI";
			sleep(2);
		}
			
	    else
	    {	
			gotoxy(67,13);
	    	cout << "TU TON TAI";
			sleep(1);
		}
	    
	}while(p==NULL);
	
	int choice;
	do{
		system("cls");
		Xoa1();
		gotoxy(58,30);
		cin >> choice;
		switch(choice)
		{
					
			case 1:
			{
				XoaNodeTrenCay(root, p->data.TuVung);
				choice = 5;
				break;
			}
			case 2:
			{
				char loaitu[20] = "";
				ThemKiTu(loaitu, '*', '\n');
				strcpy(p->data.LoaiTu, loaitu);
				break;
			}
			
			case 3:
			{
				int choice3;
				do{
					system("cls");
					DanhSachNghia();
				    int dem=0;
				    NodeDS *nghia = p->data.Nghia.pHead;
				    
				    if(nghia == NULL)
				    {	
						gotoxy(35,9);
				    	cout << "===> KHONG CO NGHIA NAO";
				    	getch();
				    	break;
					}
				    // xuat danh sach nghia
					int k=0;
				    while(nghia!=NULL)
				    {
				    	dem++;
				    	char tempt[100];
				    	strcpy(tempt, nghia->data);
				    	XoaKiTu(tempt, '-');
						gotoxy(35,9+k);
				    	cout <<dem << ")" <<tempt;
					    nghia = nghia->link;
				    	k++;
					}
				
				    int SoCanXoa;
				    do{	
						gotoxy(32,17);
						cout << "===> MOI NHAP LUA CHON CAN XOA: ";
						fflush(stdin);
						gotoxy(65,17);	
				        cin >> SoCanXoa;
					}while(SoCanXoa < 1|| SoCanXoa>dem);
				    XoaDSLKDTheoSo(p->data.Nghia, SoCanXoa);
					gotoxy(32,20);
				    cout << "BAN CO MUON XOA TIEP HAY KHONG: 1) CO: ";
					gotoxy(76,20); 
				    cin >> choice3;
				}while(choice3==1);
				
				break;
			}
			
			case 4:
			{
				int choice4;
				do{
					system("cls");
					DanhSachViDu();
				    int dem=1;
				    NodeDS *vidu = p->data.ViDu.pHead;
				    
				    if(vidu == NULL)
				    {	
						gotoxy(35,9);
				    	cout<<"===> KHONG CO VI DU NAO";
				    	getch();
				    	break;
					}
				    
				    // xuat danh sach nghia
					int k=0;
				    while(vidu!=NULL)
				    {	
						dem++;
				    	char tempt[100];
				    	strcpy(tempt, vidu->data);
				    	XoaKiTu(tempt, '#');
						gotoxy(35,9+k);
				    	cout <<dem <<")" <<tempt;
					    vidu = vidu->link;
						k++;
				    }
				    
				    int SoCanXoa;
				    do{
						gotoxy(32,17);
				    	cout << "===> MOI NHAP LUA CHON CAN XOA: ";
						fflush(stdin);
						gotoxy(65,17);
						cin >> SoCanXoa;
					}while(SoCanXoa < 1|| SoCanXoa>dem);
				  
				    XoaDSLKDTheoSo(p->data.ViDu, SoCanXoa);
					 gotoxy(32,20);
				    cout << "BAN CO MUON XOA TIEP HAY KHONG: 1) CO: ";
					gotoxy(76,20);
				    cin >> choice4;
				}while(choice4==1);
				
				break;
			}
			
			default: break;
		}
	}while(choice!=5);
}
//Xoa toan bo
void XoaToanBo(Tree &root)
{
    if (root == NULL) 
	{
		return;
	}
	if (root->left) {
        XoaToanBo(root->left);
    }
     if (root->right) {
        XoaToanBo(root->right);
    }
    delete root;
// them vao cuoi
  root=NULL;
}

int main()
{
    Tree root = NULL;
	ifstream filein;
	filein.open("data.txt", ios_base::in);
	// doc file ra cay
    //FILE *filein = fopen("data.txt", "r");
    DocFile(root, filein);
    //fclose(filein);
    filein.close();
	int choice;
	do{
		
		system("cls");
		GiaoDienChinh();
		gotoxy(65,25);
		cin >> choice;
		
		switch(choice)
		{   
            case 1:
			{   
				char key;
				do{	
					system("cls");
					GiaoDienTraTu();
					key=TraTu(root);
				}while(key==9);
				break;
			}
			
			
			case 2:				
			{	
				system("cls");
				Them(root);				
			    break;	
			}
			
			case 3:
			{
				system("cls");
                CapNhat(root);
				break;
			}
				
			case 4:
			{   
				int key;
				do
				{
					system("cls");
					ChonXoa();
					gotoxy(56,22);
					cin>>key;
					switch(key)
					{
						case 1:
							Xoa(root);
						case 2:
							XoaToanBo(root);
					}
				} while (key==0);
				break;
			}
			
			case 5:
            {	
				system("cls");
				gotoxy(4,1);
				cout <<"=========CHU THICH.===========";
				gotoxy(3,2);
				cout <<" @ la tu vung.";
				gotoxy(20,2);
				cout <<" * la tu loai.";
				gotoxy(3,3);
				cout <<" - la nghia.";
				gotoxy(20,3);
				cout <<" # la vi du." <<endl;
				Xuat(root);
				system("pause");
				
				break;
			}
			default: break;
				  
		}
	}

	while(choice !=0);
    //FILE *fout = fopen("data.txt", "w");
    //GhiFile(root,fout);
    //fclose(fout);
    return 0;
}