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
	while (true) {
		//descripcion de las entidades de la habitacion (y de la propia habitacíon). Es decir, se hace automaticamente un 'look'
		input = "";
		getline(cin, input); //leemos el input del jugador

		tokens = tokenizeInput(input);

		if (tokens.size() == 1 && tokens[0] == "quit") {
			cout << "Are you sure you want to quit?\n";
			getline(cin, input);
			tokens = tokenizeInput(input);
			while (tokens[0] != "yes" && tokens[0] != "no") {
				cout << "Please answer yes or no.\n";
				getline(cin, input);
				tokens = tokenizeInput(input);
			}
			if (tokens[0] == "yes") break;
			if (tokens[0] == "no") continue;
		}

		if (!world.Parser(tokens)) cout << "That's not a verb I recognise.\n";

		//ahora le pasa el input al world, este se encarga de parsearlo para poder gestionar las entidades7
	}
	cout << "Bye!\n";
	return 0;
}