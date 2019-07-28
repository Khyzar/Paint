#include<iostream>
#include "winbgim.h"
#include <math.h>
#include"graphics.h"
#include <fstream>
using namespace std;
ofstream fout("save.txt");

class paint{
protected:
	int x,y,x1,y1,area;
public:
	paint(){
	}
	paint(int a,int b,int c,int d):x(a),y(b),x1(c),y1(d){}
	virtual void printshape(){}
	virtual void Area(){}
};
void fill_color(int c){
	int x,y;	
	while(!ismouseclick(WM_LBUTTONDOWN)){}
	getmouseclick(WM_LBUTTONDOWN,x,y);
	fout<<"color"<<" "<<x<<" "<<y<<" "<<c<<endl;
	if(y>40){
		setfillstyle(SOLID_FILL,c);
		floodfill(x,y,15);
	}
}
void initialize(){

	rectangle(0,0,40,40);
	circle(20,20,15);
	rectangle(45,0,85,40);
	rectangle(50,5,80,35);
	rectangle(90,0,130,40);
	ellipse(110,20,0,360,15,10);
	rectangle(135,0,175,40);
	line(155,5,141,35);
	line(141,35,169,35);
	line(169,35,155,5);
	rectangle(180,0,220,40);
	setfillstyle(SOLID_FILL,2);
	floodfill(190,15,15);
	rectangle(225,0,265,40);
	setfillstyle(SOLID_FILL,4);
	floodfill(235,10,15);
	rectangle(270,0,310,40);
	setfillstyle(SOLID_FILL,12);
	floodfill(290,10,15);
	rectangle(315,0,355,40);
	setfillstyle(SOLID_FILL,10);
	floodfill(320,20,15);
	rectangle(360,0,400,40);
	setfillstyle(SOLID_FILL,14);
	floodfill(375,20,15);
	rectangle(405,0,445,40);
	setfillstyle(SOLID_FILL,5);
	floodfill(420,20,15);
	rectangle(450,0,490,40);
	outtextxy(455,20,"EXIT");
	rectangle(495,0,540,40);
	outtextxy(497,5,"Rotate");
	outtextxy(500,20,"Right");
	rectangle(545,0,590,40);
	outtextxy(548,5,"Rotate");
	outtextxy(554,20,"Left");
	rectangle(595,0,645,40);
	outtextxy(605,20,"Undo");
	rectangle(650,0,690,40);
	outtextxy(655,10,"Save");
	rectangle(695,0,745,40);
	outtextxy(698,5,"Clear");
	outtextxy(698,20,"Screen");
	rectangle(750,0,800,40);
	outtextxy(760,10,"Load");
}
class circl:public paint{
private:
	int rad;
	float r;
public:
	circl(){}
	circl(int i, int j,int a,int b,float c):paint(i,j,a,b){
		r=c;
	}
	void Area(int a){
		area=3.14*(a*a);
	}

