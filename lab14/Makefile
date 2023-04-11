CC = clang
LAB_OPTS =  -I./src -I./assets -I/usr/local/include -L/usr/local/lib 
C_OPTS = $(MAC_OPTS) -std=c18 -Weverything -g -fsanitize=address $(LAB_OPTS)


clean:
	rm -rf dist 

prep:
	mkdir dist

compile: main.bin
	
main.bin: src/main.c
	$(CC) $(C_OPTS) src/lib.c src/main.c -o dist/main.bin

run: clean prep compile
	clear
	./dist/main.bin

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump

leak-check: clean prep compile
    ASAN_OPTIONS=detect_leaks=1 dist/main.bin
