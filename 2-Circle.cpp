#include<iostream>
#include<graphics.h>
using namespace std;

class circle_draw
{
			protected:
			int x,y,rad;
			public:
			circle_draw()
			{
				cout<<"\n Bresenham's circle generation algorithm : ";
				cout<<"\n\n\tEnter center co-ordinates for the circle : \n";
				cin>>x>>y;

				cout<<"\n Enter radius of the circle : \n";
				cin>>rad;

			}
};

class pixel:public circle_draw
{
	public:
	void circle_bresenham();
	void display_red(int,int,int,int);
};

void pixel::circle_bresenham()
{
    float dp;
    int x1,y1;
    x1 = 0;
    y1 = rad;
    dp = 3-2*rad;
    display_red(x1,y1,x,y);
    while(x1<=y1)
    {
        if(dp<=0)
            dp += (4*x1)+6;
        else
        {
            dp += 4*(x1-y1)+10;
            y1--;
        }
        x1++;
        display_red(x1,y1,x,y);
    }
}

void pixel::display_red(int x1,int y1,int x,int y)
{
    putpixel(x1+x,y1+y,13);
    putpixel(x1+x,y-y1,13);
    putpixel(x-x1,y1+y,13);
    putpixel(x-x1,y-y1,13);
    putpixel(y1+x,y+x1,13);
    putpixel(y1+x,y-x1,13);
    putpixel(x-y1,y+x1,13);
    putpixel(x-y1,y-x1,13);
    delay(150);
}

int main()
{   
	pixel p;
    
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    cleardevice();

    delay(2000);
    p.circle_bresenham();

    getch();
    closegraph();

    return 0;
}

