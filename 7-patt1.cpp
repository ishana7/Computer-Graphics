#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class geometry
{
	public:
		void line_bresenham(int,int,int,int);
		int sign(float);
		void circle_bresenham(int,int,int);
		void display_red(int,int,int,int);
		void draw(int,int,int,int);
};

void geometry::line_bresenham(int x1,int y1,int x2,int y2)
{
    int s1,s2,exchange,x,y,i;
    float dx,dy,g,temp;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = x1;
    y = y1;
    s1 = sign(x2-x1);
    s2 = sign(y2-y1);
    if(dy>dx)                                                       
    {
        temp = dx;
        dx = dy;
        dy = temp;
        exchange = 1;                                               
    }
    else
        exchange = 0;

        g = 2*dy - dx;
        i = 1;
        while(i <= dx)
        {
            putpixel(x,y,RED);
            delay(10);
            if(exchange == 0)
                x = x+s1;
            else
                y = y+s2;

            if(g >= 0)
            {
                if(exchange == 0)
                    y = y + s2;
                else
                    x = x + s1;

                g = g + 2*dy  - 2*dx;
            }

            else
            {
                g = g + 2*dy;
            }
               i++;
        }
}

int geometry::sign(float arg)
{
    if(arg < 0)
        return -1;
    else if(arg == 0)
        return 0;
    else
        return 1;
}

void geometry::circle_bresenham(int x,int y,int rad)
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

void geometry::display_red(int x1,int y1,int x,int y)
{
    putpixel(x1+x,y1+y,RED);
    putpixel(x1+x,y-y1,RED);
    putpixel(x-x1,y1+y,RED);
    putpixel(x-x1,y-y1,RED);
    putpixel(y1+x,y+x1,RED);
    putpixel(y1+x,y-x1,RED);
    putpixel(x-y1,y+x1,RED);
    putpixel(x-y1,y-x1,RED);
    delay(50);
}

void geometry::draw(int x1,int y1,int x2,int y2)
{
	setbkcolor(WHITE);
	delay(2000);
	line_bresenham(x1,y1,x2,y2);
	float h;
	h = pow(3,0.5);
	h = (h/2)*(x2-x1);
	int x3,y3;
	x3 = (x1+x2)/2;
	y3 = y1-h;
	line_bresenham(x2,y2,x3,y3);
	line_bresenham(x3,y3,x1,y1);
	
	h = h/3;
	int x,y,rad;
	y = y1-h;
	circle_bresenham(x3,y,h);
	circle_bresenham(x3,y,2*h);
}


int main()
{
	int x1,y1,x2,y2;
	cout<<"\nEnter y co-ordinate of base of triangle : ";
	cin>>y1;
	y2=y1;
	cout<<"\nEnter x co-ordinate of left point off triangle : ";
	cin>>x1;
	cout<<"\n Enter length of side of triangle : ";
	cin>>x2;
	x2+=x1;
	
	geometry g;
	
	int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    cleardevice();

    g.draw(x1,y1,x2,y2);
    
    getch();
    closegraph();


	return 0;
}
