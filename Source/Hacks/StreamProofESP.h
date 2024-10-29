#pragma once

#include <Config.h>
#include "../Memory.h"

namespace StreamProofESP
{
    void render(const Memory& memory);
    void updateInput() noexcept;

    // GUI
    void menuBarItem() noexcept;
    void tabItem(Config& config) noexcept;
    void drawGUI(bool contentOnly) noexcept;
}
