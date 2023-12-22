// Round Robin Scheduling Algorithm

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using std::cout;
using std::endl;

class Process {
    
    private:
        int id; 
        int arrival_time; 
        int time_needed; 
        int finished_time; 

    public:
        Process() { // Constructor
            finished_time = -1;
        }
  
        Process(int a, int b, int c) { // Argument Constructor
            id = a;
            arrival_time = b;
            time_needed = c;
            finished_time = -1;
        }
    
        void setID(int a) { // Setters
            id = a;
        }

        void setArrivalTime(int a) {
            arrival_time = a;
        }

        void setTimeNeeded(int a) {
            time_needed = a;
        }
  
        void setFinishedTime(int a) {
            finished_time = a;
        }

        int getID() { // Getters
            return(id);
        }

        int getArrivalTime() {
            return(arrival_time);
        }

        int getTimeNeeded() {
            return(time_needed);
        }

        int getFinishedTime() {
            return(finished_time);
        }

};

void finish(Process *p, int s, int id, int t) { // Finished Process and Update Finished Time
    for (int i = 0; i < s; ++i) {
        if (p[i].getID() == id) {
            p[i].setFinishedTime(t);
            break;
        }
    }
}

void print(Process *p, int s) { // Print all Processes
    for(int i=0;i<s;i++) {
        cout << "Process ID : " << p[i].getID();
        cout << " , Arrival Time : " << p[i].getArrivalTime();
        cout << " , Time Needed : " << p[i].getTimeNeeded();
        cout << " , Finished Time : " << p[i].getFinishedTime();
        cout << endl;
    }
}

int main() {
    std::ifstream in("RoundRobin.txt");;
    Process *p = new Process[5]; // Process Objects in Array
    int a, b, c;
  
    for (int i = 0; i < 5; i++) { // Extract Input from file
        in >> a;
        in >> b;
        in >> c;
        p[i].setID(a);
        p[i].setArrivalTime(b);
        p[i].setTimeNeeded(c);      
    }
  
    cout << "Finished taking Input...";
  
    int time_frame=4; // Frame rate = 4

    std::queue <Process> queue; // For the ready process
  
    std::vector<int> vec; // Process IDs for algorithms

    std::vector<int> vect;
  
    int time=0; 
  
  // for checking if either process arrived or not. 0 = Not arrived, 1 = Arrived
  
    int *count = new int[5];
  
    for (int i = 0; i < 5; i++) {
        count[i]=0;
    }

    for (int i = 0; i < 5; i++) { // Initially load ready process in queue
        if(p[i].getArrivalTime() <= time && count[i] == 0) {
            queue.push(p[i]);
            count[i]=1;
        }
    }

    while(!queue.empty())  {// Loop until Quene empty

        Process cur=queue.front(); // get first process from queue

        queue.pop();
      
        if(cur.getTimeNeeded() < 4) {// if execution time of current process is less tha 4
            time += cur.getTimeNeeded();
            finish(p, 5, cur.getID(), time); 
              
            for (int i = 0; i < 5; i++) {
                if(count[i]==0 && p[i].getArrivalTime()<=time) {
                queue.push(p[i]);
                count[i]=1;
                }
            }      

            vec.push_back(cur.getID()); // id
            vect.push_back(cur.getTimeNeeded()); //time   
        }
        else {
            cur.setTimeNeeded(cur.getTimeNeeded() - 4); // set remaining time to execute
            time += 4;
      
            for(int i = 0; i < 5; i++)  { // check all process are arrived or not
      
                if(count[i] == 0 && p[i].getArrivalTime() <= time) {
                queue.push(p[i]);
                count[i]=1;
                }
            }
                 
            if(cur.getTimeNeeded()>0) { // if time remain for next execution , then load in queue   
                queue.push(cur);    
            }
            else {
                finish(p,5,cur.getID(),time);
            }

            vec.push_back(cur.getID()); //id
            vect.push_back(4); //time
      
            }
    }

    time=0; // reset time

    for(int i = 0; i < vec.size(); i++)  { // print process id with time
        cout << endl << "[ Process ID " << vec.at(i) << " ] " << time << "-" << (time+vect.at(i));
        time += vect.at(i);
    }
  
    cout << endl;
    cout << endl;
  
    cout << "Processes are :" <<endl;
    print (p, 5);
  
    return(0);
}