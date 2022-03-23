explosive-c4
============

Connect4 clone

Gameplay
--------

[Youtube video](https://www.youtube.com/watch?v=oBcFPTqldt8)

Install
-------

Available on Debian, otherwise build from sources.


Build
=====

Install the build requirements listed in `debian/control`.
Adapt the package names to whatever they might be on your distribution.



```bash
mkdir build; cd build; qmake ../src; make -j

# To execute
./explosive-c4

# Or you can do
sudo make install

```

