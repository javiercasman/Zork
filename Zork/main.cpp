#include <iostream>
#include "World.h"
#include <string>
#include <sstream> 

using namespace std;

vector<string> tokenizeInput(const string& input) {
	vector<string> words;
	istringstream stream(input);
	string word;

	while (stream >> word) {
		words.push_back(word);
	}

	return words;
}

int main() {
	World world;
	vector<string> tokens;
	string input;
	string word;
	//gameloop
	//aqui leer el comando puesto por el jugador y luego ya interpretarlo y updatear el world. world es para representar la partida, donde estan las entidades
	cout << "Welcome to Zork!" << endl;
	world.Parser(vector<string>{"l"});
	while (true) {
		if (world.player_alive()) {
			if (world.player->parent->name != "End") {
				//descripcion de las entidades de la habitacion (y de la propia habitacíon). Es decir, se hace automaticamente un 'look'
				//world.Parser(vector<string>{"l"}); //esto esta mal, es solo cuando entramos a una nueva habitacion

				input = "";
				cout << endl;
				getline(cin, input); //leemos el input del jugador

				tokens = tokenizeInput(input);

				if (tokens.size() == 1 && tokens[0] == "quit") {
					cout << "Are you sure you want to quit?\n";
					getline(cin, input);
					tokens = tokenizeInput(input);
					while (tokens[0] != "yes" && tokens[0] != "y" && tokens[0] != "no" && tokens[0] != "n") {
						cout << "Please answer yes or no.\n";
						getline(cin, input);
						tokens = tokenizeInput(input);
					}
					if (tokens[0] == "yes" || tokens[0] == "y") break;
					if (tokens[0] == "no" || tokens[0] == "n") continue;
				}

				else if (tokens.size() == 0) {
					cout << "I beg your pardon?\n";
					continue;
				}
				else if (!world.Parser(tokens)) cout << "That's not a verb I recognise.\n";
				// posibilidad para meter quit y restart en Parser: eliminamos el primer if, y despues de este else if metemos un else, donde comprobemos si tokens[0] es quit o restart
			}
			else{
				break;
			}
		}
		else {
			cout << "You died!" << endl;
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}