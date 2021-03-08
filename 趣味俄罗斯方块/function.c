#include"head.h"
int arr[HEIGHT][WIDTH/2]={0};
fang fn[5][4]={{STARTX,STARTY,0,1,0,2,1,1},{STARTX,STARTY,1,0,-1,0,0,1},{STARTX,STARTY,0,1,0,2,-1,1},{STARTX,STARTY,0,1,1,1,-1,1},
               {STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,},
               {STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,},
               {STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,},
               {STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,},{STARTX,STARTY,}};
//typedef struct fangkuai
//{
//    int mfx;
//    int mfy;
//    int fx2;
//    int fy2;
//    int fx3;
//    int fy3;
//    int fx4;
//    int fy4;
//}fang;
void color(int n)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);
}
void gotoxy(int x,int y)
{
    COORD pos;
    pos.X=x;
    pos.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void menu()
{
    int i;
    color(15);
    gotoxy(45,2);
    printf("趣 味 俄 罗 斯 方 块\n");
    color(F1);
    gotoxy(37,4);
    printf("■");
    gotoxy(37,5);
    printf("■■");
    gotoxy(37,6);
    printf("■");
    color(F2);
    gotoxy(45,5);
    printf("■■");
    gotoxy(47,6);
    printf("■■");
    color(F3);
    gotoxy(55,5);
    printf("■■");
    gotoxy(55,6);
    printf("■■");
    color(F4);
    gotoxy(63,4);
    printf("■");
    gotoxy(63,5);
    printf("■");
    gotoxy(63,6);
    printf("■");
    gotoxy(63,7);
    printf("■");
    color(F5);
    gotoxy(73,5);
    printf("■");
    gotoxy(69,6);
    printf("■■■");
    color(14);
    gotoxy(27,9);
    printf("======================================================");
    for(i=10;i<22;i++)
    {
        gotoxy(26,i);
        printf("‖                                                    ‖");
    }
    gotoxy(27,22);
    printf("======================================================");
    gotoxy(37,13);
    color(4);
    printf("[1]开始游戏          [2]按键说明");
    gotoxy(37,17);
    printf("[3]游戏规则          [4]退出程序");
    gotoxy(42,24);
    color(1);
    printf("请选择[1 2 3 4]:[ ]");
    gotoxy(59,24);
}
int choose()
{
    int tmp;
    while((tmp=getch()))
    {
        if(tmp=='1')
        {
            printf("1");
            Sleep(1000);
            return 1;
        }
        else if(tmp=='2')
        {
            printf("2");
            Sleep(1000);
            return 2;
        }
        else if(tmp=='3')
        {
            printf("3");
            Sleep(1000);
            return 3;
        }
        else if(tmp=='4')
        {
            printf("4");
            Sleep(1000);
            return 4;
        }
        else
        {
            gotoxy(40,25);
            color(12);
            printf("提示:请输入1-4之间的数字");
            color(1);
            gotoxy(59,24);
        }
    }
}
void anjian()
{
    int i;
    color(13);
    gotoxy(49,4);
    printf("按键说明");
    color(14);
    gotoxy(27,6);
    printf("======================================================");
    for(i=7;i<19;i++)
    {
        gotoxy(26,i);
        printf("‖                                                    ‖");
    }
    gotoxy(27,19);
    printf("======================================================");
    color(9);
    gotoxy(29,8);
    printf("tip1：玩家可以通过←→方向键来移动方块");
    color(11);
    gotoxy(29,10);
    printf("tip2：玩家可以通过↑使方块旋转");
    color(14);
    gotoxy(29,12);
    printf("tip3：玩家可以通过↓加速方块下落");
    color(10);
    gotoxy(29,14);
    printf("tip4：按空格键暂停游戏，再按空格键继续");
    color(12);
    gotoxy(29,16);
    printf("tip5：按ESC键退出游戏");
    color(7);
    gotoxy(29,20);
    printf("按任意键返回上一界面");
    getch();
}
void guize()
{
    int i;
    color(13);
    gotoxy(49,4);
    printf("按键说明");
    color(14);
    gotoxy(27,6);
    printf("======================================================");
    for(i=7;i<20;i++)
    {
        gotoxy(26,i);
        printf("‖                                                    ‖");
    }
    gotoxy(27,20);
    printf("======================================================");
    color(12);
    gotoxy(29,8);
    printf("tip1：不同形状的小方块从屏幕上方下落，玩家通过调整");
    gotoxy(35,10);
    printf("方块的位置和方向，它们在屏幕底部拼出完整的一");
    gotoxy(35,12);
    printf("行或几行");
    color(9);
    gotoxy(29,14);
    printf("tip2：每消除一行，积分增加100");
    color(13);
    gotoxy(29,16);
    printf("tip3：每累计1000分，会提升一个等级");
    color(10);
    gotoxy(29,18);
    printf("tip4：提升等级会使方块下落速度加快，游戏难度加大");
    color(7);
    gotoxy(29,21);
    printf("按任意键返回上一界面");
    getch();
}
void game()
{
    st jilu;
    initst(&jilu);
    gamemenu();
    show(&jilu);
    getch();
}
void gamemenu()
{
    int i;
    color(1);
    gotoxy(25,2);
    printf("趣味俄罗斯方块");
    gotoxy(10,4);
    color(12);
    printf("╔═════════════════════════════════════════╗");//└┘│└─┘│
    for(i=0;i<HEIGHT;i++)
    {
        gotoxy(10,i+5);
        printf("║                                         ║");
    }
    gotoxy(10,30);
    printf("╚═════════════════════════════════════════╝");
    color(10);
    gotoxy(16+WIDTH,8);
    printf("══════════");
    color(11);
    printf(" 下一出现方块");
    color(10);
    gotoxy(16+WIDTH,14);
    printf("══════════");
    color(12);
}
void initst(st*p)
{
    p->curi=0;
    p->curj=0;
    p->leval=0;
    p->nexti=0;
    p->nextj=0;
    p->score=0;
    p->speed=0;
}
void show(st*p)
{
    int i,j;
    gotoxy(16+WIDTH,5);
    printf("等级：%d",p->leval);
    gotoxy(16+WIDTH,6);
    printf("分数：%d",p->score);
    gotoxy(16+WIDTH,7);
    printf("速度：%d",p->speed);
    gotoxy(12,5);
    for(i=0;i<HEIGHT;i++)
    {
        for(j=0;j<WIDTH/2;j++)
            printf("■");
        gotoxy(12,6+i);
    }
}
