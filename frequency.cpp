#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

//
// Write a function that takes two parameters:
// (1) a String representing a text document and
// (2) an integer providing the number of items to return.
//
// Implement the function such that it returns a list of Strings ordered by
// word frequency, the most frequently occurring word first. Your solution
// should run in O(n) time where n is the number of characters in the document.
// Implement this function as you would for a production/commercial system.
//
std::vector<std::string> frequency(std::vector<std::string> &text,
                                   unsigned k) {
  // store {word, freq} statistics.
  std::unordered_map<std::string, unsigned> stat;

  for (auto &word : text) {
    auto search = stat.find(word);
    if (search == stat.end()) {
      stat[word] = 1;
    } else {
      stat[word] += 1;
    }
  }

#if 0
  // print the statistics.
  for (auto it = stat.begin(), ie = stat.end(); it != ie; ++it) {
    std::cout << it->first << ": " << it->second << std::endl;
  }
#endif

  // keep min-heap of words with highest frequency
  std::vector<std::string> result;
  auto it = stat.begin();
  for (unsigned i = 0; i < k; ++i) {
    result.push_back(it->first);
    ++it;
  }

  // Scan the stat and maitain a size k min-heap.
  auto comp = [&stat](const std::string &s1,
                      const std::string &s2) { return stat[s1] > stat[s2]; };
  std::make_heap(result.begin(), result.end(), comp);

  for (auto ie = stat.end(); it != ie; ++it) {
    const std::string &word = it->first;
    unsigned freq = stat[word];
    if (freq > stat[*result.begin()]) {
      std::pop_heap(result.begin(), result.end(), comp);
      result.pop_back();
      result.push_back(word);
      std::push_heap(result.begin(), result.end(), comp);
    }
  }
  std::sort_heap(result.begin(), result.end(), comp);
  return result;
}

int main() {
#if 1
  std::vector<std::string> text
      {{"in", "the", "late", "spring", "hemingway", "and", "pauline", "traveled",
       "to", "kansas", "city", "where", "their", "son", "patrick", "was",
       "born", "on", "June", "28", "1928", "pauline", "had", "a", "difficult",
       "delivery", "which", "hemingway", "fictionalized", "in", "a", "Farewell",
       "to", "arms", "after", "patrick", "birth", "pauline", "and", "hemingway",
       "traveled", "to", "wyoming", "massachusetts", "and", "new", "york", "in",
       "the", "winter", "he", "was", "in", "new", "york", "with", "bumby",
       "about", "to", "board", "a", "train", "to", "florida"}};
#else
std::vector<std::string> text
      {{"a", "a", "a", "a", "b", "b", "b", "b",
       "c", "c", "c", "d", "d", "e", "f", "f",
       "f", "f", "f", "f", "f", "f", "g", "g", "g",
       "g", "g", "g"}};
#endif
  auto result = frequency(text, 3);
  // print the statistics.
  for (auto it = result.begin(), ie = result.end(); it != ie; ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
