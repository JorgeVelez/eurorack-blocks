/*****************************************************************************

      BoardKivu12.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/daisy/BoardKivu12.h"



namespace erb
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : ctor
==============================================================================
*/

BoardKivu12::BoardKivu12 ()
{
   uint8_t addr [] = {0x00, 0x02};

   constexpr auto led_i2c_config = daisy::I2CHandle::Config {
      daisy::I2CHandle::Config::Peripheral::I2C_1,
      {
         SubmoduleDaisyPatchSm::B7, // SCL
         SubmoduleDaisyPatchSm::B8  // SDA
      },
      daisy::I2CHandle::Config::Speed::I2C_1MHZ
   };

   using DmaBuffer = decltype (_led_driver)::DmaBuffer;

   static DmaBuffer DMA_BUFFER_MEM_SECTION led_dma_buffer_a;
   static DmaBuffer DMA_BUFFER_MEM_SECTION led_dma_buffer_b;

   daisy::I2CHandle i2c;
   i2c.Init (led_i2c_config);
   _led_driver.Init (
      i2c, addr,
      led_dma_buffer_a, led_dma_buffer_b
   );

   set_b_mux_addr ();
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
