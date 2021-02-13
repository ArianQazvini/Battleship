#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "conio.h"
#include "time.h"
#include "windows.h"
#include "stdbool.h"
#include "stddef.h"
int player1_score;
int player2_score;
int turn_main;
char name1[30];
char name2[30];
struct ship2 {
    int row;
    int col ;
    int place;
    int ship_size;
    int ship_index;
    int vertex_address;
    char flag;         // W /C / E /
    char flag_hide;
    struct ship2 *next;
};
struct set1
{
    struct ship2 *v[1];
    int index;
    struct set1 *next;
};
struct set2
{
    struct ship2 *v[2];
    int index;
    struct set2 *next;
};
struct set3
{
    struct ship2 *v[3];
    int index;
    struct set3 *next;
};
struct set5
{
    struct ship2 *v[5];
    int index;
    struct set5 *next;
};
struct set1 *h1[2];
struct set2 *h2[2];
struct set3 *h3[2];
struct set5 *h5[2];
struct ship2 *filled[2];
struct ship2 *head[2];
struct ship2 *playback[2];
//************************************************************************
//************************************************************************
void create(int player)
{
    if (player==1)
    {
        int count=100;
        for (int i = 9; i >= 0; --i) {
            for (int j = 9; j >=0; --j) {
                struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
                new->place=count;
                count--;
                new->row=j;
                new->col=i;
                new->next=head[0];
                new->flag='W';
                new->flag_hide=' ';
                head[0]=new;
            }
        }
    }

    else
    {
        int  count=100;
        for (int i = 9; i >= 0; --i) {
            for (int j = 9; j >=0; --j) {
                struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
                new->place=count;
                count--;
                new->row=j;
                new->col=i;
                new->next=head[1];
                new->flag='W';
                new->flag_hide=' ';
                head[1]=new;
            }
        }
    }
}
void make_water(int start_row,int start_col,int end_row,int end_col,int size,int player) {
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    if (start_row == end_row && size == 5) {
        while (temp != NULL) {
            if (abs(temp->row - start_row) <= 1 &&((abs(temp->col - start_col) == 2) && abs(temp->col - end_col) == 2))
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            else if (((abs(temp->row - start_row) >= 2) ||(abs(temp->col - start_col) >= 2 && (abs(temp->col - end_col) >= 2))));
            else
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            temp = temp->next;
        }

    }

    else if (start_col == end_col && size == 5) {
        while (temp!=NULL)
        {
            if(abs(temp->col-start_col)<=1 && ((abs(temp->row-start_row)==2)&& abs(temp->row-end_row)==2))
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            else if((abs(temp->col-start_col) >=2) || (abs(temp->row-start_row )>=2 && (abs(temp->row-end_row) >=2)))
            {
            }
            else
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            temp=temp->next;
        }
    }
    else if (start_row == end_row && size == 3) {
        while (temp != NULL) {
            if (((abs(temp->row - start_row) <= 1) &&((abs(temp->col - start_col) == 1) && (abs(temp->col - end_col) == 1))))
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            else if ((abs(temp->row - start_row) >= 2) ||(abs(temp->col - start_col) >= 2 && (abs(temp->col - end_col) >= 2)));
            else {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            temp = temp->next;
        }
    }
    else if (start_col == end_col && size == 3)
    {
        while (temp!=NULL)
        {
            if ((abs(temp->col-start_col)<=1) &&  ((abs(temp->row-start_row)==1)&& (abs(temp->row-end_row)==1)))
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            else if((abs(temp->col-start_col) >=2) || (abs(temp->row-start_row )>=2 && (abs(temp->row-end_row) >=2)));
            else
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }
            temp=temp->next;
        }
    }
    else if (start_row==end_row && size==2)
    {
        while (temp!=NULL)
        {
            if((abs(temp->row-start_row) >=2) || (abs(temp->col-start_col )>=2 && (abs(temp->col-end_col) >=2)))
            {
            }
            else
            {
                if(temp->flag=='S'|| temp->flag=='C');
                else
                {
                    temp->flag_hide='W';
                }
            }

            temp=temp->next;
        }
    }
    else if (start_col==end_col && size == 2) {
        while (temp != NULL) {
            if ((abs(temp->col - start_col) >= 2) ||
                (abs(temp->row - start_row) >= 2 && (abs(temp->row - end_row) >= 2))) {
            } else {
                if (temp->flag == 'S' || temp->flag == 'C');
                else {
                    temp->flag_hide = 'W';
                }
            }
            temp = temp->next;
        }
    }
}
void water1(int r , int c,int player)
{

    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if((abs(temp->row-r)>=2) || (abs(temp->col-c)>=2))
        {
        }
        else
        {
            if(temp->flag=='S'|| temp->flag=='C');
            else
            {
                temp->flag_hide='W';
            }
        }
        temp=temp->next;
    }
}

//********************************************************************
void create_ships(int player)
{
    if(player==1)
    {
        for (int i = 0; i < 1; ++i) { /// 1 ship with 5 lenght
            struct set5 *new=(struct set5 *)malloc(sizeof(struct set5));
            for (int j = 0; j < 5; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=0;
                new->v[j]->ship_size=5;
                new->v[j]->vertex_address=j;
            }
            new->index=0;
            new->next=h5[0];
            h5[0]=new;
        }
        for (int i = 0; i < 2; ++i) { /// 2 ships with 3 lenght
            struct set3 *new=(struct set3 *)malloc(sizeof(struct set3));
            for (int j = 0; j < 3; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=i;
                new->v[j]->ship_size=3;
                new->v[j]->vertex_address=j;
            }
            new->index=i;
            new->next=h3[0];
            h3[0]=new;
        }
        for (int i = 0; i < 3; ++i) { ///3 ships with 2 lenght
            struct set2 *new=(struct set2 *)malloc(sizeof(struct set2));
            for (int j = 0; j < 2; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=i;
                new->v[j]->ship_size=2;
                new->v[j]->vertex_address=j;
            }
            new->index=i;
            new->next=h2[0];
            h2[0]=new;
        }
        for (int i = 0; i < 4; ++i) // 4 ships with 1 lenght
        {
            struct set1 *new=(struct set1 *)malloc(sizeof(struct set1));
            for (int j = 0; j < 1; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=i;
                new->v[j]->ship_size=1;
                new->v[j]->vertex_address=j;
            }
            new->index=i;
            new->next=h1[0];
            h1[0]=new;
        }
    }
    else
    {
        //****************************************************************************************** player 2
        for (int i = 0; i < 1; ++i) { /// 1 ship with 5 lenght
            struct set5 *new=(struct set5 *)malloc(sizeof(struct set5));
            for (int j = 0; j < 5; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=0;
                new->v[j]->ship_size=5;
                new->v[j]->vertex_address=j;
            }
            new->index=0;
            new->next=h5[1];
            h5[1]=new;
        }
        for (int i = 0; i < 2; ++i) { /// 2 ships with 3 lenght
            struct set3 *new=(struct set3 *)malloc(sizeof(struct set3));
            for (int j = 0; j < 3; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=i;
                new->v[j]->ship_size=3;
                new->v[j]->vertex_address=j;
            }
            new->index=i;
            new->next=h3[1];
            h3[1]=new;
        }
        for (int i = 0; i < 3; ++i) { ///3 ships with 2 lenght
            struct set2 *new=(struct set2 *)malloc(sizeof(struct set2));
            for (int j = 0; j < 2; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=i;
                new->v[j]->ship_size=2;
                new->v[j]->vertex_address=j;
            }
            new->index=i;
            new->next=h2[1];
            h2[1]=new;
        }
        for (int i = 0; i < 4; ++i) // 4 ships with 1 lenght
        {
            struct set1 *new=(struct set1 *)malloc(sizeof(struct set1));
            for (int j = 0; j < 1; ++j) {
                new->v[j]=(struct ship2 *)malloc(sizeof(struct ship2));
                new->v[j]->flag='S';
                new->v[j]->ship_index=i;
                new->v[j]->ship_size=1;
                new->v[j]->vertex_address=j;
            }
            new->index=i;
            new->next=h1[1];
            h1[1]=new;
        }
    }
}
//*******************************************************************************
void add_end(int r,int c,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=filled[0];

        if(temp==NULL)
        {
            struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
            new->place=(c*10)+(r+1);
            new->row=r;
            new->col=c;
            new->next=temp;
            temp=new;
            filled[0]=temp;
        }
        else
        {
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
            new->place=(c*10)+(r+1);
            new->row=r;
            new->col=c;
            new->next=temp->next;
            temp->next=new;
        }
    }
    else
    {
        temp=filled[1];

        if(temp==NULL)
        {
            struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
            new->place=(c*10)+(r+1);
            new->row=r;
            new->col=c;
            new->next=temp;
            temp=new;
            filled[1]=temp;
        }
        else
        {
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
            new->place=(c*10)+(r+1);
            new->row=r;
            new->col=c;
            new->next=temp->next;
            temp->next=new;
        }
    }

}
//********************************************************************************
void reserve1(int c,int r,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if((abs(temp->row-r)>=2) || (abs(temp->col-c)>=2))
        {
        }
        else
        {

            add_end(temp->row,temp->col,player);


        }
        temp=temp->next;
    }
}
void reserve_horizontal2(int r,int c1,int c2,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if((abs(temp->row-r) >=2) || (abs(temp->col-c1 )>=2 && (abs(temp->col-c2) >=2)))
        {
        }
        else
        {
            add_end(temp->row,temp->col,player);
        }
        temp=temp->next;
    }
}
void reserve_vertical2(int c,int r1,int r2,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if((abs(temp->col-c) >=2) || (abs(temp->row-r1 )>=2 && (abs(temp->row-r2) >=2)))
        {
        }
        else
        {
            add_end(temp->row,temp->col,player);
        }
        temp=temp->next;
    }
}
void reserve_horizontal5(int r,int start_col,int end_col,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if(abs(temp->row-r)<=1 && ((abs(temp->col-start_col)==2)&& abs(temp->col-end_col)==2))
        {
            add_end(temp->row,temp->col,player);
        }
        else if((abs(temp->row-r) >=2) || (abs(temp->col-start_col )>=2 && (abs(temp->col-end_col) >=2)))
        {
        }
        else
        {
            add_end(temp->row,temp->col,player);
        }
        temp=temp->next;
    }
}
void reserve_vertical5(int c,int start_row,int end_row,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if(abs(temp->col-c)<=1 && ((abs(temp->row-start_row)==2)&& abs(temp->row-end_row)==2))
        {
            add_end(temp->row,temp->col,player);
        }
        else if((abs(temp->col-c) >=2) || (abs(temp->row-start_row )>=2 && (abs(temp->row-end_row) >=2)))
        {
        }
        else
        {
            add_end(temp->row,temp->col,player);
        }
        temp=temp->next;
    }
}
void reserve_horizontal3(int r,int start_col,int end_col,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if((abs(temp->row-r)<=1) && ((abs(temp->col-start_col)==1) && (abs(temp->col-end_col)==1)))
        {
            add_end(temp->row,temp->col,player);
        }
        else if((abs(temp->row-r) >=2) || (abs(temp->col-start_col )>=2 && (abs(temp->col-end_col) >=2)))
        {
        }
        else
        {
            add_end(temp->row,temp->col,player);
        }
        temp=temp->next;
    }
}
void reserve_vertical3(int c,int start_row,int end_row,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while (temp!=NULL)
    {
        if((abs(temp->col-c)<=1) &&      ((abs(temp->row-start_row)==1)&& (abs(temp->row-end_row)==1)))
        {
            add_end(temp->row,temp->col,player);
        }
        else if((abs(temp->col-c) >=2) || (abs(temp->row-start_row )>=2 && (abs(temp->row-end_row) >=2)))
        {

        }
        else
        {
            add_end(temp->row,temp->col,player);
        }
        temp=temp->next;
    }
}
//*******************************************************
int func(int place,int player)
{
    struct ship2 *temp;
    if(player==1)
    {
        temp=filled[0];
    }
    else
    {
        temp=filled[1];
    }
    while (temp!=NULL)
    {
        if(temp->place==place)
        {
            return 0;
        }
        temp=temp->next;
    }
    return 1;
}
//************************************************************
void  put_ship_link(int row1,int col1,int player)
{
    int sum;
    sum=col1*10+(row1+1);
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else
    {
        temp=head[1];
    }
    while(temp != NULL) {
        if (temp->place==sum ){
            temp->row=row1;
            temp->col=col1;
            temp->flag='S';
            break;
        }
        temp = temp->next;
    }
}
void fix(int ship_index,int ship_size,int place,int player,int vertex_address)
{
    struct ship2 *p;
    if(player==1)
    {
        p=head[0];
    }
    else
    {
        p=head[1];
    }
    while (p->place!=place)
    {
        p=p->next;
    }
    p->ship_size=ship_size;
    p->ship_index=ship_index;
    p->vertex_address=vertex_address;
    //  p->flag='S';
}
//***********************************************************************
void fill5(int row,int col,int ship_i,int vertex_i,int player)
{
    struct set5 *temp;
    if(player==1)
    {
        temp=h5[0];
    }
    else
    {
        temp=h5[1];
    }
    while (temp->index!=ship_i)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    temp->v[vertex_i]->row=row;
    temp->v[vertex_i]->col=col;
    temp->v[vertex_i]->place=(col*10)+(row+1);
    fix(ship_i,5,temp->v[vertex_i]->place,player,vertex_i);
}
void fill3(int row,int col,int ship_i,int vertex_i,int player)
{
    struct set3 *temp;
    if(player==1)
    {
        temp=h3[0];
    }
    else
    {
        temp=h3[1];
    }
    while (temp->index!=ship_i)
    {
        temp=temp->next;
    }
    temp->v[vertex_i]->row=row;
    temp->v[vertex_i]->col=col;
    temp->v[vertex_i]->place=(col*10)+(row+1);
    fix(ship_i,3,temp->v[vertex_i]->place,player,vertex_i);
}
void fill2(int row,int col,int ship_i,int vertex_i,int player)
{
    struct set2 *temp;
    if(player==1)
    {
        temp=h2[0];
    }
    else
    {
        temp=h2[1];
    }
    while (temp->index!=ship_i)
    {
        temp=temp->next;
    }
    temp->v[vertex_i]->row=row;
    temp->v[vertex_i]->col=col;
    temp->v[vertex_i]->place=(col*10)+(row+1);
    fix(ship_i,2,temp->v[vertex_i]->place,player,vertex_i);
}
void fill1(int row,int col,int ship_i,int vertex_i,int player)
{
    struct set1 *temp;
    if(player==1)
    {
        temp=h1[0];
    }
    else
    {
        temp=h1[1];
    }
    while (temp->index!=ship_i)
    {
        temp=temp->next;
    }
    temp->v[vertex_i]->row=row;
    temp->v[vertex_i]->col=col;
    temp->v[vertex_i]->place=(col*10)+(row+1);
    fix(ship_i,1,temp->v[vertex_i]->place,player,vertex_i);
}

