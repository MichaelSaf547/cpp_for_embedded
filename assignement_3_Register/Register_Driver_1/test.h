#ifndef __FUNCTIONNS__
#define __FUNCTIONS__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "register_Class.h"

bool error_Type(err_status name, std::string & result);

template <typename T>
bool test(permission type = read_and_Write, uint8 bit_number = 5)
{
    
    register_Driver<T> program_counter(0, type);
    err_status check;
    T res;
    bool print_Error;
    uint8 bit_res;
    std::string s;
    std::string temp;
    std::string error_temp;
    std::stringstream strings;

    std::ofstream OutputFile("Register_Driver_1/output.txt");

    s =  "\nTrying to write: ";
    check = program_counter.setRegisterValue(200);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done setting the register value.\n";
    }
    else
    {   
        s += "failed to set the register value due to " + error_temp + ".\n";
    } 

    OutputFile << s;

    s = "Trying to read: ";
    check = program_counter.getRegisterValue(res);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        strings << (unsigned int)res;
        strings >> temp;
        s += "done getting the register value and it is = " + temp + ".\n";
    }
    else
    {
        s += "failed to get the register value due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    s = "Trying to read bit number " + temp + ": ";
    check = program_counter.getBit(bit_number, bit_res);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        strings.clear();
        strings << (unsigned int)bit_res;
        strings >> temp;
        s += "done getting the bit value and it is = " + temp + ".\n";
    }
    else
    {
        s += "failed to get the register value due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    s =  "Trying to set bit number " + temp + ": ";
    check = program_counter.setBit(bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done setting the bit value.\n";
    }
    else
    {
        s += "failed to set the bit value due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;

    s = "Trying to read bit number " + temp + ": ";
    check = program_counter.getBit(bit_number, bit_res);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        strings.clear();
        strings << (unsigned int)bit_res;
        strings >> temp;
        s += "done getting the bit value and it is = " + temp + ".\n";
    }
    else
    {
        s += "failed to get the bit value due to " + error_temp + ".\n";
    }
    
    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;

    s = "Trying to clear bit number " + temp + ": ";
    check = program_counter.clearBit(bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done clearing the bit value.\n";
    }
    else
    {
        s += "failed to clear the bit value due to " + error_temp + ".\n";
    }

    OutputFile << s;


    s = "Trying to change register permission to reserved: ";
    check = program_counter.setPermission(reserved);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done changing the permission.\n";
    }
    else
    {
        s += "failed to change the permission due to " + error_temp + ".\n";
    }

    OutputFile << s;


    s = "Trying to write: ";
    check = program_counter.setRegisterValue(200);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done setting the register value.\n";
    }
    else
    {
        s += "failed to set the register value due to " + error_temp + ".\n";
    } 

    OutputFile << s;


    s ="Trying to read: ";
    check = program_counter.getRegisterValue(res);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        strings.clear();
        strings << (unsigned int)res;
        strings >> temp;
        s +="done getting the register value and it is = " + temp + ".\n";
    }
    else
    {
        s += "failed to get the register value due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    s = "Trying to change bit " + temp + " permission to write only: ";
    check = program_counter.setPermission(write_Only, true, bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done changing the permission.\n" ;
    }
    else
    {
        s += "failed to change the permission due to " + error_temp + ".\n";
    }

    OutputFile << s;
    
    
    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    
    s = "Trying to set bit number " + temp + ": ";
    check = program_counter.setBit(bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done setting the bit value.\n";
    }
    else
    {
        s += "failed to set the bit value due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    
    s = "Trying to read bit number " + temp + ": ";
    check = program_counter.getBit(bit_number, bit_res);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        strings.clear();
        strings << (unsigned int)bit_res;
        strings >> temp;    
        s += "done getting the bit value and it is = " + temp + ".\n";
    }
    else
    {
        s += "failed to get the bit value due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    s = "Trying to clear bit number " + temp + ": ";
    check = program_counter.clearBit(bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done clearing the bit value.\n";
    }
    else
    {
        s += "failed to clear the bit value due to " + error_temp + ".\n";
    }

    OutputFile << s;


    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    
    s = "Trying to change bit " + temp + " permission to read only: ";
    check = program_counter.setPermission(read_Only, true, bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done changing the permission.\n";
    }
    else
    {
        s += "failed to change the permission due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    s = "Trying to set bit number " + temp + ": ";
    check = program_counter.setBit(bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done setting the bit value.\n";
    }
    else
    {
        s += "failed to set the bit value due to " + error_temp + ".\n";
    }

    OutputFile << s;


    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    s = "Trying to read bit number " + temp + ": ";
    check = program_counter.getBit(bit_number, bit_res);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        strings.clear();
        strings << (unsigned int)bit_res;
        strings >> temp;
        
        s += "done getting the bit value and it is = " + temp + ".\n";
    }
    else
    {
        s += "failed to get the bit value due to " + error_temp + ".\n";
    }

    OutputFile << s;

    strings.clear();
    strings << (unsigned int)bit_number;
    strings >> temp;
    s = "Trying to clear bit number " + temp + ": ";
    check = program_counter.clearBit(bit_number);
    print_Error = error_Type(check, error_temp);
    if(print_Error == true)
    {
        s += "done clearing the bit value.\n\n";
    }
    else
    {
        s += "failed to clear the bit value due to " + error_temp + ".\n\n";
    }

    OutputFile << s;

    OutputFile.close();

    return true;
}

#endif