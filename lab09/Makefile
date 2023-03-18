CC = clang
C_OPTS = $(MAC_OPTS) -std=gnu11 -g 
TEST_OPTS = -I/src -I/usr/local/include -L/usr/local/lib 
TEST_FILES = src/det.c test/test.c -lm -lcheck -lsubunit

clean:
	rm -rf dist 
prep:
	mkdir dist
compile: test/test.c
	$(CC) $(C_OPTS) $(TEST_OPTS) -o dist/my_test $(TEST_FILES)
run: clean prep compile
	./dist/my_test
check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump


