# UI for service

## Developement

- Ubuntu
    
        sudo apt-get install build-essential libtcmalloc-minimal4 && sudo ln -s /usr/lib/libtcmalloc_minimal.so.4 /usr/lib/libtcmalloc_minimal.so 

- Mac    

        brew install boost google-perftools

## Build and run

    g++ -o app.out -O3 -std=c++14 main.cpp -lboost_thread-mt -lboost_system-mt -pthread  

    ./app.out  