//********************************************************
//

void show_map_link(char kind[],int player)
{

    int i,j;
    struct ship2 *temp;
    if(player==1)
    {
        temp=head[0];
    }
    else if(player==2)
    {
        temp=head[1];
    }
    printf("\n   a: |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |\n");
    for (j = 0; j <10 ; ++j) {
        printf("b[%d]: ",j);
        for (i = 0; i <10; ++i)  {
            if (kind[0]=='r')
            {
                printf("|  %c  ",temp->flag);
            }
            else if  (kind[0]=='h')
            {
                printf("|  %c  ",temp->flag_hide );
            }
            temp = temp->next;
        }
        printf("|\n");
    }
}
int possible(int row,int col,int size)
{
    int place=(col*10)+row+1;
    if(size==5)
    {
        int arr[4]={0};
        if(row<4)
        {
            arr[0]=place+4;
        }
        else if(row>=6)
        {
            arr[0]=place-4;
        }
        else
        {
            arr[0]=place+4;
            arr[1]=place-4;
        }
        if(col<4)
        {
            arr[2]=place+40;
        }
        else if(col>=6)
        {
            arr[2]=place-40;
        }
        else
        {
            arr[2]=place+40;
            arr[3]=place-40;
        }
        int x=0;
        for (int i = 0; i < 4; ++i) {
            if(arr[i]!=0)
            {
                x++;
            }
        }
        int temp[x];
        int z=0;
        for (int i = 0; i < 4; ++i) {
            if(arr[i]!=0)
            {
                temp[z]=arr[i];
                z++;
            }
        }
        return temp[rand()%x];
    }
    else if(size==3)
    {
        int arr[4]={0};
        if(row<2)
        {
            arr[0]=place+2;
        }
        else if(row>=8)
        {
            arr[0]=place-2;
        }
        else
        {
            arr[0]=place+2;
            arr[1]=place-2;
        }
        if(col<2)
        {
            arr[2]=place+20;
        }
        else if(col>=8)
        {
            arr[2]=place-20;
        }
        else
        {
            arr[2]=place+20;
            arr[3]=place-20;
        }
        int x=0;
        for (int i = 0; i < 4; ++i) {
            if(arr[i]!=0)
            {
                x++;
            }
        }
        int temp[x];
        int z=0;
        for (int i = 0; i < 4; ++i) {
            if(arr[i]!=0)
            {
                temp[z]=arr[i];
                z++;
            }
        }
        return temp[rand()%x];
    }
    else if(size==2)
    {
        int arr[4]={0};
        if(row<1)
        {
            arr[0]=place+1;
        }
        else if(row>=9)
        {
            arr[0]=place-1;
        }
        else
        {
            arr[0]=place+1;
            arr[1]=place-1;
        }
        if(col<1)
        {
            arr[2]=place+10;
        }
        else if(col>=9)
        {
            arr[2]=place-10;
        }
        else
        {
            arr[2]=place+10;
            arr[3]=place-10;
        }
        int x=0;
        for (int i = 0; i < 4; ++i) {
            if(arr[i]!=0)
            {
                x++;
            }
        }
        int temp[x];
        int z=0;
        for (int i = 0; i < 4; ++i) {
            if(arr[i]!=0)
            {
                temp[z]=arr[i];
                z++;
            }
        }
        return temp[rand()%x];
    }

}
void place_ship(int player,char kind)
{
    if(kind=='M')
    {
        int i, j;
        show_map_link("real",player);
        printf("1 ship with 5 lenght:\n");
        int start_row5;
        int start_col5;
        int end_row5;
        int end_col5;
        int count=0;
        for (i = 0; i <1 ; ++i)
        {

            printf("select start vertex a and b :");
            scanf("%d%d",&start_row5 , &start_col5);
            int place_start=(start_col5)*10+(start_row5+1);
            printf("select end vertex a and b :");
            scanf("%d%d",&end_row5 , &end_col5);
            int place_end=(end_col5)*10+(end_row5+1);
            if(start_row5==end_row5 && start_col5== end_col5)
            {
                i--;
                continue;
            }
            if(start_row5!=end_row5 && start_col5!=end_col5)
            {
                i--;
                continue;
            }
            if(abs(place_start-place_end)==4)
            {
                reserve_vertical5(start_col5,start_row5,end_row5,player);
                if(place_start>place_end)
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(start_row5,start_col5,player);
                        fill5(start_row5,start_col5,0,count,player);
                        count++;
                        start_row5--;
                        place_start--;
                    }
                    put_ship_link(end_row5,end_col5,player);
                    fill5(end_row5,end_col5,0,4,player);
                    system("cls");
                    show_map_link("real",player);
                }
                else
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(end_row5,end_col5,player);
                        fill5(end_row5,end_col5,0,count,player);
                        count++;
                        end_row5--;
                        place_end--;
                    }
                    put_ship_link(start_row5,start_col5,player);
                    fill5(start_row5,start_col5,0,4,player);
                    system("cls");
                    show_map_link("real",player);
                }
            }
            else if(abs(place_start-place_end)==40)
            {
                reserve_horizontal5(start_row5,start_col5,end_col5,player);
                if(place_start>place_end)
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(start_row5,start_col5,player);
                        fill5(start_row5,start_col5,i,count,player);
                        count++;
                        start_col5--;
                        place_start=place_start-10;
                    }
                    put_ship_link(end_row5,end_col5,player);
                    fill5(end_row5,end_col5,i,4,player);
                    system("cls");
                    show_map_link("real",player);
                }
                else
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(end_row5,end_col5,player);
                        fill5(end_row5,end_col5,i,count,player);
                        count++;
                        end_col5--;
                        place_end=place_end-10;
                    }
                    put_ship_link(start_row5,start_col5,player);
                    fill5(start_row5,start_col5,i,4,player);
                    system("cls");
                    show_map_link("real",player);
                }
            }
            else
            {
                printf("NOT VALID TRY AGAIN\n");
                i--;
            }

        }

        printf("-------------------------------------------------\n");
        printf(" 3 ships with 2 lenght :\n");
        int r1,c1;
        int r2,c2;
        for (j = 0; j < 3 ; ++j)
        {

            printf("for ship[%d]//select first vertex a,b:",j+1);
            scanf("%d %d",&r1,&c1);
            int p1=(c1*10+(r1+1));
            if(func(p1,player)==0)
            {
                while (func(p1,player)==0)
                {
                    printf("NOT VALID TRY AGAIN\n");
                    printf("for ship:[%d]//select first vertex a,b :",j+1);
                    scanf("%d %d",&r1,&c1);
                    p1=(c1*10+(r1+1));
                }
            }
            printf("for ship:[%d]//select second vertex a,b :",j+1);
            scanf("%d %d",&r2,&c2);
            int p2=(c2*10+(r2+1));
            if(func(p2,player)==0)
            {
                while (func(p2,player)==0)
                {
                    printf("NOT VALID TRY AGAIN\n");
                    printf("for ship:[%d]//select second vertex a,b :",j+1);
                    scanf("%d %d",&r2,&c2);
                    p2=(c2*10+(r2+1));
                }
            }
            if(r1==r2 && c1==c2)
            {
                j--;
                continue;
            }
            if(r1!=r2 && c1 !=c2)
            {
                j--;
                continue;
            }
            if ((abs(p1-p2)==10))
            {
                reserve_horizontal2(r1,c1,c2,player);
                put_ship_link(r1,c1,player);
                fill2(r1,c1,j,0,player);
                system("cls");
                show_map_link("real",player);
                put_ship_link(r2,c2,player);
                fill2(r2,c2,j,1,player);
                system("cls");
                show_map_link("real",player);

            }
            else if((abs(p1-p2)==1))
            {
                reserve_vertical2(c1,r1,r2,player);
                put_ship_link(r1,c1,player);
                fill2(r1,c1,j,0,player);
                system("cls");
                show_map_link("real",player);
                put_ship_link(r2,c2,player);
                fill2(r2,c2,j,1,player);
                system("cls");
                show_map_link("real",player);
            }
            else
            {
                printf("WRONG COMBINATION\n");
                j--;
            }
        }


