#include <string>
#include <iostream>

/* As the name suggests, this function checks if a given char is a vowel or not, the logic is used to check if a character is equal to "a,e,i,o,u"  */
bool is_vowel(char p) {

	if (p == 'a' || p == 'e' || p == 'i' || p == 'o' || p == 'u') {
		return true;
	}
	else {
		return false;
	}	
}

/* As the name suggests, this function checks if a given char is a consonant or not , the logic used is simple, if it is not a vowel then it is a consonant */
bool is_consonant(char p) {
	if (!(is_vowel(p))) {
		return true;
	}
	else {
		return false;
	}
}

/* As the name suggests, this function checks if a given string ends with another specific string
Logic for the function: Introduce 2 variables whose values will decrement as the loops runs until the condition of the loop
Each of the variable (i & k) will point to a exact point in the given string (a & b), there will be a flag variable for the entire function
which will be used to check if the function will return true or false */
bool ends_with(std::string a, std::string b) {
	int k = b.length() - 1;
	int flag = 1;
	if (a.length() == 0 && b.length() == 0) {
		return true;
	}
	else if (b.length() == 0 && a.length() != 0) {
		return true;
	}

	else if (a.length()>= b.length()){

		for (int i = a.length() - 1; k >= 0; i--) {
			if (a.at(i) == b.at(k)) {
				flag = 0;
			}
			else {
				flag = 1;
				break;
			}
			k--;
		}
	}

	else {
		return false;
	}
	
	if (flag == 0) {
		return true;
	}
	else {
		return false;
	}
}
/* The function is used to check if a given string ends with a double consonant, the logic used is if the length of the given string is less than 2 then it returns false but if it is greater than 2 then I extracted the last two character and checked if it was a consonant 
and if they were equal to each oteher */
bool ends_with_double_consonant(std::string a) {
	int length = a.length();
	if (length < 2) {
		return false;
	}
	else {
		char last = a.at(length-1);
		char slast = a.at(length - 2);
		if (!(is_vowel(last)) && !(is_vowel(slast)) && last==slast) {
			return true;
		}
		else {
			return false;
		}
	}

}
/* The function is used to calculate the number of consonant present at the start of given string, the logic used is starting a for loop from the start of the string and check if each character is a consonant until we reach a vowel and break out of the loop */
int count_consonants_at_front(std::string a) {
	int counter = 0;
	if (a.length() == 0) {
		return counter;
	}
	else {
		for (int i = 0; i < a.length(); i++) {
			if (!(is_vowel(a.at(i)))) {
				counter++;
			}
			else {
				break;
			}

		}
	}
	
	return counter;
}

/* The function is used to calculate the number of vowel present at the end of given string, the logic used is starting a for loop from the back of the string and check if each character is a vowel until we reach a consonant and break out of the loop */
int count_vowels_at_back(std::string a) {
	int counter = 0;
	for (int i = a.length() - 1; i >= 0; i--) {
		if (is_vowel(a.at(i))) {
			counter++;
		}
		else {
			break;
		}
	}
	return counter;
}

/* The function checks if the last three character of a given string is a consonant, vowel and a consonant in that order
The logic I used for the function is check the length and if the length is more than 2, I extracted the last three character and used the "is vowel" and the "is consonant" function to check if the consonant and the vowel are in the correct order */
bool ends_with_cvc(std::string a) {
	if (a.length() == 0) {
		return false;
	}
	else if (a.length() == 1) {
		return false;
	}
	else if (a.length() == 2) {
		return false;
	}
	else if (a.length() > 2) {
		char last = a.at(a.length() - 1);
		char slast = a.at(a.length() - 2);
		char tlast = a.at(a.length() - 3);
		if (is_vowel(last) && is_vowel(tlast)) {
			return false;
		}
		else {
			if ((is_consonant(last)) && is_vowel(slast) && ((is_consonant(tlast)))) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}
/* The function checks if a string has any vowels throughout it's content, The logic for the function is basically to run the loop for the length for the given string and runs the "is vowel" function for each character in the string */
bool contains_vowel(std::string a) {
	if (a.length() == 0) {
		return false;
	}
	else {
		for (int i = 0; i < a.length(); i++) {
			if (is_vowel(a.at(i))) {
				return true;
				break;
			}
		}
	}
}
/* The function is used to replace the a certain part of a given string with another string, the logic used for the function is just a cutting the string (from the back) and adding the new string onto the newly cut string*/
std::string new_ending(const std::string candidate, int suffix_length, const std::string replacement) {
	if (suffix_length <= 0) {
		return candidate;

	}
	return candidate.substr(0, candidate.length() - suffix_length) + replacement;
}