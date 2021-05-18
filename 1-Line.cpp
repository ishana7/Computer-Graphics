#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

class line_draw
{
	protected:
		int x1,y1,x2,y2;
	public:
		line_draw()
			{			
    			cout<<"\n DDA Line Drawing Algorithm & Bresenham's Line Drawing Algorithm Implementation :";
    			cout<<"\n\n(NOTE : Line using DDA algo. will be displayed in WHITE and Line using Bresenham's algo. will be RED in colour)";
    			cout<<"\n\n\n Enter co-ordinates of first point (x1,y1):\n";
    			cin>>x1>>y1;
    			cout<<"\n Enter co-ordinates of second point (x2,y2):\n";
    			cin>>x2>>y2;
			}
};

class pixel:public line_draw
{
	public:
		void dda();
		void bresenham();
		int sign(float);
};

void pixel::dda()
{
    int i,dx,dy,steps;
    float x,y;
    int xt,yt;
    float xinc,yinc;

	xt = x1;
	yt = x2;
    dx = (x2-x1);
    dy = (y2-y1);

    if(abs(dx)>= abs(dy))                                            //decide whether to move along
        steps = abs(dx);                                                //x-axis
    else
        steps = abs(dy);                                                //or y-axis

    xinc = (float)dx/steps;                                         //calculate the increment value for x & y
    yinc = (float)dy/steps;

    x = x1;
    y = y1;

    putpixel(x,y,WHITE);                                            // plot first point
    for(i=1;i<steps;i++)
    {
        x = x + xinc;
        y = y + yinc;

        xt = x + 0.5;
        yt = y + 0.5;
        delay(10);
        putpixel(xt,yt,WHITE);                                      // plot the points
    }
}

void pixel::bresenham()
{
    int s1,s2,exchange,x,y,i;
    float dx,dy,g,temp;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    x = x1;
    y = y1;
    s1 = sign(x2-x1);
    s2 = sign(y2-y1);
    if(dy>dx)                                                       // interchange dx & dy depending on the slope of the line;
    {
        temp = dx;
        dx = dy;
        dy = temp;
        exchange = 1;                                               // flag named exchange has been set to mark it as steep slope and dy and dx value interchanged
    }
    else
    {
        exchange = 0;
	}
	
        g = 2*dy - dx;
        i = 1;
        while(i <= dx)
        {
            putpixel(x,y,RED);
            delay(50);
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

int pixel::sign(float arg)
{
    if(arg < 0)
        return -1;
    else if(arg == 0)
        return 0;
    else
        return 1;
}


int main()
{   
	pixel p;
    
    int gd = DETECT,gm;
    initgraph(&gd,&gm,NULL);
    cleardevice();
	setbkcolor(BLACK);
    delay(2000);
    
    p.dda();
    p.bresenham();
	
	getch();
    closegraph();

    return 0;
}

