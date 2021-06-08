#include<iostream>

using namespace std;

int modpow(int base, int exp, int modulus) {
	base %= modulus;
	int result = 1;
	while (exp > 0) {
		if (exp & 1) result = (result * base) % modulus;
		base = (base * base) % modulus;
		exp >>= 1;
	}
	return result;
}

int pm_rabinkarp(string t, string p)
{
	int t_len = t.length(), p_len = p.length();
	if (p_len < t_len || t_len == 0 || p_len == 0) return 0;

	int matches = 0;
	int Q = 101;
	int p_hash = 0, t_hash = 0;
	int h = modpow(N_CHARS, p_len - 1, Q);
	for (int i = 0; i < p_len; i++)
	{
		p_hash = (N_CHARS * p_hash + p[i]) % Q;
		t_hash = (N_CHARS * t_hash + t[i]) % Q;
	}

	for (int i = 0, j = 0; i <= t_len - p_len; i++)
	{
		if (p_hash == t_hash)
		{
			j = 0;
			while (j < p_len)
			{
				if (t[i + j] != p[j]) break;
				j++;
			}
			if (j == p_len) matches++;
		}

		if (i < t_len - p_len)
		{
			t_hash = (N_CHARS * (t_hash - t[i] * h) + t[i + p_len]) % Q;

			if (t_hash < 0) t_hash = (t_hash + Q);
		}
	}
	return matches;
}
