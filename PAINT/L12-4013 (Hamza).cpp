#include<iostream>
#include "winbgim.h"
#include <math.h>
#include"graphics.h"
using namespace std;

struct cord
{
	int x;
	int y;
};

struct cord_node
{
	cord data;
	cord_node* next;
};

struct cord_list
{
	cord_node* head;
};

void GET_CLICK(int &x,int &y,cord_list &list,bool &flag,int &count)
{
	cord obj;
	cord_node *newcord,*curr;
	if(flag==false)
	{
		while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x,y);
		if(x>850 && x<1000 && y>400 && y<425)
			return;

		obj.x=x;
		obj.y=y;
		newcord=new cord_node;
		newcord->data=obj;
		newcord->next=NULL;
		if(list.head==NULL)
		{
			list.head=newcord;
		}
		else
		{
			curr=list.head;
			while(curr->next!=NULL)
				curr=curr->next;
			curr->next=newcord;
		}
	}
	else
	{
		curr=list.head;
		for(int i=0;i<count;i++)
		{
			if(curr->next->next==NULL)
			{
				curr->next=NULL;
				flag=false;
				return;
			}
			else
				curr=curr->next;
		}
		x=curr->data.x;
		y=curr->data.y;
		count++;
	}
}

void INTERFACE()
{
	rectangle(850,0,925,75);                //circle
	circle(887,37,28);

	rectangle(925,0,1000,75);                //triangle
	line(962,15,985,58);
	line(962,15,940,58);
	line(940,58,985,58);

	rectangle(850,75,925,150);              //rectangle
	rectangle(865,90,910,135);

	rectangle(925,75,1000,150);              //ellipse
	ellipse(962,112,0,360,27,19);

	rectangle(850,150,925,225);
	setfillstyle(SOLID_FILL,14);
	floodfill(887,187,15);

	rectangle(925,150,1000,225);
	setfillstyle(SOLID_FILL,3);
	floodfill(962,187,15);

	rectangle(850,225,925,300);
	setfillstyle(SOLID_FILL,4);
	floodfill(887,262,15);

	rectangle(925,225,1000,300);
	setfillstyle(SOLID_FILL,10);
	floodfill(962,262,15);

	rectangle(850,300,925,375);
	setfillstyle(SOLID_FILL,9);
	floodfill(887,337,15);

	rectangle(925,300,1000,375);
	setfillstyle(SOLID_FILL,5);
	floodfill(962,337,15);

	rectangle(850,375,1000,400);
	outtextxy(890,380,"New Paint");

	rectangle(850,400,1000,425);
	outtextxy(909,405,"Undo");

	rectangle(850,425,1000,450);
	outtextxy(882,430,"Rotate 90 Left");

	rectangle(850,450,1000,475);
	outtextxy(879,455,"Rotate 90 Right");

	rectangle(850,475,1000,500);
	outtextxy(891,480,"Rotate 180");
}

class shape
{
protected:
	int x1,y1,x2,y2;
public:
	virtual void setx1y1(int,int)=0;
	virtual void setx2y2(int,int)=0;
	virtual void setx3y3(int,int)=0;
	virtual void print()=0;
};

class Circle:public shape
{
	int radius;
public:
	void setx1y1(int a1,int b1)
	{
		x1=a1;
		y1=b1;
	}
	void setx2y2(int a2,int b2)
	{
		x2=a2;
		y2=b2;
	}
	void setx3y3(int a1,int b1)
	{
		cout<<"NO Use"<<endl;
	}
	void print()
	{
		int x=(x2-x1)*(x2-x1);
		int y=(y2-y1)*(y2-y1);
		float s=x+y;
		radius=sqrt(s);
		if( (850-x1)<radius)
			return;
		circle(x1,y1,radius);
	}
};

class triangle:public shape
{
	int x3,y3;
public:
	void setx1y1(int a1,int b1)
	{
		x1=a1;
		y1=b1;
	}
	void setx2y2(int a2,int b2)
	{
		x2=a2;
		y2=b2;
	}
	void setx3y3(int a3,int b3)
	{
		x3=a3;
		y3=b3;
	}
	void print()
	{
		line(x1,y1,x2,y2);
		line(x2,y2,x3,y3);
		line(x3,y3,x1,y1);
	}
};

