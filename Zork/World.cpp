#include <iostream>
#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Exit.h"
#include "Room.h"

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
	Room* end = new Room("End", "Congratulations! You made it to the end.\n Thanks for playing :)\n");

	//Create exits (cada puerta es una Exit)
	Exit* entry_north = new Exit("north", "The room feels still, but you notice a faint draft coming from the north. The scent of aged spices and something long forgotten beckons you to the doorway ahead.", 
								 entry, /*NORTH, */kitchen);
	Exit* kitchen_south = new Exit("south", "", kitchen, /*SOUTH, */entry);
	Exit* kitchen_east = new Exit("east", "To the east, a darkened passageway stretches forward. The heavy air grows denser as you move, and the stillness is palpable, inviting you to step into the unknown.",
								  kitchen, /*EAST, */dining_room);
	Exit* dining_room_west = new Exit("west", "", dining_room, /*WEST, */kitchen);
	Exit* dining_room_east = new Exit("east", "To the east, a tall and imposing doorway stands. Its frame blends almost seamlessly with the shadows. There's a strange resistance here, as if the passage doesn’t want to be disturbed.",
									  dining_room, /*WEST, */library);//lo de 'una vez desbloqueada'?
	Exit* library_west = new Exit("west", "", library, /*WEST, */dining_room);
	Exit* library_south = new Exit("south", "To the south, a massive bookshelf stands against the wall, filled with dusty tomes. Something about it feels... off. The books are perfectly arranged, almost too perfectly. Upon closer inspection, you notice faint scratch marks on the floor, as if the bookshelf has been moved before.",
								   library, /*SOUTH, */cellar);
	Exit* cellar_north = new Exit("north", "", cellar, /*NORTH, */library);
	Exit* cellar_west = new Exit("west", "To the west, a narrow corridor leads into an even deeper silence. The dampness in the air grows heavier, and the oppressive quiet swallows your every step.",
								 cellar, /*WEST, */studio);
	Exit* cellar_south = new Exit("south", "In the southern corner, the darkness seems to thicken. There is something here, something you can feel but not quite see, drawing you into the shadows beyond.",
								  cellar, /*SOUTH, */gallery);
	Exit* cellar_east = new Exit("east", "To the east, a narrow staircase leads upward, vanishing into the darkness above. At the top, a heavy wooden door blocks the way, its surface scarred by time and neglect. You try the handle—it doesn’t budge. A sturdy lock keeps it sealed, its key nowhere in sight. As you step back, a chill runs down your spine—something lurks nearby, watching, waiting.",
								 cellar, /*EAST, */garden);
	Exit* studio_east = new Exit("east", "", studio, /*EAST, */cellar);
	Exit* gallery_north = new Exit("north", "", gallery, /*NORTH, */cellar);
	Exit* garden_west = new Exit("west", "", garden, /*WEST, */cellar);
	Exit* garden_east = new Exit("east", "To the east, a faint light glimmers through the shadows, and the air feels charged with anticipation. Before you, a weathered door stands sealed with a heavy chain, its surface marked by time. The path beyond beckons, as if waiting for something—or someone—to set it in motion.",
								 garden, /*EAST, */end);

	//Create items
	Item* mailbox = new Item("mailbox", "There is a weathered mailbox, its paint chipped and faded. It looks like it hasn’t been used in quite some time, but something about it seems important.");
}