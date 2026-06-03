#pragma once
#include "GameObject.h"
#include <set>
#include <vector>
#include <list>
#include <thread>
#include <memory>
#include <chrono>
#include <future>
#include <iostream>

class Multithreading {
public:
    Multithreading() {
        t = std::thread(&Multithreading::Working, 10, this); //A reference to mulltithreading, in the constructor
    }                                                        //When you have a constructor, it will call and run this method

    ~Multithreading() {
        if (t.joinable()) {
            t.join(); //Check if able to join, join with main thread
        }
    }


    void Working(int param) //Will pause breifly and iterate through
    {
        int i = 0;
        while (i < param)
        {
            std::cout << "Processing 1" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(120));
            i++;
        }
    }

    bool MoreWorking()
    {
        int j = 0;
        while (j < 3)
        {
            std::cout << "Processing 2" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(240));
            j++;
        }

        return true;
    }


    //std::future<bool> f = std::async(std::launch::async, MoreWorking); //Launch it immediately

private:
    std::thread t;

};

