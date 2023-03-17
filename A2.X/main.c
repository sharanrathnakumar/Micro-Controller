/*
 * File:   main.c
 * Author: sharan
 *
 * Created on 6 March, 2023, 11:30 PM
 */


#include "main.h"
#pragma config WDTE = OFF


void main(void) {
    init_config();
    unsigned long int flag = 0;
    unsigned long int count = 0;
    unsigned long int counter = 0;
    unsigned long int edge = 1;
    unsigned long int clk = 1;
    while(1)
    {
        /* When switch is on*/
        if(RB0 == 0 && edge)
        {
            if(counter == 0)
            {
                clk = 2;
                counter++;
            }
            else
            {
                clk = 1;
                counter--;
            }
            edge = 0;
        }
        
        /* When switch is off*/
        else if(RB0 == 1)                                                       
        {
            edge = 1;
        }
        
        if(clk == 1)
        {
            if(((count <= 7)) && (flag++ == 20000))               //top to bottom
            {
                if(PORTD == 0)
                {
                    PORTD = 0x01;
                    flag = 0;
                    count++;
                }
                else
                {
                    PORTD = PORTD | (PORTD << 1);
                    flag = 0;
                    count++;
                }
            }
            else if(((count > 7) && (count <= 15)) && (flag++ == 20000))
            {
                PORTD = PORTD << 1;
                flag = 0;
                count++;
            }
            else if((count == 16) && (flag++ == 10000))
            {
                count = 0;
                flag = 0;
            }
        }
        else if(clk == 2)
        {
            if(((count <= 7)) && (flag++ == 20000))               //bottom to top
            {
                if(PORTD == 0)
                {
                    PORTD = 0x80;
                    flag = 0;
                    count++;
                }
                else
                {
                    PORTD = PORTD | (PORTD >> 1);
                    flag = 0;
                    count++;
                }
            }
            else if(((count > 7) && (count <= 15)) && (flag++ == 20000))
            {
                PORTD = PORTD >> 1;
                flag = 0;
                count++;
            }
            else if((count == 16) && (flag++ == 10000))
            {
                count = 0;
                flag = 0;
            }
        }
    }
}
