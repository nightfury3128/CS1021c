#include <iostream>
#include <fstream>
#include <string>
#include <cassert>


const int ALPHABET_LENGTH{26};

int number_from_letter(char letter) {
  int offset = letter - (int)'a';
  if (offset < 0 || offset >= ALPHABET_LENGTH) {
    std::cout << "number_from_letter called with invalid argument (" << letter << ").\n";
    assert(false);
  }
  return offset;
}

char letter_from_number(int number) {

  if (number < 0 || number >= ALPHABET_LENGTH) {
    std::cout << "letter_from_number called with an invalid argument (" << number << ").\n";
    assert(false);
  }

  const char alphabet[] = { 'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z'};
  return alphabet[number];
}

/* This is a cipher program used for encrypted the data gvien to it by the use of shift number and the direction of the shift*/
int main() {
    char letter{ 'a' };
    std::ifstream input_file{};
    input_file.open("input.txt");
    int shift{};
    char shiftl{};
    /* All if condition are to check for the error cases as mentioned for the lab*/
    if (!(input_file >> shiftl)) {
        std::cout << "Oops: Could not read the direction from the input file." << std::endl;
        return 0;
    }
    if (shiftl != 'l' && shiftl != 'r') {
        std::cout << "Oops: Invalid direction in the input file." << std::endl;
        return 0;
    }
    if (!(input_file >> shift)) {
        std::cout << "Oops: Could not read the shift number from the input file." << std::endl;
        return 0;
    }
    while (!std::iscntrl(input_file.peek()) && !input_file.eof())
    {// This loop will work until .txt file has no content
        input_file >> letter;//Used to extract character in the file
        int x = number_from_letter(letter);
        if (shiftl == 'l') {
            int l = x-shift;
            int n{};
            int re = l % 26;
            if (re < 0) {
                 re+=26;
            }
            std::cout << letter_from_number(re);
        }
        else {
            int pos = shift +x;
            int m = pos % 26;
            std::cout << letter_from_number(m);
        }
    }
    std::cout<< std::endl;
}
