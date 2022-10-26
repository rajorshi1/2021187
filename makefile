main: maincode.c cat date ls mkdir rm
	gcc -lpthread maincode.c -o main -lpthread

cat: cat.c
	gcc cat.c -o cat

date: date.c
	gcc date.c -o date
ls: ls.c
	gcc ls.c -o ls

mkdir: mkdir.c
	gcc mkdir.c -o mkdir

rm: rm.c
	gcc rm.c -o rm

clean:
	rm -rf cat date ls main mkdir rm
