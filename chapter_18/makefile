CC = g++
OBJS = main.o Employee.o Production_worker.o Shift_supervisor.o Team_leader.o Linked_list.o cpp_utilities.o
CFLAGS = -c -Werror
LFLAGS = -Werror

all: main

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

employee.o: Employee.cpp
	$(CC) $(CFLAGS) Employee.cpp

production_worker.o: Production_worker.cpp
	$(CC) $(CFLAGS) Production_worker.cpp

shift_supervisor.o: Shift_supervisor.cpp
	$(CC) $(CFLAGS) Shift_supervisor.cpp

team_leader.o: Team_leader.cpp
	$(CC) $(CFLAGS) Team_leader.cpp

linked_list.o: Linked_list.cpp
	$(CC) $(CFLAGS) Linked_list.cpp

cpp_utilities.o: cpp_utilities.cpp
	$(CC) $(CFLAGS) cpp_utilities.cpp

clean:
	rm *.o
	rm main

rebuild: clean main
