build:
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -lm -o recover recover.c

lint:
	/home/${USER}/.local/bin/style50 recover.c

check: lint
	check50 --local cs50/problems/2021/x/recover
