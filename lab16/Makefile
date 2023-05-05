CC = clang
LAB_OPTS =  -I./src -I/usr/local/include -L/usr/local/lib src/discipline.c
C_OPTS = $(MAC_OPTS) -std=c18 -g -fsanitize=address $(LAB_OPTS)


clean:
	rm -rf dist 

prep:
	mkdir dist

compile: main.bin
	
main.bin: src/main.c
	$(CC) $(C_OPTS) src/main.c -o dist/main.bin

test.bin: 
	$(CC) $(C_OPTS) $(TEST_OPTS) test/test.c -o dist/test.bin -lcheck -lsubunit

run: clean prep compile
	./dist/main.bin

test: clean prep test.bin
	./dist/test.bin

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump

leak-check: clean prep compile
    ASAN_OPTIONS=detect_leaks=1 dist/main.bin
