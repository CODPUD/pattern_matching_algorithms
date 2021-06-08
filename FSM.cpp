#include<iostream>
#include<vector>

using namespace std;

#define N_CHARS 256

int get_next_value(string p, int p_len, int a, int b) {
	if (a < p_len&& b == p[a]) {
		return a + 1;
	}

	int j = 0;
	for (int i = a; i > 0; i--) {
		if (p[i - 1] == b)
		{
			for (j = 0;j < i - 1;j++) {
				if (p[j] != p[a - i + 1 + j]) break;
			}
			if (j == i - 1) return i;
		}
	}

	return 0;

}

vector<vector<int>> compute_transition_function(string p, int p_len) {
	vector<vector<int>> TF;
	for (int i = 0;i <= p_len; ++i) {
		vector<int> temp_vec;
		for (int j = 0; j < N_CHARS; ++j) {
			temp_vec.push_back(get_next_value(p, p_len, i, j));
		}
		TF.push_back(temp_vec);
	}
	return TF;

}

int pm_fsm(string t, string p) {
	int t_len = t.length(), p_len = p.length();
	if (p_len < t_len || t_len == 0 || p_len == 0) return 0;

	int matches = 0;
	vector<vector<int>> TF = compute_transition_function(p, p_len);
	int state = 0;
	for (int i = 0; i < t_len; i++)
	{
		state = TF[state][t[i]];
		if (state == p_len)
			matches++;
	}
	return matches;
}

