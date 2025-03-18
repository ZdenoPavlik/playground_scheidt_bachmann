# Playground


# Tools to install
Installing elementary tools and libraries
```
sudo apt install gcc make perl bzip2 tar build-essential gedit notepadqq htop tldr googletest google-mock libgtest-dev libgmock-dev git meld gh gitk libboost-all-dev valgrind
sudo snap install code --classic
```

Building gtest & gmock libraries
```
cd /usr/src/gtest
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib
cd ../gmock
sudo cmake .
sudo make
sudo cp lib/*.a /usr/lib
```

