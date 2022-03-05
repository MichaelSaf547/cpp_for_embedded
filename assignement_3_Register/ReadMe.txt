There are three versions:
1-1-Using the class template
  2-Using enum for the error status 
  3-Using enum for the permissions
  4-Using 2 variables of T type the ith bit in both variables to represent the permission
    of each bit (0, 0 for read_only)
                (0, 1 for write_only)
                (1, 0 for read_write)
                (1, 1 for reserved)
  
  But here there is not a way to forbidden the user from creating a register of type float
  or even set and map so i added shift operation in the constructor to generate error.
  
2-1-Using the same as above but i explicitly declared the three available sizes
    in my machine (unsigned char, unsigned short it, unsigned int) -unsigned long int 
    is the same as unsigned int in my machine and it can be added if needed-
    so the compiler will not allow the creation of the register from the start.
    
3-1-Using the same as above but instead of using SET_BIT and GET_BIT 
    i created template of union that contains a register size and a template of struct
    that contains bits accessible but i needed two new functions
    1- set_Bit_Union, to change the value of th bit.
    2- get_Bit_Union, to read the value of the bit.
    
    But i think it is not faster than version 2 due to the cost of function context switching 
    and jump. It may be faster if i kept the switch in the function itself but 
    the code would have lost the readibality. But the implementation of template for
    Union and Struct with new and need to be used.
    
    
For all the versions a template function called "test" is used to test code 
it takes the "type" and the "permission" and a "bit_number" to test the bit operations 
and it prints the output a file called "output.txt" to see the result of the test.
