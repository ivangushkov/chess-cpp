#include "move_parser.h"

#include <array>
#include <string>
#include <iostream>

std::string remove_whitespaces(std::string input_str) {
    int write_ind = 0;
    int n = input_str.length();

    for (int i = 0; i < n; i++) {

        if (input_str[i] != ' ') {
            input_str[write_ind] = input_str[i];
            write_ind += 1;
        }
    }
    
    return input_str.substr(0, write_ind);
};

ParsedMove parse_move(std::string move_candidate) {

    /*
    Parses string inputs on experced form "a1 b4", i.e. "FLFN TLTN"
    where F = from, T = to, L = letter, N = number

    F = from 
    T = to
    N = number
    L = letter
    */
    

    move_candidate = remove_whitespaces(move_candidate);

    std::cout << "Parse string: " << move_candidate << std::endl;

    ParsedMove output = {std::array<int, 4> {0, 0, 0, 0}, 0};

    // Extract the numbers and convert them to chess indices
    int FN = move_candidate[1] - '0' - 1;
    int TN = move_candidate[3] - '0' - 1;

    // Extract the letters and turn them into indices
    char FL = move_candidate[0];
    char TL = move_candidate[2];

    int fInd{10000};
    int tInd{10000};

    bool correctFL = 0;
    bool correctTL = 0;

    std::array<char, 8> validLetters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

    for (int i = 0; i < 8; i++) {
        if (FL == validLetters[i]) {
            fInd = i;
            correctFL = 1;
        }
        if (TL == validLetters[i]) {
            tInd = i;
            correctTL = 1;
        }
    }

    output.move[0] = fInd;
    output.move[1] = FN;
    output.move[2] = tInd;
    output.move[3] = TN;


    // Check if the move is correct
    output.valid = 1;
    std::string error_flag = " ";

    if (FN < 0 || FN > 7) {
        output.valid = 0;
        error_flag += "Invalid \"from\" number! ";
    }

    if (TN < 0 || TN > 7) {
        output.valid = 0;
        error_flag += "Invalid \"to\" number! ";
    }

    if (fInd < 0 || fInd > 7) {
        output.valid = 0;
        error_flag += "Invalid \"from\" letter! ";
    }

    if (tInd < 0 || tInd > 7) {
        output.valid = 0;
        error_flag += "Invalid \"to\" letter! ";
    }
    
    if (move_candidate.length() != 4) {
        output.valid = 0;
        error_flag += "Incorrect format (length)! ";
    }

    if (FN == TN && fInd==tInd) {
        output.valid = 0;
        error_flag += "Incorrect format (from = to)";
    }

    if (output.valid) {
        output.flag = "Looks like a correct move!";
    } else {
        output.flag = "Encountered the following errors while parsing the move: " + error_flag;
    }

    //std::cout << output.move[0] << std::endl;
    //std::cout << output.move[1] << std::endl;
    //std::cout << output.move[2] << std::endl;
    //std::cout << output.move[3] << std::endl;
    //std::cout << output.valid << std::endl;
    //std::cout << output.flag << std::endl;

    return output;

};