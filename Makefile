######################################
ROOT_DIR = .
EXE_NAME = tqm
TARGET = deal.o hqimen.o calendar.o public.o
TARGET_RELEASE = rdeal.o rhqimen.o rcalendar.o rpublic.o
CC = g++
MAKE = make
######################################
vpath %.h include
vpath %.cpp src
INCLUDE_DIR = $(ROOT_DIR)/include
CFLAGS = -g -Wall

release: $(TARGET_RELEASE)
	$(CC) -o $(EXE_NAME) main.cpp -I$(INCLUDE_DIR) $(TARGET_RELEASE)
	- rm -f *.o
rdeal.o: calendar.h calendar.cpp deal.h deal.cpp
	$(CC) -o rdeal.o -c src/deal.cpp -I$(INCLUDE_DIR)
rcalendar.o: calendar.h calendar.cpp
	$(CC) -o rcalendar.o -c src/calendar.cpp -I$(INCLUDE_DIR)
rhqimen.o: calendar.h calendar.cpp deal.h deal.cpp hqimen.cpp hqimen.h
	$(CC) -o rhqimen.o -c src/hqimen.cpp -I$(INCLUDE_DIR)
rpublic.o: public.h public.cpp
	$(CC) -o rpublic.o -c src/public.cpp -I$(INCLUDE_DIR)

debug: $(TARGET)
	$(CC) $(CFLAGS) -o $(EXE_NAME) main.cpp -I$(INCLUDE_DIR) $(TARGET)
deal.o: calendar.h calendar.cpp deal.h deal.cpp
	$(CC) $(CFLAGS) -c src/deal.cpp -I$(INCLUDE_DIR)
calendar.o: calendar.h calendar.cpp
	$(CC) $(CFLAGS) -c src/calendar.cpp -I$(INCLUDE_DIR)
hqimen.o: calendar.h calendar.cpp deal.h deal.cpp hqimen.cpp hqimen.h
	$(CC) $(CFLAGS) -c src/hqimen.cpp -I$(INCLUDE_DIR)
public.o: public.h public.cpp
	$(CC) $(CFLAGS) -c src/public.cpp -I$(INCLUDE_DIR)

clean:
	- rm -f *.o
	- rm -f $(EXE_NAME)