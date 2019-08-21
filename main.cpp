#include<iostream>
#include"graphics.h"
#include<conio.h>//getch
#include<stdio.h>//fflush
using namespace std;
#include<string.h>
#include <dos.h>
#include<vector>
#include <windows.h>//messagebox
#define Max 100
#include<math.h>
#include<fstream>
#include<iomanip>//setw
struct dinh
{
	int x;
	int y;
	char tendinh[3];
};
typedef struct dinh Dinh;
struct dsdinh
{
	dinh ds[30];
	int n;
};
typedef struct dsdinh DsDinh;

struct canh
{
	int giatri;
	Dinh dinhdau;
	Dinh dinhcuoi;
	int trongsoX;//toa do ghi trong so
	int trongsoY;
	
};
typedef struct canh Canh;
struct dscanh
{
	Canh ds[100];
	int n;
};
typedef struct dscanh DsCanh;


//ham chuyen so sang chuoi so
void Chuyen_Sang_Chuoi(char arr[],int x);
//ham chuyen chuyen sang so
int Chuyen_Sang_So(char arr[]);
//ham nhan chuoi so tu ban phim
void GetInputInt(char arr[],char str[]);
//ham nhan chuoi ky tu tu ban phim
void GetInputChar(char arr[],char str[]);
//ham ve khung chay chuong tring
void Ve_Khung_CT();
//ve khung thanh chon
void Ve_Khung_TC();
//ham ve cac chuc nang
void Ve_Hinh_Chucnang();
//ham ve khung menu chon
void Ve_Khung_Menu();
//ghi noi dung vao khung menu
void GhiNoiDung_Menu();
//ham ve khung ma tran
void Ve_Khung_MT();
//ham ve khung the hien ket qua
void Ve_Khung_KQ();
//cai dat toan bo man hinh
void InitScreen();


//ham them dinh vao danh sach
void Them_Dinh_VaoDS(DsDinh &dsd,Dinh a);
//ham them duong di vao danh sach(noi dinh)
void Them_Duongdi_VaoDS(DsCanh &dsdd,Canh b);
//ham ve dinh moi
void Them_Dinh(DsDinh &dsd,DsCanh dsdd,int &x,int &y,char TenDinh[],int &dem);

//ham ve lai dinh
void Ve_Lai_Dinh(int x,int y,char tendinh[],int mau);
void VeMuiTen(dinh dau, dinh cuoi, int color);
//noi 2 dinh
void Noi_Dinh(DsCanh &dsdd,DsDinh &dsd,int &x,int &y);
//ham doi ten dinh va trong so
void Doi_TenDinh(DsCanh &dsdd,DsDinh &dsd,int &x,int &y,char TenDinh[]);
//cap nhat lai duong di sau khi doi ten
void Update_DsCanh(DsCanh &dsdd,char TenDinh[],char tendinhmoi[]);
//ham xoa dinh tai vt
void Delete(DsDinh &dsd,int vt);
//ham xoa duong di bat ki
void Delete_Duongdi(DsCanh &dsdd,int vt);
//xoa dinh va duong di toi dinh do neu co
void Delete_Dinh(DsDinh &dsd,DsCanh &dsdd,Dinh a);
//ham xoa dinh
void Delete_TuyChon(DsCanh &dsdd,DsDinh &dsd,int &x,int &y);
//ham cap nhat toa do cac dinh va duong di cua dinh
void Update_DoThi(DsDinh &dsd,DsCanh &dsdd,int x,int y,int x1,int y1);
//ham di chuyen dinh trong do thi
void Move(DsCanh &dsdd, DsDinh &dsd,int &x,int &y);



//ve lai do thi
void Ve_Dothi(DsDinh dsd,DsCanh dsdd);
//ve ma tran
void Ve_MaTran(DsDinh dsd,DsCanh dsdd);



//ham xoa ki tu
void Xoa_Ki_Tu(char arr[],int vt);
//ham sao chuan hoa chuoi
void Chuan_Hoa_Chuoi(char arr[]);
//ham dao nguoc chuoi
void Dao_Chuoi(char arr[]);
//ham cat chuoi lay thong tin tung canh
void Cat_Chuoi(Canh &c1,char nguon[]);
//ham cat chuoi de lay thong tin cua tung dinh
void Cat_Chuoi2(Dinh &d,char nguon[]);
//ham kiem tra ten dinh co trung hay khong de them vao danh sach dinh
bool KiemTraDinh(DsDinh dsd,char tendinh[]);
//ham doc file
void ReadFile(ifstream &fileIn,DsCanh &dsdd,DsDinh &dsd);
//ham ghi file
void WriteFile(ofstream &fileOut,DsCanh dsdd, DsDinh dsd);


//tim ma tran ke
void TimMaTranKe(DsCanh dsdd,DsDinh dsd,int a[][30]);
//ham ve duong di bat ki
void Ve_Duong_Di(Canh c,int mau);
//thuat toan DFS
void DFS1(DsCanh dsdd,DsDinh dsd,int a[][30],int n,int tham[],int i,string &s,int tam[],int &m);
void DFS(DsCanh dsdd,DsDinh dsd,int a[][30],int n,int tham[],int dinh);
//thuat toan BFS
void BFS1(DsCanh dsdd,DsDinh dsd,int a[][30],int QUEUE[30],int tham[],int i);
void BFS(DsCanh dsdd, DsDinh dsd,int a[][30],int QUEUE[30],int tham[],int dinhxp);
//tu dinh X den dinh Y su dung thuat toan Dijkstra
void X_Y1(DsCanh dsdd,DsDinh dsd,int a[][30],int truoc[],int tham[],int dinhdau,int dinhcuoi);
void X_Y(DsCanh dsdd,DsDinh dsd,int dinhxp,int dinhkt);
//thuat toan hamilton
//kiem tra co phai do thi hamilton hay khong
void TimBac(DsCanh dsdd,DsDinh dsd,int bacvao[],int bacra[]);
void Try(DsCanh dsdd,DsDinh dsd,int a[][30],int x[][30],int tham[],int i,char &c,int &ktct);
void Hamilton(DsCanh dsdd,DsDinh dsd);
//tim thanh phan lien thong
void DFS1_TPLT(DsDinh dsd,int a[][30],int tham[],int i,int &stplt,int dstam[],int &m,int dstam1[],int &n,int dinhbd);
void TPLT(DsCanh dsdd,DsDinh dsd);
//tim chu trinh euler
void Euler_Cycle(DsCanh dsdd, DsDinh dsd);
//dem so canh cau cua do thi dung thuat toan BFS
void DFS_CC(DsCanh dsdd, DsDinh dsd,int &stplt);
int CanhCau(DsCanh dsdd,DsDinh dsd,int stplt);
//tim dinh tru cua do thi
void DFS_DTru(DsCanh dsdd,DsDinh dsd,int &stplt);
void DinhTru(DsCanh dsdd,DsDinh dsd,int stplt);
//sap xep topo
void Topo_Sort(DsCanh dsdd,DsDinh dsd);
//Duyet BFS de kiem tra X-Y co lien thong hay khong va tim duong di tu X_Y
void BFS1_DT(DsDinh dsd,int a[][30],int tham[],int truoc[],int dinhxp);
//tim dinh that
void DinhThat(DsCanh dsdd,DsDinh dsd,int dinhxp,int dinhkt);

//hien thi hop thu thong bao va thuc thi xoa do thi
int DisplayMessageBox(DsDinh &dsd,DsCanh &dsdd);
void MenuChucNang(DsDinh &dsd,DsCanh &dsdd,int x,int y);
void MenuFile(DsCanh &dsdd,DsDinh &dsd,int x,int y,int &kt);
void MenuThuatToan(DsCanh dsdd,DsDinh dsd,int x,int y);
int main()
{
	int gd=3,gm=3,maloi;
	initgraph(&gd,&gm,"");
	if((maloi=graphresult())!=0)
	{
		cout<<"\nKhong the khoi dong do hoa";
		cout<<"\nMaloi: "<<maloi;
		cout<<"\nNguyen nhan loi: "<<grapherrormsg(maloi);
		cout<<"\nAn phim bat ki de thoat";
		getch();
		exit(1);//dung chuong trinh
	}	
	InitScreen();
	DsDinh dsd;
	DsCanh dsdd;
	dsd.n=dsdd.n=0;
	int x,y;
	int kt;
	while(1)
	{
		kt=1;
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
		}
		if(x>=310 && x<=1300 && y>=1&& y<=480)
		{
			MenuChucNang(dsd,dsdd,x,y);
		}
		else if(x>=1 && x<=300 && y>=310 && y<=380)
		{
			MenuFile(dsdd,dsd,x,y,kt);
		}
		else if(x>=1&& x<=300 && y>=1 && y<=285)
		{
			MenuThuatToan(dsdd,dsd,x,y);
			Ve_Dothi(dsd,dsdd);//ve lai do thi ban dau
		}
		if(kt==0)//kt trong lua chon thoat cua menufile
		{
			break;
		}
	}
	closegraph();
	return 0;
}

