#include"header.h"

void del_rollno(sll **p,int n)
{
        sll *d=*p,*pre=0;
        while(d)
        {
                if(d->rollno==n)
                {
                        if(0==pre)
                        {
                                *p=d->next;
                        }
                        else
                                pre->next=d->next;
                        free(d);
                        return;
                        d=pre->next;
                }
                if(d)
                {
                        pre=d;
                        d=d->next;
                }
        }
}
void stud_del(sll **ptr)
{
        if(*ptr==0)
        {
                printf("No Nodes\n");
                return;
        }
        char choice;
        printf("R/r:del based on rollno\nN/n:del based on name\n");
        printf("Enter your choice\n");
        scanf(" %c",&choice);
        if((choice=='R')||(choice=='r'))
        {
                sll *del=*ptr;
                int num;
                printf("Enter rollno\n");
                scanf("%d",&num);
                while(del)
                {
                        if(num==del->rollno)
                                del_rollno(ptr,del->rollno);
                        del=del->next;
                }
                printf("\033[33mNode Deleted\033[0m\n");
        }
        else if((choice=='N')||(choice=='n'))
        {
                sll *del=*ptr;
                int flag=0;
                char s[20];
                printf("Enter name\n");
                scanf(" %s",s);
                while(del)
                {
                        if(strcmp(s,del->name)==0)
                        {
                                printf("%d %s %f\n",del->rollno,del->name,del->percentage);
                                flag++;
                        }
                        del=del->next;
                }
                if(flag==1)
                {
                        del=*ptr;
                        while(del)
                        {
                                if(strcmp(s,del->name)==0)
                                        del_rollno(ptr,del->rollno);
                                del=del->next;
                        }
                }
                else if(flag>1)
                {
                        int num;
                        printf("\033[33mThere are %d no.of identical names present in the record\033[0m\n",flag);
                        printf("Enter rollno to delete the node\n");
                        scanf("%d",&num);
                        del_rollno(ptr,num);
                }
                printf("\033[33mNode Deleted\033[0m\n");
        }
        else
                printf("Unknown choice\n");
}

void stud_del_all(sll **ptr)   /// del all
{
sll *del;
if(*ptr==0)
{
printf("\033[32mNo Records\033[0m\n");
return;
}
while(*ptr)
{
del=*ptr;
*ptr=del->next;
free(del);
}
printf("\033[30mAll Nodes Deleted\033[0m\n");
}
