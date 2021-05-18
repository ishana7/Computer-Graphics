#include<iostream>
#include<graphics.h>
#include<math.h>
#include<stdlib.h>
using namespace std;

class animation
{
	public:
	void car();
};

void animation::car()
{
	cleardevice();
	int i,maxx,midy;
	maxx = getmaxx();
	midy = getmaxy()/2;
	setbkcolor(WHITE);
	
	for(i=0;i<maxx-150;i=i+3)
	{
		cleardevice();
		setcolor(BLACK);
		line(0,midy+37,maxx,midy+37);
		setcolor(RED);
		setlinestyle(SOLID_LINE,RED,1);
		line(i,midy+23,i,midy);
		line(i,midy,40+i,midy-20);
		line(40+i,midy-20,80+i,midy-20);
		line(80+i,midy-20,100+i,midy);
		line(100+i,midy,120+i,midy);
		line(120+i,midy,120+i,midy+23);
		line(0+i,midy+23,18+i,midy+23);
		arc(30+i,midy+23,0,180,12);
		line(42+i,midy+23,78+i,midy+23);
		arc(90+i,midy+23,0,180,12);
		line(102+i,midy+23,120+i,midy+23);
		line(28+i,midy,43+i,midy-15);
		line(43+i,midy-15,57+i,midy-15);
		line(57+i,midy-15,57+i,midy);
		line(57+i,midy,28+i,midy);
		line(62+i,midy-15,77+i,midy-15);
		line(77+i,midy-15,92+i,midy);
		line(92+i,midy,62+i,midy);
		line(62+i,midy,62+i,midy-15);
		
		floodfill(5+i,midy+22,RED);
		setcolor(DARKGRAY);
		setlinestyle(SOLID_LINE,DARKGRAY,1);
		
		circle(30+i,midy+25,12);
		circle(90+i,midy+25,12);
		floodfill(30+i,midy+25,DARKGRAY);
		floodfill(90+i,midy+25,DARKGRAY);
				
		delay(15);
	}
	getch();
}

int main()
{
	animation n;
	int gd = DETECT,gm;
	initgraph(&gd,&gm,NULL);
	n.car();
	closegraph();
	return 0;
}
