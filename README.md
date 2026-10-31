# LeviModeControl

Starter scaffold for a LeviLauncher Android native mod.

**This is not yet a working game-mode switcher.** The public Preloader SDK supports native mod lifecycle and menu/input APIs, but this scaffold does not implement a verified Bedrock game-mode operation. It intentionally does not claim to preserve achievements when changing game modes.

## Target
- LeviLauncher Android
- arm64-v8a
- Requested Minecraft version: 1.26.60.4 (must be tested)

## Build
The project follows the public LeviLauncher Android template and pins Preloader Android SDK 0.2.2. GitHub Actions builds `.levipack` artifacts.

See the official [Native Mod Quick Start](https://docs.levimc.org/LeviLaunchroid/guide/build) and [upstream template](https://github.com/QYCottage/levilauncher-android-mod-template).

## Status
- [x] Native mod project structure
- [x] Preloader SDK dependency
- [x] GitHub Actions workflow
- [ ] Verify CI build
- [ ] Verify supported game-mode API
- [ ] Test on Minecraft 1.26.60.4
