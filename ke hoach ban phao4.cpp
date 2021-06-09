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
void del_display_star(int a[],int b[],int spt)
{
	for(int i=0;i<spt;i++)
   {
   	gotoxy(a[i],b[i]);
      cout<<" ";
   }
}
void display_star(int x,int y,int type,int color)
{
	if(color==0)
 		randomize();
	if(color==-1||color==0)
   {
   	do{color=random(16);}while(color<10);
   }
	textcolor(color);
	gotoxy(x,y);
   cprintf("%c",type);
}
void display_star(int a[],int b[],int spt)
{
	for(int i=0;i<spt;i++)
   	display_star(a[i],b[i],15,11);
}
bool move_star_left(int &x,int &y,int i)
	{del_display_star(x,y);if(x-i>minx){x-=i;y;return true;}return false;}
bool move_star_right(int &x,int &y,int i)
	{del_display_star(x,y);if(x+i<maxx){x+=i;y;return true;}return false;}
bool move_star_down(int &x,int &y,int i)
	{del_display_star(x,y);if(y+i<maxy){x;y+=i;return true;}return false;}
bool move_star_up(int &x,int &y,int i)
	{del_display_star(x,y);if(y-i>miny){x;y-=i;return true;}return false;}
bool move_star_up_left(int &x,int &y,int i,int k=0)
	{del_display_star(x,y);if(x-(i+k)>minx&&y-i>miny){x-=(i+k);y-=i;return true;}return false;}
bool move_star_up_right(int &x,int &y,int i,int k=0)
	{del_display_star(x,y);if(x+(i+k)<maxx&&y-i>miny){x+=(i+k);y-=i;return true;}return false;}
bool move_star_down_left(int &x,int &y,int i,int k=0)
	{del_display_star(x,y);if(x-(i+k)>minx&&y+i<maxy){x-=(i+k);y+=i;return true;}return false;}
bool move_star_down_right(int &x,int &y,int i,int k=0)
	{del_display_star(x,y);if(x+(i+k)<maxx&&y+i<maxy){x+=(i+k);y+=i;return true;}return false;}
void start_star(int &x,int &y)
{
	if(x>=1&&x<80&&y>1&&y<50)
{   	gotoxy(x,y);cout<<" ";}
	do{x=random(79);}while(x<2);
   y=49;
}
void start_star(int a[],int b[],int k[],int &spt,int x,int y)
{
	spt=0;
   if(x+1<maxx){a[spt]=x+1;	b[spt++]=y;}       //0
   if(x-1>minx){a[spt]=x-1;	b[spt++]=y;}       //1
   if(y+1<maxy){a[spt]=x;	b[spt++]=y+1; }    //2
   if(y-1>miny){a[spt]=x;	b[spt++]=y-1; }    //3
   if(x+1<maxx&&y-1>miny){a[spt]=x+1;	b[spt++]=y-1;}     // 4
   if(x-1>minx&&y-1>miny){a[spt]=x-1;	b[spt++]=y-1;}     // 5
   if(x-1>minx&&y+1<maxy){a[spt]=x-1;	b[spt++]=y+1;}     // 6
   if(x+1<maxx&&y+1<maxy){a[spt]=x+1;	b[spt++]=y+1;}     // 7
   if(x-1>minx&&y-1>miny){a[spt]=x-2;	b[spt++]=y-1;}     // 8
   if(x+1<maxx&&y-1>miny){a[spt]=x+2;	b[spt++]=y-1;}     //  9
   if(x-1>minx&&y+1<maxy){a[spt]=x-2;	b[spt++]=y+1;}      // 10
   if(x+1<maxx&&y+1<maxy){a[spt]=x+2;	b[spt++]=y+1;}      //  11
   for(int i=0;i<spt;i++)
   	k[i]=0;
}

