/*
    Auteur :
        * Max Bleriot Mba Fossi - 2417938
        * Roosevelt Sonfack Ngoune - 2464064
    Date : 03/18/2026
*/

#pragma once
#include <string>

namespace constantes {
    // Couleurs ANSI (Codes de formatage console)   
    inline constexpr int BLEU = 94;
    inline constexpr int ROUGE = 91;
    inline constexpr int CYAN = 96;
    inline constexpr int MAGENTA = 95;
    inline constexpr int WHITE = 0;

    // Chaînes de caractères répétitives
    inline const std::string ligneSeparation = "\n\033[92m"
        "════════════════════════════════════════════════════════════════════"
        "\033[0m\n";

    inline const std::string traitSimple =
        "---------------------------------------------------------------------";  
}