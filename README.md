# Lair of Xyrallion [![Build Status](https://travis-ci.org/MrDetonia/LairOfXyrallion.svg?branch=master)](https://travis-ci.org/MrDetonia/LairOfXyrallion)
### An open source, single player, D&D based roguelike written in C++.

---

**Warning: Lair of Xyrallion is currently in a pre-alpha state, and will be largely unfinished and at times completely broken. As such, versioning and a formal changelog will only be introduced when the game reaches a state that can be described as 'playable' i.e. most core features are complete.**

---

## The Game
Lair of Xyrallion is a fantasy roguelike RPG set in the fictional world of Aarim. The player must delve to the bottom of a series of ancient caverns in order to destroy the dragon Xyrallion, who threatens to destroy the land.

The game is based around the D&D 3.5e ruleset, and includes standard races, creatures, and classes. The game mechanics also utilise the D&D dice system.

## Building
### Requirements
To build the game, you will require a curses library. If you are unsure as to where to get one; Linux users should try [ncurses](https://www.gnu.org/software/ncurses/), wheras Windows users should instead try [PDCurses](http://pdcurses.sourceforge.net/).

Other than that, you will require a c++11 compatible c++ compiler, and a version of GNU Make. Linux users can obtain these from their package maintainer, and I recommend [MinGW](http://www.mingw.org/) for Windows users.

### Build Process
After checking the Makefile matches your system, simply run 'make' to build the binary executable in the bin directory.

## License
Copyright 2015 Zac Herd

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License
You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

A full copy of the Apache License, Version 2.0 is in LICENSE.md.
