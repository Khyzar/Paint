#include "winbgim.h"
#include "graphics.h"
#include <iostream>
#include<math.h>

using namespace std;
class shape
{
protected:
     int x1,x2,y1,y2,area;
public:
	shape();
	virtual void draw(int);
};
shape::shape()
{
	x1=x2=y1=y2=area=0;
}
void shape::draw(int a)
{
	
}
class circal:public shape
{
protected:
	int radius;
public:
	circal();
	void draw(int);
};
circal::circal()
{
	radius=0;

}
void circal::draw(int a)
{
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		putpixel(x1,y1,LIGHTBLUE);
		cout<<x1<<" "<<y1<<endl;
		while(y1<90)
		{
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
			cout<<x1<<" "<<y1<<endl;
		}	
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x2,y2);
		putpixel(x2,y2,LIGHTBLUE);
		x2=(x2-x1)*(x2-x1);
		y2=(y2-y1)*(y2-y1);
		radius=x2+y2;
		radius=sqrt(radius);
		cout<<x2<<" "<<y2<<endl;
		circle(x1,y1,radius);
		area=3.1426*(radius*radius);
		cout<<"area of circle is: "<<area<<endl;
		
}
class rectangal:public shape
{
protected:
public:
	rectangal();
    void draw(int);
};
rectangal::rectangal()
{
	

}
void rectangal::draw(int a)
{
	int a1=0,a2=0,b1=0,b2=0,c1=0,d1=0;
	if(a==1)
	{
	   while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		putpixel(x1,y1,LIGHTBLUE);
		cout<<x1<<" "<<y1<<endl;
       while(y1<90)
		{
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
			cout<<x1<<" "<<y1<<endl;
		}
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x2,y2);
		putpixel(x2,y2,LIGHTBLUE);
		cout<<x2<<" "<<y2<<endl;
		rectangle(x1,y1,x2,y2);
		c1=(x2-x1)+(y1-y1);
		d1=(x2-x2)+(y2-y1);
		area=c1*d1;
		cout<<"area of rectangle is: "<<area<<endl;

		a1=x1;
		a2=x2;
		b1=y1;
		b2=y2;
		rectangle(x1,y2,x2,y1);

	}
	if(a==2)
	{
		a1=x1;
		a2=x2;
		b1=y1;
		b2=y2;
		rectangle(a1,b2,a2,b1);
	}
}
class liine:public shape
{
protected:
public:
	liine();
    void draw(int);
};
liine::liine()
{
}
void liine::draw(int a)
{
	int dis=0,c=0,b=0,b1=0,c1=0;
	if(a==1)
	{
	  while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		putpixel(x1,y1,LIGHTBLUE);
		cout<<x1<<" "<<y1<<endl;
		while(y1<90)
		{
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
			cout<<x1<<" "<<y1<<endl;
		}
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x2,y2);
		putpixel(x2,y2,LIGHTBLUE);
		cout<<x2<<" "<<y2<<endl;
		line(x1,y1,x2,y2);
		b1=(x2-x1)*(x2-x1);
		c1=(y2-y1)*(y2-y1);
		area=b1+c1;
		area=sqrt(area);
		cout<<"the area of line is: "<<area<<endl;
		
	}
	if(a==2)
	{
		b=(x2-x1)*(x2-x1);
		c=(y2-y1)*(y2-y1);
		dis=b+c;
		dis=sqrt(dis)/2;
		x1=(x1+x2)/2;
		y1=(y1+y2)/2;
		x2=x1;
		y2=y1;	
		line(x1,y1+dis,x2,y2-dis);
	}
}
class triangle:public shape
{
protected:
      int x3,y3;
public:
	triangle();
    void draw(int);
	
};
triangle::triangle()
{
	x3=y3=0;

}
void triangle::draw(int)
{
	int a=0,b=0,a1=0,b1=0;
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		putpixel(x1,y1,LIGHTBLUE);
		cout<<x1<<" "<<y1<<endl;
		while(y1<90)
		{
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
			cout<<x1<<" "<<y1<<endl;
		}
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x2,y2);
		putpixel(x2,y2,LIGHTBLUE);
		cout<<x2<<" "<<y2<<endl;
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x3,y3);
		putpixel(x3,y3,LIGHTBLUE);
		cout<<x3<<" "<<y3<<endl;
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);
		a=(x2-x1)*(x2-x1);
		b=(y2-y1)*(y2-y1);
		a1=b+a;
		a1=sqrt(a1);
		a=(x3-x2)*(x3-x2);
		b=(y3-y2)*(y3-y2);
		b1=b+a;
		b1=sqrt(b1);
		area=(a1*b1)/2;
		cout<<"the area of triangle is: "<<area<<endl;

		
}
class ellipce:public shape
{
protected:
public:
	ellipce();
    void draw(int);
};
ellipce::ellipce()
{

}
void ellipce::draw(int a)
{
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		putpixel(x1,y1,LIGHTBLUE);
		cout<<x1<<" "<<y1<<endl;
		while(y1<90)
		{
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
			cout<<x1<<" "<<y1<<endl;
		}
	while(!ismouseclick(WM_LBUTTONDOWN)){}
	    getmouseclick(WM_LBUTTONDOWN,x2,y2);
		putpixel(x2,y2,LIGHTBLUE);
		cout<<x2<<" "<<y2<<endl;
		ellipse (x1,y1,0,360,300-x1,(300-x1)/2);
		
}

