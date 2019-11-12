#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<time.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<graphics.h>
#include "FBLEAGUE\MOUSE.H"
#include "FBLEAGUE\INTRO.H"
#include "FBLEAGUE\CLDEFINE.H"
#include "FBLEAGUE\DBMENU.H"
#include "FBLEAGUE\FIXMENU.H"
#include "FBLEAGUE\PREDICT.H"

void main()
{
	 int a,b;
	 initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	 resetmouse();
	 a=10;
	 b=10;
	 setposi(a,b);
	 callmouse();
	 x=getmaxx()/2;
	 y=getmaxy()/2;
	 Intro();
	 setcolor(WHITE);
	 cleardevice();
	 while(1)
	 {
	  setcolor(GREEN);
	  outtextxy(x-34,y-158,"MAIN MENU");
	  setcolor(LIGHTCYAN);
	  rectangle(x-70,y-100,x+70,y-70);
	  outtextxy(x-50,y-88,"Fixtures Menu");
	  setcolor(WHITE);
	  rectangle(x-75,y-40,x+75,y-10);
	  outtextxy(x-58,y-28,"Match Predictor");
	  setcolor(YELLOW);
	  rectangle(x-75,y+20,x+75,y+50);
	  outtextxy(x-58,y+32,"Access Database");
	  setcolor(RED);
	  rectangle(x-65,y+80,x+65,y+110);
	  outtextxy(x-45,y+92,"Exit Program");
	   cl=0;
	   getposi(xp,yp,cl);
	    if((xp>x-70)&&(yp>y-100)&&(xp<x+70)&&(yp<y-70))
	     {
	      if(cl==1)
	      {
		setcolor(LIGHTCYAN);
		FixturesMenu();
		cleardevice();
	      }
	     }
	    else if((xp>x-75)&&(yp>y-40)&&(xp<x+75)&&(yp<y-10))
	     {
	      if(cl==1)
	      {
		closegraph();
		Predictor();
		initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
		resetmouse();
		callmouse();
		cleardevice();
	      }
	     }
	    else if((xp>x-75)&&(yp>y+20)&&(xp<x+75)&&(yp<y+50))
	     {
	      if(cl==1)
	      {
		setcolor(YELLOW);
		DBMenu();
		cleardevice();
	      }
	     }
	    if((xp>x-65)&&(yp>y+80)&&(xp<x+65)&&(yp<y+110))
	    {
	     if(cl==1)
	     {
	       closegraph();
	       exit(0);
	     }
	    }
	   }

}