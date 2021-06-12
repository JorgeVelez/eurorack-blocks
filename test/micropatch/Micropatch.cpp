/*****************************************************************************

      Micropatch.cpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "Micropatch.h"

#include <cmath>



/*
==============================================================================
Name : process
==============================================================================
*/

void  Micropatch::process ()
{
   bool osc1_gate = ui.osc1_button.held () || ui.osc1_gate;
   float osc1_amp = (ui.osc1_amp + ui.osc1_amp2) * osc1_gate;
   osc1.set_freq_norm (ui.osc1_freq + ui.osc1_freq2);

   float osc2_amp = ui.osc2_amp + ui.osc2_amp2;
   osc2.set_freq_norm (ui.osc2_freq + ui.osc2_freq2);

   for (size_t i = 0 ; i < erb_BUFFER_SIZE ; ++i)
   {
      ui.audio_out1 [i] = ui.audio_in1 [i] + osc1_amp * osc1.process ();

      if (ui.osc2_type.position_first ())
      {
         ui.audio_out2 [i] = ui.audio_in2 [i] + osc2_amp * osc2.process ();
      }
      else if (ui.osc2_type.position_last ())
      {
         ui.audio_out2 [i] = ui.audio_in2 [i] + osc2_amp * (osc2.process () > 0.f ? 1.f : -1.f);
      }
      else
      {
         ui.audio_out2 [i] = ui.audio_in2 [i];
      }
   }

   ui.osc1_state = osc1_gate;
   ui.osc2_state = ui.osc2_gate;
   ui.osc1_lvl = osc1_amp;

   ui.led = ui.pot1;
}
