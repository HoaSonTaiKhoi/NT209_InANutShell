#!/bin/sh
echo -n "Nhập tên: "
read name
echo -n "Nhập mã số sinh viên: "
read mssv

if [ "$mssv" = '22520481' ] && [ "$name" = 'Vo Nhat Hoang' ];
then
	echo "Nhập đúng rồi $name"
	exit 1
else
	echo "Sai mã số sinh viên rồi $name"
	exit 0
fi

exit 0
