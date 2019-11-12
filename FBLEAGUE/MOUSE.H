union REGS in,out;
int x,y,xp,yp,cl;
int gd=DETECT,gm;
void resetmouse()
{
	in.x.ax=0;
	int86(51,&in,&out);
}
void callmouse()
{
	in.x.ax=1;
	int86(51,&in,&out);
}
void setposi(int a,int b)
{
	in.x.ax=4;
	in.x.cx=a;
	in.x.dx=b;
	int86(51,&in,&out);
}
void getposi(int &xp,int &yp,int &cl)
{
	in.x.ax=3;
	int86(51,&in,&out);
	cl=out.x.bx;
	xp=out.x.cx;
	yp=out.x.dx;
}
