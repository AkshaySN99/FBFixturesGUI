void Predictor()
{
	 clrscr();
	 Team T;
	 int hflag=0,aflag=0;
	 char home[30],away[30];
	 float homeOVR,awayOVR;
	 int i;
	  pred:
	  cout<<"\n\n\n\n"<<setw(49)<<"MATCH PREDICTOR :";
	  cout<<"\n\n"<<setw(35)<<"Enter home team name : ";
	  gets(home);
	  cout<<setw(35)<<"Enter away team name : ";
	  gets(away);
	  if(strcmpi(home,away)==0)
	  {
	   cout<<"\n"<<setw(66)<<"Invalid parameters! A team cannot have a match with itself.";
	   cout<<"\n"<<setw(52)<<"Please enter valid team names.";
	   getch();
	   clrscr();
	   goto pred;
	  }
	 ifstream fin("TEAM.DAT",ios::binary);
	 if(!fin)
	 {
	  cout<<"\n"<<setw(54)<<"'TEAM.DAT' cannot be found!";
	  cout<<"\n"<<setw(59)<<"'TEAM.DAT' is required for this module";
	  getch();
	  return;
	 }
	 while(fin.read((char*)&T,sizeof(T)))
	 {
	   if(strcmpi(home,T.Re_TName())==0)
	    {
	     hflag=1;
	     homeOVR=T.TOVR_Calc();
	     homeOVR+=(homeOVR*0.02);
	     strcpy(home,T.Re_TName());
	     break;
	    }
	 }
	 if(hflag==0)
	 {
	  cout<<"\n"<<setw(53)<<"Incorrect home team name!";
	  cout<<"\n"<<setw(55)<<"Press enter correct team name.";
	  getch();
	  clrscr();
	  goto pred;
	 }
	 fin.clear();
	 fin.seekg(0,ios::beg);
	 while(fin.read((char*)&T,sizeof(T)))
	 {
	   if(strcmpi(away,T.Re_TName())==0)
	    {
	     aflag=1;
	     awayOVR=T.TOVR_Calc();
	     strcpy(away,T.Re_TName());
	     break;
	    }
	 }
	 if(aflag==0)
	 {
	  cout<<"\n"<<setw(53)<<"Incorrect away team name!";
	  cout<<"\n"<<setw(55)<<"Press enter correct team name.";
	  getch();
	  clrscr();
	  goto pred;
	 }
	 fin.close();
	 cout<<"\n"<<setw(54)<<"Calculating team overalls...";
	 sleep(2);
	 cout<<"\n"<<setw(59)<<"Calculating home ground advantage...";
	 sleep(1);
	 int len1=(strlen(home))/2;
	 int len2=(strlen(away))/2;
	 cout<<"\n\n"<<setw(50)<<"Prediction Result :";
	 if(homeOVR>awayOVR)
	  cout<<"\n"<<setw(23+len1)<<home<<" is more likely to win the match.";
	 else if(homeOVR<awayOVR)
	  cout<<"\n"<<setw(23+len2)<<away<<" is more likely to win the match.";
	 else
	  cout<<"\n"<<setw(58)<<"The match is more likely to be a draw.";
	 getch();
}
