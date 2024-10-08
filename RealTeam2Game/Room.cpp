#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;


Room::Room(string name, string des, int id)
{
	// Initalizing Grid 
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			room_layout[x][y] = false;
		}
	}
	roomName = name;
	roomDescription = des;
	roomID = id;

}

string Room::GetRoomName()
{
	return roomName;
}

string Room::GetRoomDescript()
{
	return roomDescription;
}

void RoomManager::createRoom(string name, string description)
{
	roomList.push_back(Room(name, description, totalRooms));
	if (totalRooms == 0)
	{
		currentRoomID = 0;
	}
	totalRooms += 1;
}





