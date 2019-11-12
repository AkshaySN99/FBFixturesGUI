void CreatePlayer();
void EditPlayer();
void RemovePlayer();
void SearchPlayer();
void EditTeam();
void DisplayTeam();
void SearchTeam();

void DBMenu()
{
 cleardevice();
 while(1)
 {
	outtextxy(x-95,y-170,"DATABASE MANAGEMENT MENU");
	outtextxy(x-260,y-140,"PLAYER OPTIONS");
	rectangle(x-270,y-115,x-140,y-95);
	outtextxy(x-260,y-108,"Create Players");
	rectangle(x-260,y-80,x-150,y-60);
	outtextxy(x-251,y-75,"Edit Players [protected]");
	rectangle(x-265,y-45,x-145,y-25);
	outtextxy(x-258,y-40,"Remove Players [protected]");
	rectangle(x-265,y-10,x-145,y+10);
	outtextxy(x-258,y-5,"Search Players");
	outtextxy(x+100,y-140,"TEAM OPTIONS");
	rectangle(x+70,y-115,x+220,y-95);
	outtextxy(x+75,y-108,"Display Teams List");
	rectangle(x+100,y-80,x+190,y-60);
	outtextxy(x+107,y-75,"Edit Teams [protected]");
	rectangle(x+95,y-45,x+198,y-25);
	outtextxy(x+100,y-40,"Search Teams");
	rectangle(x-230,y+65,x-100,y+80);
	outtextxy(x-224,y+70,"Change Password");
        setcolor(GREEN);
	rectangle(x+70,y+65,x+220,y+80);
	outtextxy(x+78,y+70,"Exit to main menu ");
        setcolor(YELLOW);
	cl=0;
	getposi(xp,yp,cl);
	if((xp>x-270)&&(yp>y-115)&&(xp<x-140)&&(yp<y-95))
	 if(cl==1)
	 {
	  closegraph();
	  CreatePlayer();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x-260)&&(yp>y-80)&&(xp<x-150)&&(yp<y-60))
	 if(cl==1)
	 {
	  closegraph();
	  EditPlayer();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x-265)&&(yp>y-45)&&(xp<x-145)&&(yp<y-25))
	 if(cl==1)
	 {
	  closegraph();
	  RemovePlayer();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x-265)&&(yp>y-10)&&(xp<x-145)&&(yp<y+10))
	 if(cl==1)
	 {
	  closegraph();
	  SearchPlayer();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x+70)&&(yp>y-115)&&(xp<x+220)&&(yp<y-95))
	 if(cl==1)
	 {
	  closegraph();
	  DisplayTeam();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x+100)&&(yp>y-80)&&(xp<x+190)&&(yp<y-60))
	 if(cl==1)
	 {
	  closegraph();
	  EditTeam();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x+95)&&(yp>y-45)&&(xp<x+198)&&(yp<y-25))
	 if(cl==1)
	 {
	  closegraph();
	  SearchTeam();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x-230)&&(yp>y+65)&&(xp<x-100)&&(yp<y+80))
	 if(cl==1)
	 {
	  closegraph();
	  Password P;
	  P.ChangePassword();
	  initgraph(&gd,&gm,"C:\\Turboc3\\BGI");
	  resetmouse();
	  callmouse();
	  cleardevice();
	 }
	if((xp>x+70)&&(yp>y+65)&&(xp<x+220)&&(yp<y+80))
	if(cl==1)
	 {
	  cleardevice();
	  return;
	 }

  }
}

void CreatePlayer()
{
	 Player P;
	 int i=0;
	 char ch;
	 ofstream fout("PLAYER.DAT",ios::binary|ios::app);
	 if(!fout)
	 {
	  cout<<"\n"<<setw(66)<<"File cannot be created! Returning to database menu...";
	  getch();
	  return;
	 }
	 do
	 {
	  clrscr();
	  cout<<"\n"<<setw(60)<<"Enter details for player to be created : "<<endl;
	  P.Enter();
	  fout.write((char*)&P,sizeof(P));
	  cout<<"\n\n"<<setw(56)<<"Do you wish to enter more? <y/n> ";
	  cin>>ch;
	  i++;
	 }
	 while((ch=='y')||(ch=='Y'));
	 fout.close();
}

