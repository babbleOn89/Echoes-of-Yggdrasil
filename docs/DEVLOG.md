
# Echo's of Yggdrasil - DEVELOPMENT LOG

# Project Goal

A 2D fantasy rpg

---



# DATE: 
* 2026-05-23

# Session Length

Not Recorded

# Goals For Session

* Incorporate attack/battle system
* Add battle timer
* Create dialogue prototype

# Completed

* Added attack selection system
* Added battle timer
* Added dialogue prototype
* Established basic combat flow

# Problems Encountered

* No major issues encountered

# Solutions / Discoveries

* Confirmed combat loop structure is viable
* Established foundation for future combat systems

# Ideas For Later

* Better dialogue scripting
* Mana/AP system
* Health system

# Commands / Build Notes

```bash
clear && g++ *.cpp -o StupidWizards -lraylib
```

# Files Modified

* game.cpp
* game.hpp
* hero.cpp
* enemy.cpp

# End Session Notes

Combat framework is functional and ready for expansion.

END SESSION

# DATE: 
* 2026-05-28

# Session Length

~4 Hours

# Goals For Session

* Update character sprites
* Fit hero and enemy artwork into the battle window
* Improve battle screen presentation
* Flesh out story concepts

# Completed

* Replaced hero sprite artwork
* Added multiple enemy sprite variants
* Adjusted sprite scaling for battle scenes
* Improved visual consistency between hero and enemy characters
* Created outline for story direction
* Improved overall battle screen presentation

# Problems Encountered

* Enemy PNG files used different dimensions than hero sprites
* Characters appeared to stand at different heights despite similar scales
* Sprite positioning looked inconsistent between enemies

# Solutions / Discoveries

* Implemented enemy foot-offset positioning
* Learned that transparent padding affects sprite alignment
* Discovered that visual grounding is often solved with per-character offsets
* Kept the narrow battle-screen layout instead of redesigning the window

# Ideas For Later

* Rename spells
* Create Health system
* Create AP/Mana system
* Add combat animations
* Add damage calculations
* Expand story dialogue

# Commands / Build Notes

```bash
clear && g++ *.cpp -o StupidWizards -lraylib
```

# Files Modified

* enemy.cpp
* enemy.hpp
* Updated enemy sprite assets
* Updated hero sprite assets

# End Session Notes

Battle scenes now look significantly more cohesive. Character positioning and sprite presentation are beginning to resemble a real game rather than a prototype.

END SESSION

---

## RESTRUCTRUING OCCURS HERE!

# DATE: 
* 2026-06-01

# Session Length

~3 hours

# Goals For Session
* implement character movement for intro
* implement dialogue
* transition to title/character select

# Completed
* All of it because technically I started doing this yesterday and suck at keeping up with this.

# Problems Encountered


# Solutions / Discoveries

# Ideas For Later
* clean up dialogue box
* create a delay before title screen

# Commands / Build Notes
* the usual

# Files Modified
game.cpp, game.hpp

# End Session Notes
* I need to change the prototype artwork.
END SESSION

# DATE: 2026-06-02

# Session Length 
* 4.5 hours

# Goals For Session
* Transition from Character select to Tutorial
* Maintain the selected character
* implement that movement though

# Completed
* D) All of the above

# Problems Encountered
* I wrote Handle_Input in my .cpp and HandleInput everywhere else...

# Solutions / Discoveries
* Found the bugger and corrected it.

# Ideas For Later
* Actual farmhouse background
* Animals
* dialogue
* inventory

# Commands / Build Notes

# Files Modified
* game.cpp, game.hpp, main.cpp

# End Session Notes
* probably focus more on the inventory system next session and getting items picked up.
* Change the title from "Shadows" to "Echo's" because I'm dumb and forgot my own title...

END SESSION

# DATE:
* 2026-06-03

# Goals For Session
* implement prototype of farm map
* clean up the code so it isn't so cluttered
* some character sprite redesigns

# Problems Encountered
* I couldn't get the camera to move nor could I get the camera to move with the player.

# Solutions / Discoveries
* class for camera update with it locked to the player position.

# Ideas For Later
* inventory system
* dialogue for the tutorial system
* some sprites of chickens

# Commands / Build Notes
to compile
```
g++ src/*.cpp -o echoes -lraylib
```

to run:
```
 ./echoes
```

# Files Modified
* game.cpp
* game.hpp
* player.hpp
* player.cpp
* farmstead.hpp
* farmstead.cpp
* main.cpp

# End Session Notes

END SESSION

# DATE:
* 2026-06-04

# Goals For Session
* refactor everything and get the bluprint for other features setup
* implement tutorial dialogue
* implement basic control prototype
* implement inventory prototype
* implement basic item prototype

# Problems Encountered
* All the problems. Like, literally. Typos, duplicate functions, missing lines. This was a much more daunting task than I originally had planned lol.

# Solutions / Discoveries
* just make the file from the start. don't "i'll just see if I get it to work" a bunch of features that you eventually have to move.

# Ideas For Later
* clean up the inventory layout so it loads the item image
* SPACEBAR for attack.
* Up arrow for spell "feed chickum" (in this case)
# Commands / Build Notes
to compile
```
g++ src/*.cpp -o echoes -lraylib
```

to run:
```
 ./echoes
```

# Files Modified
* All of them and then some.

# End Session Notes

END SESSION
