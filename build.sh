if [ -f "tqm" ];then
    rm -f tqm
fi
echo "正在编译(如果是手机终端这样的设备，编译可能较慢，请耐心等待)......"
make
echo "编译完成，生成的程序与本脚本在同一目录下!"