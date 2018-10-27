
lsmod
insmod xxx.ko		装载
rmmod xxx			卸载
或者：（自动解决依赖关系）
mkdir /lib/modules/`uname -r`/extra/ -p
cp /mnt/nfs/module_test*.ko /lib/modules/`uname -r`/extra/
depmod 建立依赖关系
modprobe module_test1.ko	装载
modprobe -r module_test1.ko	卸载