class rect:public shape
{
public:
	void setx1y1(int a1,int b1)
	{
		x1=a1;
		y1=b1;
	}
	void setx2y2(int a2,int b2)
	{
		x2=a2;
		y2=b2;
	}
	void setx3y3(int a1,int b1)
	{
		cout<<"NO Use"<<endl;
	}
	void print()
	{
		if(x1<x2 && y1<y2)
			rectangle(x1,y1,x2,y2);
		if(x1<x2 && y1>y2)
			rectangle(x1,y2,x2,y1);
		if(x1>x2 && y1>y2)
			rectangle(x2,y2,x1,y1);
		if(x1>x2 && y1<y2)
			rectangle(x2,y1,x1,y2);
	}
};

class oval:public shape
{
	int x_radius,y_radius;
public:
	void setx1y1(int a1,int b1)
	{
		x1=a1;
		y1=b1;
	}
	void setx2y2(int a2,int b2)
	{
		x2=a2;
		y2=b2;
	}
	void setx3y3(int a1,int b1)
	{
		cout<<"NO Use"<<endl;
	}
	void print()
	{
		if(x1<x2)
			x_radius=x2-x1;
		else
			x_radius=x1-x2;
		if(y1<y2)
			y_radius=y2-y1;
		else
			y_radius=y1-y2;
		ellipse(x1,y1,0,720,x_radius,y_radius);
	}
};

void P_CIRCLE(shape* &ptr,cord_list &list,bool &flag,int &count)
{
	int x,y;
	ptr=new Circle;

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx1y1(x,y);

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx2y2(x,y);

	ptr->print();
}

void P_TRIANGLE(shape* &ptr,cord_list &list,bool &flag,int &count)
{
	int x,y;
	ptr=new triangle;

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx1y1(x,y);

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx2y2(x,y);
	GET_CLICK(x,y,list,flag,count);
	ptr->setx3y3(x,y);

	ptr->print();
}

void  P_RECTANGLE(shape* &ptr,cord_list &list,bool &flag,int &count)
{
	int x,y;
	ptr=new rect;

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx1y1(x,y);

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx2y2(x,y);

	ptr->print();
}

void P_OVAL(shape* &ptr,cord_list &list,bool &flag,int &count)
{
	int x,y;
	ptr=new oval;

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx1y1(x,y);

	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	ptr->setx2y2(x,y);

	ptr->print();
}

void FILL_COLOR(int color,cord_list &list,bool &flag,int &count)
{
	int x,y;
	GET_CLICK(x,y,list,flag,count);
	if(x>850)
		return;
	setfillstyle(SOLID_FILL,color);
	floodfill(x,y,15);
}

int main()
{
	int x=0,y=0,p_x,p_y,count=0;

	cord obj;
	cord_node *newcord=NULL,*curr=NULL;
	cord_list list;
	list.head=NULL;

	bool LINE=false,flag=false;

	initwindow(1000,690,"HaZa");
	INTERFACE();
	shape* ptr;
	while(1)
	{
		if(flag==true)
			cout<<true;
		GET_CLICK(x,y,list,flag,count);
	
		if(x>850 && x<1000 && y>375 && y<400)
		{
			cleardevice();
			list.head=NULL;
			INTERFACE();
		}
		if(x>850 && x<1000 && y>400 && y<425)
		{
			cleardevice();
			INTERFACE();
			if(list.head=NULL)
				continue;
			flag=true;
			count=0;
		}
		if(x<850)
		{
			if(LINE==true)
			{
				line(p_x,p_y,x,y);
				LINE=false;
			}
			else
			{
				putpixel(x,y,15);
				LINE=true;
			}
			p_x=x;p_y=y;
		}
		if(x>850 && x<925 && y>0 && y<75)
		{
			P_CIRCLE(ptr,list,flag,count);
			delete ptr;
		}

		if(x>925 && x<1000 && y>0 && y<75)
		{
			P_TRIANGLE(ptr,list,flag,count);
			delete ptr;
		}

		if(x>850 && x<925 && y>75 && y<150)
		{
			P_RECTANGLE(ptr,list,flag,count);
			delete ptr;
		}

		if(x>925 && x<1000 && y>75 && y<150)
		{
			P_OVAL(ptr,list,flag,count);
			delete ptr;
		}

		if(x>850 && x<925 && y>150 && y<225)
			FILL_COLOR(14,list,flag,count);

		if(x>925 && x<1000 && y>150 && y<225)
			FILL_COLOR(3,list,flag,count);

		if(x>850 && x<925 && y>225 && y<300)
			FILL_COLOR(4,list,flag,count);

		if(x>925 && x<1000 && y>225 && y<300)
			FILL_COLOR(10,list,flag,count);

		if(x>850 && x<925 && y>300 && y<375)
			FILL_COLOR(9,list,flag,count);

		if(x>925 && x<1000 && y>300 && y<375)
			FILL_COLOR(5,list,flag,count);
	}
	system("pause");
}