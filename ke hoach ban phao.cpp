#include <iostream.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

/*
	Doi net quay xung quanh van de ban phao hoa :
   	1, Vi tri ban phao hoa & phuong huong ban phao & khoang cach ban no
      2, Kieu no phao, mau phao no, ket thuc qua trinh no thi cho phao roi the nao?
   Chi tiet hoa van de :
   	1.1, vi tri ban
      		duoc xac dinh random o dong thu 49 , tai toa do x bat ky
      1.2, phuong huong ban
      		duoc random boi 3 kieu ban co ban
            	-> phuong thang dung
               -> phuong cheo sang phai < neu nhu toa do o ben trai>
               -> phuong cheo sang trai < neu nhu toa do o ben phai>
      1.3, khoang cach ban phao no
      		duoc han che random cho den toa do y bat ky nhung phai nho hon 35
      2.1, Kieu no phao, gom cac kieu co ban sau :
      		-> kieu hinh tron
            -> kieu hinh chu thap kep (8 huong)
            -> kieu mang luoi
      2,2, Mau phao no , duoc random boi 2 loai co ban:
      		-> loai 1 mau duy nhat
            -> loai da mau sac
      2,3, Ket thuc qua trinh phao no, cac loai phao duoc quy dinh quay tro ve trang thai
      		chi con la mot dau cham va roi xuong theo phuong thang dung va bien mat
            bat ky o vi tri nao do
*/
/*
	Suy nghi chung ve ket cau cua mot qua phao :
   	- mot qua phao luc ban dau moi xuat hien thi chi la 1 diem;
      - ta xac dinh su di chuyen cua no dua vao su cap nhat thoi gian
      - den khi no, ta se cho no random kieu no va tu dong sinh ra cac qua phao con
      - sau khi no, roi xuong va mat di bat ky
*/
#define minx 1
#define maxx 79
#define miny 1
#define maxy 50
void del_display_star(int x,int y)
{
	gotoxy(x,y);
   cout<<" ";
}
void display_star(int x,int y,int type,int color)
{
	textcolor(color);
	gotoxy(x,y);
   cprintf("%c",type);
}
void display_star(int a[],int b[],int spt)
{
	for(int i=0;i<spt;i++)
   	display_star(a[i],b[i],15,11);
}
void move_star_left(int &x,int &y)
	{if(x>minx){x--;y;}}
void move_star_right(int &x,int &y)
	{if(x<maxx){x++;y;}}
void move_star_down(int &x,int &y)
	{if(y<maxy){x;y++;}}
void move_star_up(int &x,int &y)
	{if(y>miny){x;y--;}}
void move_star_up_left(int &x,int &y)
	{if(x>minx&&y>miny){x--;y--;}}
void move_star_up_right(int &x,int &y)
	{if(x<maxx&&y>miny){x++;y--;}}
void move_star_down_left(int &x,int &y)
	{if(x>minx&&y<maxy){x--;y++;}}
void move_star_down_right(int &x,int &y)
	{if(x<maxx&&y<maxy){x++;y++;}}
void move_up_left(int a[],int b[],int &spt)
{
	for(int i=0;i<spt;i++)
   {
   	a[i]--;
      b[i]--;
   }
}
void move_up_right(int a[],int b[],int &spt)
{
	for(int i=0;i<spt;i++)
   {
   	a[i]++;
      b[i]--;
   }
}
void move_up(int a[],int b[],int &spt)
{
	for(int i=0;i<spt;i++)
   {
   	a[i];
      b[i]--;
   }
}
void start_star(int &x,int &y)
{
	randomize();
	do{x=random(80);}while(x<1);
   y=25;
}
bool seek_star(int a[],int b[],int &spt,int x,int y)
{
	for(int i=0;i<spt;i++)
   	if(a[i]==x&&b[i]==y)
      	return true;
   return false;
}
void start_star(int a[],int b[],int k[],int &spt,int x,int y)
{
	spt=0;
   a[spt]=x+1;	b[spt++]=y;       //0
   a[spt]=x-1;	b[spt++]=y;       //1
   a[spt]=x;	b[spt++]=y+1;     //2
   a[spt]=x;	b[spt++]=y-1;     //3
   a[spt]=x+1;	b[spt++]=y-1;     // 4
   a[spt]=x-1;	b[spt++]=y-1;     // 5
   a[spt]=x-1;	b[spt++]=y+1;     // 6
   a[spt]=x+1;	b[spt++]=y+1;     // 7
   a[spt]=x-7;	b[spt++]=y-1;     // 8
   a[spt]=x+7;	b[spt++]=y-1;     //  9
   a[spt]=x-7;	b[spt++]=y+1;      // 10
   a[spt]=x+7;	b[spt++]=y+1;      //  11
   for(int i=0;i<spt;i++)
   	k[i]=0;
}
bool check(int count,int k)
{
	switch(k)
   {
   	case 0:
      {if(count<6)return true;return false;}
      case 1:
      {if(count<6)return true;return false;}
      case 2:
      {if(count<6)return true;return false;}
      case 3:
      {if(count<6)return true;return false;}
      case 4:
      {if(count<6)return true;return false;}
      case 5:
      {if(count<6)return true;return false;}
      case 6:
      {if(count<6)return true;return false;}
      case 7:
      {if(count<6)return true;return false;}
      case 8:
      {if(count<6)return true;return false;}
      case 9:
      {if(count<6)return true;return false;}
      case 10:
      {if(count<6)return true;return false;}
      case 11:
      {if(count<6)return true;return false;}
   }
   return false;
}
void move_type_one(int a[],int b[],int k[],int spt)
{
	for(int i=0;i<spt;i++)
   {
   	del_display_star(a[i],b[i]);

   	switch(i)
      {
      	case 0:if(check(k[i],i)) move_star_right(a[i],b[i]);break;
         case 1:if(check(k[i],i)) move_star_left(a[i],b[i]);break;
         case 2:if(check(k[i],i)) move_star_down(a[i],b[i]);break;
         case 3:if(check(k[i],i)) move_star_up(a[i],b[i]);break;
			case 4:if(check(k[i],i)) move_star_up_right(a[i],b[i]);break;
         case 5:if(check(k[i],i)) move_star_up_left(a[i],b[i]);break;
         case 6:if(check(k[i],i)) move_star_down_left(a[i],b[i]);break;
         case 7:if(check(k[i],i)) move_star_down_right(a[i],b[i]);break;
         case 8:if(check(k[i],i)) move_star_up_left(a[i],b[i]);break;
         case 9:if(check(k[i],i)) move_star_up_right(a[i],b[i]);break;
         case 10:if(check(k[i],i)) move_star_down_left(a[i],b[i]);break;
         case 11:if(check(k[i],i)) move_star_down_right(a[i],b[i]);break;
      }
      display_star(a[i],b[i],15,11);
      k[i]++;
   }
}
void main()
{
	textmode(C4350);
	int star[100],star1[100],k[100],spt=1;
	int x,y;
   start_star(x,y);
   gotoxy(x,y);
   cout<<char(15);
   start_star(star,star1,k,spt,x,y);
   display_star(star,star1,spt);
   getch();
   clock_t start,end;
   start=clock();
   while(1)
   {
   	end=clock();
      if(((end-start)/CLK_TCK)>=.1)
      {
      	start=end;
         move_type_one(star,star1,k,spt);
      }
   }
}
