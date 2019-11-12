struct Match
{
	 short T1;
	 short T2;
};
struct Matchday
{
	 Match M[10];
};
class Password
{
	 private:
	  char Pin[5];
	 public:
	  void EnterPass()
	  {
	   cin>>Pin;
	  }
	  void ChangePassword();
	  char* Re_Pass()
	  {
	   return Pin;
	  }
	};
void Password::ChangePassword()
{
	 int n;
	 char old[5],confirm[5];
	 Password PWD;
	 fstream f("PASS.DAT",ios::binary|ios::in|ios::out);
	 if(!f)
	 {
	  cout<<"\n"<<setw(56)<<"'PASS.DAT' could not be opened!";
	  cout<<"\n"<<setw(54)<<"Password cannot be changed.";
	  getch();
	  return;
	 }
	 cout<<"\n"<<setw(49)<<"Enter old password : ";
	 gets(old);
	 f.read((char*)&PWD,sizeof(PWD));
	 if(strcmpi(PWD.Re_Pass(),old)==0)
	 {
	  cout<<"\n"<<setw(56)<<"Enter new 4-character password : ";
	  PWD.EnterPass();
	  cout<<""<<setw(50)<<"Confirm new password : ";
	  gets(confirm);
	  if(strcmp(PWD.Re_Pass(),confirm)==0)
	  {
	   n=(f.tellg()-sizeof(PWD));
	   f.seekp(n);
	   f.write((char*)&PWD,sizeof(PWD));
	   cout<<"\n"<<setw(55)<<"Password changed successfully!";
	   getch();
	 }
	  else
	  {
	   cout<<"\n"<<setw(52)<<"Passwords do not match!";
	   cout<<"\n"<<setw(58)<<"Press any key to return to main menu";
	   getch();
	  }
	 }
	 else
	 {
	  cout<<"\n"<<setw(50)<<"Incorrect password!";
	  cout<<"\n"<<setw(58)<<"Press any key to return to main menu";
	  getch();
	 }
	 f.close();
}

class Player
{
     private:
	char Name[30];
	char TName[30];
	char Nationality[25];
	int Age;
	char Foot;
	short OVR;
	char POS[4];
     public:
	short Re_OVR()
	{
	 return OVR;
	}
	char* Re_TName()
	{
	 return TName;
	}
	char* Re_PName()
	{
	 return Name;
	}
	void TeamListDisp()
	{
	 int len;
	 len=strlen(Name);
	 cout<<"\n\t\t\t"<<POS<<"\t"<<Name<<setw(25-len)<<OVR;
	}
	void Enter();
	void Display()
	{
	 cout<<"\n"<<setw(40)<<"Name : "<<Name;
	 cout<<"\n"<<setw(40)<<"Team name : "<<TName;
	 cout<<"\n"<<setw(40)<<"Nationality : "<<Nationality;
	 cout<<"\n"<<setw(40)<<"Age : "<<Age;
	 cout<<"\n"<<setw(40)<<"Foot : "<<Foot;
	 cout<<"\n"<<setw(40)<<"Player overall : "<<OVR;
	 cout<<"\n"<<setw(40)<<"Position : "<<POS;
	}
};
void Player::Enter()
{
	  int i;
	  char strAge[10];
	  NAME:
	  cout<<"\n"<<setw(40)<<"Enter name : ";
	  gets(Name);
	  for(i=0;Name[i]!='\0';i++)
	  {
	   if((Name[i]>=48)&&(Name[i]<=57))
	   {
	    cout<<"\n"<<setw(62)<<"Incorrect name! Name cannot contain a number";
	    goto NAME;
	   }
	  }
	  TEAMNAME:
	  cout<<setw(40)<<"Enter team name : ";
	  gets(TName);
	  for(i=0;TName[i]!='\0';i++)
	  {
	   if((TName[i]>=48)&&(TName[i]<=57))
	   {
	    cout<<"\n"<<setw(67)<<"Incorrect team name! Team name cannot contain a number";
	    goto TEAMNAME;
	   }
	  }
	  NATION:
	  cout<<setw(40)<<"Enter nationality : ";
	  gets(Nationality);
	  for(i=0;Nationality[i]!='\0';i++)
	  {
	   if((Nationality[i]>=48)&&(Nationality[i]<=57))
	   {
	    cout<<"\n"<<setw(69)<<"Incorrect nationality! Nationality cannot contain a number";
	    goto NATION;
	   }
	  }
	  AGE:
	  cout<<setw(40)<<"Enter age : ";
	  gets(strAge);
	  for(i=0;strAge[i]!='\0';i++)
	  {
	   if(isalpha(strAge[i]))
	   {
	    cout<<"\n"<<setw(63)<<"Incorrect age! Please enter age in numericals"<<endl;
	    goto AGE;
	   }
	  }
	  Age=atoi(strAge);
	  if((Age<18)||(Age>40))
	  {
	   cout<<"\n"<<setw(72)<<"You have entered incorrect age! Please enter age between 18-40."<<endl;
	   getch();
	   goto AGE;
	  }
	  FEET:
	  cout<<setw(40)<<"Enter foot (L/R) : ";
	  cin>>Foot;
	  if((Foot!='L')&&(Foot!='l')&&(Foot!='R')&&(Foot!='r'))
	  {
	   cout<<"\n"<<setw(72)<<"Incorrect parameters for foot! Please enter correct foot (L/R)."<<endl;
	   getch();
	   goto FEET;
	  }
	  else if((Foot=='l')||(Foot=='r'))
	   toupper(Foot);
	  OVERALL:
	  cout<<setw(40)<<"Enter player overall : ";
	  cin>>OVR;
	  if((OVR<0)||(OVR>99))
	  {
	   cout<<"\n"<<setw(78)<<"Incorrect parameters of overall. Please enter correct overall between 0-99."<<endl;
	   getch();
	   goto OVERALL;
	  }
	  cout<<setw(40)<<"Enter position : ";
	  gets(POS);
}