bool move_type_one(int a[],int b[],int k[],int spt,int c,int space,bool lock,int type_star=0)
{
	int type=15;
	for(int i=0;i<spt;i++)
   {
   	del_display_star(a[i],b[i]);
      if(k[i]<space)
      {
      	if(!type_star)
         {
      	if(k[i]>=space*40/100)
         	type=42;
      	if(k[i]>=space*60/100)
         	type=-7;
      	if(k[i]>=space*80/100)
         	type=-6;
         }
         else
         {
          	if(k[i]>=space*10/100)
         	type=42;
      	if(k[i]>=space*20/100)
         	type=-7;
      	if(k[i]>=space*60/100)
         	type=-6;
         }
   	switch(i)
      {
      	case 0:if( move_star_right(a[i],b[i],4)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]); break;
         case 1:if( move_star_left(a[i],b[i],4)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 2:if( move_star_down(a[i],b[i],2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 3:if( move_star_up(a[i],b[i],2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
			case 4:if( move_star_up_right(a[i],b[i],2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 5:if( move_star_up_left(a[i],b[i],2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 6:if( move_star_down_left(a[i],b[i],2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 7:if( move_star_down_right(a[i],b[i],2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 8:if( move_star_up_left(a[i],b[i],1,2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 9:if( move_star_up_right(a[i],b[i],1,2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 10:if( move_star_down_left(a[i],b[i],1,2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
         case 11:if( move_star_down_right(a[i],b[i],1,2)&&lock)display_star(a[i],b[i],type,c);else del_display_star(a[i],b[i]);break;
      }
      	k[i]++;
      }
   }
   if(k[spt-1]>=space)
   	return false;
   return true;
}
class star
{
	public:
	int star[100],star1[100],k[100],spt,color,space,store1,store2,number,type;
   star();
   bool move();
   void start(int x,int y);
   void display()
   {
   	display_star(star,star1,spt);
   }
};
bool star::move()
   {
   	del_display_star(star,star1,spt);
      if (move_type_one(star,star1,k,spt,color,space,true,type))
      {	return true;}
      else
      	{
         	number--;
         	del_display_star(star,star1,spt);
            if(number>0)
            {
            	color=random(25);
      				if(color>15)
      					color=-1;
            	do{space=random(12);}while(space<3);
             	start_star(star,star1,k,spt,store1,store2);
               return true;
            }
         }
      return false;
   }
void star::start(int x,int y)
   {
   	store1=x,store2=y;
   	color=random(25);
      if(color>15)
      	color=-1;
         if(type%3==0||type%7==0)
      	type=1;
      else
      	type=0;
   	do{space=random(12);}while(space<3);
      do{number=random(4);}while(number<1);
   	start_star(star,star1,k,spt,x,y);
   }
star::star()
   {
   	store1=0,store2=0;
   	spt=0;
      color=random(25);
      if(color>15)
      	color=-1;
      type=random(87);
      if(type%11==0||type%7==0)
      	type=1;
      else
      	type=0;
      do{space=random(12);}while(space<4);
      do{number=random(4);}while(number<1);
   }
void move_up(int &x,int &y,int color)
{
	gotoxy(x,y);
   cout<<" ";
	if(y>2)
   {
   y--;
   gotoxy(x,y);
   textcolor(color);
   cprintf("%c",4);
   //cout<<char(4);
   }
}
void move_up_left(int &x,int &y,int color)
{
	gotoxy(x,y);
   cout<<" ";
   if(x>2&&y>2){
   x--;y--;
   gotoxy(x,y);
   textcolor(color);
   cprintf("%c",4);
   //cout<<char(4);
   }
}
void move_up_right(int &x,int &y,int color)
{
	gotoxy(x,y);
   cout<<" ";
	if(x<80&&y>2){
   x++;y--;
   gotoxy(x,y);
   textcolor(color);
   cprintf("%c",4);
   //cout<<char(4);
   }
}
bool automove(int &x,int &y,int &n,int k=0)
{
	if(x<=2||x>=79||y<=2)
   	return false;
   if(x<30&&k)
   {
   	int k=random(30);
      if(k%2==0)
      	n=2;
      else
      	n=0;
   }
   else
   {
   	if(n>50&&k)
      {
      	int k=random(30);
      if(k%2==0)
      	n=1;
      else
      	n=0;
      }
      else
      	{
         	if(k){
         	int k=random(30);
      		if(k%2==0)
      			n=2;
      		else
            	if(k%3==0)
      			n=1;
            	else
               	n=0;}
         }
   }
   int color;
   do{color=random(16);}while(color<9||color==14||color==11||color==12||color==13||color==10);
	switch(n)
   {
   	case 0: move_up(x,y,color);     break;
      case 1: move_up_left(x,y,color);      break;
      default: move_up_right(x,y,color);break;
   }
	return true;
}
void main()
{
	textmode(C4350);
   _setcursortype(0);

   star A,B,C;
   clock_t start,end,burn,burn1,start1,end1,burn2,start2;

   int x,y,lock,space,k=0,x1,y1,lock1,k1=0,space1;
   bool co=true,co1=true,co2=true,co3=true,co4=false;
   randomize();
   start_star(x1,y1);
   start_star(x,y);
   lock=random(12);
   if(lock%3==0)
   	lock=1;
   else
   	lock=0;
   gotoxy(x,y);
   cout<<char (9);
      lock1=random(12);
   if(lock1%3==0)
   	lock1=1;
   else
   	lock1=0;
   do{space1=random(30);}while(space1<4);
   start=clock();
   burn=start;
   burn1=start;
   end1=start;
   start2=start;
   burn2=start;
   do{space=random(30);}while(space<4);
   while(!kbhit())
   {
    	end = clock();
      if(((end-end1)/CLK_TCK)>=.7)
      {
      	end1=end;
      	start1=end;
      }
      if(co1&&((end-start)/CLK_TCK)>=.0004)
      {
      	start=end;
      	if(!automove(x,y,lock,k))
         { 	start_star(x,y);k=random(12);if(k%3==0||k%5==0)k=1;else k=0;  co1=true;}
      }
      if(y<=space&&co)
         {
         	co1=false;
         	A.start(x,y);
            co=false;
            lock = random (15);
            if(!co4&&lock %3==0)
            {
            	C.start(x,y);
               co4=true;
            }
         }
      if(y<=space&&((end-burn)/CLK_TCK)>=.1)
         {
         	burn=end;
            del_display_star(x,y);
            if(!A.move())
            {
            	start=end;
               burn=end;
            	start_star(x,y);
				   lock=random(15);
				   if(lock%5==0)
			      	lock=2;
				   if(lock%3==0)
			   		lock=1;
				   else
			   		lock=0;

               k=random(20);if(k%7==0||k%5==0)k=1;else k=0;
				   do{space=random(25);}while(space<7);
               co1=true;
               co=true;
            }
            if(co4&&((end-start2)/CLK_TCK)>=.2)
            if(((end-burn2)/CLK_TCK)>=.05)
            {
            	burn2=end;
               if(!C.move())
               {	start2=end;	co4=false;}
            }
         }
//============================================================================
			if(co3&&((end-start1)/CLK_TCK)>=.0005)
      {
      	start1=end;
      	if(!automove(x1,y1,lock1,k1))
         { 	start_star(x1,y1);k1=random(12);if(k1%3==0||k1%5==0)k1=1;else k1=0;  co3=true;}
      }
      if(y1<=space1&&co2)
         {
         	co3=false;
         	B.start(x1,y1);
            co2=false;
         }
      if(y1<=space1&&((end-burn1)/CLK_TCK)>=.12)
         {
         	burn1=end;
            del_display_star(x1,y1);
            if(!B.move())
            {
            	start1=end;
               burn1=end;
            	start_star(x1,y1);
				   lock1=random(15);
				   if(lock1%5==0)
			      	lock1=2;
				   if(lock1%3==0)
			   		lock1=1;
				   else
			   		lock1=0;

               k1=random(20);if(k1%7==0||k1%5==0)k1=1;else k1=0;
				   do{space1=random(25);}while(space1<7);
               co2=true;
               co3=true;
            }
         }

   }
}