//ham chuyen so sang chuoi so
void Chuyen_Sang_Chuoi(char arr[],int x)
{
	int i=0;
	if(x==0)
	{
		arr[i++]='0';
	}
	else
	{
		while(x!=0)
		{
			arr[i++]=(x%10+48);
			x/=10;
		}
	}
	arr[i]='\0';
	//dao nguoc chuoi
	int n=strlen(arr);
	for(int i=0;i<n/2;i++)
	{
		int tam=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=tam;
	}
}
//ham chuyen chuyen sang so
int Chuyen_Sang_So(char arr[])
{
	int so=0;
	int i=0;
	int n=strlen(arr);
	while(i<n)
	{
		so=so*10+(arr[i]-48);
		i++;
	}
	return so;
}
//ham nhan chuoi so tu ban phim
void GetInputInt(char arr[],char str[])
{
	int x=310+textwidth(str);//lay do rong cua chuoi
	int y=500;
	int i=0;
	char kytu[2]={'\0','\0'};
	kytu[0]=getch(); 
	while((int)kytu[0]!=13)//neu nhan enter thi thoat
	{
		if((int)kytu[0]==8)//neu nhan backspace
		{
			x=310+textwidth(str);//xac dinh lai toa do
			if(i>0)
			{
				setfillstyle(1,7);
				settextstyle(8,0,2);
				bar(x,500,x+textwidth(arr),y+textheight(arr));//va khung cung mau voi nen de lam mat di cac ky  tu cua chuoi arr dang hien thi
				arr[--i]='\0';//xoa di 1 ky tu cuoi cua chuoi
				outtextxy(x,y,arr);//ghi ra man hinh chuoi
				x+=textwidth(arr);
			}
		}
		else if(kytu[0]>='0'&& kytu[0]<='9')
		{
			if(strlen(arr)==0)
			{
				x=310+textwidth(str);//xac dinh lai toa do
			}
			arr[i++]=kytu[0];
			arr[i]='\0';
			settextstyle(8,0,2);
			outtextxy(x,y,kytu);
			x+=textwidth(kytu);		
		}
		kytu[0]=getch();
	}
	Ve_Khung_KQ();
}
//ham nhan chuoi ky tu tu ban phim
void GetInputChar(char arr[],char str[])
{
	int x=310+textwidth(str);//lay do rong cua chuoi
	int y=500;
	int i=0;
	char kytu[2]={'\0','\0'};
	kytu[0]=getch(); 
	while((int)kytu[0]!=13)//neu nhan enter thi thoat
	{
		if((int)kytu[0]==8)//neu nhan backspace
		{
			x=310+textwidth(str);//lay do rong cua chuoi
			if(i>0)
			{
				setfillstyle(1,7);
				settextstyle(8,0,2);
				bar(x,500,x+textwidth(arr),y+textheight(arr));//ve khung lam mat cac ky tu cua arr dang hien thi
				arr[--i]='\0';//xoa di 1 ky tu
				outtextxy(x,y,arr);//xuat ra chuoi
				x+=textwidth(arr);//xac dinh toa do sau chuoi
			}
		}
		else if((kytu[0]>='0'&& kytu[0]<='9' )|| (kytu[0]>='A' && kytu[0]<='Z')||( kytu[0]>='a' && kytu[0]<='z' ) || kytu[0]==' ' || kytu[0]=='.')
		{
			if(strlen(arr)==0)
			{
				x=310+textwidth(str);//lay do rong cua chuoi
			}
			arr[i++]=kytu[0];//gan ky tu nhan duoc vao chuoi
			arr[i]='\0';
			settextstyle(8,0,2);
			outtextxy(x,y,kytu);//ghi ra man hinh ky tu vua nhap
			x+=textwidth(kytu);//xac dinh toa do sau ky tu vau ghi	
		}
		kytu[0]=getch();
	}
	Ve_Khung_KQ();//sau khi ket thuc nhap thi xoa cac tu dang hien thi
}
//ham ve khung nen chay chuong trinh
void Ve_Khung_CT()
{
	int maxx=getmaxx();			//lay toa do
	int maxy=getmaxy();
	setbkcolor(7);				//mau nen
	setfillstyle(10,15);		//kieu,mau to
	bar(1,1,maxx,maxy);			//ve khung toan man hinh
	//ve khung chuong trinh
	setfillstyle(1,7);			//mâu,mau khung
	setcolor(RED);//mau net ve khung
	bar(310,1,1300,480);
}
//ve khung thanh chon
void Ve_Khung_TC()
{
	setcolor(4);
	setlinestyle(0,0,3);		//kieu,mâu,do lon net ve
	//ve khung chua thanh chon
	setfillstyle(1,15);			//mâu,mau khung
	bar(310,1,390,480);
	rectangle(310,1,1300,480);
}
//ham ve cac chuc nang
void Ve_Hinh_Chucnang()
{
	setcolor(BLACK);			//mau net ve
	//ve gach ngang phan chia o chuc nang
	setlinestyle(0,0,1);		//kieu,mâu,do lon net ve
	line(310,80,390,80);
	line(310,160,390,160);
	line(310,240,390,240);
	line(310,320,390,320);
	line(310,400,390,400);
	//ve dau cong(them dinh)
	setlinestyle(0,0,2);		//kieu,mau,do lon net ve
	line(330,45,370,45);		//ve duong thang ngang
	line(350,25,350,65);		//ve duong thang dung
	setlinestyle(0,0,1);		
	circle(350,45,25);			//ve vong tron
	//ve mui ten(noi dinh)
	setlinestyle(0,0,2);
	line(330,150,370,90);		//ve duong thang
	setcolor(0);
	setlinestyle(0,0,1);
	setfillstyle(1,0);			//kieu mau,mau to
	int arr[8]={355,90,370,90,375,105};
	fillpoly(3,arr);//ve tam giac lam dau mui ten
	//ve hinh cay but(chinh sua)
	setlinestyle(0,0,2);		//kieu,mau,do lon net ve
	line(330,200,350,165);
	line(350,165,380,185);
	line(380,185,360,220);
	line(360,220,330,200);
	//ve dau nhon
	setfillstyle(1,0);
	int tam[8]={330,200,330,230,360,220};
	fillpoly(3,tam);
	//ve dau X(xoa dinh)
	setlinestyle(0,0,1);		//kieu,mau,do lon net ve
	circle(350,280,25);			//ve duong tron
	setlinestyle(0,0,2);
	line(340,270,360,290);		//ve dau gach cheo trai sang phai
	line(360,270,340,290);		//ve dau gach cheo phai sang trai
	//ve chuc nang di chuyen cac dinh do thi
	setlinestyle(0,0,3);		//kieu,mau,do lon net ve
	line(320,360,380,360);		//ve dau gach ngang
	line(350,330,350,390);		//ve dau gach dung
	//ve 4 dau mui ten
	line(340,340,350,330);		//mui ten tren
	line(360,340,350,330);
	line(370,350,380,360);		//mui tren phai
	line(370,370,380,360);
	line(360,380,350,390);		//mui ten duoi
	line(340,380,350,390);
	line(330,370,320,360);		//mui ten trai
	line(330,350,320,360);
	//ve chuc nang xoa do thi
	rectangle(330,430,370,470);
	rectangle(340,420,360,430);
	line(340,450,340,465);
	line(350,450,350,465);
	line(360,450,360,465);

}
//ham ve khung menu chon
void Ve_Khung_Menu()
{
	setcolor(RED);
	setbkcolor(7);
	//ve khung menu
	setlinestyle(0,0,3);
	bar(1,30,300,285);
	rectangle(1,30,300,285);
	//ve khung file
	bar(1,310,300,380);
	rectangle(1,310,300,380);//ve duong vien khung
	//ve khung chua thanh phan trong menu
	setfillstyle(1,15);				//cai dat mau, mau net ve
	int y1=40;
	int y2=90;
	for(int i=0;i<4;i++)
	{
		int x1=5,x2=95;
		int k=0;
		if(i<3)
		{
			while(k<3)
			{
				bar(x1,y1,x2,y2);		//ve khung cho tung lua chon trong menu
				x1=x2+10;
				x2=x1+90;
				k++;
			}
		}
		else //(i==3)
		{
			bar(x1,y1,x2,y2);		//ve khung cho tung lua chon trong menu
			x1=x2+10;
			x2=x1+90;
		}
		y1=y2+10;
		y2=y1+50;
	}
	int x1=5;
	int x2=95;
	y1=320;
	y2=370;
	int k=0;
	while(k<3)
	{
		bar(x1,y1,x2,y2);			//ve khung cho tung lua chon trong menu file
		x1=x2+10;
		x2=x1+90;
		k++;
	}

}
void GhiNoiDung_Menu()
{
		//============ghi noi dung menu=========
	setcolor(RED);
	setbkcolor(7);				//tao nen mau xam 
	settextstyle(1,0,2);
	outtextxy(10,10,"Menu");
	outtextxy(10,290,"File");
	settextstyle(3,0,2);
	outtextxy(10,381,"Matrix");
	//dong 1
	setbkcolor(15);			//tao nen mau trang
	settextstyle(2,0,5);		//phong,huong,co chu
	outtextxy(40,60,"DFS");
	outtextxy(140,60,"BFS");
	outtextxy(240,60,"X->Y");
	//dong 2
	outtextxy(20,120,"DINH TRU");
	outtextxy(120,120,"DINH THAT");
	outtextxy(220,120,"CANH CAU");
	//dong 3
	outtextxy(20,180,"HAMILTON");
	outtextxy(130,180,"EULER");
	outtextxy(210,180,"TOPO SORT");
	//dong 4
	outtextxy(30,240,"TPLT");
	//dong 5
	outtextxy(20,340,"MO FILE");
	outtextxy(120,340,"LUU FILE");
	outtextxy(220,340,"THOAT");
}
//ham ve khung ma tran
void Ve_Khung_MT()
{
	setfillstyle(1,7);		//cai dat mau xam cho khung
	setlinestyle(0,1,0);
	bar(1,400,300,700);
	rectangle(1,400,300,700);
}
//ham ve khung the hien ket qua
void Ve_Khung_KQ()
{
	setfillstyle(1,7);			//to mau
	bar(310,490,1300,700);		//ve khung
	setlinestyle(0,0,3);		//kieu ,mau,do lon cua net ve
	setcolor(4);				//mau net ve
	rectangle(310,490,1300,700);
}
//cai dat man hinh
void InitScreen()
{	
	Ve_Khung_CT();
	Ve_Khung_TC();
	Ve_Khung_KQ();
	Ve_Khung_Menu();
	GhiNoiDung_Menu();
	Ve_Khung_MT();
	Ve_Hinh_Chucnang();	
}
//ham them dinh vao danh sach
void Them_Dinh_VaoDS(DsDinh &ds,Dinh a)
{
	ds.ds[ds.n++]=a;
}
//ham them duong di vao danh sach
void Them_Duongdi_VaoDS(DsCanh &ds,Canh b)
{
	ds.ds[ds.n++]=b;
}
//ham ve dinh moi
void Them_Dinh(DsDinh &dsd,DsCanh dsdd,int &x,int &y,char TenDinh[],int &dem)
{
	setfillstyle(1,11);		//to mau cho o chuc nang duoc chon
	bar(311,1,389,80);
	Ve_Hinh_Chucnang(); 
	while(dem<=25)
	{
		setcolor(GREEN);
		rectangle(389,1,1300,480);//ve duong vien mau xanh
		while (1)					//nhan chuot trai de ve dinh
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	       		break;
	        }
		}
		bool kta=true;
		//xet dieu kien ve dinh trong khung co toa do
		if((x>390+20 && x<1300-20)&&(y>20 && y<480-20))
		{
			for(int i=0;i<dsd.n;i++)
			{
				if((x>dsd.ds[i].x-20 && x<dsd.ds[i].x+20)&& (y>dsd.ds[i].y-20 && y<dsd.ds[i].y+20))//neu bi trung ngay dinh da co thi khong them dinh
				{
					kta=false;
					break;
				} 
			}
			if(kta==true)
			{
				dem++;
				//duyet danh sach xem co trung ten dinh khong
				while(KiemTraDinh(dsd,TenDinh)==false)// neu trung ten dinh
				{
					TenDinh[0]++;
					if(TenDinh[0]>='Z')
					{
						TenDinh[0]='1';
					}
				}
				Dinh a;
				a.x=x;
				a.y=y;
				strcpy(a.tendinh,TenDinh);
				Ve_Lai_Dinh(a.x,a.y,a.tendinh,14);
				Them_Dinh_VaoDS(dsd,a);			//dua toa do cua dinh vao danh sach
				Ve_MaTran(dsd,dsdd);
				if(TenDinh[0]>='Z')
				{
					TenDinh[0]='1';
				}
				else
				{
					TenDinh[0]++;	
				}						
			}		
		}
		else
		{
			Ve_Khung_TC();
			Ve_Hinh_Chucnang();
			break;
		}
	}
	if(dem>25)
	{
		MessageBox(0, "Khong the them dinh.", "Thong bao",MB_OK+MB_ICONWARNING);//1:có 1 lua chon OK,them dau cham than
		Ve_Khung_TC();
		Ve_Hinh_Chucnang();
		return;
	}	
}
//ham ve lai dinh dung de ve lai dinh voi mau khac mau ban dau(dinh tru,dinh that,tplt)
void Ve_Lai_Dinh(int x,int y,char tendinh[],int mau)
{
 	setfillstyle(1,mau); 		//mau nen cua dinh
   	setlinestyle(0,0,1);			//kieu,mau,do lon net ve
   	setcolor(RED);					//mau vien cua hinh tron
	fillellipse(x,y,20,20);			//ve hinh tron
	setbkcolor(mau);				//tao mau nen ghi ten dinh
	setcolor(BLACK);				//mau ghi ten cua dinh
	settextstyle(0,0,2);			//phong chu
	outtextxy(x-5,y-7,tendinh);
}
void VeMuiTen(dinh dau, dinh cuoi, int color)
{
	const int R =12;
	const double PI = 3.14159265;
	dinh d1, d2, d3, d;
	setcolor(color);
	line(dau.x, dau.y, cuoi.x, cuoi.y);
	d.x = (dau.x + cuoi.x ) / 2;
	d.y = (dau.y + cuoi.y ) / 2;	
	setcolor(7);//cai dat mau cua cung tron cung mau nen xám
	double result;			
	double param = 0;
	struct arccoordstype h;
	if (cuoi.x > dau.x && cuoi.y < dau.y){
		param = 1.0*(dau.y - cuoi.y) /(cuoi.x - dau.x);
		result = atan(param) * 180/ PI;
		arc(d.x, d.y, 0, result+90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, result + 90, result + 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, 0, result, R);
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x < dau.x && cuoi.y > dau.y){
		param = 1.0*(cuoi.y - dau.y) / (dau.x - cuoi.x);
		result = atan(param) * 180/ PI;
		arc(d.x, d.y, 0, result + 90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, result + 90, result + 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, result, 180 + result, R);
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;
	}
	else if (cuoi.x < dau.x && cuoi.y < dau.y){
		param = 1.0*(cuoi.y - dau.y) / (cuoi.x - dau.x);
		result = atan(param) * 180/ PI;
		arc(d.x, d.y, 0, 90-result, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90-result, 90-result + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, 0, 180 - result, R);
		getarccoords(&h);
		d3.x = h.xend;
		d3.y = h.yend;		
	}
	else if (cuoi.x > dau.x && cuoi.y > dau.y){
		param = 1.0*(cuoi.y - dau.y) / (cuoi.x - dau.x);
		result = atan(param) * 180/ PI;
		arc(d.x, d.y, 0, 90-result, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90-result, 90-result + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		arc(d.x, d.y, -result, 0, R);
		getarccoords(&h);
		d3.x = h.xstart;
		d3.y = h.ystart;
	}
	else if (dau.y == cuoi.y){
		arc(d.x, d.y, 0, 90, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		arc(d.x, d.y, 90, 90 + 180, R);
		getarccoords(&h);
		d2.x = h.xend;
		d2.y = h.yend;
		if (dau.x < cuoi.x){
			arc(d.x, d.y, 0, 0, R);
			getarccoords(&h);
			d3.x = h.xstart;
			d3.y = h.ystart;
		}
		else{
			arc(d.x, d.y, 0, 180, R);
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
	}
	else{
		arc(d.x, d.y, 0, 180, R);
		getarccoords(&h);
		d1.x = h.xend;
		d1.y = h.yend;
		d2.x = h.xstart;
		d2.y = h.ystart;
		if (cuoi.y > dau.y){
			arc(d.x, d.y, 0, 270, R);
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;			
		}
		else{
			arc(d.x, d.y, 0, 90, R);
			getarccoords(&h);
			d3.x = h.xend;
			d3.y = h.yend;
		}
	}
	setcolor(color);
	setfillstyle(SOLID_FILL, color);
	int a[] = {d3.x, d3.y, d1.x, d1.y, d2.x, d2.y, d3.x, d3.y};
	fillpoly(4, a);
}
//noi 2 dinh
void Noi_Dinh(DsCanh &dsdd,DsDinh &dsd,int &x,int &y)
{
	Canh b;
	Ve_Khung_TC();//ve khung thanh chon
	setfillstyle(1,11);//to mau o duoc chon
	bar(311,80,389,160);
	Ve_Hinh_Chucnang();//ve hinh trong thanh chon
	while(1)
	{
		setcolor(GREEN);
		rectangle(389,1,1300,480);
		int x1,y1;
		bool kta=false,ktb=false;
		char dinh1[3],dinh2[3];
		while(1)//nhan chuot dinh thu 1
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	       		break;
	        }
		}
		//tim toa do dinh 1
		for(int i=0;i<dsd.n;i++)
		{
			if((x>dsd.ds[i].x-20 && x<dsd.ds[i].x+20)&& (y>dsd.ds[i].y-20 && y<dsd.ds[i].y+20))//kiem tra co ton tai dinh ngay vi tri do chua
			{
				kta=true;
				x=dsd.ds[i].x;
				y=dsd.ds[i].y;
				b.dinhdau.x=x;
				b.dinhdau.y=y;
				strcpy(dinh1,dsd.ds[i].tendinh);
				strcpy(b.dinhdau.tendinh,dsd.ds[i].tendinh);
				break;
			}
		}
		if(kta==false)
		{
			Ve_Khung_TC();//ve khung thanh chon
			Ve_Hinh_Chucnang();//ve hinh trong thanh chon
			break;
		}
		while (1)//nhan chuot dinh thu 2
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x1, y1);
				break;
	        }
		}
		//tim toa do dinh 2
		for(int i=0;i<dsd.n;i++)
		{
			if((x1>dsd.ds[i].x-20 && x1<dsd.ds[i].x+20)&& (y1>dsd.ds[i].y-20 && y1<dsd.ds[i].y+20))
			{
				ktb=true;
				x1=dsd.ds[i].x;
				y1=dsd.ds[i].y;
				strcpy(dinh2,dsd.ds[i].tendinh);
				strcpy(b.dinhcuoi.tendinh,dsd.ds[i].tendinh);//dua dinh vao danh sach duong di
				b.dinhcuoi.x=x1;
				b.dinhcuoi.y=y1;
				break;
			}
		}
		//ve duong di
		if(kta==true && ktb==true && x1!=x && y1!=y)//kiem tra toa do nhan chuot co thuoc toa do cac dinh khong
		{
			setcolor(GREEN);		//mau net ve
			setlinestyle(0,0,2);	//kieu,mâu,do lon net ve
			while(1)
			{
				bool kt1,kt2;
				for(int i=0;i<dsdd.n;i++)	//kiem tra duong di co bi trung khong
				{
					kt1=true;
					kt2=true;
					if(dsdd.ds[i].dinhdau.x==b.dinhdau.x && dsdd.ds[i].dinhcuoi.x==b.dinhcuoi.x && dsdd.ds[i].dinhdau.y==b.dinhdau.y && dsdd.ds[i].dinhcuoi.y==b.dinhcuoi.y)
					{
						kta=false;
						settextstyle(8,0,2);
						setcolor(RED);
						setbkcolor(7);
						outtextxy(312,500,"Da ton tai duong di.Nhan phim bat ki de tiep tuc");
						getch();
						setfillstyle(1,7);
						bar(312,500,312+textwidth("Da ton tai duong di.Nhan phim bat ki de tiep tuc"),500+textheight("Da ton tai duong di.Nhan phim bat ki de tiep tuc"));
						break;
					}
					else if(dsdd.ds[i].dinhdau.x==b.dinhcuoi.x && dsdd.ds[i].dinhcuoi.x==b.dinhdau.x && dsdd.ds[i].dinhdau.y==b.dinhcuoi.y && dsdd.ds[i].dinhcuoi.y==b.dinhdau.y)
					{
						kt1=false;
						for(int j=i+1;j<dsdd.n;j++)
						{//kiem tra duong di thu 2 co ton tai chua
							if(dsdd.ds[j].dinhdau.x==b.dinhdau.x && dsdd.ds[j].dinhcuoi.x==b.dinhcuoi.x && dsdd.ds[j].dinhdau.y==b.dinhdau.y && dsdd.ds[j].dinhcuoi.y==b.dinhcuoi.y)
							{
								kt2=false;//khong the them duong di
								kta=false;
								settextstyle(8,0,2);
								setcolor(RED);
								setbkcolor(7);
								outtextxy(312,500,"Da ton tai duong di.Nhan phim bat ki de tiep tuc");
								getch();
								setfillstyle(1,7);
								bar(312,500,312+textwidth("Da ton tai duong di.Nhan phim bat ki de tiep tuc"),500+textheight("Da ton tai duong di.Nhan phim bat ki de tiep tuc"));
								break;
							}
						}
					}
					if(kt1==false)
					{
						break;
					}
				}
				if(kt1==false && kt2==true)//ve duong tai vi tri xep thu 2
				{
					ktb=false;
					canh tam;
					if(abs(b.dinhdau.x-b.dinhcuoi.x)<150)
					{
						tam.dinhdau.x=b.dinhdau.x-10;
						tam.dinhcuoi.x=b.dinhcuoi.x-10;
						tam.dinhdau.y=b.dinhdau.y;
						tam.dinhcuoi.y=b.dinhcuoi.y;
					}
					else
					{
						tam.dinhdau.x=b.dinhdau.x;
						tam.dinhcuoi.x=b.dinhcuoi.x;
						tam.dinhdau.y=b.dinhdau.y+10;
						tam.dinhcuoi.y=b.dinhcuoi.y+10;	
					}
					b.trongsoX=(tam.dinhdau.x+tam.dinhcuoi.x)/2;
					b.trongsoY=(tam.dinhdau.y+tam.dinhcuoi.y)/2;
					VeMuiTen(tam.dinhdau,tam.dinhcuoi,2);//ve canh duoi
				}
				break;
			}
			if(kta==true &&ktb==true)
			{
				canh tam1;
				if(abs(b.dinhdau.x-b.dinhcuoi.x)<150)
				{
					tam1.dinhdau.x=b.dinhdau.x+10;
					tam1.dinhcuoi.x=b.dinhcuoi.x+10;
					tam1.dinhdau.y=b.dinhdau.y;
					tam1.dinhcuoi.y=b.dinhcuoi.y;
				}
				else 
				{
					tam1.dinhdau.x=b.dinhdau.x;
					tam1.dinhcuoi.x=b.dinhcuoi.x;	
					tam1.dinhdau.y=b.dinhdau.y-10;
					tam1.dinhcuoi.y=b.dinhcuoi.y-10;
				}
				b.trongsoX=(tam1.dinhdau.x+tam1.dinhcuoi.x)/2;
				b.trongsoY=(tam1.dinhdau.y+tam1.dinhcuoi.y)/2;
				VeMuiTen(tam1.dinhdau,tam1.dinhcuoi,2);//ve canh tren
			}
			if(kta==true || ktb==false)
			{
				Ve_Lai_Dinh(x,y,dinh1,14);		//ve lai dinh
				Ve_Lai_Dinh(x1,y1,dinh2,14);
				char arr[Max];
				settextstyle(8,0,2);
				bool kt;
				do
				{
					kt=true;
					char str[Max]="Nhap trong so: ";
					setcolor(BLACK);
					setbkcolor(7);//dat mau nen ghi chu
					outtextxy(315,500,str);
					GetInputInt(arr,str);
					if(strlen(arr)>4)
					{
						settextstyle(8,0,2);
						outtextxy(315,500,"Vuot qua gia tri cho phep(<10000).Enter nhap lai");
						kt=false;
						getch();
					}
					setbkcolor(7);
					bar(315,500,315+textwidth("Vuot qua gia tri cho phep(<10000).Enter nhap lai"),500+textheight("Vuot qua gia tri cho phep(<10000).Enter nhap lai"));
				}
				while(kt==false);
				b.giatri=Chuyen_Sang_So(arr);
				Them_Duongdi_VaoDS(dsdd,b);
				//ve trong so
				setcolor(0);
				setbkcolor(7);
				if(kta==true&& ktb==true)
				{
					settextstyle(2,0,5);
					outtextxy(b.trongsoX,b.trongsoY,arr);
				}
				else if(kta==true && ktb==false)
				{
					settextstyle(2,0,5);
					outtextxy(b.trongsoX,b.trongsoY,arr);
				}
				Ve_MaTran(dsd,dsdd);	
			}
		}
		else
		{
			Ve_Khung_TC();//ve khung thanh chon
			Ve_Hinh_Chucnang();//ve hinh trong thanh chon
			break;
		}
	}
}
//cap nhat lai duong di sau khi doi ten
void Update_DsCanh(DsCanh &dsdd,char TenDinh[],char tendinhmoi[])
{
	for(int i=0;i<dsdd.n;i++)
	{
		if(stricmp(dsdd.ds[i].dinhdau.tendinh,TenDinh)==0)
		{
			strcpy(dsdd.ds[i].dinhdau.tendinh,tendinhmoi);
		}
		else if(stricmp(dsdd.ds[i].dinhcuoi.tendinh,TenDinh)==0)
		{
			strcpy(dsdd.ds[i].dinhcuoi.tendinh,tendinhmoi);
		}
	}
}
//ham doi ten dinh va trong so
void Doi_TenDinh(DsCanh &dsdd,DsDinh &dsd,int &x,int &y,char TenDinh[])
{
	Ve_Khung_TC();
	Ve_Hinh_Chucnang();
	setfillstyle(1,11);		//mau nen cho khung duoc chon
	bar(311,160,389,240);
	Ve_Hinh_Chucnang();
	while(1)
	{
		setcolor(GREEN);
		rectangle(389,1,1300,480);
		while(1)				//nhan chuot tai dinh can thay doi
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	       		break;
	        }
		}
		if(x>390&&x<1300 && y>1&& y<480)//ktra co thuoc vung ve do thi hay khong
		{
			bool t=false;
			for(int i=0;i<dsd.n;i++)
			{
				if((x>dsd.ds[i].x-20 && x<dsd.ds[i].x+20)&& (y>dsd.ds[i].y-20 && y<dsd.ds[i].y+20))//tim dinh trong danh sach can doi ten
				{
					t=true;
					char tendinh[10]={'\0'};
					bool kta;
					do
					{
						Ve_Khung_KQ();
						kta=true;
						char str[Max]="Nhap ten dinh moi: ";
						bool loi=true;
						do
						{
							loi=true;
							setbkcolor(7);
							setcolor(BLACK);
							settextstyle(8,0,2);	//phong,huong,co chu
							outtextxy(315,500,str);
							GetInputChar(tendinh,str);
							if(strlen(tendinh)!=1 || tendinh[0]==' '|| tendinh[0]=='.' )
							{
								loi=false;
								setcolor(BLACK);
								outtextxy(315,500,"Ten dinh qua dai(Enter de nhap lai)");
								getch();
								setfillstyle(1,7);
								bar(315,500,315+textwidth("Ten dinh qua dai(Enter de nhap lai)"),520+textheight("Ten dinh qua dai(Enter de nhap lai)")); //xoa dong chu thong bao loi 
							}
						}
						while(loi==false);
						if(KiemTraDinh(dsd,tendinh)==false)
						{
							kta=false;
							setcolor(BLACK);
							setbkcolor(7);
							settextstyle(8,0,2);
							outtextxy(315,500,"Ten dinh bi trung.Enter de nhap lai!");
							getch();
						}
					}
					while(kta==false);
					Ve_Khung_KQ();
					Update_DsCanh(dsdd,dsd.ds[i].tendinh,tendinh);//cap nhat lai ten dinh trong dsanh sach duong di
					strcpy(dsd.ds[i].tendinh,tendinh);
					Ve_Lai_Dinh(dsd.ds[i].x,dsd.ds[i].y,tendinh,14);
					Ve_MaTran(dsd,dsdd);
					break;
				}
			}
			if(t==false)//doi trong so khong phai doi ten dinh
			{
				for(int i=0;i<dsdd.n;i++)
				{
					char tam[10];
					Chuyen_Sang_Chuoi(tam,dsdd.ds[i].giatri);
					if(x>=dsdd.ds[i].trongsoX && x<=dsdd.ds[i].trongsoX+textwidth(tam) && y>=dsdd.ds[i].trongsoY && y<=dsdd.ds[i].trongsoY+textheight(tam))
					{
						char trongso[10]={'\0'};
						bool kt;
						do
						{
							kt=true;
							setbkcolor(7);
							setcolor(BLACK);
							settextstyle(8,0,2);
							char str[Max]="Nhap trong so moi: ";
							outtextxy(315,500,str);
							GetInputInt(trongso,str);
							if(strlen(trongso)>4)
							{
								settextstyle(8,0,2);
								outtextxy(315,500,"Vuot qua gia tri cho phep(<10000).Enter nhap lai");
								kt=false;
								getch();
							}
							//xoa thong bao nhap lai tren man hinh
							bar(315,500,315+textwidth("Vuot qua gia tri cho phep(<10000).Enter nhap lai"),500+textheight("Vuot qua gia tri cho phep(<10000).Enter nhap lai"));
						}
						while(kt==false);
						int ts=Chuyen_Sang_So(trongso);
						dsdd.ds[i].giatri=ts;
						Ve_MaTran(dsd,dsdd);
						Ve_Khung_KQ();
						Ve_Dothi(dsd,dsdd);
						break;
					}
				}
			}
		}
		else
		{
			Ve_Khung_TC();
			Ve_Hinh_Chucnang();
			break;
		}
	}
}
//ham di chuyen dinh trong do thi
void Move(DsCanh &dsdd, DsDinh &dsd,int &x,int &y)
{
	int x1,y1;
	Ve_Khung_TC();
	setfillstyle(1,11);
	bar(311,320,389,400);
	Ve_Hinh_Chucnang();
	while(1)
	{
		setcolor(GREEN);
		rectangle(389,1,1300,480);		//ve duong vien cua khung mau xanh
		while(1)
		{
			delay(0.0001);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
 			}
			if (ismouseclick(WM_LBUTTONUP))
			{
	            getmouseclick(WM_LBUTTONUP, x1, y1);
	            break;
	        }
		}
		if(x<390+20 || y>480-20 ||x>1300-20  || x1>1300-20 || x1<390+20 || y1>480-20)
		{
			Ve_Khung_TC();
			Ve_Hinh_Chucnang();
			return;
		}
		else
		{	
			for(int i=0;i<dsd.n;i++)
			{
				if((x>dsd.ds[i].x-20 && x<dsd.ds[i].x+20)&& (y>dsd.ds[i].y-20 && y<dsd.ds[i].y+20))
				{
					x=dsd.ds[i].x;
					y=dsd.ds[i].y;
					Update_DoThi(dsd,dsdd,x,y,x1,y1);
		    		Ve_Dothi(dsd,dsdd);
					break;
				}
			}
		}
	}
}
//ve lai do thi
void Ve_Dothi(DsDinh dsd,DsCanh dsdd)
{
	setfillstyle(1,7);			//mâu,mau khung
	setcolor(RED);				//mau net ve khung
	bar(390,1,1300,480);
	int i=0;
	while(i<dsdd.n)
	{
		setcolor(GREEN);		//mau net ve
		setlinestyle(0,0,2);	//kieu,mâu,do lon net ve
		int tbx=(dsdd.ds[i].dinhdau.x+dsdd.ds[i].dinhcuoi.x)/2;
		int tby=(dsdd.ds[i].dinhdau.y+dsdd.ds[i].dinhcuoi.y)/2;
		if(tbx < dsdd.ds[i].trongsoX || tby>dsdd.ds[i].trongsoY) 
		{
			canh tam;
			if(abs(dsdd.ds[i].dinhdau.x-dsdd.ds[i].dinhcuoi.x)<150)
			{
				tam.dinhdau.x=dsdd.ds[i].dinhdau.x+10;
				tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x+10;
				tam.dinhdau.y=dsdd.ds[i].dinhdau.y;
				tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y;
			}
			else
			{
				tam.dinhdau.x=dsdd.ds[i].dinhdau.x;
				tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x;	
				tam.dinhdau.y=dsdd.ds[i].dinhdau.y-10;
				tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y-10;
			}

			VeMuiTen(tam.dinhdau,tam.dinhcuoi,2);// duong tren
		}
		else
		{
			canh tam;
			if(abs(dsdd.ds[i].dinhdau.x-dsdd.ds[i].dinhcuoi.x)<150)
			{
				tam.dinhdau.x=dsdd.ds[i].dinhdau.x-10;
				tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x-10;
				tam.dinhdau.y=dsdd.ds[i].dinhdau.y;
				tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y;
			}
			else
			{
				tam.dinhdau.x=dsdd.ds[i].dinhdau.x;
				tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x;
				tam.dinhdau.y=dsdd.ds[i].dinhdau.y+10;
				tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y+10;	
			}

			VeMuiTen(tam.dinhdau,tam.dinhcuoi,2);//ve duong duoi
		}
		setcolor(0);
		setbkcolor(7);
		settextstyle(2,0,5);	
		char ck[10]={'\0'};
		int gt=dsdd.ds[i].giatri;
		Chuyen_Sang_Chuoi(ck,gt);
		outtextxy(dsdd.ds[i].trongsoX,dsdd.ds[i].trongsoY,ck);
		i++;
	}
	i=0;
	while(i<dsd.n)
	{
		Ve_Lai_Dinh(dsd.ds[i].x,dsd.ds[i].y,dsd.ds[i].tendinh,14);
		i++;
	}
	Ve_MaTran(dsd,dsdd);
}
//ham cap nhat toa do cac dinh va duong di cua dinh sau khi di chuyen dinh
void Update_DoThi(DsDinh &dsd,DsCanh &dsdd,int x,int y,int x1,int y1)
{
	//cap nhat danh sach dinh
	for(int i=0;i<dsd.n;i++)
	{
		if(dsd.ds[i].x==x && dsd.ds[i].y==y)
		{
			dsd.ds[i].x=x1;
			dsd.ds[i].y=y1;
		}
	}
	//cap nhat danh sach duong di
	for(int i=0;i<dsdd.n;i++)
	{
		if(dsdd.ds[i].dinhdau.x==x && dsdd.ds[i].dinhdau.y==y)
		{
			int tbx=(dsdd.ds[i].dinhdau.x+dsdd.ds[i].dinhcuoi.x)/2;
			int tby=(dsdd.ds[i].dinhdau.y+dsdd.ds[i].dinhcuoi.y)/2;
			if(tbx<dsdd.ds[i].trongsoX ||tby>dsdd.ds[i].trongsoY)//canh tren
			{
				canh tam;
				if(abs(dsdd.ds[i].dinhdau.x-dsdd.ds[i].dinhcuoi.x)<150)
				{
					tam.dinhdau.x=x1+10;
					tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x+10;
					tam.dinhdau.y=y1;
					tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y;
				}
				else
				{
					tam.dinhdau.x=x1;
					tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x;
					tam.dinhdau.y=y1-10;
					tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y-10;	
				}
				dsdd.ds[i].trongsoX=(tam.dinhdau.x+tam.dinhcuoi.x)/2;
				dsdd.ds[i].trongsoY=(tam.dinhdau.y+tam.dinhcuoi.y)/2;
			}
			else //canh duoi
			{
				canh tam;
				if(abs(dsdd.ds[i].dinhdau.x-dsdd.ds[i].dinhcuoi.x)<150)
				{
					tam.dinhdau.x=x1-10;
					tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x-10;
					tam.dinhdau.y=y1;
					tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y;
				}
				else
				{
					tam.dinhdau.x=x1;
					tam.dinhcuoi.x=dsdd.ds[i].dinhcuoi.x;
					tam.dinhdau.y=y1+10;
					tam.dinhcuoi.y=dsdd.ds[i].dinhcuoi.y+10;	
				}
				dsdd.ds[i].trongsoX=(tam.dinhdau.x+tam.dinhcuoi.x)/2;
				dsdd.ds[i].trongsoY=(tam.dinhdau.y+tam.dinhcuoi.y)/2;
			}
			dsdd.ds[i].dinhdau.x=x1;
			dsdd.ds[i].dinhdau.y=y1;
		}
		if(dsdd.ds[i].dinhcuoi.x==x && dsdd.ds[i].dinhcuoi.y==y)
		{
			int tbx=(dsdd.ds[i].dinhdau.x+dsdd.ds[i].dinhcuoi.x)/2;
			int tby=(dsdd.ds[i].dinhdau.y+dsdd.ds[i].dinhcuoi.y)/2;
			if(tbx<dsdd.ds[i].trongsoX ||tby>dsdd.ds[i].trongsoY)//canh tren
			{
				canh tam;
				if(abs(dsdd.ds[i].dinhdau.x-dsdd.ds[i].dinhcuoi.x)<150)
				{
					tam.dinhdau.x=dsdd.ds[i].dinhdau.x+10;
					tam.dinhcuoi.x=x1+10;
					tam.dinhdau.y=dsdd.ds[i].dinhdau.y;
					tam.dinhcuoi.y=y1;
				}
				else
				{
					tam.dinhdau.x=dsdd.ds[i].dinhdau.x;
					tam.dinhcuoi.x=x1;
					tam.dinhdau.y=dsdd.ds[i].dinhdau.y-10;
					tam.dinhcuoi.y=y1-10;	
				}
				dsdd.ds[i].trongsoX=(tam.dinhdau.x+tam.dinhcuoi.x)/2;
				dsdd.ds[i].trongsoY=(tam.dinhdau.y+tam.dinhcuoi.y)/2;
			}
			else//canh duoi
			{
				canh tam;
				if(abs(dsdd.ds[i].dinhdau.x-dsdd.ds[i].dinhcuoi.x)<150)
				{
					tam.dinhdau.x=dsdd.ds[i].dinhdau.x-10;
					tam.dinhcuoi.x=x1-10;
					tam.dinhdau.y=dsdd.ds[i].dinhdau.y;
					tam.dinhcuoi.y=y1;
				}
				else
				{
					tam.dinhdau.x=dsdd.ds[i].dinhdau.x;
					tam.dinhcuoi.x=x1;
					tam.dinhdau.y=dsdd.ds[i].dinhdau.y+10;
					tam.dinhcuoi.y=y1+10;	
				}
				dsdd.ds[i].trongsoX=(tam.dinhdau.x+tam.dinhcuoi.x)/2;
				dsdd.ds[i].trongsoY=(tam.dinhdau.y+tam.dinhcuoi.y)/2;
			}
			dsdd.ds[i].dinhcuoi.x=x1;
			dsdd.ds[i].dinhcuoi.y=y1;
		}
	}
}
//ham xoa duong di
void Delete_Duongdi(DsCanh &dsdd,int vt)
{
	for(int i=vt;i<dsdd.n-1;i++)
	{
		dsdd.ds[i]=dsdd.ds[i+1];
	}
	dsdd.n--;
}
//ham xoa 1 dinh
void Delete(DsDinh &dsd,int vt)
{
	for(int i=vt;i<dsd.n-1;i++)
	{
		dsd.ds[i]=dsd.ds[i+1];
	}
	dsd.n--;
}
//ham xoa nhieu dinh va xoa duong di toi dinh do neu co
void Delete_Dinh(DsDinh &dsd,DsCanh &dsdd,Dinh a)
{
	int i=0;
	while(i<dsd.n)
	{
		if(stricmp(a.tendinh,dsd.ds[i].tendinh)==0)
		{
			Delete(dsd,i);
			for(int j=0;j<dsdd.n;j++)//neu co duong di toi dinh can xoa thi xoa luon duong di
			{
				if(stricmp(a.tendinh,dsdd.ds[j].dinhdau.tendinh)==0 || stricmp(a.tendinh,dsdd.ds[j].dinhcuoi.tendinh)==0)
				{
					Delete_Duongdi(dsdd,j);
					j--;
				}
			}
			break;
		}
		i++;
		
	}
}
//ham xoa dinh
void Delete_TuyChon(DsCanh &dsdd,DsDinh &dsd,int &x,int &y)
{
	Ve_Khung_TC();
	setfillstyle(1,11);//to mau o duoc chon
	bar(311,240,389,320);
	Ve_Hinh_Chucnang();
	while(1)
	{
		setcolor(GREEN);
		rectangle(389,1,1300,480);
		while(1)//nhan chuot tai dinh can thay doi
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	       		break;
	        }
		}
		if(x<390 || y>480)
		{
			Ve_Khung_TC();
			Ve_Hinh_Chucnang();
			break;
		}
		for(int i=0;i<dsd.n;i++)
		{
			if((x>dsd.ds[i].x-20 && x<dsd.ds[i].x+20)&& (y>dsd.ds[i].y-20 && y<dsd.ds[i].y+20))
			{
				setfillstyle(1,7);			//mâu,mau khung
				setcolor(RED);//mau net ve khung
				bar(390,1,1300,480);//ve lai khung hien thi do thi
				Dinh dinha=dsd.ds[i];
				Delete_Dinh(dsd,dsdd,dinha);
				Ve_Dothi(dsd,dsdd);
				break;
			}
		}
	}
}
//ve ma tran
void Ve_MaTran(DsDinh dsd,DsCanh dsdd)
{
	if(dsd.n==0)
	{
		return;
	}
	else
	{
		Ve_Khung_MT();
		if(dsd.n<=10)
		{
		
			int tam=300/dsd.n;
			int i=1;
			int x=1;
			int y=400;
			settextstyle(2,0,5);
			setbkcolor(7);
			outtextxy(3,402,dsd.ds[0].tendinh);		//dien ten dinh vao ma tran
			while(i<dsd.n)
			{
				setcolor(BLACK);			//mau net ve
				setlinestyle(0,0,1);		//kieu,mâu,do lon net ve
				line(x+tam,400,x+tam,700);  //ve cot doc
				outtextxy(x+tam+2,402,dsd.ds[i].tendinh);	//ghi ten dinh theo cot
				line(1,y+tam,300,y+tam);	//ve cot ngang
				outtextxy(1,y+tam+2,dsd.ds[i].tendinh);		//ghi ten dinh theo hang
				x+=tam;
				y+=tam;
				i++;
			}
			//ghi trong so vao ma tran neu co duong di
			if(dsdd.n>0)
			{
				for(int j=0;j<dsdd.n;j++)
				{
					char arr[10];
					int so=dsdd.ds[j].giatri;
					Chuyen_Sang_Chuoi(arr,so);
					int drong=textwidth(arr);
					int x1,y1;
					for(int i=0;i<dsd.n;i++)
					{
						if(stricmp(dsdd.ds[j].dinhcuoi.tendinh,dsd.ds[i].tendinh)==0)
						{
							x1=1+(i+1)*tam-tam/2-drong/2;
						}
						if(stricmp(dsdd.ds[j].dinhdau.tendinh,dsd.ds[i].tendinh)==0)
						{
							y1=400+(i+1)*tam-tam/2;
						}
					}
					settextstyle(2,0,5);
					outtextxy(x1,y1,arr);			//ghi trong so vao ma tran
				}
			}
		}
		else
		{
			setcolor(RED);
			setbkcolor(7);
			settextstyle(3,0,2);
			outtextxy(25,500,"KHONG THE HIEN THI");
		}
		
	}
}
//ham xoa ki tu
void Xoa_Ki_Tu(char arr[],int vt)
{
	int n=strlen(arr);
	if(vt<n)
	{
		for(int i=vt;i<n-1;i++)
		{
			arr[i]=arr[i+1];
		}
		arr[n-1]='\0';
	}

}
//ham sao chuan hoa chuoi dau ,cuoi
void Chuan_Hoa_Chuoi(char arr[])
{
	while(arr[0]==' ')
	{
		Xoa_Ki_Tu(arr,0);
	}
	int n=strlen(arr);
	while(arr[n-1]==' ')
	{
		arr[n-1]='\0';
		n--;
	}
}
//ham dao nguoc chuoi
void Dao_Chuoi(char arr[])
{
	int n=strlen(arr);
	for(int i=0;i<n/2;i++)
	{
		int tam=arr[i];
		arr[i]=arr[n-1-i];
		arr[n-1-i]=tam;
	}
}
//ham cat chuoi lay thong tin cua tung canh
void Cat_Chuoi(Canh &c1,char nguon[])
{
	int n=strlen(nguon);
	int i=0;
	char arr[100];
	while(nguon[n-1]!=' ')//lay vi tri trongsoY
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	c1.trongsoY=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	n=strlen(nguon);
	i=0;
	while(nguon[n-1]!=' ')//lay vi tri trongsoX
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	c1.trongsoX=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	n=strlen(nguon);
	i=0;
	while(nguon[n-1]!=' ')//lay vi tri Y cua diem cuoi
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	c1.dinhcuoi.y=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	n=strlen(nguon);
	i=0;
	while(nguon[n-1]!=' ')//lay vi tri X cua diem cuoi
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	c1.dinhcuoi.x=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	n=strlen(nguon);
	i=0;
	while(nguon[n-1]!=' ')//lay vi tri Y cua diem dau
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	c1.dinhdau.y=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	n=strlen(nguon);
	i=0;
	while(nguon[n-1]!=' ')//lay vi tri X cua diem dau
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	c1.dinhdau.x=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	n=strlen(nguon);
	i=0;
	while(nguon[n-1]!=' ')//lay trong so
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	c1.giatri=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	n=strlen(nguon);
	i=0;
	while(nguon[n-1]!=' ')//lay ten dinh cuoi
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	strcpy(c1.dinhcuoi.tendinh,arr);
	Chuan_Hoa_Chuoi(nguon);
	strcpy(c1.dinhdau.tendinh,nguon);//lay ten dinh dau
}
//ham cat chuoi de lay thong tin cua tung dinh
void Cat_Chuoi2(Dinh &d,char nguon[])
{
	int i=0;
	int n=strlen(nguon);
	char arr[10];
	while(nguon[n-1]!=' ')
	{
			arr[i]=nguon[n-1];
			nguon[n-1]='\0';
			n--;
			i++;	
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	d.y=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	i=0;
	n=strlen(nguon);
	while(nguon[n-1]!=' ')
	{
		arr[i]=nguon[n-1];
		nguon[n-1]='\0';
		n--;
		i++;
	}
	arr[i]='\0';
	Dao_Chuoi(arr);
	d.x=Chuyen_Sang_So(arr);
	Chuan_Hoa_Chuoi(nguon);
	strcpy(d.tendinh,nguon);
}
//ham kiem tra ten dinh co trung hay khong de them vao danh sach dinh
bool KiemTraDinh(DsDinh dsd,char tendinh[])
{
	for(int i=0;i<dsd.n;i++)
	{
		if(stricmp(dsd.ds[i].tendinh,tendinh)==0)
		{
			return false;
		}
	}
	return true;
}
//ham doc file
void ReadFile(ifstream &fileIn,DsCanh &dsdd,DsDinh &dsd)
{
	string s="Mo file de doc(them .txt): ";
	char name[100];
	settextstyle(8,0,2);
	setbkcolor(7);
	setcolor(BLACK);
	outtextxy(312,500,(char*)s.c_str());
	GetInputChar(name,(char*)s.c_str());
	fileIn.open(name,ios_base::in);
	if(fileIn.fail())
	{
		setcolor(RED);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Loi khi mo file nay.Nhan phim bat ky de tiep tuc.");
		getch();
		Ve_Khung_KQ();
		return;
	}
	fileIn>>dsdd.n;
	int i=0;
	fflush(stdin);
	string str;
	getline(fileIn,str);//doc ki tu xuong dong sau khi doc so vao dsdd.n
	while(i<dsdd.n)
	{
		fflush(stdin);
		getline(fileIn,str);
		Chuan_Hoa_Chuoi((char*)str.c_str());
		if(str.length()>0)
		{
			Cat_Chuoi(dsdd.ds[i],(char*)str.c_str());	
		}
		i++;
	}
	fileIn>>dsd.n;
	fflush(stdin);
	getline(fileIn,str);//doc ki tu xuong dong sau khi doc so vao dsd.n
	i=0;
	while(!fileIn.eof())
	{
		fflush(stdin);
		getline(fileIn,str);
		Chuan_Hoa_Chuoi((char*)str.c_str());
		if(str.length()>0)
		{
			Cat_Chuoi2(dsd.ds[i],(char*)str.c_str());
		}
		i++;
	}
	fileIn.close();
}
//ham ghi file
 void WriteFile(ofstream &fileOut,DsCanh dsdd, DsDinh dsd)
{
	char name[100];
	settextstyle(8,0,2);
	string str="Nhap ten file can mo de ghi(them .txt): ";
	setbkcolor(7);
	outtextxy(312,500,(char*)str.c_str());
	GetInputChar(name,(char*)str.c_str());
	fileOut.open(name,ios::out);
	fileOut<<dsdd.n<<endl;
	for(int i=0;i<dsdd.n;i++)
	{
		fileOut<<dsdd.ds[i].dinhdau.tendinh<<setw(5)<<dsdd.ds[i].dinhcuoi.tendinh<<setw(5)<<dsdd.ds[i].giatri<<setw(5)<<dsdd.ds[i].dinhdau.x<<"  "<<dsdd.ds[i].dinhdau.y<<setw(5)<<dsdd.ds[i].dinhcuoi.x<<"  "<<dsdd.ds[i].dinhcuoi.y<<setw(5)<<dsdd.ds[i].trongsoX<<"  "<<dsdd.ds[i].trongsoY<<endl;
	}
	fileOut<<dsd.n<<endl;
	for(int i=0;i<dsd.n;i++)
	{
		fileOut<<dsd.ds[i].tendinh<<setw(5)<<dsd.ds[i].x<<"  "<<dsd.ds[i].y<<endl;
	}
	fileOut.close();
}

//ham ve duong di bat ki(canh cau)
void Ve_Duong_Di(Canh c,int mau)
{
	setlinestyle(0,0,2);	//kieu,mâu,do lon net ve
	int tbx=(c.dinhdau.x+c.dinhcuoi.x)/2;
	int tby=(c.dinhdau.y+c.dinhcuoi.y)/2;
	if(tbx < c.trongsoX || tby>c.trongsoY) 
	{
		canh tam;
		if(abs(c.dinhdau.x-c.dinhcuoi.x)<150)
		{
			tam.dinhdau.x=c.dinhdau.x+10;
			tam.dinhcuoi.x=c.dinhcuoi.x+10;
			tam.dinhdau.y=c.dinhdau.y;
			tam.dinhcuoi.y=c.dinhcuoi.y;
		}
		else
		{
			tam.dinhdau.x=c.dinhdau.x;
			tam.dinhcuoi.x=c.dinhcuoi.x;	
			tam.dinhdau.y=c.dinhdau.y-10;
			tam.dinhcuoi.y=c.dinhcuoi.y-10;
		}

		VeMuiTen(tam.dinhdau,tam.dinhcuoi,mau);// duong tren
	}
	else
	{
		canh tam;
		if(abs(c.dinhdau.x-c.dinhcuoi.x)<150)
		{
			tam.dinhdau.x=c.dinhdau.x-10;
			tam.dinhcuoi.x=c.dinhcuoi.x-10;
			tam.dinhdau.y=c.dinhdau.y;
			tam.dinhcuoi.y=c.dinhcuoi.y;
		}
		else
		{
			tam.dinhdau.x=c.dinhdau.x;
			tam.dinhcuoi.x=c.dinhcuoi.x;
			tam.dinhdau.y=c.dinhdau.y+10;
			tam.dinhcuoi.y=c.dinhcuoi.y+10;	
		}

		VeMuiTen(tam.dinhdau,tam.dinhcuoi,mau);//ve duong duoi
	}
	Ve_Lai_Dinh(c.dinhdau.x,c.dinhdau.y,c.dinhdau.tendinh,14);
	Ve_Lai_Dinh(c.dinhcuoi.x,c.dinhcuoi.y,c.dinhcuoi.tendinh,14);
	setcolor(0);
	setbkcolor(7);
	settextstyle(2,0,5);
	char ck[10]={'\0'};
	int gt=c.giatri;
	Chuyen_Sang_Chuoi(ck,gt);
	outtextxy(c.trongsoX,c.trongsoY,ck);
}
//tim ma tran ke
void TimMaTranKe(DsCanh dsdd,DsDinh dsd,int a[][30])
{
	int m,n;
	for(int i=0;i<dsdd.n;i++)
	{
		m=-1,n=-1;
		for(int j=0;j<dsd.n;j++)
		{
			if(stricmp(dsdd.ds[i].dinhdau.tendinh,dsd.ds[j].tendinh)==0)
			{
				m=j;
			}
			if(stricmp(dsdd.ds[i].dinhcuoi.tendinh,dsd.ds[j].tendinh)==0)
			{
				n=j;
			}
		}
		if(m!=-1 && n!=-1)
		{
			a[m][n]=dsdd.ds[i].giatri;
		}
	}
}
//thuat toan DFS(duyet sau)
void DFS1(DsCanh dsdd,DsDinh dsd,int a[][30],int n,int tham[],int i,string &s,int tam[],int &m)
{
	s=s+dsd.ds[i].tendinh;
	setcolor(GREEN);
	setbkcolor(7);			//tao nen mau xanh
	settextstyle(8,0,2);
	outtextxy(312,500+textheight("Asd"),(char*)s.c_str());
	tham[i]=1;
	tam[m]=i;//tam dung de luu giu nhung dinh tham roi
	if(m>0)
	{
		int n=0;
		bool kt=true;
		for(int j=0;j<dsdd.n;j++)//neu dinh truoc m co duong di toi dinh m
		{
			if(stricmp(dsd.ds[tam[m-1]].tendinh,dsdd.ds[j].dinhdau.tendinh)==0 && stricmp(dsd.ds[tam[m]].tendinh,dsdd.ds[j].dinhcuoi.tendinh)==0)//ve duong di khi duyet DFS
			{
				kt=false;
				Ve_Duong_Di(dsdd.ds[j],10);
				break;		
			}
		}
		while(n<=m && kt==true)//neu dinh truoc m trong danh sach tam khong co duong di thi tim dinh bat ki trong danh sach co duong di toi tam[m]
		{
			for(int j=0;j<dsdd.n;j++)
			{
				if(stricmp(dsd.ds[tam[n]].tendinh,dsdd.ds[j].dinhdau.tendinh)==0 && stricmp(dsd.ds[tam[m]].tendinh,dsdd.ds[j].dinhcuoi.tendinh)==0)
				{
					kt=false;
					Ve_Duong_Di(dsdd.ds[j],10);
					break;
				}
				
			}
			n++;	
		}
		Sleep(500);
		
	}
	m++;
	for(int j=0;j<n;j++)
	{
		if(tham[j]==0 && a[i][j]!=0)
		{
			s=s+"-->";
			DFS1(dsdd,dsd,a,n,tham,j,s,tam,m);
		}
	}
}
void DFS(DsCanh dsdd,DsDinh dsd,int a[][30],int n,int tham[],int dinh)
{
	for(int i=0;i<n;i++)
	{
		tham[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	int tam[30];
	int m=0;
	TimMaTranKe(dsdd,dsd,a);
	string s="DFS: ";
	DFS1(dsdd,dsd,a,n,tham,dinh,s,tam,m);
}
//thuat toan BFS
void BFS1(DsCanh dsdd,DsDinh dsd,int a[][30],int QUEUE[30],int tham[],int i)
{
	string s="BFS: ";
	int tam[30];
	int m=0;
	int d,c;
	d=c=0;
	QUEUE[c++]=i;
	tham[i]=1;
	while(d!=c)
	{
		i=QUEUE[d++];
		tam[m]=i;
		s=s+dsd.ds[i].tendinh;
		setcolor(GREEN);
		setbkcolor(7);			//tao nen mau xam
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("Asd"),(char*)s.c_str());
 		if(m>0)
		{
			int n=0;
			bool kt=true;
			for(int j=0;j<dsdd.n;j++)
			{
				if(stricmp(dsd.ds[tam[m-1]].tendinh,dsdd.ds[j].dinhdau.tendinh)==0 && stricmp(dsd.ds[tam[m]].tendinh,dsdd.ds[j].dinhcuoi.tendinh)==0 )
				{
					kt=false;
					Ve_Duong_Di(dsdd.ds[j],10);
					break;		
				}
			}
			while(n<=m && kt==true)
			{
				for(int j=0;j<dsdd.n;j++)
				{
					if(stricmp(dsd.ds[tam[n]].tendinh,dsdd.ds[j].dinhdau.tendinh)==0 && stricmp(dsd.ds[tam[m]].tendinh,dsdd.ds[j].dinhcuoi.tendinh)==0)
					{
						kt=false;
						Ve_Duong_Di(dsdd.ds[j],10);
						break;
					}
					
				}
				n++;	
			}
			Sleep(500);
		}
		m++;
		s=s+"-->";
		for(int j=0;j<dsd.n;j++)
		{
			if(tham[j]==0 && a[i][j]!=0)
			{
				QUEUE[c++]=j;
				tham[j]=1;
			}
		}
	}
}
void BFS(DsCanh dsdd, DsDinh dsd,int a[][30],int QUEUE[30],int tham[],int dinhxp)
{
	for(int i=0;i<dsd.n;i++)
	{
		tham[i]=0;
	}
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	TimMaTranKe(dsdd,dsd,a);
	BFS1(dsdd,dsd,a,QUEUE,tham,dinhxp);
}
//tu dinh X den dinh Y su dung thuat toan Dijkstra
void X_Y1(DsCanh dsdd,DsDinh dsd,int a[][30],int truoc[],int dinhdau,int dinhcuoi)
{
	int d[30];
	int tham[30];
	int vc=10000;
	int tam[30];
	int m=0;
	for(int i=0;i<dsd.n;i++)
	{
		d[i]=a[dinhdau][i];
		truoc[i]=dinhdau;
		tham[i]=0;
	}
	tham[dinhdau]=1;
	for(int i=0;i<dsd.n-1;i++)
	{
		int u=-1,temp=vc;
		for(int j=0;j<dsd.n;j++)
		{
			if(tham[j]==0 && d[j]<temp)
			{
				u=j;
				temp=d[j];
			}
		}
		if(u==-1)
		{
			break;
		}
		tham[u]=1;
		for(int v=0;v<dsd.n;v++)
		{
			if(tham[v]==0 && d[v]>d[u]+a[u][v])
			{
				d[v]=d[u]+a[u][v];
				truoc[v]=u;
			}
		}
		if(tham[dinhcuoi]==1)//da tim ra duong di ngan nhat
		{
			break;
		}
	}
	if(d[dinhcuoi]==vc)
	{
		setcolor(RED);
		settextstyle(8,0,2);
		outtextxy(312,500+textwidth("sdf")*2,"Khong co duong di.");
	}
	else
	{
		string s="Duong di ngan nhat: ";
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdf")*3,(char*)s.c_str());
		int stack[30],top=-1;
		stack[++top]=dinhcuoi;//dua dinh vao stack
		int t=dinhcuoi;
		do
		{
			t=truoc[t];
			stack[++top]=t;
		}
		while(t!=dinhdau);
		while(top!=-1)//duyet nguoc danh sach de ve duoong di
		{
			s=s+dsd.ds[stack[top]].tendinh;
			setcolor(GREEN);
			settextstyle(8,0,2);
			outtextxy(312,500+textheight("sfg")*3,(char*)s.c_str());
			s=s+"-->";
			if(top>0)
			{
				for(int i=0;i<dsdd.n;i++)
				{
					if(stricmp(dsd.ds[stack[top]].tendinh,dsdd.ds[i].dinhdau.tendinh)==0 && stricmp(dsd.ds[stack[top-1]].tendinh,dsdd.ds[i].dinhcuoi.tendinh)==0)
					{
						Ve_Duong_Di(dsdd.ds[i],10);
						break;
					}
				}	
			}
			stack[top--];
			Sleep(500);
		}
		setcolor(BLACK);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("asd")*4,"Tong trong so: ");
		char trongso[10];
		Chuyen_Sang_Chuoi(trongso,d[dinhcuoi]);
		settextstyle(8,0,2);
		outtextxy(312+textwidth("Tong trong so: "),500+textheight("asd")*4,trongso);
	}
	setcolor(BLACK);
	settextstyle(8,0,2);
	outtextxy(312,500+textheight("asdf")*5,"Click chuot de tiep tuc.");
}
void X_Y(DsCanh dsdd,DsDinh dsd,int dinhxp, int dinhkt)
{
	int a[30][30];
	int truoc[30];
	int vc=10000;
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=vc;
		}
	}
	TimMaTranKe(dsdd,dsd,a);
	setcolor(BLACK);
	settextstyle(8,0,2);
	outtextxy(312,500+textheight("sdf")*2,"Khoi tao thuat toan Dijkstra.");
	X_Y1(dsdd,dsd,a,truoc,dinhxp,dinhkt);
}
//kiem tra co phai do thi hamilton hay khong
void TimBac(DsCanh dsdd,DsDinh dsd,int bacvao[],int bacra[])
{
	int bv,br;
	for(int i=0;i<dsd.n;i++)
	{
		br=bv=0;
		for(int j=0;j<dsdd.n;j++)
		{
			if(stricmp(dsd.ds[i].tendinh,dsdd.ds[j].dinhdau.tendinh)==0)//dau ra
			{
				br++;
			}
			if(stricmp(dsd.ds[i].tendinh,dsdd.ds[j].dinhcuoi.tendinh)==0)//cuoi vao
			{
				bv++;
			}
		}
		bacra[i]=br;
		bacvao[i]=bv;
	}
}
//thuat toan hamilton
void Try(DsCanh dsdd,DsDinh dsd,int a[][30],int x[],int tham[],int i,char &c,int &ktct)
{
	for(int j=0;j<dsd.n;j++)
	{
		if(tham[j]==0 & a[x[i-1]][j]!=0)//tim dinh ke cua dinh x[i-1](dinh vua dua vao x)
		{
			x[i]=j;//luu nhung dinh da tham
			tham[j]=1;
			if(i==dsd.n-1)//da duyet den dinh cuoi cung
			{
				if(a[x[dsd.n-1]][x[0]]!=0)//neu dinh dau, dinh cuoi co duong di
				{
					ktct=1;//xac dinh do thi co chu trinh
					string s="CT: ";
					for(int k=0;k<dsd.n;k++)
					{
						s=s+dsd.ds[x[k]].tendinh;
						setbkcolor(7);
						setcolor(GREEN);
						settextstyle(8,0,2);
						outtextxy(312,500,(char*)s.c_str());
						s=s+"--> ";
						if(k>0)//k=0 (chi có 1 dinh)thi khong con duong di toi dinh nao nua
						{
							for(int h=0;h<dsdd.n;h++)
							{
								if(stricmp(dsd.ds[x[k-1]].tendinh,dsdd.ds[h].dinhdau.tendinh)==0 && stricmp(dsd.ds[x[k]].tendinh,dsdd.ds[h].dinhcuoi.tendinh )==0)
								{
									Ve_Duong_Di(dsdd.ds[h],10);
									Sleep(500);
									break;
								}
							}
						}
					}
					s=s+dsd.ds[x[0]].tendinh;
					setcolor(GREEN);
					settextstyle(8,0,2);
					outtextxy(312,500,(char*)s.c_str());
					for(int h=0;h<dsdd.n;h++)//ve duong di tu dinh dau toi dinh cuoi cua chu trinh
					{
						if(stricmp(dsd.ds[x[dsd.n-1]].tendinh,dsdd.ds[h].dinhdau.tendinh)==0 && stricmp(dsd.ds[x[0]].tendinh,dsdd.ds[h].dinhcuoi.tendinh)==0)
						{
							Ve_Duong_Di(dsdd.ds[h],10);
							break;
						}
					}
					setcolor(BLACK);
					setbkcolor(7);
					settextstyle(8,0,2);
					outtextxy(312,500+textheight("sdf"),"Tiep tuc(Y/N)? ");
					c=getch();
					Ve_Dothi(dsd,dsdd);
					if(c=='N')
					{
						return;
					}
				}			
			}
			else
			{
				Try(dsdd,dsd,a,x,tham,i+1,c,ktct);
			}
			tham[j]=0;
		}
	}
}
void Hamilton(DsCanh dsdd,DsDinh dsd)
{
	int a[30][30],x[30],tham[30];
	for(int i=0;i<dsd.n;i++)
	{
		tham[i]=0;
	}
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	TimMaTranKe(dsdd,dsd,a);
	char c;
	int ktct=0;
	for(int i=0;i<dsd.n;i++)
	{
		x[0]=i;
		tham[i]=1;
		Try(dsdd,dsd,a,x,tham,1,c,ktct);
		Ve_Dothi(dsd,dsdd);
		Ve_Khung_KQ();
		for(int i=0;i<dsd.n;i++)
		{
			tham[i]=0;
		}
		if(c=='N')
		{
			return;
		}
}
	if(ktct==0)//kiem tra co chu trinh hay khong neu khong thi thong bao
	{
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Khong co chu trinh hamilton");
	}
}
//xoa phan tu mang(xoa dinh trong dstam)
void Xoa_PhanTu_Mang(int a[],int &n,int vt)
{
	for(int i=vt;i<n-1;i++)
	{
		a[i]=a[i+1];
	}	
	n--;
}
//tim cac thanh phan lien thong su dung thuat toan DFS
void DFS1_TPLT(DsDinh dsd,int a[][30],int tham[],int i,int &stplt,int dstam[],int &m,int dstam1[],int &n,int dinhbd)
{	
	tham[i]=stplt;
	for(int j=0;j<dsd.n;j++)
	{
		if(tham[j]==0 && a[i][j]!=0 && a[j][i]!=0 && m==0 )//duong 2 chieu
		{ 
			dstam1[n++]=j;
			DFS1_TPLT(dsd,a,tham,j,stplt,dstam,m,dstam1,n,dinhbd);
		}
		else if(tham[j]==0 && a[i][j]!=0)
		{
			int x,vt;//vt de giu vitri ma dinh thu j di toi 1 tplt
			bool kt=false;
			if(a[j][dinhbd]!=0)
			{
				x=j;
				vt=dinhbd;
				kt=true;
				dstam1[n++]=j;
			}
			else//kiem tra xem dinh nay co di toi tplt nao khong
			{
				for(int k=0;k<n;k++)
				{
					if(a[j][dstam1[k]]!=0)
					{
						x=j;
						vt=dstam1[k];//luu giu vi tri dinh thu j di toi 1 dinh thuoc 1 tplt
						kt=true;
						dstam1[n++]=j;
						break;
					}		
				}
			}
			if(kt==true)
			{
				for(int k=m-1;k>=0;k--)
				{
					if(a[dstam[k]][x]!=0 && dstam[k]!=vt)//duyet toi vt thi dung lai
					{
						x=dstam[k];
						dstam1[n++]=dstam[k];//dua nhung dinh cung 1 tplt vao dstam1
						Xoa_PhanTu_Mang(dstam,m,k);//xoa  nhung dinh da thuoc 1 tplt ra khoi dstam
					}
				}
			}
			else
			{
				dstam[m++]=j;//dua dinh thu j vao dstam
			}		
			DFS1_TPLT(dsd,a,tham,j,stplt,dstam,m,dstam1,n,dinhbd);
		}
	}
}
//tim thanh phan lien thong
void TPLT(DsCanh dsdd,DsDinh dsd)
{
	int a[30][30];
	int tham[30];
	int stplt=0;
	for(int i=0;i<dsd.n;i++)
	{
		tham[i]=0;
	}
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	TimMaTranKe(dsdd,dsd,a);
	int dinhbd;
	int dstam[30],m;//dung de luu nhung dinh di qua nhung chua chac chan thuoc cung 1 tplt
	int dstam1[30],n;//dung de luu nhung dinh cung 1 tplt
	for(int i=0;i<dsd.n;i++)
	{
		if(tham[i]==0)
		{
			stplt++;
			m=0;
			n=0;
			dinhbd=i;
			DFS1_TPLT(dsd,a,tham,i,stplt,dstam,m,dstam1,n,dinhbd);
			if(m>0)
			{
				for(int j=0;j<m;j++)
				{
					tham[dstam[j]]=0;//nhung dinh di qua nhung khong cung 1 tplt danh dau lai chua tham
				}
			}
		}
	}
	if(stplt==1)
	{
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Do thi lien thong manh.");
	}
	else
	{
		setbkcolor(7);//mau xam
		settextstyle(8,0,2);
		outtextxy(312,500,"Cac thanh phan lien thong: ");
		setcolor(GREEN);
		string s;
		int mau=3;
		for(int i=1;i<=stplt;i++)
		{
			if(i==10)
			{
				s=" ";
			}
			s=s+"(";
			char aar[5];
			Chuyen_Sang_Chuoi(aar,i);
			s=s+aar;
			s=s+"):";
			s=s+"(";
			for(int j=0;j<dsd.n;j++)
			{
				if(tham[j]==i)
				{
					s=s+dsd.ds[j].tendinh;
					s=s+"-";
					if(mau==7)
					{
						mau++;
					}
					if(mau==16)//gioi han so luong mau to
					{
						mau=1;
					}
					Ve_Lai_Dinh(dsd.ds[j].x,dsd.ds[j].y,dsd.ds[j].tendinh,mau);//to mau dinh tung thanh phan lien thong
				}
			}
			s=s+")";
			setcolor(GREEN);
			settextstyle(8,0,2);
			setbkcolor(7);//mau xam
			if(i<10)
			{
				outtextxy(312,500+textheight("sdf"),(char*)s.c_str());
			}
			else
			{
				outtextxy(312,500+textheight("sdf")*2,(char*)s.c_str());
			}
			mau++;
		}
	}
}
//tim chu trinh euler
void Euler_Cycle(DsCanh dsdd, DsDinh dsd)
{
	int stack[30];
	int a[30][30];
	int CE[30];
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	TimMaTranKe(dsdd,dsd,a);
	int bacvao[30],bacra[30];
	TimBac(dsdd,dsd,bacvao,bacra);
	int dem=0;
	for(int i=0;i<dsd.n;i++)
	{
		if(bacvao[i]!=bacra[i])
		{
			dem++;
		}
	}
	if(dem!=0)
	{
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Khong co chu trinh Euler.");
	}
	else//bacvao==bacra
	{
		int xp=0;
		int top=0;
		int n=0,x;
		stack[++top]=xp;
		while(top!=0)
		{
			x=stack[top];
			int y=0;
			while(y<dsd.n && a[x][y]==0)//tim trong danh sach dinh ke voi x thi thoat vong lap
			{
				y++;
			}
			if(y>=dsd.n)//x khong co dinh ke
			{
				CE[n++]=x;
				top--;
			}
			else//dinh y la dinh ke voi x
			{
				stack[++top]=y;
				a[x][y]=0;
			}
		}
		string s="CT:  ";
		if(stricmp(dsd.ds[CE[0]].tendinh,dsd.ds[CE[n-1]].tendinh)==0)//kiem tra xem dinh dau co trung dinh cuoi hay khong
		{
			for(int i=n-1;i>=0;i--)//duyet nguoc danh sach CE
			{
				s=s+dsd.ds[CE[i]].tendinh;
				setcolor(GREEN);
				setbkcolor(7);
				settextstyle(8,0,2);
				outtextxy(312,500,(char*)s.c_str());
				if(i>=1)
				{
					Canh a;
					for(int k=0;k<dsdd.n;k++)
					{
						if(stricmp(dsdd.ds[k].dinhdau.tendinh,dsd.ds[CE[i]].tendinh)==0 && stricmp(dsdd.ds[k].dinhcuoi.tendinh,dsd.ds[CE[i-1]].tendinh)==0)
						{
							a=dsdd.ds[k];
							break;
						}
					}
					Ve_Duong_Di(a,10);
				}
				Sleep(500);
				s=s+" --> ";
			}
		}
		else
		{
			setcolor(BLACK);
			setbkcolor(7);
			settextstyle(8,0,2);
			outtextxy(312,500,"Khong co chu trinh Euler.");
		}
	}	
}
//Duyet do thi tim tat ca thanh phan lien thong(Canh cau)
void DFS_CC(DsCanh dsdd, DsDinh dsd,int &stplt)
{
	int a[30][30],tham[30];
	stplt=0;
	for(int i=0;i<dsd.n;i++)
	{
		tham[i]=0;
	}
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	int dinhbd;
	int dstam[30],dstam1[30];
	int m,n;
	TimMaTranKe(dsdd,dsd,a);
	for(int i=0;i<dsd.n;i++)
	{
		if(tham[i]==0)
		{
			stplt++;
			m=n=0;
			dinhbd=i;
			DFS1_TPLT(dsd,a,tham,i,stplt,dstam,m,dstam1,n,dinhbd);
			if(m>0)
			{
				for(int j=0;j<m;j++)
				{
					tham[dstam[j]]=0;//loai bo nhung dinh khong thuoc cung 1 tplt
				}
			}
		}
	}
}
int CanhCau(DsCanh dsdd,DsDinh dsd,int stplt)
{
	int stplt1;
	int dem=0;
	string tam;
	string s="Canh cau: ( ";
	Canh t;
	int i=0;
	while(i<dsdd.n)
	{
		s=s+dsdd.ds[0].dinhdau.tendinh;
		s=s+"-";
		s=s+dsdd.ds[0].dinhcuoi.tendinh;
		s=s+" )";
		t=dsdd.ds[0];
		Delete_Duongdi(dsdd,0);//xoa canh de kiem tra no co la canh cau hay khong
		DFS_CC(dsdd,dsd,stplt1);
		if(stplt1>stplt)
		{
			tam=tam+s;
			setcolor(GREEN);
			settextstyle(8,0,2);
			setbkcolor(7);
			outtextxy(312,500,(char*)tam.c_str());
			dem++;
			Ve_Duong_Di(t,10);
			Sleep(500);
		}
		Them_Duongdi_VaoDS(dsdd,t);
		s="( ";
		i++;
	}
	char x[10];
	Chuyen_Sang_Chuoi(x,dem);
	string v="So canh cau: ";
	v=v+x;
	settextstyle(8,0,2);
	setbkcolor(7);
	setcolor(BLACK);
	outtextxy(312,500+textheight("sf"),(char*)v.c_str());
}
//tim dinh tru cua do thi
//duyet DFS tim so tplt
void DFS_DTru(DsCanh dsdd,DsDinh dsd,int &stplt)
{
	int tham[30],a[30][30];
	for(int i=0;i<dsd.n;i++)
	{
		tham[i]=0;
	}
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	int m,n;
	TimMaTranKe(dsdd,dsd,a);
	int dstam[30],dstam1[30];
	int dinhbd;
	for(int i=0;i<dsd.n;i++)
	{
		if(tham[i]==0)
		{
			m=0;
			n=0;
			stplt++;
			dinhbd=i;
			DFS1_TPLT(dsd,a,tham,i,stplt,dstam,m,dstam1,n,dinhbd);
			if(m>0)//nhung dinh tham qua nhung khong cung 1 tplt thi sua lai =0 danh dau chua tham
			{
				for(int j=0;j<m;j++)
				{
					tham[dstam[j]]=0;
				}
			}
		}
	}
	
}
void DinhTru(DsCanh dsdd,DsDinh dsd,int stplt)
{
	int stplt1;
	Dinh dinh;
	int i=0;
	int dem=0;
	string s="Dinh tru: ";
	int x=dsd.n;
	while(i<x)
	{
		dinh=dsd.ds[0];
		Delete(dsd,0);//xoa dinh kiem tra xem no co la dinh tru hay khong
		stplt1=0;
		DFS_DTru(dsdd,dsd,stplt1);
		if(stplt1>stplt)//so tplt tang thi la dinh tru
		{
			dem++;
			s=s+dinh.tendinh;
			setcolor(GREEN);
			setbkcolor(7);
			settextstyle(8,0,2);
			outtextxy(312,500,(char*)s.c_str());
			s=s+"-";
			Ve_Lai_Dinh(dinh.x,dinh.y,dinh.tendinh,4);
		}
		i++;
		dsd.ds[dsd.n++]=dinh;//them dinh vua xoa vao lai danh sach
	}
	s="So dinh tru: ";
	char tam[10];
	Chuyen_Sang_Chuoi(tam,dem);
	s=s+tam;
	setcolor(BLACK);
	setbkcolor(7);
	settextstyle(8,0,2);
	outtextxy(312,500+textheight("sdf"),(char*)s.c_str());
}
//sap xep topo
void Topo_Sort(DsCanh dsdd,DsDinh dsd)
{
	bool kt;
	string dsdinh[30];
	int m=0;
	for(int i=0;i<dsd.n;i++)//lay nhung dinh khong phai la dinh cuoi cua canh nao
	{
		kt=true;
		for(int j=0;j<dsdd.n;j++)
		{
			if(stricmp(dsd.ds[i].tendinh,dsdd.ds[j].dinhcuoi.tendinh)==0)
			{
				kt=false;
				break;
			}
		}
		if(kt==true)
		{
			dsdinh[m++]=dsd.ds[i].tendinh;//dua vao danh sach
		}
	}
	int i=0;
	while(dsdd.n>0 && m>0)
	{
		for(int j=0;j<dsdd.n;j++)
		{
			if(stricmp((char*)dsdinh[i].c_str(),dsdd.ds[j].dinhdau.tendinh)==0)//tim dinh cuoi cua dinh trong dsdinh dua vao dsdinh
			{
				dsdinh[m]=dsdd.ds[j].dinhcuoi.tendinh;
				for(int k=0;k<dsdd.n;k++)//xoa nhung canh co duong di toi dinh vua duoc chon
				{
					if(stricmp(dsdd.ds[k].dinhcuoi.tendinh,(char*)dsdinh[m].c_str())==0)//neu dinh vua them vao la dinh cuoi cua 1 canh nao do thi xoa canh do di
					{
						Delete_Duongdi(dsdd,k);
						k--;
					}
				}
				m++;
			}
		}
		i++;
		if(i==m)//khi duyet den cuoi danh sach thi quay lai duyet dau danh sach cho den khi dsdd.n ==0 co nghia la da lay duoc tat ca cac dinh
		{
			i=0;
		}
	}
	if(m>0)
	{
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Thu tu TOPO: ");
		string s;
		for(int j=0;j<m;j++)
		{
			s=s+dsdinh[j];
			setcolor(GREEN);
			setbkcolor(7);
			settextstyle(8,0,2);
			outtextxy(312,500+textheight("sdfg"),(char*)s.c_str());
			s=s+"-->";
			for(int k=0;k<dsd.n;k++)
			{
				if(dsdinh[j]==dsd.ds[k].tendinh)
				{
					Ve_Lai_Dinh(dsd.ds[k].x,dsd.ds[k].y,dsd.ds[k].tendinh,4);
					break;
				}
			}
			Sleep(500);
		}
	}
	else
	{
		settextstyle(8,0,2);
		setbkcolor(7);
		setcolor(BLACK);
		outtextxy(312,500,"Ton tai chu trinh.");
	}

}
//Duyet BFS de kiem tra X-Y co lien thong hay khong va tim duong di tu X_Y(dinh that)
void BFS1_DT(DsDinh dsd,int a[][30],int tham[],int truoc[],int dinhxp)
{
	int QUEUE[30],d,c;
	d=c=0;
	QUEUE[c++]=dinhxp;
	tham[dinhxp]=1;
	while(d!=c)
	{
		dinhxp=QUEUE[d++];
		for(int j=0;j<dsd.n;j++)
		{
			if(tham[j]==0 && a[dinhxp][j]!=0)
			{
				truoc[j]=dinhxp;
				QUEUE[c++]=j;
				tham[j]=1;
			}
		}
	}
}
//tim dinh that
void DinhThat(DsCanh dsdd,DsDinh dsd,int dinhxp,int dinhkt)
{
	int tham[30],a[30][30],truoc[30];
	for(int i=0;i<dsd.n;i++)
	{
		tham[i]=0;
	}
	for(int i=0;i<dsd.n;i++)
	{
		for(int j=i;j<dsd.n;j++)
		{
			a[i][j]=a[j][i]=0;
		}
	}
	TimMaTranKe(dsdd,dsd,a);
	BFS1_DT(dsd,a,tham,truoc,dinhxp);//tim cac dinh di qua
	if(tham[dinhkt]==0)
	{
		setbkcolor(7);
		setcolor(BLACK);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdfd")*2,"Khong lien thong.");
	}
	else
	{
		int dsdinh[30];
		int v=dinhkt;
		int m=0;
		while(v!=dinhxp)//dua cac dinh di qua vao danh sach(khong dua dinhxp vao ds)
		{
			v=truoc[v];
			dsdinh[m++]=v;
		}
		string s="Dinh that: ";
		for(int i=0;i<m-1;i++)//khong lay dinh xuat phat va dinh ket thuc(dinh ket thuc tai m-1)
		{
			for(int k=0;k<dsd.n;k++)
			{
				tham[k]=0;
			}
			for(int k=0;k<dsd.n;k++)
			{
				for(int h=k;h<dsd.n;h++)
				{
					a[k][h]=a[h][k]=0;
				}
			}
			TimMaTranKe(dsdd,dsd,a);
			for(int h=0;h<dsd.n;h++)//xoa dinh trong ma tran ke
			{
				a[h][dsdinh[i]]=a[dsdinh[i]][h]=0;
			}
			BFS1_DT(dsd,a,tham,truoc,dinhxp);
			if(tham[dinhkt]==0)//neu khong co duong di thi no la dinh that
			{
				s=s+dsd.ds[dsdinh[i]].tendinh;
				setbkcolor(7);
				settextstyle(8,0,2);
				setcolor(GREEN);
				outtextxy(312,500+textheight("dfds")*2,(char*)s.c_str());
				Ve_Lai_Dinh(dsd.ds[dsdinh[i]].x,dsd.ds[dsdinh[i]].y,dsd.ds[dsdinh[i]].tendinh,4);
				s=s+" , ";
				Sleep(500);
			}
		}
	}
	
}
//hien thi hop thu thong bao va thuc thi
int DisplayMessageBox(DsDinh &dsd,DsCanh &dsdd)
{
	int msgboxID=MessageBox(0, "Ban muon xoa?", "Xoa do thi",MB_OKCANCEL+32);//1:có 2 lua chon YES or CANCEL,32:them dau cham hoi truoc cau hoi
	switch(msgboxID)
	{
		case 1:
			InitScreen();
			dsd.n=dsdd.n=0;
			break;
		case 2:
			break;
	}
	return 0;
}
void MenuChucNang(DsDinh &dsd,DsCanh &dsdd,int x,int y)
{
	static int dem=0;
	char TenDinh[]="A";
	while(1)
	{
		//them dinh
		if( (x>310 && x<390)&&(y>1&& y<80))
		{
			if(dem<=25)
			{
				Them_Dinh(dsd,dsdd,x,y ,TenDinh,dem);
			}
			else
			{
				MessageBox(0, "Khong the them dinh.", "Thong bao",MB_OK+MB_ICONWARNING);//1:có 1 lua chon OK,them dau cham than
				break;
			}
		}
		//noi 2 dinh
		else if( (x>310 && x<390)&&(y>80&& y<160) )
		{
			Noi_Dinh(dsdd,dsd,x,y);
		}
		//doi ten dinh hoac trong so
		else if((x>310 && x<390)&&(y>160&& y<240))
		{
			Doi_TenDinh(dsdd,dsd,x,y,TenDinh);
		}
		//xoa dinh
		else if((x>310 && x<390)&&(y>240&& y<320))
		{
			Delete_TuyChon(dsdd,dsd,x,y);
		}
		//di chuyen dinh
		else if((x>310 && x<390)&&(y>320&& y<400) )
		{
			Move(dsdd,dsd,x,y);
		}
		//xoa do thi
		else if( (x>310 && x<390)&&(y>400&& y<480))
		{
			Ve_Khung_TC();
			setfillstyle(1,11);
			bar(311,400,389,480);
			Ve_Hinh_Chucnang();
			setcolor(GREEN);
			rectangle(389,1,1300,480);
			//hien thi hop thoai thong bao va thuc thi lenh xoa
			DisplayMessageBox(dsd,dsdd);
			Ve_Khung_TC();
			Ve_Hinh_Chucnang();
			dem=0;
			TenDinh[0]='A';
			break;//de dong messageBox
		}
		else
		{
			break;
		}
	}

}
void MenuFile(DsCanh &dsdd,DsDinh &dsd,int x,int y,int &kt)
{	
	if(x>=5 && x<=95 && y>=320 && y<=370)//mo file de doc
	{
		settextstyle(2,0,5);
		setfillstyle(1,11);		//to mau cho o chuc nang duoc chon
		bar(5,320,95,370);
		setcolor(1);
		setlinestyle(0,0,1);
		rectangle(6,321,93,368);
		setcolor(BLACK);
		setbkcolor(11);			//tao mau nen de ghi chu
		outtextxy(20,340,"MO FILE");
		ifstream fileIn;
		dsd.n=dsdd.n=0;
		ReadFile(fileIn,dsdd,dsd);
		Ve_Dothi(dsd,dsdd);
		Sleep(100);
		setfillstyle(1,15);		//to mau cho o chuc nang duoc chon
		bar(5,320,95,370);
		setbkcolor(15);			//tao mau nen de ghi chu
		setcolor(RED);
		settextstyle(2,0,5);
		outtextxy(20,340,"MO FILE");
	}
	else if(x>=105 && x<=195 && y>=320 && y<=370)//mo file de ghi
	{
		settextstyle(2,0,5);
		setfillstyle(1,11);		//to mau cho o chuc nang duoc chon
		bar(105,320,195,370);
		setlinestyle(0,0,1);
		setcolor(1);
		rectangle(106,321,193,368);
		setbkcolor(11);			//tao mau nen ghi chu cho khung duoc chon
		setcolor(BLACK);
		outtextxy(120,340,"LUU FILE");
		ofstream fileOut;
		WriteFile(fileOut,dsdd,dsd);
		Sleep(100);
		setfillstyle(1,15);		//to mau cho o chuc nang duoc chon
		bar(105,320,195,370);
		setcolor(RED);
		setbkcolor(15);			//tao mau nen ghi chu cho khung duoc chon
		settextstyle(2,0,5);
		outtextxy(120,340,"LUU FILE");
	}
	else if(x>=205 && x<=295 && y>=320 && y<=370)
	{
		settextstyle(2,0,5);
		setfillstyle(1,11);		//to mau cho o chuc nang duoc chon
		bar(205,320,295,370);
		setcolor(1);
		setlinestyle(0,0,1);
		rectangle(205,320,293,368);
		setbkcolor(11);			//tao mau nen ghi chu cho khung duoc chon
		setcolor(BLACK);
		outtextxy(220,340,"THOAT");
		kt=0;
		Sleep(500);
		settextstyle(2,0,5);
		setfillstyle(1,15);		//to mau cho o chuc nang duoc chon
		bar(205,320,295,370);
		setbkcolor(15);			//tao mau nen ghi chu cho khung duoc chon
		setcolor(BLACK);
		outtextxy(220,340,"THOAT");
		return;
	}
}
void MenuThuatToan(DsCanh dsdd,DsDinh dsd,int x,int y)
{
	//DFS
	if(x>=5 && x<=95 && y>=40 && y<=90)
	{
		setfillstyle(1,11);
		bar(5,40,95,90);
		setcolor(1);		//mau vien xanh
		setlinestyle(0,0,1);
		rectangle(5,40,93,88);
		setbkcolor(11);			//tao nen mau xanh
		setcolor(BLACK);
		settextstyle(2,0,5);		//phong,huong,co chu
		outtextxy(40,60,"DFS");
		int a[30][30];
		int tham[30];
		int n=dsd.n;
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Chon dinh bat dau: ");
		int x,y;
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    for(int i=0;i<dsd.n;i++)
	    {
	    	if(x>=dsd.ds[i].x-20 && x<=dsd.ds[i].x+20 &&y>=dsd.ds[i].y-20 && y<=dsd.ds[i].y+20)
	    	{
	    		settextstyle(8,0,2);
	    		outtextxy(312+textwidth("Chon dinh bat dau:  "),500,dsd.ds[i].tendinh);
	    		DFS(dsdd,dsd,a,n,tham,i);
	    		setcolor(BLACK);
	    		settextstyle(8,0,2);
	    		outtextxy(312,500+textheight("asd")*2,"Click chuot de tiep tuc");
	    		while (1)
				{
			        delay(0.0001);
			        if (ismouseclick(WM_LBUTTONDOWN))
					{
			            getmouseclick(WM_LBUTTONDOWN, x, y);
			            break;
			        }
			    }
			    Ve_Khung_KQ();
	    		break;
			}
		}
		Ve_Khung_KQ();
		setfillstyle(1,15);
		bar(5,40,95,90);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(40,60,"DFS");
	}
	//BFS
	else if(x>=105 && x<=195 && y>=40 && y<=90)
	{
		setfillstyle(1,11);
		bar(105,40,195,90);
		setcolor(1);		//mau vien xanh
		setlinestyle(0,0,1);
		rectangle(105,40,193,88);
		setcolor(BLACK);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		outtextxy(140,60,"BFS");
		int a[30][30];
		int tham[30];
		int QUEUE[30];
		//int n=dsd.n;
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Chon dinh bat dau: ");
		int x,y;
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    for(int i=0;i<dsd.n;i++)
	    {
	    	if(x>=dsd.ds[i].x-20 && x<=dsd.ds[i].x+20 &&y>=dsd.ds[i].y-20 && y<=dsd.ds[i].y+20)
	    	{
	    		settextstyle(8,0,2);
	    		outtextxy(312+textwidth("Chon dinh bat dau:  "),500,dsd.ds[i].tendinh);
	    		BFS(dsdd,dsd,a,QUEUE,tham,i);
	    		setcolor(BLACK);
	    		settextstyle(8,0,2);
	    		outtextxy(312,500+textheight("asd")*2,"Click chuot de tiep tuc");
	    		while (1)
				{
			        delay(0.0001);
			        if (ismouseclick(WM_LBUTTONDOWN))
					{
			            getmouseclick(WM_LBUTTONDOWN, x, y);
			            break;
			        }
			    }
			    Ve_Khung_KQ();
	    		break;
			}
		}
		Ve_Khung_KQ();
		setfillstyle(1,15);
		bar(105,40,195,90);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(140,60,"BFS");
	}
	//X-->Y
	else if(x>=205 && x<=295 && y>=40 && y<=90)
	{
		setfillstyle(1,11);
		bar(205,40,295,90);
		setlinestyle(0,0,1);
		setcolor(1);		//mau vien xanh
		rectangle(205,40,293,88);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(240,60,"X->Y");
		
		int dinhxp,dinhkt;
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500,"Chon dinh bat dau: ");
		int x,y,x1,y1;
		bool kt1,kt2;
		kt1=kt2=false;
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    for(int i=0;i<dsd.n;i++)
	    {
	    	if(x>=dsd.ds[i].x-20 && x<=dsd.ds[i].x+20 &&y>=dsd.ds[i].y-20 && y<=dsd.ds[i].y+20)
	    	{
	    		kt1=true;
	    		settextstyle(8,0,2);
	    		outtextxy(312+textwidth("Chon dinh bat dau: "),500,dsd.ds[i].tendinh);
	    		dinhxp=i;
	    		break;
	    	}
		}
		settextstyle(8,0,2);
	   	outtextxy(312,500+textheight("asd"),"Chon dinh ket thuc: ");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x1, y1);
	            break;
	        }
	    }
	    for(int i=0;i<dsd.n;i++)
	    {
	    	if(x1>=dsd.ds[i].x-20 && x1<=dsd.ds[i].x+20 &&y1>=dsd.ds[i].y-20 && y1<=dsd.ds[i].y+20)
	    	{
	    		kt2=true;
	    		dinhkt=i;
	    		settextstyle(8,0,2);
	    		outtextxy(312+textwidth("Chon dinh ket thuc: "),500+textheight("asd"),dsd.ds[i].tendinh);
	    		break;
	    	}
		}
		if(kt1==true && kt2==true)
		{
			X_Y(dsdd,dsd,dinhxp,dinhkt);	
		}
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x1, y1);
	            break;
	        }
	    }
		setfillstyle(1,15);
		bar(205,40,295,90);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(240,60,"X->Y");
		Ve_Khung_KQ();
	}
	//DINH TRU
	else if(x>=5 && x<=95 && y>=100 && y<=150)
	{
		setfillstyle(1,11);
		bar(5,100,95,150);
		setlinestyle(0,0,1);
		setcolor(1);			//mau vien xanh
		rectangle(6,101,93,148);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(20,120,"DINH TRU");
		int stplt=0;
		//BFS_CC(dsdd,dsd,stplt);
		DFS_DTru(dsdd,dsd,stplt);
		DinhTru(dsdd,dsd,stplt);
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdf")*2,"Click chuot de tiep tuc.");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    Ve_Khung_KQ();
		setfillstyle(1,15);
		bar(5,100,95,150);
		setbkcolor(15);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(20,120,"DINH TRU");
		
	}
	//DINH THAT
	else if(x>=105 && x<=195 && y>=100 && y<=150)
	{
		setfillstyle(1,11);
		bar(105,100,195,150);
		setlinestyle(0,0,1);
		setcolor(1);			//mau vien xanh
		rectangle(106,101,193,148);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(120,120,"DINH THAT");
		string s="Chon dinh bat dau: ";
		setbkcolor(7);
		setcolor(BLACK);
		settextstyle(8,0,2);
		outtextxy(312,500,(char*)s.c_str());
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    int dinhxp,dinhkt;
	    bool kt1,kt2;
	    kt1=kt2=false;
	    for(int i=0;i<dsd.n;i++)
	    {
	    	if(x>=dsd.ds[i].x-20 && x<=dsd.ds[i].x+20 && y>=dsd.ds[i].y-20 && y<=dsd.ds[i].y+20 )
	    	{
	    		dinhxp=i;
	    		s=s+dsd.ds[dinhxp].tendinh;
	    		kt1=true;
	    		break;
			}
		}
		outtextxy(312,500,(char*)s.c_str());
		s="Chon dinh ket thuc: ";
		outtextxy(312,500+textheight("sdf"),(char*)s.c_str());
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    for(int i=0;i<dsd.n;i++)
	    {
	    	if(x>=dsd.ds[i].x-20 && x<=dsd.ds[i].x+20 && y>=dsd.ds[i].y-20 && y<=dsd.ds[i].y+20 )
	    	{
	    		dinhkt=i;
	    		s=s+dsd.ds[dinhkt].tendinh;
	    		kt2=true;
	    		break;
			}
		}
		outtextxy(312,500+textheight("sdf"),(char*)s.c_str());
		if(kt1==true && kt2==true)
		{
			DinhThat(dsdd,dsd,dinhxp,dinhkt);	
		}
		setbkcolor(7);
		setcolor(BLACK);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdff")*4,"Click chuot de tiep tuc.");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
		Ve_Khung_KQ();
		setfillstyle(1,15);
		bar(105,100,195,150);
		setlinestyle(0,0,1);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(120,120,"DINH THAT");
	}
	//CANH CAU
	else if(x>=205 && x<=295 && y>=100 && y<=150)
	{
		setfillstyle(1,11); 
		bar(205,100,295,150);
		setlinestyle(0,0,1);
		setcolor(1);			//mau vien xanh
		rectangle(206,101,293,148);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(220,120,"CANH CAU");
		int stplt;
		DFS_CC(dsdd,dsd,stplt);
		CanhCau(dsdd,dsd,stplt);
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdf")*2,"Click chuot de tiep tuc.");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    Ve_Khung_KQ();
		setfillstyle(1,15);
		bar(205,100,295,150);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(220,120,"CANH CAU");
	}
	//hamilton
	else if(x>=5 && x<=95 && y>=160 && y<=210)
	{
		setfillstyle(1,11);
		bar(5,160,95,210);
		setlinestyle(0,0,1);
		setcolor(1);		//mau vien xanh
		rectangle(5,160,93,208);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(20,180,"HAMILTON");
		Hamilton(dsdd,dsd);
		setcolor(BLACK);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdf"),"Click chuot de tiep tuc.");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
		Ve_Khung_KQ();
		setfillstyle(1,15);
		bar(5,160,95,210);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(20,180,"HAMILTON");
	}
	//EULER
	else if(x>=105 && x<=195 && y>=160 && y<=210)
	{
		setfillstyle(1,11);
		bar(105,160,195,210);
		setlinestyle(0,0,1);
		setcolor(1);		//mau vien xanh
		rectangle(105,160,193,208);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(130,180,"EULER");
		Euler_Cycle(dsdd,dsd);
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdf"),"Click chuot de tiep tuc.");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    Ve_Khung_KQ();
	   	setfillstyle(1,15);
		bar(105,160,195,210);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(130,180,"EULER");
	}
	//TOPO SORT
	else if(x>=205 && x<=295 && y>=160 && y<210)
	{
		setfillstyle(1,11);
		bar(205,160,295,210);
		setlinestyle(0,0,1);
		setcolor(1);		//mau vien xanh
		rectangle(206,161,293,208);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(210,180,"TOPO SORT");
		Topo_Sort(dsdd,dsd);
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdf")*2,"Click chuot de tiep tuc.");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
	        {
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    Ve_Khung_KQ();
	   	setfillstyle(1,15);
		bar(205,160,295,210);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(210,180,"TOPO SORT");
		
	}
	//TPLT
	else if(x>=5 && x<=95 && y>=220 && y<=270)
	{
		setfillstyle(1,11);
		bar(5,220,95,270);
		setcolor(1);		//mau vien xanh
		setlinestyle(0,0,1);		//dang,mau,do lon net ve
		rectangle(7,222,93,268);
		setbkcolor(11);			//tao nen mau xanh
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(BLACK);
		outtextxy(30,240,"TPLT");
		TPLT(dsdd,dsd);
		setcolor(BLACK);
		setbkcolor(7);
		settextstyle(8,0,2);
		outtextxy(312,500+textheight("sdfsg")*3,"Click chuot de tiep tuc.");
		while (1)
		{
	        delay(0.0001);
	        if (ismouseclick(WM_LBUTTONDOWN))
			{
	            getmouseclick(WM_LBUTTONDOWN, x, y);
	            break;
	        }
	    }
	    Ve_Khung_KQ();
		setfillstyle(1,15);
		bar(5,220,95,270);
		setbkcolor(15);			//tao nen mau trang
		settextstyle(2,0,5);		//phong,huong,co chu
		setcolor(RED);
		outtextxy(30,240,"TPLT");
	}
}
