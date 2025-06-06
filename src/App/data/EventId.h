#ifndef IG20240315181752
#define IG20240315181752

#include <string>
#include <unordered_map>

enum class EventId
{
    NONE = 0,
    CHANGE_COLOR_THEME,
    CURSOR_POSITION_CHANGED,
    GAME_OVER,
    HERO_MOVED,
    HERO_POSITION_CHANGED,
    INTERRUPT_MOVEMENT,
    LEVEL_UP,
    LEVELED_UP,
    MAP_CHANGE,
    MULTIFRAME_ACTIONS_DONE,
    NEXT_LEVEL,
    NEXT_TURN,
    NPC_ACTION,
    PREVIOUS_LEVEL,
    WINDOW_RESIZED,
};

inline std::unordered_map<EventId, std::string> const eventIdToName{
    { EventId::NONE, "None" },
    { EventId::CHANGE_COLOR_THEME, "Change color theme" },
    { EventId::CURSOR_POSITION_CHANGED, "Cursor position changed" },
    { EventId::GAME_OVER, "Game over" },
    { EventId::HERO_MOVED, "Hero moved" },
    { EventId::HERO_POSITION_CHANGED, "Hero position changed" },
    { EventId::INTERRUPT_MOVEMENT, "Interrupt movement" },
    { EventId::LEVEL_UP, "Level up" },
    { EventId::LEVELED_UP, "Leveled up" },
    { EventId::MAP_CHANGE, "Map change" },
    { EventId::MULTIFRAME_ACTIONS_DONE, "Multiframe action done" },
    { EventId::NEXT_LEVEL, "Next level" },
    { EventId::NEXT_TURN, "Next turn, take hero action" },
    { EventId::NPC_ACTION, "Take enemy action" },
    { EventId::PREVIOUS_LEVEL, "Previous level" },
    { EventId::WINDOW_RESIZED, "Window resized" },
};

#endif
