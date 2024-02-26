#include "metaverse.h"
#include "display.h"
#include <fstream>
#include <ios>
#include <iostream>
#include <istream>
#include <vector>

using namespace std;

using metaverse_t = std::vector<std::vector<bool>>;

/**
 * Count Neighbors:
 * This function counts the number of occupied neighbors for a given location in the Metaverse.
 *
 * The input and the output of the function are:
 * param metaverse  A metaverse_t const reference describing the current generation of the Metaverse.
 * param row        An int for the row of the location to determine neighborhood population.
 * param column     An int for the column of the location to determine neighborhood population.


 * return           The number of occupied neighbors at the specified location.

 */
int count_neighbors(const metaverse_t& board, int row, int column) {
    int count = 0;
    int rows = board.size();
    int cols = board[0].size();

    int dr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dc[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < 8; i++) {
        int newRow = row + dr[i];
        int newCol = column + dc[i];

        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && board[newRow][newCol]) {
            count++;
        }
    }


    return count;
}

/**
 * Occupied in Next Tick:
 * This function determines if a given location in the Metaverse is occupied in the next generation.
 *
 * The input and output of the function are
 * param isOccupied         A bool that indicates whether the location is occupied (true) or not (false) in the current generation.
 * param neighborCount      An integer holding the count of the number of occupied neighbors.

 * return                   True if the location will be occupied in the next generation; false otherwise.
 */
bool occupied_in_next_tick(bool currently_occupied, int neighbor_count) {
    if (currently_occupied) {
        return neighbor_count == 2 || neighbor_count == 3;
    }
    else {
        return neighbor_count == 3;
    }
    return false;
}


/**
 * Tick:
 * This function builds a new Metaverse one tick in the future from a given Metaverse.
 *
 * The input and output of the function are:
 * param currentGeneration   A metaverse_t const reference describing the current generation of the Metaverse.


 * return                   A new Metaverse (as a metaverse_t) that describes the next generation of the Metaverse.
 */
metaverse_t tick(const metaverse_t& board) {

    int rows = board.size();
    int cols = board[0].size();

    metaverse_t nextGeneration(rows, vector<bool>(cols, false));

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int aliveNeighbors = count_neighbors(board, row, col);

            if (board[row][col]) {
                if (aliveNeighbors == 2 || aliveNeighbors == 3) {
                    nextGeneration[row][col] = true;
                }
            }
            else {
                if (aliveNeighbors == 3) {
                    nextGeneration[row][col] = true;
                }
            }
        }
    }

    return nextGeneration;
}

/**
 * Resize Metaverse:
 * This function resizes a Metaverse according to a given size.
 *
 * The inputs and the output of the function are:
 * param size       An int representing the number of rows and columns in the Metaverse.
 * param metaverse  A metaverse_t reference to be resized according to the size.

 */

bool resize_metaverse(int rows, metaverse_t& board) {
    board.resize(rows, vector<bool>(rows, false));
    return true;
}


/**
 * Citizenship Row to Metaverse Row:
 * This function takes a string of characters read from a row of the Universe File and updates the initial citizenship of the Metaverse accordingly.
 *
 * The input and the output of the fuction are:
 * param rowString     A const reference to a std::string containing the citizenship row of the Metaverse.
 * param rowNumber     An int specifying the row whose occupancy is defined by the rowString.
 * param metaverse     A metaverse_t reference to be updated according to the preceding parameters.
 */
bool citizenship_row_to_metaverse_row(const std::string& input_row, int row,
    metaverse_t& board) {

    if (row < board.size() && input_row.length() == board[row].size()) {
        for (int i = 0; i < input_row.length(); i++) {
            if (input_row[i] == '1') {
                board[row][i] = true;
            }
            else {
                board[row][i] = false;
            }
        }
        return true;
    }

    return false;
}

/**
 * Read Metaverse Configuration Line from a Universe File:
 * This function reads and parses the configuration line from a Universe File.
 * It returns true and updates its out parameters if reading was successful.
 * It returns false otherwise.

 * The input and output of the function are:
 * param universeFile        A reference to a std::ifstream for the Universe File.
 * param size                A reference to an int for the size of the Metaverse.
 * param generation          A reference to an int for the number of generations to model.


 * return                    True if a valid configuration could be read from the Universe File; false otherwise.

 */
bool read_metaverse_configuration_line_from_file(std::ifstream& metaverse_file,
    int& size, int& generations) {

    int a{};
    metaverse_file >> a;

    size = a;

    char b{};
    metaverse_file >> b;

    int c{};
    metaverse_file >> c;

    generations = c;

    if (size > 0 && generations >= 0) {

        return true;
    }
    return false;
}

/**
 * Initialize Metaverse from a Universe File:
 * This function reads the configuration from a Universe File and initializes the Metaverse grid.

 * The inputs and the output of the function are:
 * universeFile   A reference to a std::ifstream for accessing the Universe File.
 * metaverse      A reference to a metaverse_t that will be configured according to the data in the Universe File.
 * generations    A reference to an int that will hold the number of generations to model (as read from the Universe File).

 * return              True if reading the configuration from the Universe File was successful; false otherwise.
 */

bool initialize_metaverse_from_file(std::ifstream& metaverse_file,
    metaverse_t& metaverse,
    int& generations) {


    int size{};
    int actual_row{};

    generations = 0;

    if (!read_metaverse_configuration_line_from_file(metaverse_file, size,
        generations)) {
        return false;
    }

    if (!resize_metaverse(size, metaverse)) {
        return false;
    }

    metaverse_file >> std::ws;
    while (!metaverse_file.eof()) {
        std::string line{};



        if (!getline(metaverse_file, line)) {

            return false;
        }


        if (!citizenship_row_to_metaverse_row(line, actual_row, metaverse)) {

            return false;
        }

        actual_row++;
        metaverse_file >> std::ws;
    }
    return actual_row == size;
}



/**
 * Model Metaverse Evolution:
 * This function models the evolution of the Metaverse for a specified number of generations.

 * The inputs and the output of the function are:
 * initialMetaverse  A const reference to a metaverse_t specifying the citizenship of the Metaverse at Generation 0.
 * numGenerations    The number of generations for which to model the Metaverse.
 */

void model_metaverse(const metaverse_t& starting_metaverse, int generations) {
    metaverse_t currentMetaverse = starting_metaverse;

    for (int generation = 0; generation < generations; generation++) {
        display_metaverse(cout, currentMetaverse);
        currentMetaverse = tick(currentMetaverse);
    }
}

