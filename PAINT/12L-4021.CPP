//PaintApp 12L-4021
#include <iostream>
#include "winbgim.h"
#include <math.h>
void MENU(){
	setfillstyle(1,BLACK);
	floodfill(0,0,BLUE);
	setcolor(BLUE);
	line(0,40,1000,40);
	line(1000,0,1000,600);
	line(1100,0,1100,600);
	line(1200,0,1200,600);
	line(1000,100,1300,100);
	line(1000,200,1300,200);
	line(1000,300,1300,300);
	line(1000,400,1300,400);
	line(1000,500,1300,500);
	setcolor(YELLOW);
	outtextxy(470,0,"PaintApp 12L-4021");
	outtextxy(50,20,"To fill color in a shape, Left Click on Fill Color, Left Click on the desired Color, Then Right Click in the shape in which you want to color");
	outtextxy(1050,50,"Line");
	outtextxy(1150,50,"Circle");
	outtextxy(1250,50,"Tri");
	outtextxy(1050,150,"Oval");
	outtextxy(1150,150,"Rect");
	outtextxy(1250,150,"Clear");
	outtextxy(1030,450,"FillColor");
	outtextxy(1150,450,"Save");
	outtextxy(1250,450,"Load");
	outtextxy(1030,550,"Rotate");
	outtextxy(1140,550,"Quit");
	setfillstyle(1,YELLOW);
	floodfill(1050,250,BLUE);
	setfillstyle(1,CYAN);
	floodfill(1150,250,BLUE);
	setfillstyle(1,BLUE);
	floodfill(1250,250,BLUE);
	setfillstyle(1,LIGHTMAGENTA);
	floodfill(1050,350,BLUE);
	setfillstyle(1,GREEN);
	floodfill(1150,350,BLUE);
	setfillstyle(1,GREEN);
	floodfill(1150,350,BLUE);
	setfillstyle(1,LIGHTGREEN);
	floodfill(1250,350,BLUE);
}
void CLS(){
	cleardevice();
	MENU();
}
class Shape{
public:
	virtual void draw(){};
	virtual float CalArea(){return 0;};
};
class Line: public Shape{
	
private:
	int xcoord[2];
	int ycoord[2];
public:
	Line(){
		for(int i=0; i<2; i++){
			xcoord[i]=0;
			ycoord[i]=0;}
	}
	void draw(){
		setbkcolor(15);
		int index=0;
			while(index<2){
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, xcoord[index],ycoord[index]);
				putpixel(xcoord[index],ycoord[index],15);
				clearmouseclick(WM_LBUTTONDOWN); 
				index++;
			}}
			setcolor(BLUE);
			line(xcoord[0], ycoord[0], xcoord[1], ycoord[1]);
	}
};
class Circle:public Shape{
	
private:
	int xcoord[2];
	int ycoord[2];
	float rad;
	float area;
	int color;
public:
	
	Circle(){
		for(int i=0; i<2; i++){
			xcoord[i]=0;
			ycoord[i]=0;
		}
		rad=0;
		area=0;}
	float CalArea(){
		area=3.14*rad*rad;
		return area;
	}
	void draw(){
		int index=0;
			while(index<2){
			if(ismouseclick(WM_LBUTTONDOWN)){
				getmouseclick(WM_LBUTTONDOWN, xcoord[index],ycoord[index]);
		clearmouseclick(WM_LBUTTONDOWN); 
		index++;
			}}
	rad=((xcoord[1]-xcoord[0])*((xcoord[1]-xcoord[0]))+((ycoord[1]-ycoord[0])*((ycoord[1]-ycoord[0]))));
	rad=sqrt(rad);
	setcolor(BLUE);
	
	if((xcoord[0]<=xcoord[1])&&(ycoord[0]<=ycoord[1])){
		circle(xcoord[0],ycoord[0],rad);}
	else if((xcoord[0]<=xcoord[1])&&(ycoord[0]>ycoord[1])){
		circle(xcoord[0],ycoord[1],rad);}
	else if((xcoord[0]>=xcoord[1])&&(ycoord[0]<ycoord[1])){
		circle(xcoord[1],ycoord[0],rad);}
	else if((xcoord[0]>=xcoord[1])&&(ycoord[0]>ycoord[1])){
		circle(xcoord[1],ycoord[1],rad);}

	}
};
class Rect: public Shape{
	int xcoord[2];
	int ycoord[2];
public:
	Rect(){}
	void draw(){
		
		int index=0;
			
		while(index<2){
			
			if(ismouseclick(WM_LBUTTONDOWN)){
				
				getmouseclick(WM_LBUTTONDOWN, xcoord[index],ycoord[index]);
		
				clearmouseclick(WM_LBUTTONDOWN); 
		
				index++;
			}
		}
		setcolor(BLUE);
		rectangle(xcoord[0],ycoord[0],xcoord[1],ycoord[1]);
	}
	float CalArea(){
		float width=xcoord[1]-xcoord[0];
		float length=ycoord[1]-ycoord[0];
		float area= width*length;
		return area;
	}
};
class Tri: public Shape{
	int xcoord[3];
	int ycoord[4];
public:
	Tri(){}
	void draw(){
		int index=0;
			
		while(index<3){
			
			if(ismouseclick(WM_LBUTTONDOWN)){
				
				getmouseclick(WM_LBUTTONDOWN, xcoord[index],ycoord[index]);
		
				clearmouseclick(WM_LBUTTONDOWN); 
		
				index++;
			}
		}
		setcolor(BLUE);
		line(xcoord[0],ycoord[0],xcoord[1],ycoord[1]);
		line(xcoord[1],ycoord[1],xcoord[2],ycoord[2]);
		line(xcoord[2],ycoord[2],xcoord[0],ycoord[0]);
	}

};
class Oval: public Shape{
	int xcoord[2];
	int ycoord[2];
	int xradius;
	int yradius;
public:
	Oval(){}
	void draw(){
			int index=0;
			
			while(index<2){
			
				if(ismouseclick(WM_LBUTTONDOWN)){
				
					getmouseclick(WM_LBUTTONDOWN, xcoord[index],ycoord[index]);
		
					clearmouseclick(WM_LBUTTONDOWN); 
		
					index++;
			
				}
			}

			setcolor(BLUE);
			xradius=xcoord[1]-xcoord[0];
			yradius=ycoord[1]-ycoord[0];
			ellipse(xcoord[0],ycoord[0],0,1080,xradius,yradius);
	}
};
void Save(){
	writeimagefile(NULL,0,0,1300,600);
}

