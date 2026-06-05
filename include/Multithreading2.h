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
#include <mutex>

class Multithreading2 {
private:
    std::thread t;
    std::future<bool> f;
    std::mutex m;
    std::thread s;
    int loadingTimer = 0;
    bool b_assetsReady = true;
    float f_progress = 0;

public:
    sf::Sprite StartSprite;
    sf::Sprite getSprite()
    {
        return StartSprite;
    }
    bool finishedLoading = false;
    void render(sf::RenderWindow& GO_window);

    bool LoadAssets(int timeValue) //Will pause breifly and iterate through
    {
        //std::lock_guard<std::mutex> guard(m);
        for (int i = 0; i < timeValue; i++) {
            std::cout << "Loading assets..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(200));

            std::unique_lock<std::mutex> lock(m);
            f_progress += 1.0f;
            lock.unlock();
            
        }
        b_assetsReady = true;
        return b_assetsReady;
    }

    float getProgress() {
        std::unique_lock<std::mutex> lock(m);
        return f_progress;
    }

    bool MoreWorking()
    {
        int j = 0;
        while (j < 3)
        {
            std::cout << "Processing 2" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            j++;
        }

        return true;
    }

    void StartScreen() {
        int s = 0;
        while (s < 5) 
        {
            std::cout << "Loading game..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(10));

            std::unique_lock<std::mutex> lock(m);
            //f_progress += 0.01f;
            lock.unlock();
            s++;

        }
    }

    Multithreading2() {
        //When you have a constructor, it will call and run this method
        t = std::thread(&Multithreading2::LoadAssets, this, 10); //A reference to mulltithreading, in the constructor
        f = std::async(std::launch::async, &Multithreading2::MoreWorking, this); //Launch it immediately
        s = std::thread(&Multithreading2::StartScreen, this);
    } 


    ~Multithreading2() {
        if (t.joinable()) {
            t.join(); //Check if able to join, join with main thread
        }
    }
};


