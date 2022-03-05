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

template <typename T>
class register_Driver
{
    public:
        register_Driver(T value = 0, permission per_value = read_and_Write);
        err_status setRegisterValue(T value);
        err_status getRegisterValue(T & res);
        err_status setBit(T bit);
        err_status clearBit(T bit);
        err_status getBit(T bit, uint8 &res);
        err_status setPermission(permission per_val, bool reg_bit = false, uint8 bit_number = 0);
        ~register_Driver(void);

    private:
        T  register_area;
        permission perm;
        T first;
        T second;
        
};

template <typename T>
register_Driver<T>::register_Driver(T value, permission per_value)
: register_area{value}, perm{per_value}
{   
    first = 0;
    first = first >> 0;
    switch (per_value)
    {
        case read_Only:
        {
            first = 0;
            second = 0;
            break;
        }

        case write_Only:
        {
            first = (T)0xffffffff;
            second = 0;
            break;
        }

        case read_and_Write:
        {
            first = 0;
            second = (T)0xffffffff;
            break;
        }

        case reserved:
        {
            first = (T)0xffffffff;
            second = (T)0xffffffff;
            break;
        }    
        
        default:
            break;
    }
}

template <typename T>
err_status register_Driver<T>::setRegisterValue(T value)
{
    err_status res = Done;
    if(perm == read_Only || perm == reserved)
    {
        res = error_Write;
    }
    else
    {
        register_area = value;
    }
    return res;
}

template <typename T>
err_status register_Driver<T>::getRegisterValue(T & result)
{
    err_status res = Done;
    if(perm == write_Only || perm == reserved)
    {
        res = error_Read;
    }
    else
    {
        result = register_area;
    }
    return res;
}

template <typename T>
err_status register_Driver<T>::setBit(T bit)
{
    err_status res = Done;
    if(bit >= ((sizeof(T) << 3)))
    {
        res = error_bit_value;
    }

    if((((first >> bit) & 1) ^ ((second >> bit) & 1)) == 0)
    {
        res = error_Write;
    }
    else
    {
        register_area |= (((T)1) << bit);
    }
    return res;
}

template <typename T>
err_status register_Driver<T>::clearBit(T bit)
{
    err_status res = Done;
    if(bit >= ((sizeof(T) << 3)))
    {
        res = error_bit_value;
    }

    if((((first >> bit) & 1) ^ ((second >> bit) & 1)) == 0)
    {
        res = error_Write;
    }
    else
    {
        register_area &= ~(((T)1) << bit);
    }
    return res;
}

template <typename T>
err_status register_Driver<T>::getBit(T bit, uint8 & result)
{
    err_status res = Done;
    if(bit >= ((sizeof(T) << 3)))
    {
        res = error_bit_value;
    }
    
    bool temp1 = ((first >> bit) & 1) && ((second >> bit) & 1);
    bool temp2 = ((((first >> bit) & 1) == 1) && (((second >> bit) & 1) == 0)); 

    if(temp1 || temp2)
    {
        res = error_Read;
    }
    else
    {
        result = (register_area >> bit) & 1;
    }
    return res;
}

template <typename T>
err_status register_Driver<T>::setPermission(permission per_val, bool reg_bit, uint8 bit_number)
{
    err_status res = Done;
    if(reg_bit == false)
    {
        perm = per_val;
    }
    else
    {
        if(bit_number >= ((sizeof(T) << 3)))
        {
            res = error_bit_value;
        }
        switch (per_val)
        {
            case read_Only:
            {
                first = first & (~((T)1 << bit_number));
                second = second & (~((T)1 << bit_number));
                break;
            }

            case write_Only:
            {
                first = first | ((T)1 << bit_number);
                second = second & (~((T)1 << bit_number));
                break;
            }

            case read_and_Write:
            {
                first = first & (~((T)1 << bit_number));
                second = second | ((T)1 << bit_number);
                break;
            }

            case reserved:
            {
                first = first | ((T)1 << bit_number);
                second = second | ((T)1 << bit_number);
                break;
            }    
            
            default:
                break;
        }
    }
    return res;
}

template <typename T>
register_Driver<T>::~register_Driver(void)
{

}


#endif