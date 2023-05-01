/*******************************************************************************
 * This example shows how to use the DPS2 sleep mode which is an LGT8F328P     *
 * specific sleep mode. In DPS2 mode, no need to set up IOs against leakage    *
 * current because all IOs have a weak internal pull-up resistor which         *
 * automatically turned on. Thats why the built-in LED on the MiniEVB board    *
 * will be glow dimly during sleep. Using this mode no RAM or other port state *
 * retention. After wake up the chip will perform a complete power-on reset.   *
 * Wake up sources are: port D pin level change( INT0, INT1, RXD, TXD, etc) or *
 * Low Power RC timer or Reset pin.                                            *
 * Available durations for this low power mode: about 128, 256, 512, 2500 ms   *
 *                                                    and     SLEEP_FOREVER    *
 *******************************************************************************/
 
#include "lgt_LowPower.h"

void setup()
{
    // No setup is required for LowPower library
}

void loop() 
{
    delay(4000);

    // Set which pins should be the wake-up pins
    IOCWK = PORTD2 | PORTD4;

    // Enter deep sleep state for > 2 s
    LowPower.deepSleep2(SLEEP_1S);

    // No code executiion after deepSleep2
}

