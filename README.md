# STM8L151

### Setup:

#### Install [SDCC compiller](http://sdcc.sourceforge.net/snap.php#Linux)
---

#### Install [stm8flash](https://github.com/vdudouyt/stm8flash)
---


#### Prepare SPL
---

1. Go to [st.com](https://st.com)
2. Search for STM8 SPL and download it
3. Dowload [patch](https://github.com/gicking/STM8-SPL_SDCC_patch)
4. Extract SPL, add patch and script and run it

#### Install toolchain
---

At least something is easy on Ubuntu ;)

1. Add repository: `sudo add-apt-repository ppa:team-gcc-arm-embedded/ppa`
2. Install: `sudo apt-get update && sudo apt-get install gcc-arm-embedded`

## Preparing code
---

1. Clone repository
2. Copy patched SPL into it
3. `make`
4. `flash`
