#include <vector>
#include<iostream>

using namespace std;

#define N_CHARS 256

vector<int> compute_prefix(string p) {
	vector<int> pi(p.length(), 0);
	int	idx = 0;

	for (int i = 1;i < p.length();i++) {
		while (idx && p[i] != p[idx]) {
			idx = pi[idx - 1];
		}

		if (p[idx] == p[i]) {
			idx++;
			pi[i] = idx;
		}
	}
	return pi;
}

int pm_kmp(string t, string p) {
	int t_len = t.length(), p_len = p.length();
	if (p_len < t_len || t_len == 0 || p_len == 0) return 0;

	int matches = 0;
	vector <int> pi = compute_prefix(p);
	for (int i = 0, idx_p = 0;i < t_len;i++) {
		while (idx_p && p[idx_p] != t[i]) {
			idx_p = pi[idx_p - 1];
		}

		if (p[idx_p] == t[i]) {
			if (idx_p == p_len - 1) {
				matches++;
				idx_p = pi[idx_p];
			}
			else {
				idx_p++;
			}
		}
	}
	return matches;
}
