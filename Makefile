obj-y += mach-o/macho.o
obj-y += mach-o/macho_util.o

obj-y += serialize/jsmn.o
obj-y += serialize/xml_plist.o

obj-y += device_tree/device_tree.o
obj-y += device_tree/JS_device_tree_parser.o
obj-y += device_tree/XML_device_tree_parser.o

obj-y += main/memory.o
obj-y += main/loader.o
obj-y += main/mach_boot.o

obj-y += image3/image3.o

obj-y += libkern/strol.o

obj-y += compressed/lzss.o
obj-y += compressed/quicklz.o

ccflags-y := -I$(srctree)/$(src)/include
