#include"header.h"
void main()
{
sll *head=0;
unsigned char op;
while(1)
{
printf("***** STUDENT RECORD MENU *****\n");
printf("a/A : add new record\nd/D : delete a record\ns/S : show the list\nm/M : modify a record\nv/V : save\ne/E : exit\nt/T : sort the list\nl/L : delete all the records\nr/R : reverse the list\n");
printf("Enter your choice:\n");
scanf(" %c",&op);
switch(op)
{
case 'a': stud_add(&head);break;
case 'A': stud_add(&head);break;
case 's': stud_show(head);break;
case 'S': stud_show(head);break;
case 'e': exit(0);
case 'E': exit(0);
case 'd': stud_del(&head);break;
case 'D': stud_del(&head);break;
case 'l': stud_del_all(&head);break;
case 'L': stud_del_all(&head);break;
case 'v': stud_save(head);break;
case 'V': stud_save(head);break;
case 't': stud_sort(&head);break;
case 'T': stud_sort(&head);break;
case 'r': stud_rev(&head);break;
case 'R': stud_rev(&head);break;
case 'm': stud_mod(&head);break;
case 'M': stud_mod(&head);break;
default : printf("Unknown Option\n");
}
}
}
