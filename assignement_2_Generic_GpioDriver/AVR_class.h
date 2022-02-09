#ifndef AVR_CLASS_H_INCLUDED
#define AVR_CLASS_H_INCLUDED

#include "GPIO_class.h"

class AVR : public GPIO
{
	public:
		void Port_Confg(string port_name, uint8 config_value);
		void Pin_Config(string port_name, uint8 config_value);
		uint8 Read_Input_Port(string port_name);
		uint8 Read_Input_Pin(string port_name, uint8 pin_number);
		void write_Output_Port(string port_name, uint8 value);
		void write_Output_Pin(string port_name, uint8 value);
};


#endif // AVR_CLASS_H_INCLUDED