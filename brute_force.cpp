#include<iostream>

using namespace std;

int pm_bruteforce(string t, string p) {
	int t_len = t.length(), p_len = p.length();
	if (p_len < t_len || t_len == 0 || p_len == 0) return 0;

	int matches = 0;
	for (int i = 0, j = 0; i <= t_len - p_len; i++) {
		j = 0;
		while (t[i + j] == p[j] && j < p_len)
		{
			j++;
		}

		if (j == p.length())
			matches++;
	}

	return matches;
}