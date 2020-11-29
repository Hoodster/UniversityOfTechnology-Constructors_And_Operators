#include <iostream>
#include "Napis.h"

void printDefaultNapisCall();
void printArrayNapisCall();
void printCharacterNapisCall();
void printConcatCharacterToObject();
void printConcatArrayToObject();
void printConcatObjectToObject();
void printIndexFunctionResults();

int main() {
    printCharacterNapisCall();
    std::cout << std::endl;
    printArrayNapisCall();
    std::cout << std::endl;
    printDefaultNapisCall();
    std::cout << std::endl;
    printConcatCharacterToObject();
    std::cout << std::endl;
    printConcatArrayToObject();
    std::cout << std::endl;
    printConcatObjectToObject();
    std::cout << std::endl;
    printIndexFunctionResults();
    return 0;
}

void printDefaultNapisCall() {
    Napis * napisInstance = new Napis();
    std::cout << "3. Default _array instance" << std::endl;
    napisInstance->printText();
    delete napisInstance;
}

void printArrayNapisCall() {
    char arr[] = "test";
    Napis * napisInstance = new Napis(arr);
    std::cout << "2. Array instance" << std::endl;
    napisInstance->printText();
    delete napisInstance;
}

void printCharacterNapisCall() {
    char cLetter = 'c';
    Napis * napisInstance = new Napis(cLetter);
    std::cout << "1. Single character instance" << std::endl;
    napisInstance->printText();
    delete napisInstance;
}

void printConcatCharacterToObject() {
    std::cout << "4. Union character to object" << std::endl;
    char character = '$';
    Napis * napisInstance = new Napis("test with merged character = ");
    napisInstance->concat(character);
    napisInstance->printText(true);
    delete napisInstance;
}

void printConcatArrayToObject() {
    std::cout << "5. Union text to object" << std::endl;
    char arr[] = "test2";
    Napis * napisInstance = new Napis("test with merged text = ");
    napisInstance->concat(arr);
    napisInstance->printText(true);
    delete napisInstance;
}

void printConcatObjectToObject() {
    std::cout << "6. Union object to object" << std::endl;
    Napis * napisInstance = new Napis("destination object text ===> ");
    Napis * mergeInstance = new Napis("source object text");
    napisInstance->concat(*mergeInstance);
    napisInstance->printText(true);
}

void printIndexFunctionResults() {
    std::cout << "7. Indexing operations" << std::endl;
    char fixTypo = 'Y';
    Napis * napisInstance = new Napis("tIpo intended for fix");
    std::cout << "Full text: " << napisInstance->get_text() << std::endl;

    int indexOfTypo = 1;
    std::cout << "Letter of typo: " << napisInstance->index(indexOfTypo) << " at index " << indexOfTypo << std::endl;

    std::cout << "Replacement with: " << fixTypo << std::endl;

    napisInstance->index(indexOfTypo, fixTypo);
    std::cout << "Result: " << napisInstance->get_text();
    delete napisInstance;
}