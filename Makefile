target = main.o stud_add.o stud_save.o stud_show.o stud_del.o stud_mod.o
CC = cc
exe: ${target}
        ${CC} ${target} -o exe
main.o: main.c
        ${CC} -c $^
stud_add.o: stud_add.c
        ${CC} -c $^
stud_save.o: stud_save.c
        ${CC} -c $^
stud_show.o: stud_show.c
        ${CC} -c $^
stud_del.o: stud_del.c
        ${CC} -c $^
stud_mod.o: stud_mod.c
        ${CC} -c $^
clean:
        @echo "Cleaning up......"
        @rm -vv *.o
