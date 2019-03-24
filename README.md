# googleTest

Для компиляции нужен ninja-build 
"sudo apt-get install ninja-build" 
./compile.sh

#Для запуска тестов
ninja test
1. test0 OK
2. test1 Fail

# Статический анализ
# sudo apt install clang-tools-6.0
/usr/bin/scan-build-6.0 cmake -DCMAKE_CXX_STANDARD=14 -DCMAKE_CXX_COMPILER=clang++-6.0 .
/usr/bin/scan-build-6.0 ninja
