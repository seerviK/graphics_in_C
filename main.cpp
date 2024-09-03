#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
using namespace std;
int update(int);
void display(int,int,int,int);
char Aname[25],Bname[25],txt[50];
int main()
{
    int gd=DETECT,gm;
    char aa[6]="BIG";
//initgraph(&gd,&gm,NULL);
    initwindow(1000,1000);
    int A=1,B=1,f=1,D;
    char x,ds[10];
//    clrscr();
    cleardevice();
    cout<<"Welcome to snakes and ladders game\n";
    cout<<"Please enter players name\n";
    cout<<"Player A:";cin>>Aname;
    cout<<"Player B:";cin>>Bname;
    strupr(Aname);
    strupr(Bname);
    cout<<"Press 'Q' or 'q' to quit the game\n";
    cout<<"Press any key to throw dice\n";
    cout<<"Press any key to start the game\nAll the best...";
    getch();
//    clrscr();
    cleardevice();
    srand(time(0));
    while(A!=100&&B!=100)
    {
        closegraph();
        display(A,B,f,1);
        x=getch();
        if(x=='q'||x=='Q')
        {
//            clrscr();
            cleardevice();
            closegraph();
            initgraph(&gd,&gm,aa);
            setcolor(RED);
            settextstyle(1,HORIZ_DIR,1);
            outtextxy(250,250,"GAME TERMENATED");
            getch();
            return(0);
        }
        D=(rand()%6)+1;
        itoa(D,ds,10);
        if(f)
        {
            setcolor(CYAN);
            strcpy(txt,Aname);
            strcat(txt," GOT: ");
            outtextxy(460,120,txt);
            outtextxy(590,120,ds);
            getch();
            A=A+D;
            if(A>100)
                A=A-D;
            A=update(A);
        }
        else
        { setcolor(CYAN);
            strcpy(txt,Bname);
            strcat(txt," GOT: ");
            outtextxy(460,120,txt);
            outtextxy(590,120,ds);
            getch();
            B=B+D;
            if(B>100)
                B=B-D;
            B=update(B);
        }
        f=!f;
    }
    if(A==100)
    {
        display(A,B,f,0);
        setcolor(BLUE);
        outtextxy(460,120,Aname);
        outtextxy(460,140,"Won the game");
        getch();
    }
    else
    {
        display(A,B,f,0);
        setcolor(YELLOW);
        outtextxy(460,120,Bname);
        outtextxy(460,140,"Won the game");
        getch();
    }
    getch();
    closegraph();
    return(0);
}
void display(int A,int B,int f,int t)
{
    int gd=DETECT,gm;
//char aa[6]="BIG";
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    int k=100,l=0,i=0,xh1=50,xh2=450,yh1=20,yh2=20,xv1=50,xv2=50,yv1=20,yv2=470;
//draw the bord
    for(;i<11;i++)
    {
        line(xh1,yh1,xh2,yh2);
        line(xv1,yv1,xv2,yv2);
        xv1+=40;
        xv2+=40;
        yh1+=45;
        yh2+=45;
    }
//ladder
    setcolor(YELLOW);
//**************************************
    setlinestyle(0,0,4);
    line(380,445,300,400);//down 9-14
    line(390,435,310,390); //up 9-14
    line(340,422,346,410);//bet1
    line(360,433,366,422);//bet2
    line(320,411,326,399);//bet3
    line(330,416,336,404);
    line(350,428,356,416);
    line(370,439,378,428);
    line(310,406,318,394);
//****************************************
    line(420,130,420,40);//71-91
    line(435,130,435,40);
    line(435,85,420,85);
    line(435,116,420,116);
    line(435,55,420,55);
    line(435,100,420,100);
//****************************************
    line(300,270,238,235);//56-47
    line(305,255,244,220);
    line(265,250,272,236);
    line(282,260,290,246);
    line(247,240,255,226);
    line(274,255,281,240);
    line(256,245,264,231);
//*****************************************
    line(160,315,190,280);//38-44
    line(150,305,176,275);
    line(175,298,164,289);
    line(182,289,169,283);
    line(168,306,157,297);
//******************************************
    line(120,175,195,100);//62-84
    line(110,165,179,96);
    line(144,130,154,140);
    line(127,147,138,158);
    line(136,138,146,149);
    line(162,113,172,123);
    line(153,122,163,132);
    line(171,104,184,112);
    line(118,156,129,166);
//******************************************
    line(185,95,185,175);//64-84
    line(200,95,200,175);
    line(185,105,200,105);
    line(185,120,200,120);
    line(185,135,200,135);
    line(185,150,200,150);
    line(185,165,200,165);
//*******************************************
    line(385,325,415,360);//30-32
    line(400,320,426,350);
    line(400,342,410,333);
    line(392,334,403,324);
    line(408,351,419,342);
//********************************************
    line(345,55,375,90);//89-93
    line(360,50,386,80);
    line(360,72,370,63);
    line(352,64,363,54);
    line(368,81,379,72);
//**********************************************
//**59-65
    int cl=2;
    for(l=0;l<9;l++)
    {
        setcolor(cl);
        ellipse(119+13*l,225,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(119+13*l,225,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    cl=4;
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(231,220-(l*13),0,360,3,6);
        setfillstyle(SOLID_FILL,cl);
        floodfill(231,220-(l*13),cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    ellipse(230,183,0,360,6,3);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(230,183,WHITE);
//***************************************
//*25-28
    cl=2;
    for(l=0;l<10;l++)
    {
        setcolor(cl);
        ellipse(228+13*l,355,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(228+13*l,355,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    setcolor(15);
    ellipse(355,355,0,360,3,6);
    setfillstyle(SOLID_FILL,15);
    floodfill(355,355,15);
    setcolor(15);
//**************************
//********************* 6-17
    cl=2;
    for(l=0;l<7;l++)
    {
        setcolor(cl);
        ellipse(192+13*l,450,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(192+13*l,450,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    for(l=1;l<4;l++)
    {
        setcolor(cl);
        ellipse(187,455-13*l,0,360,3,6);
        setfillstyle(SOLID_FILL,cl);
        floodfill(187,455-13*l,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    setcolor(15);
    ellipse(187,406,0,360,6,3);
    setfillstyle(SOLID_FILL,15);
    floodfill(187,406,15);
    setcolor(15);
//********************************
//**40-42
    cl=2;
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(74+13*l,315,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(74+13*l,315,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    cl=4;
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(109,310-(l*13),0,360,3,6);
        setfillstyle(SOLID_FILL,cl);
        floodfill(109,310-(l*13),cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    ellipse(109,273,0,360,6,3);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(109,273,WHITE);
//*********************************
//**48-52
    cl=2;
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(356+13*l,275,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(356+13*l,275,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    cl=4;
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(390,271-(l*13),0,360,3,6);
        setfillstyle(SOLID_FILL,cl);
        floodfill(390,271-(l*13),cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    ellipse(390,235,0,360,6,3);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(390,235,WHITE);
//*********************************
//**70-73
    cl=2;
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(430,177-13*l,0,360,3,6);
        setfillstyle(SOLID_FILL,cl);
        floodfill(430,177-13*l,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    cl=4;
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(398+13*l,142,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(398+13*l,142,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    ellipse(388,142,0,360,3,6);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(388,142,WHITE);
//**********************************
//*90-94
    cl=4;
    for(l=0;l<9;l++)
    {
        setcolor(cl);
        ellipse(316+13*l,83,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(316+13*l,83,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(312,75-13*l,0,360,3,6);
        setfillstyle(SOLID_FILL,cl);
        floodfill(312,75-13*l,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    ellipse(312,40,0,360,6,3);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(312,40,WHITE);
//*****************************
//*80-83
    cl=2;
    for(l=0;l<6;l++)
    {
        setcolor(cl);
        ellipse(74+13*l,135,0,360,6,3);
        setfillstyle(SOLID_FILL,cl);
        floodfill(74+13*l,135,cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    for(l=0;l<3;l++)
    {
        setcolor(cl);
        ellipse(149,130-(l*13),0,360,3,6);
        setfillstyle(SOLID_FILL,cl);
        floodfill(149,130-(l*13),cl);
        setcolor(15);
        if(cl==2)
            cl=4;
        else
            cl=2;
    }
    ellipse(149,95,0,360,6,3);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(149,95,WHITE);
//*********************************
//putpixel(228,355,WHITE);
//getch();
//closegraph();
//return(0);
//numbering
    char str[5];
    yh1=20,yh2=20,xv1=50,xv2=50;
    for(i=0;i<10;i++)
    {
        if(i%2==0)
        {
            for(l=0;l<10;l++)
            { itoa(k,str,10);
                outtextxy(xh1+3+(l*40),yh1+3,str);
                if(k==A)
                { setcolor(BLUE);
                    circle(65+(40*l),40+(i*45),9);
                    setfillstyle(SOLID_FILL,BLUE);
                    floodfill(65+(40*l),40+(i*45),BLUE);
                    setcolor(15);
                }
                if(k==B)
                { setcolor(YELLOW);
                    circle(65+9+(40*l),40+(i*45),9);
                    setfillstyle(SOLID_FILL,YELLOW);
                    floodfill(65+9+(40*l),40+(i*45),YELLOW);
                    setcolor(15);
                }
                k--;
            }
        }
        else
        {
            for(l=0;l<10;l++)
            {
                itoa(k,str,10);
                outtextxy(xh1+3+360-(l*40),yh1+3,str);
                if(k==A)
                { setcolor(BLUE);
                    circle(65+360-(40*l),40+(i*45),9);
                    setfillstyle(SOLID_FILL,BLUE);
                    floodfill(65+360-(40*l),40+(i*45),BLUE);
                    setcolor(15);
                }
                if(k==B)
                { setcolor(YELLOW);
                    circle(65+9+360-(40*l),40+(i*45),9);
                    setfillstyle(SOLID_FILL,YELLOW);
                    floodfill(65+9+360-(40*l),40+(i*45),YELLOW);
                    setcolor(15);
                }
                k--;
            }
        }
        xv1+=40;
        xv2+=40;
        yh1+=45;
        yh2+=45;
    }
//**********************************
    setcolor(RED);
    outtextxy(53,40,"HOME");
    outtextxy(53,40+9*45,"START");
//***********************************
    setcolor(MAGENTA);
    settextstyle(1,HORIZ_DIR,1);
//    outtextxy(460,10,"COLORS OF PLAYERS");
    settextstyle(0,HORIZ_DIR,0);
    setcolor(GREEN);
    outtextxy(460,40,Aname);
    setcolor(YELLOW);
    outtextxy(550,40,Bname);
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if(f&&t)
    {
        setcolor(BLUE);
        strcpy(txt,"PLAYER ");
        strcat(txt,Aname);
        strcat(txt,"'s TURN");
        outtextxy(460,80,txt);
//gotoxy(460,120);
    }
    else if(t)
    {
        setcolor(YELLOW);
        strcpy(txt,"PLAYER ");
        strcat(txt,Bname);
        strcat(txt,"'s TURN");
        outtextxy(460,80,txt);
//gotoxy(460,120);
    }
}//END OF DISPLAY
int update(int sc)
{
    if(sc==9) return 14;
    if(sc==17) return 6;
    if(sc==30) return 32;
    if(sc==28) return 25;
    if(sc==38) return 44;
    if(sc==47) return 55;
    if(sc==42) return 40;
    if(sc==52) return 48;
    if(sc==65) return 59;
    if(sc==64) return 84;
    if(sc==62) return 84;
    if(sc==71) return 91;
    if(sc==73) return 70;
    if(sc==83) return 80;
    if(sc==89) return 93;
    if(sc==94) return 90;
    return sc;
}