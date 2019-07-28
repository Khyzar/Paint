#include"graphics.h"

#include<iostream>

using namespace std;

void paint_interface()
{
	int poly[8]={28,50,44,78,15,78,28,50};
	initwindow(600,600,"PAINT");
 //........... 
	line(10,5,90,5); 
	line(10,85,90,85);

	line(50,5,50,85);

	line(10,5,10,85);
	line(90,5,90,85);

	line(10,45,90,45);

	circle(30,24,15);

	rectangle(100,5,140,45);
	rectangle(56,9,84,37);

	drawpoly(4,poly);
	ellipse(71,67,0,360,13,18);

	//................
	line(100,5,180,5); 
	line(100,85,180,85);

	line(140,5,140,85);

	line(100,5,100,85);
	line(180,5,180,85);

	line(100,45,180,45);

	setfillstyle(SOLID_FILL,1);
	floodfill(120,25,15);
	setfillstyle(SOLID_FILL,4);
	floodfill(160,25,15);
	setfillstyle(SOLID_FILL,3);
	floodfill(118,67,15);
	setfillstyle(SOLID_FILL,2);
	floodfill(162,65,15);
//................
	line(180,5,260,5); 
	line(180,85,260,85);

	line(220,5,220,85);

	line(180,5,180,85);
	line(260,5,260,85);

	line(180,45,260,45);

	setfillstyle(SOLID_FILL,5);
	floodfill(204,27,15);
	setfillstyle(SOLID_FILL,14);
	floodfill(254,20,15);
	setfillstyle(SOLID_FILL,11);
	floodfill(209,63,15);
	setfillstyle(SOLID_FILL,6);
	floodfill(247,69,15);

//...............
	int x_1,y_1;
	  
	line(270,5,350,5); 
	line(270,85,350,85);
	//first half
	line(270,25,350,25);
    //second half
	line(270,65,350,65); 
	//middle half
	line(270,45,350,45);

	line(270,5,270,85);
	line(350,5,350,85);


	outtextxy(293,7,"Save");
	outtextxy(293,28,"Load");
	outtextxy(293,49,"Clear");
	outtextxy(293,68,"Undo");
	
//..................
	line(370,5,450,5); 
	line(370,85,450,85);

	//setlinestyle(1,3,2);
	
	//first half
	//line(370,25,450,25);
	//middle half 
	line(370,45,450,45);
	line(410,5,410,45);
	//second half 
	//line(370,65,450,65);

	line(370,5,370,85);
	line(450,5,450,85);
	outtextxy(375,19,"90 R");
	outtextxy(416,19,"90 L");
	outtextxy(373,60,"180 Degree");

	line(551,2,551,45);
	line(551,45,597,45);
	line(597,2,551,2);
	line(597,2,597,45);
	
	/*line(552,45,597,2);
	line(597,45,551,2);*/

	
	outtextxy(564,15,"Exit");
	settextstyle(3,2,1);
	outtextxy(28,92,"Shapes");
	outtextxy(160,92,"Colors");
	outtextxy(296,92,"File");
	outtextxy(382,92,"Rotation");
	line(0,120,600,120);
	line(0,122,600,122);
	/*while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_1, y_1);
	cout<<x_1<<"  "<<y_1;*/

}

	class paint{
	protected:
		int x_1,y_1,x_2,y_2;
	public:
		paint()
		{
		x_1=y_1=x_2=y_2=0;
		}
		virtual void input()=0;
	    virtual void draw_figure()=0;
	
	};

	class Circle:public paint{
	public:
		void input()
		{  bool true_false=false;
			 do{
			                     							
		 while(!ismouseclick(WM_LBUTTONDOWN));
       	 getmouseclick(WM_LBUTTONDOWN, x_1, y_1);
		 if((x_1<600&&x_1>=0)&&(y_1<120&&y_1>=0))
           true_false=false; 
		 else 
		   true_false=true;
         }while(true_false==false);
		 putpixel(x_1,y_1,15);

		 do{
		 while(!ismouseclick(WM_LBUTTONDOWN));
     	 getmouseclick(WM_LBUTTONDOWN, x_2, y_2);
		 if((x_2<600&&x_2>=0)&&(y_2<120&&y_2>=0))
           true_false=false; 
		 else 
		   true_false=true;
		 }while(true_false==false);
		 putpixel(x_2,y_2,15);
		}
	
	  void draw_figure()
	   {   int radius=0;
		   radius=pow((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2),.5);
	       circle(x_1,y_1,radius);
	   }
	
	};
	class ELLIPSE:public paint{
	public:
    void input()
		{   bool true_false=false;
			do{
		 while(!ismouseclick(WM_LBUTTONDOWN));
       	 getmouseclick(WM_LBUTTONDOWN, x_1, y_1);
		 if((x_1<600&&x_1>=0)&&(y_1<120&&y_1>=0))
                  true_false=false; 
		        else 
		          true_false=true;
			}while(true_false==false);
		 putpixel(x_1,y_1,15);
		

		 do{
		 while(!ismouseclick(WM_LBUTTONDOWN));
     	 getmouseclick(WM_LBUTTONDOWN, x_2, y_2);
		 if((x_2<600&&x_2>=0)&&(y_2<120&&y_2>=0))
                  true_false=false; 
		        else 
		          true_false=true;
		 }while(true_false==false);
		 
		 putpixel(x_2,y_2,15);
		}
	
	  void draw_figure()
	   {   int x_radius=0,y_radius=0;
		   if(x_1>x_2)
	        x_radius=x_1-x_2;
		   else 
            x_radius=x_2-x_1;
		   if(y_1>y_2)
			   y_radius=y_1-y_2;
		   else 
			   y_radius=y_2-y_1;

	        ellipse(x_1,y_1,0,360,x_radius,y_radius);  
	   }
	
	};
	class RECTANGLE:public paint{
	public:
		void input()
		{
		 while(!ismouseclick(WM_LBUTTONDOWN));
       	 getmouseclick(WM_LBUTTONDOWN, x_1, y_1);
		 cout<<x_1<<"  "<<y_1<<endl;
		 putpixel(x_1,y_1,15);
		 while(!ismouseclick(WM_LBUTTONDOWN));
     	 getmouseclick(WM_LBUTTONDOWN, x_2, y_2);
		 cout<<x_2<<"  "<<y_2<<endl;
		 putpixel(x_2,y_2,15);
		}
	
	  void draw_figure()
	   {   
		   if(x_1<x_2 &&y_1<y_2)
	       rectangle(x_1,y_1,x_2,y_2);
		   else if(x_2<x_1&&y_2>y_1)
			     rectangle(x_2,y_1,x_1,y_2);
	 	        else if(x_2<x_1 && y_1>y_2)
					  rectangle(x_2,y_2,x_1,y_1);
		             else if(x_1<x_2 && y_1>y_2)
						   rectangle(x_1,y_2,x_2,y_1);
				
				
				/*line(y_1,x_2,y_2,x_2);
				line(y_2,x_2,y_2,x_1);
				line(y_2,x_1,y_1,x_1);
				line(y_1,x_1,y_1,x_2);*/
				//swap(x_1,y_1);
				//swap(x_2,y_2);
				////cout<<(x_1+x_2)/2<<"       "<<(y_1+y_2)/2;
				// moveto((y_1+y_2)/2,(x_1+x_2)/2);
				rectangle(y_2,x_1,y_1,x_2);
	              
	  }

	
	};
	class TRIANGLE:public paint{
	private:
		int x_3,y_3;
	public:
		void input()
		{ bool true_false=false;
			do{
		 while(!ismouseclick(WM_LBUTTONDOWN));
       	 getmouseclick(WM_LBUTTONDOWN, x_1, y_1);
		   if((x_1<600&&x_1>=0)&&(y_1<120&&y_1>=0))
                  true_false=false; 
		        else 
		          true_false=true;
		    
			}while(true_false==false);
		    
			putpixel(x_1,y_1,15);

			do{
		 while(!ismouseclick(WM_LBUTTONDOWN));
     	 getmouseclick(WM_LBUTTONDOWN, x_2, y_2);
		        if((x_2<600&&x_2>=0)&&(y_2<120&&y_2>=0))
                  true_false=false; 
		        else 
		          true_false=true;
			}while(true_false==false);
		 putpixel(x_2,y_2,15);
		
			do{
		 while(!ismouseclick(WM_LBUTTONDOWN));
     	 getmouseclick(WM_LBUTTONDOWN, x_3, y_3);
		    if((x_3<600&&x_3>=0)&&(y_3<120&&y_3>=0))
                  true_false=false; 
		        else 
		          true_false=true;
			}while(true_false==false);
		 putpixel(x_2,y_2,15);
		}
		void draw_figure()
	   {  
		   int	poly[8];
			poly[0]=x_1;
			poly[1]=y_1;
			poly[2]=x_2;
			poly[3]=y_2;
			poly[4]=x_3;
			poly[5]=y_3;
			poly[6]=x_1;
			poly[7]=y_1;
	       drawpoly(4,poly);
	   }

	};
