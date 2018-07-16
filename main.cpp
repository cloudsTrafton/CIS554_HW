/*Driver program for converting numbers from any other base to base 10
Homework 1 for CIS554 by Claudia Trafton
If you look at my stuff, please do not copy it and please cite me if you use it or reference it at all.*/

#include <iostream>
#include <math.h>
#include "Convert.h"

int main(){

    Convert convert;

    int num = convert.getNumber();
    if(num < 0){
        convert.printError(num);
        return num;
    }

    int base = convert.getBase();
    if(base < 0){
        convert.printError(base);
        return base;
    }

    int valid = convert.validate(num, base);
    if(valid != 0){
        convert.printError(valid);
        return valid;
    }

    int converted = convert.convert(num, base);
    convert.printConvertedNumber(converted);
    return 0;
}