	void printshape(){

		while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x,y);
		while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		r=((x1-x)*(x1-x))+((y1-y)*(y1-y));
		rad=sqrt(r);
		Area(rad);
		fout<<"circle"<<" "<<x<<" "<<y<<" "<<rad<<endl;
		circle(x,y,rad);
	}
};
class rect:public paint{

public:
	rect(){}
	rect(int a,int b,int c, int d):paint(a,b,c,d){}
	void Area(int a,int b,int c,int d){
		area=(x1-x)*(y1-y);
	}
	void printshape(){
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN, x, y);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		fout<<"rect"<<" "<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
		rectangle(x,y,x1,y1);
	}
};
class elipse:public paint{

public:
	elipse(){}
	elipse(int a,int b,int c,int d):paint(a,b,c,d){}
	void printshape(){
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN,x,y);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		fout<<"elipse"<<" "<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
		ellipse( x, y,0,360,x1-x,y1-y );
	}
};
class triangle:public paint{
private:
	int x2,y2;
public:
	triangle(){}
	triangle(int a,int b,int c,int d,int e,int f):paint(a,b,c,d){
		x2=e;
		y2=f;
	}
	void Area(int a,int b,int c,int d,int e,int f){
		int x,y;
		x=(a+c)/2;
		y=(b+d)/2;
		area=(y-f)*(c-a)/2;
	}
	void printshape(){
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN,x,y);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN,x1,y1);
		while(!ismouseclick(WM_LBUTTONDOWN))
		{}
		getmouseclick(WM_LBUTTONDOWN,x2,y2);
		fout<<"triangle"<<" "<<x<<" "<<y<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
		line(x,y,x1,y1);
		line(x1,y1,x2,y2);
		line(x2,y2,x,y);
	}
};
int temp(){
	ifstream fin("save.txt");
	char fun[15],a[100];
	int i,x,y,x1,y1,x2,y2,c,r,count=0;
	for(i=0;!fin.eof();i++){
		fin.getline(a,100,'\n');
	}
	fin.close();
	fin.open("save.txt");
	while(!fin.eof()){
		fin>>fun;
		if(count<i-2){
		if(fun[0]=='p'){
			fin>>x;
			fin>>y;
			putpixel(x,y,0);
		}
		if(fun[0]=='l'){
			fin>>x;
			fin>>y;
			fin>>x1;
			fin>>y1;
			line(x,y,x1,y1);
		}
		if(fun[0]=='c'&&fun[1]=='o'){
			fin>>x;
			fin>>y;
			fin>>c;
			setfillstyle(SOLID_FILL,c);
			floodfill(x,y,15);
		}
		if(fun[0]=='t'){
			fin>>x;
			fin>>y;
			fin>>x1;
			fin>>y1;
			fin>>x2;
			fin>>y2;
			line(x,y,x1,y1);
			line(x1,y1,x2,y2);
			line(x2,y2,x,y);
		}
		if(fun[0]=='e'){
			fin>>x;
			fin>>y;
			fin>>x1;
			fin>>y1;
			ellipse( x, y,0,360,x1-x,y1-y );
		}
		if(fun[0]=='r'){
			fin>>x;
			fin>>y;
			fin>>x1;
			fin>>y1;
			rectangle(x,y,x1,y1);
		}
		if(fun[0]=='c'&& fun[1]=='i'){
			fin>>x;
			fin>>y;
			fin>>r;
			circle(x,y,r);
		}
		count++;
	}
		else 
			break;

	}
	fin.close();
	return count;
}
int main()
{
	initwindow(800,900);
	paint *obj;
	int x1,y1,x,y,x2,y2;
	initialize();

	while(1){

		while(!ismouseclick(WM_LBUTTONDOWN)){}
		getmouseclick(WM_LBUTTONDOWN,x,y);
		if(y>40)
			fout<<"point"<<" "<<x<<" "<<y<<endl;
		if(y>40){
			putpixel(x,y,15);
			while(!ismouseclick(WM_LBUTTONDOWN)){}
			getmouseclick(WM_LBUTTONDOWN,x1,y1);
			fout<<"point"<<" "<<x1<<" "<<y1<<endl;
			if(y1>40){
				line(x,y,x1,y1);
				fout<<"line"<<" "<<x<<" "<<y<<" "<<x1<<" "<<y1<<endl;
			}
			else
			{
				x=x1;
				y=y1;
			}
		}
		if(x>=0&&x<=40 && y>=0 && y<=40){
			obj=new circl;
			obj->printshape();
		}
		if(x>=45&&x<=85 && y>=0 && y<=40){
			obj=new rect;
			obj->printshape();
		}


		if(x>=90&&x<=130 && y>=0 && y<=40){
			obj=new elipse;
			obj->printshape();
		}		

		if(x>=135&&x<=175 && y>=0 && y<=40){
			obj=new triangle;
			obj->printshape();
		}
		if(x>=180&&x<=220 && y>=0 && y<=40){
			fill_color(2);
		}
		if(x>=225&&x<=265 && y>=0 && y<=40){
			fill_color(4);
		}
		if(x>=270&&x<=310 && y>=0 && y<=40){
			fill_color(12);
		}
		if(x>=315&&x<=355 && y>=0 && y<=40){
			fill_color(10);
		}
		if(x>=360&&x<=400 && y>=0 && y<=40){
			fill_color(14);
		}
		if(x>=405&&x<=445 && y>=0 && y<=40){
			fill_color(5);
		}
		if(x>=450&&x<=490 && y>=0 && y<=40){
			exit(0);
		}
		if(x>=695&&x<=745 && y>=0 && y<=40){
			cleardevice();
			initialize();
			fout.close();
			fout.open("save.txt");
		}
		if(x>=650&&x<=690 && y>=0 && y<=40){
			writeimagefile("save",0,0,800,900);
		}
		if(x>=750&&x<=800 && y>=0 && y<=40){
			readimagefile("save",0,0,800,900);	
		}
		if(x>=495&&x<=545 && y>=0 && y<=40){
			int a;
			char p[100];
			ifstream fin("save.txt");
			cleardevice();
			initialize();
			a=temp();
			for(int i=0;i<a;i++){
				fin.getline(p,99,'\n');
			}
			fin>>p;
			if(p[0]=='t'){
				fin>>x;
				fin>>y;
				fin>>x1;
				fin>>y1;
				fin>>x2;
				fin>>y2;
				line(x+(x1-x)+(y1-y),y-(x1-x),x1,y1);
		        line(x1,y1,(x1-x)+(y1-y)+x,x2-(x1-x2)+(y2-y));
		        line((x1-x)+(y1-y)+x,x2-(x1-x2)+(y2-y),x+(x1-x)+(y1-y),y-(x1-x));
			}
			if(p[0]=='r'){
				int a;
				fin>>x;
				fin>>y;
				fin>>x1;
				fin>>y1;
				a=x;
				x=x+(y1-y)+(x1-x);
				y=y+(y1-y)-(x1-a);
				rectangle(x,y,x1,y1);
			}
			if(p[0]=='l'){
				fin>>x;
				fin>>y;
				fin>>x1;
				fin>>y1;
				line(x+(x1-x)+(y1-y),y1-(x1-x),x1,y1);
			}
		}  
		
		if(x>=595&&x<=645 && y>=0 && y<=40){
			cleardevice();
			initialize();
			temp();
		}
	}

	system("pause");
}
