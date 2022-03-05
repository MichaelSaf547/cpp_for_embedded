
#include "test.h"

bool error_Type(err_status name, std::string & result)
{
    bool res = true;
    switch (name)
    {
    case Done:
        {
            result = "Done";
            break;
        }
    case error_bit_value:
        {
            result = "Error Bit Value";
            res = false;
            break;
        }
    case error_Read:
        {
            result = "Error Read";
            res = false;
            break;
        }
        case error_Write:
        {
            result = "Error Write";
            res = false;
            break;
        }
    
    default:
        res = false;
        break;
    }
    return res;
}