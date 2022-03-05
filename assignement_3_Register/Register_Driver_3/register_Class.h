#ifndef __REGISTER_DRIVER__
#define __REGISTER_DRIVER__

#include <iostream>

typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;

enum permission
{
    read_Only = 0,
    write_Only = 1,
    read_and_Write = 2,
    reserved = 3
};

enum err_status
{
    error_Read = 0,
    error_Write = 1,
    error_bit_value = 2,
    Done = 3
};

template <typename T> struct bits_val;

template <typename T> 
union reg_bits
{
    T in_Bytes;

    bits_val<T> bits;
};


template <typename T> class register_Driver;

#endif