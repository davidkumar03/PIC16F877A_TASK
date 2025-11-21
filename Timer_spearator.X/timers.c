#include <xc.h>

void init_timer0(void)
{
    /* Setting the internal clock source */
    T0CS = 0;
    
    /* Assinging the prescaler to Watchdog Timer */
    PSA = 1;

    TMR0 = 6;
    
    /* The timer interrupt is enabled */
    TMR0IE = 1;
    
    /* Enable all the Global Interrupts */
    GIE = 1;
}
void init_timer1(void)
{
    T1CON=0;
    /*Timer 1 Turn on*/
    TMR1ON = 1;
    
    TMR1 = 3036;
    
    TMR1IE = 1;
    
    PEIE = 1;
    
    GIE=1;
}
void init_timer2(void)
{
    /* Selecting the scale as 1:1 */
    T2CKPS0 = 0;
    T2CKPS1 = 0;
    
    TMR2 = 0;
    /* Loading the Pre Load register with 250 */
    PR2 = 250;
    
    /* The timer interrupt is enabled */
    TMR2IE = 1;
       
    /* Switching on the Timer2 */
    TMR2ON = 1;
    
     /* Peripheral Interrupt Enable Bit (For Timer2) */
    PEIE = 1;
    
    GIE=1;
}