void Interface(){
	initwindow(500,500,"Paint ");
	line(0,90,120,90);
	line(120,90,120,60);
	 outtextxy(0,70,"ROTATE LEFT");
	 line(120,90,240,90);
	line(240,90,240,60);
	 outtextxy(122,70,"ROTATE RIGHT");
	 line(240,90,360,90);
	line(360,90,360,60);
	 outtextxy(242,70,"ROTATE 180");
	line(0,60,500,60);
	line(60,0,60,60);
	line(120,0,120,60);
	line(180,0,180,60);
	line(240,0,240,60);
	line(308,0,308,60);
	line (350,0,350,60);
	line (308,30,350,30);
	line (350,30,500,30);
	line (350,0,350,60);
	line (390,0,390,60);
	line (430,0,430,60);
	outtextxy(395,33,"save");
	outtextxy(445,33,"exit");
	outtextxy(433,0,"new\n");
	outtextxy(433,13,"page");
	ellipse (270,30,0,360,300-270,(300-270)/2);
	circle(27,30,20);
	line(90,2,62,58);
	rectangle(130,2,170,50);
	line(207,6,187,44);
	line(187,44,231,44);
	line(231,44,207,6);
	for (int i=352;i<388;i++)
		for (int j=32;j<58;j++)
		{
			putpixel(i,j,BROWN);
		}
		for (int i=352;i<388;i++)
			for (int j=0;j<30;j++)
			{
				putpixel(i,j,RED);
			}
			for (int i=310;i<350;i++)
				for (int j=0;j<30;j++)
				{
					putpixel(i,j,GREEN);
				}
				for (int i=310;i<350;i++)
					for (int j=34;j<58;j++)
					{
						putpixel(i,j,BLUE);
					}
}
int main(){
	/*initwindow(500,500);
	int x,y,w,z;
	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x,y);

	while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,w,z);
		
		
		putpixel(x,y,6);
			circle(x,y,w);
			Sleep(500);

			cout<<x<<" "<<y<<endl;
	*/	
	int x,y,x1,y1,g=0;	
	shape **f;
	f=new shape*[4];
	circal a;
	liine b;
	rectangal c;
	triangle d;
	ellipce e;
	f[0]=&a;
	f[1]=&b;
	f[2]=&c;
	f[3]=&d;
	f[4]=&e;
   	Interface();
	while(1)
	{
		while(ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN,x,y);
			  cout<<x<<" "<<y<<endl;
			   if(x<50 && y<60)
			   {
				   f[0]->draw(g);
				   break;
			   }
			   if(x>50 && x<119  && y<60)
			   {
				   g=1;
				   f[1]->draw(g);
				   break;
			   }
			   if(x>119 && x<179  && y<60)
			   {
				   g=1;
				   f[2]->draw(g);
				   break;
			   }
			   if(x>179 && x<239  && y<60)
			   {
				   f[3]->draw(g);
				   break;
			   }
			   if(x>239 && x<309  && y<60)
			   {
				   f[4]->draw(g);
				   break;
			   }
			   if(x>309 && x<350  && y<30)
			   {
				   while(!ismouseclick(WM_LBUTTONDOWN)){}
				         getmouseclick(WM_LBUTTONDOWN,x1,y1);
				          setfillstyle(SOLID_FILL,GREEN);
                          floodfill(x1,y1,15);
				          break;
				   
			   }
			   if(x>309 && x<350  && y>30 && y<60)
			   {
				   while(!ismouseclick(WM_LBUTTONDOWN)){}
				         getmouseclick(WM_LBUTTONDOWN,x1,y1);
				          setfillstyle(SOLID_FILL,BLUE);
                          floodfill(x1,y1,15);
				          break;
			   }
			   if(x>350 && x<390  && y<30)
			   {
				   while(!ismouseclick(WM_LBUTTONDOWN)){}
				         getmouseclick(WM_LBUTTONDOWN,x1,y1);
				          setfillstyle(SOLID_FILL,RED);
                          floodfill(x1,y1,15);
				  
				   break;
			   }
			   if(x>350 && x<390  && y>30 && y<60)
			   {
				   while(!ismouseclick(WM_LBUTTONDOWN)){}
				         getmouseclick(WM_LBUTTONDOWN,x1,y1);
				          setfillstyle(SOLID_FILL,YELLOW);
                          floodfill(x1,y1,15);
				  
				   break;
			   }
			   if(x<119 && y>60 && y<90)
			   {
				 g=2;
				 f[1]->draw(g);
				 
			   }
			   if(x>119 && x<240 && y>60 && y<90)
			   {
				 g=2;
				 f[1]->draw(g);
				 
			   }
			   if(x>433 && x<500 && y<30)
			   {

				   cleardevice();
				   Interface();

			   }
			   if(x>434 && x<500  && y>30 && y<60)
				   exit(1);
				  
			  
		}
	}
	

	system("pause");
	return 0;
}
