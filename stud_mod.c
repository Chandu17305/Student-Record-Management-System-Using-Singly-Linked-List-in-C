#include"header.h"
void stud_rev(sll **ptr)
{
if(*ptr==0)
{
printf("No Nodes\n");
return;
}
int c=stud_count(*ptr);
if(c>1)
{
sll **a=malloc(sizeof(sll *)*c);
sll *p=*ptr;
int i=0;
while(p)
{
a[i++]=p;
p=p->next;
}
for(i=c-1;i>=0;i--)
a[i]->next=a[i-1];
a[0]->next=0;
*ptr=a[c-1];
}
printf("\033[33mData is Reversed\033[0m\n");
}

void stud_sort(sll **ptr)
{
char ch;
printf("N/n: sort with name\nP/p: sort with percentage\n");
printf("Enter your choice:\n");
scanf(" %c",&ch);
if((ch=='n')||(ch=='N'))
{
if(*ptr==0)
{
printf("No Nodes\n");
return;
}
sll *a,*b,t;
a=*ptr;
int i,j;
for(i=0;a;i++)
{
b=a->next;
for(j=0;b;j++)
{
if(strcmp(a->name,b->name)>0)
{
t.rollno=a->rollno;
strcpy(t.name,a->name);
t.percentage=a->percentage;
a->rollno=b->rollno;
strcpy(a->name,b->name);
a->percentage=b->percentage;
b->rollno=t.rollno;
strcpy(b->name,t.name);
b->percentage=t.percentage;
}
b=b->next;
}
a=a->next;
}
printf("\033[33mData is sorted based on name\n\033[0m");
}
else if((ch=='p')||(ch=='P'))
{
if(*ptr==0)
{
printf("\033[32mNo Nodes\033[0m\n");
return;
}
sll *a,*b,t;
a=*ptr;
int i,j;
for(i=0;a;i++)
{
b=a->next;
for(j=0;b;j++)
{
if(b->percentage>a->percentage)
{
t.rollno=a->rollno;
strcpy(t.name,a->name);
t.percentage=a->percentage;
a->rollno=b->rollno;
strcpy(a->name,b->name);
a->percentage=b->percentage;
b->rollno=t.rollno;
strcpy(b->name,t.name);
b->percentage=t.percentage;
}
b=b->next;
}
a=a->next;
}
printf("\033[33mData is sorted based on percentage\n\033[0m");
}
else
printf("\033[33mUnknown choice for sorting\033[0m\n");
}

void stud_mod(sll **ptr)
{
        sll *p=*ptr;
        if(*ptr==0)
        {
                printf("\033[32mNo Records\033[0m\n");
                return;
        }
        int flag=0;
        char ch;
        printf("\033[34mSearch to Modify a Record \n");
        printf("R/r:based on roll no \nN/n:based on name\nP/p:based on percentage\n");
        printf("Enter your choice\033[0m\n");
        scanf(" %c",&ch);
        if((ch=='r')||(ch=='R'))
        {
                int num;
                printf("Enter rollno for search\n");
                scanf("%d",&num);
                mod_rollno(*ptr,num);
        }
        else if((ch=='n')||(ch=='N'))
        {
                char s[10];
                printf("Enter name for search\n");
                scanf("%s",s);
                while(p){
                        if(strcmp(s,p->name)==0){
                                printf("\033[35m%d %s %f\n\033[0m",p->rollno,p->name,p->percentage);
                                flag++;
                        }
                        p=p->next;
                }
                if(flag==1)
                {
int rn;
                        p=*ptr;
                        while(p)
                        {
                                if(strcmp(s,p->name)==0)
                                 rn=p->rollno;
p=p->next;
                        }
mod_rollno(*ptr,rn);
                }
                else if(flag>1)
                {
                        printf("\033[35mThere are %d no.of records present based on your input\n",flag);
                        int num;
                        printf("Enter rollno of the record to modify\033[0m\n");
                        scanf("%d",&num);
                        mod_rollno(*ptr,num);
                }
        }
        else if((ch=='p')||(ch=='P'))
        {
                float f;
                printf("Enter percentage for search\n");
                scanf("%f",&f);
                while(p){
                        if(f==p->percentage){
                                printf("\033[35m%d %s %f\n\033[0m",p->rollno,p->name,p->percentage);
                                flag++;
                        }
                        p=p->next;
                }
                if(flag==1)
                {
int rn;
                        p=*ptr;
                        while(p)
                        {
                                if(f==p->percentage)
                                        rn=p->rollno;
p=p->next;
                        }
mod_rollno(*ptr,rn);
                }
                else if(flag>1)
                {
                        printf("\033[35mThere are %d no.of records present based on your input\n",flag);
                        int num;
                        printf("Enter rollno of the record to modify\n\033[0m");
                        scanf("%d",&num);
                        mod_rollno(*ptr,num);
                }
        }
}

void mod_rollno(sll *p,int n)
{
while(p){
if(n==p->rollno)
{
printf("\033[36mSelected record:%d %s %f\n",p->rollno,p->name,p->percentage);
        char d;
        printf("N/n:modify name\nP/p:modify percentage\n");
        printf("Enter which you want to modify\n");
        scanf(" %c",&d);
        if((d=='n')||(d=='N'))
        {
                char st[20];
                printf("Enter new name\033[0m\n");
                scanf("%s",st);
                strcpy(p->name,st);
                printf("\033[33mModified Record\n%d %s %f\n\033[0m",p->rollno,p->name,p->percentage);
        }
        else if((d=='p')||(d=='P'))
        {
                float fl;
                printf("Enter new percentage\033[0m\n");
                scanf("%f",&fl);
                p->percentage=fl;
                printf("\033[33mModified Record\033[0m\n%d %s %f\n",p->rollno,p->name,p->percentage);
        }
        else
                printf("Unknown option\033[0m\n");
}
p=p->next;
}
}
