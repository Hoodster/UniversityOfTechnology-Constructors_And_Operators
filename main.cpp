#include <iostream>
#include "Napis.h"

void printDefaultNapisCall();
void printArrayNapisCall();
void printCharacterNapisCall();
void printConcatCharacterToObject();
void printConcatArrayToObject();
void printConcatObjectToObject();
void printIndexFunctionResults();
void printReassignmentResults();

char indent[] = "    ";

int main() {
    printCharacterNapisCall();
    std::cout << "\n";
    printArrayNapisCall();
    std::cout << "\n";
    printDefaultNapisCall();
    std::cout << "\n";
    printConcatCharacterToObject();
    std::cout << "\n";
    printConcatArrayToObject();
    std::cout << "\n";
    printConcatObjectToObject();
    std::cout << "\n";
    printIndexFunctionResults();
    std::cout << "\n";
    printReassignmentResults();
    return 0;
}

void printCharacterNapisCall() {
    std::cout << "1. Single character instance" << "\n";
    char cLetter = 'c';
    Napis * napisInstance = new Napis(cLetter);
    std::cout << indent << "1.1 Result: \n";
    napisInstance->printText();
    delete napisInstance;
}

void printArrayNapisCall() {
    std::cout << "2. Array instance" << "\n";
    char arra[] = "test";
    Napis * napisInstance = new Napis(arra);
    std::cout << indent << "2.1 Result: \n";
    napisInstance->printText();
    delete napisInstance;
}

void printDefaultNapisCall() {
    std::cout << "3. Default _array instance" << "\n";
    Napis * napisInstance = new Napis();
    std::cout << indent << "3.1 Result: \n";
    napisInstance->printText();
    delete napisInstance;
}

void printConcatCharacterToObject() {
    std::cout << "4. Union character to object" << "\n";
    std::cout << indent << "4.1 Character: ";
    char character = '$';
    std::cout << character << "\n";

    std::cout << indent << "4.2 Instance text: ";
    Napis * napisInstance = new Napis("test with merged character = ");
    napisInstance->printText(true);

    std::cout << indent << "4.3 Result: ";
    napisInstance->concat(character);
    napisInstance->printText(true);
    delete napisInstance;
}

void printConcatArrayToObject() {
    std::cout << "5. Union text to object" << "\n";
    std::cout << indent << "5.1 Merge text: ";
    char arr[] = "new sample text";
    std::cout << arr << "\n";

    std::cout << indent << "5.2 Instance text: ";
    Napis * napisInstance = new Napis("test with merged text = ");
    napisInstance->printText(true);

    std::cout << indent << "5.3 Result: ";
    napisInstance->concat(arr);
    napisInstance->printText(true);
    delete napisInstance;
}

void printConcatObjectToObject() {
    std::cout << "6. Union object to object" << "\n";
    std::cout << indent << "6.1 Base text: ";
    Napis * napisInstance = new Napis("destination object text ===> ");
    napisInstance->printText(true);

    std::cout << indent << "6.2 Merging text: ";
    Napis * mergeInstance = new Napis("source object text");
    mergeInstance->printText(true);

    std::cout << indent << "6.3 Result: ";
    napisInstance->concat(*mergeInstance);
    napisInstance->printText(true);
}

void printIndexFunctionResults() {
    std::cout << "7. Indexing operations" << "\n";
    char fixTypo = 'Y';
    std::cout << indent << "7.1 Full text: ";
    Napis * napisInstance = new Napis("tIpo intended for fix");
    napisInstance->printText(true);

    int indexOfTypo = 1;
    std::cout << indent<< "7.2 Letter of typo: " << napisInstance->index(indexOfTypo)
    << " at index " << indexOfTypo << "\n";

    std::cout << indent << "7.3 Replacement with: " << fixTypo << "\n";

    napisInstance->index(indexOfTypo, fixTypo);
    std::cout << indent << "7.4 Result: ";
    napisInstance->printText(true);
    delete napisInstance;
}

void printReassignmentResults() {
    std::cout << "8. Reassignment" << "\n";
    Napis * destinationInstance = new Napis("destination object text");
    Napis * sourceInstance = new Napis("source object text");

    std::cout << indent << "8.1 Before reassignment: ";
    destinationInstance->printText(true);

    std::cout  << indent << "8.2 After reassignment: ";
    destinationInstance = sourceInstance;
    destinationInstance->printText(true);
    delete destinationInstance;
}
