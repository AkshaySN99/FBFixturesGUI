void Intro()
{

	   int midx, midy;
	   int radius = 75;
	   midx = getmaxx() / 2;
	   midy = getmaxy() / 2;
	   setcolor(LIGHTRED);
	   sleep(1);
	   outtextxy(midx-24,midy-130,"WELCOME");
	   outtextxy(midx-4,midy-110,"TO");
	   setcolor(WHITE);
	   sleep(1);
	   outtextxy(midx-27,midy-35,"FOOTBALL");
	   sleep(1);
	   outtextxy(midx-21,midy-5,"LEAGUE");
	   sleep(1);
	   outtextxy(midx-24,midy+25,"PROGRAM");
	   sleep(1);
	   setcolor(LIGHTCYAN);
	   delay(50);
	   do
	   {
		setcolor(LIGHTCYAN);
		circle(midx+1, midy, radius);
		circle(midx+1,midy,radius+1);
		setcolor(YELLOW);
		outtextxy(midx-97,midy+150,"Press any key to continue");
	   }
	   while(!kbhit());
}