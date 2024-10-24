/*
841. Keys and Rooms
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. 
Your goal is to visit all the rooms. 
However, you cannot enter a locked room without having its key.
When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, 
denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.
Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, 
return true if you can visit all the rooms, or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<int>visited;
    void dfs(vector<vector<int>>& rooms , int room){
        if(visited.count(room)) return;
        visited.insert(room);
        for(int i = 0 ; i < rooms[room].size() ; i++){
            dfs(rooms , rooms[room][i]);
        }   
    }

    bool canVisitAllRooms( vector<vector<int>>& rooms) {
        dfs(rooms , 0);
        if(rooms.size() != visited.size()) return false;
        else return true;
    }
};

int main(){

}