int main()
{

	
	//paint_interface();	
	

	int x=0,y=0,x_=0,y_=0;
	bool true_false=true;
	paint_interface();
	moveto(525,100);
	//cout<<ismouseclick(WM_MOUSEMOVE);
	if(true)
	//setbkcolor(3);

	while(true){
		
		do{
	while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x, y);
	cout<<x<<"  "<<y<<endl;
	 if((x>10&&x<50)&&(y>4&&y<45)||(x>50&&x<90)&&(y>4&&y<45)||(x>10&&x<50)&&(y>45&&y<85)||(x>50&&x<90)&&(y>45&&y<85)||(x>100&&x<140)&&(y>4&&y<45)||(x>140&&x<180)&&(y>4&&y<45)||(x>180&&x<220)&&(y>4&&y<45)||(x>220&&x<260)&&(y>4&&y<45)||(x>100&&x<140)&&(y>45&&y<85)||(x>140&&x<180)&&(y>45&&y<85)||(x>180&&x<220)&&(y>45&&y<85)||(x>220&&x<260)&&(y>45&&y<85)||(x>551&&x<597)&&(y<45&&y>2))
	  true_false=true;
    else if((x<600&&x>=0)&&(y<120&&y>=0))
	      true_false=false; 
	     else if((y>=120))
			   true_false=true;
 		}while(true_false==false);

	if((y>=120))
		putpixel(x,y,15);

	if((x>10&&x<50)&&(y>4&&y<45))
	{
	Circle object_1_c;
	paint *obj=&object_1_c;
	obj->input();
	obj->draw_figure();
	 }
	else if((x>50&&x<90)&&(y>4&&y<45))
	      {
			  RECTANGLE object_1_r;
	          paint *obj=&object_1_r;
			  obj->input();
	          obj->draw_figure();
	      }
	     else if((x>10&&x<50)&&(y>45&&y<85))
	          {
	           TRIANGLE object_1_t;
		       paint *obj=&object_1_t;
			   obj->input();
	           obj->draw_figure();
	          }
		     else if((x>50&&x<90)&&(y>45&&y<85))
			       {
		             ELLIPSE object_1_e;
	                 paint *obj=&object_1_e;
			         obj->input();
	                 obj->draw_figure();
		           }
			 else if((x>100&&x<140)&&(y>4&&y<45))
			       {
					while(!ismouseclick(WM_LBUTTONDOWN));
	                getmouseclick(WM_LBUTTONDOWN, x_, y_);
					  if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						continue;
					setfillstyle(SOLID_FILL,1);
	                  floodfill(x_,y_,15);
			       }
			      else if((x>140&&x<180)&&(y>4&&y<45))
				        { while(!ismouseclick(WM_LBUTTONDOWN));
	                      getmouseclick(WM_LBUTTONDOWN, x_, y_);
					       if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						        continue;
						  setfillstyle(SOLID_FILL,4);
	                      floodfill(x_,y_,15);
			             }
				        else if((x>180&&x<220)&&(y>4&&y<45))
						       {
				                  while(!ismouseclick(WM_LBUTTONDOWN));
	                              getmouseclick(WM_LBUTTONDOWN, x_, y_);
								  if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						               continue;
					              setfillstyle(SOLID_FILL,5);
	                              floodfill(x_,y_,15);
				               }
				              else if((x>220&&x<260)&&(y>4&&y<45))
						            { while(!ismouseclick(WM_LBUTTONDOWN));
	                                  getmouseclick(WM_LBUTTONDOWN, x_, y_);
									   if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						                  continue;
					                  setfillstyle(SOLID_FILL,14);
	                                  floodfill(x_,y_,15);
				  
				                     }
						           else if((x>100&&x<140)&&(y>45&&y<85))
						                  {
				                            while(!ismouseclick(WM_LBUTTONDOWN));
	                                        getmouseclick(WM_LBUTTONDOWN, x_, y_);
											  if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						                           continue;
					                        setfillstyle(SOLID_FILL,3);
	                                        floodfill(x_,y_,15);
				                           }
							             else if((x>140&&x<180)&&(y>45&&y<85))
						                       { while(!ismouseclick(WM_LBUTTONDOWN));
	                                             getmouseclick(WM_LBUTTONDOWN, x_, y_);
												 if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						                               continue;
					                             setfillstyle(SOLID_FILL,2);
	                                             floodfill(x_,y_,15);
				  
				                               }       
							                   else if((x>180&&x<220)&&(y>45&&y<85))
						                              {  while(!ismouseclick(WM_LBUTTONDOWN));
	                                                     getmouseclick(WM_LBUTTONDOWN, x_, y_);
														 if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						                                            continue;
					                                     setfillstyle(SOLID_FILL,11);
	                                                     floodfill(x_,y_,15);
				  
				                                       }  
										             else if((x>220&&x<260)&&(y>45&&y<85))
						                              {   while(!ismouseclick(WM_LBUTTONDOWN));
	                                                      getmouseclick(WM_LBUTTONDOWN, x_, y_);
														  if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
						                                            continue;
					                                      setfillstyle(SOLID_FILL,6);
	                                                      floodfill(x_,y_,15);
				  
				                                       }
													    else if((x>551&&x<597)&&(y<45&&y>2))
														      { 
																  setfillstyle(XHATCH_FILL,2);
																  floodfill(x,y,15);
																  delay(250);
																  exit(0);
													          }
			                                            
														
														else {

														   do{
			                                                while(!ismouseclick(WM_LBUTTONDOWN));
	                                                        getmouseclick(WM_LBUTTONDOWN, x_, y_);
	                                                        cout<<x_<<"  "<<y_<<endl;
															if((x_<600&&x_>=0)&&(y_<120&&y_>=0))
																true_false=false;
															else 
																true_false=true;
														     }while(true_false==false);
					                                        putpixel(x_,y_,15);
					                                        line(x,y,x_,y_);
			                                                }




													  /* int column,row,x_1,y_1,x_2,y_2,x_3,y_3,x_4,y_4;
	while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_1, y_1);
	cout<<x_1<<"  "<<y_1<<endl;
	while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_2, y_2);
	cout<<x_2<<"  "<<y_2<<endl;
	while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_3, y_3);
	cout<<x_3<<"  "<<y_3<<endl;
	while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_4, y_4);
	cout<<x_4<<"  "<<y_4<<endl;
*/
   }
	//cleardevice();
	
	

	/*line(120,5,220,5);
	line(120,80,220,70);*/
	 // line(55,100,100,55);
	  
	  /*line(50,50,50,5);
	  line(50,5,5,5);
	  line(5,5,5,50);*/

	  //line(5,100,5,100);

	//rectangle(0,200,200,0);
	//rectangle(5,50,50,5);

	//rectangle(10,50,50,10);

	//line(1,15,900,15);
	//line(10,20,120,20);
	//line(10,120,120,120);

	/*while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_1, y_1);
	 
	while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_2, y_2);

	 while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_3, y_3);

	  while(!ismouseclick(WM_LBUTTONDOWN));
	getmouseclick(WM_LBUTTONDOWN, x_4, y_4);

	 line(x_1,y_1,x_2,y_2);
	 line(x_2,y_2,x_3,y_3);
	 line(x_3,y_3,x_4,y_4);
	  line(x_4,y_4,x_1,y_1);
	*/

	//rectangle(1,200,597,20);
	//rectangle(20,100,100,30);
	//rectangle(420,300,300,30);
	//rectangle(10,100,100,60);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//	
