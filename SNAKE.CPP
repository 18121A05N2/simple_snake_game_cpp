#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<time.h>
struct node{
	int x,y;
	struct node *next;
};
struct node *head=NULL;
int arr[31][23],food_x,food_y;
void FoodGenerator()
{
	srand(time(0));
	food_x=rand()%30;
	food_y=rand()%22;
	if(arr[food_x*20-10][food_y*20-9]==1)
		FoodGenerator();
}
void create_node(int i,int j)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
	temp->x=i;
	temp->y=j;
	arr[(i+10)/20][(j+9)/20]=1;
}
void freee()
{
	struct node *tmp,*tmp1;
	tmp=head;
	while(tmp->next)
	{
		tmp1=tmp;
		tmp=tmp->next;
	}
	tmp1->next=NULL;
	arr[(tmp->x+10)/20][(tmp->y+9)/20]=0;
	free(tmp);
}
void EndIt()
{
	int i=0,j;
	struct node *tmp;
	tmp=head;
	while(tmp)
	{
		i++;
		tmp=tmp->next;
	}
	cout<<"\n\n\n\t\t\t\t******* GAME OVER *******\n";
	cout<<"\t\t\t\tYour source is : "<<i;
}
int main()
{
	int i=20,j=0,k,n=DETECT,m,i1=10,j1=11,a,b,i2,j2;
	char input;
	struct node *tmp;
	initgraph(&n,&m,"c://turboc3//bgi");
		for(i2=0;i2<31;i2++)
		{
			for(j2=0;j2<23;j2++)
			{
				arr[i2][j2]=0;
			}
		}
	create_node(30,31);arr[2][2]=1;
	create_node(50,31);arr[3][2]=1;
	create_node(70,31);arr[4][2]=1;
	cout<<"hi";
	getch();
	FoodGenerator();

	while(1)
	{
		tmp=head;
		line(0,1,600,1);
		line(0,1,0,441);
		line(0,441,600,441);
		line(600,441,600,0);
		while(tmp)
		{
			a=tmp->x;
			b=tmp->y;
			circle(a,b,10);
			tmp=tmp->next;
		}
		circle(food_x*20-10,food_y*20-9,10);
		if(kbhit())
		{
			input=getch();
			switch(input)
			{
				case 'w':

					i=0;j=-20;
					break;
				case 'a':
					i=-20;j=0;
					break;
				case 's':
					i=20;j=0;
					break;
				case 'z':
					i=0;j=20;
					break;
				case ' ':
					j=99;

			}
		}
		if(j==99)
			break;
		if(arr[(head->x+i+10)/20][(head->y+j+9)/20]==1)
		{
			cleardevice();
			EndIt();
			break;
		}
		create_node(head->x+i,head->y+j);
		if(food_x*20-10==head->x && food_y*20-9==head->y)
		{
			FoodGenerator();
		}
		else
			freee();
		if(head->x<0||head->x>600)
		{
			if(head->x<0)
				head->x=590;
			else
				head->x=10;
		}
		else if(head->y<0||head->y>440)
		{
			if(head->y<0)
				head->y=431;
			else
				head->y=11;
		}
		delay(200);
		cleardevice();

	}
	getch();
}
