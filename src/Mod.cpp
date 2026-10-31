#include "Mod.h"

LeviModeControl& LeviModeControl::instance() {
    static LeviModeControl mod;
    return mod;
}

LeviModeControl::LeviModeControl() : mSelf(*ll::mod::NativeMod::current()) {}

bool LeviModeControl::load() {
    mSelf.getLogger().info("LeviModeControl loaded. Game-mode switching is not implemented.");
    return true;
}
bool LeviModeControl::enable() {
    mSelf.getLogger().info("LeviModeControl enabled.");
    return true;
}
bool LeviModeControl::disable() { return true; }
bool LeviModeControl::unload() { return true; }
