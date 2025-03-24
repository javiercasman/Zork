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
	Room* end = new Room("End", "Congratulations! You made it to the end.\n Thanks for playing :)\n")

	//Create exits (cada puerta es una Exit)
	Exit* entry_north = new Exit("Entry North", "The room feels still, but you notice a faint draft coming from the north. The scent of aged spices and something long forgotten beckons you to the doorway ahead.", 
								 entry, NORTH, entry, kitchen);
	Exit* kitchen_south = new Exit("Kitchen South", "", kitchen, SOUTH, kitchen, entry);
	Exit* kitchen_east = new Exit("Kitchen East", "To the east, a darkened passageway stretches forward. The heavy air grows denser as you move, and the stillness is palpable, inviting you to step into the unknown.",
								  kitchen, EAST, kitchen, dining_room);
	Exit* dining_room_west = new Exit("Dining Room West", "", dining_room, WEST, dining_room, kitchen);
	Exit* dining_room_east = new Exit("Dining Room East", "To the east, a tall and imposing doorway stands. Its frame blends almost seamlessly with the shadows. There's a strange resistance here, as if the passage doesn’t want to be disturbed.",
									  dining_room, WEST, dining_room, library);//lo de 'una vez desbloqueada'?
	Exit* library_west = new Exit("Library West", "", library, WEST, library, dining_room);
	Exit* library_south = new Exit("Library South", "To the south, you notice something odd—almost as if the wall is too perfect. With a closer inspection, you find a faint outline in the stone, a hidden passage leading downward.",
								   library, SOUTH, library, cellar);
	Exit* cellar_north = new Exit("Cellar North", "", cellar, NORTH, cellar, library);
	Exit* cellar_west = new Exit("Cellar West", "To the west, a narrow corridor leads into an even deeper silence. The dampness in the air grows heavier, and the oppressive quiet swallows your every step.",
								 cellar, WEST, cellar, studio);
	Exit* cellar_south = new Exit("Cellar South", "In the southern corner, the darkness seems to thicken. There is something here, something you can feel but not quite see, drawing you into the shadows beyond.",
								  cellar, SOUTH, cellar, gallery);
	Exit* cellar_east = new Exit("Cellar East", "To the east, a heavy obstruction halts your path. It resists, unmoving. Something prowls nearby, its presence brushing against the silence.",
								 cellar, EAST, cellar, garden);
	Exit* studio_east = new Exit("Studio East", "", studio, EAST, studio, cellar);
	Exit* gallery_north = new Exit("Gallery North", "", gallery, NORTH, gallery, cellar);
	Exit* garden_west = new Exit("Garden West", "", garden, WEST, garden, cellar);
	Exit* garden_east = new Exit("Garden East", "To the east, the air feels lighter, less oppressive. The path ahead beckons with an almost otherworldly pull, drawing you toward the final destination of your journey.",
								 garden, EAST, garden, end);


}