void EditPlayer()
{
	int tries=3;
	ifstream fp;
	do
	{
	 clrscr();
	 Password PWD;
	 char Pass[5];
	 cout<<"\n"<<setw(59)<<"Enter password to access this module : ";
	 gets(Pass);
	 fp.open("PASS.DAT",ios::binary);
	 if(!fp)
	 {
	  cout<<"\n"<<setw(51)<<"File cannot be opened!";
	  getch();
	  return;
	 }
	 fp.read((char*)&PWD,sizeof(PWD));
	 if(strcmpi(PWD.Re_Pass(),Pass)==0)
	 {
	  clrscr();
	  Player P;
	  int n,flag=0;
	  char ch,EditName[30];
	  fstream f("PLAYER.DAT",ios::binary|ios::in|ios::out);
	  if(!f)
	  {
	   cout<<"\n"<<setw(66)<<"File cannot be opened! Returning to database menu...";
	   getch();
	   return;
	  }
	  do
	  {
	   flag=0;
	   f.clear();
	   f.seekg(0,ios::beg);
	   clrscr();
	   cout<<"\n"<<setw(47)<<"Enter player name to be edited : ";
	   gets(EditName);
	   while((flag==0)&&(f.read((char*)&P,sizeof(P))))
	   {
	    if(strcmpi(P.Re_PName(),EditName)==0)
	     {
	     flag=1;
	     cout<<"\n"<<setw(48)<<"Player details : ";
	     P.Display();
	     cout<<"\n\n"<<setw(50)<<"Enter new details : ";
	     P.Enter();
	     n=(f.tellg()-sizeof(P));
	     f.seekp(n);
	     f.write((char*)&P,sizeof(P));
	    }
	   }
	   if(flag==0)
	     cout<<"\n"<<setw(48)<<"Player not found!";
	   if(flag==1)
	     cout<<"\n"<<setw(53)<<"Player edited successfully";
	   cout<<"\n\n"<<setw(57)<<"Do you want to edit more players? <y/n> ";
	   cin>>ch;
	  }
	  while((ch=='y')||(ch=='Y'));
	  f.close();
	  break;
	}
	 else
	 {
	  tries--;
	  cout<<"\n"<<setw(51)<<"Incorrect password! ";
	  cout<<"\n"<<setw(39)<<"You have "<<tries<<" tries left";
	  if(tries==0)
	   cout<<"\n\n"<<setw(61)<<"Press any key to return to database menu.";
	  fp.close();
	  getch();
	 }
	}
	while(tries!=0);
	fp.close();
}

