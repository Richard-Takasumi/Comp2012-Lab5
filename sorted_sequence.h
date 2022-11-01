#ifndef __SORTED_SEQUENCE__
#define __SORTED_SEQUENCE__

#include <iostream>
#include <sstream>
#include <string>

template <typename T>
class SortedSequence{
  public:
    SortedSequence() : capacity_(0), size_(0), data_(nullptr) {}
    ~SortedSequence() { delete[] data_; }

    void add(const T &a) {  // Task 2 - To Do

      //memory allocation phase
      if (data_ == nullptr) {
          data_ = new T;
          capacity_ = 1;
        } 
      else if (size_ == capacity_) {
          T* new_data_ = new T[2*capacity_];
          for (int i = 0; i < size_; i++) {
            // is this shallow copy?
            new_data_[i] = data_[i];
          }
          // why did added the if and else instead of just doing delete[] data_ fix the code?
          if (size_ == 1) {
            delete data_;
          } else {
            delete[] data_;
          }
          
          data_ = new_data_;
          capacity_ = 2* capacity_;
      }


      //addition phase
      data_[size_] = a;
      for (int i = 0; i < size_; i++) {
        if (a < data_[i]) {
          for (int j = size_; j > i; j--) {
            data_[j] = data_[j-1];
          }
          data_[i] = a;
          break;
        }

      }
      size_ += 1;
    }

    std::string toString() const {
      std::stringstream ss;
      ss << "capacity: " << capacity_ << ", size: " << size_
        << ", data: " << std::endl;
      if (data_ == nullptr) {
        ss << "None";
      } else {
        for (int i = 0; i < size_; i++) {
          ss << data_[i] << " ";
        }
      }
      return ss.str();
    }

  private:
    int capacity_;
    int size_;
    T *data_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const SortedSequence<T>& t) {
  os << t.toString();
  return os;
}

#endif 