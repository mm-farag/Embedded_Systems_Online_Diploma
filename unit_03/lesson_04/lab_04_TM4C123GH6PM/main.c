/**
*Eng. Mohamed Mustafa Farag
*Tiva C TM4C123
*
*/

#define  SYSCTL_RCGC2_R     *((volatile unsigned long *)0x400FE108)
#define  GPIO_PORTF_DIR_R   *((volatile unsigned long *)0x40025400)
#define  GPIO_PORTF_DEN_R   *((volatile unsigned long *)0x4002551C)
#define  GPIO_PORTF_DATA_R  *((volatile unsigned long *)0x400253FC)


int main(void)
{
  volatile unsigned long i;
  volatile unsigned long delay_Count;
  SYSCTL_RCGC2_R = 0x22; // enabling the GPIO and enabling the clock for gpiof
  for(delay_Count = 0; delay_Count < 200; delay_Count++); // just delay after the GPIO enable
  GPIO_PORTF_DIR_R |= 1<<3;
  GPIO_PORTF_DEN_R |= 1<<3;
GPIO_PORTF_DATA_R = 0;
  while (1)
  {
    GPIO_PORTF_DATA_R |= 1<<3;
    for(i = 0; i < (500000); i++ );
    GPIO_PORTF_DATA_R &= ~(1<<3);
    for(i = 0; i < (500000); i++ );
  }
  return 0;
}
