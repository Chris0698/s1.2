#include <mbed.h>
#include <stdbool.h>

//only colors the LED supports
enum LedColours
{
  red,
  blue,
  green
};

//The switches that can be used
enum ButtonsSwitches
{
  rightButton,        //would have value of int =0
  leftButton,
  centerStick
};

//The buttons variables
DigitalIn buttons[]
{
    DigitalIn(PTC6),    // right sw3 button
    DigitalIn(PTA4),    // left sw2 button
    DigitalIn(D4)       //center joystick
};

//LED variables
DigitalOut LED[]
{
  DigitalOut(PTB22, 1),  //red
  DigitalOut(PTB21, 1),  //blue
  DigitalOut(PTE26, 1)   //green
};

bool isPressed(/*DigitalIn button*/ int press)
{
  //returns if the button been pressed.
  return !buttons[press].read();
}

void ledOn(int i)
{
  LED[i].write(0);
}

void ledOff(int i)
{
  LED[i].write(1);
}

int main()
{
   LedColours color = blue;
   ButtonsSwitches butSwitch = rightButton;
   bool flashing = false;

    //printf("button %d\n", leftButton.read() );

    while(true)
    {
      if(isPressed(butSwitch))
      {
        flashing = !flashing;
      }



      if(flashing)
      {
        ledOn(color);
        wait(0.5);
        ledOff(color);
        wait(0.5);
      }
      else
      {
        ledOff(color);
        wait(0.5);
      }
      /*
      flashing = isPressed(btn);

      flashing = isPressed(center);

        if( btn.read() ) flashing = true;
            else         flashing = false;
            */

        //If button not pressed then flashing = true
        //printf("button %d\n", btn.read() );
        /*
        if(flashing)
        {
            red.write(0);
            wait(0.5);
            red.write(1);
            wait(0.5);
        }
        else
        {
            red.write(1);
            wait(1);
        }
        */
    }
}
