#include "samples.h"
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

// Function generates N samples of size C from a set of n elements

// Returns a 2D vector where each row represents a sample and each element in the row is an index referring to the element in the set
// shuffled sequence containing integers 0, 1, ..., n-1 each l times
vector<int> gen_seq(int &l, int &n) {
    vector<int> seq = vector<int>(l * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < l; ++j) {
            seq.at(i * l + j) = i;
        }
    }
    random_device rd;
    mt19937 g(rd());
    shuffle(seq.begin(), seq.end(), g);
    return seq;
}

// N = 30 random samples | C = choose 6 | n = 13 elements
vector<vector<int> > gen_samples(int N, int C, int n) {
    int l = 1 + (int) (N * C) / n;
    vector<int> seq = gen_seq(l, n);
    // Initialize variables to keep track of the number of samples filled and the last index used for each element
    vector<int> heads(n, 0);
    vector<int> size(n, 0);
    int filled = 0;

    // Initialize 2D vector to hold the samples
    vector<vector<int>> samps(N, vector<int>(C));

    int c = 0;
    for (int x : seq) {
        c++;
        // If the current index has already been used in a previous sample, set its head to the last filled sample index
        if (heads[x] < filled) {
            heads[x] = filled;
        }
        // Add the current index to the sample at the current head position
        samps[heads[x]][size[x]] = x;
        size[x]++;
        // If the current sample is filled, increment the filled counter
        if (size[x] == C) {
            filled++;
        }
        // If all samples have been filled, stop iterating
        if (filled == N) {
            break;
        }
        // Move the head position for the current index to the next position
        heads[x]++;
    }
    return samps;
}