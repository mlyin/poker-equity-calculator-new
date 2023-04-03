#include "tables.h"
#include "tools.h"
#include "cards.h"
#include <vector>
#include <iostream>
using namespace std;

// Determine if one vector should replace another based on its values
bool replace(vector<int> &arr1, vector<int> &arr2) {
    return arr1[0] < arr2[0] || (arr1[0] == arr2[0] && arr1[1] <= arr2[1]);
}

// Retrieves the two highest-ranking cards in the hand based on their frequency and value. 
// Returns a vector of two vectors, where each vector contains the frequency and value of a high-ranking card.
vector<vector<int>> retrieve_top(const vector<int> &hand){
    vector<vector<int>> top2(2, vector<int>(2)); // Initialize top2 to a 2x2 matrix
    int prev = 0;

    for (int i = 1; i < hand.size(); ++i) { // Iterate over the hand
        if (hand[i] != hand[i-1]) { // If the current card is different from the previous card
            vector<int> arr = {i - prev, hand[i - 1]}; // Calculate the length of the run of cards and the value of the card
            if (replace(top2[0], arr)) { // If the new run of cards should replace the first top card
                top2[1] = top2[0]; // Move the old top card down to the second spot
                top2[0] = arr; // Replace the first top card with the new run of cards
            } else if (replace(top2[1], arr)) { // If the new run of cards should replace the second top card
                top2[1] = arr; // Replace the second top card with the new run of cards
            }
            prev = i; // Update the previous card index to the current card index
        }
    }
    return top2; // Return the top two cards
}

// Numerize the top two cards in a hand, based on their values
int numerize_top(const vector<vector<int>> &top2){
    int a = top2[0][0];
    int b = top2[1][0];

    int m = 0;
    if (a == 4) {
        m = 7;
    } else if (a == 3) {
        if (b == 2) {
            m = 6;
        } else {
            m = 3;
        }
    } else if (a == 2) {
        if (b == 2) {
            m = 2;
        } else {
            m = 1;
        }
    }

    return m * 13 * 13 + top2[0][1] * 13 + ((m == 2 || m == 6) ? top2[1][1] : 0);
}

// Numerize a hand based on its values
int numerize_global(const vector<int> &hand, const vector<int> &suit){
    bool is_flush = true; bool is_straight = true;

    for (int i = 1; i < hand.size(); ++i) {
        is_straight &= (hand[i-1] + 1 == hand[i]);
        is_flush &= (suit[i-1] == suit[i]);
    }

    int m = 0;
    if(is_straight && is_flush){
        if(hand.back() == 12){
            m = 9;
        } else {
            m = 8;
        }
    } else if(is_straight){
        m = 4;
    } else if(is_flush){
        m = 5;
    }

    return m * 13 * 13;
}

// This function evaluates a given hand of cards and returns a unique integer
// value representing the strength of the hand. The input is a vector of integers
// representing the cards in the hand.
int evaluate(const vector<int> &hand2){
    // Make a copy of the input vector and sort it by card rank (modulo 13).
    vector<int> hand1 (hand2);
    sort(hand1.begin(), hand1.end(), [](int a, int b) { return a % 13 < b % 13; });

    // Separate the sorted hand vector into two separate vectors, one for the 
    // card rank and one for the card suit.
    vector<int> hand; vector<int> suit;
    for (int j = 0; j < hand1.size(); ++j) {
        hand.push_back(hand1[j] % 13);
        suit.push_back(hand1[j] / 13);
    }
    
    // Add a dummy value to the end of the hand vector to simplify the subsequent
    // calculations.

    hand.push_back(-1);

    // Retrieve the top two hands that can be made with the given set of cards,
    // and convert them to numerical values.
    vector<vector<int>> top2 = retrieve_top(hand);
    hand.pop_back();

    int max_head = max(numerize_top(top2), numerize_global(hand, suit));

    // Convert the hand vector to a single integer value.
    int hand_val = 0; int factor = 1;
    for (int i = 0; i < hand.size(); ++i) {
        hand_val += hand[i] * factor;
        factor *= 13;
    }

    // Multiply the numerical hand value by a large factor and add the maximum
    // hand strength value to get the final evaluation.
    return max_head * factor + hand_val;
}

// This vector is used to convert a vector of cards to a unique integer key.
vector<int> pow52 = {1, 52, 52 * 52, 52 * 52 * 52, 52 * 52 * 52 * 52};

// This function converts a vector of cards to a unique integer key using the pow52 vector.
int to_key(const vector<int> &hand){
    int ret = 0;
    for (int i = 0; i < hand.size(); ++i) {
        ret += pow52[i] * hand[i];
    }
    return ret;
}

// This function converts a vector of cards to a unique integer key using a pre-generated
// combination table.
int to_ckey(const vector<int> & c_table, const vector<int> &hand){
    int key = 0;
    for (int i = 0; i < hand.size(); ++i) {
        key += c_table[(i + 1) * 53 + hand[i]];
    }
    return key;
}

// This recursive function fills a lookup table with the strength values of all possible
// hands that can be made with a given number of cards.
void fill_lookup_table(const vector<int> & c_table, vector<int> &table, vector<int> &hand){
    // If the hand size is 5, evaluate the hand and store the result in the lookup table.
    if(hand.size() == 5){
        print(hand); cout << endl;
        table[to_ckey(c_table, hand)] = evaluate(hand);
    } else {
        // Otherwise, add each possible card to the hand and recursively call the function
        // with the larger hand.
        for (int i = (hand.empty() ? 0 : (hand.back() + 1)); i <= 52 - ( 5 - hand.size()); ++i) {
            hand.push_back(i);
            fill_lookup_table(c_table, table, hand);
            hand.pop_back();
        }
    }
}

vector<int> gen_lookup_table(){
    vector<int> c_table = gen_combo_table(52, 5);
    vector<int> table(c_table[5 * 53 + 52]);
    vector<int> hand;
    fill_lookup_table(c_table, table, hand);

    return table;
}



