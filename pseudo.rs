#![no_std]
#![no_main]

use panic_halt as _;

use arduino_hal::{
    hal::port::{PC0, PD2, PD3, PD4, PD5, PD6, PD7, PB0, PB1, PB2, PB3, PB4, PB5},
    port::{mode::Output, Pin},
};

#[arduino_hal::entry]
fn main() -> ! {
    let dp = arduino_hal::Peripherals::take().unwrap();
    let pins = arduino_hal::pins!(dp);

    //Neck buttons
    let orange = pins.d6;
    let blue = pins.d5;
    let yellow = pins.d4;
    let red = pins.d3;
    let green = pins.d2;

    //strum bar, dpad, menu buttons
    let menu = pins.d13;
    let up = pins.d12;
    let dn = pins.d11;
    let lr = pins.d10;
    let dr = pins.d9;
    let start = pins.d8;
    let select = pins.d7;

    //whammy
    let mut adc = atmega_hal::Adc::new(dp.ADC, Default::default());
    let a0 = pins.pc0.into_analog_input(&mut adc);
    

    arduino_hal::delay_ms(1000);

    loop {
        //TODO: Write code ;)
    }
}