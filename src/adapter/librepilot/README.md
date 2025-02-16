### Librepilot Adapter

* This adapter is used for fuzzing the librepilot firmware
* You might need Ubuntu 18.04 and [Fork of Librepilot](https://github.com/stacksmash-vuln/LibrePilot)
* The fork version of Librepilot, build flags are changed for this fuzzing system.

### Requirements (Maybe)

```
sudo apt-get install make
sudo apt install qt5-qmake
sudo apt install qtbase5-dev
sudo apt install qt5-default
sudo apt install python2
make arm_sdk_install
```