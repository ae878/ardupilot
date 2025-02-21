# The ardupilot adapter

### Usage

1. Clone the repository
```
git clone https://github.com/stacksmash-vuln/ardupilot --recurse-submodules
```

2. Build one, this makes the `build_commands.json` file
```
./waf configure --board r9pilot -g --check-verbose --disable-Werror --toolchain=arm-none-eabi --notests --enable-scripting --enable-opendroneid --enable-check-firmware --enable-custom-controller --enable-gps-logging --enable-header-checks --enable-stats 

./waf -v rover
```

3. Replace the `build_commands.json` file in the `ardupilot` directory with the one in this repository.