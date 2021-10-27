#![no_std]
#![no_main]

#[panic_handler]
fn panic(__info: &core::panic::PanicInfo) {
    loop {}
}
