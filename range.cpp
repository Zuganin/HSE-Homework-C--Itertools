

#include "range.h"
Iterator::Iterator(int current, int step) : current_(current), step_(step) {};

int Iterator::operator*() const { return current_; }

const Iterator &Iterator::operator++() {
  current_ += step_;
  return *this;
};
bool Iterator::operator!=(const Iterator &other) const {
  if (step_ == 0) {
    return false;
  }
  if (step_ > 0) {
    return current_ < other.current_;
  }
  return current_ > other.current_;
}

ReverseIterator::ReverseIterator(int current, int step)
    : current_(current), step_(step) {};

int ReverseIterator::operator*() const { return current_; }

const ReverseIterator &ReverseIterator::operator++() {
  current_ -= step_;
  return *this;
};
bool ReverseIterator::operator!=(const ReverseIterator &other) const {
  if(step_ ==0) {
    return false;
  }
  return current_ != other.current_;

}

Range::Range(int end) : begin_(0), end_(end), step_(1) {}
Range::Range(int begin, int end) : begin_(begin), end_(end), step_(1) {}
Range::Range(int begin, int end, int step)
    : begin_(begin), end_(end), step_(step) {
  if (begin_ == end_ || (end_ < begin_ && step_ > 0) ||  (begin_< end_ && step_ <0)) {
    step_ = 0;
  }
}

Iterator Range::begin() const { return {begin_, step_}; }  // NOLINT
Iterator Range::end() const { return {end_, step_}; }      // NOLINT

ReverseIterator Range::rbegin() const {
  int adjusted_end =
    begin_ + (end_ - begin_ + step_ -1) - step_;
  return {adjusted_end, step_};
}  // NOLINT
ReverseIterator Range::rend() const {
  return {begin_ - step_, step_};
}  // NOLINT
