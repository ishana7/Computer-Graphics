#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

void draw(int lev,int x1,int y1,int x5,int y5)
{
	int dx,dy,x2,y2,x3,y3,x4,y4;
	if(lev==0)
	{
		setcolor(3);
		line(x1,y1,x5,y5);
	}
	else
	{
		dx=x5-x1;
		dy=y5-y1;
		x2=x1+dx/3;
		y2=y1+dy/3;
		x3=(int)(0.5*(x5+x1)+sqrt(3)*(y1-y5)/6);
		y3=(int)(0.5*(y5+y1)+sqrt(3)*(x5-x1)/6);
		x4=x1+(2*dx/3);
		y4=y1+(2*dy/3);
		
		draw(lev-1,x1,y1,x2,y2);
		draw(lev-1,x2,y2,x3,y3);
		draw(lev-1,x3,y3,x4,y4);
		draw(lev-1,x4,y4,x5,y5);
	}
}

int main()
{
	int lev;
	int gd = DETECT, gm;
	cout<<"\nEnter the level of Koch Curve formation (0 and above) : ";
	cin>>lev;
	
	initgraph(&gd,&gm,NULL);
	draw(lev,400,300,50,300);
	getch();
	closegraph();
	return 0;
}
