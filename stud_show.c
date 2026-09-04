#include"header.h"
void stud_show(sll *ptr)
{
if(ptr==0)
{
printf("\033[35mNo Data Present\n\033[0m");
return;
}
printf("\033[35mRollno\tName\tPercentage\n");
while(ptr)
{
printf("%d\t%s\t%f\n\033[0m",ptr->rollno,ptr->name,ptr->percentage);
ptr=ptr->next;
}
}

int stud_count(sll *ptr) //// count
{
int c=0;
while(ptr)
{
c++;
ptr=ptr->next;
}
return c;
}
