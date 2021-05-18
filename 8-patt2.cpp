#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class geometry
{
	public:
		void line_bresenham(int,int,int,int);
		int sign(float);
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

void geometry::draw(int x1,int y1,int length,int width)
{
	setbkcolor(WHITE);
	delay(2000);
	line_bresenham(x1,y1,x1+length,y1);
	line_bresenham(x1+length,y1,x1+length,y1-width);
	line_bresenham(x1+length,y1-width,x1,y1-width);
	line_bresenham(x1,y1-width,x1,y1);
	
	line_bresenham(x1+length/2,y1,x1+length,y1-width/2);
	line_bresenham(x1+length,y1-width/2,x1+length/2,y1-width);
	line_bresenham(x1+length/2,y1-width,x1,y1-width/2);
	line_bresenham(x1,y1-width/2,x1+length/2,y1);
	
	line_bresenham(x1+0.25*length,y1-0.25*width,x1+0.75*length,y1-0.25*width);
	line_bresenham(x1+0.75*length,y1-0.25*width,x1+0.75*length,y1-0.75*width);
	line_bresenham(x1+0.75*length,y1-0.75*width,x1+0.25*length,y1-0.75*width);
	line_bresenham(x1+0.25*length,y1-0.75*width,x1+0.25*length,y1-0.25*width);
	
}


int main()
{
	int x1,y1,x2,y2;
	cout<<"\nEnter y co-ordinate of base of rectangle : ";
	cin>>y1;
	cout<<"\nEnter x co-ordinate of left point of rectangle : ";
	cin>>x1;
	cout<<"\n Enter length of rectangle : ";
	cin>>x2;
	cout<<"\n Enter width of rectangle : ";
	cin>>y2;
	
	geometry g;
	
	int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    cleardevice();

    g.draw(x1,y1,x2,y2);
    
    getch();
    closegraph();


	return 0;
}