void Load(){
	readimagefile(NULL,0,0,1300,600);
}

void FillColor(){
	int x=0;
	int y=0;
	int x1=0; 
	int y1=0;
	int color=0;

	while(!ismouseclick(WM_LBUTTONDOWN)){}
	getmouseclick(WM_LBUTTONDOWN,x,y);
	
	while(!ismouseclick(WM_RBUTTONDOWN)){}
	getmouseclick(WM_RBUTTONDOWN,x1,y1);
	
	if(x>1000&&x<1100&&y>200&&y<300){
		color=YELLOW;
		setfillstyle(1,color);
		floodfill(x1,y1,BLUE);
	}
	if(x>1100&&x<1200&&y>200&&y<300){
		color=CYAN;
		setfillstyle(1,color);
		floodfill(x1,y1,BLUE);
	}
	if(x>1200&&x<1300&&y>200&&y<300){
		color=BLUE;
		setfillstyle(1,color);
		floodfill(x1,y1,BLUE);
	}
	if(x>1000&&x<1100&&y>300&&y<400){
		color=LIGHTMAGENTA;
		setfillstyle(1,color);
		floodfill(x1,y1,BLUE);
	}
	if(x>1100&&x<1200&&y>300&&y<400){
		color=GREEN;
		setfillstyle(1,color);
		floodfill(x1,y1,BLUE);
	}
	if(x>1200&&x<1300&&y>300&&y<400){
		color=LIGHTGREEN;
		setfillstyle(1,color);
		floodfill(x1,y1,BLUE);
	}
}
int main(){
	initwindow(1300,600,"PAINTAPP 12L-4021");
	int xcoord=0;
	int ycoord=0;
	Shape *s=NULL;
	MENU();
	while(1){
	begin:
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN,xcoord,ycoord);
		}
		else
			goto begin;
		clearmouseclick(WM_LBUTTONDOWN);
		clearmouseclick(WM_RBUTTONDOWN);

		if(xcoord<1000){
			putpixel(xcoord,ycoord,WHITE);
			clearmouseclick(WM_LBUTTONDOWN);
			clearmouseclick(WM_RBUTTONDOWN);
		}
		//1st Column of Menu:
		if(xcoord>1000&&xcoord<1100){
			if(ycoord>0&&ycoord<100){
				s=new Line();
				s->draw();
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
			if(ycoord>100&&ycoord<200){
				s=new Oval();
				s->draw();
				
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
			if(ycoord>400&&ycoord<500){
				FillColor();
				
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
		}
		//2nd Column of Menu:
		if(xcoord>1100&&xcoord<1200){
			if(ycoord>0&&ycoord<100){
				s=new Circle();
				s->draw();
				
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
			if(ycoord>100&&ycoord<200){
				s=new Rect();
				s->draw();
				
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
			if(ycoord>400&&ycoord<500){
				Save();
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
			if(ycoord>500&&ycoord<600){
				break;
			}
		}
		//3rd Column of Menu:
		if(xcoord>1200&&xcoord<1300){
			if(ycoord>0&&ycoord<100){
				s=new Tri();
				s->draw();
				
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
			if(ycoord>100&&ycoord<200){
				CLS();
				
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
			if(ycoord>400&&ycoord<500){
				Load();
				clearmouseclick(WM_LBUTTONDOWN);
				clearmouseclick(WM_RBUTTONDOWN);
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
		clearmouseclick(WM_RBUTTONDOWN);
		delete s;
		s=NULL;

	}
	return 0;
}