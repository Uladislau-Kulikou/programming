CC = clang
C_OPTS = $(MAC_OPTS) -std=gnu11 -g 
TEST_OPTS = -I/usr/local/include -L/usr/local/lib -lm

clean:
	rm -rf dist 
    
prep:
	mkdir dist

compile: main.bin

main.bin: src/main.c
	$(CC) $(C_OPTS) $(TEST_OPTS) $< -ldet -o ./dist/$@

run: clean prep compile
	./dist/main.bin

check:
	clang-format --verbose -dry-run --Werror src/*
	clang-tidy src/*.c -checks=-readability-uppercase-literal-suffix,-readability-magic-numbers,-clang-analyzer-deadcode.DeadStores,-clang-analyzer-security.insecureAPI.rand
	rm -rf src/*.dump