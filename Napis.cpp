//
// Created by Jakub Porębski on 28/11/2020.
//

#include <iostream>
#include "Napis.h"

void Napis::printText(bool printAsNormalText) {
    char *text = Napis::get_text();
    int arrayLength = Napis::getTextLength(text);

    printAsNormalText ? std::cout << "" : std::cout << "[" << std::endl;

    for (int i = 0;i < arrayLength; i++) {
        std::cout << text[i];
        if (i != arrayLength - 1 && !printAsNormalText) {
            std::cout << ",";
        }

       if (!printAsNormalText) {
           std::cout << std::endl;
       }
    }
    const char *endText = printAsNormalText ? "" : "]";
    std:: cout << endText << std::endl;
}

int Napis::getTextLength(char *text) const {
    if (text == NULL) {
        text = Napis::get_text();

        if (text == NULL) {
            return 0;
        }
    }
    return std::strlen(text);
}

Napis & Napis::concat(Napis const &src) {
    return *this += src;
}

Napis & Napis::concat(char *text) {
    const Napis * newInstance = new Napis(text);
    return *this += *newInstance;
}

Napis & Napis::concat(char character) {
    const Napis * newInstance = new Napis(character);
    return *this += *newInstance;
}

char Napis::index(int index, char character) {
    char *text = Napis::get_text();
    if (character == NULL) {
        return text[index];
    } else {
        text[index] = character;
        return text[index];
    }
}
