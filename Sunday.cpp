#include<iostream>

using namespace std;

int pm_sunday(string t, string p) {
	int t_len = t.length(), p_len = p.length();
	if (p_len < t_len || t_len == 0 || p_len == 0) return 0;

	int matches = 0;
	int m = p_len, k;
	for (int i = 0, j = 0;i < t_len;) {
		if (t[i] != p[j]) {
			for (k = p_len - 1;k >= 0;k--) {
				if (p[k] == t[m])
					break;
			}
			i = m - k;
			j = 0;
			m = i + p_len;
		}
		else {
			if (j == p_len - 1)
				matches++;
			i++;
			j++;
		}
	}
	return matches;
}
