#include <queue>
#include <functional>

//template<typename TYPE, typename MINCOMP = std::greater<TYPE>, typename MAXCOMP = std::less<TYPE> >
class MedianHeap {
public:
	int getMedian();
	void push(int x);
	MedianHeap();
private:
	std::priority_queue<int, std::vector<int>, std::greater<int> > minHeap;
	std::priority_queue<int, std::vector<int>, std::less<int> > maxHeap;
	inline void minToMax();
	inline void maxToMin();
};

int MedianHeap::getMedian() {
	int a = minHeap.size();
	int b = maxHeap.size();
	if(a==0 && b==0) return -1;
	if(a > b) return minHeap.top();
	if(a < b) return maxHeap.top();
	return ((minHeap.top() + maxHeap.top()) / 2);
}


inline void MedianHeap::minToMax() {
	maxHeap.push(minHeap.top());
	minHeap.pop();
}
inline void MedianHeap::maxToMin() {
	minHeap.push(maxHeap.top());
	maxHeap.pop();
}

MedianHeap::MedianHeap() {
}

void MedianHeap::push(int x) {
	if(maxHeap.size()==minHeap.size()) {
		if(!minHeap.empty() && x > minHeap.top()) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
			minHeap.push(x);
		} else {
			maxHeap.push(x);
		}
	} else {
		if(x < maxHeap.top()) {
			minHeap.push(maxHeap.top());
			maxHeap.pop();
			maxHeap.push(x);
		} else {
			minHeap.push(x);
   		}
	}
}

