/*****************************************************************************

      DoubleBuffer.h
      Copyright (c) 2020 Raphael DINGE

*Tab=3***********************************************************************/



#pragma once



/*\\\ INCLUDE FILES \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

#include "erb/Buffer.h"



namespace erb
{



class DoubleBuffer
{

/*\\\ PUBLIC \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

public:
                  DoubleBuffer () = default;
                  DoubleBuffer (DoubleBuffer && rhs) = default;
   virtual        ~DoubleBuffer () = default;

   inline         operator Buffer & ();
   inline         operator const Buffer & () const;
   inline DoubleBuffer &
                  operator = (const Buffer & buffer);

   inline size_t  size () const;
   inline float & operator [] (size_t index);
   inline const float &
                  operator [] (size_t index) const;
   inline void    fill (float val);

   inline size_t  tell () const;
   inline void    push (float spl);
   inline float   pull ();



/*\\\ PROTECTED \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

protected:



/*\\\ PRIVATE \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
   inline void    swap ();

   std::array <Buffer, 2>
                  _buffers = {};
   size_t         _cur_buf = 0;
   size_t         _cur_index = 0;



/*\\\ FORBIDDEN MEMBER FUNCTIONS \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

private:
                  DoubleBuffer (const DoubleBuffer & rhs) = delete;
   DoubleBuffer & operator = (const DoubleBuffer & rhs) = delete;
   DoubleBuffer & operator = (DoubleBuffer && rhs) = delete;
   bool           operator == (const DoubleBuffer & rhs) const = delete;
   bool           operator != (const DoubleBuffer & rhs) const = delete;



}; // class DoubleBuffer



}  // namespace erb



#include "erb/detail/DoubleBuffer.hpp"



/*\\\ EOF \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