void RemovePlayer()
{
	int tries=3;
	ifstream fp;
	do
	{
	 clrscr();
	 Password PWD;
	 char Pass[5];
	 cout<<"\n"<<setw(59)<<"Enter password to access this module : ";
	 gets(Pass);
	 fp.open("PASS.DAT",ios::binary);
	 if(!fp)
	 {
	  cout<<"\n"<<setw(50)<<"File cannot be opened!";
	  getch();
	  return;
	 }
	 fp.read((char*)&PWD,sizeof(PWD));
	 if(strcmpi(PWD.Re_Pass(),Pass)==0)
	 {
	 char choice;
	 do
	 {
	  ifstream fin("PLAYER.DAT",ios::binary);
	  ofstream fout("TEMP.DAT",ios::binary);
	  if(!fin)
	  {
	   cout<<"\n"<<setw(50)<<"File cannot be opened!";
	   getch();
	   return;
	  }
	  if(!fout)
	  {
	   cout<<"\n"<<setw(50)<<"File cannot be created!";
	   getch();
	   return;
	  }
	  Player P;
	  char pname[30];
	  int flag=0;
	  int RemoveStatus,RenameStatus;
	   flag=0;
	   clrscr();
	   cout<<"\n"<<setw(54)<<"Enter name of player to be removed : ";
	   gets(pname);
	   while(fin.read((char*)&P,sizeof(P)))
	   {
	   if(strcmpi(P.Re_PName(),pname)!=0)
	   {
	    fout.write((char*)&P,sizeof(P));
	   }
	   else
	   {
	    cout<<"\n\n"<<setw(57)<<"Details for player being removed : ";
	    P.Display();
	    flag=1;
	   }
	  }
	  fin.close();
	  fout.close();
	  if(flag==0)
	   cout<<"\n"<<setw(48)<<"Player not found!";
	  if(flag==1)
	   {
	   cout<<"\n\n"<<setw(54)<<"Player removed successfully!";
	    RemoveStatus=remove("PLAYER.DAT");
	    if(RemoveStatus!=0)
	     cout<<"\n"<<setw(56)<<"Unable to remove file 'PLAYER.DAT'";
	    RenameStatus=rename("TEMP.DAT","PLAYER.DAT");
	   if(RenameStatus!=0)
	     cout<<"\n"<<setw(63)<<"Unable to rename file 'TEMP.DAT' to 'PLAYER.DAT'";
	   }
	   cout<<"\n"<<setw(60)<<"Do you want to remove more players? <y/n> ";
	   cin>>choice;
	  }
	  while((choice=='y')||(choice=='Y'));
	  break;
	 }
	 else
	 {
	  tries--;
	  cout<<"\n"<<setw(51)<<"Incorrect password! ";
	  cout<<"\n"<<setw(39)<<"You have "<<tries<<" tries left";
	  if(tries==0)
	   cout<<"\n\n"<<setw(61)<<"Press any key to return to database menu.";
	  fp.close();
	  getch();
	 }
	}
	while(tries!=0);
	fp.close();
}

void SearchPlayer()
{
	 clrscr();
	 Player P;
	 int flag;
	 char ch,pname[30];
	 ifstream fin("PLAYER.DAT",ios::binary);
	 if(!fin)
	 {
	  cout<<"\n"<<setw(55)<<"'PLAYER.DAT' cannot be found!";
	  cout<<"\n"<<setw(61)<<"Press any key to return to database menu.";
	  getch();
	  return;
	 }
	 do
	 {
	  flag=0;
	  fin.clear();
	  fin.seekg(0,ios::beg);
	  clrscr();
	  cout<<"\n"<<setw(51)<<"Enter name of player to be searched : ";
	  gets(pname);
	  while(fin.read((char*)&P,sizeof(P)))
	  {
	   if(strcmpi(P.Re_PName(),pname)==0)
	   {
	    cout<<"\n"<<setw(55)<<"Player found! Player details are : "<<endl;
	    P.Display();
	    flag=1;
	    break;
	   }
	  }
	  if(flag==0)
	   cout<<"\n"<<setw(48)<<"Player not found!";
	  cout<<"\n\n"<<setw(62)<<"Would you like to search more players? <y/n> ";
	  cin>>ch;
	 }
	 while((ch=='y')||(ch=='Y'));
	 fin.close();
}

