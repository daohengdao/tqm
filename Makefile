######################################
ROOT_DIR = .
EXE_NAME = tqm
EXE_NAME_WIN = tqm.exe
TARGET = deal.o hqimen.o calendar.o public.o
TARGET_RELEASE = rdeal.o rhqimen.o rcalendar.o rpublic.o
WIN_TARGET = win-deal.obj win-hqimen.obj win-calendar.obj win-public.obj win-main.obj
WIN_TARGET_RELEASE = win-rdeal.obj win-rhqimen.obj win-rcalendar.obj win-rpublic.obj win-rmain.obj
CC = g++
VSCC = cl
VSLINK = link
MAKE = make
######################################
vpath %.h include
vpath %.cpp src
INCLUDE_DIR = $(ROOT_DIR)/include
CFLAGS = -g -Wall
WINCFLAGS = /Zi /c /EHsc /source-charset:utf-8 /execution-charset:gbk /nologo
WINCFLAGS_RELEASE = /c /EHsc /source-charset:utf-8 /execution-charset:gbk /nologo

release: $(TARGET_RELEASE)
	$(CC) -o $(EXE_NAME) main.cpp -I$(INCLUDE_DIR) $(TARGET_RELEASE)
	- rm -f *.o
rdeal.o: calendar.h calendar.cpp deal.h deal.cpp
	$(CC) -o rdeal.o -c src/deal.cpp -I$(INCLUDE_DIR)
rcalendar.o: calendar.h calendar.cpp
	$(CC) -o rcalendar.o -c src/calendar.cpp -I$(INCLUDE_DIR)
rhqimen.o: calendar.h calendar.cpp hqimen.cpp hqimen.h
	$(CC) -o rhqimen.o -c src/hqimen.cpp -I$(INCLUDE_DIR)
rpublic.o: public.h public.cpp
	$(CC) -o rpublic.o -c src/public.cpp -I$(INCLUDE_DIR)

win-mingw-release: min-rdeal.o min-rcalendar.o min-rhqimen.o min-rpublic.o
	$(CC) -o $(EXE_NAME_WIN) main.cpp -I$(INCLUDE_DIR) min-rdeal.o min-rcalendar.o min-rhqimen.o min-rpublic.o
	- del *.o
min-rdeal.o: calendar.h calendar.cpp deal.h deal.cpp
	$(CC) -o min-rdeal.o -c src/deal.cpp -I$(INCLUDE_DIR) -fexec-charset=GBK
min-rcalendar.o: calendar.h calendar.cpp
	$(CC) -o min-rcalendar.o -c src/calendar.cpp -I$(INCLUDE_DIR) -fexec-charset=GBK
min-rhqimen.o: calendar.h calendar.cpp hqimen.cpp hqimen.h
	$(CC) -o min-rhqimen.o -c src/hqimen.cpp -I$(INCLUDE_DIR) -fexec-charset=GBK
min-rpublic.o: public.h public.cpp
	$(CC) -o min-rpublic.o -c src/public.cpp -I$(INCLUDE_DIR) -fexec-charset=GBK

debug: $(TARGET)
	$(CC) $(CFLAGS) -o $(EXE_NAME) main.cpp -I$(INCLUDE_DIR) $(TARGET)
deal.o: calendar.h calendar.cpp deal.h deal.cpp
	$(CC) $(CFLAGS) -c src/deal.cpp -I$(INCLUDE_DIR)
calendar.o: calendar.h calendar.cpp
	$(CC) $(CFLAGS) -c src/calendar.cpp -I$(INCLUDE_DIR)
hqimen.o: calendar.h calendar.cpp hqimen.cpp hqimen.h
	$(CC) $(CFLAGS) -c src/hqimen.cpp -I$(INCLUDE_DIR)
public.o: public.h public.cpp
	$(CC) $(CFLAGS) -c src/public.cpp -I$(INCLUDE_DIR)

win-debug: $(WIN_TARGET)
	$(VSLINK) /OUT:tqm.exe /SUBSYSTEM:CONSOLE $(WIN_TARGET)
win-deal.obj: calendar.h calendar.cpp deal.h deal.cpp
	$(VSCC) $(WINCFLAGS) /Fowin-deal.obj /I$(INCLUDE_DIR) src/deal.cpp
win-calendar.obj: calendar.h calendar.cpp
	$(VSCC) $(WINCFLAGS) /Fowin-calendar.obj /I$(INCLUDE_DIR) src/calendar.cpp
win-hqimen.obj: calendar.h calendar.cpp hqimen.cpp hqimen.h
	$(VSCC) $(WINCFLAGS) /Fowin-hqimen.obj /I$(INCLUDE_DIR) src/hqimen.cpp
win-public.obj: public.h public.cpp
	$(VSCC) $(WINCFLAGS) /Fowin-public.obj /I$(INCLUDE_DIR) src/public.cpp
win-main.obj: main.cpp
	$(VSCC) $(WINCFLAGS) /Fowin-main.obj /I$(INCLUDE_DIR) main.cpp

win-release: $(WIN_TARGET_RELEASE)
	$(VSLINK) /OUT:tqm.exe /SUBSYSTEM:CONSOLE $(WIN_TARGET_RELEASE)
	- del *.obj
win-rdeal.obj: calendar.h calendar.cpp deal.h deal.cpp
	$(VSCC) $(WINCFLAGS_RELEASE) /Fowin-rdeal.obj /I$(INCLUDE_DIR) src/deal.cpp
win-rcalendar.obj: calendar.h calendar.cpp
	$(VSCC) $(WINCFLAGS_RELEASE) /Fowin-rcalendar.obj /I$(INCLUDE_DIR) src/calendar.cpp
win-rhqimen.obj: calendar.h calendar.cpp hqimen.cpp hqimen.h
	$(VSCC) $(WINCFLAGS_RELEASE) /Fowin-rhqimen.obj /I$(INCLUDE_DIR) src/hqimen.cpp
win-rpublic.obj: public.h public.cpp
	$(VSCC) $(WINCFLAGS_RELEASE) /Fowin-rpublic.obj /I$(INCLUDE_DIR) src/public.cpp
win-rmain.obj: main.cpp
	$(VSCC) $(WINCFLAGS_RELEASE) /Fowin-rmain.obj /I$(INCLUDE_DIR) main.cpp

clean:
	- rm -f *.o
	- rm -f $(EXE_NAME)
win-clean:
	- del *.obj
	- del *.ilk
	- del *.pdb
min-clean:
	- del *.o