#include"header.h"
void stud_add(sll **ptr)
{
int a;
sll *new,*last=*ptr;
new=malloc(sizeof(sll));
printf("Enter name and percentage\n");
scanf("%s%f",new->name,&new->percentage);
a=stud_roll(*ptr);
new->rollno=a;
new->next=0;
if(*ptr==0)
*ptr=new;
else
{
while(last->next!=0)
last=last->next;
last->next=new;
}
printf("\033[35mNode Added\n\033[0m");
}

int stud_roll(sll *ptr)
{
int i,f;
for(i=1;i;i++)
{
f=0;
sll *pos=ptr;
while(pos)
{
if(pos->rollno==i)
f++;
pos=pos->next;
}
if(f==0)
return i;
}
}