//	int column,row,x_1,y_1,x_2,y_2,x_3,y_3;
//int poly[8]={1,1,41,1,41,41,1,41};
//	initwindow(600,600,"Paint");
//	//outtextxy(0, 0, "Left click in to end.");
//	
//	 
//	int poly_1[8]={10,1,20,20,1,20,10,1};
//	
//	/*while(!ismouseclick(WM_LBUTTONDOWN));
//	getmouseclick(WM_LBUTTONDOWN, y_1, x_1);
//	 
//	while(!ismouseclick(WM_LBUTTONDOWN));
//	getmouseclick(WM_LBUTTONDOWN, y_2, x_2);
//
//	 while(!ismouseclick(WM_LBUTTONDOWN));
//	getmouseclick(WM_LBUTTONDOWN, y_3, x_3);
//	
//	
//	int poly_1[8]={y_1,x_1,y_2,x_2,y_3,x_3,y_1,x_1};
//	
//	 drawpoly(4,poly_1);
//	 system("pause");*/
//
//    //setcolor(GREEN);
//	setfillstyle(SOLID_FILL, 6);
//	rectangle(1,1,41,41);//left,top,right,bottom
//	floodfill(2,5,15);
//	system("pause");
//	//circle(21, 21, 21);
//	//cout<<getmaxcolor()-1;
	//for (int i=EMPTY_FILL; i<USER_FILL; i++) {

 //     /* set fill pattern */

 //     setfillstyle(i, 6);


	//  rectangle(1,1,41,41);//left,top,right,bottom
 //     /* draw a filled polygon */

 //     fillpoly(4, poly);
	//  delay(100);
	//}
//	//fillpoly(4,poly);
//	//floodfill(2, 2, 15);
//	while(!ismouseclick(WM_LBUTTONDOWN));
//	getmouseclick(WM_LBUTTONDOWN, column, row);
//	 cout<<column<<"   "<<row;
	
	
	system("pause");
}
