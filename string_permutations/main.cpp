/*
    Copyright 2021 by Michał Gibas

    Given a string generate all of its possible permutations.
*/

#include <iostream>

void gen_permutations(std::string str, std::string buffer, size_t n);

int main(void) {
    std::string str;
    std::cout << "This program generates all possible permutations for a given string.\n"
        << "Author: @TheMadMike \n\n"
        << "Please type in a string: ";
    std::cin >> str;
    gen_permutations(str, "", str.length());

    return 0;
}

std::string remove_char(std::string input, size_t pos) {
    std::string output = "";
    for(size_t i = 0; i < input.length(); ++i) {
        if(i != pos) {
            output += input.at(i);
        }
    }

    return output;
}

void gen_permutations(std::string str, std::string buffer, size_t n) {
    if(buffer.length() == n) {
        std::cout << buffer << '\n';
        return;
    }

    for(size_t i = 0; i < str.length(); ++i) {
        gen_permutations(remove_char(str, i), buffer+str.at(i), n);
    }
}
