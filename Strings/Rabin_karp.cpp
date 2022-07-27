#include <bits/stdc++.h> 
using namespace std; 

// d is the number of characters in the input alphabet 


/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
void rabinKarp(string text, string pat) 
{ 
	int m= text.length(); 
	int n = pat.length(); 
    int d=101;
	int p = 0; // hash value for pattern 
	int t = 0; // hash value for txt 
	int h = 1; 
    int q=11;

	// The value of h would be "pow(d, M-1)%q" 
	for (int i = 0; i < n - 1; i++) 
		h = (h * d) % q; 

	// Calculate the hash value of pattern and first 
	// window of text 
	for (int i = 0; i < n; i++) 
	{ 
		p = (d * p + pat[i]) % q; 
		t = (d * t + text[i]) % q; 
	} 

	// Slide the pattern over text one by one 
	for (int i = 0; i <= m-n; i++) 
	{ 

		// Check the hash values of current window of text 
		// and pattern. If the hash values match then only 
		// check for characters on by one 
		if ( p == t ) 
		{ 
            int j;
			/* Check for characters one by one */
			for (j = 0; j < n; j++) 
			{ 
				if (text[i+j] != pat[j]) 
					break; 
			} 

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == n) 
				cout<<"Pattern found at index "<< i<<endl; 
		} 

		// Calculate hash value for next window of text: Remove 
		// leading digit, add trailing digit 
		if ( i <= m-n ) 
		{ 
			t = (d*(t - text[i]*h) + text[i+n])%q; 

			// We might get negative value of t, converting it 
			// to positive 
			if (t < 0) 
			t = (t + q); 
		} 
	} 
} 

/* Driver code */
int main() 
{ 
	string text,pat;
    cin>>text;
    cin>>pat;
	rabinKarp(text, pat); 
	return 0; 
} 
