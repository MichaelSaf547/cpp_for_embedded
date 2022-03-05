
#include "register_Class.h"

template<>
struct bits_val<uint16>
{
    uint16 b0 : 1;
    uint16 b1 : 1;
    uint16 b2 : 1;
    uint16 b3 : 1;
    uint16 b4 : 1;
    uint16 b5 : 1;
    uint16 b6 : 1;
    uint16 b7 : 1;
    uint16 b8 : 1;
    uint16 b9 : 1;
    uint16 b10 : 1;
    uint16 b11 : 1;
    uint16 b12 : 1;
    uint16 b13 : 1;
    uint16 b14 : 1;
    uint16 b15 : 1;
};

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
                    first.in_Bytes = 0;
                    second.in_Bytes = 0;
                    break;
                }

                case write_Only:
                {
                    first.in_Bytes = 0xffff;
                    second.in_Bytes = 0;
                    break;
                }

                case read_and_Write:
                {
                    first.in_Bytes = 0;
                    second.in_Bytes = 0xffff;
                    break;
                }

                case reserved:
                {
                    first.in_Bytes = 0xffff;
                    second.in_Bytes = 0xffff;
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
                register_area.in_Bytes = value;
            }
            return res;
        }
        err_status getRegisterValue(uint16 & result)
        {
            err_status res = Done;
            if(perm == write_Only || perm == reserved)
            {
                res = error_Read;
            }
            else
            {
                result = register_area.in_Bytes;
            }
            return res;
        }
        err_status setBit(uint8 bit)
        {
            uint8 temp1;
            uint8 temp2;
            bool check;
            err_status res = Done;
            if(bit >= 16)
            {
                res = error_bit_value;
            }

            check = get_Bit_Union(first, bit, temp1);
            if(check == false)
            {
                res = error_bit_value;
            }
            check = get_Bit_Union(second, bit, temp2);
            if(check == false)
            {
                res = error_bit_value;
            }

            if((temp1 ^ temp2) == 0)
            {
                res = error_Write;
            }
            else
            {
                check = set_Bit_Union(register_area, bit, 1);
                if(check == false)
                {
                    res = error_bit_value;
                }
            }
            return res;
        }

        err_status clearBit(uint8 bit)
        {
            uint8 temp1;
            uint8 temp2;
            bool check;
            err_status res = Done;
            if(bit >= 16)
            {
                res = error_bit_value;
            }

            check = get_Bit_Union(first, bit, temp1);
            if(check == false)
            {
                res = error_bit_value;
            }

            check = get_Bit_Union(second, bit, temp2);
            if(check == false)
            {
                res = error_bit_value;
            }

            if((temp1 ^ temp2) == 0)
            {
                res = error_Write;
            }
            else
            {
                check = set_Bit_Union(register_area, bit, 0);
                if(check == false)
                {
                    res = error_bit_value;
                }
            }
            return res;
        }
        err_status getBit(uint8 bit, uint8 & result)
        {
            uint8 temp1;
            uint8 temp2;
            bool temp3;
            bool temp4;
            bool check;
            err_status res = Done;
            if(bit >= 16)
            {
                res = error_bit_value;
            }
            
            check = get_Bit_Union(first, bit, temp1);
            if(check == false)
            {
                res = error_bit_value;
            }

            check = get_Bit_Union(second, bit, temp2);
            if(check == false)
            {
                res = error_bit_value;
            }

            temp3 = temp1 & temp2;

            check = get_Bit_Union(first, bit, temp1);
            if(check == false)
            {
                res = error_bit_value;
            }

            check = get_Bit_Union(second, bit, temp2);

            temp4 = ((temp1 == 1) && (temp2 == 0)); 

            if(temp3 || temp4)
            {
                res = error_Read;
            }
            else
            {
                check = get_Bit_Union(register_area, bit, result);
                if(check == false)
                {
                    res = error_bit_value;
                }
            }
            return res;
        }
        err_status setPermission(permission per_val, bool reg_bit = false, uint8 bit_number = 0)
        {
            bool check;
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
                else
                {
                    switch (per_val)
                    {
                        case read_Only:
                        {
                            check = set_Bit_Union(first, bit_number, 0);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }
                            
                            check = set_Bit_Union(second, bit_number, 0);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }
                            break;
                        }

                        case write_Only:
                        {
                            check = set_Bit_Union(first, bit_number, 1);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }
                            check = set_Bit_Union(second, bit_number, 0);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }
                            break;
                        }

                        case read_and_Write:
                        {
                            check = set_Bit_Union(first, bit_number, 0);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }
                            
                            check = set_Bit_Union(second, bit_number, 1);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }
                            
                            break;
                        }

                        case reserved:
                        {
                            check = set_Bit_Union(first, bit_number, 1);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }

                            check = set_Bit_Union(second, bit_number, 1);
                            if(check == false)
                            {
                                res = error_bit_value;
                            }

                            break;
                        }    
                        
                        default:
                            res = error_bit_value;
                            break;
                    }
                }
                
            }
            return res;
        }

        bool set_Bit_Union(reg_bits<uint16> & reg, uint8 bit, uint8 val)
        {
            switch (bit)
            {
            case 0:
                reg.bits.b0 = val;
                return true;
                break;
            case 1:
                reg.bits.b1 = val;
                return true;
                break;
            case 2:
                reg.bits.b2 = val;
                return true;
                break;
            case 3:
                reg.bits.b3 = val;
                return true;
                break;
            case 4:
                reg.bits.b4 = val;
                return true;
                break;
            case 5:
                reg.bits.b5 = val;
                return true;
                break;
            case 6:
                reg.bits.b6 = val;
                return true;
                break;
            case 7:
                reg.bits.b7 = val;
                return true;
                break;
            case 8:
                reg.bits.b8 = val;
                return true;
                break;
            case 9:
                reg.bits.b9 = val;
                return true;
                break;
            case 10:
                reg.bits.b10 = val;
                return true;
                break;
            case 11:
                reg.bits.b11 = val;
                return true;
                break;
            case 12:
                reg.bits.b12 = val;
                return true;
                break;
            case 13:
                reg.bits.b13 = val;
                return true;
                break;
            case 14:
                reg.bits.b14 = val;
                return true;
                break;
            case 15:
                reg.bits.b15 = val;
                return true;
                break;
            default:
                return false;
                break;
            }
        }    

        bool get_Bit_Union(reg_bits<uint16> reg, uint8 bit, uint8 & res)
        {
            switch (bit)
            {
            case 0:
                res = reg.bits.b0;
                return true;
                break;
            case 1:
                res = reg.bits.b1;
                return true;
                break;
            case 2:
                res = reg.bits.b2;
                return true;
                break;
            case 3:
                res = reg.bits.b3;
                return true;
                break;
            case 4:
                res = reg.bits.b4;
                return true;
                break;
            case 5:
                res = reg.bits.b5;
                return true;
                break;
            case 6:
                res = reg.bits.b6;
                return true;
                break;
            case 7:
                res = reg.bits.b7;
                return true;
                break;
            case 8:
                res = reg.bits.b8;
                return true;
                break;
            case 9:
                res = reg.bits.b9;
                return true;
                break;
            case 10:
                res = reg.bits.b10;
                return true;
                break;
            case 11:
                res = reg.bits.b11;
                return true;
                break;
            case 12:
                res = reg.bits.b12;
                return true;
                break;
            case 13:
                res = reg.bits.b13;
                return true;
                break;
            case 14:
                res = reg.bits.b14;
                return true;
                break;
            case 15:
                res = reg.bits.b15;
                return true;
                break;
            default:
                return false;
                break;
            }
        }    

        ~register_Driver(void)
        {}

    private:
        reg_bits<uint16>  register_area;
        permission perm;
        reg_bits<uint16> first;
        reg_bits<uint16> second;
        
};