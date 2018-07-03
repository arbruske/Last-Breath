
OBJS = main.o Player.o Game.o Space.o Bathroom.o CommandRoom.o Lounge.o OxygenRoom.o QuarterDeck.o SickBay.o
CC = g++ -std=c++11
CFLAGS = -Wall -c
LFLAGS = -Wall

FinalProject: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o FinalProject

main.o: main.cpp Game.hpp
	$(CC) $(CFLAGS) main.cpp
	
Player.o: Player.hpp Player.cpp Space.hpp
	$(CC) $(CFLAGS) Player.cpp
	
Game.o: Game.hpp Game.cpp Space.hpp Player.hpp CommandRoom.hpp Bathroom.hpp Lounge.hpp OxygenRoom.hpp QuarterDeck.hpp SickBay.hpp
	$(CC) $(CFLAGS) Game.cpp

Space.o: Space.hpp Space.cpp
	$(CC) $(CFLAGS) Space.cpp
	
Bathroom.o: Bathroom.hpp Bathroom.cpp Space.hpp
	$(CC) $(CFLAGS) Bathroom.cpp

CommandRoom.o: CommandRoom.hpp CommandRoom.cpp Space.hpp
	$(CC) $(CFLAGS) CommandRoom.cpp

Lounge.o: Lounge.hpp Lounge.cpp Space.hpp
	$(CC) $(CFLAGS) Lounge.cpp

OxygenRoom.o: OxygenRoom.hpp OxygenRoom.cpp Space.hpp
	$(CC) $(CFLAGS) OxygenRoom.cpp

QuarterDeck.o: QuarterDeck.hpp QuarterDeck.cpp Space.hpp
	$(CC) $(CFLAGS) QuarterDeck.cpp

SickBay.o: SickBay.hpp SickBay.cpp Space.hpp
	$(CC) $(CFLAGS) SickBay.cpp

clean:
	\rm *.o *~FinalProject
	
#Source: https://www.cs.umd.edu/class/fall2002/cmsc214/Tutorial/makefile.html