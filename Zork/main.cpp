#include <iostream>

using namespace std;

int main() {
	World world;
	string input;
	//gameloop
	//aqui leer el comando puesto por el jugador y luego ya interpretarlo y updatear el world. world es para representar la partida, donde estan las entidades
	while (true) {
		cout << "Welcome to Zork!" << endl;

		//descripcion de las entidades de la habitacion (y de la propia habitacíon)

		getline(cin, input); //leemos el input del jugador

		//ahora le pasa el input al world, este se encarga de parsearlo para poder gestionar las entidades
	}
}