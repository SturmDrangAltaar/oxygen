#ifndef oxygendockseparatorengine_h
#define oxygendockseparatorengine_h

//////////////////////////////////////////////////////////////////////////////
// oxygendockseparatorengine.h
// stores event filters and maps widgets to timelines for animations
// -------------------
//
// Copyright (c) 2009 Hugo Pereira Da Costa <hugo.pereira@free.fr>
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

#include "oxygenbaseengine.h"
#include "oxygendatamap.h"
#include "oxygendockseparatordata.h"

namespace Oxygen
{

    //! stores dockseparator hovered action and timeLine
    class DockSeparatorEngine: public BaseEngine
    {

        Q_OBJECT

        public:

        //! constructor
        explicit DockSeparatorEngine( QObject* parent ):
            BaseEngine( parent )
        {}

        //! destructor
        virtual ~DockSeparatorEngine( void )
        {}

        //! register dockseparator
        virtual bool registerWidget( QWidget* );

        //! update rect and hover value for data matching widget
        virtual void updateRect( const QObject* object, const QRect& r, const Qt::Orientation orientation, bool hovered )
        {
            if( DataMap<DockSeparatorData>::Value data = _data.find( object ) )
            { data.data()->updateRect( r, orientation, hovered ); }
        }

        //! returns true if object is animated
        virtual bool isAnimated( const QObject* object, const QRect& r, const Qt::Orientation orientation )
        {
            if( DataMap<DockSeparatorData>::Value data = _data.find( object ) )
            {
                return data.data()->isAnimated( r, orientation );
            } else return false;

        }

        //! returns true if object is animated
        virtual qreal opacity( const QObject* object, const Qt::Orientation orientation )
        {
            if( DataMap<DockSeparatorData>::Value data = _data.find( object ) )
            {
                return data.data()->opacity( orientation );
            } else return AnimationData::OpacityInvalid;
        }

        //! enability
        void setEnabled( bool value )
        {
            BaseEngine::setEnabled( value );
            _data.setEnabled( value );
        }

        //! duration
        void setDuration( int value )
        {
            BaseEngine::setDuration( value );
            _data.setDuration( value );
        }

        public Q_SLOTS:

        //! remove widget from map
        bool unregisterWidget( QObject* object )
        { return _data.unregisterWidget( object ); }

        private:

        //! data map
        DataMap<DockSeparatorData> _data;

    };

}

#endif
