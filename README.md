# Lair of Xyrallion
### An open source, single player, D&D based roguelike written in C++.

---
[![Build Status](https://travis-ci.org/MrDetonia/LairOfXyrallion.svg?branch=master)](https://travis-ci.org/MrDetonia/LairOfXyrallion)

**Current Version:** 0.2.0.0

---

## The Setting
The kingdom of Aarim is a peaceful one. It is a kingdom ruled by the grand Empress Tir'Alerwyn, who has sat upon the Marble Throne for 173 cycles of the sun.  
But a shadow has been cast over the land, and dark forces gather and grow, quietly out of sight. For the great and terrible Dragon 'Xyrallion' has awoken from his ancient slumber in the caverns below Aarim, and seeks to destroy the mortal races that have chosen to dwell in his kingdom during his absence.  
Now, Empress Tir'Alerwyn calls for a champion; one who shall rise against the coming darkness; one who will delve into the Lair of Xyrallion, and silence the beast for good.

## Controls
4/h - Move left  
6/l - Move right  
8/k - Move up  
2/j - Move down  
\>  - Stair down  
<   - Stair up  
q   - Quit

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