class Team
{
  private:
     char tname[30];
     char city[25];
     char stadium[30];
     short TeamID;
     short POVR[20];
     short TOVR;
  public:
     int TOVR_Calc();
     int POVR_Calc();
     void Enter();
     void Display()
     {
      cout<<"\n"<<setw(40)<<"Team Name : "<<tname;
      cout<<"\n"<<setw(40)<<"City : "<<city;
      cout<<"\n"<<setw(40)<<"Stadium : "<<stadium;
     }
     void Asgn_TeamID(int RandId)
     {
      TeamID=RandId;
     }
     int Re_TId()
     {
      return TeamID;
     }
     char* Re_TName()
     {
      return tname;
     }
     char* Re_Stadium()
     {
      return stadium;
     }
};
void Team::Enter()
{
      int i;
      TN:
      cout<<"\n"<<setw(40)<<"Enter team name : ";
      gets(tname);
      for(i=0;tname[i]!='\0';i++)
	  {
	   if((tname[i]>=48)&&(tname[i]<=57))
	   {
	    cout<<"\n"<<setw(67)<<"Incorrect team name! Team name cannot contain a number";
	    goto TN;
	   }
	  }
      CITY:
      cout<<setw(40)<<"Enter city : ";
      gets(city);
      for(i=0;city[i]!='\0';i++)
	  {
	   if((city[i]>=48)&&(city[i]<=57))
	   {
	    cout<<"\n"<<setw(69)<<"Incorrect city! City cannot contain a number";
	    goto CITY;
	   }
	  }
      cout<<setw(40)<<"Enter stadium : ";
      gets(stadium);
}
int Team::TOVR_Calc()
{
	  int num,j;
	  TOVR=0;
	  num=POVR_Calc();
	  for(j=0;j<num;j++)
	   TOVR+=POVR[j];
	  TOVR/=num;
	  return (TOVR);
	}
	int Team::POVR_Calc()
	{
	  Player P1;
	  int i=0;
	  ifstream fin("PLAYER.DAT",ios::binary);
	  if(!fin)
	  {
	   cout<<"\n"<<setw(55)<<"'PLAYER.DAT' cannot be opened.";
	   getch();
	   return(0);
	  }
	  while(fin.read((char*)&P1,sizeof(P1)))
	  {
	   if(strcmpi(P1.Re_TName(),tname)==0)
	   {
	    POVR[i]=P1.Re_OVR();
	    i++;
	   }
	  }
	  fin.close();
	  return (i+1);
}