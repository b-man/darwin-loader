# darwin-loader
## A Darwin bootloader module for U-Boot

How to use this module:

 * Clone u-boot source code:

   ```git clone git://git.denx.de/u-boot.git```

 * Place this module at the root of the source tree:

   ```mv darwin-loader u-boot/```

 * Add the following line to ```u-boot/Makefile``` afrer ```libs-y += env/```:

   ```libs-y += darwin-loader/```


 * Go through the normal steps in building u-boot for your platform.


This loader is based on Kristina Brooks's [xnu-uboot-arm32](https://github.com/christinaa/xnu-uboot-arm32) project.
