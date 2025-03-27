#include <iostream>
#include "World.h"
#include "Entity.h"
#include "Creature.h"
#include "Exit.h"
#include "Room.h"
#include "Item.h"
#include "Npc.h"
#include "Player.h"

using namespace std;

World::World()
{
	//Initialize rooms
	Room* entry = new Room("Entry", "The room is dimly lit, with shadows stretching along the walls. The air feels heavy, carrying the scent of time and dust. The floor creaks softly beneath your steps.");
	Room* kitchen = new Room("Kitchen", "A faint aroma of old spices lingers in the air. The walls are stained from years of use, and the cold atmosphere makes the room feel long abandoned.");
	Room* dining_room = new Room("Dining room", "The space feels eerily silent, as if waiting for an unseen presence to return. The air is stale, carrying whispers of past gatherings now long forgotten.");
	Room* library = new Room("Library", "A deep silence fills the room, broken only by the occasional creak of settling wood. The air is thick with the scent of aged paper and ink, remnants of stories left unread.");
	Room* cellar = new Room("Cellar", "The air is damp and cool, carrying a faint musty scent. The darkness here feels deeper, pressing in from all sides, and the silence is absolute.");
	Room* studio = new Room("Studio", "A faint sense of focus and solitude lingers in the air, as if the room still remembers moments of intense concentration. Dust hangs in the stillness, undisturbed.");
	Room* gallery = new Room("Gallery", "A strange hush fills the space, as if the very walls are holding their breath. The dim light creates shifting patterns, distorting the edges of the room.");
	Room* garden = new Room("Garden", "The scent of earth and damp greenery lingers in the air. The wind carries faint rustling sounds, their source unseen, as if the space is alive in its own quiet way.");
	Room* end = new Room("End", "Congratulations! You made it to the end.\n Thanks for playing :)\n");

	entities.push_back(entry);
	entities.push_back(kitchen);
	entities.push_back(dining_room);
	entities.push_back(library);
	entities.push_back(cellar);
	entities.push_back(studio);
	entities.push_back(gallery);
	entities.push_back(garden);
	entities.push_back(end);

	//Initialize creatures
	Npc* troll = new Npc("troll", "A hulking figure stands before you, its grotesque face twisted into a sneer. With thick, ragged skin covered in patches of moss, the troll towers over you, exuding a menacing presence. Its eyes gleam with malice, and a low growl rumbles from deep within its throat.",
		cellar, 100, 25);//el parent ira cambiando, mecanica de q el bicho se vaya moviendo
	player = new Player("player", "", entry, 100);

	entities.push_back(troll);
	entities.push_back(player);


	//Initialize items
	Item* mailbox = new Item("mailbox", "There is a weathered mailbox, its paint chipped and faded. It looks like it hasn\'t been used in quite some time, but something about it seems important.",
		entry, false, false, false, true, false, true, false, 0);
	Item* letter = new Item("letter", "A single letter, sealed with an old wax emblem. The paper is brittle with age.",
		mailbox, true, true, false, false, false, true, false, 1);
	Item* lamp = new Item("lamp", "A tarnished brass lamp, its once-bright glow now dimmed by years of dust. It still holds some warmth when touched, though it\'s clear it hasn\'t been used in a long time.",
		kitchen, true, false, true, false, false, true, false, 3);
	Item* note = new Item("note", "There is a small, crumpled note left on the dining table. The handwriting is hurried, almost frantic: \"The guardian of this gate prefers art to words. He searches behind his haunting gaze.\"",
		dining_room, true, true, false, false, false, true, false, 1);
	Item* painting = new Item("painting", "There is a painting on the wall, depicting the face of a person. The features are oddly lifelike, almost as if the eyes are following you. It feels as though the figure in the painting is watching your every move.",
		dining_room, false, false, false, false, true, true, false, 0);
	Item* key_library = new Item("key", "There is a small, rusted key, nearly blending with the wall behind the painting. Its purpose is unclear, but it\'s evident it has been hidden for a reason.",
		NULL, true, false, false, false, false, false, false, 1); //NULL porque ya cambiara a dining_room cuando se rompa o se mueva el cuadro, esta oculto
	Item* bookshelf = new Item("bookshelf", "Something about it feels... off. The books are perfectly arranged, almost too perfectly. Upon closer inspection, you notice faint scratch marks on the floor, as if the bookshelf has been moved before.",
		library, false, false, false, false, true, false, false, 0);
	Item* showcase = new Item("showcase", "There is a dusty showcase that holds a variety of strange and unusual objects, each one more peculiar than the last. One item in particular catches your eye—a small, ornate amulet, resting under a dim light, almost glowing with an ethereal energy.",
		gallery, false, false, false, true, false, true, false, 0);
	Item* amulet = new Item("amulet", "There is a small, intricately carved amulet made of silver. It seems to shimmer faintly in the light, and there is an inscription on its surface in an ancient language. Something about it feels strangely familiar, as though it holds a purpose beyond simple decoration.",
		showcase, true, false, false, false, false, false, true, 1);
	Item* key_troll = new Item("key", "The key hangs from a small leather strap, tucked away in a hidden pocket of the troll\'s attire. Its shape is simple yet distinctive, the metal catching a faint glint of light as it shifts with every movement.",
		troll, false, false, false, false, false, false, false, 1); //de momento, no se podra coger, mas tarde si, cuando el troll la dropee
	Item* sword = new Item("sword", "There is a rusty sword lying on the ground, its blade dulled with age and neglect. Despite its worn appearance, the sword could still be useful in the right hands.",
		entry, true, false, false, false, false, false, false, 25);

	entities.push_back(mailbox);
	entities.push_back(letter);
	entities.push_back(lamp);
	entities.push_back(note);
	entities.push_back(painting);
	entities.push_back(key_library);
	entities.push_back(bookshelf);
	entities.push_back(showcase);
	entities.push_back(amulet);
	entities.push_back(key_troll);
	entities.push_back(sword);

	//Initialize exits (cada puerta es una Exit)
	Exit* entry_north = new Exit("north", "The room feels still, but you notice a faint draft coming from the north. The scent of aged spices and something long forgotten beckons you to the doorway ahead.", 
								 entry, /*NORTH, */kitchen, false, NULL, false, NULL);
	Exit* kitchen_south = new Exit("south", "", kitchen, /*SOUTH, */entry, false, NULL, false, NULL);
	Exit* kitchen_east = new Exit("east", "To the east, a darkened passageway stretches forward. The heavy air grows denser as you move, and the stillness is palpable, inviting you to step into the unknown.",
								  kitchen, /*EAST, */dining_room, false, NULL, false, NULL);
	Exit* dining_room_west = new Exit("west", "", dining_room, /*WEST, */kitchen, false, NULL, false, NULL);
	Exit* dining_room_east = new Exit("east", "To the east, a tall and imposing doorway stands. Its frame blends almost seamlessly with the shadows. There\'s a strange resistance here, as if the passage doesn\'t want to be disturbed.",
									  dining_room, /*WEST, */library, true, key_library, false, NULL);//lo de 'una vez desbloqueada'?
	Exit* library_west = new Exit("west", "", library, /*WEST, */dining_room, false, NULL, false, NULL);
	Exit* library_south = new Exit("south", "To the south, a massive bookshelf stands against the wall, filled with dusty tomes. Something about it feels... off. The books are perfectly arranged, almost too perfectly. Upon closer inspection, you notice faint scratch marks on the floor, as if the bookshelf has been moved before.",
								   library, /*SOUTH, */cellar, false, NULL, true, bookshelf);
	Exit* cellar_north = new Exit("north", "", cellar, /*NORTH, */library, false, NULL, false, NULL);
	Exit* cellar_west = new Exit("west", "To the west, a narrow corridor leads into an even deeper silence. The dampness in the air grows heavier, and the oppressive quiet swallows your every step.",
								 cellar, /*WEST, */studio, false, NULL, false, NULL);
	Exit* cellar_south = new Exit("south", "In the southern corner, the darkness seems to thicken. There is something here, something you can feel but not quite see, drawing you into the shadows beyond.",
								  cellar, /*SOUTH, */gallery, false, NULL, false, NULL);
	Exit* cellar_east = new Exit("east", "To the east, a narrow staircase leads upward, vanishing into the darkness above. At the top, a heavy wooden door blocks the way, its surface scarred by time and neglect. You try the handle—it doesn\'t budge. A sturdy lock keeps it sealed, its key nowhere in sight. As you step back, a chill runs down your spine—something lurks nearby, watching, waiting.",
								 cellar, /*EAST, */garden, true, key_troll, false, NULL);
	Exit* studio_east = new Exit("east", "", studio, /*EAST, */cellar, false, NULL, false, NULL);
	Exit* gallery_north = new Exit("north", "", gallery, /*NORTH, */cellar, false, NULL, false, NULL);
	Exit* garden_west = new Exit("west", "", garden, /*WEST, */cellar, false, NULL, false, NULL);
	Exit* garden_east = new Exit("east", "To the east, a faint light glimmers through the shadows, and the air feels charged with anticipation. Before you, a weathered door stands sealed with a heavy chain, its surface marked by time. The path beyond beckons, as if waiting for something—or someone—to set it in motion.",
								 garden, /*EAST, */end, true, NULL, false, NULL); //locked es solo para unlock, pero el amuleto se activara con 'use' (en vd es mas complicado pero le veo mas sentido), cuando hagamos use unlockearemos esta puerta. ponemos q esta bloqueada pero no el objeto pq eso es solo si fuera "unlock"

	entities.push_back(entry_north);
	entities.push_back(kitchen_south);
	entities.push_back(kitchen_east);
	entities.push_back(dining_room_west);
	entities.push_back(dining_room_east);
	entities.push_back(library_west);
	entities.push_back(library_south);
	entities.push_back(cellar_north);
	entities.push_back(cellar_west);
	entities.push_back(cellar_south);
	entities.push_back(cellar_east);
	entities.push_back(studio_east);
	entities.push_back(gallery_north);
	entities.push_back(garden_west);
	entities.push_back(garden_east);
}

