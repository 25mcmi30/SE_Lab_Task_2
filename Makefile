CC = gcc
CFLAGS = -Wall -Wextra -std=c11

TARGET = student_database
OBJ = main.o student.o validation.o result.o stats.o fileio.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

main.o: main.c student.h fileio.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

validation.o: validation.c validation.h student.h
	$(CC) $(CFLAGS) -c validation.c

result.o: result.c result.h student.h
	$(CC) $(CFLAGS) -c result.c

stats.o: stats.c stats.h student.h
	$(CC) $(CFLAGS) -c stats.c

fileio.o: fileio.h student.h validation.h result.h stats.h
	$(CC) $(CFLAGS) -c fileio.c

clean:
	rm -f *.o $(TARGET)