//
// Created by Jakub Porębski on 28/11/2020.
//

#ifndef UNTITLED4_NAPIS_H
#define UNTITLED4_NAPIS_H
#include <cstring>


class Napis {
    public:
        Napis() = default;

        explicit  Napis(const char *text) {
            int length = std::strlen(text);
            this->_array = new char[length];
            std:strcpy(this->_array, text);
        }

        explicit Napis(char character) {
            this->_array = new char[1];
            this->_array[0] = character;
        }

        explicit Napis(Napis const &napis) {
            this->_array = napis._array;
        }

        ~Napis() {
            delete _array;
        }

        Napis & operator =(Napis const & src) = default;

        Napis & operator +=(Napis const & src) {
            int destLength = this->getTextLength();
            int srcLength = src.getTextLength();
            int newSum = (destLength + srcLength);
            for(int i = destLength; i < newSum; i++) {
                this->_array[i] = src._array[i - destLength];
            }
            return *this;
        }

        char* get_text() const { return _array; }
        int getTextLength(char *text = NULL) const;
        void printText(bool printAsNormalText = false);
        char index(int index, char character = NULL);
        Napis & concat(Napis const & src);
        Napis & concat(char text[]);
        Napis & concat(char character);

    private:
        char* _array;

};


#endif //UNTITLED4_NAPIS_H
