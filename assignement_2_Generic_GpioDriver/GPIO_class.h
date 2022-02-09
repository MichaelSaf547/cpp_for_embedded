#ifndef GPIO_CLASS_H_INCLUDED
#define GPIO_CLASS_H_INCLUDED

#include <iostream>

typedef unsigned char uint8;
using std::string;

class GPIO
{
	public:
		virtual void Port_Confg(string port_name, uint8 config_value) = 0;
		virtual void Pin_Config(string port_name, uint8 config_value) = 0;
		virtual uint8 Read_Input_Port(string port_name) = 0;
		virtual uint8 Read_Input_Pin(string port_name, uint8 pin_number) = 0;
		virtual void write_Output_Port(string port_name, uint8 value) = 0;
		virtual void write_Output_Pin(string port_name, uint8 value) = 0;
};

#endif // GPIO_CLASS_H_INCLUDED