////
        printf("--------------------------------------------\n");
        printf("\n 2 ships with 3 lenght\n :");
        int start_row3;
        int start_col3;
        int end_row3;
        int end_col3;
        for (j = 0; j < 2 ; ++j)
        {
            int count3=0;
            printf("for ship[%d]//select start vertex a,b:",j+1);
            scanf("%d %d",&start_row3,&start_col3);
            int p1=(start_col3*10)+(start_row3+1);
            if(func(p1,player)==0)
            {
                while (func(p1,player)==0)
                {
                    printf("NOT VALID TRY AGAIN\n");
                    printf("for ship:[%d]//select start vertex a,b :",j+1);
                    scanf("%d %d",&start_row3,&start_col3);
                    p1=(start_col3*10+(start_row3+1));
                }
            }
            printf("for ship:[%d]//select end vertex a,b :",j+1);
            scanf("%d %d",&end_row3,&end_col3);
            int p2=(end_col3*10+(end_row3+1));
            if(func(p2,player)==0)
            {
                while (func(p2,player)==0)
                {
                    printf("NOT VALID TRY AGAIN\n");
                    printf("for ship:[%d]//select second vertex a,b :",j+1);
                    scanf("%d %d",&end_row3,&end_col3);
                    p2=(end_col3*10+(end_row3+1));
                }
            }
            if(start_row3==end_row3 && start_col3==end_col3)
            {
                j--;
                continue;
            }
            if(start_row3!=end_row3 && start_col3 !=end_col3)
            {
                j--;
                continue;
            }
            if(abs(p1-p2)==20)
            {
                reserve_horizontal3(start_row3,start_col3,end_col3,player);
                if(p1>p2)
                {
                    while (p1!=p2)
                    {
                        put_ship_link(start_row3,start_col3,player);
                        fill3(start_row3,start_col3,j,count3,player);
                        count3++;
                        start_col3--;
                        p1=p1-10;
                    }
                    put_ship_link(end_row3,end_col3,player);
                    fill3(end_row3,end_col3,j,2,player);
                    system("cls");
                    show_map_link("real",player);
                }
                else
                {
                    while (p1!=p2)
                    {
                        put_ship_link(end_row3,end_col3,player);
                        fill3(end_row3,end_col3,j,count3,player);
                        count3++;
                        end_col3--;
                        p2=p2-10;
                    }
                    put_ship_link(start_row3,start_col3,player);
                    fill3(start_row3,start_col3,j,2,player);
                    system("cls");
                    show_map_link("real",player);
                }


            }
            else if((abs(p1-p2)==2))
            {
                reserve_vertical3(start_col3,start_row3,end_row3,player);
                if(p1>p2)
                {
                    while (p1!=p2)
                    {
                        put_ship_link(start_row3,start_col3,player);
                        fill3(start_row3,start_col3,j,count3,player);
                        count3++;
                        start_row3--;
                        p1--;
                    }
                    put_ship_link(end_row3,end_col3,player);
                    fill3(end_row3,end_col3,j,2,player);
                    system("cls");
                    show_map_link("real",player);
                }
                else
                {
                    while (p1!=p2)
                    {
                        put_ship_link(end_row3,end_col3,player);
                        fill3(end_row3,end_col3,j,count3,player);
                        count3++;
                        end_row3--;
                        p2--;
                    }
                    put_ship_link(start_row3,start_col3,player);
                    fill3(start_row3,start_col3,j,2,player);
                    system("cls");
                    show_map_link("real",player);
                }
            }
            else
            {
                printf("WRONG COMBINATION\n");
                j--;
            }
        }


        printf("----------------------------------------------\n");
        printf("4 ships with 1 lenght:\n");
        int row1;
        int col1;
        for (j = 0; j < 4 ; ++j)
        {
            printf("select a,b for ship [%d]:",j+1);
            scanf("%d %d",&row1,&col1);

            int place=(col1)*10+(row1+1);
            if(func(place,player)==1)
            {
                reserve1(col1,row1,player);
                put_ship_link(row1,col1,player);
                fill1(row1,col1,j,0,player);
                system("cls");
                show_map_link("real",player);
            }
            else
            {
                printf("NOT valid TRY AGAIN\n");
                j--;
            }

        }
    }
    else if(kind=='A')
    {
        int i, j;
//        show_map_link("real",player);
//        printf("1 ship with 5 lenght:\n");
        int start_row5;
        int start_col5;
        int end_row5;
        int end_col5;
        int count=0;
        for (i = 0; i <1 ; ++i)
        {

            //    printf("select start vertex a and b :");
            //   scanf("%d%d",&start_row5 , &start_col5);
            start_row5= rand()%10;
            start_col5= rand()%10;
            int help=possible(start_row5,start_col5,5);
            if(help==100)
            {
                end_row5=9;
                end_col5=9;
            }
            else if(help==10)
            {
                end_row5=9;
                end_col5=0;
            }
            else if(help<=9)
            {
                end_row5=help-1;
                end_col5=0;
            }
            else
            {
                end_row5=(help%10)-1;
                end_col5=(help/10);
            }
            int place_start=(start_col5)*10+(start_row5+1);
//            printf("select end vertex a and b :");
//            scanf("%d%d",&end_row5 , &end_col5);
            if(start_row5==end_row5 && start_col5== end_col5)
            {
                i--;
                continue;
            }
            if(start_row5!=end_row5 && start_col5!=end_col5)
            {
                i--;
                continue;
            }
            int place_end=(end_col5)*10+(end_row5+1);
            if(abs(place_start-place_end)==4)
            {
                reserve_vertical5(start_col5,start_row5,end_row5,player);
                if(place_start>place_end)
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(start_row5,start_col5,player);
                        fill5(start_row5,start_col5,0,count,player);
                        count++;
                        start_row5--;
                        place_start--;
                    }
                    put_ship_link(end_row5,end_col5,player);
                    fill5(end_row5,end_col5,0,4,player);
//                    system("cls");
//                    show_map_link("real",player);
                }
                else
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(end_row5,end_col5,player);
                        fill5(end_row5,end_col5,0,count,player);
                        count++;
                        end_row5--;
                        place_end--;
                    }
                    put_ship_link(start_row5,start_col5,player);
                    fill5(start_row5,start_col5,0,4,player);
//                    system("cls");
//                    show_map_link("real",player);
                }
            }
            else if(abs(place_start-place_end)==40)
            {
                reserve_horizontal5(start_row5,start_col5,end_col5,player);
                if(place_start>place_end)
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(start_row5,start_col5,player);
                        fill5(start_row5,start_col5,i,count,player);
                        count++;
                        start_col5--;
                        place_start=place_start-10;
                    }
                    put_ship_link(end_row5,end_col5,player);
                    fill5(end_row5,end_col5,i,4,player);
//                    system("cls");
//                    show_map_link("real",player);
                }
                else
                {
                    while (place_start!=place_end)
                    {
                        put_ship_link(end_row5,end_col5,player);
                        fill5(end_row5,end_col5,i,count,player);
                        count++;
                        end_col5--;
                        place_end=place_end-10;
                    }
                    put_ship_link(start_row5,start_col5,player);
                    fill5(start_row5,start_col5,i,4,player);
//                    system("cls");
//                    show_map_link("real",player);
                }
            }
            else
            {
                //  printf("NOT VALID TRY AGAIN\n");
                i--;
            }

        }

//        printf("-------------------------------------------------\n");
//        printf(" 3 ships with 2 lenght :\n");
        int r1,c1;
        int r2,c2;
        for (j = 0; j < 3 ; ++j)
        {

//            printf("for ship[%d]//select first vertex a,b:",j+1);
//            scanf("%d %d",&r1,&c1);
            r1=rand()%10;
            c1=rand()%10;
            int p1=(c1*10+(r1+1));
            if(func(p1,player)==0)
            {
                while (func(p1,player)==0)
                {
//                    printf("NOT VALID TRY AGAIN\n");
//                    printf("for ship:[%d]//select first vertex a,b :",j+1);
//                    scanf("%d %d",&r1,&c1);
                    r1=rand()%10;
                    c1=rand()%10;
                    p1=(c1*10+(r1+1));
                }
            }
//            printf("for ship:[%d]//select second vertex a,b :",j+1);
//            scanf("%d %d",&r2,&c2);
            int help=possible(r1,c1,3);
            if(help==100)
            {
                r2=9;
                c2=9;
            }
            else if(help==10)
            {
                r2=9;
                c2=0;
            }
            else if(help<=9)
            {
                r2=help-1;
                c2=0;
            }
            else
            {
                r2=(help%10)-1;
                c2=(help/10);
            }
            int p2=(c2*10+(r2+1));
            if(func(p2,player)==0)
            {
                while (func(p2,player)==0)
                {
//                    printf("NOT VALID TRY AGAIN\n");
//                    printf("for ship:[%d]//select second vertex a,b :",j+1);
//                    scanf("%d %d",&r2,&c2);
                    int help2=possible(r1,c1,2);
                    if(help2==100)
                    {
                        r2=9;
                        c2=9;
                    }
                    else if(help2==10)
                    {
                        r2=9;
                        c2=0;
                    }
                    else if(help2<=9)
                    {
                        r2=help2-1;
                        c2=0;
                    }
                    else
                    {
                        r2=(help2%10)-1;
                        c2=(help2/10);
                    }
                    p2=(c2*10+(r2+1));
                }
            }
            if(r1==r2 && c1==c2)
            {
                j--;
                continue;
            }
            if(r1!=r2 && c1 !=c2)
            {
                j--;
                continue;
            }
            if ((abs(p1-p2)==10))
            {
                reserve_horizontal2(r1,c1,c2,player);
                put_ship_link(r1,c1,player);
                fill2(r1,c1,j,0,player);
//                system("cls");
//                show_map_link("real",player);
                put_ship_link(r2,c2,player);
                fill2(r2,c2,j,1,player);
//                system("cls");
//                show_map_link("real",player);

            }
            else if((abs(p1-p2)==1))
            {
                reserve_vertical2(c1,r1,r2,player);
                put_ship_link(r1,c1,player);
                fill2(r1,c1,j,0,player);
//                system("cls");
//                show_map_link("real",player);
                put_ship_link(r2,c2,player);
                fill2(r2,c2,j,1,player);
//                system("cls");
//                show_map_link("real",player);
            }
            else
            {
//                printf("WRONG COMBINATION\n");
                j--;
            }
        }


////
//        printf("--------------------------------------------\n");
//        printf("\n 2 ships with 3 lenght\n :");
        int start_row3;
        int start_col3;
        int end_row3;
        int end_col3;
        for (j = 0; j < 2 ; ++j)
        {
            int count3=0;
//            printf("for ship[%d]//select start vertex a,b:",j+1);
//            scanf("%d %d",&start_row3,&start_col3);
            start_row3=rand()%10;
            start_col3=rand()%10;
            int p1=(start_col3*10)+(start_row3+1);
            if(func(p1,player)==0)
            {
                while (func(p1,player)==0)
                {
//                    printf("NOT VALID TRY AGAIN\n");
//                    printf("for ship:[%d]//select start vertex a,b :",j+1);
//                    scanf("%d %d",&start_row3,&start_col3);
                    start_row3=rand()%10;
                    start_col3=rand()%10;
                    p1=(start_col3*10+(start_row3+1));
                }
            }
//            printf("for ship:[%d]//select end vertex a,b :",j+1);
//            scanf("%d %d",&end_row3,&end_col3);
            int help=possible(start_row3,start_col3,3);
            if(help==100)
            {
                end_row3=9;
                end_col3=9;
            }
            else if(help==10)
            {
                end_row3=9;
                end_col3=0;
            }
            else if(help<=9)
            {
                end_row3=help-1;
                end_col3=0;
            }
            else
            {
                end_row3=(help%10)-1;
                end_col3=(help/10);
            }
            int p2=(end_col3*10+(end_row3+1));
            if(func(p2,player)==0)
            {
                while (func(p2,player)==0)
                {
//                    printf("NOT VALID TRY AGAIN\n");
//                    printf("for ship:[%d]//select second vertex a,b :",j+1);
//                    scanf("%d %d",&end_row3,&end_col3);
                    int help1=possible(start_row3,start_col3,3);
                    if(help1==100)
                    {
                        end_row3=9;
                        end_col3=9;
                    }
                    else if(help1==10)
                    {
                        end_row3=9;
                        end_col3=0;
                    }
                    else if(help1<=9)
                    {
                        end_row3=help1-1;
                        end_col3=0;
                    }
                    else
                    {
                        end_row3=(help1%10)-1;
                        end_col3=(help1/10);
                    }
                    p2=(end_col3*10+(end_row3+1));
                }
            }
            if(start_row3==end_row3 && start_col3==end_col3)
            {
                j--;
                continue;
            }
            if(start_row3!=end_row3 && start_col3 !=end_col3)
            {
                j--;
                continue;
            }
            if(abs(p1-p2)==20)
            {
                reserve_horizontal3(start_row3,start_col3,end_col3,player);
                if(p1>p2)
                {
                    while (p1!=p2)
                    {
                        put_ship_link(start_row3,start_col3,player);
                        fill3(start_row3,start_col3,j,count3,player);
                        count3++;
                        start_col3--;
                        p1=p1-10;
                    }
                    put_ship_link(end_row3,end_col3,player);
                    fill3(end_row3,end_col3,j,2,player);
//                    system("cls");
//                    show_map_link("real",player);
                }
                else
                {
                    while (p1!=p2)
                    {
                        put_ship_link(end_row3,end_col3,player);
                        fill3(end_row3,end_col3,j,count3,player);
                        count3++;
                        end_col3--;
                        p2=p2-10;
                    }
                    put_ship_link(start_row3,start_col3,player);
                    fill3(start_row3,start_col3,j,2,player);
//                    system("cls");
//                    show_map_link("real",player);
                }


            }
            else if((abs(p1-p2)==2))
            {
                reserve_vertical3(start_col3,start_row3,end_row3,player);
                if(p1>p2)
                {
                    while (p1!=p2)
                    {
                        put_ship_link(start_row3,start_col3,player);
                        fill3(start_row3,start_col3,j,count3,player);
                        count3++;
                        start_row3--;
                        p1--;
                    }
                    put_ship_link(end_row3,end_col3,player);
                    fill3(end_row3,end_col3,j,2,player);
//                    system("cls");
//                    show_map_link("real",player);
                }
                else
                {
                    while (p1!=p2)
                    {
                        put_ship_link(end_row3,end_col3,player);
                        fill3(end_row3,end_col3,j,count3,player);
                        count3++;
                        end_row3--;
                        p2--;
                    }
                    put_ship_link(start_row3,start_col3,player);
                    fill3(start_row3,start_col3,j,2,player);
//                    system("cls");
//                    show_map_link("real",player);
                }
            }
            else
            {
//                printf("WRONG COMBINATION\n");
                j--;
            }
        }