World::~World()
{
	entities.clear();
}

bool World::Parser(const vector<string>& tokens)
{
	// Hay comandos de una palabra, dos, tres y cuatro
	// Todas las acciones las hace el Player. A partir de ahi, sus acciones repercuten en las otras Entitys.
	// En verdad este metodo esta mal, lo q tendria q hacer es comprobar el primer token y luego verificar q no hay mas (en caso de, por ejemplo, inventory)
	bool ret = true;
	//if(tokens.size() == 1) {
	//	if ((tokens[0] == "north" || tokens[0] == "n") ||
	//		(tokens[0] == "south" || tokens[0] == "s") ||
	//		(tokens[0] == "east" || tokens[0] == "e") ||
	//		(tokens[0] == "west" || tokens[0] == "w")) {
	//		player->Move(tokens[0]);
	//	}
	//	else if (tokens[0] == "look" || tokens[0] == "l") {
	//		player->Look();
	//	}
	//	else if (tokens[0] == "inventory" || tokens[0] == "i") {
	//		player->Inventory();
	//	}
	//	/*else if (tokens[0] == "save") {
	//		//save
	//	}
	//	else if (tokens[0] == "restore"){
	//		//restore save
	//	}
	//	no nos da tiempo creo yo*/
	//	else if (tokens[0] == "restart") {
	//		//restart
	//	}
	//	/*else if (tokens[0] == "help") {
	//		//help. no se si meterlo
	//	}*/
	//	else ret = false;
	//}
	//else if (tokens.size() == 2) {
	//	if (tokens[0] == "go") {
	//		if ((tokens[1] == "north" || tokens[1] == "n") ||
	//			(tokens[1] == "south" || tokens[1] == "s") ||
	//			(tokens[1] == "east" || tokens[1] == "e") ||
	//			(tokens[1] == "west" || tokens[1] == "w")) {
	//			player->Move(tokens[1]);
	//		}
	//		else ret = false;
	//	}
	//	else if (tokens[0] == "get" || tokens[0] == "take") {
	//		//tiene q ser o un objeto o all
	//	}
	//}
	if ((tokens[0] == "north" || tokens[0] == "n") ||
		(tokens[0] == "south" || tokens[0] == "s") ||
		(tokens[0] == "east" || tokens[0] == "e") ||
		(tokens[0] == "west" || tokens[0] == "w")) {
		if (tokens.size() > 1) {
			cout << "I only understood you as far as wanting to";
			if (tokens[0] == "north" || tokens[0] == "n") cout << " north." << endl;
			else if (tokens[0] == "south" || tokens[0] == "s") cout << " south." << endl;
			else if (tokens[0] == "east" || tokens[0] == "e") cout << " east." << endl;
			else if (tokens[0] == "west" || tokens[0] == "w") cout << " west." << endl;
		}
		else player->Move(tokens[0]);
	}

	else if (tokens[0] == "look" || tokens[0] == "l") {
		if (tokens.size() > 1) {
			cout << "I only understood you as far as wanting to look.";
		}
		else player->Look();
	}

	else if (tokens[0] == "inventory" || tokens[0] == "i") {
		if (tokens.size() > 1) {
			cout << "I only understood you as far as wanting to inventory.";
		}
		else player->Inventory();
	}
	else if (tokens[0] == "restart") {
		if (tokens.size() > 1) {
			cout << "I only understood you as far as wanting to restart.";
		}
	}
	else if (tokens[0] == "quit") {
		if (tokens.size() > 1) {
			cout << "I only understood you as far as wanting to quit.";
		}
	}
	else if (tokens[0] == "go") {
		if ((tokens[1] == "north" || tokens[1] == "n") ||
			(tokens[1] == "south" || tokens[1] == "s") ||
			(tokens[1] == "east" || tokens[1] == "e") ||
			(tokens[1] == "west" || tokens[1] == "w")) {
			if (tokens.size() > 2) {
				cout << "I only understood you as far as wanting to go to the";
				if (tokens[1] == "north" || tokens[1] == "n") cout << " north wall." << endl;
				else if (tokens[1] == "south" || tokens[1] == "s") cout << " south wall." << endl;
				else if (tokens[1] == "east" || tokens[1] == "e") cout << " east wall." << endl;
				else if (tokens[1] == "west" || tokens[1] == "w") cout << " west wall." << endl;
			}
			else player->Move(tokens[1]);
		}
	}
	else if (tokens[0] == "get" || tokens[0] == "take") {
		//tiene q ser o un objeto o all
		if (tokens.size() > 2) cout << "You can\'t see any such thing." << endl;
		else player->Take(tokens[1]);
	}

	else if (tokens[0] == "drop") {
		//tiene q ser o un objeto o all
		if (tokens.size() > 2) cout << "You can\'t see any such thing." << endl;
		else player->Drop(tokens[1]);
	}

	else if (tokens[0] == "open") {
		if (tokens.size() > 2) cout << "You can\'t see any such thing." << endl;
		else player->Open(tokens[1]);
	}

	else ret = false;

	return ret;
}