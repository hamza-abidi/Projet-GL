#ifndef _CLEARSRC_H_
#define _CLEARSRC_H_
#include <cstdlib>

/// \function clear_screen est une fonction permet de vider le console
void clear_screen()
{
#ifdef WINDOWS
    std::system("cls"); ///\brief si on est est sur windows
#else
    std::system ("clear");///\brief si on est sur un autre systéme d'exploitation
#endif
}
#endif /* end of include guard:  */
