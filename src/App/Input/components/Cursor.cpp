#include "Cursor.h"

#include "Convert.h"
#include "EventDispatcher.h"
#include "EventId.h"
#include "raylibEx.h"
#include <raylib.h>

namespace CursorModule
{
    Cursor const& toggle( Cursor& cursor )
    {
        cursor.isActive = !cursor.isActive;

#if !defined( EMSCRIPTEN )
        ( cursor.isActive )
            ? HideCursor()
            : ShowCursor();
#endif

        return cursor;
    }

    Cursor const& update(
        Cursor& cursor,
        Camera2D const& camera,
        Vector2I const& heroPosition
    )
    {
        //* Keep cursor on hero if inactive
        if ( !cursor.isActive )
        {
            cursor.position = Convert::tileToWorld( heroPosition );

            return cursor;
        }

        //* Update cursor position if active
        Vector2I mouseTile{ Convert::screenToTile( GetMousePosition(), camera ) };

        if ( !( Convert::worldToTile( cursor.position ) == mouseTile ) )
        {
            cursor.position = Convert::tileToWorld( mouseTile );

            snx::EventDispatcher::notify( EventId::CURSOR_POSITION_CHANGED );
        }

        return cursor;
    }
}
