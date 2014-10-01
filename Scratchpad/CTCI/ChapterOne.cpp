#include <string>
#include <algorithm>
#include <iostream>

inline bool p_1_1() {
	std::string s = "whatever";
	std::sort(begin(s), end(s));
	for (size_t i = 0; i < s.size() - 1; i++) {
		if (s[i] == s[i + 1]) return false;
	}
	return true;
}

inline void p_1_2() {
	std::string s = "abcdef";
	std::reverse(begin(s), end(s));
	std::cout << "problem 1.2: " << s << std::endl;
}

inline void p_1_3() {
	std::string s1 = "team";
	std::string s2 = "meat";
	std::string tmp1 = s1, tmp2 = s2;
	std::sort(begin(tmp1), end(tmp1));
	std::sort(begin(tmp2), end(tmp2));
	std::cout << "problem 1.3: " << s1 << " is " << (tmp1 == tmp2 ? "" : "not") << " a permutation of " << s2 << std::endl;
}

inline void p_1_4() {
	std::string s = "Mr John Smith    ";
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			s.replace(i, 1, "%20");
		}
	}
	std::cout << "problem 1.4: " << s << std::endl;
}