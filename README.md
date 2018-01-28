# StatNLP Service in C++

## Developement

- Ubuntu
    
        sudo apt-get install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so 

- Mac    

        brew install boost google-perftools

## Build and run

    mkdir build && cd build  

    cmake ../ && make

    ./app/app.out

## Service with UI

- [UI version](https://github.com/sutd-statnlp/initializer-statnlp-service-cpp/tree/master/ui)  