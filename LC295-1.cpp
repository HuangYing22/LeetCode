//LC295
//Median is the middle value in an ordered integer list. 
//If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//Examples: 
//[2,3,4] , the median is 3
//[2,3], the median is (2 + 3) / 2 = 2.5
//Design a data structure that supports the following two operations:
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.

//Time Limit Exceeded
/*
class MedianFinder {
public:
    priority_queue<int> pq;
    
    // Adds a number into the data structure.
    void addNum(int num) {
        pq.push(num);
    }

    // Returns the median of current data stream
    double findMedian() {
        int n = pq.size();
        double res;
        queue<int> temp;
        
        if(n%2 != 0) {
            for(int i=0; i<n/2; i++) {
                temp.push(pq.top());
                pq.pop();
            }
            res = pq.top();
        } else {
            for(int i=0; i<n/2-1; i++) {
                temp.push(pq.top());
                pq.pop();
            }
            res =  (pq.top() + pq.top())/2;
        }
        while(!temp.empty()) {
            pq.push(temp.front());
            temp.pop();
        }
        return res;
    }
};
*/

//Time Limit Exceeded
/*
class MedianFinder {
public:
    priority_queue<int> pq;
    vector<int> v;
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if(pq.empty() || v.empty()) {
            pq.push(num);
            return;
        }
        if(!v.empty()) {
            if((num < v[v.size()-1]) && (num > pq.top())) {
                v.push_back(num);
            } else if(num <= pq.top()) {
                pq.push(num);
            } else if(num >= v[v.size()-1]) {
                v.push_back(num);
                for(int i = 1; i<v.size()-1; i++) {
                    if ((v[i-1] >= num) && (v[i] < num)) {
                        for(int j=v.size()-1; j > i; j--) {
                            v[j] = v[j-1];
                        }
                        v[i] = num;
                    }
                }
            }
        }
        
        return;
    }

    // Returns the median of current data stream
    double findMedian() {
        int npq = pq.size();
        int nv = v.size();
        double res = 0.0;
        
        if(npq == 0) return res;
        
        if(nv == 0) {
            if(npq%2 != 0) {
                for(int i=0; i<npq/2; i++) {
                    v.push_back(pq.top());
                    pq.pop();
                }
                res = pq.top();
            } else {
                for(int i=0; i<npq/2-1; i++) {
                    v.push_back(pq.top());
                    pq.pop();
                }
                res = pq.top();
                v.push_back(pq.top());
                pq.pop();
                res += pq.top();
                res /=2;
            }
            return res;
        }
        
        if(npq = nv) {
            res = (pq.top()+v[nv-1])/2;
            return res;
        }
        
        if(npq > nv) {
            if((npq + nv)%2 != 0) {
                for(int i=0; i<((npq+nv)/2 - nv); i++) {
                    v.push_back(pq.top());
                    pq.pop();
                }
                res = pq.top();
            } else {
                for(int i=0; i<((npq+nv)/2-1-nv); i++) {
                    v.push_back(pq.top());
                    pq.pop();
                }
                res = pq.top();
                v.push_back(pq.top());
                res += pq.top();
                res /= 2;
            }
        } else {
            if((npq+nv)%2 !=0) {
                res = v[(npq+nv)/2];
            } else {
                res = (v[(npq+nv)/2-1] + v[(npq+nv)/2])/2;
            }
        }
        return res;
        
    }
};
*/

class MedianFinder {
public:
    priority_queue<int> heap_max;
    priority_queue<int, vector<int>, greater<int>> heap_min;
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if(heap_max.empty()) {
            heap_max.push(num);
            return;
        }
        if(heap_min.empty()) {
            if(heap_max.top() > num) {
                heap_min.push(heap_max.top());
                heap_max.pop();
                heap_max.push(num);
            } else {
                heap_min.push(num);
            }
            return;
        }
        
        int n1 = heap_max.size();
        int n2 = heap_min.size();
        
        if(n1 == n2) {
            if(num <= heap_min.top() && num >= heap_max.top()) {
                heap_max.push(num);
            } else if(num > heap_min.top()) {
                heap_min.push(num);
            } else if(num < heap_max.top()) {
                heap_max.push(num);
            }
        }
        
        if(n1 - n2 == -1) {
             if(num <= heap_min.top() && num >= heap_max.top()) {
                heap_max.push(num);
            } else if(num > heap_min.top()) {
                heap_max.push(heap_min.top());
                heap_min.pop();
                heap_min.push(num);
            } else if(num < heap_max.top()) {
                heap_max.push(num);
            }
        }
        
        if(n1 - n2 == 1) {
             if(num <= heap_min.top() && num >= heap_max.top()) {
                heap_min.push(num);
            } else if(num > heap_min.top()) {
                heap_min.push(num);
            } else if(num < heap_max.top()) {
                heap_min.push(heap_max.top());
                heap_max.pop();
                heap_max.push(num);
            }
        }
        return;
    }

    // Returns the median of current data stream
    double findMedian() {
        int n1 = heap_max.size();
        int n2 = heap_min.size();
        double res;
        
        switch(n1 - n2) {
            case 0:
                res = ((double)heap_max.top() + (double)heap_min.top())/2;
                break;
            case 1:
                res = heap_max.top();
                break;
            case -1:
                res = heap_min.top();
                break;
        }
        return res;
    }
};
// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
