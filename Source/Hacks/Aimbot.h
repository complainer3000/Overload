#pragma once

#include <Config.h>
#include "../Memory.h"

namespace csgo
{
    struct UserCmd;
    struct Vector;
}

class ClientInterfaces;
class EngineInterfaces;

class Aimbot {
public:
    static csgo::Vector calculateRelativeAngle(csgo::Vector& source, csgo::Vector& destination, const csgo::Vector& viewAngles) noexcept;
    void run(Misc& misc, const EngineInterfaces& engineInterfaces, const ClientInterfaces& clientInterfaces, const OtherInterfaces& interfaces, const Config& config, const Memory& memory, csgo::UserCmd*) noexcept;

    void updateInput() noexcept;
};
