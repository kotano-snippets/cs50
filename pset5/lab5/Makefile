speller:
	clang -ggdb3 -O0 -Qunused-arguments -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -c -o inheritance inheritance.c

lint:
	/home/${USER}/.local/bin/style50 inheritance.c

check: lint
	/home/${USER}/.local/bin/check50 --local cs50/labs/2021/x/inheritance