void EditTeam()
{
	int tries=3;
	ifstream fp;
	do
	{
	 clrscr();
	 Password PWD;
	 char Pass[5];
	 cout<<"\n"<<setw(59)<<"Enter password to access this module : ";
	 gets(Pass);
	 fp.open("PASS.DAT",ios::binary);
	 if(!fp)
	 {
	  cout<<"\n"<<setw(50)<<"File cannot be opened!";
	  getch();
	  return;
	 }
	 fp.read((char*)&PWD,sizeof(PWD));
	 if(strcmpi(PWD.Re_Pass(),Pass)==0)
	 {
	  clrscr();
	  Team T;
	  int n,flag=0;
	  char ch,EditName[30];
	  fstream f("TEAM.DAT",ios::binary|ios::in|ios::out);
	  if(!f)
	  {
	   cout<<"\n"<<setw(65)<<"File cannot be opened! Returning to database menu...";
	   getch();
	   return;
	  }
	  do
	  {
	   flag=0;
	   f.clear();
	   f.seekg(0,ios::beg);
	   clrscr();
	   cout<<"\n"<<setw(55)<<"Enter team name to be edited : ";
	   gets(EditName);
	   while((flag==0)&&(f.read((char*)&T,sizeof(T))))
	   {
	    if(strcmpi(T.Re_TName(),EditName)==0)
	    {
	     flag=1;
	     cout<<"\n"<<setw(47)<<"Team details : ";
	     T.Display();
	     cout<<"\n\n"<<setw(49)<<"Enter new details : ";
	     T.Enter();
	     n=(f.tellg()-sizeof(T));
	     f.seekp(n);
	     f.write((char*)&T,sizeof(T));
	    }
	   }
	   if(flag==0)
	    cout<<"\n"<<setw(47)<<"Team not found!";
	   if(flag==1)
	    cout<<"\n"<<setw(51)<<"Team edited successfully";
	    cout<<"\n\n"<<setw(58)<<"Do you want to edit more teams? <y/n> ";
	    cin>>ch;
	  }
	  while((ch=='y')||(ch=='Y'));
	  f.close();
	  break;
	}
	 else
	 {
	  tries--;
	  cout<<"\n"<<setw(51)<<"Incorrect password! ";
	  cout<<"\n"<<setw(39)<<"You have "<<tries<<" tries left";
	  if(tries==0)
	   cout<<"\n\n"<<setw(61)<<"Press any key to return to database menu.";
	  fp.close();
	  getch();
	 }
	}
	while(tries!=0);
	fp.close();
}

void DisplayTeam()
{
	 clrscr();
	 Team T;
	 int i=1;
	 char ch,tname[30];
	 ifstream fin("TEAM.DAT",ios::binary);
	 if(!fin)
	 {
	  cout<<"\n"<<setw(68)<<"'TEAM.DAT' cannot be found! Returning to database menu...";
	  getch();
	  return;
	 }
	 cout<<"\n"<<setw(47)<<"TEAMS LIST : ";
	  while(fin.read((char*)&T,sizeof(T)))
	  {
	    cout<<"\n"<<i<<". "<<T.Re_TName();
	    i++;
	  }
	  cout<<"\n\n"<<setw(59)<<"Press any key to return to database menu";
	  getch();
	 fin.close();
}

void SearchTeam()
{
	 clrscr();
	 Player P;
	 Team T;
	 int flag;
	 char ch,tname[30];
	 ifstream fin("PLAYER.DAT",ios::binary);
	 ifstream ft("TEAM.DAT",ios::binary);
	 if((!fin)||(!ft))
	 {
	  cout<<"\n"<<setw(55)<<"Required .DAT files cannot be found! Returning to database menu...";
	  getch();
	  return;
	 }
	 do
	 {
	  flag=0;
	  ft.clear();
	  ft.seekg(0,ios::beg);
	  fin.clear();
	  fin.seekg(0,ios::beg);
	  clrscr();
	  cout<<"\n"<<setw(47)<<"Enter name of team to be searched : ";
	  gets(tname);
	  while(ft.read((char*)&T,sizeof(T)))
	  {
	   if(strcmpi(T.Re_TName(),tname)==0)
	   {
	    flag=1;
	    T.Display();
	    cout<<"\n\n"<<setw(47)<<"PLAYER LIST : "<<endl;
	    while(fin.read((char*)&P,sizeof(P)))
	    {
	      if(strcmpi(P.Re_TName(),tname)==0)
	      {
	       P.TeamListDisp();
	      }
	    }
	    break;
	   }
	  }
	  if(flag==0)
	   cout<<"\n"<<setw(48)<<"Team not found!";
	  cout<<"\n\n"<<setw(61)<<"Would you like to search more teams? <y/n> ";
	  cin>>ch;
	 }
	 while((ch=='y')||(ch=='Y'));
	 fin.close();
	 ft.close();
}
