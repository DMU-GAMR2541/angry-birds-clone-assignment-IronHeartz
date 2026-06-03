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

class Multithreading2 {
private:
    std::thread t;
    std::future<bool> f;

public:
    void Working() //Will pause breifly and iterate through
    {
        int i = 0;
        while (i < 3)
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

    Multithreading2() {
        t = std::thread(&Multithreading2::Working, this); //A reference to mulltithreading, in the constructor
        f = std::async(std::launch::async, &Multithreading2::MoreWorking, this); //Launch it immediately
    }                                                    //When you have a constructor, it will call and run this method

    ~Multithreading2() {
        if (t.joinable()) {
            t.join(); //Check if able to join, join with main thread
        }
    }
};


