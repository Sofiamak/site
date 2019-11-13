#docker rmi -f $(docker images -a -q)
#mysql -uroot -ppass
#show databases;
#show tables;
#sudo killall docker-containerd-shim
#sudo  apt-get install libmysqlclient-dev
#find /usr/ -name 'mysql.h' 
#sudo apt  install cmake
<!-- tar -xzf cmake-3.5.0-rc3.tar.gz
cd cmake-3.5.0-rc3/
./configure --prefix=/usr
make -j<cpu_count>
sudo make install -->

sudo apt-get purge --auto-remove apparmor
sudo service docker restart
docker system prune --all --volumes