//Write C++/Java program for line drawing using DDA or Bresenhams algorithm with patterns such as solid, dotted, dashed, dash dot and thick. 


#include<graphics.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
class pt //base class
{
protected: int xco,yco,color;

public:
pt()
{
xco=0;yco=0;color=15;
}
void setco(int x,int y)
{
xco=x;
yco=y;
}
void setcolor(int c)
{
color=c;
}
void draw()
{ putpixel(xco,yco,color);

}

};

class dline: public pt //derived class
{
private: int x2,y2;
public:
dline():pt()
{
x2=0,y2=0;
}
void setline(int x, int y, int xx, int yy)
{
pt::setco(x,y);
x2=xx;
y2=yy;
}

void drawsi(int colour) //Simple DDA Line
{
float x,y,dx,dy,len;
int i;
pt::setcolor(colour);
dx=abs(x2-xco);
dy=abs(y2-yco);
if(dx >= dy)
{
len=dx;
}
else
{
len=dy;
}

dx=(x2-xco)/len;
dy=(y2-yco)/len;

x = xco + 0.5;
y = yco + 0.5;

i=1;
while(i<=len)
{
pt::setco(x,y);
pt::draw();
x = x + dx;
y = y + dy;
i = i + 1;
}
pt::setco(x,y);
pt::draw();
}

void drawda(int colour) //Dash DDA Line
{
float x,y,dx,dy,len;
int i,dash_pixel=0, dash_space=0;
pt::setcolor(colour);
dx=abs(x2-xco);
dy=abs(y2-yco);
if(dx >= dy)
{
len=dx;
}
else
{
len=dy;
}

dx=(x2-xco)/len;
dy=(y2-yco)/len;

x = xco + 0.5;
y = yco + 0.5;

i=1;
while(i<=len)
{
dash_pixel=0;
while(dash_pixel<5)
{
pt::setco(x,y);
pt::draw();
x = x + dx;
y = y + dy;
i = i + 1;
dash_pixel = dash_pixel +1;
}
dash_space=0;
while(dash_space<=2)
{
x = x + dx;
y = y + dy;
i = i + 1;
dash_space = dash_space +1;
}
}
}

void drawdo(int colour) //Dotted DDA Line
{ float x,y,dx,dy,len;
int i,dot_space;
pt::setcolor(colour);
dx=abs(x2-xco);
dy=abs(y2-yco);
if(dx >= dy)
{
len=dx;
}
else
{
len=dy;
}
dx=(x2-xco)/len;
dy=(y2-yco)/len;
x = xco + 0.5;
y = yco + 0.5;
i=1;
while(i<=len)
{
dot_space=0;
while(dot_space<=1)
{
x = x + dx;
y = y + dy;
i = i + 1;
dot_space = dot_space +1;
}
pt::setco(x,y);
pt::draw();
}

}

void drawth(int x1,int y1, int x2, int y2,int colour ) //Thick DDA Line
{
float x,y,dx,dy,len;
int i;
dx=abs(x2-x1);
dy=abs(y2-y1);
if(dx >= dy)
{ len=dx;
}
else
{ len=dy;
}
dx=(x2-x1)/len;
dy=(y2-y1)/len;
x = x1 + 0.5;
y = y1 + 0.5;

i=1;
while(i<=len)
{ putpixel(x,y,colour);
x = x + dx;
y = y + dy;
i = i + 1;
}
putpixel(x,y,colour);

}
};
int main()
{
int gd=DETECT,gm=VGAMAX;
int i, ch,x1,y1,x2,y2, dx,dy,xmax,ymax,xmid,ymid,wx,wy,th;
char a;
initgraph(&gd,&gm,NULL);
dline ls;
xmax = getmaxx();
ymax = getmaxy();
xmid = xmax /2;
ymid = ymax /2;
line(xmid,0,xmid,ymax); //Y co-ordinate
line(0,ymid,xmax,ymid); //X co-ordinate
do
{ xmax = getmaxx();
ymax = getmaxy();
xmid = xmax /2;
ymid = ymax /2;

cout<<"\nEnter Line Styles";
cout<<"\n1.SIMPLE..";
cout<<"\n2.DASH..";
cout<<"\n3.DOTTED..";
cout<<"\n4.THICK..";
cout<<"\n5.EXIT..";
cout<<"\nEnter your choice: ";
cin>>ch;
switch(ch)
{
case 1:
cout<<"\n Enter x1: "; cin>>x1;
cout<<"\n Enter y1: "; cin>>y1;
cout<<"\n Enter x2: "; cin>>x2;
cout<<"\n Enter y2: "; cin>>y2;
ls.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
ls.drawsi(15);
break;
case 2:
cout<<"\n Enter x1: "; cin>>x1;
cout<<"\n Enter y1: "; cin>>y1;
cout<<"\n Enter x2: "; cin>>x2;
cout<<"\n Enter y2: "; cin>>y2;
ls.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
ls.drawda(15);
break;
case 3:
cout<<"\n Enter x1: "; cin>>x1;
cout<<"\n Enter y1: "; cin>>y1;
cout<<"\n Enter x2: "; cin>>x2;
cout<<"\n Enter y2: "; cin>>y2;
ls.setline(x1+xmid,ymid-y1,x2+xmid,ymid-y2);
ls.drawdo(15);
break;
case 4:
cout<<"\n Enter x1: "; cin>>x1;
cout<<"\n Enter y1: "; cin>>y1;
cout<<"\n Enter x2: "; cin>>x2;
cout<<"\n Enter y2: "; cin>>y2;
cout<<"Enter Thickness: ";
cin>>th;
ls.drawth(x1+xmid,ymid-y1,x2+xmid,ymid-y2,15);
if((y2-y1)/(x2-x1) <1)
{
wy=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(x2-x1));
for(i=0;i<wy;i++)
{
ls.drawth(x1+xmid,ymid-y1-i,x2+xmid,ymid-y2-i,15);
ls.drawth(x1+xmid,ymid-y1+i,x2+xmid,ymid-y2+i,15);
}
}
else
{
wx=(th-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*abs(y2-y1));
for(i=0;i<wx;i++)
{
ls.drawth(x1+xmid-i,ymid-y1,x2+xmid-i,ymid-y2,15);
ls.drawth(x1+xmid+i,ymid-y1,x2+xmid+i,ymid-y2,15);
}
}
break;
case 5:
exit;
break;
}
cout<<"\nDO U Want To Continue y OR n: ";
cin>>a;
}while(a!='n');
delay(3000);
getch();
closegraph();
return 0;
}
