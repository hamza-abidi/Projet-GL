#include "../include/ClearSrc.h"

void clear_screen()
{
#ifdef WINDOWS
    std::system("cls"); ///\brief si on est est sur windows
#else
    std::system ("clear");///\brief si on est sur un autre systéme d'exploitation
#endif
}
