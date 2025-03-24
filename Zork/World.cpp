#include <iostream>
#include <World.h>
#include <Entity.h>
#include <Creature.h>


using namespace std;

World::World()
{
	//Create rooms
	Room* entry = new Room("Entry", "The room is dimly lit, with shadows stretching along the walls. The air feels heavy, carrying the scent of time and dust. The floor creaks softly beneath your steps.");
	Room* kitchen = new Room("Kitchen", "A faint aroma of old spices lingers in the air. The walls are stained from years of use, and the cold atmosphere makes the room feel long abandoned.");
	Room* dining_room = new Room("Dining room", "The space feels eerily silent, as if waiting for an unseen presence to return. The air is stale, carrying whispers of past gatherings now long forgotten.");
	Room* library = new Room("Library", "A deep silence fills the room, broken only by the occasional creak of settling wood. The air is thick with the scent of aged paper and ink, remnants of stories left unread.");
	Room* cellar = new Room("Cellar", "The air is damp and cool, carrying a faint musty scent. The darkness here feels deeper, pressing in from all sides, and the silence is absolute.");
	Room* studio = new Room("Studio", "A faint sense of focus and solitude lingers in the air, as if the room still remembers moments of intense concentration. Dust hangs in the stillness, undisturbed.");
	Room* gallery = new Room("Gallery", "A strange hush fills the space, as if the very walls are holding their breath. The dim light creates shifting patterns, distorting the edges of the room.");
	Room* garden = new Room("Garden", "The scent of earth and damp greenery lingers in the air. The wind carries faint rustling sounds, their source unseen, as if the space is alive in its own quiet way.");

}