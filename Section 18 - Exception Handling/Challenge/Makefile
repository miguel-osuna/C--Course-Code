# Declared variables
CC = g++
CFLAGS = -c -Wall -std=c++14 -g

# Generate executable file
all: main

main: main.o account.o savings_account.o trust_account.o check_account.o i_print.o
	$(CC) main.o account.o savings_account.o trust_account.o check_account.o i_print.o -o main

# Generate object files
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

account.o: account.cpp
	$(CC) $(CFLAGS) account.cpp

savings_account.o: savings_account.cpp
	$(CC) $(CFLAGS) savings_account.cpp

trust_account.o: trust_account.cpp
	$(CC) $(CFLAGS) trust_account.cpp

check_acccount.o: check_account.cpp
	$(CC) $(CFLAGS) check_account.cpp

i_print.o: i_print.cpp
	$(CC) $(CFLAGS) i_print.cpp

# Delete generated object files
clean:
	rm -rf *o main
