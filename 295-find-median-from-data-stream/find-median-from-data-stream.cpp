class MedianFinder {
public:
    multiset<int> ms;
    multiset<int>::iterator mid; 

    MedianFinder() {
        mid = ms.end();
    }

    void addNum(int num) {
        int n = ms.size();
        ms.insert(num);

        if (n == 0) {
            mid = ms.begin(); 
        }
        else if (n&1) {
            if (num < *mid) { 
                mid--;
            }
        } 
        else {
            if (num>=*mid) { 
                mid++;
            }
        }
    }

    double findMedian() {
        int n = ms.size();

        if (n % 2 != 0) {
            return *mid;
        }

        auto next_mid = next(mid);
        return (*mid + *next_mid) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */