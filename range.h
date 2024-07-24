

#ifndef Range_H
#define Range_H


class Iterator {
 private:
  int current_;
  int step_ = 1;

 public:
  Iterator(int current, int step);

  int operator*() const;

  const Iterator& operator++();

  bool operator!=(const Iterator& other) const;
};

class ReverseIterator {
 private:
  int current_;
  int step_ = 1;

 public:
  ReverseIterator(int current, int step);

  int operator*() const;

  const ReverseIterator& operator++();

  bool operator!=(const ReverseIterator& other) const;
};

class Range {
 private:
  int begin_;
  int end_;
  int step_;

 public:
  explicit Range(int end);
  Range(int begin, int end);
  Range(int begin, int end, int step);

  Iterator begin() const;           // NOLINT
  Iterator end() const;             // NOLINT
  ReverseIterator rbegin() const;  // NOLINT
  ReverseIterator rend() const;    // NOLINT
};
#endif
