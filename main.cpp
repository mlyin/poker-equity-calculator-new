#include <iostream>
#include "simulator.h"
#include "cards.h"
#include "tools.h"
using namespace std;

int main() {
    // Create instance of the simulator
    Simulator sim;

    vector<vector<string>> known_hands = {{"Ac", "Kh"}, {"2s", "7d"}}; // Poker hand pairs for each player 
    vector<string> comm_hand = {}; // Between 0-5 cards available in the community hand //can add "5s" for 5 of spades in the community hand

    int num_sims = 100000; // Number of simulations to run

    cout << "Simulating..." << endl;

    // Last parameter is optionally including more players, whose hands are unknown (random)
    // The last parameter specifies the number of additional players with unknown hands
    // In this case, no additional players are included
    vector<vector<int>> results = sim.compute_probabilities(num_sims, comm_hand, known_hands, 0);
}