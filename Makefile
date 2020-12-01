default:
	gcc cat.c -o cat
	gcc date.c -o date
	gcc ls.c -o ls
	gcc mkdir.c -o mkdir
	gcc rm.c -o rm
	gcc linux.c -o linux
	./linux

c_cat:
	gcc cat.c -o cat

c_date:
	gcc date.c -o date

c_ls:
	gcc ls.c -o ls

c_mkdir:
	gcc mkdir.c -o mkdir
c_rm:
	gcc rm.c -o rm	

c_linux:
	gcc linux.c -o linux	



