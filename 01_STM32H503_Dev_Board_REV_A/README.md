
# Executive Summary

I have been using a NUCLEO64-F446RE as my daily go to. It was reliable and easy to program, but I hated the need for a breadboard to use an OLED or other accessories. It also only had a USB VCOM port and I wanted more USB functionality and storage.

So, I came up with the idea to create my own board with common peripherals already broken out onto headers with the pins arranged and grouped in an intuitive fashion along with clear labelling. The board would cut down on time spent building the circuit and allow me to get to firmware faster and eventually a working device.

My first revision of this board actually used an STM32C5A microcontroller chip along with OctoSPI PSRAM. The only problem with this board was that I couldn’t get it assembled as those parts were very recent and not in stock at JLCPCB. I then rethought the BOM and chose the STM32H503CB6T6 48-LQFP as it was also an M33-core (I wanted to try a new CPU) and had most of the same peripherals allowing me to hit the same requirements for slightly cheaper.

I also streamlined the storage and choose single SPI for two flash chips as they are easier to route and are capped by the 12 Mbps of USB-FS anyways. Routing a full Quad-SPI or OctoSPI bus, while cool, would be a waste of engineering hours for zero ROI.

Despite some DFM hiccups, I was able to get the board build and assembled and am currently going through the bring up and firmware writing phase. And let me say, this phase has taught me a lot more about electronics and hardware than actually designing the board in Altium and has left me with a lot of learnings and a laundry list of changes for REV B which I am currently working through.
