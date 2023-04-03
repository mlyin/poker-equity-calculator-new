#ifndef MONTECARLOPOKER_CARDS_H
#define MONTECARLOPOKER_CARDS_H

#include <vector>
using namespace std;

void print_hand(vector<int> hand);
vector<int> convert_hand(vector<string> &s_hand);
double calc_error(double prop, int N);
vector<int> gen_combo_table(int N, int k);
int decode_card(string hand);


#endif
