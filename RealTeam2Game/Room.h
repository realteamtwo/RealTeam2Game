#include <string>
#include <iostream>
#include <vector>
using namespace std;
#ifndef ROOM
#define ROOM



class Room
{
private:
	// Defining the Room Layout and Info
	bool room_layout[3][3];
	std::string roomName = "BAD NAME";
	std::string roomDescription = "BAD NAME";
	int roomID = -1;
	// Connections between rooms

public:
	Room(std::string name, std::string des, int id);

	string GetRoomName();
	string GetRoomDescript();
};


class RoomManager
{
public:
	std::vector<Room> roomList;
	int totalRooms = 0;

	void createRoom(std::string name, std::string description);

private:
	int currentRoomID = -1;
};
#endif