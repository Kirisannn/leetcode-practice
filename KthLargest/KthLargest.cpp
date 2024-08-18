#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KthLargest {
   protected:
    vector<int>* nums = new vector<int>();
    int k = 0;

   public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = &nums;
    }

    int add(int val) {
        this->nums->push_back(val);
        sort(this->nums->begin(), this->nums->end(), greater<int>());
        return this->nums->at(this->k - 1);
    }
};

//  Your KthLargest object will be instantiated and called as such:
//  KthLargest* obj = new KthLargest(k, nums);
//  int param_1 = obj->add(val);

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest* obj = new KthLargest(3, nums);
    cout << obj->add(3) << endl;
    cout << obj->add(5) << endl;
    cout << obj->add(10) << endl;
    cout << obj->add(9) << endl;
    cout << obj->add(4) << endl;
    return 0;
}