#ifndef oxygenprogressbardata_h
#define oxygenprogressbardata_h

//////////////////////////////////////////////////////////////////////////////
// oxygenprogressbardata.h
// data container for progressbar animations
// -------------------
//
// Copyright (c) 2009 Hugo Pereira Da Costa <hugo@oxygen-icons.org>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//////////////////////////////////////////////////////////////////////////////

#include "oxygenanimationdata.h"
#include "oxygenanimation.h"

#include <QtCore/QObject>
#include <QtCore/QTextStream>
namespace Oxygen
{


    //! generic data
    class ProgressBarData: public AnimationData
    {

        Q_OBJECT

        //! declare progess fraction property
        Q_PROPERTY( qreal ratio READ ratio WRITE setRatio )

        public:

        //! constructor
        ProgressBarData( QObject* parent, QWidget* widget, int duration );

        //! destructor
        virtual ~ProgressBarData( void )
        {}

        //! event filter
        virtual bool eventFilter( QObject*, QEvent* );

        //! return timeLine
        virtual const Animation::Pointer& animation() const
        { return animation_; }

        //! duration
        virtual void setDuration( int duration )
        { animation_.data()->setDuration( duration ); }

        //! progressbar value (during animation)
        virtual int value( void ) const
        { return startValue() + ratio_*( endValue() - startValue() ); }

        //! ratio
        virtual qreal ratio( void ) const
        { return ratio_; }

        //! ratio
        virtual void setRatio( qreal value )
        { ratio_ = value; }

        protected slots:

        //! triggered by progressBar::valueChanged
        void valueChanged( int );

        protected:

        const int& startValue( void ) const
        { return startValue_; }

        void setStartValue( int value )
        { startValue_ = value; }

        const int& endValue( void ) const
        { return endValue_; }

        void setEndValue( int value )
        { endValue_ = value; }

        private:

        //! animation handling
        Animation::Pointer animation_;

        //! opacity variable
        qreal ratio_;

        //! animation starting value
        int startValue_;

        //! animation ending value
        int endValue_;

    };

}

#endif