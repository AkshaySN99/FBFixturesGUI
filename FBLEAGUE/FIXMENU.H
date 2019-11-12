Matchday Md[38];
void getposi(int &,int&,int&);
void CreateFixtures();
void DispFixtures();
int Check(int,int[]);
void AssignTeamID();
char* AsgnTeamName(short);
void DisplayFixtures(Matchday Mf[38]);

void FixturesMenu()
{
	 cleardevice();
	 while(1)
	 {
	  setcolor(LIGHTCYAN);
	  outtextxy(x-45,y-128,"FIXTURE MENU");
	  rectangle(x-70,y-70,x+70,y-40);
	  outtextxy(x-54,y-58,"Create Fixtures");
	  rectangle(x-75,y-10,x+75,y+20);
	  outtextxy(x-58,y+2,"Display Fixtures");
	  setcolor(GREEN);
	  rectangle(x-80,y+50,x+80,y+80);
	  outtextxy(x-68,y+62,"Exit to Main Menu");
	  setcolor(LIGHTCYAN);
	  cl=0;
	  getposi(xp,yp,cl);
	  if((xp>x-70)&&(yp>y-70)&&(xp<x+70)&&(yp<y-40))
	   if(cl==1)
	   {
	     closegraph();
	     CreateFixtures();
	     initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	     resetmouse();
	     callmouse();
	     cleardevice();
	   }
	  if((xp>x-75)&&(yp>y-10)&&(xp<x+75)&&(yp<y+20))
	  if(cl==1)
	   {
	     closegraph();
	     DispFixtures();
	     initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	     resetmouse();
	     callmouse();
	     cleardevice();
	   }
	  if((xp>x-80)&&(yp>y+50)&&(xp<x+80)&&(yp<y+80))
	   if(cl==1)
	   {
	     cleardevice();
	     return;
	   }
	 }
}

void DispFixtures()
{
	 clrscr();
	 int i;
	 Matchday Mt[38];
	 ifstream fin("FIXTURES.DAT",ios::binary);
	 if(!fin)
	 {
	    gotoxy(22,10);
	    cout<<"Unable to open 'FIXTURES.DAT'";
	    gotoxy(20,11);
	    cout<<"Fixtures could not be created!";
	 }
	 for(i=0;i<38;i++)
	 {
	  fin.read((char*)&Mt[i],sizeof(Matchday));
	 }
	 fin.close();
	 DisplayFixtures(Mt);
}

void CreateFixtures()
{
	  clrscr();
	  char ch;
	  int i=0,m,n,x=0,y,z;
	  for(;x<19;x++)
	  {
	   for(z=0;z<10;z++)
	   {
	    Md[x].M[z].T1=(x+z)%19;
	    Md[x].M[z].T2=(x-z+19)%19;
	    if(z==0)
	     Md[x].M[z].T2=19;
	   }
	  }
	  for(y=0;y<19,x<38;y++,x++)
	  {
	   for(z=0;z<10;z++)
	   {
	    Md[x].M[z].T1=Md[y].M[z].T2;
	    Md[x].M[z].T2=Md[y].M[z].T1;
	   }
	  }
	  AssignTeamID();
	  gotoxy(20,10);
	  cout<<"Fixtures have been created successfully!";
	  cout<<"\n"<<setw(60)<<"Press any key to return to fixtures menu.";
	  ofstream fout("FIXTURES.DAT",ios::binary);
	  if(!fout)
	  {
	    gotoxy(22,10);
	    cout<<"Unable to create 'FIXTURES.DAT'";
	    gotoxy(20,11);
	    cout<<"Fixtures could not be created!";
	    getch();
	    return;
	  }
	  for(m=0;m<38;m++)
	  {
	     fout.write((char*)&Md[i],sizeof(Matchday));
	     i++;
	  }
	   getch();
	   fout.close();
}

int Check(int Rndm,int B[20])
{
	 int i,flag=0;
	 for(i=0;i<20;i++)
	 {
	  if(B[i]==Rndm)
	  {
	   flag=1;
	   break;
	  }
	 }
	 return (flag);
}

void AssignTeamID()
{
	 int B[20],Rndm,i=0,flag,n;
	 Team T;
	 srand(time(NULL));
	 fstream f("TEAM.DAT",ios::binary|ios::in|ios::out);
	 if(!f)
	 {
	  gotoxy(22,10);
	  cout<<"'TEAM.DAT' cannot be found.";
	  gotoxy(20,11);
	  cout<<"Fixtures could not be created!";
	  getch();
	  return;
	 }
	 while(f.read((char*)&T,sizeof(T)))
	 {
	  flag=0;
	  //Loop to take out random number between 0-19
	  do
	  {
	   Rndm=rand()%20;
	   if(Check(Rndm,B)==0)
	    flag=1;
	  }
	  while(flag==0);
	  //Loop for random number ends
	  B[i]=Rndm;
	  i++;
	  T.Asgn_TeamID(Rndm);
	  n=(f.tellg()-sizeof(T));
	  f.seekp(n);
	  f.write((char*)&T,sizeof(T));
	 }
	 f.close();
}

char* AsgnTeamName(short x)
{
	 Team T;
	 char string[30];
	 ifstream fin("TEAM.DAT",ios::binary);
	 if(!fin)
	 {
	  gotoxy(22,10);
	  cout<<"'TEAM.DAT' cannot be found.";
	  gotoxy(20,11);
	  cout<<"Fixtures could not be created!";
	 }
	 while(fin.read((char*)&T,sizeof(T)))
	 {
	  if(x==T.Re_TId())
	  {
	   strcpy(string,T.Re_TName());
	   break;
	  }
	 }
	 fin.close();
	 return (string);
}

void DisplayFixtures(Matchday Mf[38])
{
	 clrscr();
	 int m,n;
	 char home[30],away[30],ch;
	 for(m=0;m<38;m++)
	 {
	  ReDisp:
	  clrscr();
	  cout<<"\n"<<setw(43)<<"MATCHDAY "<<m+1<<endl;
	  for(n=0;n<10;n++)
	  {
	   strcpy(home,AsgnTeamName(Mf[m].M[n].T1));
	   strcpy(away,AsgnTeamName(Mf[m].M[n].T2));
	   cout<<"\n"<<setw(34)<<home<<"    v    "<<away;
	  }
	  if(m<37)
	  {
	   cout<<"\n\n\n\nN - Proceed to next matchday \10\10";
	   if(m==0)
	    cout<<"\nX - Exit to fixtures menu";
	  }
	  if(m>0)
	  {
	   if(m==37)
	   {
	    cout<<"\n\n\n\nP - Proceed to previous matchday \11\11";
	    cout<<"\nX - Exit to fixtures menu";
	   }
	   else
	   {
	    cout<<"\nP - Proceed to previous matchday \11\11";
	    cout<<"\nX - Exit to fixtures menu";
	   }
	  }
	  ch=getch();
	  switch(ch)
	  {
	   case 'n':
	   case 'N': if(m<37)
		      continue;
		     else
		      m--;
		     break;
	   case 'p':
	   case 'P': if(m==0)
		     goto ReDisp;
		     else
		     {
		       clrscr();
		       m-=2;
		     }
		     break;
	   case 'x':
	   case 'X': return;
	   default : goto ReDisp;
	  }
	}
}