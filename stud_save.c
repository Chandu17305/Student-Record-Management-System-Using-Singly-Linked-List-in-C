#include"header.h"
void stud_save(sll *ptr) //// save
{
FILE *fp;
fp=fopen("student.dat","w");
if(ptr==0)
{
printf("\033[32mNo Data Present\033[0m\n");
return;
}
while(ptr)
{
fprintf(fp,"%d %s %f \n",ptr->rollno,ptr->name,ptr->percentage);
ptr=ptr->next;
}
printf("\033[30mFile Saved\033[0m\n");
}
