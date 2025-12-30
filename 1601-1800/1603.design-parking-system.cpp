/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {
public:
private:
  int slots[4]; // slots[1]: big, slots[2]: medium, slots[3]: small

public:
  ParkingSystem(int big, int medium, int small) {
    slots[1] = big;
    slots[2] = medium;
    slots[3] = small;
  }

  bool addCar(int carType) {
    if (slots[carType] > 0) {
      slots[carType]--;
      return true;
    }
    return false;
  }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