//        printf("----------------------------------------------\n");
//        printf("4 ships with 1 lenght:\n");
        int row1;
        int col1;
        for (j = 0; j < 4 ; ++j)
        {
//            printf("select a,b for ship [%d]:",j+1);
//            scanf("%d %d",&row1,&col1);
            row1=rand()%10;
            col1=rand()%10;
            int place=(col1)*10+(row1+1);
            if(func(place,player)==1)
            {
                reserve1(col1,row1,player);
                put_ship_link(row1,col1,player);
                fill1(row1,col1,j,0,player);
//                system("cls");
//                show_map_link("real",player);
            }
            else
            {
//                printf("NOT valid TRY AGAIN\n");
                j--;
            }

        }
    }

}
int menu()
{
    int n;
    printf("1-play with a friend\n");
    printf("2-play with bot\n");
    printf("3-Load Game\n");
    printf("4-Load Last Game\n");
    printf("5-Score board\n");
    printf("6-MAP THEME\n");
    printf("7-EXIT\n");
    scanf("%d",&n);
    return n;
}

void find(int row , int col,int ship_size,int ship_index,int player)
{

    struct ship2 *p;
    if(player==1)
    {
        p=head[0];
        if(ship_size==5)
        {
            struct set5 *temp5=h5[0];
            if (temp5!=NULL)
            {
                // temp5=temp5->next;
                for (int i = 0; i < 5; ++i) {
                    if(temp5->v[i]->row==row && temp5->v[i]->col==col )
                    {
                        temp5->v[i]->flag_hide='E';
                        temp5->v[i]->flag='E';
                        while (p->place!=temp5->v[i]->place)
                        {
                            p=p->next;
                        }
                        p->flag_hide='E';
                        p->flag='E';
                    }
                }
            }
        }
        else if(ship_size==3)
        {
            struct set3 *temp3=h3[0];
            while (temp3->index!=ship_index)
            {
                temp3=temp3->next;
            }
            for (int i = 0; i < 3; ++i) {
                if(temp3->v[i]->row==row && temp3->v[i]->col==col)
                {
                    temp3->v[i]->flag_hide='E';
                    temp3->v[i]->flag='E';
                    while (p->place!=temp3->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='E';
                    p->flag='E';
                }
                p=head[0];
            }
        }
        else if(ship_size==2)
        {
            struct set2 *temp2=h2[0];
            while (temp2->index!=ship_index)
            {
                temp2=temp2->next;
            }
            for (int i = 0; i < 2; ++i) {
                if(temp2->v[i]->row==row && temp2->v[i]->col==col)
                {
                    temp2->v[i]->flag_hide='E';
                    temp2->v[i]->flag='E';
                    while (p->place!=temp2->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='E';
                    p->flag='E';
                }
                p=head[0];
            }
        }
        if(ship_size==1)
        {
            struct set1 *temp1=h1[0];
            while (temp1->index!=ship_index)
            {
                temp1=temp1->next;
            }
            for (int i = 0; i < 1; ++i) {
                if(temp1->v[i]->row==row && temp1->v[i]->col==col)
                {
                    temp1->v[i]->flag_hide='E';
                    temp1->v[i]->flag='E';
                    while (p->place!=temp1->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='E';
                    p->flag='E';
                }
                p=head[0];
            }
        }
    }
    else
    {

        p=head[1];
        if(ship_size==5)
        {
            struct set5 *temp5=h5[1];
            if (temp5!=NULL)
            {
                // temp5=temp5->next;
                for (int i = 0; i < 5; ++i) {
                    if(temp5->v[i]->row==row && temp5->v[i]->col==col )
                    {
                        temp5->v[i]->flag_hide='E';
                        temp5->v[i]->flag='E';
                        while (p->place!=temp5->v[i]->place)
                        {
                            p=p->next;
                        }
                        p->flag_hide='E';
                        p->flag='E';
                    }
                }
            }
        }
        else if(ship_size==3)
        {
            struct set3 *temp3=h3[1];
            while (temp3->index!=ship_index)
            {
                temp3=temp3->next;
            }
            for (int i = 0; i < 3; ++i) {
                if(temp3->v[i]->row==row && temp3->v[i]->col==col)
                {
                    temp3->v[i]->flag_hide='E';
                    temp3->v[i]->flag='E';
                    while (p->place!=temp3->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='E';
                    p->flag='E';
                }
                p=head[1];
            }
        }
        else if(ship_size==2)
        {
            struct set2 *temp2=h2[1];
            while (temp2->index!=ship_index)
            {
                temp2=temp2->next;
            }
            for (int i = 0; i < 2; ++i) {
                if(temp2->v[i]->row==row && temp2->v[i]->col==col)
                {
                    temp2->v[i]->flag_hide='E';
                    temp2->v[i]->flag='E';
                    while (p->place!=temp2->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='E';
                    p->flag='E';
                }
                p=head[1];
            }
        }
        if(ship_size==1)
        {
            struct set1 *temp1=h1[1];
            while (temp1->index!=ship_index)
            {
                temp1=temp1->next;
            }
            for (int i = 0; i < 1; ++i) {
                if(temp1->v[i]->row==row && temp1->v[i]->col==col)
                {
                    temp1->v[i]->flag_hide='E';
                    temp1->v[i]->flag='E';
                    while (p->place!=temp1->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='E';
                    p->flag='E';
                }
                p=head[1];
            }
        }

    }


}
void delete(int size,int ship_index,int player)
{
    if(size==5) {
        struct set5 *temp;
        if(player==1)
        {
            temp=h5[0];
            h5[0]=h5[0]->next;
            free(temp);
        }
        else
        {
            temp=h5[1];
            h5[1]=h5[1]->next;
            free(temp);
        }
    }
    else if(size==3)
    {
        struct set3 *temp;
        struct set3 *before;
        if(player==1)
        {
            temp=h3[0];
            h3[0]=h3[0]->next;
            if(ship_index==0)
            {
                h3[0]=h3[0]->next;
                free(temp);
            }
            else if(ship_index==1)
            {
                before=temp;
                temp=temp->next;
                free(temp);
                before->next=NULL;
            }
        }
        else
        {
            temp=h3[1];
            h3[1]=h3[1]->next;
            if(ship_index==0)
            {
                h3[1]=h3[1]->next;
                free(temp);
            }
            else if(ship_index==1)
            {
                before=temp;
                temp=temp->next;
                free(temp);
                before->next=NULL;
            }

        }
    }
    else if (size==2)
    {
        struct set2 *temp;
        struct set2 *before;
        if(player==1)
        {
            temp=h2[0];
            if(ship_index==0)
            {
                h2[0]=h2[0]->next;
                free(temp);
            }
            else if(ship_index==1)
            {
                before=temp;
                temp=temp->next;
                before->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
        }
        else
        {
            temp=h2[1];
            if(ship_index==0)
            {
                h2[1]=h2[1]->next;
                free(temp);
            }
            else if(ship_index==1)
            {
                before=temp;
                temp=temp->next;
                before->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
        }

    }
    else if(size==1)
    {
        struct set1 *temp;
        struct set1 *before;
        if(player==1)
        {
            temp=h1[0];
            if(ship_index==0)
            {
                h1[0]=h1[0]->next;
                free(temp);
            }
            else if(ship_index==3)
            {
                while (temp->next!=NULL)
                {
                    before=temp;
                    temp=temp->next;
                }
                before->next=NULL;
                free(temp);
            }
            else
            {
                while (temp->index!=ship_index)
                {
                    before=temp;
                    temp=temp->next;
                }
                before->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
        }
        else
        {
            temp=h1[1];
            if(ship_index==0)
            {
                h1[1]=h1[1]->next;
                free(temp);
            }
            else if(ship_index==3)
            {
                while (temp->next!=NULL)
                {
                    before=temp;
                    temp=temp->next;
                }
                before->next=NULL;
                free(temp);
            }
            else
            {
                while (temp->index!=ship_index)
                {
                    before=temp;
                    temp=temp->next;
                }
                before->next=temp->next;
                temp->next=NULL;
                free(temp);
            }
        }
    }
}

//************************************************************
void check_complete(int index,int size,int player)
{

    struct ship2 *p;
    if(player==1)
    {
        p=head[0];
        int c5=0;
        int c3=0;
        int c2=0;
        int c1=0;
        if(size==5)
        {
            struct set5 *temp5=h5[0];
            while (temp5->index!=index)
            {
                temp5=temp5->next;
            }
            for (int i = 0; i < 5; ++i) {
                if (temp5->v[i]->flag_hide=='E')
                {
                    c5++;
                }
            }
            if(c5==5)
            {
                player1_score=player1_score+5;
                for (int i = 0; i < 5; ++i) {
                    temp5->v[i]->flag_hide='C';
                    while (p->place!=temp5->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='C';
                    p->flag='C';
                    p=head[0];
                }
                if(temp5->v[0]->place>temp5->v[4]->place)
                {
                    make_water(temp5->v[4]->row,temp5->v[4]->col,temp5->v[0]->row,temp5->v[0]->col,5,player);
                    delete(5,index,player);
                }
                else if(temp5->v[0]->place<temp5->v[4]->place)
                {
                    make_water(temp5->v[0]->row,temp5->v[0]->col,temp5->v[4]->row,temp5->v[4]->col,5,player);
                    delete(5,index,player);
                }
            }
        }
        else if(size==3)
        {
            struct set3 *temp3=h3[0];
            while (temp3->index!=index)
            {
                temp3=temp3->next;
            }
            for (int i = 0; i < 3; ++i) {
                if (temp3->v[i]->flag_hide=='E')
                {
                    c3++;
                }
            }
            if(c3==3)
            {
                player2_score=player2_score+8;
                for (int i = 0; i < 3; ++i) {
                    temp3->v[i]->flag_hide='C';
                    while (p->place!=temp3->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='C';
                    p->flag='C';
                    p=head[0];
                }
                if(temp3->v[0]->place>temp3->v[2]->place)
                {
                    make_water(temp3->v[2]->row,temp3->v[2]->col,temp3->v[0]->row,temp3->v[0]->col,3,player);
                    delete(3,index,player);
                }
                else if(temp3->v[2]->place>temp3->v[0]->place)
                {
                    make_water(temp3->v[0]->row,temp3->v[0]->col,temp3->v[2]->row,temp3->v[2]->col,3,player);
                    delete(3,index,player);
                }
            }
        }
        else if(size==2) {
            struct set2 *temp2=h2[0];
            while (temp2->index != index) {
                temp2 = temp2->next;
            }
            for (int i = 0; i < 2; ++i) {
                if (temp2->v[i]->flag_hide == 'E') {
                    c2++;
                }
            }
            if (c2 == 2) {
                player2_score=player2_score+12;
                for (int i = 0; i < 2; ++i) {
                    temp2->v[i]->flag_hide = 'C';
                    while (p->place != temp2->v[i]->place) {
                        p = p->next;
                    }
                    p->flag_hide = 'C';
                    p->flag = 'C';
                    p = head[0];
                }
                if (temp2->v[0]->place > temp2->v[1]->place) {
                    make_water(temp2->v[1]->row, temp2->v[1]->col, temp2->v[0]->row, temp2->v[0]->col, 2,player);
                    delete(2, index,player);
                } else if (temp2->v[1]->place > temp2->v[0]->place) {
                    make_water(temp2->v[0]->row, temp2->v[0]->col, temp2->v[1]->row, temp2->v[1]->col, 2,player);
                    delete(2, index,player);
                }

            }
        }
        else if(size==1)
        {
            struct set1 *temp1=h1[0];
            while (temp1->index!=index)
            {
                temp1=temp1->next;
            }
            for (int i = 0; i < 1; ++i) {
                if (temp1->v[i]->flag_hide=='E')
                {
                    c1++;
                }
            }
            if(c1==1)
            {
                player2_score=player2_score+25;
                for (int i = 0; i < 1; ++i) {
                    temp1->v[i]->flag_hide='C';
                    while (p->place!=temp1->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='C';
                    p->flag='C';
                }
                water1(temp1->v[0]->row,temp1->v[0]->col,player);
                delete(1,index,player);
            }
        }
    }
    else
    {
        p=head[1];
        int c5=0;
        int c3=0;
        int c2=0;
        int c1=0;
        if(size==5)
        {
            struct set5 *temp5=h5[1];
            while (temp5->index!=index)
            {
                temp5=temp5->next;
            }
            for (int i = 0; i < 5; ++i) {
                if (temp5->v[i]->flag_hide=='E')
                {
                    c5++;
                }
            }
            if(c5==5)
            {
                player1_score=player1_score+5;
                for (int i = 0; i < 5; ++i) {
                    temp5->v[i]->flag_hide='C';
                    while (p->place!=temp5->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='C';
                    p->flag='C';
                    p=head[1];
                }
                if(temp5->v[0]->place>temp5->v[4]->place)
                {
                    make_water(temp5->v[4]->row,temp5->v[4]->col,temp5->v[0]->row,temp5->v[0]->col,5,player);
                    delete(5,index,player);
                }
                else if(temp5->v[0]->place<temp5->v[4]->place)
                {
                    make_water(temp5->v[0]->row,temp5->v[0]->col,temp5->v[4]->row,temp5->v[4]->col,5,player);
                    delete(5,index,player);
                }
            }
        }
        else if(size==3)
        {
            struct set3 *temp3=h3[1];
            while (temp3->index!=index)
            {
                temp3=temp3->next;
            }
            for (int i = 0; i < 3; ++i) {
                if (temp3->v[i]->flag_hide=='E')
                {
                    c3++;
                }
            }
            if(c3==3)
            {
                player1_score=player1_score+8;
                for (int i = 0; i < 3; ++i) {
                    temp3->v[i]->flag_hide='C';
                    while (p->place!=temp3->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='C';
                    p->flag='C';
                    p=head[1];
                }
                if(temp3->v[0]->place>temp3->v[2]->place)
                {
                    make_water(temp3->v[2]->row,temp3->v[2]->col,temp3->v[0]->row,temp3->v[0]->col,3,player);
                    delete(3,index,player);
                }
                else if(temp3->v[2]->place>temp3->v[0]->place)
                {
                    make_water(temp3->v[0]->row,temp3->v[0]->col,temp3->v[2]->row,temp3->v[2]->col,3,player);
                    delete(3,index,player);
                }
            }
        }
        else if(size==2) {
            struct set2 *temp2=h2[1];
            while (temp2->index != index) {
                temp2 = temp2->next;
            }
            for (int i = 0; i < 2; ++i) {
                if (temp2->v[i]->flag_hide == 'E') {
                    c2++;
                }
            }
            if (c2 == 2) {
                player1_score=player1_score+12;
                for (int i = 0; i < 2; ++i) {
                    temp2->v[i]->flag_hide = 'C';
                    while (p->place != temp2->v[i]->place) {
                        p = p->next;
                    }
                    p->flag_hide = 'C';
                    p->flag = 'C';
                    p = head[1];

                }
                if (temp2->v[0]->place > temp2->v[1]->place) {
                    make_water(temp2->v[1]->row, temp2->v[1]->col, temp2->v[0]->row, temp2->v[0]->col, 2,player);
                    delete(2, index,player);
                } else if (temp2->v[1]->place > temp2->v[0]->place) {
                    make_water(temp2->v[0]->row, temp2->v[0]->col, temp2->v[1]->row, temp2->v[1]->col, 2,player);
                    delete(2, index,player);
                }

            }
        }
        else if(size==1)
        {
            struct set1 *temp_1=h1[1];
            while (temp_1->index!=index)
            {
                temp_1=temp_1->next;
            }
            for (int i = 0; i < 1; ++i) {
                if (temp_1->v[i]->flag_hide=='E')
                {
                    c1++;
                }
            }
            if(c1==1)
            {
                player1_score=player1_score+25;
                for (int i = 0; i < 1; ++i) {
                    temp_1->v[i]->flag_hide='C';
                    while (p->place!=temp_1->v[i]->place)
                    {
                        p=p->next;
                    }
                    p->flag_hide='C';
                    p->flag='C';
                    p=head[1];
                }
                water1(temp_1->v[0]->row,temp_1->v[0]->col,player);
                delete(1,index,player);
            }
        }
    }
}
//**********************************************************************
int fire(int row, int col,int player,char kind)
{
    if(kind=='M')
    {

        int sum;
        int found;
        sum=col*10+row+1;
        int rival;
        struct ship2 *temp;
        if(player==1)
        {
            temp=head[1];
            rival=2;
        }
        else
        {
            temp=head[0];
            rival=1;
        }
//        show_map_link("hide",rival);
        while(temp != NULL) {
            if(temp->place==sum && (temp->flag=='E' || temp->flag=='C'))
            {
                printf("YOU MISSED\n");
                found=0;
                return found;
            }
            if(temp->place==sum && temp->flag=='W')
            {
                temp->flag_hide='W';
                printf("NO SHIPS\n");
                found=0;
                return found;
            }
            if ((temp->place==sum ) && (temp->flag=='S')) {

                temp->flag='E';
                temp->flag_hide='E';
                if(player==1)
                {
                    player1_score++;
                }
                else
                {
                    player2_score++;
                }
                find(row, col,temp->ship_size,temp->ship_index,rival);
                check_complete(temp->ship_index,temp->ship_size,rival);
                if(player==1)
                {
                    printf("\n%s SCORE IS : %d\n",name1,player1_score);
                }
                else
                {
                    printf("\n%s SCORE IS : %d\n",name2,player2_score);
                }
                found=1;
                return found;
            }
            temp= temp->next;
        }
    }
    else if(kind=='A')
    {
        system("cls");
        int sum;
        int found;
        sum=col*10+row+1;
        int rival;
        struct ship2 *temp;
        temp=head[0];
        rival=1;
        while(temp != NULL) {
            if(temp->place==sum && (temp->flag=='E' || temp->flag=='C'))
            {
                found=0;
                return found;
            }
            if(temp->place==sum && temp->flag=='W')
            {
                temp->flag_hide='W';
                found=0;
                return found;
            }
            if ((temp->place==sum ) && (temp->flag=='S')) {

                temp->flag='E';
                temp->flag_hide='E';
                player2_score++;
                find(row, col,temp->ship_size,temp->ship_index,rival);
                check_complete(temp->ship_index,temp->ship_size,rival);
                printf("\nBOT SCORE IS : %d\n",player2_score);
                found=1;
                return found;
            }
            temp= temp->next;
        }
    }

}
//************************************************************

//*****************************************************************************
int save_menu()
{
    printf("Do you want to Save it?\n");
    printf("1-yes\n");
    printf("0-No\n");
    int n;
    scanf("%d",&n);
    return n;
}
FILE *last_game1;
FILE *last_game2;
FILE *n_score1;
FILE *n_score2;
FILE *name_turn;
void save_turn(char n1[],char n2[],int turn)
{
    name_turn=fopen("turn.txt","w");
    fputs(n1,name_turn);
    fprintf(name_turn,"%c",'\n');
    fputs(n2,name_turn);
    fprintf(name_turn,"%c",'\n');
    fprintf(name_turn,"%d",turn);
    fclose(name_turn);
}
void load_turn()
{
    name_turn=fopen("turn.txt","r");
    fgets(name1,40,name_turn);
    fgets(name2,40,name_turn);
    fscanf(name_turn,"%d",&turn_main);
    name1[strlen(name1)-1]='\0';
    name2[strlen(name2)-1]='\0';
    fclose(name_turn);
}

void swap(struct ship2 *a,struct ship2 *b)
{
    struct ship2 *temp=(struct ship2 *)malloc(sizeof(struct ship2));
    temp->row=a->row;
    temp->col=a->col;
    temp->place=a->place;
    temp->flag=a->flag;
    temp->flag_hide=a->flag_hide;
    temp->vertex_address=a->vertex_address;
    temp->ship_size=a->ship_size;
    temp->ship_index=a->ship_index;
    //******************************************
    a->row=b->row;
    a->col=b->col;
    a->place=b->place;
    a->flag=b->flag;
    a->flag_hide=b->flag_hide;
    a->vertex_address=b->vertex_address;
    a->ship_size=b->ship_size;
    a->ship_index=b->ship_index;
    //*********************************
    b->row=temp->row;
    b->col=temp->col;
    b->place=temp->place;
    b->flag=temp->flag;
    b->flag_hide=temp->flag_hide;
    b->vertex_address=temp->vertex_address;
    b->ship_size=temp->ship_size;
    b->ship_index=temp->ship_index;
}
void bubblesort(int player){
    int swapped, i;
    struct ship2 *lptr=NULL;
    struct ship2 *ptr1=NULL;
    if(player==1)
    {
        ptr1=head[0];
    }
    else if(player==2)
    {
        ptr1=head[1];
    }
    do  {
        swapped = 0;
        if(player==1)
        {
            ptr1=head[0];
        }
        else
        {
            ptr1=head[1];
        }
        while (ptr1->next != lptr)       {
            if (ptr1->place > ptr1->next->place)  {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
void save1()
{

    n_score1=fopen("name1.bin","wb");
    last_game1=fopen("final1.bin","wb");
    fwrite(&player1_score,sizeof(int),1,n_score1);
    struct ship2 *t1=head[0];
    while (t1!=NULL)
    {
        fwrite(&t1->row,sizeof(int ),1,last_game1);
        fwrite(&t1->col,sizeof(int ),1,last_game1);
        fwrite(&t1->place,sizeof(int ),1,last_game1);
        fwrite(&t1->ship_size,sizeof(int ),1,last_game1);
        fwrite(&t1->ship_index,sizeof(int ),1,last_game1);
        fwrite(&t1->flag,sizeof(char ),1,last_game1);
        fwrite(&t1->flag_hide,sizeof(char ),1,last_game1);
        fwrite(&t1->vertex_address,sizeof(int ),1,last_game1);
        t1=t1->next;
    }
    fclose(last_game1);
    fclose(n_score1);

}
void save2()
{

    n_score2=fopen("name2.bin","wb");
    last_game2=fopen("final2.bin","wb");
    fwrite(&player2_score,sizeof(int),1,n_score2);
    struct ship2 *t2=head[1];
    while (t2!=NULL)
    {

        fwrite(&t2->row,sizeof(int ),1,last_game2);
        fwrite(&t2->col,sizeof(int ),1,last_game2);
        fwrite(&t2->place,sizeof(int ),1,last_game2);
        fwrite(&t2->ship_size,sizeof(int ),1,last_game2);
        fwrite(&t2->ship_index,sizeof(int ),1,last_game2);
        fwrite(&t2->flag,sizeof(char ),1,last_game2);
        fwrite(&t2->flag_hide,sizeof(char ),1,last_game2);
        fwrite(&t2->vertex_address,sizeof(int ),1,last_game2);
        t2=t2->next;
    }
    fclose(last_game2);
    fclose(n_score2);

}
void delete1()
{
    struct ship2 *t1=head[0];
    struct ship2 *before1;
    name1[0]='\0';
    player1_score=0;
    while (t1!=NULL)
    {
        before1=t1;
        t1=t1->next;
        free(before1);
    }
    head[0]=NULL;
    struct set5 *a5_1;
    struct set5 *prev5_1;
    struct set3 *a3_1;
    struct set3 *prev3_1;
    struct set2 *a2_1;
    struct set2 *prev2_1;
    struct set1 *a1_1;
    struct set1 *prev1_1;
    a5_1=h5[0];
    a3_1=h3[0];
    a2_1=h2[0];
    a1_1=h1[0];
    while(a5_1!=NULL )
    {
        prev5_1=a5_1;
        a5_1=a5_1->next;
        free(prev5_1);
    }
    while(a3_1!=NULL)
    {
        prev3_1=a3_1;
        a3_1=a3_1->next;
        free(prev3_1);
    }
    while(a2_1!=NULL )
    {
        prev2_1=a2_1;
        a2_1=a2_1->next;
        free(prev2_1);
    }
    while(a1_1!=NULL)
    {
        prev1_1=a1_1;
        a1_1=a1_1->next;
        free(prev1_1);
    }
    h5[0]=NULL;
    h3[0]=NULL;
    h2[0]=NULL;
    h1[0]=NULL;
}
void delete2()
{
    name2[0]='\0';
    player2_score=0;
    struct ship2 *t2=head[1];
    struct ship2 *before2;
    struct set5 *a5_2;
    struct set3 *a3_2;
    struct set2 *a2_2;
    struct set1 *a1_2;
    struct set5 *prev5_2;
    struct set3 *prev3_2;
    struct set2 *prev2_2;
    struct set1 *prev1_2;
    a5_2=h5[1];
    a3_2=h3[1];
    a2_2=h2[1];
    a1_2=h1[1];
    while (t2!=NULL)
    {
        before2=t2;
        t2=t2->next;
        free(before2);
    }
    head[1]=NULL;
    while(a5_2!=NULL )
    {
        prev5_2=a5_2;
        a5_2=a5_2->next;
        free(prev5_2);
    }
    while(a3_2!=NULL)
    {
        prev3_2=a3_2;
        a3_2=a3_2->next;
        free(prev3_2);
    }
    while(a2_2!=NULL )
    {
        prev2_2=a2_2;
        a2_2=a2_2->next;
        free(prev2_2);
    }
    while(a1_2!=NULL)
    {
        prev1_2=a1_2;
        a1_2=a1_2->next;
        free(prev1_2);
    }
    h5[1]=NULL;
    h3[1]=NULL;
    h2[1]=NULL;
    h1[1]=NULL;

}
void load_ships1()
{
    struct ship2 *temp=head[0];
    while (temp!=NULL)
    {
        if(temp->ship_size==5)
        {
            fill5(temp->row,temp->col,temp->ship_index,temp->vertex_address,1);
        }
        else if(temp->ship_size==3)
        {
            fill3(temp->row,temp->col,temp->ship_index,temp->vertex_address,1);
        }
        else if(temp->ship_size==2)
        {
            fill2(temp->row,temp->col,temp->ship_index,temp->vertex_address,1);
        }
        else if(temp->ship_size==1)
        {
            fill1(temp->row,temp->col,temp->ship_index,0,1);
        }
        else;
        temp=temp->next;
    }
}
void load_ships2()
{
    struct ship2 *temp=head[1];
    while (temp!=NULL)
    {
        if(temp->ship_size==5)
        {
            fill5(temp->row,temp->col,temp->ship_index,temp->vertex_address,2);
        }
        else if(temp->ship_size==3)
        {
            fill3(temp->row,temp->col,temp->ship_index,temp->vertex_address,2);
        }
        else if(temp->ship_size==2)
        {
            fill2(temp->row,temp->col,temp->ship_index,temp->vertex_address,2);
        }
        else if(temp->ship_size==1)
        {
            fill1(temp->row,temp->col,temp->ship_index,0,2);
        }
        else;
        temp=temp->next;
    }
}
void load_lastgame1()
{

    n_score1=fopen("name1.bin","rb");
    last_game1=fopen("final1.bin","rb");
    fread(&player1_score,sizeof(int),1,n_score1);
    int i=1;
    while (i<=100)
    {

        struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
        fread(&new->row,sizeof(int ),1,last_game1);
        fread(&new->col,sizeof(int ),1,last_game1);
        fread(&new->place,sizeof(int ),1,last_game1);
        fread(&new->ship_size,sizeof(int ),1,last_game1);
        fread(&new->ship_index,sizeof(int ),1,last_game1);
        fread(&new->flag,sizeof(char ),1,last_game1);
        fread(&new->flag_hide,sizeof(char ),1,last_game1);
        fread(&new->vertex_address,sizeof(int ),1,last_game1);
        new->next=head[0];
        head[0]=new;
        i++;
    }
    bubblesort(1);
    load_ships1();
    fclose(last_game1);

}
void load_lastgame2()
{

    n_score2=fopen("name2.bin","rb");
    last_game2=fopen("final2.bin","rb");
    fread(&player2_score,sizeof(int),1,n_score2);
    int i;
    i=1;
    while (i<=100)
    {

        struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
        fread(&new->row,sizeof(int ),1,last_game2);
        fread(&new->col,sizeof(int ),1,last_game2);
        fread(&new->place,sizeof(int ),1,last_game2);
        fread(&new->ship_size,sizeof(int ),1,last_game2);
        fread(&new->ship_index,sizeof(int ),1,last_game2);
        fread(&new->flag,sizeof(char ),1,last_game2);
        fread(&new->flag_hide,sizeof(char ),1,last_game2);
        fread(&new->vertex_address,sizeof(int ),1,last_game2);
        new->next=head[1];
        head[1]=new;
        i++;
    }
    bubblesort(2);
    load_ships2();
    fclose(last_game2);


}
FILE *merge;
void merge_save()
{
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime ( &rawtime );
    char buffer[20];
    char path[45];
    strftime(buffer,20,"last%H%M",timeinfo);
    strcat(buffer,".bin");
    merge=fopen(buffer,"wb");
    fwrite(&player1_score,sizeof(int),1,merge);
    fwrite(&player2_score,sizeof(int),1,merge);
    struct ship2 *t1=head[0];
    while (t1!=NULL)
    {
        fwrite(&t1->row,sizeof(int ),1,merge);
        fwrite(&t1->col,sizeof(int ),1,merge);
        fwrite(&t1->place,sizeof(int ),1,merge);
        fwrite(&t1->ship_size,sizeof(int ),1,merge);
        fwrite(&t1->ship_index,sizeof(int ),1,merge);
        fwrite(&t1->flag,sizeof(char ),1,merge);
        fwrite(&t1->flag_hide,sizeof(char ),1,merge);
        fwrite(&t1->vertex_address,sizeof(int ),1,merge);
        t1=t1->next;
    }
    struct ship2 *t2=head[1];
    while (t2!=NULL)
    {

        fwrite(&t2->row,sizeof(int ),1,merge);
        fwrite(&t2->col,sizeof(int ),1,merge);
        fwrite(&t2->place,sizeof(int ),1,merge);
        fwrite(&t2->ship_size,sizeof(int ),1,merge);
        fwrite(&t2->ship_index,sizeof(int ),1,merge);
        fwrite(&t2->flag,sizeof(char ),1,merge);
        fwrite(&t2->flag_hide,sizeof(char ),1,merge);
        fwrite(&t2->vertex_address,sizeof(int ),1,merge);
        t2=t2->next;
    }
    fclose(merge);
}
void load_merge(char address[])
{
    merge=fopen(address,"rb");
    fread(&player1_score,sizeof(int),1,merge);
    fread(&player2_score,sizeof(int),1,merge);
    int i=1;
    while (i<=100)
    {

        struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
        fread(&new->row,sizeof(int ),1,merge);
        fread(&new->col,sizeof(int ),1,merge);
        fread(&new->place,sizeof(int ),1,merge);
        fread(&new->ship_size,sizeof(int ),1,merge);
        fread(&new->ship_index,sizeof(int ),1,merge);
        fread(&new->flag,sizeof(char ),1,merge);
        fread(&new->flag_hide,sizeof(char ),1,merge);
        fread(&new->vertex_address,sizeof(int ),1,merge);
        new->next=head[0];
        head[0]=new;
        i++;
    }
    i=1;
    while (i<=100)
    {

        struct ship2 *new=(struct ship2 *)malloc(sizeof(struct ship2));
        fread(&new->row,sizeof(int ),1,merge);
        fread(&new->col,sizeof(int ),1,merge);
        fread(&new->place,sizeof(int ),1,merge);
        fread(&new->ship_size,sizeof(int ),1,merge);
        fread(&new->ship_index,sizeof(int ),1,merge);
        fread(&new->flag,sizeof(char ),1,merge);
        fread(&new->flag_hide,sizeof(char ),1,merge);
        fread(&new->vertex_address,sizeof(int ),1,merge);
        new->next=head[1];
        head[1]=new;
        i++;
    }
    load_ships1();
    load_ships2();
    bubblesort(1);
    bubblesort(2);
    fclose(merge);
}
int hide_map()
{
    printf("do you want to hide it ?1-yes 0-no\n");
    int n;
    scanf("%d",&n);
    if(n==1)
    {
        system("cls");
    }
    else;
}
//int check_name(char a[],char b[])
//{
//    if(strlen(a)!=strlen(b))
//    {
//        return 0;
//    }
//    else
//    {
//        int q=0;
//        for (int i = 0; i < strlen(a); ++i) {
//            if(a[i]==b[i])
//            {
//                q++;
//            }
//            else
//            {
//                return 0;
//            }
//        }
//        if(q==strlen(a))
//        {
//            return 1;
//        }
//    }
//}
//FILE *people;
//FILE *scores;
//int search(char name[])
//{
//    int found=0;
//    struct player *temp=root;
//    while (temp!=NULL)
//    {
//        if(check_name(root->name,name)==1)
//        {
//            return 1;
//        }
//        temp=temp->next;
//    }
//    return 0;
//}
//void update_score(char name[],int new_score)
//{
//    int index=0;
//    struct player *temp=root;
//    if(search(name)==0)
//    {
//        printf("not availble\n");
//    }
//    else
//    {
//        while (temp!=NULL)
//        {
//            if(check_name(temp->name,name)==1)
//            {
//                index=temp->index;
//                break;
//            }
//            temp=temp->next;
//        }
//        scores=fopen("scores.bin","r+b");
//        fseek(scores,sizeof(int)*(index-1),SEEK_SET);
//        fwrite(&new_score,sizeof(int),1,scores);
//        fclose(scores);
//    }
//}
//void add_name_file(char name[],int score)
//{
//    people=fopen("people.bin","ab");
//    scores=fopen("scores.bin","ab");
//    int len=strlen(name);
//    char u[31];
//    for (int i = 0; i < 30; ++i) {
//        u[i]='@';
//    }
//    for (int i = 0; i < strlen(name); ++i) {
//        u[i]=name[i];
//    }
//    fwrite(&score,sizeof(int),1,scores);
//    fwrite(u,sizeof(char),30,people);
//    fclose(people);
//    fclose(scores);
//    struct player *temp=root;
//    if(root==NULL)
//    {
//        struct player *new=(struct player *)malloc(sizeof(struct player));
//        for (int i = 0; i < len; ++i) {
//            new->name[i]=name[i];
//        }
//        new->name[len]='\0';
//        new->score=score;
//        new->index=1;
//        new->next=root;
//        root=new;
//    }
//    else
//    {
//        if(search(name)==1)
//        {
//            printf("%s is already available \n",name);
//        }
//        else
//        {
//            while (temp->next!=NULL)
//            {
//                temp=temp->next;
//            }
//            struct player *new=(struct player *)malloc(sizeof(struct player));
//            for (int i = 0; i < len; ++i) {
//                new->name[i]=name[i];
//            }
//            new->name[len]='\0';
//            new->score=score;
//            new->index=(temp->index+1);
//            new->next=temp->next;
//            temp->next=new;
//        }
//    }
//}
//void swap2(struct player *a,struct player *b)
//{
//  struct player *temp=(struct player *)malloc(sizeof(struct player));
//  temp->score=a->score;
//    for (int i = 0; i < strlen(a->name); ++i) {
//        temp->name[i]=a->name[i];
//    }
//    temp->name[strlen(a->name)]='\0';
//    temp->score=a->score;
//  //*****************************
//    a->score=b->score;
//    for (int i = 0; i < strlen(b->name); ++i) {
//        a->name[i]=b->name[i];
//    }
//    a->name[strlen(b->name)]='\0';
//    a->score=b->score;
//    //***********************************
//    b->score=temp->score;
//    for (int i = 0; i < strlen(temp->name); ++i) {
//        b->name[i]=temp->name[i];
//    }
//    b->name[strlen(temp->name)]='\0';
//    b->score=temp->score;
//}
//void bubblesort2()
//{
//    int swapped;
//    struct player *lptr=NULL;
//    struct player *ptr1=NULL;
//    do  {
//        swapped = 0;
//        ptr1=root;
//        while (ptr1->next != lptr)       {
//            if (ptr1->score < ptr1->next->score)  {
//                swap2(ptr1, ptr1->next);
//                swapped = 1;
//            }
//            ptr1 = ptr1->next;
//        }
//        lptr = ptr1;
//    }
//    while (swapped);
//}
//void show_list()
//{
//  bubblesort2();
//  struct player *temp=root;
//  while (temp!=NULL)
//  {
//      printf("%d-%s-%d\n",temp->index,temp->name,temp->score);
//      temp=temp->next;
//  }
//  printf("No availble users\n");
//}
//void read_data()
//{
//    people=fopen("people.bin","rb");
//    scores=fopen("scores.bin","rb");
//    int k=1;
//    int j=0;
//    int index=1;
//    while (!feof(people))
//    {
//        struct player *new=(struct player *)malloc(sizeof(struct player));
//        fread(new->name,sizeof(char),30,people);
//        fseek(people,0,SEEK_SET);
//        for (int i = 0; i < 30; ++i) {
//            if(new->name[i]=='@')
//            {
//                new->name[i]='\0';
//                break;
//            }
//            else;
//        }
//        new->index=index;
//        index++;
//        fread(&new->score,sizeof(int),1,scores);
//        fseek(scores,0,SEEK_SET);
//        new->next=root;
//        root=new;
//        fseek(people,sizeof(char)*30*k,SEEK_SET);
//        fseek(scores,sizeof(int)*j,SEEK_SET);
//        k++;
//        j++;
//    }
//}
int found_user_on_list=0;
int print_user_name( ) {
    char name[50];

    int mark,i,n;
    FILE *fptr;
    fptr = fopen( "list.txt" , "r" );
    if( fptr == NULL) {
        printf( "list.txt Not found" );
        return 0;
    }
    i=-1;
    printf("name      score\n ");
    do {
        fgets(name,50,fptr);
        if (feof(fptr))   {
            break;
        }
        printf("%s" ,name);
        i=i+1;
    }
    while (1) ;
    fclose(fptr);
    return i;
}
//***********************************************************
int find_user_name( char name[],int user,int filecount ) {
    char filename[50];
    int mark,i;
    FILE *fptr;
    //  int found_user_on_list=0;
    fptr = ( fopen( "list.txt" , "r" ) );
    if( fptr == NULL) {
        printf( "lis.txt Not found" );
        return 0;
    }

    for( i=1 ; i<=filecount ; i++ )  {
        fscanf( fptr, "%s %d" ,filename,&mark);
        if ( strstr(filename, name) !=NULL)   {
            if (strlen(filename)==strlen(name)) {
                //printf("  foumd.....yes \n");
                found_user_on_list=1;
                return mark;
            }
        }
    }
    fclose(fptr);
    return 1;
}
//int save_user_name( char name[],int mark) {
//
//    FILE *fptr;
//
//    fptr = ( fopen( "list.txt" , "a+" ) );
//    if( fptr == NULL)
//    {
//        printf( "Error" );
//        exit(1);
//    }
//    fprintf( fptr, "%s\t%d\n" ,name,mark);
//    fclose(fptr);
//    return 1;
//}
//int update_user_last_txt_file(char update_n[] ,int mark) {
//    char update_name[50][50];
//    int  update_mark[50];
//    char filename[50];
//    int mark1,i,n;
//    i=0;
//    FILE *fptr;
//    fptr = ( fopen( "list.txt" , "r" ) );
//    if( fptr == NULL) {
//        printf( "\nlist.txt Not found." );
//        return 0;
//    }
//    n=0;
//    //------------------------------------------
//
//    if ( !feof(fptr))    {
//        fscanf( fptr, "%s %d" ,filename,&mark1);
//        strcpy(update_name[i],filename);
//        i++;
//        update_mark[i]=mark;
//        n=n+1;
//    }
//    fclose(fptr);
//    //------------------------------------------
//    for( i=0; i<n ; i++ )  {
//        if ( strstr(update_name[i], update_n) !=NULL)   {
//            if (strlen(update_name[i]) == strlen(update_n)) {
//                //printf("  foumd.....yes \n");
//                update_mark[i]=mark;
//                //  	 found_user_on_list=1;
//            }
//        }
//    }
//    //--------------------------------------------------
//    for( i=0; i<n ; i++ )  {
//        save_user_name( update_name[i],update_mark[i]) ;
//    }
//
//    //---------------------------------------------------
//
//
//    return i;
//}
void game_2player(char n1[],char n2[],int turn)
{
    if(turn==1)
    {
        int a,b;
        printf("for %s --- fire\n",n1);
        printf("\n b,a:");
        show_map_link("hide",2);
        scanf("%d%d",&b,&a);
        while(player1_score!=178 || player2_score!=178 )
        {
            while (fire(a,b,1,'M')==1)
            {
                system("cls");
                show_map_link("hide",2);
                printf("%s score : [%d]\n",n1,player1_score);
                if(save_menu()==1)
                {
                    save2();
                    save1();
                    merge_save();
                    save_turn(name1,name2,1);

                }
                else;
                printf("%s score is %d\n",n1,player1_score);
                printf("for %s --- fire\n",n1);
                printf("enter b,a:\n");
                scanf("%d%d",&b,&a);
            }
            system("cls");
            show_map_link("hide",2);
            printf("%s missed\n",n1);
            if(save_menu()==1)
            {
                save2();
                save1();
                merge_save();
                save_turn(name1,name2,2);
//                update_user_last_txt_file(name1,player1_score);
//                update_user_last_txt_file(name2,player2_score);
            }
            else;
            hide_map();
            show_map_link("hide",1);
            printf("for %s ----- fire\n",n2);
            printf("\n b,a:");
            scanf("%d%d",&b,&a);
            while(fire(a,b,2,'M')==1)
            {
                system("cls");
                show_map_link("hide",1);
                printf("%s score : [%d]\n",n2,player2_score);
                if(save_menu()==1)
                {
                    save2();
                    save1();
                    merge_save();
                    save_turn(name1,name2,2);
//                    update_user_last_txt_file(name1,player1_score);
//                    update_user_last_txt_file(name2,player2_score);
                }
                else;
                printf("%s score is %d\n",n2,player2_score);
                printf("for %s --- fire\n",n2);
                printf("enter b,a:\n");
                scanf("%d%d",&b,&a);
            }
            system("cls");
            show_map_link("hide",1);
            printf("%s missed\n",n2);
            if(save_menu()==1)
            {
                save2();
                save1();
                merge_save();
                save_turn(name1,name2,1);
//                update_user_last_txt_file(name1,player1_score);
//                update_user_last_txt_file(name2,player2_score);
            }
            else;
            system("cls");
            show_map_link("hide",2);
            printf("for %s ----- fire\n",n1);
            printf("\n b,a:");
            scanf("%d%d",&b,&a);

        }
    }
    else if(turn==2)
    {
        ;
        int a,b;
        printf("for %s --- fire\n",n2);
        printf("\n b,a:");
        show_map_link("hide",1);
        scanf("%d%d",&b,&a);
        while(player1_score!=178 || player2_score!=178 )
        {
            while (fire(a,b,2,'M')==1)
            {
                system("cls");
                show_map_link("hide",1);
                printf("%s score : [%d]\n",n2,player2_score);
                if(save_menu()==1)
                {
                    save2();
                    save1();
                    merge_save();
                    save_turn(name1,name2,2);
//                    update_user_last_txt_file(name1,player1_score);
//                    update_user_last_txt_file(name2,player2_score);
                }
                else;
                printf("%s score is %d\n",n2,player2_score);
                printf("for %s --- fire\n",n2);
                printf("enter b,a:\n");
                scanf("%d%d",&b,&a);
            }
            system("cls");
            show_map_link("hide",1);
            printf("%s missed\n",n2);
            if(save_menu()==1)
            {
                save2();
                save1();
                merge_save();
                save_turn(name1,name2,1);
//                update_user_last_txt_file(name1,player1_score);
//                update_user_last_txt_file(name2,player2_score);
            }
            else;

            hide_map();
            show_map_link("hide",2);
            printf("for %s ----- fire\n",n1);
            printf("\n b,a:");
            scanf("%d%d",&b,&a);
            while(fire(a,b,1,'M')==1)
            {
                system("cls");
                show_map_link("hide",2);
                printf("%s score : [%d]\n",n1,player1_score);
                if(save_menu()==1)
                {
                    save2();
                    save1();
                    merge_save();
                    save_turn(name1,name2,1);
//                    update_user_last_txt_file(name1,player1_score);
//                    update_user_last_txt_file(name2,player2_score);
                }
                else;
                printf("%s score is %d\n",n1,player1_score);
                printf("for %s --- fire\n",n1);
                printf("enter b,a:\n");
                scanf("%d%d",&b,&a);
            }
            system("cls");
            show_map_link("hide",2);
            printf("%s missed\n",n1);
            if(save_menu()==1)
            {
                save2();
                save1();
                merge_save();
                save_turn(name1,name2,2);
//                update_user_last_txt_file(name1,player1_score);
//                update_user_last_txt_file(name2,player2_score);
            }
            else;
            hide_map();
            system("cls");
            show_map_link("hide",1);
            printf("for %s ----- fire\n",n2);
            printf("\n b,a:");
            scanf("%d%d",&b,&a);
        }
    }
}
void game_bot(char n1[],int turn)
{   if(turn==3)
    {
        int choice;
        int a,b;
        printf("for %s --- fire\n",name1);
        printf("\n b,a:");
        show_map_link("hide",2);
        scanf("%d%d",&b,&a);
        while(player1_score!=178 || player2_score!=178 )
        {

            while (fire(a,b,1,'M')==1)
            {
                system("cls");
                show_map_link("hide",2);
                printf("%s score : [%d]\n",n1,player1_score);
                if(save_menu()==1)
                {
                    save1();
                    save2();
                    merge_save();
                    save_turn(name1,"BOT",3);
//                    update_user_last_txt_file(name1,player1_score);
//                    update_user_last_txt_file("BOT",player2_score);
                }
                else;
                printf("%s score is %d\n",n1,player1_score);
                printf("for %s --- fire\n",n1);
                printf("enter b,a:\n");
                scanf("%d%d",&b,&a);
            }
            system("cls");
            show_map_link("hide",2);
            printf("%s missed\n",n1);
            if(save_menu()==1)
            {
                save1();
                save2();
                merge_save();
                save_turn(name1,"BOT",4);
//                update_user_last_txt_file(name1,player1_score);
//                update_user_last_txt_file("BOT",player2_score);
            }
            else;
            printf("hide it ? 1-yes 0-NO \n");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
            }
            else;
            a=rand()%10;
            b=rand()%10;
            while (fire(a,b,2,'A')==1)
            {
                system("cls");
                show_map_link("hide",1);
                a=rand()%10;
                b=rand()%10;
            }
            system("cls");
            printf("BOT SCORE IS %d\n",player2_score);
            printf("YOUR SCORE IS %d\n",player1_score);
            show_map_link("hide",1);
            printf("your hide plan status \n");
            if(save_menu()==1)
            {
                save1();
                save2();
                merge_save();
                save_turn(name1,"BOT",3);
//                update_user_last_txt_file(name1,player1_score);
//                update_user_last_txt_file("BOT",player2_score);
            }
            else;
            printf("hide it ? 1-yes 0-NO \n");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
            }
            else;
            printf("for %s --- fire\n",name1);
            printf("\n b,a:");
            show_map_link("hide",2);
            scanf("%d%d",&b,&a);
            fire(a,b,1,'M');
        }
    }
    else if(turn ==4)
    {
        int choice;
        int a,b;
        a=rand()%10;
        b=rand()%10;
        while(player1_score!=178 || player2_score!=178 )
        {
            while (fire(a,b,2,'A')==1)
            {
                system("cls");
                show_map_link("hide",1);
                a=rand()%10;
                b=rand()%10;
            }
            system("cls");
            printf("BOT SCORE IS %d\n",player2_score);
            printf("YOUR SCORE IS %d\n",player1_score);
            show_map_link("hide",1);
            printf("your hide plan status \n");
            if(save_menu()==1)
            {
                save1();
                save2();
                merge_save();
                save_turn(name1,"BOT",3);
//                update_user_last_txt_file(name1,player1_score);
//                update_user_last_txt_file("BOT",player2_score);
            }
            else;
            printf("hide it ? 1-yes 0-NO \n");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
            }
            else;
            printf("for %s --- fire\n",name1);
            printf("\n b,a:");
            show_map_link("hide",2);
            scanf("%d%d",&b,&a);
            while (fire(a,b,1,'M')==1)
            {
                system("cls");
                show_map_link("hide",2);
                printf("%s score : [%d]\n",n1,player1_score);
                if(save_menu()==1)
                {
                    save1();
                    save2();
                    merge_save();
                    save_turn(name1,"BOT",3);
                }
                else;
                hide_map();
                printf("%s score is %d\n",n1,player1_score);
                printf("for %s --- fire\n",n1);
                printf("enter b,a:\n");
                scanf("%d%d",&b,&a);
            }
            system("cls");
            show_map_link("hide",2);
            printf("%s missed\n",n1);
            if(save_menu()==1)
            {
                save1();
                save2();
                merge_save();
                save_turn(name1,"BOT",4);
            }
            else;
            printf("hide it ? 1-yes 0-NO \n");
            scanf("%d",&choice);
            if(choice==1)
            {
                system("cls");
            }
            else;
        }
    }

}

int  main() {
    int a,b;
    srand(time(0));
    create(1);
    create(0);
    create_ships(1);
    create_ships(2);
    int j=menu();
    while ((j!=7)) {
        if (j == 1)
        {
            printf("Fisrt Player\n");
            printf("1-new player\n");
            int z;
            scanf("%d",&z);
             if(z==1)
            {
                printf("Enter player 1 name\n");
                scanf("%s",name1);
                printf("Enter player 2 name\n");
                scanf("%s",name2);
                printf("--------------------\n");
//                save_user_name(name1,0);
//                save_user_name(name2,0);
                printf("for %s\n",name1);
                int choice;
                printf("Put Ships\n");
                printf("1)AUTO\n2)MANUAL\n");
                scanf("%d",&choice);
                if(choice==1)
                {
                    place_ship(1,'A');
                    show_map_link("real",1);
                    if(save_menu()==1)
                    {
                        save1();
                        save2();
                        merge_save();
                        save_turn(name1,name2,1);
                    }
                    else;
                }
                else
                {
                    place_ship(1,'M');
                    if(save_menu()==1)
                    {
                        save1();
                        save2();
                        merge_save();
                        save_turn(name1,name2,1);
                    }
                    else;
                }
                printf("hide your plan ? 0)NO,1)YES\n");
                scanf("%d",&choice);
                if(choice==1)
                {
                    system("cls");
                }
                else;
                printf("--------------------\n");
                printf("for %s\n",name2);
                printf("Put Ships\n");
                printf("1)AUTO\n2)MANUAL\n");
                scanf("%d",&choice);
                if(choice==1)
                {
                    place_ship(2,'A');
                    show_map_link("real",2);
                    if(save_menu()==1)
                    {
                        save1();
                        save2();
                        merge_save();
                        save_turn(name1,name2,2);
                    }
                    else;
                }
                else
                {
                    place_ship(2,'M');
                    if(save_menu()==1)
                    {
                        save2();
                        save1();
                        save_turn(name1,name2,2);
                    }
                    else;
                }
                printf("hide your plan ? 0)NO,1)YES\n");
                scanf("%d",&choice);
                if(choice==1)
                {
                    system("cls");
                }
                else;
                while (player1_score!=178 && player2_score!=178 )
                {
                    game_2player(name1,name2,1);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf("%s GAME OVER\n",name2);
                    printf("%s SCORE %d\n",name2,(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS %s\n",name2);
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
             else;
        }
        else if(j==2)
        {
            place_ship(2,'A');
            int choice;
            printf("Fisrt Player\n");
            printf("1-new player\n");
            int z;
            scanf("%d",&z);
            if(z==1000);
            else
            {
                strcpy(name2,"BOT");
                name2[4]='\0';
                printf("Enter player 1 name\n");
                scanf("%s",name1);
                printf("----------------------------\n");
                printf("for %s\n",name1);
                printf("Put Ships\n");
                printf("1)AUTO\n2)MANUAL\n");
                scanf("%d",&choice);
                if(choice==1)
                {
                    place_ship(1,'A');
                    show_map_link("real",1);
                    if(save_menu()==1)
                    {
                        save1();
                        save2();
                        merge_save();
                        save_turn(name1,"BOT",3);
                    }
                    else;
                }
                else
                {
                    place_ship(1,'M');
                    if(save_menu()==1)
                    {
                        save1();
                        save2();
                        save_turn(name1,"BOT",3);
                    }
                }
                printf("hide your plan ? 0)NO,1)YES\n");
                scanf("%d",&choice);
                if(choice==1)
                {
                    system("cls");
                }
                else;
                while (player1_score!=178 && player2_score != 178)
                {
                    game_bot(name1,3);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf(" GAME OVER for BOT\n");
                    printf("BOT SCORE %d\n",(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS BOT\n");
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }

            }
        }
        else if(j==4)
        {
            delete1();
            delete2();
            create_ships(1);
            create_ships(2);
            load_lastgame1();
            load_lastgame2();
            load_turn();
            printf("*********************************************************\n");
            printf("*********************************************************\n");

            if(turn_main==1)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("%s score is %d\n",name2,player2_score);
                while (player1_score!=178 && player2_score!=178 )
                {
                    game_2player(name1,name2,1);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf("%s GAME OVER\n",name2);
                    printf("%s SCORE %d\n",name2,(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS %s\n",name2);
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
            else if(turn_main==2)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("%s score is %d\n",name2,player2_score);
                while (player1_score!=178 && player2_score!=178 )
                {
                    game_2player(name1,name2,2);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf("%s GAME OVER\n",name2);
                    printf("%s SCORE %d\n",name2,(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS %s\n",name2);
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
            else if(turn_main==3)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("BOTscore is %d\n",player2_score);
                printf("BOT turn for fire:\n");
                while (player1_score!=178 && player2_score != 178)
                {
                    game_bot(name1,3);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf(" GAME OVER for BOT\n");
                    printf("BOT SCORE %d\n",(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS BOT\n");
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
            else if(turn_main==4)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("BOTscore is %d\n",player2_score);
                while (player1_score!=178 && player2_score != 178)
                {
                    game_bot(name1,4);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf(" GAME OVER for BOT\n");
                    printf("BOT SCORE %d\n",(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS BOT\n");
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }

        }
        else if(j==3)
        {
            system("cls");
            system("dir/b last*.bin*");
            printf("choose one address\n");
            char buff[50];
            scanf("%s",buff);
            delete1();
            delete2();
            create_ships(1);
            create_ships(2);
            load_merge(buff);
            load_turn();
            printf("********************************************\n");

            if(turn_main==1)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("%s score is %d\n",name2,player2_score);
                while (player1_score!=178 && player2_score!=178 )
                {
                    game_2player(name1,name2,1);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf("%s GAME OVER\n",name2);
                    printf("%s SCORE %d\n",name2,(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS %s\n",name2);
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
            else if(turn_main==2)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("%s score is %d\n",name2,player2_score);
                while (player1_score!=178 && player2_score!=178 )
                {
                    game_2player(name1,name2,2);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf("%s GAME OVER\n",name2);
                    printf("%s SCORE %d\n",name2,(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS %s\n",name2);
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
            else if(turn_main==3)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("BOTscore is %d\n",player2_score);
                printf("BOT turn for fire:\n");
                while (player1_score!=178 && player2_score != 178)
                {
                    game_bot(name1,3);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf(" GAME OVER for BOT\n");
                    printf("BOT SCORE %d\n",(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS BOT\n");
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
            else if(turn_main==4)
            {
                printf("%s score is %d\n",name1,player1_score);
                printf("BOTscore is %d\n",player2_score);
                while (player1_score!=178 && player2_score != 178)
                {
                    game_bot(name1,4);
                }
                if(player1_score==178)
                {
                    printf("THE WINNER IS %s\n",name1);
                    printf(" GAME OVER for BOT\n");
                    printf("BOT SCORE %d\n",(player2_score/2));
                }
                else if(player2_score==178)
                {
                    printf("THE WINNER IS BOT\n");
                    printf("%s GAME OVER\n",name1);
                    printf("%s SCORE %d\n",name1,(player1_score/2));
                }
            }
        }
        else if(j==5)
        {
            load_turn();
            delete1();
            delete2();
            create_ships(1);
            create_ships(2);
            load_lastgame1();
            load_lastgame2();
            load_turn();
            printf("%s score is %d\n",name1,player1_score);
            printf("%s score is %d\n",name2,player2_score);
            exit(0);
        }
        else if(j==6)
        {
            printf("1-Blue\n");
            printf("2-Green\n");
            printf("3-Purple\n");
            printf("4-yellow\n");
            printf("5-red\n");
            printf("6-gray\n");
            printf("7-aqua\n");
            printf("8-light red\n");
            printf("9-light yellow\n");
            int n;
            scanf("%d",&n);
            if(n==1)
            {
                system("color 9");
            }
            else if(n==2)
            {
                system("color 2");
            }
            else if(n==3)
            {
                system("color D");
            }
            else if(n==4)
            {
                system("color 6");
            }
            else if(n==5)
            {
                system("color 4");
            }
            else if(n==6)
            {
                system("color 8");
            }
            else if(n==7)
            {
                system("color 3");
            }
            else if (n==8)
            {
                system("color C");
            }
            else if (n==9)
            {
                system("color E");
            }
        }
        j=menu();
    }
    return 0;
}

































//scanf("%d",&n);
//switch(n)
//{
//case 1:
//printf("Play with a friend\n ");
//place_ship1();
////  show_map_link("real");
//break;
//case 2:
//
//printf("\nselect a point for fire :");
//printf("\n b,a:");
//scanf("%d%d",&b,&a);
//fire(a,b);
//break;
//case  3:
//printf("\nshow map :");
//show_map_link("real");
//break;
//case 4:
//printf("\nshow hide map :");
//show_map_link("hide");
//break;
















//
//
//
//
//void record(int rival,int place,int row ,int col , char flag)
//{
//    struct ship2 *link=(struct ship2 *)malloc(sizeof(struct ship2));
//    link->flag_hide=flag;
//    link->flag=' ';
//    link->place=place;
//    link->row=row;
//    link->col=col;
//    if(rival==1)
//    {
//        link->next=playback[0];
//        playback[0]=link;
//    }
//    else
//    {
//        link->next=playback[1];
//        playback[1]=link;
//    }
//}
//void gotoxy(int x, int y){
//    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
//    COORD cursorCoord;
//    cursorCoord.X = x;
//    cursorCoord.Y = y;
//    SetConsoleCursorPosition(consoleHandle, cursorCoord);
//}
//void delay(int number_of_seconds)
//{
//
//    int milli_seconds = 1000 * number_of_seconds;
//    clock_t start_time = clock();
//    while (clock() < start_time + milli_seconds)
//        ;
//}
//void playback_show(int rival){
//    struct ship2 *temp;
//    if(rival==1)
//    {
//        temp=playback[0];
//    }
//    else
//    {
//        temp=playback[1];
//    }
//    int  row , col, i ;
//    system("cls");
//    printf("\n USER : %d ",rival);
//    printf("\n   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |");
//    for(i=0;i<10;++i)
//        printf("\n %d |   |   |   |   |   |   |   |   |   |   |",i);
//    //--------------------------------------------
//    while(temp != NULL) {
//        row=(temp->place/10)+3;
//        col=((temp->place%10)*4)+5;
//        gotoxy(col,row);
//        printf("%c",temp->flag_hide);
//        temp = temp->next;
//        delay(5);
//    }
//}
//void playback_show_request(int rival)
//{
//    printf("Do you want to show playback? 1-yes 0-no\n");
//    int n;
//    scanf("%d",&n);
//    if(n==1)
//    {
//        playback_show(rival);
//    }
//    else;
//}