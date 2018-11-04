#ifndef SNAKE1_H_INCLUDED
#define SNAKE1_H_INCLUDED
#include <windows.h>
#define up 'w'
#define down 's'
#define left 'a'
#define right 'd'
#define stop 'b'

void welcomePage();
void gotoxy(int x, int y);
void gotoprint(int x, int y);
void gotodelete(int x, int y);
void CreateMap();
void CreateFood();
void CreatePoison();
void Finish();
void Move();
void Body();
void EatFood();
void EatPoison();
int ClickControl();


char name[30];
int score = 0;
int Judge();
char c = 1;

typedef struct Snake
{
    int x;
    int y;
    struct Snake*next;
}snake;

snake *tail, *head;

struct Food
{
    int x;
    int y;
}food;

struct Poison
{
    int x;
    int y;
}poison;

void welcomePage()
{
    gotoxy(20,10);
    printf("-------------------------------------\n");
    gotoxy(20,20);
    printf("-------------------------------------\n");
    gotoxy(26,12);
    printf("WELCOME TO THE GAME  :)");
    gotoxy(26,17);
    printf("PLEASE ENTER YOUR NAME:");
    scanf("%s",&name);
    system("cls");
}

void gotoxy(int x, int y)

{

	COORD pos;

	HANDLE hOutput;

	pos.X = x;

	pos.Y = y;

	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorPosition(hOutput, pos);

}

void gotoprint(int x, int y)

{

	gotoxy(x, y);

	printf("*");

}

void gotodelete(int x, int y)

{

	gotoxy(x, y);

	printf("  ");

}

void CreateMap()
{
    int i;
    for(i = 0;i < 52;i++)
    {
        gotoprint(i,0);
        gotoprint(i,26);
    }
    for(i = 1;i < 26;i++)
    {
        gotoprint(0,i);
        gotoprint(50,i);
    }
    gotoxy(60,10);
    printf("CURRENT SCORE:%d",score);
    head = (snake*)malloc(sizeof(snake));
	head->x = 16;
	head->y = 15;
	gotoprint(head->x,head->y);
	tail = (snake*)malloc(sizeof(snake));
	snake *p = (snake*)malloc(sizeof(snake));
	snake *q = (snake*)malloc(sizeof(snake));
	head->next = p;
	p->next = q;
	q->next = tail;
	p->x = 16;
	p->y = 16;
	q->x = 16;
	q->y = 17;
	gotoprint(p->x, p->y);
	gotoprint(q->x, q->y);
	tail->next = NULL;
	tail->x = 4;
	tail->y = 2;
}
void CreateFood()
{
    srand((int)time(NULL));
    random:
	food.y = rand() % 24 + 1;
	food.x = rand() % 47+1;
	if(food.x%2!=0)
    {
        food.x += 1;
    }
    snake *judge = head;
    while (1)
	{
	    if (judge->next == NULL)
            break;
		if (food.x == judge->x&&food.y == judge->y)
		{
			goto random;
		}
		judge = judge->next;
	}
    if(poison.x == food.x || poison.y == food.y)
    {
        goto random;
    }
	gotoxy(food.x,food.y);
	printf("@");
}

void CreatePoison()
{
    srand((int)time(NULL));
    random:
	poison.y = rand() % 25+ 1;
	poison.x = rand() % 47+1;
	if(poison.x%2!=0)
    {
        poison.x += 1;
    }
    snake *judge = head;
    while (1)
	{
	    if (judge->next == NULL)
            break;
		if (poison.x == judge->x&&poison.y == judge->y)
		{
			goto random;
		}
		judge = judge->next;
	}
	if(poison.x == food.x || poison.y == food.y)
    {
        goto random;
    }
    gotoxy(poison.x,poison.y);
    printf("#");
}

int ClickControl()
{
	while (1)
	{
		if (Judge()==0) return 0;
		if (_kbhit())
		{
			c = _getch();
		}
		Move();
		EatFood();
		EatPoison();
	}
	return 1;
}

void Move()
{
    int a = head->x;
    int b = head->y;
    snake *p = head;
    while(1)
    {
        if (p->next == NULL) break;
		gotodelete(p->x, p->y);
		p = p->next;
    }
    switch(c)
    {
    case up:
        head->y-=1;
        Body(a,b);
        break;
    case down:
        head->y+=1;
        Body(a,b);
        break;
    case left:
        head->x-=2;
        Body(a,b);
        break;
    case right:
        head->x+=2;
        Body(a,b);
        break;
    case stop:
        system("pause");
        break;
    }
    p = head;
	while (1)
	{
		if (p->next == NULL) break;
		gotoprint(p->x, p->y);
		p = p->next;
	}
	p = head;
    Sleep(200);
}

void Body(int a, int b)
{
    snake *p = head->next;
    int s,e,h,u;
    s = p->x;
    e = p->y;
    p->x=a;
    p->y=b;
    while(p->next->next != NULL)
    {
        h = p->next->x;
        u = p->next->y;
        p->next->x = s;
		p->next->y = e;
		s = h;
		e = u;
		p = p->next;
    }
    p = head->next;
}

void EatPoison()
{
    if(poison.x == head->x && poison.y == head->y)
    {
        CreatePoison();
		snake *p, *q;
		p = head;
		if(p->next->next->next == NULL) exit(0);
        while(p->next->next != NULL)
        {
            q =p;
            p=p->next;
        }
        gotodelete(p->x,p->y);
        q->next = tail;
        score -=10;
        gotoxy(60,10);
        printf("CURRENT SCORE:%d",score);
    }
}

void EatFood()
{
    if(food.x == head->x && food.y == head->y)
    {
        CreateFood();
		snake *_new = (snake*)malloc(sizeof(snake));
		snake *p;
		p = head;
        while(p->next->next != NULL)
        {
            p = p->next;
        }
        p->next = _new;
        _new->next = tail;
        score +=10;
        gotoxy(60,10);
        printf("CURRENT SCORE:%d",score);
    }
}
int Judge()
{
	if (head->x == 0|| head->x == 50|| head->y == 0 || head->y == 25)
	{
		Finish();
		return 0;
	}
	snake *p = head->next;
	while (1)
	{
		if (p->next == NULL)break;
		if (head->x == p->x&&head->y == p->y)
		{
			Finish();
			return 0;
		}
		p = p->next;
	}
	return 1;
}
void Finish()
{
    system("cls");
    gotoxy(20,10);
    printf("-------------------------------------\n");
    gotoxy(20,20);
    printf("-------------------------------------\n");
    gotoxy(26,12);
    printf("GAME OVER!");
    gotoxy(26,17);
    printf("%s'S SCORE IS %d",name, score);
    }
#endif // SNAKE1_H_INCLUDED
