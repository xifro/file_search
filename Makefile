all:
	gcc -c file_search.c -o file_search.o
	ar rcs libfile_search.a file_search.o
	gcc -o file_searcher main.c -L. -lfile_search

clear:
	rm file_search.o libfile_search.a file_searcher
