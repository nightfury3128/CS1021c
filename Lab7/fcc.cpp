#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

#include "fcc.h"

bool more_to_read(std::ifstream& file) {
    file >> std::noskipws;
    while (file.peek() == ' ') {
        char discard;
        file >> discard;
    }
    return !(file.eof() || std::iscntrl(file.peek()));
}
/* /*
 * int fcc
 *
 * This function opens mulitple text file and corrects the spelling mistake made in the document
 *
 * input: takes the three files and a fixed sentence variable 
 * output: the fixed sentence variable is constant and the return vaule is the name of corrections made if there are no correction then the return -1
 */
int fcc(const std::string& fixme_filename, const std::string& typo_filename,
    const std::string& fixo_filename, std::string& fixed_sentence) {

    std::ifstream fixme_file(fixme_filename);
    std::ifstream typo_file(typo_filename);
    std::ifstream fixo_file(fixo_filename);

    if (!fixme_file.is_open() || !typo_file.is_open() || !fixo_file.is_open()) {
        std::cout << "Error: Unable to open one or more input files." << std::endl;
        return -1;
    }

    std::vector<std::string> typos;
    std::vector<std::string> fixos;
    std::string word;

    // Read typos and fixos from files
    while (more_to_read(typo_file)) {
        typo_file >> word;
        typos.push_back(word);

    }
    while (more_to_read(fixo_file)) {
        fixo_file >> word;
        fixos.push_back(word);
    }

    int corrections = 0;
    if (typos.size() != fixos.size()) {
        return -1;
    }

    else {
        // Read words from the fixme file and autocorrect
        while (more_to_read(fixme_file)) {
            fixme_file >> word;
            bool corrected = false;

            // Autocorrection logic
            for (size_t i = 0; i < typos.size(); i++) {
                if (word == typos[i]) {
                    fixed_sentence += fixos[i] + " ";
                    corrections++;
                    corrected = true;
                    break; // Stop checking after the first correction
                }
            }

            // If the word was not corrected, add it as is to the fixed_sentence
            if (!corrected) {
                fixed_sentence += word + " ";
            }
        }

        // Trim the trailing space and add a period
        if (!fixed_sentence.empty()) {
            fixed_sentence.pop_back();
            fixed_sentence += ".";
        }

        fixme_file.close();
        typo_file.close();
        fixo_file.close();

        return corrections;

    }
}