CC = clang
C_OPTS = $(MAC_OPTS) -std=gnu11 -g 
TEST_OPTS = -I/usr/local/include -L/usr/local/lib test/test.c 

clean:
	rm -rf dist 
    
prep:
	mkdir dist

compile: det.a test.bin

test.bin: test/test.c
	$(CC) $(C_OPTS) $(TEST_OPTS) -o dist/test.bin -lm -lcheck -lsubunit

det.a:
	$(CC) -c $(C_OPTS) $(TEST_OPTS) -o dist/det.o 
	ar rcs dist/libdet.a ./dist/det.o
	cp dist/libdet.a ../lib
	cp src/det.h ../lib

run: clean prep compile
	./dist/test.bin

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump