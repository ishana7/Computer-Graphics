#include<iostream>
#include<graphics.h>
using namespace std;
class curve
{
     int x[4],y[4];
     public:
          curve()
          {
               for(int k=0;k<4;k++)
               {
                    x[k]=y[k]=0;
               }
          }
          void brezier();
          void points(int x,int y);
};
void curve :: brezier()
{
     int px,py;
     for(float u=0;u<=1;u+=0.0005)
	{
		px=(1-u)*(1-u)*(1-u)*x[0]+3*u*(1-u)*(1-u)*x[1]+3*u*u*(1-u)*x[2]+u*u*u*x[3];
		py=(1-u)*(1-u)*(1-u)*y[0]+3*u*(1-u)*(1-u)*y[1]+3*u*u*(1-u)*y[2]+u*u*u*y[3];
		putpixel(px,py,WHITE);

	}
}
void curve :: points(int a,int b)
{
     putpixel(a,b,WHITE);
	x[0]=x[1]=a-25; x[2]=x[3]=a+25;
	y[0]=y[3]=b+25; y[2]=y[1]=b+25+75/2;
	brezier();
	x[0]=x[3]=a+25; x[1]=x[2]=a+25+75/2;
	y[0]=y[1]=b+25; y[2]=y[3]=b-25;
	brezier();
	x[0]=x[1]=a+25; x[2]=x[3]=a-25;
	y[0]=y[3]=b-25; y[2]=y[1]=b-25-75/2;
	brezier();
	x[0]=x[3]=a-25; x[1]=x[2]=a-25-75/2;
	y[0]=y[1]=b-25; y[2]=y[3]=b+25;
	brezier();
}
int main()
{
	int gd=DETECT,gm;
	curve c;
	int x,y;
	cout<<"Enter the (x,y) coordinates of centre point: ";
	cin>>x>>y;
	initgraph(&gd,&gm,NULL);
	c.points(x,y);
	getch();
	closegraph();
	return 0;
}
