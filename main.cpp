#include<iostream>
#include<stack>
#include<string>
using namespace std; 
string decodeString(string s) {
	int n = s.length(); 
	stack <char> st; 
	for (int i = 0; i < n; i++) {
		char c = s[i]; 
		if (c == ']') {
			string Stringloop = ""; 
			while (st.top() != '[') {
				Stringloop = st.top() + Stringloop; 
				st.pop(); 
			}
			st.pop(); // xoa luon dau [
			// tiep theo den lay so lan lap 
			string StringNumber = ""; 
			while (st.empty() == false && isdigit(st.top() == true)) {
				StringNumber = st.top() + StringNumber; 
				st.pop(); 
			}
			int nLoop = atoi(StringNumber.c_str()); 
			for (int i = 0; i < nLoop-1; i++) {
				Stringloop += Stringloop; 
			}
			for (int i = 0; i < Stringloop.length(); i++) {
				st.push(Stringloop[i]); 
			}
		}
		else {
			st.push(c); 
		}
	}
	string result = ""; 
	while (st.empty() == false) {
		result = st.top() + result; 
		st.pop(); 
	}
	return result; 
}

int main() {
	string s = "3[a]2[b]"; 
	string k = decodeString(s); 
	cout << k; 
}
