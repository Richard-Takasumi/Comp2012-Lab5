#include "kid.h"

#include <cstring>

Kid::Kid() : height_(0), gender_(Gender::Female), name_(nullptr), weight_(0) {}

Kid::Kid(int height, Gender gender, const char* name, int weight)
    : height_(height), gender_(gender), name_(nullptr), weight_(weight) {
  name_ = new char[strlen(name) + 1];
  strcpy(name_, name);
}

Kid::Kid(const Kid& other)
    : Kid(other.height(), other.gender(), other.name(), other.weight()) {}

Kid::~Kid() { delete[] name_; }

int Kid::height() const { return height_; }
Gender Kid::gender() const { return gender_; }
const char* Kid::name() const { return name_; }
int Kid::weight() const {return weight_;}

bool Kid::operator<(const Kid& other) const {  // Task 1 - To Do
  
  bool same_height = false;
  bool same_gender = false;
  bool same_name = false;
  if (this->height() == other.height()) {
    same_height = true;
  }
  if (this->gender() == other.gender()) {
    same_gender = true;
  }
  if (strcmp(this->name(), other.name()) == 0) {
    same_name = true;
  }
  
  if (this->height() < other.height()) {
    return true;
  }

  if (same_height) {
    if (this->gender() == Female && other.gender() != Female) {
      return true;
    }
  
    if (same_gender) { 
      if (strcmp(this->name(), other.name()) < 0) {
        return true;
      }

      if (same_name) {
        if (this->weight() > other.weight()) {
          return true;
        }
      }

    }
  }
  return false;
}

Kid& Kid::operator=(const Kid& other) {
  height_ = other.height();
  gender_ = other.gender();
  delete[] name_;
  name_ = new char[strlen(other.name()) + 1];
  strcpy(name_, other.name());
  weight_ = other.weight();
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Kid& k) {
  os << "(Height:" << k.height();
  os << ", Gender:" << (k.gender() == Female ? "Female" : "Male");
  os << ", Name:" << k.name();
  os << ", weight:" << k.weight() << ")";
  return os;
}
