
#include "register_Class.h"

template<>
class register_Driver<uint16>
{
    public:
        register_Driver(uint16 value = 0, permission per_value = read_and_Write)
        : register_area{value}, perm{per_value}
        {
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
                    first = 0xffff;
                    second = 0;
                    break;
                }

                case read_and_Write:
                {
                    first = 0;
                    second = 0xffff;
                    break;
                }

                case reserved:
                {
                    first = 0xffff;
                    second = 0xffff;
                    break;
                }    
                
                default:
                    break;
            }
                
            
        }
        err_status setRegisterValue(uint16 value)
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
        err_status getRegisterValue(uint16 & result)
        {
            err_status res= Done;
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
        err_status setBit(uint8 bit)
        {
            err_status res= Done;
            if(bit >= 16)
            {
                res = error_bit_value;
            }

            if((((first >> bit) & 1) ^ ((second >> bit) & 1)) == 0)
            {
                res = error_Write;
            }
            else
            {
                register_area |= (((uint16)1) << bit);
            }
            return res;
        }
        err_status clearBit(uint8 bit)
        {
            err_status res = Done;
            if(bit >= 16)
            {
                res = error_bit_value;
            }

            if((((first >> bit) & 1) ^ ((second >> bit) & 1)) == 0)
            {
                res = error_Write;
            }
            else
            {
                register_area &= ~(((uint16)1) << bit);
            }
            return res;
        }
        err_status getBit(uint8 bit, uint8 &result)
        {
            err_status res = Done;
            if(bit >= 16)
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
        err_status setPermission(permission per_val, bool reg_bit = false, uint8 bit_number = 0)
        {
            err_status res = Done;
            if(reg_bit == false)
            {
                perm = per_val;
            }
            else
            {
                if(bit_number >= 16)
                {
                    res = error_bit_value;
                }
                switch (per_val)
                {
                    case read_Only:
                    {
                        first = first & (~((uint16)1 << bit_number));
                        second = second & (~((uint16)1 << bit_number));
                        break;
                    }

                    case write_Only:
                    {
                        first = first | ((uint16)1 << bit_number);
                        second = second & (~((uint16)1 << bit_number));
                        break;
                    }

                    case read_and_Write:
                    {
                        first = first & (~((uint16)1 << bit_number));
                        second = second | ((uint16)1 << bit_number);
                        break;
                    }

                    case reserved:
                    {
                        first = first | ((uint16)1 << bit_number);
                        second = second | ((uint16)1 << bit_number);
                        break;
                    }    
                    
                    default:
                        break;
                }
            }
            return res;
        }


        ~register_Driver(void)
        {}

    private:
        uint16  register_area;
        permission perm;
        uint16 first;
        uint16 second;
        
};