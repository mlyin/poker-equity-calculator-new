#include "cards.h"
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

// Define the possible hands in descending order of value
vector<string> hands = {"HIGH CARD", "ONE PAIR", "TWO PAIR", "THREE OF A KIND", "STRAIGHT",
                        "FLUSH", "FULL HOUSE", "FOUR OF A KIND", "STRAIGHT FLUSH", "ROYAL FLUSH"};

// Define the possible values of a card
vector<string> values = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

// Define the possible suits of a card
vector<string> suits = {"c", "d", "h", "s"};

// Define the stylized version of the suits
vector<string> stylized_suits = {"♣", "♦", "♥", "♠"};

// Returns the string representation of a card given its index
string card_string(int index) {
    return values[index % 13] + stylized_suits[index / 13];
}

// Finds the index of a key in a vector
int get_index(vector<string> &vec, string key) {
    auto it = find(vec.begin(), vec.end(), key); 

    return (it != vec.end() ? it - vec.begin() : -1);
}

// Decodes a card string into an index
int decode_card(string card){
    int value_index = get_index(values, card.substr(0, card.size()-1));
    int suit_index = get_index(suits, card.substr(card.size()-1, card.size()));
    return (value_index != -1 && suit_index != -1) ? suit_index * 13 + value_index : -1;
}

// Converts a hand of cards from strings to indexes and sorts it
vector<int> convert_hand(vector<string> &string_hand) {
    vector<int> hand;
    for (string card : string_hand) {
        hand.push_back(decode_card(card));
    }
    sort(hand.begin(), hand.end());

    return hand;
}


// Prints a hand of cards
void print_hand(vector<int> hand) {
    for (int card : hand) {
        cout << card_string(card) << " ";
    }
}

// Prints the score of a hand
void print_score(int score) {
    // Decode the score integer
    score /= pow(13, 5);

    int second_value_index = score % 13;
    score /= 13;
    int first_value_index = score % 13;
    score /= 13;
    int hand_type_index = score;

    // Print the hand type and the values of the cards involved
    printf("%s ", hands[hand_type_index].c_str());
    if (hand_type_index == 2 || hand_type_index == 6) {
        printf("with %s & %s", values[first_value_index].c_str(), values[second_value_index].c_str());
    } else if (!(hand_type_index > 3 && hand_type_index != 7)) {
        printf("with %s", values[first_value_index].c_str());
    }
    cout << endl;
}

// Calculates the margin of error for a proportion
double calc_error(double proportion, int sample_size) {
    return 1.96 * sqrt(proportion * (1 - proportion) / sample_size);
}

// Calculates the number of combinations of k elements from a set of N elements
int pascal(vector<int> &table, int N, int k) {
    int combos;
    int ix = 53 * k + N;
    if ( N < k){
        return 0;
    } else if (table[ix] != 0) {
        return table[ix];
    }

    combos = pascal(table, N - 1, k - 1) + pascal(table, N - 1, k);
    table[ix] = combos;
    return combos;
}

// Generates the possible combination table given N and k
vector<int> gen_combo_table(int N, int k) {
    vector<int> c_table((k + 1) * (N + 1));
    for (int m = 0; m <= N; ++m) {
        c_table[m] = 1;
    }

    for (int i = 1; i <= k; ++i) {
        for (int j = i; j <= N; ++j) {
            pascal(c_table, j, i);
        }
    }

    return c_table;
}

