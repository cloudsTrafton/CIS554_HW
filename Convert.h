//Header file for Convert.cpp class
//Claudia Trafton, Homework1 for CIS554

#ifndef CONVERT_H
#define CONVERT_H

class Convert {

    public:
        int convert(int num, int base);

        int getNumber();

        int getBase();

        int validate(int num, int base);

        int printError(int error);

        void printConvertedNumber(int converted);
            

};
#endif