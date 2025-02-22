/*****************************************************************************

      AudioOut.hpp
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



namespace erb
{



/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*
==============================================================================
Name : ctor
==============================================================================
*/

AudioOut::AudioOut (Buffer & buffer)
:  impl_data (buffer)
{
}



/*
==============================================================================
Name : operator =
==============================================================================
*/

AudioOut &   AudioOut::operator = (const Buffer & buffer)
{
   impl_data = buffer;

   return *this;
}



/*
==============================================================================
Name : operator Buffer &
==============================================================================
*/

AudioOut::operator Buffer & ()
{
   return impl_data;
}



/*
==============================================================================
Name : size
==============================================================================
*/

size_t   AudioOut::size () const
{
   return impl_data.size ();
}



/*
==============================================================================
Name : operator []
==============================================================================
*/

float &  AudioOut::operator [] (size_t index)
{
   return impl_data [index];
}



/*
==============================================================================
Name : fill
==============================================================================
*/

void  AudioOut::fill (float val)
{
   impl_data.fill (val);
}



/*\\\ INTERNAL \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/



}  // namespace erb



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
