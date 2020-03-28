//
//  quad.cpp
//  RL
//
//  Created by Gautam Sharma on 3/25/20.
//  Copyright © 2020 Gautam Sharma. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
#include <map>
#include <array>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdio.h>


int SIZE = 10;
int EPISODES = 800;
int MOVE_PENALTY = 1;
int ENEMY_PENALTY = 300;
int FOOD_REWARD = 250;
int GOAL_X = 5;
int GOAL_Y = 5;
float EPSILON = 0.9;
float EPS_DECAY = 0.9998;

class Quad{
public:
    int x;
    int y;
    int z;
    Quad(){
        this->x = rand()% 10 + 1;
        this->y = rand()% 10 + 1;
        this->z = rand()% 10 + 1;
    }
    void action(int choice){
        if (choice == 0){
            this->move( x=1,  y=0,  z=0);
        }
        else if(choice ==1){
            this->move(x=-1,y=0,z=0);
        }
        else if(choice ==2){
            this->move(x=0,y=1,z=0);
        }
        else if(choice ==3){
            this->move(x=0,y=-1,z=0);
        }
        else if(choice ==4){
            this->move(x=0,y=0,z=1);
        }
        else if(choice ==5){
            this->move(x=0,y=0,z=-1); //Looks good
        }
    }
    void print(){
        
        cout<<this->x<<this->y<<this->z<<endl;
    }
    
    
    
    void move(int x = 0,int y=0,int z=0){
        if (x==0){
            this->x+= -1 + (rand() % ( 4 ) );
            
        }
        else{
            this->x +=x;
        }
        if (y==0){
            this->y+= -1 + (rand() % ( 4 ) );
            
        }
        else{
            this->y +=y;
        }
        if (x==z){
            this->z+= -1 + (rand() % ( 4 ) );
            
        }
        else{
            this->z +=z;
        }
        if (this->x<0){
            this->x=0;}
        else if(this->x>(SIZE-1)){
            this->x = SIZE-1; //Looks good
        }
        if (this->y<0){
            this->y=0;}
        else if(this->y>(SIZE-1)){
            this->y = SIZE-1;
        }
        if (this->z<0){
            this->z=0;}
        else if(this->z>(SIZE-1)){
            this->z = SIZE-1;
        }
    }
};


map<array<int, 3>, array<int, 6>> q_table;

void qtable(){
    for (int i =-SIZE; i<SIZE; i++){
        for (int j =-SIZE; j<SIZE; j++){
            for (int k =-SIZE; k<SIZE; k++){
                //vector<coord>myvec;
                //myvec.push_back({i,j,k});

//                array<int, 3> a {{i,j,k}};
                
                q_table[{i,j,k}][0] = (rand() % 5)+1;
                q_table[{i,j,k}][1] =  (rand() % 5)+1;
                q_table[{i,j,k}][2] =  (rand() % 5)+1;
                q_table[{i,j,k}][3] =  (rand() % 5)+1;
                q_table[{i,j,k}][4] =  (rand() % 5)+1;
                q_table[{i,j,k}][5] =  (rand() % 5)+1; //Looks Good
                
                
            }
        }
    }
}

Quad foo;
Quad *food = &foo;


int main(){
    food -> x = 4;
    

    srand((int) time(0));
    Quad Q;
    //Q.print();
    qtable();
    cout<<"First value is "<< q_table[{1,5,8}][0]<< " "<< q_table[{1,2,3}][2]<< " "<<q_table[{5,5,5}][3]<<q_table[{0,0,0}][4]<<q_table[{-1,0,0}][5]<< endl;
    for (int i =0; i<EPISODES ; i++){
        Quad player;
        int episode_reward = 0;
        for (auto j=0;j<200;j++){
            
        }
    }
    
}
