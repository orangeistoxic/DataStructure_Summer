#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    int N;
    int type, x;
    while (cin >> N)
    {
        bool isQueue = true, isStack = true, isPriorityQueue = true;
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        while (N--)
        {
            cin >> type >> x;

            if (type == 1)
            {
                q.push(x);
                s.push(x);
                pq.push(x);
            }
            else //type == 2
            {
                if(isQueue){
                    if(q.empty() || q.front() != x){
                        isQueue = false;
                        
                    }
                    else{
                        q.pop();
                    }
                }
                if(isStack){
                    if(s.empty() || s.top() != x){
                        isStack = false;
                    }
                    else{
                        s.pop();
                    }
                }
                if(isPriorityQueue){
                    if(pq.empty() || pq.top() != x){
                        isPriorityQueue = false;
                    }
                    else{
                        pq.pop();
                    }
                }
            }
            
        }
        if (!isQueue && !isStack && !isPriorityQueue)
        {
            cout << "impossible" << endl;
        }
        else if (isQueue && !isStack && !isPriorityQueue)
        {
            cout << "queue" << endl;
        }
        else if (!isQueue && isStack && !isPriorityQueue)
        {
            cout << "stack" << endl;
        }
        else if (!isQueue && !isStack && isPriorityQueue)
        {
            cout << "priority queue" << endl;
        }
        else
        {
            cout << "not sure" << endl;
        }
    }
}