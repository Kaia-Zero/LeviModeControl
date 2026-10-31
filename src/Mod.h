#pragma once
#include <pl/Mod.hpp>

class LeviModeControl {
public:
    static LeviModeControl& instance();
    LeviModeControl();
    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }
    bool load();
    bool enable();
    bool disable();
    bool unload();
private:
    ll::mod::NativeMod& mSelf;
};
