//Implementation of Convert.h class containing methods for converting a number to base 10 entered by the user 
//Homework 1 for CIS554 by Claudia Trafton
//If you look at my stuff, please do not copy it and please cite me if you use it or reference it at all.

//Allow us to create the header file
#include <iostream>
#include <math.h>
#include "Convert.h"

        /*
            *int num: a postive whole number to be converted to a base 10
            *int base: a positive whole number that represents the base of num
            * The function converts the inputted number to its base 10 representation
            * Please note that numbers that are too big for int type will throw an error.
        */
        int Convert::convert(int num, int base){
            int decimalBase = 10;
            int converted = 0;
            int power = 0;
            while(num != 0){
                int digit = num % decimalBase; //this gets us the digit we are looking at in reverse
                num = num / decimalBase; //saves the number after we have discarded the digit we are using
                converted = converted + (digit * pow(base,power)); //perform conversion on the digit as outlined in assignment
                power++; //move over to the next place
            }
            return converted;
        }

        /*
            * Retrieves and performs error handling on user input.
            * Checks that inputs are positive integers
        */
        int Convert::getNumber(){
            int num = 0;
            int error = 0;

            std::cout << "Input the number: ";
            std::cin >> num;
            if(std::cin.fail() || num <= 0){
                error = -1;
                return error;
            }
            else {
                return num;
            }
        }

        int Convert::getBase(){
            int base = 0;
            int error = 0;

            std::cout << "Input the base: ";
            std::cin >> base;
            if(std::cin.fail() || base <= 0){
                error = -2;
                return error;
            }
            else {
                return base;
            } 
        }

        /*get all of the digits and check to verify that there is no digit greater than equal to the base
        that would mean an invalid nunmber. */
        int Convert::validate(int num, int base){
            int decimalBase = 10;
            int error = 0;
            while(num != 0){
                int digit = num % decimalBase;
                num = num / decimalBase;
                if(digit >= base){
                    error = -3;
                    return error;
                }
            }
            return error;
        }

        /*
            * Print any errors to the console. If there are no errors, do nothing.
            * Note that the error specifies that the number must not be too big for int type
        */
        int Convert::printError(int error){
            switch(error){
                case -1:
                    std::cout << "Please input a positive integer of reasonable size to be converted to decimal.\n";
                    break;
                case -2: 
                    std::cout << "Please input a positive integer of reasonable size for your number's base.\n";
                    break;
                case -3: 
                    std::cout << "The number you've entered does not exist in this base.\n";
                    break;
                default:
                    break;

            }
            return error;
        }

        void Convert::printConvertedNumber(int converted){
            std::cout << "Your number in base 10 is: ";
            std::cout << converted;
            std::cout << "\n";
        }


